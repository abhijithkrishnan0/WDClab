#include<iostream>
#include<conio.h>

#define DLE 16
#define STX 2

#define ETX 3

using namespace std;

int main()
{
	char ch, msg[50] = { STX,DLE }, rev[50];
	int i = 2;
	cout << "enter message\n";
	while ((ch = getch()) != '\r')
	{
		if (ch == DLE)
		{
			cout << "DLE";
			msg[i++] = ch;
		}
		else if (ch == STX)
			cout << "STX";
		else if (ch == ETX)
			cout << "ETX";
		else 
			cout << ch;
		
		msg[i++] = ch;

	}
	msg[i++] = ETX;
	msg[i++] = DLE;
	
	cout << "\nstuffed stream is\n";
	for (int j = 0;j < i;j++)
	{
		if (msg[j] == DLE)
			cout << "DLE";
		else if (msg[j] == STX)
			cout << "STX";
		else if (msg[j] == ETX)
			cout << "ETX";
		else
			cout << msg[j];

	}

	// destuffing
	cout << "\n Destuffed bits\n";
	for (int j = 2;j < i-2	;j++)
	{
		if (msg[j] == DLE)
		{
			cout<< "DLE";
			j++;

		}
		else if (msg[j] == STX)
			cout << "STX";
		else if (msg[j] == ETX)
			cout << "ETX";
		else
			cout << msg[j];

	}
	getch();
}