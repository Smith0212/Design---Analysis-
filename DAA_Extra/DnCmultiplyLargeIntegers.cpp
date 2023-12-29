#include <iostream>
#include <string>
#include<Math.h>  
using namespace std;

int multiply(int x, int y)
{
    // Base case: if x or y has only one digit, return the product of the digits
    if (to_string(x).length() == 1 || to_string(y).length() == 1)
    {
        return x * y;
    }

    // Split x and y into two halves of equal length
    int n = max(to_string(x).length(), to_string(y).length());
    int m = n / 2;
    int a = x / pow(10, m);
    int b = x % (int)pow(10, m);
    int c = y / pow(10, m);
    int d = y % (int)pow(10, m);

    // Recursively compute the products of the halves
    int ac = multiply(a, c);
    int bd = multiply(b, d);
    int ad_bc = multiply(a + b, c + d) - ac - bd;

    // Combine the products to compute the final result
    int result = ac * pow(10, 2 * m) + ad_bc * pow(10, m) + bd;

    return result;
}

int main()
{
    int x, y;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;
    cout << "Product: " << multiply(x, y) << endl;
    return 0;
}

