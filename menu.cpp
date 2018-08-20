#include <iostream>
using namespace std;

void Registration(string name, string address, long long int phone, long long int mobile) {
    cout << "enter user name : " << endl;
    cin >> name;
    cout << "enter address :" << endl;
    cin >> address;
    cout << "enter phone number :" << endl;
    cin >> phone;
    cout << "enter mobile number :" << endl;
    cin >> mobile;
}

int createMenuOptions() {
    cout << "Press 1 for login" << endl;
    cout << "Press 2 for new registrations" << endl;
    int option;
    cin >> option;
    return option;
}


struct subset{
    int parent;
    int rank;
};

int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

struct Profile{
    string owner_name;
    string address;
    int mobile;
    int phone;
    int password;
};

struct Node{
    int time;
    int nodeID;
    int parID;
    int childID;
};

map <int, Node> Nodes;

#define mp make_pair

void errorShow(int x){
    if(x == 1)cout << "Create a node first\n";
    if(x == 2)cout << "Parent doesnt exist\n";
    if(x == 3)cout << "Node doesnt exist\n";
}

int main(){
    struct subset *subsets =(struct subset*) malloc( V * sizeof(struct subset) );
    for (int v = 0; v < V; ++v){
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    int node_number = 0;
    while(true){
        int ch, f = 1;
        Node x;
        cin >> ch;
        switch(ch){
        case 1:
            x.time = time(0);
            x.nodeID = node_number;
            x.parID = node_number;
            x.childID = -1;
            f = 1;
            break;
        case 2:
            if(!f){
                errorShow();
                break;
            }
            M[node] = x;
            break;
        case 3:
            if(!f){
                errorShow(1);
                break;
            }
            cout << "Choose a set to add this to";
            int option;
            cin >> option;
            while(!M[option]){
                errorShow(2);
                cout << "Choose a set to add this to";
                int option;
                cin >> option;
            }
            Union(node_number, option);
            break;
        case 4:
            if(!f){
                errorShow(1);
                break;
            }
            break;
        case 5:
            if(!f){
                errorShow(1);
                break;
            }
            break;
        case 6:
            cout << "Choose a node to break apart";
            int option;
            cin >> option;
            while(!M[option]){
                errorShow(3);
                cout << "Choose a node to break apart";
                cin >> option;
            }
            subsets[option] = option;
            map<int, Node> :: iterator it;
            it=M.find(option);
            M.erase(it);
            break;
        case 7:
            cout << "Enter node to change the owner of:";
            int option;
            cin >> option;
            while(!M[option]){
                errorShow(3);
                cout << "Enter node to change the owner of:";
                cin >> option;
            }
            break;
        case 8:
            cout << "Enter node to find longest chain of";
            int option;
            cin >> option;
            while(!M[option]){
                errorShow(3);
                cout << "Enter node to find longest chain of";
                cin >> option;
            }
            map <int, Node> :: iterator it;
            for(it = M.begin(); it != M.end(); it++){
                int x = find(it->first);
                if(x == option){

                }
            }
            break;
        case 9:
            break;
        case 10:

    }
}
