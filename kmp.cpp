#include <iostream>
#include <cstring>
using namespace std;
void KMPsetup(string pattern, int f[])
{
    int m = pattern.length(), k;
    f[0] = -1;
    for (int i = 1; i < m; i++)
    {
        k = f[i - 1];
        while (k >= 0)
        {
            if (pattern[k] == pattern[i - 1])
                break;
            else
                k = f[k];
        }
        f[i] = k + 1;
    }
}

//check whether target string contains pattern
bool KMPscan(string pattern, string text)
{
    int m = pattern.length();
    int n = text.length();
    int f[m];
    KMPsetup(pattern, f);
    int i = 0;
    int k = 0;
    while (i < n)
    {
        if (k == -1)
        {
            i++;
            k = 0;
        }
        else if (text[i] == pattern[k])
        {
            i++;
            k++;
            if (k == m)
                return 1;
        }
        else
            k = f[k];
    }
    return 0;
}

int main()
{
    string text;
    string pattern;
    cout<<"Enter pattern as a string:";
    getline(cin,pattern);
    cout<<"Enter Text as a string:";
    getline(cin,text);
    if (KMPscan(pattern, text))
        cout<<"'"<<pattern<<"' found in string '"<<text<<"'"<<endl;
    else
        cout<<"'"<<pattern<<"' not found in string '"<<text<<"'"<<endl;

    return 0;
}
