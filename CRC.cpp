#include<iostream>
#include<conio.h>

#define N strlen(gen)
#define STX 2

#define ETX 3

using namespace std;
char t[128] = "",cs[128] = "", gen[] = "11011";
int a, e, c;
void xor()
{
	for (c = 1;c < N;c++)
		cs[c] = ((cs[c] == gen[c]) ? '0' : '1');
}
void crc()
{
	for (e = 0;e < N;e++)
		cs[e] = t[e];
	do 
	{
		if (cs[0] == '1')
			xor ();
		for (c = 0;c < N - 1;c++)
			cs[c] = cs[c + 1];
		cs[c] = t[e++];
	} while (e <= a + N - 1);
}

int main()
{
	cout << "enter poly";
	gets_s(t);
	cout << "\n Generating pol is\n" << gen;
	a = strlen(t);
	for (e = a;e < a + N - 1;e++)
		t[e] = '0';
	t[e] = '\0';
	crc();
	
	cout << "Checksum is" << cs<<endl<<strlen(cs);
	for (e = a;e < a + N - 1;e++)
		t[e] = cs[e - a];
		
	
	t[e] = '\0';
	cout << "\nFinal code word\n" << t;
	cout << endl;
	crc();
	cout << "\n CS" << cs;


	getch();

}