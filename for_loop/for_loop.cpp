#include <iostream>
#include <cstdio>
using namespace std;
void solution(int a, int b)
{
    string digits[9] = {"one","two","three","four","five",
                      "six","seven","eight","nine"};
    for (int n=a; n<=b; n++)
    {
        if (n > 9)
        {
            if (n % 2) // odd:
                cout << "odd\n";
            else
                cout <<"even\n";
                    
        }
        else
        {
            cout << digits[n-1]<<"\n";
        }
    }
}
int main() {
    // Complete the code.
    int a, b;
    cin >> a;
    cin >> b;
    solution(a,b);
    return 0;
}

