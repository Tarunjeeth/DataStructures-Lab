#include <iostream>
using namespace std;

int main()
{
    int len;
    int bkwid;
    int data;
    int count;
    int x;
    cin >> len;
    int solution[len];
    for (int i = 0; i < len; i++)
    {
        count = 1;
        cin >> bkwid;
        int arr[bkwid];
        for (int j = 0; j < bkwid; j++)
        {
            cin >> data;
            arr[j] = data;
        }
        sort(arr + 1, arr + bkwid);
        for (int j = 1; j < bkwid; j++)
        {
            if (arr[0] < arr[j])
            {
                x = (arr[j] - arr[0]);
                if (x % 2 == 1)
                {
                    x = x + 1;
                }
                x = x / 2;
                arr[0] = arr[0] + x;
                arr[j] = arr[j] - x;
            }
        }
        solution[i] = arr[0];
    }
    for (int i = 0; i < len; i++)
    {
        cout << solution[i] << endl;
    }
}