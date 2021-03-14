//Alexandos Galanis icsd14027
//algorithmos backtracking
//Ο(n!)
#include<iostream>

#define NODE 4


int graph[NODE][NODE];
int path[NODE];

using namespace std;

void displayCycle() {
    cout<<"The Hamilton Cycle : "<<endl;

    for (int i = 0; i < NODE; i++){
        cout<<path[i]<<endl;
    }
    cout<<path[0]<<endl;
}

bool isValid(int v, int k) {
    if (graph [path[k - 1]][v] == 0){
        return false;
    }

    for (int i = 0; i < k; i++){
        if (path[i] == v){
            return false;
        }
    }
    return true;
}

bool cycleFound(int k) {
    if (k == NODE) {
        if (graph[path[k - 1]][path[0] ] == 1 ){
            return true;
        }else{
            return false;
        }
    }

    for (int v = 1; v < NODE; v++) {
        if (isValid(v, k)) {
            path[k] = v;
            if (cycleFound (k+1) == true){
                return true;
            }
            path[k] = -1;
        }
    }
    return false;
}

bool hamiltonianCycle() {
    for (int i = 0; i < NODE; i++){
        path[i] = -1;
    }

    path[0] = 0;

    if ( cycleFound(1) == false ) {
        cout<<"Sorry friend";
        return false;
    }

    displayCycle();
    return true;
}

int main() {
    int i,j;

    cout<<"Enter the Graph : ";
    for (i = 0; i < NODE; i++){
        for (j = 0; j < NODE; j++){
            cout<<"Graph G("<<(i + 1)<<","<<(j + 1)<<")"<<endl;
            cin>>graph[i][j];
        }
    }

    cout<<"The Graph :"<<endl;
    for (i = 0; i < NODE; i++){
        for (j = 0; j < NODE; j++){
            cout<<"\t"<< graph [i][j];
        }
        cout<<endl;
    }

    cout<<endl;

    hamiltonianCycle();
}


