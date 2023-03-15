#include<bits/stdc++.h>
using namespace std;
string m="A1B";

int main()
{
    string s;
    cin>>s;
    bool a=false;
    bool flag=false;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='1')
            a=true;
    }
    if(a)
    {
        cout<<"The input string is Accepted\n";
        flag=true;
    }
    else cout<<"The input string is not Accepted\n"<<endl;

    if(flag)
    {
        string sA,sB;
        int i;

        for(i=0; i<s.size(); i++)
        {
            if(s[0]=='1')
                sA="e";
            if(s[i] == '1' and i == 0)
            {
                sB=s.substr(1,s.size()-1);
                break;
            }
            else if(s[i] == '1' and i != 0)
            {
                sA=s.substr(0,i);
                sB=s.substr(i+1,((s.size()-i-1)));
                break;
            }
        }
        cout<<"Leftmost Derivative : \n";
        cout<<"S-->A1B\n";
        string tempA,tempB;
        tempA.push_back('A');
        for(int i=0;i<sA.size();i++)
        {
            if(sA=="e")break;

            tempA="0"+tempA;

            cout <<" -->"<< tempA<<"1B\n";
        }
        tempA.pop_back();
        cout<<" -->" << tempA<<"1B\n";

        tempB.push_back('B');
        for(int i=0;i<sB.size();i++)
        {
            if(sB[i]=='0')
            {
                tempB.pop_back();

                tempB+="0B";

                cout<<" -->"<< tempA<<"1"<<tempB<<"\n";
            }
            else
            {
                tempB.pop_back();

                tempB+="1B\n";

                cout<<" -->"<< tempA<<"1"<<tempB;
            }
        }
        tempB.pop_back();
        tempB.pop_back();
        cout<<" -->" << tempA<<"1"<<tempB;

        cout<<"\n\nRightmost Derivative : ";
        string t1, t2;

        t2.push_back('B');


        for(int i=0; i<sB.size(); i++)
        {
            if(sB[i]=='0')
            {
                t2.pop_back();
                t2+="0B";
                cout<< "A1"<<t2<<"-->";
            }
            else
            {
                t2.pop_back();
                t2+="1B";
                cout<< "A1"<<t2<<"-->";
            }
        }

        t2.pop_back();
        t1.push_back('A');
        cout << t1<<"1"<<t2<<"-->";


        for(int i=0; i<sA.size(); i++)
        {
            if(sA[i]=='e')
                break;
            t1="0"+t1;
            cout << t1<<"1"<<t2<<"-->";
        }

        t1.pop_back();
        cout <<t1<<"1"<<t2;


    }
}
