#include<bits/stdc++.h>

using namespace std;


void createLPS(vector<int>&lps , string pat)
{
    int len=1;
    int i=0;
    lps[0]=0;
    while(i<pat.length())
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len=lps[len-1];

            }
            else
            {
                lps[i]=0;
                i++;
            }
            
        }
        
    }
}


bool KMPalgortihm(string text,string pat)
{
    int i=0;
    int j=0;

    vector<int>lps(pat.length());

    createLPS(lps,pat);

    while(i<text.length())
    {
        if(text[i]==pat[j])
        {
            i++;
            j++;
        }

        if(j==pat.length())
        {
           return true;
        }
        else if(i<text.length() && pat[j]!=text[i])
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                i=i+1;
            }
            
        }
    }

    return false;
}


int main()
{
    string text="ABCD";
    string pat="CDAB";

    string temp=text+text;

    if(KMPalgortihm(temp,pat)) cout<<"It is left rotated";
}