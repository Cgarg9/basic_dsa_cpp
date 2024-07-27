// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define ll long long int;

class Solution
{
private:
    int check(int pages, vector<int> &books, int student)
    {
        int count = 1;
        int pagesAllocated = 0;
        for (int i = 0; i < books.size(); i++)
        {
            if (pagesAllocated + books[i] <= pages)
            {
                pagesAllocated += books[i];
            }
            else
            {
                count++;
                pagesAllocated = books[i];
            }
        }
        return count == student ? true : false;
    }

public:
    int findPages(int n, vector<int> &books, int students)
    {
        int low = *(max_element(books.begin(), books.end()));
        int high = 0;
        int ans = -1;
        for (int i = 0; i < n; i++)
            high += books[i];
        while (low <= high)
        {
            int mid = (high - low) / 2 + low;
            if (check(mid, books, students))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    int n, students;
    cin >> n >> students;
    vector<int> books(n);
    for (int i = 0; i < n; i++)
        cin >> books[i];
    Solution obj;
    cout << obj.findPages(n, books, students);
    return 0;
}