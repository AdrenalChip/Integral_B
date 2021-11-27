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

using namespace std;

unsigned int myHash(const string s) {
	unsigned int acum = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		acum += (int) s[i];
	}
	return acum;
}
array<string,100> generatearray(){
	string line;
	array<string,100> arr2;
	ifstream lee("ciudades.txt");   
	string u,v;
	int i=0;
	if (lee.is_open()){
		while(getline(lee,line)){
				arr2[i++]= line;
		}
		lee.close();
		}else{
			cout<<"Unable to open file";
		}
	return arr2;
}
array<int,100> generatearray2(int option){
	array<int,100> arr2;
	if(option==0){
		arr2[0]=0;
		arr2[1]=86;
		arr2[2]=591;
		arr2[3]=333;
		arr2[4]=2357;
		arr2[5]=508;
	}else if (option==1){
		arr2[0]=86;
		arr2[1]=0;
		arr2[2]=510;
		arr2[3]=252;
		arr2[4]=2110;
		arr2[5]=588;
	}else if (option==2){
		arr2[0]=595;
		arr2[1]=513;
		arr2[2]=0;
		arr2[3]=246;
		arr2[4]=2007;
		arr2[5]=902;
	}else if (option==3){
		arr2[0]=338;
		arr2[1]=256;
		arr2[2]=247;
		arr2[3]=0;
		arr2[4]=1855;
		arr2[5]=840;
	}else if (option==4){
		arr2[0]=2351;
		arr2[1]=2114;
		arr2[2]=2007;
		arr2[3]=1854;
		arr2[4]=0;
		arr2[5]=2962;
	}else if (option==5){
		arr2[0]=507;
		arr2[1]=589;
		arr2[2]=899;
		arr2[3]=836;
		arr2[4]=2968;
		arr2[5]=0;
	}
	return arr2;
}

int main(){
	int flag=0;
	while (flag==0){
			array<string,100> arr=generatearray();
			int size=sizeof(arr)/sizeof(arr[0]);
			weightedGraph<string> myGraph(size);
			queue<string> adjacents;
			for (int i=0;i<size;i++){
			myGraph.addVertex(arr[i]);
		}
		myGraph.addEdge("Monterrey","Durango",1);
		myGraph.addEdge("Durango","Tampico",1); 
		myGraph.addEdge("Durango","Saltillo",1); 
		myGraph.addEdge("Torreon","Monterrey",1);
		myGraph.addEdge("Tijuana","Torreon",1);
		myGraph.addEdge("Torreon","Tijuana",1); 
		myGraph.addEdge("Tampico","Monterrey",1); 
		myGraph.addEdge("Saltillo","Torreon",1); 
			cout<<"Bienvenido\nQue desea hacer?\n1.-Viaje\n2.-Agregar un destino\n3.-Salir\n";
		int x;
		cin>>x;
		if (x==1){
			cout<<"Desde que lugar inicia tu viaje? Ingresa numero \n1.-Monterrey \n2.-Saltillo \n3.-Durango \n4.-Torreon \n5.-Tijuana \n6.-Tampico\n";
    		int Inicio;
			cin>>Inicio;
			cout<<"A donde quieres llegar? Ingresa numero \n1.-Monterrey \n2.-Saltillo \n3.-Durango \n4.-Torreon \n5.-Tijuana \n6.-Tampico\n";
    		int Final;
			cin>>Final;
			cout<<"El orden a seguir del viaje es el siguiente:\n";
			myGraph.DFS(arr[Inicio-1],arr[Final-1]);
			int serach=myGraph.getIndex(arr[Inicio-1]);

			array<int,100> arr2=generatearray2(serach);
    		Quadratic < string , int > city(100,string("empty"), myHash );
			for (int i=0;i<size;i++){
				city.put(string(arr[i]),arr2[i]);
			}
			cout<<"\nLa distancia de "<< arr[Inicio-1]<<" a "<<arr[Final-1]<<" son "<<city.get(arr[Final-1])<<" km\n";	
		}
		else if(x==2){
				cout<<"Que ciudad va agregar? (No espacios)";
				string add;
				cin>>add;
				ofstream foutput; 
 				ifstream finput;
 				finput.open ("ciudades.txt");
 				foutput.open ("ciudades.txt",ios::app); 
 				if(finput.is_open())
   					foutput<<"\n"<<add<<"\n"; 
 				finput.close();
 				foutput.close();
				cout<<"¿Con que ciudad se conecta?";
				for (int i=0;i<size;i++){
					cout<< i+1<<".-"<<arr[i]<<"\n";
				}


		}else if(x==3){
			flag=1;
			
		}
	}
	cout<<"Gracias por participar";
	return 0;
}
