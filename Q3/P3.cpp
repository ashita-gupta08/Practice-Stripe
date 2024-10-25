// - Parse a string representing multiple messages, 
// each containing an ID, timestamp, and message body.
// Store the messages in a hash map, indexed by their ID.
// Write a function to retrieve messages by ID, sorted by timestamp.
 
// - Extension: Add functionality to retrieve messages
// for a given range of timestamps.
// **Class-Based Design with Refactoring**:
  
// "ID1,2024-10-22T10:30:00,Message body 1;ID2,2024-10-22T10:35:00,Message body 2;ID1,2024-10-22T10:40:00,Message body 3;ID3,2024-10-22T10:32:00,Message body 4;"

  
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<sstream>
#include<cctype>

using namespace std;

map<string,vector<pair<string,string> > >m;

void store(const string &input)
{
    string w="";
    // for(auto i:input)
    // {
    //     if(i==';')
    //     {
    //         string token;
    //         stringstream ss(w);
    //         string id,timestamp,msg;
    //         getline(ss,id,',');
    //         getline(ss,timestamp,',');
    //         getline(ss,msg,',');
    //         m[id].push_back({timestamp,msg});
    //         w="";
    //     }
    //     else
    //     {
    //         w+=i;
    //     }
    // }
    // if(w!="")
    // {
    //     string token;
    //     stringstream ss(w);
    //     string id,timestamp,msg;
    //     getline(ss,id,',');
    //     getline(ss,timestamp,',');
    //     getline(ss,msg,',');
    //     m[id].push_back({timestamp,msg});
    // }
    
    stringstream s1(input);
    while(getline(s1,w,';'))
    {
        string token;
        stringstream ss(w);
        string id,timestamp,msg;
        getline(ss,id,',');
        getline(ss,timestamp,',');
        getline(ss,msg,',');
        m[id].push_back({timestamp,msg});
    }
    for(auto i:m)
    {
        cout<<i.first<<" : "<<endl;
        for(auto j:i.second)
        {
            cout<<j.first<<" "<<j.second<<endl;
        }
    }
}


static bool cmp(const pair<string,string> &p1,const pair<string,string> &p2)
{
    return p1.first<p2.first;
}

void retrieve(string id)
{
    if(m.find(id)==m.end())
    {
        cout<<"No such ID found"<<endl;
        return;
    }
    sort(m[id].begin(),m[id].end(),cmp);
    cout << "Messages for ID: " << id << endl;
    for (const auto &i : m[id]) {
        cout << i.first << ": " << i.second << endl;
    }
}

string tokenize(const string &id)
{
    // for(auto &i:id)
    // {
    //     if(i>='a' && i<='z')
    //     {
    //         i=toupper(i);
    //     }
    // }
    string newid = id;
    transform(newid.begin(), newid.end(), newid.begin(), ::toupper);
    return newid;
}

void rangeretrieval(const string &id, const string &st, const string &end)
{
    if(m.find(tokenize(id))==m.end())
    {
        cout<<"No such ID found"<<endl;
        return;
    }
    vector<pair<string,string>>msgs=m[id];
    sort(msgs.begin(),msgs.end(),cmp);
    for(const auto &i:msgs)
    {
        if(i.first>=st && i.first<=end)
        {
            cout<<tokenize(id)<<": "<<i.first<<" "<<i.second<<endl;
        }
    }
}

int main()
{
    string input;
    getline(cin,input);
    //Assuming all ids are in block
    // ID1,2024-10-22T10:40:00,Message body 1;ID2,2024-10-22T10:35:00,Message body 2;ID1,2024-10-22T10:20:00,Message body 3;ID3,2024-10-22T10:32:00,Message body 4;
    store(input);
    string id;
    cin>>id;
    id=tokenize(id);
    retrieve(id);
    rangeretrieval("ID1", "2024-10-22T10:25:00", "2024-10-22T10:45:00");
    return 0;
}