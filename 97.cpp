// a.has a function divide(int a ,int b)that performs division b.throws an exception if the denominator is zero. C.calls the divide function from main() and handles the exception in main()
#include <iostream>
using namespace std;
void divide(int a, int b)
{
    double divide;

    try
    {
        if (b == 0)
            throw 0;
        divide = a / b;
        cout << a << "/" << b << " = " << divide << endl;
    }
    catch (int num_exception)
    {
        cout << "Error: Cannot divide by " << num_exception << endl;
    }
}
int main()
{
    int num1, num2;
    cout << "Enter Numerator: ";
    cin >> num1;
    cout << "Enter Denominator: ";
    cin >> num2;
    divide(num1, num2);
    return 0;
}