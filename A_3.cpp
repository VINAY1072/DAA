#include <iostream>

using namespace std;

class Find
{
public:
    // function to print Minimum element using recursion

    int find_Min_Rec(int A[], int n)
    {

        // if size = 0 means whole array has been traversed

        if (n == 1)

            return A[0];

        return min(A[n - 1], find_Min_Rec(A, n - 1));
    }

    int find_Max_Rec(int A[], int n)
    {

        // if size = 0 means whole array has been traversed

        if (n == 1)

            return A[0];

        return max(A[n - 1], find_Max_Rec(A, n - 1));
    }
};
int main()
{
    Find f1;
    int n, i;
    cout << "Enter array size: ";
    cin >> n;
    int Array[n];
    cout << "Enter"
         << " " << n << " "
         << "elements: "
         << "\n";
    for (i = 0; i < n; i++)
    {
        cin >> Array[i];
    }

    int max = f1.find_Max_Rec(Array, n), min = f1.find_Min_Rec(Array, n);

    for (i = 0; i < n; i++)
    {
        if (Array[i] == min)
        {

            Array[i] = Array[i + 1];
        }
    }

    for (i = 0; i < n; i++)
    {
        if (Array[i] == max)
        {
            Array[i] = Array[i + 1];
        }
    }

    int smin = f1.find_Min_Rec(Array, n - 1), smax = f1.find_Max_Rec(Array, n - 1);

    cout << "First minimum: " << min << "\n";
    cout << "First maximum: " << max << "\n";
    cout << "Second minimum:" << smin << "\n";
    cout << "Second maximum: " << smax << "\n";

    return 0;
}