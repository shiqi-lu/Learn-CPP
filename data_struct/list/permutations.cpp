#include <iostream>
#include <iterator>
#include <algorithm>

template <typename T>
void permutations(T list[], int k, int m)
{
    int i;
    if (k == m) {
        std::copy(list, list+m+1, std::ostream_iterator<T>(std::cout, ""));
        std::cout << std::endl;
    } else {
        for (i = k; i <= m; ++i) {
            std::swap(list[k], list[i]);
            permutations(list, k+1, m);
            std::swap(list[k], list[i]);
        }
    }
}

int main()
{
    char a[] = {'1', '2', '3', '4'};

    std::cout << "The permutations of 1 are" << std::endl;
    permutations(a, 0, 0);

    std::cout << "The permutations of 123 are" << std::endl;
    permutations(a, 0, 2);

    std::cout << "The permutations of 1234 are" << std::endl;
    permutations(a, 0, 3);

    return 0;
}
/*
 * output:
The permutations of 1 are
1
The permutations of 123 are
123
132
213
231
321
312
The permutations of 1234 are
1234
1243
1324
1342
1432
1423
2134
2143
2314
2341
2431
2413
3214
3241
3124
3142
3412
3421
4231
4213
4321
4312
4132
4123
*/
