#include <iostream>
using namespace std;

/* Function to sort an array using insertion sort*/
void insertionSort(int a[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = a[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && a[j] > key) 
        {  
            a[j + 1] = a[j];  
            j = j - 1;  
        }  
        a[j + 1] = key;  
    }  
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
    
    cout << "Enter 5 integers in any order: " << endl;
    for (int i = 0; i < 5; i++) 
        cin >> myarray[i];
    
    cout << "Before Sorting" << endl;
    printArray(myarray, 5); 

    insertionSort(myarray, 5); // sorting

    cout << endl << "After Sorting" << endl;
    printArray(myarray, 5);  

    return 0;
}