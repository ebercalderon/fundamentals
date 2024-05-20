#include <iostream>
using namespace std;

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  

/* Function to sort an array using selection sort*/
void selectionSort(int a[], int n)  
{  
    int i, j, min;  
  
    // One by one move boundary of unsorted subarray  
    for (i = 0; i < n-1; i++)  
    {  
        // Find the minimum element in unsorted array  
        min = i;  
        for (j = i+1; j < n; j++)
        {  
            if (a[j] < a[min])  
                min = j;  
        }
        // Swap the found minimum element with the first element  
        swap(&a[min], &a[i]);  
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

    selectionSort(myarray, 5); // sorting

    cout << endl << "After Sorting" << endl;
    printArray(myarray, 5);  

    return 0;
}