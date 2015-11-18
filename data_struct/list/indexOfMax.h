// find location of maximum of n numbers

#include "myExceptions.h"

template <typename T>
int indexOfMax(T a[], int n)
{
    if (n <= 0) {
        throw illegalParameterValue("n must be > 0");
    }
    int indexOfMax = 0;
    for (int i = 1; i < n; ++i) {
        if (a[indexOfMax] < a[i]) {
            indexOfMax = i;
        }
    }
    return indexOfMax;
}
