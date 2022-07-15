// Official: Unattempted
#include <iostream>
using namespace std;
#define MAX_SIZE 3 * 10e5

// seg tree
#define BIG_NUM 1'000'000'000
class SegTree
{
private:
    int *changeDown;
    pii *cover, *tree;
    void init_tree(int pos, int left, int right, int *arr)
    {
        cover[pos] = pii(left, right);
        changeDown[pos] = 0;
        if (left == right)
        {
            tree[pos] = pii(arr[left], arr[left]);
            return;
        }
        init_tree(2 * pos + 0, left, (left + right) / 2 + 0, arr);
        init_tree(2 * pos + 1, (left + right) / 2 + 1, right, arr);
        tree[pos].first = min(tree[2 * pos + 0], tree[2 * pos + 1]);
        tree[pos].second = max(tree[2 * pos + 0], tree[2 * pos + 1]);
    }
    void updateChangeDown(int pos)
    {
        tree[pos].first += changeDown[pos];
        tree[pos].second += changeDown[pos];
        if (cover[pos].first != cover[pos].second)
        {
            changeDown[2 * pos + 0] += changeDown[pos];
            changeDown[2 * pos + 1] += changeDown[pos];
        }
        changeDown[pos] = 0;
    }

public:
    SegTree(int size, int *arr)
    {
        tree = new pii[size * 3];
        cover = new pii[size * 3];
        changeDown = new int[size * 3];
        init_tree(1, 0, size - 1, arr);
    }
    ~SegTree()
    {
        delete[] tree;
        delete[] cover;
        delete[] changeDown;
    }
    int query2(int left, int right, int pos = 1)
    {
        // optimization
        if (cover[pos].second < left || right < cover[pos].first)
            return BIG_NUM;
        updateChangeDown(pos);
        if (tree[pos].second < 2)
            return BIG_NUM;
        // answer query
        if (cover[pos].first == cover[pos].second)
            return cover[pos].first;
        int ans = query(left, right, 2 * pos + 0);
        if (ans == BIG_NUM)
            ans = query(left, right, 2 * pos + 1);
        return ans;
    }
    int query0(int left, int right, int pos = 1)
    {
        // optimization
        if (cover[pos].second < left || right < cover[pos].first)
            return BIG_NUM;
        updateChangeDown(pos);
        if (tree[pos].first > 0)
            return BIG_NUM;
        // answer query
        if (cover[pos].first == cover[pos].second)
            return cover[pos].first;
        int ans = query(left, right, 2 * pos + 0);
        if (ans == BIG_NUM)
            ans = query(left, right, 2 * pos + 1);
        return ans;
    }
    int query1(int left, int right, int pos = 1)
    {
        // optimization
        if (cover[pos].second < left || right < cover[pos].first)
            return BIG_NUM;
        updateChangeDown(pos);
        if (tree[pos].second < 1)
            return BIG_NUM;
        // answer query
        if (cover[pos].first == cover[pos].second)
            return cover[pos].first;
        int ans = query(left, right, 2 * pos + 0);
        if (ans == BIG_NUM)
            ans = query(left, right, 2 * pos + 1);
        return ans;
    }
    int last1(int left, int right, int pos = 1)
    {
        // optimization
        if (cover[pos].second < left || right < cover[pos].first)
            return BIG_NUM;
        updateChangeDown(pos);
        if (tree[pos].second < 1)
            return BIG_NUM;
        // answer query
        if (cover[pos].first == cover[pos].second)
            return cover[pos].first;
        int ans = query(left, right, 2 * pos + 1);
        if (ans == BIG_NUM)
            ans = query(left, right, 2 * pos + 0);
        return ans;
    }
    void update(int left, int right, int change, int pos = 1)
    {
        // fully covered
        if (left <= cover[pos].first &&
            cover[pos].second <= right)
            changeDown[pos] += change;
        updateChangeDown(pos);
        // no intersection
        if (cover[pos].second < left ||
            right < cover[pos].first)
            return;
        // some intersection
        if (cover[pos].first < left ||
            right < cover[pos].second)
        {
            update(left, right, change, 2 * pos + 0);
            update(left, right, change, 2 * pos + 1);
            tree[pos].first = min(tree[2 * pos + 0], tree[2 * pos + 1]);
            tree[pos].second = max(tree[2 * pos + 0], tree[2 * pos + 1]);
        }
    }
};

int main(void)
{
    int n, q, rem;
    cin >> n >> q;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int *temp = new int[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
        temp[i] = 0;
    for (int i = 0; i < n; i++)
        temp[arr[i]]++;
    for (int i = 1; i < MAX_SIZE; i++)
    {
        rem = temp[i - 1] / 2;
        temp[i - 1] -= 2 * rem;
        temp[i] += rem;
    }
    SegTree st(MAX_SIZE, temp);

    for (int i = 0; i < q; i++)
    {
        int idx, become, from;
        cin >> idx >> become;
        from = arr[idx - 1];
        arr[idx - 1] = become;

        int first1 = st.query1(from, MAX_SIZE - 1);
        st.update(first1, first1, -1);
        st.update(from, first1 - 1, 1);
        st.update(become, become, 1);
        int res;
        while ((res = st.query2(0, MAX_SIZE - 1)) != BIG_NUM)
        {
            end = st.query0(res, MAX_SIZE - 1);
            st.update(res, res, -1);
            st.update(res, end - 1, -1);
            st.update(end, end, 1);
        }
        cout << st.last1(0, MAX_SIZE - 1) << endl;
    }
    return 0;
}