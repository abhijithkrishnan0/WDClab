#include<iostream>
#include<conio.h>
#include<string.h>

#define SIZE 80


using namespace std;
int text2caesar(char *text, char *cipher, int key, int length)
{
	for (int i = 0;i < length;i++)
	{
		cipher[i] = text[i];
		if (!isalpha(cipher[i]))
			return 0;
		cipher[i] = toupper(cipher[i]);
		cipher[i] -= 'A';
		cipher[i] += key;
		cipher[i] %= 26;
		cipher[i] += 'A';
	}


	return 1;
}
int caesar2text(char *text, char *cipher, int key, int length)
{
	for (int i = 0;i < length;i++)
	{
		cout << endl;
		text[i] = cipher[i];
		if (!isalpha(text[i]))
			return 0;
		text[i] = toupper(text[i]);
		text[i] -= 'A';
		text[i] += 26-key;
		text[i] %= 26;
		text[i] += 'A';
	}


	return 1;
}

int main()
{
	char pt[SIZE]="", ct[SIZE]="", ch;
	int key;
	while (1) {
		
		cout << "\n1.Text to Cipher\n2.Cipher to Text\n";
		cin >> ch;
		switch (ch)
		{
		case '1':cout << "\nEnter Plain text(ONLY ALPHABETS)\n";
			cin >> pt;
			cout << "\n Enter key\n(Below 25)";
			cin >> key;
			if ((key < 1) || (key > 25))
			{
				cout << "invalidkey ";
				break;
			}
			if (!text2caesar(pt, ct, key, strlen(pt)))
			{
				cout << "Invalid input";
				break;
			}
			cout << "\nCipher Text\n" << ct;
			break;

		case '2':cout << "\nEnter CIPHER(ONLY ALPHABETS)\n";
			cin >> ct;
			cout << "\n Enter key\n(Below 25)";
			cin >> key;
			if ((key < 1) || (key > 25))
			{
				cout << "invalidkey ";
				break;
			}
			if (!caesar2text(pt, ct, key, strlen(ct)))
			{
				cout << "Invalid input";
				break;
			}
			cout << "\nPlain Text\n" << pt;
			break;
		default:cout << "invalid input";
			break;


		}
		getch();
	}
}