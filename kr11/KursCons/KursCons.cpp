#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include <windows.h>
#include <clocale>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;
using namespace System;
using namespace System::IO;

#define ENTER 13
#define ESC 27
#define UP 72
#define DOWN 80
#define HOME 71
#define END 79

char dan[9][61]={
"Самая дорогая оплата?                                       ",
"Самый неопытный мастер?                                     ",
"Количество мастеров отделочных работ                        ",
"Список мастеров монтажа с оплатой меньше 1000 р.            ",
"Алфавитный список мастеров со стоимостью их оплаты          ",
"Обратный алфавитный список мастеров со стоимостью их оплаты ",
"Есть ли у разных мастеров одинаковая специализация?         ",
"Диаграмма. Процентное содержание от общей стоимости работ   ",
"Выход                                                       "
};
char BlankLine[]="                                                              ";
int NC;
struct z {
char name[30];
char usluga[20];
long price;
long kolvo;
char kvl[20];
};
struct sp {
char fio[20];
long price;
struct sp* sled;
struct sp* pred;
} *spisok;

int menu(int);
void maxim(struct z*);
void exp(struct z*);
void listing(struct z*);
void kolvo(struct z*);
void alfalist(struct z*);
void vstavka(struct z*,char*);
void diagram(struct z*);
void sovpadenie(struct z*);
void obrtalfalist(struct z*); 

int main(array<System::String ^> ^args)
{
int i,n;
FILE *in;
struct z *masters;
setlocale(LC_CTYPE,"Russian");
Console::CursorVisible::set(false);
Console::BufferHeight=Console::WindowHeight;
Console::BufferWidth=Console::WindowWidth;

if((in=fopen("spisok.dat","r"))==NULL)
{
printf("\nФайл не открыт!");
getch();
exit(1);
}
fscanf(in,"%d",&NC);
masters=(struct z*)malloc(NC*sizeof(struct z));

for(i=0;i<NC;i++)
	fscanf(in,"%s%s%ld%ld%s",masters[i].name,
	masters[i].usluga,&masters[i].price,
	&masters[i].kolvo,masters[i].kvl);

for(i=0;i<NC;i++)
	printf("\n% -20s %-15s %5d %5d %20s",masters[i].name,
	masters[i].usluga,masters[i].price,
	masters[i].kolvo,masters[i].kvl);
getch();

while(1)
{
Console::BackgroundColor=ConsoleColor::Black;
Console::Clear();
Console::ForegroundColor=ConsoleColor::Black;
Console::BackgroundColor=ConsoleColor::Cyan;
Console::CursorLeft=10;
Console::CursorTop=4;
printf(BlankLine);

for(i=0;i<9;i++)
{
Console::CursorLeft=10;
Console::CursorTop=i+5;
printf(" %s ",dan[i]);
}
Console::CursorLeft=10;
Console::CursorTop=14;
printf(BlankLine);
n=menu(9);

switch(n) {
case 1: maxim(masters); break; 
case 2: exp(masters);break;
case 3: kolvo(masters); break;
case 4: listing(masters); break;
case 5: alfalist(masters); break;
case 6: obrtalfalist(masters); break;
case 7: sovpadenie(masters); break;
case 8: diagram(masters); break;
case 9: exit(0);
}
}
getch();
}

int menu(int n)
{
int y1=0,y2=n-1;
char c=1;
while (c!=ESC)
{
switch(c)
{
case DOWN: y2=y1; y1++; break;
case UP:  y2=y1; y1--; break;
case ENTER: return y1 + 1; break;
case HOME :y2 = y1; y1 = 0; break;
case END :y2 = y1; y1 = n - 1; break;

}
if(y1>n-1){y2=n-1;y1=0;}
if(y1<0){y1=n-1;y2=0;}

Console::ForegroundColor=ConsoleColor::White;
Console::BackgroundColor=ConsoleColor::Magenta;
Console::CursorLeft=11;
Console::CursorTop=y1+5;
	printf("%s",dan[y1]);

Console::ForegroundColor=ConsoleColor::Black;
Console::BackgroundColor=ConsoleColor::Cyan;
Console::CursorLeft=11;
Console::CursorTop=y2+5;
printf("%s",dan[y2]);

c=getch();
}
exit(0);
}



 void maxim(struct z* masters)
{
int i;
struct z best;
strcpy(best.name,masters[0].name);
best.price=masters[0].price;
for(i=1;i<NC;i++)
	if(masters[i].price>best.price)
	{
	strcpy(best.name,masters[i].name);
	best.price=masters[i].price;
	}
		Console::ForegroundColor=ConsoleColor::Cyan;
		Console::BackgroundColor=ConsoleColor::Black;
		Console::CursorLeft=25;
		Console::CursorTop=17;
		
printf("Самая дорогая оплата %1d руб.",best.price);
Console::CursorLeft=25;
Console::CursorTop=18;
printf("Мастер: %s",best.name);
getch();
}

void exp(struct z* masters)
{
int i=0;
struct z min;
strcpy(min.name,masters[0].name);
min.kolvo=masters[0].kolvo;
for(i=1;i<NC;i++)
	if(masters[i].kolvo<min.kolvo)
	{
	strcpy(min.name,masters[i].name);
	min.kolvo=masters[i].kolvo;
	}
Console::ForegroundColor=ConsoleColor::Cyan;
Console::BackgroundColor=ConsoleColor::Black;
Console::CursorLeft=25;
Console::CursorTop=17;
	printf("Самый неопытный мастер: %s",min.name);
Console::CursorLeft=25;
Console::CursorTop=18;
	printf("Опыт работы: %1d",min.kolvo);
getch();
}

void listing(struct z* master)
{
int i;
struct z* nt;
Console::ForegroundColor=ConsoleColor::Black;
Console::BackgroundColor=ConsoleColor::Cyan;
Console::Clear();
printf("\n Список мастеров монтажа с оплатой меньше 1000 р");
printf("\n ===============================================\n");
for(i=0,nt=master;i<NC;nt++,i++)
	if(nt->price<1000 && strcmp(nt->usluga,"монтаж")==0)
		printf("\n %-20s %-4ldp.   %-s",nt->name, nt->price, nt->usluga);
getch();
}

void vstavka(struct z* master, char* fio)
{
	int i;
	struct sp* nov, * nt, * z = 0;

	for (nt = spisok; nt != 0 && strcmp(nt->fio, fio) < 0; z = nt, nt = nt->sled);

	if (nt && strcmp(nt->fio, fio) == 0) return;

	nov = (struct sp*) malloc(sizeof(struct sp));
	strcpy(nov->fio, fio);
	nov->price = 0;
	for (i = 0; i < NC; i++)
		if (strcmp(master[i].name, fio) == 0)
			nov->price += master[i].price;
	nov->sled = nt;
	nov->pred = z;

	if (nt != 0) nt->pred = nov;
	if (z == 0) spisok = nov;
	else z->sled = nov;

	return;
}

void kolvo(struct z* master)
{
int i,k=0;
for(i=0;i<NC;i++)
	if(strcmp(master[i].usluga,"отделка")==0) k++;
Console::ForegroundColor=ConsoleColor::Cyan;
Console::BackgroundColor=ConsoleColor::Black;
Console::CursorLeft=23;
Console::CursorTop=17;
	printf("Количество мастеров отделочных работ: %d",k);
getch();
}

void alfalist(struct z* master)
{
int i,k;
char fam[80];
struct sp* nt;
Console::ForegroundColor=ConsoleColor::Black;
Console::BackgroundColor=ConsoleColor::Cyan;
if(spisok==0)
	for(i=0;i<NC;i++)
		vstavka(master,master[i].name);
Console::Clear();
printf("\n Алфавитный список мастеров со стоимостью их оплаты:");
printf("\n ===================================================\n");
for(nt=spisok; nt!=0; nt=nt->sled)
	printf("\n %-20s %1d", nt->fio,nt->price);

Console::CursorTop = 3;
Console::CursorLeft = 40;

printf("Введите имя мастера: ");
SetConsoleCP(1251);
gets_s(fam);
SetConsoleCP(866);
for (nt = spisok; nt != 0; nt = nt->sled)
if (strcmp(fam, nt->fio) == 0)
break;
if (nt->pred != 0 && nt->sled != 0) // мастер посередине
{
	nt->pred->sled = nt->sled;
	nt->sled->pred = nt->pred;
}
if (nt == spisok) //мастер первый
{
	spisok = nt->sled;
	nt->sled->pred = 0;
}
if (nt->sled == 0) //мастер последний
nt->pred->sled = 0;

free(nt);
for (nt = spisok; nt != 0; nt = nt->sled)
{
	Console::CursorLeft = 40;
	printf("%-20s %1d\n", nt->fio, nt->price);
}




/*
printf("Введите фамилию:\n");
Console::CursorLeft = 40;
SetConsoleCP(1251);
gets_s(fam);
SetConsoleCP(866);
Console::CursorLeft = 40;
for (nt = spisok; nt->sled != 0; nt = nt->sled)
if (strcmp(fam, nt->fio) == 0)
break;
for (k = 1, nt = nt->sled; nt != 0; k++, nt = nt->sled);
{
	Console::CursorLeft = 40;
	printf("Позиция мастера с конца: %d", k);
} */
getch();

} 

void obrtalfalist(struct z* master) 
{ 
int i; 
struct sp *nt, *z; 
Console::ForegroundColor=ConsoleColor::Black; 
Console::BackgroundColor=ConsoleColor::Cyan; 
Console::Clear(); 
if(!spisok) 
	for(i=0;i<NC;i++) 
		vstavka(master,master[i].name); 
Console::Clear(); 
	printf("\n Обратный алфавитный список мастеров со стоимостью их оплаты:");	
	printf("\n ============================================================\n");
for(nt=spisok,z=0; nt!=0; z=nt, nt=nt->sled); 
for(nt=z; nt!=0; nt=nt->pred) 
	printf("\n %-20s %ld",nt->fio,nt->price); 
getch(); 
}

void sovpadenie(struct z* masters)
{
int i,j;
bool k=false;
for(i=0;i<NC;i++)
{
	
	for(j=i+1;j<NC;j++)
	{
		if(strcmp(masters[i].usluga,masters[j].usluga)==0)
		{
			k=true;
			break;
		}	
	}

	if(k==true)
		break;
}
if(k)
{
Console::ForegroundColor=ConsoleColor::Cyan;
Console::BackgroundColor=ConsoleColor::Black;
Console::CursorLeft=10;
Console::CursorTop=16;
	printf("Cовпадение мастеров по услуге %s ",masters[i].usluga);
Console::CursorLeft=10;
Console::CursorTop=17;
	printf("от мастеров %s и %s", masters[i].name,masters[j].name);
getch();
}
else
{
Console::ForegroundColor=ConsoleColor::Cyan;
Console::BackgroundColor=ConsoleColor::Black;
Console::CursorLeft=30;
Console::CursorTop=18;
	printf("Совпадений нет");
getch();
}
}

void diagram(struct z *master)
{
struct sp *nt;
int len, i, NColor;
long sum=0;
char str1[30];
char str2[30];
ConsoleColor Color;
Console::ForegroundColor=ConsoleColor::Black;
Console::BackgroundColor=ConsoleColor::White;
Console::Clear();
for(i=0;i<NC;i++) sum=sum+master[i].price;
if(!spisok)
	for(i=0;i<NC;i++)
		vstavka(master,master[i].name);
Color=ConsoleColor::Black; NColor=0;

for(nt=spisok,i=0; nt!=0; nt=nt->sled, i++)
{
sprintf(str1,"%s", nt->fio);
sprintf(str2,"%3.1f%%",(nt->price*100./sum));
Console::ForegroundColor=ConsoleColor::Black;
Console::BackgroundColor=ConsoleColor::White;
Console::CursorLeft=5;
Console::CursorTop=i+1;
printf(str1);
Console::CursorLeft=20;
printf("%2s",str2);
Console::BackgroundColor=++Color; NColor++;
Console::CursorLeft=30;
for(len=0; len<nt->price*100/sum; len++)
	printf(" ");
if(NColor==14)
	{ 
	Color=ConsoleColor::Black; NColor=0;}
	}
getch(); 
return;
}
