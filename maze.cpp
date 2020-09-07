#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

int x[1000];
int y[1000];
int a[100][100];
int k=1,length,breadth,s1,s2,e1,e2,sl=500;
void print();
void nav();

void gotoXY(int x,int y)
{
	

	
	static HANDLE h=NULL;
	if(!h)
	h=GetStdHandle(STD_OUTPUT_HANDLE);
	
	COORD c={x,y};
	SetConsoleCursorPosition(h,c);
	
}

void load()
{
	int i,k=1000;
	
	
	gotoXY(25,11);
	printf("WELCOME TO THE MAZE GENERATOR");
	
	gotoXY(25,13);
	printf("LOADING THE MAZE....");
	
	
	gotoXY(25,15);
	for(i=0;i<40;i++)
	{
		printf("|");
		Sleep(sl);
		sl-=100;
		
		if(sl<0)
		sl=50;
	}
	
	
	
}

int cright(int i,int j)
{
	
	if(a[i][j+1]!=219&&a[i+1][j]!=219&&a[i-1][j]!=219&&a[i][j]!=219&&i>=0&&j>=0&&i<length&&j<breadth)
	return 1;
	
	else 
	return 0;
	
	
}

int cdown(int i,int j)
{
	
	if(a[i][j+1]!=219&&a[i+1][j]!=219&&a[i][j-1]!=219&&a[i][j]!=219&&i>=0&&j>=0&&i<length&&j<breadth)
	return 1;
	
	else 
	return 0;
	
	
}

int cleft(int i,int j)
{
	
	if(a[i][j-1]!=219&&a[i+1][j]!=219&&a[i-1][j]!=219&&a[i][j]!=219&&i>=0&&j>=0&&i<length&&j<breadth)
	return 1;
	
	else 
	return 0;
	
	
}

int cup(int i,int j)
{
	
	if(a[i][j+1]!=219&&a[i-1][j]!=219&&a[i][j-1]!=219&&a[i][j]!=219&&i>=0&&j>=0&&i<length&&j<breadth)
	return 1;
	
	else 
	return 0;
	
	
}


void print()
{
	int i,j;
	
	system("cls");
//	border();
	gotoXY(0,0);
	printf("\n\n\n    ");
		for(i=0;i<length;i++)
	{
		for(j=0;j<breadth;j++)
		if(a[i][j]==219)
		printf(" ");
		
		else if(a[i][j]=='*')
		printf("*");
		
		else if(a[i][j]=='E')
		printf("%c",176);
	
		else
		printf("%c",219) ;
		
		printf("\n    ");
	}
}


void nav()
{
	int i,j;
	char ch;
	a[s1][s2]='*';
	i=s1;
	j=s2;
	print();
	while((ch=getch())!='q'&&!(i==e1&&j==e2))
	{
		
		if(ch==77&&j<breadth&&(a[i][j+1]==219||a[i][j+1]=='E'))
		
		{
		
			a[i][j]=219;
			j++;
			a[i][j]='*';
			print();
			
		}	
		
		if(ch==75&&j>=0&&(a[i][j-1]==219||a[i][j-1]=='E'))
		{
			
			a[i][j]=219;
			j--;
			a[i][j]='*';
			print();
			
		}
			
		if(ch==72&&i>=0&&(a[i-1][j]==219||a[i-1][j]=='E'))
		{
			
			a[i][j]=219;
			i--;
			a[i][j]='*';
			print();
			
		}	
		
		if(ch==80&&i<length&&(a[i+1][j]==219||a[i+1][j]=='E'))
		{
			a[i][j]=219;
			i++;
			a[i][j]='*';
			print();
			
		}
		
		

	}
	
	
	if(i==e1&&j==e2)
		{
		system("color 0B");
	printf("\n\nYOU WIN!!!!");
	}	
		
	
	
}


int main()
{
	int i=0,j=0,m,n,count,flag;
	
		load();
		system("cls");
	
	printf("enter length\n");
	scanf("%d",&length);
	
	printf("enter breadth\n");
	scanf("%d",&breadth);
	
	printf("enter starting point\n");
	scanf("%d",&s1);
	scanf("%d",&s2);
	printf("enter ending point \n");
	scanf("%d",&e1);
	scanf("%d",&e2);
	
	srand(time(NULL));
	
	while(1)
	{
		leb:
		m=rand()%3-1;
		n=rand()%3-1;
		
		
		if(((abs(m)+abs(n))!=1))
		goto leb;
		
		count=-2;
		flag=0;
		
		abc:
	
		if(n==1)
		{
			count++;
			if(count==3)
			{	flag=1;
				goto xyz;
			}
			if(cright(i,j+1)==1)
			{
				j=j+1;	
				printf("right ");
				a[i][j]=219;
			}
			
			else
			{
				n=-1;
				m=0;
				goto abc;
				
			}
		
		}
		
		else if(n==-1)
		{
			count++;
				if(count==3)
			{	flag=1;
				goto xyz;
			}
			if(cleft(i,j-1)==1)
			{
				j=j-1;	
				printf("left ");
				a[i][j]=219;
			}
			
				else
			{
				n=0;
				m=1;
				goto abc;
				
			}
			
		
		}
		
		else if(m==1)
		{
			count++;
				if(count==3)
			{	flag=1;
				goto xyz;
			}
			if(cdown(i+1,j)==1)
			{
				i=i+1;	
				printf("down ");
				a[i][j]=219;
			}
			else
			{
				n=0;
				m=-1;
				goto abc;
				
			}
			
			
		
		}
		
		else if(m==-1)
		{
			count++;
				if(count==3)
			{	flag=1;
				goto xyz;
			}
			if(cup(i-1,j)==1)
			{
				i=i-1;	
				printf("up ");
				a[i][j]=219;
			}
			
			else
			{
				n=1;
				m=0;
				goto abc;
			}
		}
		
		
		xyz:
			if(flag==1)
			{
				k-=2;
				
				if(k<=1)
				break;
				
				printf("back\n");
				j=x[k];
				i=y[k];
				k++;
				goto leb;
				
			}
		
	//	if(k<0)
	//	break;
		x[k]=j;
		y[k]=i;
		k++;
		
}

	
	a[s1][s2]='S';
	a[e1][e2]='E';
	
	
	

	nav();
	
	
	return 0;
	
}
