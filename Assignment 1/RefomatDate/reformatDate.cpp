/**This program will ask user input a date in the format: 2nd Jan 2012
 * output this format into 2012-01-02.
 * @author Jiadong Yu
 * @date Jun-16-2017
 * 
 */
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

string ReformatDate(string oldDate);
int stringToInt(string& s);

int main()
{

    string oldDate,newDate;    //define two variables
    cout<<"Please enter a date in the format: 1st Jan 2012"<<endl;
    cout<<"Year should be between 1900 and 2100."<<endl;
    cout<<"Or enter q to exit:"<<endl;
    getline(cin,oldDate);      //ask user for input
    if (oldDate == "q")        //enter q to quit    
       return 0;
    newDate = ReformatDate(oldDate);     //call function ReformatDate
    //cout<<"\ntest"<<endl;
    if (newDate == "q") 
    	return 0;
	else{
		cout<<"The date you entered is " << newDate<<endl; 
    	return 0;
	}
}


string ReformatDate(string oldDate)
{
    string newDate;
    string tempDate;
    string strWords[5];

    string trueDay;
    string month;
    int counter = 0,year,intDay;
    int size = oldDate.size();
    //separate the string entered
    for(int i=0; i<size; i++){
        strWords[counter] += oldDate[i];  
        if(oldDate[i] == ' '){
            counter++;
        }
    }
    
    //compare day and change format of day
    if (strWords[0] == "1st ")
        trueDay = "01";
        else if(strWords[0] == "2nd ")
            trueDay = "02";
        else if(strWords[0] == "3rd ")
            trueDay = "03";
        else if(strWords[0] == "4th ")
            trueDay = "04";       
        else if(strWords[0] == "5th ")
            trueDay = "05";            
        else if(strWords[0] == "6th ")
            trueDay = "06";            
        else if(strWords[0] == "7th ")
            trueDay = "07";            
        else if(strWords[0] == "8th ")
            trueDay = "08";            
        else if(strWords[0] == "9th ")
            trueDay = "09";            
        else if(strWords[0] == "10th ")
            trueDay = "10";            
        else if(strWords[0] == "11th ")
            trueDay = "11";
        else if(strWords[0] == "12th ")
            trueDay = "12";            
        else if(strWords[0] == "13th ")
            trueDay = "13";            
        else if(strWords[0] == "14th ")
            trueDay = "14";            
        else if(strWords[0] == "15th ")
            trueDay = "15";            
        else if(strWords[0] == "16th ")
            trueDay = "16";            
        else if(strWords[0] == "17th ")
            trueDay = "17";            
        else if(strWords[0] == "18th ")
            trueDay = "18";            
        else if(strWords[0] == "19th ")
            trueDay = "19";            
        else if(strWords[0] == "20th ")
            trueDay = "20";            
        else if(strWords[0] == "21th ")
            trueDay = "21";            
        else if(strWords[0] == "22th ")
            trueDay = "22";            
        else if(strWords[0] == "23th ")
            trueDay = "23";            
        else if(strWords[0] == "24th ")
            trueDay = "24";            
        else if(strWords[0] == "25th ")
            trueDay = "25";            
        else if(strWords[0] == "26th ")
            trueDay = "26";
        else if(strWords[0] == "27th ")
            trueDay = "27";            
        else if(strWords[0] == "28th ")
            trueDay = "28";            
        else if(strWords[0] == "29th ")
            trueDay = "29";            
        else if(strWords[0] == "30th ")
            trueDay = "30";
        else if(strWords[0] == "31th ")
            trueDay = "31";
        else {
            cout<<"The date you entered is not vaild. Please re-enter again or q to exit."<<endl;
            getline(cin,tempDate);
                if (tempDate == "q")        //enter q to quit    
        			return "q";
            	else{
					tempDate = ReformatDate(tempDate);
            		return tempDate;
				}       
        }
    
    //compare month and change format of month
    if (strWords[1] == "Jan ")
        month = "01";
        else if (strWords[1] == "Feb ")
            month = "02";
        else if (strWords[1] == "Mar ")
            month = "03";
        else if (strWords[1] == "Apr ")
            month = "04";
        else if (strWords[1] == "May ")
            month = "05";
        else if (strWords[1] == "Jun ")
            month = "06";
        else if (strWords[1] == "Jul ")
            month = "07";
        else if (strWords[1] == "Aug ")
            month = "08";
        else if (strWords[1] == "Sep ")
            month = "09";
        else if (strWords[1] == "Oct ")
            month = "10";
        else if (strWords[1] == "Nov ")
            month = "11";
        else if (strWords[1] == "Dec ")
            month = "12";
        else {
            cout<<"The date you entered is not vaild. Please re-enter again or q to exit."<<endl;
            getline(cin,tempDate);
                if (tempDate == "q")        //enter q to quit    
        			return "q";
            	else{
					tempDate = ReformatDate(tempDate);
            		return tempDate;
				}
        }
    
    //convert string year into integer
    year = stringToInt(strWords[2]);

    
    //check if the year is between 1900 and 2100 inclusive
    if (year > 2100 || year < 1900){
            cout<<"The date you entered is not vaild. Please re-enter again or q to exit."<<endl;
            getline(cin,tempDate);
                if (tempDate == "q")        //enter q to quit    
        			return "q";
            	else{
					tempDate = ReformatDate(tempDate);
            		return tempDate;
				}
    }
    
    //convert string trueDay into integer intDay
    intDay = stringToInt(trueDay);

    //check out if the date is vaild
    if((year%4 == 0 && month == "02" && intDay > 29 ) ||( month == "02" && intDay > 28) ||(month == "04" && intDay > 30) || (month == "06" && intDay > 30) || (month == "08" && intDay > 30) ||(month == "10" && intDay > 30)){
    	            cout<<"The date you entered is not vaild. Please re-enter again or q to exit."<<endl;
            getline(cin,tempDate);
                if (tempDate == "q")        //enter q to quit    
        			return "q";
            	else{
					tempDate = ReformatDate(tempDate);
            		return tempDate;
				}
    }
	
    //store as format 2012-01-01
    newDate = strWords[2] + '-' + month + '-' + trueDay;
    return newDate; 
}

//function change string object with integer represeation into integer.
int stringToInt(string& s){
	
	int size = s.size();
	int number = 0;
	for( int i = 0; i < size; i++){
		number = number*10 + s[i] - '0';
	}
			
	return number;
	
}//end stringToInt
