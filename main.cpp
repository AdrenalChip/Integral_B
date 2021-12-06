/*
 *Proyecto Integral B
 *Main del programa 
 *Jorge Guerrero Díaz
 *A01411752
 *06/12/2021
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <array>
#include "funciones.h"
#include "DiGrapht.h"
#include "weight.h"
#include "radix.h"

using namespace std;

unsigned int myHash(const string s) {
	unsigned int acum = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		acum += (int) s[i];
	}
	return acum;
}

int main(){
	int flag=0;
	vector <string> arr3={"Monterrey","Saltillo"};
	vector <vector<string>> arr2;
	write("Tepito");
	int lugar=0;
	while (flag==0){
			arr2.push_back(arr3);
			array<string,100> arr=generatearray();
			int size=sizeof(arr)/sizeof(arr[0]);			

			weightedGraph<string> myGraph(size);
			queue<string> adjacents;
			for (int i=0;i<size;i++){
			myGraph.addVertex(arr[i]);
			}

		myGraph.addEdge(arr[0],arr[2],1); // Monterrey -> Durango
		myGraph.addEdge(arr[2],arr[5],1); // Durango -> Tampico
		myGraph.addEdge(arr[2],arr[1],1); //
		myGraph.addEdge(arr[3],arr[0],1);
		myGraph.addEdge(arr[4],arr[3],1);
		myGraph.addEdge(arr[3],arr[4],1); 
		myGraph.addEdge(arr[5],arr[0],1); //Tampico -> Monterrey
		myGraph.addEdge(arr[1],arr[3],1); //Saltillo
		myGraph.addEdge(arr[6],arr[0],1);

			std::cout<<"Bienvenido\nQue desea hacer?\n1.-Viaje\n2.-Ciudad mas cercana esta a\n3.-Salir\n";
		int x;
		cin>>x;
		if (x==1){
			std::cout<<"Desde que lugar inicia tu viaje? Ingresa numero\n";
			int i=0;
			while (arr[i] != "\0"){
				std::cout<<i<<".-"<<arr[i]<<"\n";
				i=i+1;
			}
    		int Inicio;
			cin>>Inicio;
			std::cout<<"A donde quieres llegar? Ingresa numero \n";
			int i2=0;
			while (arr[i2] != "\0"){
				std::cout<<i2<<".-"<<arr[i2]<<"\n";
				i2=i2+1;
			}
    		int Final;
			cin>>Final;
			std::cout<<"El orden a seguir del viaje es el siguiente:\n";
			myGraph.DFS(arr[Inicio],arr[Final]);
			int serach=myGraph.getIndex(arr[Inicio]);

			array<int,100> arr4=generatearray2(serach,i2);
    		Quadratic < string , int > city(i2,string("empty"), myHash );
			for (int i=0;i<i2;i++){
				city.put(string(arr[i]),arr4[i]);
			}
			std::cout<<"\nLa distancia de "<< arr[Inicio]<<" a "<<arr[Final]<<" son "<<city.get(arr[Final])<<" km\n";	
		}else if(x==2){
				cout<<"Desde que ciudad? (ingrese un numero del 1 hasta el ...) \n";
				int i=0;
				while(arr[i] != "\0"){
						std::cout<<i<<".-"<<arr[i]<<"\n";
						i=i+1;
					}
					int y;
					cin>>y;
				int serach=myGraph.getIndex(arr[y]);
				array<int,100> arr4=generatearray2(serach,i);
				int arr5[i];
				int j=0;
				for (int j=0;j<i;j++){
					arr5[j]=arr4[j];
				}
    			radixsort(arr5,i);
				print(arr5,i);
		}else if(x==3){
			flag=1;
		}
		lugar=lugar+1;
	}
	newfile();
	std::cout<<"Gracias por participar";
	return 0;
}
