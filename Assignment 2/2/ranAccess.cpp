#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void insertInt(fstream& file, int position);

int main(){
	
	int num_space = 5;
	fstream fput;
	fput.open("file.txt");
	
	if(fput.fail())
		cout<<"File open failed."<<endl;
	else
		cout<<"File open successful."<<endl;
		
	insertInt(fput, 6000*num_space);
	
	return 0;
} 


void insertInt(fstream& fput, int position){
	
	string number;
	vector<string> temp;
	fput.seekg(position);
	fput>>number;
	while(!fput.eof()){
		
		temp.push_back(number);
		fput>>number;
	}
	fput.clear();
	fput.seekp(position);
	
	for(int i = 7777; i <=7781 ; i++){

		fput<<i<<endl;
	}
	int size = temp.size();
	for(int i = 0 ; i < size; i ++){
		fput<<temp[i]<<endl;
	}
	
	cout<<"Insert successful."<<endl;
		
}
