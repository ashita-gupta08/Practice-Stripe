// - Given a list of shipments represented as dictionaries with 
// attributes like destination, weight, and status, process the shipments 
// to categorize them by status (e.g., delivered, in transit, delayed).
// Write a function that returns a summary of shipments by status.

// - Extension: Add functionality to filter the shipments by destination 
// and sort them by weight.
//   **String Processing and HashMap**:

#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<set>

using namespace std;

struct Shipment{
    string dest;
    double wt;
    string status;
};

map<string, vector<Shipment>> stat;
map<string,set<pair<double,string> > > parceldest;


void getstatus(const vector<Shipment> &shipments)
{
    for(const auto &i:shipments)
    {
        stat[i.status].push_back(i);
    }
}

void sortdest(const vector<Shipment> &shipments)
{
    for(const auto &i:shipments)
    {
        parceldest[i.dest].insert({i.wt,i.status});
    }
}

void summary()
{
    for(const auto &i:stat)
    {
        cout<<i.first<<" -> "<<endl;
        for(const auto &j:i.second)
        {
            string des=j.dest;
            double weight=j.wt;
            cout<<"Destination : "<<des<<" , Weight : "<<weight<<endl;
        }
        cout<<endl;
    }
}

void destsummary()
{
    for(const auto &i:parceldest)
    {
        cout<<i.first<<" -> "<<endl;
        for(const auto &j:i.second)
        {
            cout<<"Weight: "<< j.first<<", Status: "<<j.second<<endl;
        }
        cout<<endl;
    }
}

int main()
{
    vector<Shipment> shipments = {
    {"New York", 10.5, "delivered"},
    {"San Francisco", 15.0, "in transit"},
    {"New York", 8.0, "delivered"},
    {"Chicago", 12.3, "delayed"},
    {"San Francisco", 7.5, "in transit"},
    {"Chicago", 9.0, "delivered"}
    };
    // vector<Shipment>shipments;
    // int n;
    // cin>>n;
    // for (int i = 0; i < n; ++i) {
    //     string destination, status;
    //     double weight;
    //     cout << "Enter destination for shipment " << i+1 << ": ";
    //     cin >> destination;
    //     cout << "Enter weight for shipment " << i+1 << ": ";
    //     cin >> weight;
    //     cout << "Enter status for shipment " << i+1 << ": ";
    //     cin >> status;
    //     shipments.push_back({destination, weight, status});
    // }
    getstatus(shipments);
    summary();
    sortdest(shipments);
    destsummary();
    return 0;
}