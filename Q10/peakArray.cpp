#include<bits/stdc++.h>
using namespace std;

int findPeak(int arr[], int left, int right)
{
    // base case when array has only one element
    if(left == right)
    {
        return left;
    }

    // base case when array has two elements
    if(right == left+1)
    {
        return (arr[left] > arr[right]) ? left : right;
    }

    // find the middle element
    int mid = (left + right) / 2;

    // check if the middle element is peak
    if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
    {
        return mid;
    }

    // if middle element if not peak, check for peak in the right half of the array
    if(arr[mid] > arr[mid-1] && arr[mid] < arr[mid+1])
    {
        return findPeak(arr,mid+1,right);
    }

    // if peak is not in the right half, check for peak in the left half of the array
    else
    {
        return findPeak(arr,left,mid-1);
    }
}


int main()
{
    int arr[] = {1,3,5,7,9,8,6,4,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int peak = findPeak(arr,0,n-1);
    cout<<"Peak element: "<<arr[peak]<<" at index "<< peak << endl;
}