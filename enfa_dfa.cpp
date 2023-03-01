#include<bits/stdc++.h>
using namespace std;

int main()
{

//      state           ep             0            1
    map<char, pair<set<char>, pair<set<char>, set<char> > > > enfa;

    int edge, state;
    cin >> state;

    for(int i=0; i<state; i++)
    {
        char ste;
        cin >> ste;

        enfa.insert({ste, {{}, {{},{}}}});
    }

    cin >> edge;

    for(int i=0; i<edge; i++)
    {
        char state, input,going ;
        cin >> state >> input >> going;

        if(input=='p')
        {
            enfa[state].first.insert(going);
        }
        else if(input=='0')
        {
            enfa[state].second.first.insert(going);
        }
        else if(input=='1')
        {
            enfa[state].second.second.insert(going);
        }
    }
    //             states            0          1
    vector<pair<set<char>, pair<set<char>, set<char> > > > dfa;
    map<char, set<char> > ep_closure;
    queue<set<char> > q;
    map<set<char>, bool> visited;

    ep_closure[NULL]= {};
    // dfs
    for(auto itr : enfa)
    {
        set<char>st;
        // insert the state itself
        st.insert(itr.first);

        queue<char>qc;

        qc.push(itr.first);

        while(!qc.empty())
        {
            char ch=qc.front();
            qc.pop();

            for(char c : enfa[ch].first)
            {
                qc.push(c);
                st.insert(c);
            }
        }
        ep_closure.insert({itr.first, st});
    }

    cout<<"epsilon-closures: ";

    for(auto it : ep_closure)
    {
        cout << it.first << "\t";
        cout<<"{";
        for(auto c : it.second)
        {
            cout << c << " ";
        }
        cout << "}"<< "\n";
    }
    cout<<"Enter starting state: \n";
    char start_state, end_state;
    cin >> start_state ;
    cout<<"Enter final state: \n";
    cin>> end_state;

    q.push(ep_closure[start_state]);

    // bfs
    while(!q.empty())
    {
        set<char> gt;
        char c0=NULL, c1=NULL;

        gt=q.front();

        q.pop();

        if(visited.find(gt)!=visited.end() and visited[gt]==1)
        {
            continue;
        }

        visited[gt]=true;

        for(auto itr : gt)
        {
            for(char ch : enfa[itr].second.first)
            {
                if(ch >= 'a' and ch <= 'z')
                {
                    c0=ch; ///d
                }
            }
        }

        for(auto itr : gt)
        {
            for(char ch : enfa[itr].second.second)
            {
                if(ch >= 'a' and ch <= 'z')
                {
                    c1=ch; // d
                }
            }
        }

        //cout << ch0 << " " << ch1 << "\n";

        dfa.push_back({gt, {ep_closure[c0], ep_closure[c1]}});

        if(c0!=NULL)
        {
            q.push(ep_closure[c0]);
        }

        if(c1!=NULL)
        {
            q.push(ep_closure[c1]);
        }

        if(c0==c1 and c0!=NULL)
        {
            q.pop();
        }
    }

    printf("\n\nThe DFA table:\n\n");

    for(auto itr=dfa.begin(); itr!=dfa.end(); itr++)
    {
        cout<<"  ({";

        for(auto itr1=itr->first.begin(); itr1!=itr->first.end(); itr1++)
        {
            cout << *itr1;
            auto itr2=itr1;
            itr2++;
            if(itr2!=itr->first.end())
            {
                cout << ",";
            }
        }
        cout << "}, 0) \t\t= {";

        for(auto itr1=itr->second.first.begin(); itr1!=itr->second.first.end(); itr1++)
        {
            cout << *itr1;
            auto itr2=itr1;
            itr2++;
            if(itr2!=itr->second.first.end())
            {
                cout << ",";
            }
        }
        cout << "}\n";



        printf("  ({");


        for(auto itr1=itr->first.begin(); itr1!=itr->first.end(); itr1++)
        {
            cout << *itr1;
            auto itr2=itr1;
            itr2++;
            if(itr2!=itr->first.end())
            {
                cout << ",";
            }
        }
        cout << "}, 1) \t\t= {";

        for(auto itr1=itr->second.second.begin(); itr1!=itr->second.second.end(); itr1++)
        {
            cout << *itr1;
            auto itr2=itr1;
            itr2++;
            if(itr2!=itr->second.second.end())
            {
                cout << ",";
            }
        }
        cout << "}\n\n";
    }

    printf("Starting state is: { ");

    for(auto ch : ep_closure[start_state])
    {
        cout << ch << " ";
    }
    cout << "}\n\n";

    printf("Accepting states : ");

    for(auto itr : dfa)
    {
        set<char>get;

        get=itr.first;

        bool if_ending_state=false;

        for(auto ch : get)
        {
            if(ch == end_state)
            {
                if_ending_state=true;
                break;
            }
        }

        if(!if_ending_state)
        {
            continue;
        }

        cout << "{ ";

        for(auto ch : get)
        {
            cout << ch << " ";
        }
        cout << "} ";
    }
    cout << "\n\n";
}

/*
3
a b c
4
a p b
a 0 c
b p c
b 1 c
a c
5
a b c d e
5
a p b
a p c
b 0 d
c 1 d
d 1 e
a e
*/
