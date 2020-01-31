#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int current_level = 0;
    char last_step;
    int valley_started=0;
    int counted = 0;
    for (int i=0; i<n; i++)
    {
        char current_step = s[i];
        if (current_step=='D')
        {
            if (!valley_started && current_level == 0)
                valley_started = 1;
            current_level -= 1;
        }
        else if (current_step=='U')
            current_level += 1;
            // if we finally reached the sea level 
            if (current_level == 0 && valley_started)
            {
                valley_started = 0;
                counted++;
            }
    }
    return counted;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}


