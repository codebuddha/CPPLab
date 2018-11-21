#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int partition_fn(std::vector<int> &a, int start, int end)
{
    int pivot = a[start], pos = start+1;
    for(int i=start+1; i<=end; i++)
        if(a[i] < pivot)
        {
            std::swap(a[i], a[pos]);
            pos++;  
        }    
    std::swap(a[start], a[pos-1]);
    return pos-1;
}
int k_th_largest(std::vector<int> &vec, int k, int start, int end)
{
    if (end > vec.size()-1 && start < 0) 
    {
        // std::cout << "Invalid start, end parameters\n";
        return 0;
    }  
    int left=start, right=end;
    do{
        int pos = partition_fn(vec, left, right);
        // printf("current left %d right %d pos %d\n", left, right, pos);
        if(pos == k)
        {
            // for(auto &i:vec)
            //     std::cout << i << " ";
            // printf("found mid: %d\n", vec[pos]);
            return vec[pos]; 
        }
        else if(pos > k)
        {
            right = pos - 1;
        }
        else if(pos < k)
        {
            left = pos + 1;
        }
    }while(left <= right);
}
// Complete the findMedian function below.
int findMedian(vector<int> vec) 
{
    int len = vec.size();
    int mid = k_th_largest(vec, len/2, 0, vec.size()-1);
    if(len % 2 == 0)
    {
        int pre_mid = k_th_largest(vec, len/2-1, 0, len/2);
        return (pre_mid + mid)/2.0;
    }
    else{
        return mid;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = findMedian(arr);

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
    for(auto &i:splits)
        std::cout << i << " : ";
    std::cout << "\n";
    return splits;
}
