#include<iostream>
#include<conio.h>
#include<string.h>

#define LENGTH 8


using namespace std;
int main()
{
	char tx[100], rx[100], flag[] = { "01111110" }, ch;
	int count = 0, i,j,k;
	strcpy(tx, flag);
	
	cout << "Enter msg\n\t";
	for (i = 0;((ch = getch()) != '\r');i++)
	{
		cout << ch;
		if (ch == '1')
			count++;
		else
			count = 0;
		tx[i + LENGTH] = ch;
		if (count == 5) {
			tx[++i + LENGTH] = '0';
			count = 0;
		}
	}
		
	tx[i + LENGTH] = '\0';
	strcat(tx, flag);
	cout << "\nBit stuffed stream\n\t"<<tx;

	//destuffing

	cout << "\n Start destuffing... Enter character to continue";
	getch();
	j = 0;
	count = 0;
	for ( k = LENGTH;k < (strlen(tx)-LENGTH);k++)
	{
		rx[j++] = tx[k];
		if (tx[k] == '1')
			count++;
		else
			count = 0;
		
		if (count == 5)
		{
			k++;
			count = 0;
		}

	}
	rx[j] = '\0';
	cout << "\ndestuffed stream\n\t" << rx;

	getch();
	
}