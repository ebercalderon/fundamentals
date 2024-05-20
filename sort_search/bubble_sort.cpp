#include <iostream>
using namespace std;

/* Function to sort an array using bubble sort */
void bubbleSort(int a[], int n)
{
    int i, j, temp;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++) 
        {
            if (a[j] > a[j + 1]) 
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
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

    bubbleSort(myarray, 5); // sorting

    cout << endl << "After Sorting" << endl;
    printArray(myarray, 5);  

    return 0;
}