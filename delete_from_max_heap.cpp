#include <bits/stdc++.h>
using namespace std;

void insert_heap(vector<int> &v, int x)
{
    v.push_back(x);
    int current_index = v.size() - 1;
    while (current_index != 0)
    {
        int parent_index = (current_index - 1) / 2;
        if (v[parent_index] < v[current_index])
            swap(v[parent_index], v[current_index]);

        else
            break;
        current_index = parent_index;
    }
}

void delete_heap(vector<int> &v)
{
    v[0] = v[v.size() - 1];
    v.pop_back();
    int current = 0;
    while (true)
    {
        int left_index = current * 2 + 1;
        int right_index = current * 2 + 2;
        int last_index = v.size() - 1;
        if (left_index <= last_index && right_index <= last_index)
        {
            // duitai ache
            if (v[left_index] >= v[right_index] && v[left_index] > v[current])
            {
                swap(v[left_index], v[current]);
                current = left_index;
            }
            else if (v[right_index] >= v[left_index] && v[right_index] > v[current])
            {
                swap(v[right_index], v[current]);
                current = right_index;
            }
            else
            {
                break;
            }
        }
        else if (left_index <= last_index)
        {
            // left ache
            if (v[left_index] > v[current])
            {
                swap(v[left_index], v[current]);
                current = left_index;
            }
            else
            {
                break;
            }
        }
        else if (right_index <= last_index)
        {
            // right ache
            if (v[right_index] > v[current])
            {
                swap(v[right_index], v[current]);
                current = right_index;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
}

void print_heap(vector<int> v)
{
    for (int val : v)
        cout << val << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert_heap(v, x);
    }
    delete_heap(v);
    print_heap(v);
    delete_heap(v);
    print_heap(v);

    return 0;
}