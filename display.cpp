//Name:-Sagar Mhantati
//Editor:- Dev-C++
//Last Modified Date:- 23/05/2018
//GK Test using CPP
/* Description:-
I have made Functions class in which I have added methods as follows:-

1)help():- Instructions for how to play this game.
2)mainhome() :-home part which is first display part of program.
3)displayscore():- It is used to display the score which is stored in seprate file named 'display.txt'.
					Every time when user play this game Iam storing his/her score in that file.
4)writescore():- Used to write player name and his respected score in the file.
5)questions():- This is used to pick up the questions from the file name 'example.txt'.
6)main() :- In this I have created object of class Functions and called it's respective method.I have used srand() and rand() to generate random values for 
			questions.
			
Excecution flow:-									main()
													  |
												call to  mainhome()
													  |
				-----------------------------------------------------------------------------------------
				|							|								|							|
			 help()						displayscore()					  start()						quite()
				|							|								|								|
			display the 				Opening file 'score.txt'		  pick up random				exit()
			instructions					|							  value
				|						Displaying playername 				|
			call to mainhome()			and score						  call to questions()
											|								|
										call to mainhome()				  answer coorect answer 
																		  ans respected ans. are
																		  counted
																		    |
																		  call to mainhome()		
















*/
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include <fstream>
#include<limits>
#include<windows.h>
#include<vector>
#include<ctype.h>
#include"test1.h"
#include<conio.h>
using namespace std;
class Functions
{
  	public:
  	void help()
  	{
 		cout<<"\n\n\n\tThis game is very easy to play. You'll be asked some general";
 		cout<<"\n\n\tknowledge questions and the right answer is to be chosen among";
  		cout<<"\n\n\tthe four options provided. Your score will be calculated at the"; 
  		cout<<"\n\n\tend. Remember that the more quicker you give answer the more";
  		cout<<"\n\n\tscore you will secure. Your score will be calculated and displayed";
  		cout<<"\n\n\tat the end and displayed.Every time your score will be recorded.";
		cout<<"\n\n\t So BEST OF LUCK.";
		//Sleep(10000);
		//	cout<<"\n\n\n\n\t*Press 'B' + 'Enter' key  to return mainhome\n\t";
	//	char anykey;
	//	cin>>anykey;	
		getch();			
  	}
 	void displayscore()
  	{
  		
  		fstream file("score.txt");
  		GotoLine(file,1);
  		char str[255];
  		int i=1;
  		cout<<"-----------------------------------------------------------"<<endl;
  		cout<<"Player \t\t\t|Score";
  		cout<<endl<<"\t\t\t|";
  		cout<<"\n------------------------|----------------------------------"<<endl;
  		while(!(file.getline(str, 255)).eof()) {
    	if(i%2==1)
    	{
    		cout<<"\t"<<str;
		}
		else
		{
			cout<<"\t\t|"<<str<<endl;
			cout<<"\t\t\t|"<<endl;
		}
    	i++;
		}
		cout<<"\t\t\t|";
		cout<<"\n------------------------------------------------------------"<<endl;
		//char ch;
		//cout<<"\n\n\n\n\t*Press 'B' + 'Enter' key  to return mainhome\n\t";
		//cin>>ch;
		getch();
	}
	char mainhome()
 	{
 		system("cls");
		char ch;
     	cout<<"\n\t\t WELCOME TO GENERAL KNOWLEDGE TEST PROGRAM\n\n";
     	cout<<"\n\t\t-------------------------------";
     	cout<<"\n\t\t Enter 'S' to start game       ";
     	cout<<"\n\t\t Enter 'V' to view high score  ";
     	cout<<"\n\t\t Enter 'H' for help            ";
     	cout<<"\n\t\t Enter 'Q' to quit             ";
     	cout<<"\n\t\t-------------------------------\n\n\t\t  ";
     	cout<<"enter your choice\n\t\t  ";
     	cin>>ch;
     	return(ch);
	}
	void writescore(float score, char plnm[20])
  	{
  		ofstream myfile;
  		myfile.open ("score.txt",ios::in|ios::app);
  		myfile <<plnm<<"\n"<<score<<"\n";
  		myfile.close();
  		system("cls");
  		cout<<"Your Score is:"<<score<<endl;
  		//char str;
  		//cout<<"Press B + Enter to go main menu"<<endl;
  		//cin>>str;
  		getch();
   }
   int questions(int ques,int k)
   {
   		cout<<"Q"<<k<<":\n"<<endl;
   		fstream file("example.txt");
  		GotoLine(file,(ques-1)*6+1);
  		char str[255];
  		int i=1;
    	while(i<6) {
    	file.getline(str, 255);  // delim defaults to '\n'
    	if(file) cout << str << endl;
		i++;
		}
		char num[255];
		file.getline(num,255);
		char ans;
		cout<<"Enter your answer:"<<endl;
		cin>>ans;
		ans=toupper(ans);
		cout<<"\nCorrect Answer is: "<<num[0]<<endl;
		if(ans==num[0])
			{
				return 1;
			}
		else 
			{
				return 0;
			}
   }
};
int main()
{
  	Functions s;	
	vector<int> myvector; 
	myvector.push_back(0);
  	while(1)
  	{
  		char opt=s.mainhome();
  		float score;
		char playername[20];
    	int i=1;
    	int count=0;
    	int ques;
    	system("cls");
		switch(toupper(opt))
		{
			case 'H': 	s.help();
						break;
			case 'V':	s.displayscore();
						break;
			case 'Q':	cout<<"Thank you for playing this game!"<<endl;
						cout<<"Visit again!"<<endl<<endl<<endl;
				 		exit(0);
						break;
			case 'S':	cout<<"\n\n\n\t\t\tEnter your name...";
				 		cout<<"\n\t\t\t(only one word)\n\n\t\t\t";
				 		cin>>playername;
				 		srand(time(0));
				 		i=1;
				 		while(i<=10)
				 		{	
				 			ques=rand()%30+1;
				 			int flg=0;
				 			for(int j=0;j<myvector.size();j++)
				 			{
				 				if(ques==myvector[j])
				 				{
				 					flg=1;
									 break;	
								}
							}
							if(flg==1)
							continue;
							myvector.push_back(ques);
							system("cls");	
							if(s.questions(ques,i)==1)
							{
								count++;
							}
							i++;
							Sleep(1000);
						}
						s.writescore(count,playername);
						break;

		}
	}
}
