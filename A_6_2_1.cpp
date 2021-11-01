#include <iostream>
using namespace std;

class MATRIX_CHAIN_MULTI
{
public:
  int add = 0;
  void cost_calculator(int a[], int n)
  {
    int i, r = 0, k, s, c[n - 2];

    for (i = 0; i < n - 2; i++)
    {
      c[i] = a[i] * a[i + 1] * a[i + 2]; // calculating number of multiplications of 2 matrises
    }
    s = c[0];
    for (i = 1; i < n - 2; i++)
    {
      if (s > c[i])
      {
        s = c[i]; // getting the shortest value
        r = i;
      }
    }

    for (i = r + 1; i < n - 1; i++)
    { // reducing the chain by multipling a pair each time
      a[i] = a[i + 1];
    }
    add = add + s; // adding to total number of multiplications
    if (n - 3 == 0)
    {
      cout << "\nleast multiplications is :" << add;
      exit(0);
    }
    cost_calculator(a, n - 1); // recursion
  }
};

int main()
{
  int c, n;
  MATRIX_CHAIN_MULTI t;

  cout << "\nENTER NUMBER OF MATRICES IN THE CHAIN\n";
  cin >> n;
  int array[n + 1];

  cout << "\n Enter coloums of the chain and coloum and row of the last matrix";
  for (int i = 0; i < n + 1; i++)
  {
    cin >> array[i];
  }

  t.cost_calculator(array, n + 1);
  return (0);
}