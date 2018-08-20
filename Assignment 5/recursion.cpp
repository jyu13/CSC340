#include <iostream>

using namespace std;

bool isPalindrome(const string& input);
int digitSum(int input);
int waysToClimb(int numStairs);

int main(){
	
	//test isPalindrome function
	cout<<"Test function isPalindrome : 1 is true, 0 is false."<<endl;
	cout<<"Is level palindrome? : "<<isPalindrome("level")<<endl;
	cout<<"Is clever palindrome? : "<<isPalindrome("clever")<<endl;
	cout<<"Is kokokok palindrome? : "<<isPalindrome("kokokok")<<endl;
	cout<<"Is adda palindrome? : "<<isPalindrome("adda")<<endl;
	cout<<"Is u palindrome? : "<<isPalindrome("u")<<endl;
	cout<<"Is ua palindrome? : "<<isPalindrome("ua")<<endl;
	cout<<endl;
	
	//test digitSum function
	cout<<"Test function digitSum : "<<endl;
	cout<<"The sum of 9871's digits is : "<<digitSum(9871)<<endl;
	cout<<"The sum of 239871's digits is : "<<digitSum(239871)<<endl;
	cout<<"The sum of 1856954's digits is : "<<digitSum(1856954)<<endl;
	cout<<"The sum of 9879871's digits is : "<<digitSum(9879871)<<endl;
	cout<<endl;
	
	//test waysToClimb function
	cout<<"Test fucntion waysToClimb £º"<<endl;
	cout<<"The ways to climb 3 stairs is : "<<waysToClimb(3)<<endl; 
	cout<<"The ways to climb 4 stairs is : "<<waysToClimb(4)<<endl; 
	cout<<"The ways to climb 5 stairs is : "<<waysToClimb(5)<<endl; 
	cout<<"The ways to climb 6 stairs is : "<<waysToClimb(6)<<endl; 
	cout<<"The ways to climb 7 stairs is : "<<waysToClimb(7)<<endl;
	return 0;
}

//isPalindrome function
bool isPalindrome(const string& input){
	
	int length = input.size();
	if(length == 1 || length == 0)
		return true;
	else if(input[0] == input[length-1]){
		return isPalindrome(input.substr(1,length-2)); 
	}	
	return false; 
}//end isPalindrome 

//digitSum function
int digitSum(int input){
	if(input<0){
		cout<<"Please enter a positive number."<<endl;
		return 0;
	}	
	if(input<10 && input >= 0){
		return input;
	}
	return input%10 + digitSum(input/10);
}//end digitSum

//waysToClimb function 
int waysToClimb(int numStairs){
	if(numStairs < 0)
		return 0;	
	else if(numStairs == 0)
		return 1;
	else if(numStairs == 1)
		return 1;
				
	return waysToClimb(numStairs - 2) + waysToClimb(numStairs - 1);
}//end waysToClimb
