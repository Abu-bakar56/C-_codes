#include<iostream>
#include<fstream>
using namespace std;
void registration(){
	string name,checkname;
	bool samename;
	ifstream check_name.open("haha.txt");
	do{
		
		cout<<"enter the name "<<endl;
		getline(cin,name);
		samename=false;
		check_name.clear();
		check_name.seekg(0,ios::beg);
		while(check_name.eof()==0){
		getline(check_name,checkname);
		if(checkname==name){
			samename=true;
			cout<<"name is already taken";
			break;
		}
	}
}while(samename);
check_name.close;
ofstream savename.open("haha.txt",ios::app);
savename<<name<<endl;
savename.close();
}
// #include<iostream>
// #include<fstream>
// using namespace std;
// void registeration(){
	
// 	string name,checkname;
// 	bool samename;
// 	ifstream write("haha.txt");
// 	do{
// 	cout<<"Enter a username : ";
// 	getline(cin,name);
// 	samename = false;
// 	write.clear();
// 	write.seekg(0,ios::beg);
// 	while(write.eof()==0){
// 		getline(write,checkname);
// 		if(checkname==name){
// 			samename = true;
// 			cout<<"This username is already taken .";
// 			break;
// 		}
// 	}
// 	}while(samename);
// 	write.close();
// 	ofstream writee("haha.txt",ios::app);
// 	writee<<name<<endl;
// 	writee.close();
// 	}