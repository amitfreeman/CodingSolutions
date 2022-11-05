#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int pos = 1;
        char ci = chars[0];
        string strnum;
        //read write pointers
        int reader = 1, writer = 0;

        while (reader <= chars.size())
        {
            if (reader == chars.size())
            {
                chars[writer++] = ci;
                if (pos > 1)
                {
                    strnum = to_string(pos);
                    for (int i = 0; i < strnum.length(); i++)
                    {
                        chars[writer++] = strnum[i];
                    }
                }
            }
            else if (chars[reader] == ci)
            {
                pos++;
            }
            else
            {
                chars[writer++] = ci;
                if (pos > 1)
                {
                    strnum = to_string(pos);
                    for (int i = 0; i < strnum.length(); i++)
                    {
                        chars[writer++] = strnum[i];
                    }
                }

                pos = 1;
                ci = chars[reader];
            }

            reader++;
        }

        pos = chars.size();
        while (writer < pos)
        {
            chars.pop_back();
            ++writer;
        }

        return chars.size();
    }
};

int main()
{
    Solution s;

    vector<char> vchar1 = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    s.compress(vchar1);
    cout << "\ncompressed vchar1: ";
    for (char c : vchar1)
        cout << c;
    cout << endl;

    vector<char> vchar2 = {'a'};
    s.compress(vchar2);
    cout << "\ncompressed vchar2: ";
    for (char c : vchar2)
        cout << c;
    cout << endl;

    vector<char> vchar3 = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    s.compress(vchar3);
    cout << "\ncompressed vchar3: ";
    for (char c : vchar3)
        cout << c;
    cout << endl;

    return 0;
}