#include <iostream>
using namespace std;

/**
 * Function to linearly search x in arr[].
 * If x is present then return its location, 
 * otherwise return -1 
 */

int search(int arr[], int n, int x) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        if (arr[i] == x) 
            return i; 
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
int main()
{
    int myarray[5];
    int n, result;
    cout << "Enter 5 integers in any order: " << endl;
    for (int i = 0; i < 5; i++) 
        cin >> myarray[i];
    
    cout << "Number to search: ";
    cin >> n;

    result = search(myarray, 5, n); // search

    cout << "Array: " << endl;
    printArray(myarray, 5);  

    if (result == -1)
        cout<<"\nElement is not present in array";
    else
        cout<<"\nElement is present at index: " <<result;

    return 0;
}