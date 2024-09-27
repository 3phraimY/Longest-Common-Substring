#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonSubstring(string string1, string string2);

int main() 
{
    string string1 = "abab";
    string string2 = "baba";

    cout << "Enter a string" << endl;
    cin >> string1;
    cout << "Enter another string of the same length" << endl;
    cin >> string2;

    if(string1.length() != string2.length())
    {
        cout << "Error Cannot enter strings of different lengths.";
        return 1;
    }
    
    string result = longestCommonSubstring(string1, string2);
    cout << "Longest Common Substring: " << result << endl;
    
    return 0;
}

string longestCommonSubstring(string string1, string string2) 
{
    int length = string1.length();
    
    // create a 2D table to store the lengths of common substrings.
    vector<vector<int>> table(length + 1, vector<int>(length + 1, 0));
    
    // track of the length of the longest common substring
    int maxLength = 0; 

    // track of the ending index of the longest common substring
    int endIndex = 0;  
    
    // fill in the table using dynamic programming.
    for(int i = 1; i <= length; i++) 
    {
        for(int j = 1; j <= length; j++) 
        {
            if(string1[i - 1] == string2[j - 1]) 
            {
                table[i][j] = table[i - 1][j - 1] + 1;
                if(table[i][j] > maxLength) 
                {
                    maxLength = table[i][j];
                    
                    // update the ending index of the longest common substring
                    endIndex = i; 
                }
            } 
            else 
            {
                // reset the length to 0 for non-matching characters
                table[i][j] = 0; 
            }
        }
    }

    // Print out the matrix
    cout << "Matrix: " << endl;
    cout << "    ";
    for(int k = 0; k < length; k++) 
    {
        cout << string2[k] << " ";
    }
    cout << endl;
    for(int i = 0; i <= length; i++) 
    {
        if(i > 0) 
        {
            cout << string1[i - 1] << " ";
        } 
        else 
        {
            cout << "  ";
        }
        for(int j = 0; j <= length; j++) 
        {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
      
    // Extract the longest common substring from the table.
    string longestCommonSubstr = string1.substr(endIndex - maxLength, maxLength);
    return longestCommonSubstr;
}