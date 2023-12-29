#include<iostream>
using namespace std;

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int arr[], int lb, int ub){
    int i = lb;
    int j = ub;
    int pivot = arr[lb];    
    while (i < j)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if(i < j){
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[j], &arr[lb]);
    return j;
}

void QuickSort(int arr[], int lb, int ub){
    if(lb < ub){
        int loc = partition(arr, lb, ub);
        QuickSort(arr, lb, loc-1);
        QuickSort(arr, loc+1, ub);
    }
}

int main(){
    int arr[] = {9,4,10,5,8,1};
    QuickSort(arr, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] <<" ";
    }
    
}