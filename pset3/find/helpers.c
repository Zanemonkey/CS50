/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
 
    
    if (n == 0) { printf("Error!\n"); return false; }
    
    // Check for base case and prevent infinite recursion
    if (n == 1)
    {
        // Check if sole remaining value in the search array is the value sought
        if (values[0] == value)
        {
            return true;
        } else
        {
            return false;
        }
    }
    
    // Calculate the midpoint
    int mid = n / 2;
    
    // Check if the value in the midpoint is the value sought
    if (values[mid] == value)
    {
        return true;
    } 
    // If the midpoint value is bigger than the value sought, create an array
    // of all the smaller values, and recursively pass this new smaller array into the 
    // search function
    else if (values[mid] > value)
    {
        int left[n / 2];
        int size = 0;
        for (int i = 0; i < mid; i++)
        {
            left[i] = values[i];
            size++;
        }
        return search(value, left, size);
    } 
    // Likewise, if the midpoint value is smaller than the value sought, create an
    // array of all the larger values, and recursively pass this new smaller array
    // into the search function
    else if (values[mid] < value)
    {
        int right[n / 2];
        int size = 0;
        for (int i = mid; i < n; i++)
        {
            right[i - mid] = values[i];
            size++;
        }
        return search(value, right, size);
    }
    
    return false;
    
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // Implementation of bubble sort. Note that this is not optimised at all, and
    // may continue to pass through the array after it is already sorted
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            // Compare values and swap them if the larger value appears before the
            // smaller value. Larger values will 'bubble' to the top
            if (values[j] > values[j + 1])
            {
                int tmp = values[j + 1];
                values[j + 1] = values[j];
                values[j] = tmp;
            }
        }
    }
    return;
}
