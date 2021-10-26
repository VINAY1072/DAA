#include <iostream>
using namespace std;

class Fractional_knapsack
{
public:
    int profit;
    int weight;
    Fractional_knapsack()
    {
        this->profit = 0;
        this->weight = 0;
    }
};

void sort(Fractional_knapsack array[], int n)
{
    int i, j, k, l, m;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if ((double)(array[j].profit / array[j].weight) > (double)(array[k].profit / array[k].weight))
                k = j;
        }
        l = array[k].profit;
        array[k].profit = array[i].profit;
        array[i].profit = l;
        m = array[k].weight;
        array[k].weight = array[i].weight;
        array[i].weight = m;
    }
}

double fractional_knapsack(int W, Fractional_knapsack array[], int n)
{
    sort(array, n);
    for (int i = 0; i < n; i++)
    {
        cout << array[i].profit << "  " << array[i].weight << " "
             << ((double)array[i].profit / array[i].weight) << endl;
    }
    int current_weight = 0;    // Current weight in knapsack
    double final_profit = 0.0; // Result (profit in Knapsack)

    // Looping through all Items
    for (int i = 0; i < n; i++)
    {
        // If adding Item won't overflow, add it completely
        if (current_weight + array[i].weight <= W)
        {
            current_weight += array[i].weight;
            final_profit += array[i].profit;
        }

        // If we can't add current Item, add fractional part
        // of it
        // here ((double)remain / (double)array[i].weight) is the alpha which is 0 <= alpha <= 1
        else
        {
            int remain = W - current_weight;
            final_profit += array[i].profit * ((double)remain / (double)array[i].weight);
            break;
        }
    }

    // Returning final profit
    return final_profit;
}

int main()
{
    Fractional_knapsack array[1000];
    int MAX_WEIGHT;
    cout << "ENTER THE MAX WEIGHT\n";
    cin >> MAX_WEIGHT;
    int n;
    cout << "ENTER THE SIZE\n";
    cin >> n;
    cout << "ENTER THE arrayAY\n";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i].profit;
        cin >> array[i].weight;
    }
    cout << fractional_knapsack(MAX_WEIGHT, array, n) << endl;
}