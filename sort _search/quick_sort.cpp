#include <iostream>
using namespace std;

// A utility function to swap two elements  
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
  
/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
int partition (int a[], int low, int high)  
{  
    int pivot = a[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (a[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&a[i], &a[j]);  
        }  
    }  
    swap(&a[i + 1], &a[high]);  
    return (i + 1);  
}  
  
/* The main function that implements QuickSort  
a[] --> Array to be sorted,  
low --> Starting index,  
high --> Ending index */
void quickSort(int a[], int low, int high)  
{  
    if (low < high)  
    {  
        /* pi is partitioning index, a[p] is now  
        at right place */
        int pi = partition(a, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(a, low, pi - 1);  
        quickSort(a, pi + 1, high);  
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

    quickSort(myarray, 0, 5 - 1); // sorting

    cout << endl << "After Sorting" << endl;
    printArray(myarray, 5);  

    return 0;
}