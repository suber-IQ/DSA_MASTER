#include <iostream>
#include <vector>
#include <string>
using namespace std;

void phoneKeypad(vector<string> &ans, string output, int index, vector<string> &mapping, string digits)
{
    if (index >= digits.length())
    {
        ans.push_back(output);
        return;
    }

    int digit = digits[index] - '0';
    string value = mapping[digit];
    for (int i = 0; i < value.length(); i++)
    {
        char ch = value[i];
        output.push_back(ch);
        phoneKeypad(ans, output, index + 1, mapping, digits);
        output.pop_back();
    }
}

int main()
{

    vector<string> ans;

    string digits = "23"; // 🎉 output:- ["ad","ae","af","bd","be","bf","cd","ce","cf"]

    string output = "";
    int index = 0;
    vector<string> mapping(10);

    mapping[2] = "abc";
    mapping[3] = "def";
    mapping[4] = "ghi";
    mapping[5] = "jkl";
    mapping[6] = "mno";
    mapping[7] = "pqrs";
    mapping[8] = "tuv";
    mapping[9] = "wxyz";

    phoneKeypad(ans, output, index, mapping, digits);

    for (int i = 0; i < ans.size(); i++)
    { // ad ae af bd be bf cd ce cf
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}