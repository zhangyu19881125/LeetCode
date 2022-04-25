#include <string>
#include <iostream>
#include <assert.h>
#include <math.h>
#include <unistd.h>
#include <climits>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
static void assert_equal(const T& l, const T& r)
{
    if (l != r) cout << l << " != " << r << endl;
}
