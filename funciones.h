
#ifndef Graph_H_
#define Graph_H_

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

template <class Key, class Value>
class Quadratic {
private:
	unsigned int (*func) (const Key);
	unsigned int size;
	unsigned int count;
	
	Key *keys;
	Key initialValue;
	Value *values;
	
	long indexOf(const Key) const;
	
public:
	Quadratic(unsigned int, Key, unsigned int (*f) (const Key));
	~Quadratic();
	bool full() const;
	bool put(Key, Value);
	bool contains(const Key) const;
	Value get(const Key) ;
	void clear();
	std::string toString() const;
};

template <class Key, class Value>
Quadratic<Key, Value>::Quadratic(unsigned int sze, Key init, unsigned int (*f) (const Key)){
	size=sze;
    initialValue=init;
    func=f;
	count=0;
	keys=new Key[size];
	values=new Value[size];
	for(int i=0;i<size;i++){
		keys[i]=initialValue;
		values[i]=0;
	}
}

template <class Key, class Value>
Quadratic<Key, Value>::~Quadratic() {
	size=0;
	initialValue="";
	func=0;
	count=0;
	delete [] keys;
	delete [] values;
	keys=0;
	values=0;
}

template <class Key, class Value>
bool Quadratic<Key, Value>::full() const {
	if(count>=size){
		return true;
	}
	return false;
}

template <class Key, class Value>
long Quadratic<Key, Value>::indexOf(const Key k) const {
	long ind=func(k)%size;
	long start=ind;
	for(int j=0;j<size;j++){
		if(keys[ind]==k){
			return ind;
		}
		ind=(start+j*j)%size;
	}


	return -1;// Si no se encuentra la llave
}

template <class Key, class Value>
bool Quadratic<Key, Value>::put(Key k, Value v) {
	if (full()) {
		return false;
	}
	long pos=func(k);
	pos = indexOf(k);
	if (pos != -1) {
		values[pos] = v;
		return true;
	}
	unsigned int start=func(k)%size;
	unsigned int i=func(k)%size;
	for(int j=0;j<size;j++){
		if(keys[i]==initialValue){
			values[i]=v;
			keys[i]=k;
			return true;
		}
		i=(start+j*j)%size;
	}
	return false;
}

template <class Key, class Value>
bool Quadratic<Key, Value>::contains(const Key k) const {
	if(indexOf(k)==-1){
		return false;
	}
	return true;
}

template <class Key, class Value>
Value Quadratic<Key, Value>::get(const Key k) {
	if(contains(k)){
		long r=indexOf(k);
		return values[r];
	}
	return -1;//Valor no encontrado
}

template <class Key, class Value>
void Quadratic<Key, Value>::clear() {
	for (int i=0;i<size;i++){
		values[i]=0;
		keys[i]=initialValue;
	}
	count=0;
}


//impresion clase quadratic
template <class Key, class Value>
std::string Quadratic<Key, Value>::toString() const {
	std::stringstream aux;
	for (int i = 0; i < size; i++){
			if (keys[i] != initialValue){
				aux << "(" << i << " ";
			  aux << keys[i] << " : " << values[i] << ") ";
			}
	}
	return aux.str();
}
////////////////////////////////////////////
///////////////////////////////////////////


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
			std::cout<<"Unable to open file";
		}
	return arr2;
}


array<int,100> generatearray2(int option,int size){
	array<int,100> arr2;
	if(option==0){
		for (int i=0;i<size;i++){
		arr2[i]= rand() %40+100;
	}
	}else if (option==1){
		for (int i=0;i<size;i++){
		arr2[i]= rand() %70+420;
	}
	}else if (option==2){
		for (int i=0;i<size;i++){
		arr2[i]= rand() %100+400;
	}
	}else if (option==3){
		for (int i=0;i<size;i++){
		arr2[i]= rand() %1000+3000;
	}
	}else if (option==4){
		for (int i=0;i<size;i++){
		arr2[i]= rand() %2500+3000;
	}
	}else if (option==5){
		for (int i=0;i<size;i++){
		arr2[i]= rand() %100+500;
	}
	}else{
		for (int i=0;i<size;i++){
		arr2[i]= rand() %70+3000;
	}
	}
	return arr2;
}

void write(string add){
	ofstream foutput; 
 	ifstream finput;
 	finput.open ("ciudades.txt");
 	foutput.open ("ciudades.txt",ios::app); 
 	if(finput.is_open())
   		foutput<<"\n"<<add; 
	finput.close();
	foutput.close();
}

void newfile(){
	ifstream myfile;
	myfile.open("ciudades.txt");
	ofstream temp;
	string line;
	string name = "Tepito";
	temp.open("temp.txt");
	while (getline(myfile, line))
	{
	if (line != name){
	temp << line << endl;
	}else break;
}
myfile.close();
temp.close();
remove("ciudades.txt");
rename("temp.txt", "ciudades.txt");
}
/////////////////////////////////
////////////////////////////////

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
void print(int arr[], int n)
{
	cout<<"La ciudad mas cercana esta "<<arr[1] <<"km\n";
    /*for (int i = 0; i < n; i++)
        cout << arr[i] << " ";*/
}
 


#endif /* Graph_H_ */
