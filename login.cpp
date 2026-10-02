#include<iostream>
#include<string>
using namespace std;
int main()
{
	string correctUsername = "yumnafaris"; //predefined correct username and password for demostration
	string correctPassword = "password123";
	string inputUsername, inputPassword;
	
	cout<<"Start application: tour mate" <<endl;
	cout<<"-----------------------------"<<endl;
	
	cout<<"Enter username: "; //check username
	cin>>inputUsername;
	
	if(inputUsername != correctUsername)
	{
		cout<<"Error: Incorrect username"<<endl;
		return 0;
	}
	cout<<"Enter password: "; //check password
	cin>>inputPassword;
	
	if(inputPassword != correctPassword)
	{
		cout<<"Error: Incorrect Password"<<endl;
		return 0;
	}
	cout<<"welcome "<<inputUsername<<" to Tour mate"<<endl; // credentials are correct
	return 0;
}