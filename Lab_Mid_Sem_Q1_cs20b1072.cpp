#include <iostream>
#include <sstream>
#define MAX 32

using namespace std;

//Definition of the class
class Binary
{
public:
    int m_bin, n_bin, product = 0;

    void Binary_Representation(int m, int n)
    {
        int Binary1[MAX], Binary2[MAX];

        stringstream string_1, string_2;

        int i = 0;

        while (m > 0)
        {
            Binary1[i] = m % 2;

            m = m / 2;

            i++;
        }

        int j = 0;

        while (n > 0)
        {
            Binary2[j] = n % 2;

            n = n / 2;

            j++;
        }

        for (int a = i - 1; a >= 0; a--)
        {
            string_1 << Binary1[a];
        }

        string_1 >> this->m_bin;

        //Storing the Binary number from the array into an integer

        for (int a = j - 1; a >= 0; a--)
        {
            string_2 << Binary2[a];
        }

        string_2 >> this->n_bin;
    }

    //Function Binary multiplication of the Binary numbers
    void Binary_Product(int m, int n)
    {
        int temp, find = 1;

        while (n != 0)
        {
            temp = n % 10;

            if (temp == 1)
            {
                m = m * find;

                this->product = Product(m, this->product);
            }

            else
            {
                m = m * find;
            }

            n = n / 10;

            find = 10;
        }
    }

    //Function bit-level multiplication
    int Product(int x, int y)
    {
        int i = 0, remainder = 0, arr[50];

        int product = 0;

        while (x != 0 || y != 0)
        {
            arr[i++] = (x % 10 + y % 10 + remainder) % 2;

            remainder = (x % 10 + y % 10 + remainder) / 2;

            x /= 10;
            y /= 10;
        }

        if (remainder != 0)
        {
            arr[i++] = remainder;
        }

        --i;

        while (i >= 0)
        {
            product = product * 10 + arr[i--];
        }

        return product;
    }

    //Function to convert Binary into a decimal
    void Decimal_Representation(int x)
    {
        int remainder, number = 0, binary = 1;

        while (x > 0)
        {
            remainder = x % 10;
            number = number + remainder * binary;
            binary *= 2;
            x /= 10;
        }

        cout << "Decimal representation of the product : " << endl;
        cout << number << endl;
    }
};

int main()
{
    Binary B_1;

    int m, n;

    cout << "Enter the value of m : ";
    cin >> m;

    cout << "Enter the value of n : ";
    cin >> n;

    B_1.Binary_Representation(m, n);

    cout << "------------------ Binary Representation ------------------\n";

    cout << "Binary representation of " << m << " is : ";
    cout << B_1.m_bin << endl;

    cout << "Binary representation of " << n << " is : ";
    cout << B_1.n_bin << endl;

    B_1.Binary_Product(B_1.m_bin, B_1.n_bin);

    cout << "------------------ Product ------------------\n";

    cout << "Product of two numbers : ";
    cout << B_1.product << endl;

    cout << "------------------ Decimal Representation ------------------\n";

    B_1.Decimal_Representation(B_1.product);

    cout << "\n";

    return 0;
}