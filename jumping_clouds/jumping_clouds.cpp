#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the jumpingOnClouds function below.
// the strategy is to use jump by 2 if it is possible
// not written, assume Emma starts from 0 cloud always
int jumpingOnClouds(vector<int> c) 
{
    int jumps = 0;
    int n = (int) c.size();
    int is_next_hazard, is_second_hazard;
    int is_pre_last_cloud, is_last_cloud;
    int i = 0;
    // at least two elements guaranteed
    while (1)
    {   
        is_next_hazard = (c[i+1] == 1);
        // cout << "is_next_hazard = " << is_next_hazard << "\n";
        is_second_hazard = (c[i+2] == 1);
        is_pre_last_cloud = (i == (n-2));
        is_last_cloud = (i == (n-1));
        if (is_pre_last_cloud)
        {
            jumps++;
            i+=1;
            break;
        }
        else
        {
            if (is_last_cloud) break;
            else if (is_next_hazard || !is_second_hazard)
            {
                jumps++;
                i = i+2;
                
            }
            else if (is_second_hazard)
            {
                jumps++;
                i = i + 1;
                
            }
        }// if else end
    }
    
    return jumps;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(c);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

