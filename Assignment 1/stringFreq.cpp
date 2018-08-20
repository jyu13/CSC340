/**This program will ask user input a text and find out how many times each words appeared.
 * @author Jiadong Yu
 * @date Jun-18-2017
 * 
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//define struct with two variables
struct TokenFreq{

    string token;
	int freq;
};

void getLeastFreqLetter(string& s);

vector<TokenFreq> getTokenFreq(string& s);


int main()
{
    string s;
    vector<TokenFreq> vecWords;
    
    getline(cin,s); //ask for input
    
    vecWords = getTokenFreq(s);//call function getTokenFreq with parameter s
	
	int size = vecWords.size();
	
	for(int i = 0; i < size; i++){
		cout<<" \'"<<vecWords[i].token<<"\': ";
		cout<<vecWords[i].freq<<",";
	}// output the result
    
    getLeastFreqLetter(s); //output the least letter appeared in the text
}

//function getLeastFreqLetter will output the least letter appeared in the text.
void getLeastFreqLetter(string& s){
	
	vector<TokenFreq> temp;
	temp = getTokenFreq(s);
	int size = temp.size();
	int min = temp[0].freq;
	string tempToken = temp[0].token;
	for(int i = 0; i < size; i++){
		if(min > temp[i].freq ){
			min = temp[i].freq;
			tempToken = temp[i].token;
		}
		if (min == temp[i].freq && (tempToken > temp[i].token)){
			tempToken = temp[i].token;
		}
	}
	cout<<"\nThe least Frequency Letter is: "<<tempToken<<" with frequency: "<<min<<endl;
}//end getLeastFreqLetter


//function getTokenFreq will store a string and its frequceny as a pair in a defined struct vector.
vector<TokenFreq> getTokenFreq(string& s){
	
	int size = s.size();
	int i = 0,count = 0;
	string strWords[500];
	vector<TokenFreq> tokenFreq;

    //go through the text, store each word in an array and delete space, comma, and period.
	while(i<size){
		if(s[i] == ' ' || s[i] == ',' || s[i] == '.'){
			count+=1;
			i++;
		}
		else{
		    strWords[count] += s[i];
		    i++;
		}
	}
		
	//go through the array, delete duplicate and count frequency.
	for (int j = 0; j < count;){
		if (strWords[j] == ""){
			j++;
		}
		else{
			int freq=1;
		    for(int k = j+1; k < count; k ++){
		    	if(strWords[j] == strWords[k]){
					strWords[k] = "";
					freq++;
				}
			}
			tokenFreq.push_back({strWords[j],freq});
			j++;
		}
		
				
	}
	return tokenFreq; //return the paired vector
}//end getTokenFreq
























