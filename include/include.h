#include <string>
#include <iostream>
#include <assert.h>

using namespace std;

template<typename T>
static void assert_equal(const T& l, const T& r)
{
    if (l != r) cout << l << " != " << r << endl;
}
