// Given a string of comma-separated key-value pairs (e.g., "id=1,name=John,date=2023-10-23"),
// parse the string and store each pair in a hash map. 
// Write a function to retrieve values by key.
// Extension: Modify the function to handle multiple occurrences of the same key,
// storing the values as a list in the map.

#include<iostream>
#include<vector>
#include<map>
#include<sstream>
#include<set>
using namespace std;
map< string,set< string > >m;

// void split(string s)
// {
//     // stringstream ss(s);
//     // string w;
//     // vector<string>v;
//     // while(getline(ss,w,'='))
//     // {
//     //     v.push_back(w);
//     // }
//     // m[v[0]].push_back(v[1]);
//     stringstream ss(s);
//     string key, val;
//     getline(ss,key,'=');
//     getline(ss,val,'=');
//     m[key].insert(val);
// }

void parse(string s)
{
    stringstream ss(s);
    string token;
    // while(getline(ss,token,','))
    // {
    //     split(token);
    // }
    while (getline(ss,token,',')) {
        stringstream s1(token);
        string key, val;
        getline(s1,key,'=');
        getline(s1,val,'=');
        m[key].insert(val);
    }
    for(auto i:m)
    {
        cout<<i.first<<" -> { ";
        for(auto j:i.second)
        {
            // cout<<i.first<<" -> "<<j<<endl;
            cout<<j<<' ';
        }
        cout<<" }"<<endl;
    }
}

set<string> get(string key) {
    if (m.find(key) == m.end()) return {};
    return m[key];
}

int main()
{
    string s;
    getline(cin,s);
    parse(s);
    string key;
    cin>>key;
    set<string> values = get(key);
    if (values.empty()) {
        cout << "Key not found!" << endl;
    } else {
        cout << "Values for " << key << ": ";
        for (const string &val: values) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}