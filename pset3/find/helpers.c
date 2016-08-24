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

int mid(int n1, int n2);

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{

    int s = 0, e = n;

    if (n < 0)
      return false;

    do {
      if (values[mid(s, e)] < value) {
        e = mid(s, e) - 1;
      }
      else if (values[mid(s, e)] > value) {
        s = mid(s, e) + 1;
      }
      else if (values[mid(s, e)] == value) {
        return true;
      }
    } while (s < e);

    return false;
}

int mid(int n1, int n2)
{
  return ( n1 + n2 ) / 2;
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
