#include <iostream>
using namespace std;
void marge(int arr[], int lb, int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int temp[ub + 1];

    while (i <= mid && j <= ub)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= ub)
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
    }
    for (int k = lb; k <= ub; k++)
    {
        arr[k] = temp[k];
    }
}

void margeSort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        margeSort(arr, lb, mid);
        margeSort(arr, mid + 1, ub);
        marge(arr, lb, mid, ub);
    }
}

int main()
{
    int arr[] = {12, 2, 1, 5, 6};
    int n = 5;
    margeSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}