#include <iostream>

using namespace std;

string MaxTime(int a, int b, int c, int d); 

int main()
{
    int a, b, c, d;
    string maxTime;
    bool vaild = false;
    
    
    cout<<"Please enter 4 digits: "<<endl;
    do{
   	    cin>>a>>b>>c>>d;
   		if(a<0||b<0||c<0||d<0){
    	cout<<"Please enter vaild digits"<<endl;
	}
	else
		vaild = true;
		    
	}while(vaild == false);
	
	if(a>2 && b>2 && c>2 && d>2)
		cout<<"Not possible.";
	else{
		maxTime = MaxTime(a,b,c,d);
    
    	if(maxTime == "0:0")
    		cout<<"Not possible.";
    	else
    		cout<<"The max time in 24-hour format is : "<< maxTime <<endl; 
	}
	return 0;
}


string MaxTime(int a, int b, int c, int d){
	
	string maxTime;
	int hour = 0,minute = 0, tempMin = 0;
	
	if((a*10+b)<=23 && hour < (a*10+b)){
		
		if((c*10+d)<=59 && (c*10+d) >= (d*10+c)){
			hour = a*10+b;
			minute = c*10+d;
		}
		
		else if((d*10+c)<=59){			
			hour = a*10+b;
			minute = d*10+c;
		}		
	}
	
	if((b*10+a)<=23 && hour < (b*10+a)){
		
		if((c*10+d)<=59 && (c*10+d) >= (d*10+c)){
			hour = b*10+a;
			minute = c*10+d;
		}
		
		else if((d*10+c)<=59){			
			hour = b*10+a;
			minute = d*10+c;
		}		
	}
	
	if((a*10+c)<=23 && hour < (a*10+c)){
		
		if((b*10+d)<=59 && (b*10+d) >= (d*10+b)){
			hour = a*10+c;
			minute = b*10+d;
		}
		
		else if((d*10+b)<=59){			
			hour = a*10+c;
			minute = d*10+b;
		}		
	}

	if((c*10+a)<=23 && hour < (c*10+a)){
		
		if((b*10+d)<=59 && (b*10+d) >= (d*10+b)){
			hour = c*10+a;
			minute = b*10+d;
		}
		
		else if((d*10+b)<=59){			
			hour = c*10+a;
			minute = d*10+b;
		}		
	}

	if((a*10+d)<=23 && hour < (a*10+d)){
		
		if((b*10+c)<=59 && (b*10+c) >= (c*10+b)){
			hour = a*10+d;
			minute = b*10+c;
		}
		
		else if((c*10+b)<=59){			
			hour = a*10+d;
			minute = c*10+b;
		}		
	}

	if((d*10+a)<=23 && hour < (d*10+a)){
		
		if((b*10+c)<=59 && (b*10+c) >= (c*10+b)){
			hour = d*10+a;
			minute = b*10+c;
		}
		
		else if((c*10+b)<=59){			
			hour = d*10+a;
			minute = c*10+b;
		}		
	}
	
	if((b*10+c)<=23 && hour < (b*10+c)){
		
		if((a*10+d)<=59 && (a*10+d) >= (d*10+a)){
			hour = b*10+c;
			minute = a*10+d;
		}
		
		else if((d*10+a)<=59){			
			hour = b*10+c;
			minute = d*10+a;
		}		
	}
	
	if((c*10+b)<=23 && hour < (c*10+b)){
		
		if((a*10+d)<=59 && (a*10+d) >= (d*10+a)){
			hour = c*10+b;
			minute = a*10+d;
		}
		
		else if((d*10+a)<=59){			
			hour = c*10+b;
			minute = d*10+a;
		}		
	}
	
	if((b*10+d)<=23 && hour < (b*10+d)){
		
		if((a*10+c)<=59 && (a*10+c) >= (c*10+a)){
			hour = b*10+d;
			minute = a*10+c;
		}
		
		else if((c*10+a)<=59){			
			hour = b*10+d;
			minute = c*10+a;
		}		
	}	
		
	if((d*10+b)<=23 && hour < (d*10+b)){
		
		if((a*10+c)<=59 && (a*10+c) >= (c*10+a)){
			hour = d*10+b;
			minute = a*10+c;
		}
		
		else if((c*10+a)<=59){			
			hour = d*10+b;
			minute = c*10+a;
		}		
	}	

	if((c*10+d)<=23 && hour < (c*10+d)){
		
		if((a*10+b)<=59 && (a*10+b) >= (c*10+b)){
			hour = c*10+d;
			minute = a*10+b;
		}
		
		else if((b*10+a)<=59){			
			hour = c*10+d;
			minute = b*10+a;
		}		
	}

	if((d*10+c)<=23 && hour < (d*10+c)){
		
		if((a*10+b)<=59 && (a*10+b) >= (c*10+b)){
			hour = d*10+c;
			minute = a*10+b;
		}
		
		else if((b*10+a)<=59){			
			hour = d*10+c;
			minute = b*10+a;
		}		
	}

	maxTime = to_string(hour)+ ":" + to_string(minute);
	return maxTime;
}

