#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "funciones.h"

using namespace std;

void create(){
    fstream fout;
    fout.open("Viajes.csv",ios::out|ios::app);
    
    int i,day,month;
    string city,city2;
  
    for (i = 0; i < 5; i++) {
        cin >> city
            >> city2
            >> day
            >> month;
        fout << i << ", "
             << city << ", "
             << city2 << ", "
             << day << ", "
             << month
             << "\n";
    }
    fout.close();
}


int main(){
    //create();
    Graph g(4);
    g.addEdge("A","B",1);
    g.addEdge("C","A",5);
    g.addEdge("D","E",7);
    g.addEdge("E","A",5);
    g.display();
}