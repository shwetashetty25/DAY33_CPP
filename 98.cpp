// create a class called factorial having member function fact()to calculate the factorial of a given number. Throw an exception if number entered by the user is negative or zero:
#include <iostream>
#include <stdexcept>

using namespace std;

class Factorial
{
private:
    int num;

public:
    Factorial(int n) : num(n)
    {
        if (n < 0)
        {
            throw invalid_argument("Factorial is not defined for negative numbers.");
        }
        else if (n == 0)
        {
            throw invalid_argument("Factorial of zero is not defined.");
        }
    }
    long long fact()
    {
        long long result = 1;
        for (int i = 1; i <= num; i++)
        {
            result *= i;
        }
        return result;
    }
};
int main()
{
    try
    {
        int num;
        cout << "Enter a number: ";
        cin >> num;

        Factorial factorial(num);
        long long result = factorial.fact();
        cout << "Factorial of " << num << " is: " << result << endl;
    }
    catch (const invalid_argument &e)
    {
        cout << "Error: " << e.what() << endl;
    }
    catch (const exception &e)
    {
        cout << "An error occurred: " << e.what() << endl;
    }

    return 0;
}