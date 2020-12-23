/*
    Given an array of n numbers, read numbers from the array and keep at-most K numbers at the
    top according to their decreasing frequency every time a new number is read. Write a
    program using Hash Data Structure to print top k numbers sorted by frequency when input
    stream has included k distinct elements, else need to print all distinct elements sorted by
    frequency.
    
    Examples:
        Input : arr[] = {5, 2, 1, 3, 2}
        k = 4
    
    Output : 5 2 5 1 2 5 1 2 3 5 2 1 3 5
    
    Explanation:
    
        1. After reading 5, there is only one element 5 whose frequency is max till now. so print 5.
        2. After reading 2, we will have two elements 2 and 5 with the same frequency. As 2, is smaller than 5 but their frequency is the same so we will print 2 5.
        3. After reading 1, we will have 3 elements 1, 2 and 5 with the same frequency, so print 1 2 5.
        4. Similarly after reading 3, print 1 2 3 5
        5. After reading last element 2 since 2 has already occurred so we have now a frequency of 2 as 2. So we keep 2 at the top and then rest of the element with the same frequency in sorted order. So print, 2 1 3 5.
*/

#include <bits/stdc++.h>
using namespace std;

void kTop(int A[], int n, int k)
{
    vector<int> top(k + 1);
    unordered_map<int, int> freq;

    for (int m = 0; m < n; m++)
    {
        freq[A[m]]++;

        top[k] = A[m];

        auto it = find(top.begin(), top.end() - 1, A[m]);

        for (int i = distance(top.begin(), it) - 1; i >= 0; --i)
        {
            if (freq[top[i]] < freq[top[i + 1]])
                swap(top[i], top[i + 1]);

            else if ((freq[top[i]] == freq[top[i + 1]]) && (top[i] > top[i + 1]))
                swap(top[i], top[i + 1]);
            else
                break;
        }

        for (int i = 0; i < k && top[i] != 0; ++i)
            cout << top[i] << ' ';
    }
    cout << endl;
}

int main()
{
    int k;
    int Arr[10000];
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;
    cout << "Enter " << n << " Elements: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> Arr[i];
    }
    cout << endl;
    kTop(Arr, n, k);
    return 0;
}