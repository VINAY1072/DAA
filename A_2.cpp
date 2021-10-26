#include <iostream>
using namespace std;
class Find
{
public:
    void Find_max_min_smax_smin(int *array, int max, int min, int n)
    {

        int smax = min, i;
        int smin = max;

        for (i = 0; i < n; i++)
        {
            if (array[i] < max && array[i] > smax)
                smax = array[i];
            if (array[i] > min && array[i] < smin)
                smin = array[i];
        }

        cout << "First maximum: " << max << "\n";
        cout << "second maximum: " << smax << "\n";
        cout << "First minimum: " << min << "\n";
        cout << "secong minimum: " << smin << "\n";
    }
};

int main()
{
    Find f1;
    int n, i, max, smax, min, smin;

    cout << "Enter array size: ";
    cin >> n;
    int arr[n];
    cout << "Enter"
         << " " << n << " "
         << "elements: "
         << "\n";
    cin >> arr[0];
    max = min = arr[0];

    for (i = 1; i < n; i++)
    {
        cin >> arr[i];
        if (max < arr[i])
            max = arr[i];
        if (min > arr[i])
            min = arr[i];
    }

    f1.Find_max_min_smax_smin(arr, max, min, n);

    return 0;
}