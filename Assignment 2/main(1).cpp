#include <iostream>
using namespace std;
int main()
{
	int a[4];
	bool valid[4] = { true, true,true,true };
	int hour = 0;
	int minute = 0;
	bool success = false;
	cin >> a[0] >> a[1] >> a[2] >> a[3];

	for (int h = 24; h > 0; h--)
	{
  		for (int i = 0; i < 4; i++)
  		{			
   			if (h / 10 == a[i] && valid[i])
   			{
    			valid[i] = false;
    			for (int j = 0; j < 4; j++)
    			{
     				if (h % 10 == a[j] && valid[j])
     				{	
      					valid[j] = false;
     					hour = a[i] * 10 + a[j];
      					success = true;
      					break;
     				}
   				}
    			if (success != true)
    			{
     				valid[i] = true;
    			}
    			else
    			{
     				break;
    			}
   			}		
  		}
  		if (success == true)
  		{
   			success = false;
   			break;
  		}
	}

	for (int m = 60; m > 0; m--)
 	{
  		for (int i = 0; i < 4; i++)
  		{
   			if (m / 10 == a[i] && valid[i])
   			{	
    			valid[i] = false;
    			for (int j = 0; j < 4; j++)
    			{
     				if (m % 10 == a[j] && valid[j])
     				{
      					valid[j] = false;
      					minute = a[i] * 10 + a[j];
      					success = true;
      					break;
     				}
    			}
    			if (success != true)
    			{
     				valid[i] = true;
    			}
    			else
   				{
			    	break;
   				}
   			}
  		}
  		if (success == true)
  		{
   			success = false;
   			break;
  		}
 	}

 	if ((valid[0] || valid[1] || valid[2] || valid[3]) != false)
 	{
  		cout << "NOT POSSIBLE";
 	}
 	else
 	{
  		cout << hour << ":" << minute;
 	}
 	return 0;
}
