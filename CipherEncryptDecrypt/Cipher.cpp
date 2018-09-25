#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

void txt2ciph(char *txt,char *cipher,int length,int key)
{
	for(int i=0;i<length;i++)
	{
		if((txt[i]>=65&&txt[i]<=87)||(txt[i]>=97&&txt[i]<=119))
			cipher[i]=txt[i]+key;
		else
			cipher[i]=txt[i]+key-26;
	}

}

void ciph2txt(char *txt,char *cipher,int length,int key)
{
	for(int i=0;i<length;i++)
	{
		if((txt[i]>=68&&txt[i]<=90)||(txt[i]>=100&&txt[i]<=122))
			cipher[i]=txt[i]-key;
		else
			cipher[i]=txt[i]-key+26;
	}

}



int main()
{

	char txt[30]="",cipher[30]="",ch='1';
	int key=0;
	while(ch!='3')
	{
	cout<<"\n 1.Text to Cipher text\n 2.Cipher text to text\n 3.Exit\n";
	cin>>ch;
		switch (ch)
	{
	case '1':cout<<"enter text";
			cin>>txt;
			cout<<"\n Enter key";
			cin>>key;
			txt2ciph(txt,cipher,strlen(txt),key);
			cout<<"Cipher text \n   "<<cipher;
			break;
	case '2':cout<<"enter cipher text";
			cin>>cipher;
			cout<<"\n Enter key";
			cin>>key;
			ciph2txt(cipher,txt,strlen(cipher),key);
			cout<<"Original text\n	"<<txt;
			break;
	case '3':break;
	default:cout<<"invalid option";
		}
	}
	getch();
}