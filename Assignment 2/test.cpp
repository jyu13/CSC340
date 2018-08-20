#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(){
	
	fstream inputFile("file1.txt");
	int x;
	inputFile.clear();
	int position;
	vector<int> numbers;

	//while(inputFile.tellg() <= BYTES_PER_NUMBER*MAX_NUMBERS_TO_READ)

	for(int i = 0; i < 6001; i++){
		if(i == 6000){
			position = inputFile.tellg() + 1;
		}
		inputFile >> x;
	}
	
	while(true){
		numbers.push_back(x);
		inputFile >> x;
		if(inputFile.fail()){
			break;
		}
		
	}
	
	inputFile.clear();
	inputFile.seekp(position);
	for(int i = 7777; i < 7782; i++){
		inputFile << i << endl;
	}

	for(int i: numbers){
		inputFile << i << endl;
	}
	
	
	return 0;
}

