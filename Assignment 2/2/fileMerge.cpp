#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void fileMerge(fstream& ,fstream& );

int main(){
	
    string file1,file2;
    bool open = false;
    fstream merge1,merge2;
    
    do{
    	cout<<"Please enter two file names: "<<"\nOr press q two times to exit."<<endl;
		cin>>file1>>file2; 					 //intFile1 , intFile2 
		
		if(file1 == "q" && file2 == "q")
			return 0;
    	merge1.open(file1+".txt");
    	merge2.open(file2+".txt");
    
   		if(merge1.fail()||merge2.fail())
    		cout<<"File does not exist."<<endl;
    	else{
    	    cout<<"File open success."<<endl;
    	    open = true;
    	}
    }while(open == false);
    
    cout<<"Merging "<<file1<<" and "<<file2<<endl;
    fileMerge(merge1,merge2);
    
    merge1.close();
    merge2.close();
    
    return 0;
}

void fileMerge(fstream& merge1,fstream& merge2){
	
	int number1,number2;
    ofstream finalFile; 
    bool close = true;
	finalFile.open("fileMerged.txt");
	finalFile.clear();
	
	merge1>>number1;
	merge2>>number2;
	
	while(merge1 || merge2 ){
		if(merge1 && merge2){
			if(number1<=number2){
				finalFile<<number1<<endl;
				merge1>>number1;
			}
			else{
				finalFile<<number2<<endl;
				merge2>>number2;
			}	
		}
		else if(merge1){
			finalFile<<number1<<endl;
			merge1>>number1;
			
		}
		else if(merge2){
			finalFile<<number2<<endl;
			merge2>>number2; 
		}
				
	}
	
	finalFile.close();
	cout<<"Merge Successful to fileMerged.txt"<<endl;
}


