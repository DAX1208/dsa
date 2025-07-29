// bouble sorting
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // noe we doing sorting
    for (int i = 0; i < n - 1; i++) // for itration
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int swap = a[j];
                a[j] = a[j + 1];
                a[j + 1] = swap;
            }
        }
    }
    cout << "sorted array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
}