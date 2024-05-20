#include <iostream> 
using namespace std; 
  
/**
 * A recursive binary search function. It returns 
 * location of x in given array arr[l..r] is present, 
 * otherwise -1 
 */

int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (arr[mid] == x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1; 
} 
  
// A utility function to print an array of size n  
void printArray(int a[], int n)  
{
    int i;  
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
}

/* Driver code */
int main(void) 
{ 
    int myarray[5];
    int x, result;
    cout << "Enter 5 integers in order: " << endl;
    for (int i = 0; i < 5; i++) 
        cin >> myarray[i];
    
    cout << "Number to search: ";
    cin >> x;

    result = binarySearch(myarray, 0, 5 - 1, x); // search

    cout << "Array: " << endl;
    printArray(myarray, 5);  

    if (result == -1)
        cout<<"\nElement is not present in array";
    else
        cout<<"\nElement is present at index: " <<result;

    return 0;
} 