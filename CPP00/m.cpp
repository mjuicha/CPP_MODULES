#include <iostream>
#include <ctime>

using namespace std;

int main()
{
 int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
    int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9 };
	size_t const		d_size( sizeof(d) / sizeof(int) );
    cout << amounts_size << d_size;

    return 0;
}