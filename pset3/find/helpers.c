/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{

    if (n < 0)
      return false;

    for (int i = 0; i < n; ++i) {
      if (values[i] == value)
        return true;
    }

    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int temp;

    for (int x = 0; x < n - 1; ++x) {
        for (int y = x + 1; y < n; ++y) {
          if (values[y] < values[x]) {

            temp = values[x];
            values[x] = values[y];
            values[y] = temp;

          }
        }
    }

    return;
}
