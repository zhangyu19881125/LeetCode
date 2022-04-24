#include <string>
#include <iostream>
#include <assert.h>
#include <math.h>
#include <unistd.h>
#include <climits>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

template<typename T>
static void assert_equal(const T& l, const T& r)
{
    if (l != r) cout << l << " != " << r << endl;
}
