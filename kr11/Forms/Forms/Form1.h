#pragma once

using namespace	System;
using namespace	System::ComponentModel;
using namespace	System::Collections;
using namespace	System::Windows::Forms;
using namespace	System::Data;
using namespace System::Drawing;
using namespace System::Runtime::InteropServices;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <clocale>
#include <iostream>
#include <fstream>

int NC;
struct z {
char name[30];
char usluga[20];
long price;
long kolvo;
char kvl[20];
}*masters;
struct sp {
char name[20];
long price;
struct sp* sled;
} *spisok;

void vstavka(struct z* masters,char* name)
{
int i;
struct sp *nov,*nt,*z=0;
for(nt=spisok; nt!=0 && strcmp(nt->name,name)<0; z=nt, nt=nt->sled);
if(nt && strcmp(nt->name,name)==0) return;

nov=(struct sp *) malloc(sizeof(struct sp));
strcpy(nov->name,name);
nov->sled=nt;
nov->price=0;
for(i=0;i<NC;i++)
	if(strcmp(masters[i].name,name)==0)
		nov->price+=masters[i].price;

if(!z) spisok=nov;
else z->sled=nov;
return;
}



namespace Forms1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  ôàéëToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  îòêğûòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  çàâåğøèòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  âîïğîñûToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  âûõîäToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^  àëôàâèòíûéÑïèñîêToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  äèàãğàììàToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ñàìàÿÄîğîãàÿÓñëóãàToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ñàìûéÎïûòíûéÌàñòåğToolStripMenuItem;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^ íîâûéÂîïğîñToolStripMenuItem;



	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
	
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ôàéëToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->îòêğûòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->çàâåğøèòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âîïğîñûToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->àëôàâèòíûéÑïèñîêToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->äèàãğàììàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ñàìàÿÄîğîãàÿÓñëóãàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ñàìûéÎïûòíûéÌàñòåğToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->íîâûéÂîïğîñToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->ôàéëToolStripMenuItem,
					this->âîïğîñûToolStripMenuItem, this->âûõîäToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1326, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ôàéëToolStripMenuItem
			// 
			this->ôàéëToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->îòêğûòüToolStripMenuItem,
					this->çàâåğøèòüToolStripMenuItem
			});
			this->ôàéëToolStripMenuItem->Name = L"ôàéëToolStripMenuItem";
			this->ôàéëToolStripMenuItem->Size = System::Drawing::Size(59, 24);
			this->ôàéëToolStripMenuItem->Text = L"Ôàéë";
			// 
			// îòêğûòüToolStripMenuItem
			// 
			this->îòêğûòüToolStripMenuItem->Name = L"îòêğûòüToolStripMenuItem";
			this->îòêğûòüToolStripMenuItem->Size = System::Drawing::Size(168, 26);
			this->îòêğûòüToolStripMenuItem->Text = L"Îòêğûòü";
			this->îòêğûòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::îòêğûòüToolStripMenuItem_Click);
			// 
			// çàâåğøèòüToolStripMenuItem
			// 
			this->çàâåğøèòüToolStripMenuItem->Name = L"çàâåğøèòüToolStripMenuItem";
			this->çàâåğøèòüToolStripMenuItem->Size = System::Drawing::Size(168, 26);
			this->çàâåğøèòüToolStripMenuItem->Text = L"Çàâåğøèòü";
			this->çàâåğøèòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::çàâåğøèòüToolStripMenuItem_Click);
			// 
			// âîïğîñûToolStripMenuItem
			// 
			this->âîïğîñûToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->àëôàâèòíûéÑïèñîêToolStripMenuItem,
					this->äèàãğàììàToolStripMenuItem, this->ñàìàÿÄîğîãàÿÓñëóãàToolStripMenuItem, this->ñàìûéÎïûòíûéÌàñòåğToolStripMenuItem, this->íîâûéÂîïğîñToolStripMenuItem
			});
			this->âîïğîñûToolStripMenuItem->Enabled = false;
			this->âîïğîñûToolStripMenuItem->Name = L"âîïğîñûToolStripMenuItem";
			this->âîïğîñûToolStripMenuItem->Size = System::Drawing::Size(86, 24);
			this->âîïğîñûToolStripMenuItem->Text = L"Âîïğîñû";
			// 
			// àëôàâèòíûéÑïèñîêToolStripMenuItem
			// 
			this->àëôàâèòíûéÑïèñîêToolStripMenuItem->Name = L"àëôàâèòíûéÑïèñîêToolStripMenuItem";
			this->àëôàâèòíûéÑïèñîêToolStripMenuItem->Size = System::Drawing::Size(278, 28);
			this->àëôàâèòíûéÑïèñîêToolStripMenuItem->Text = L"Àëôàâèòíûé ñïèñîê";
			this->àëôàâèòíûéÑïèñîêToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::àëôàâèòíûéÑïèñîêToolStripMenuItem_Click);
			// 
			// äèàãğàììàToolStripMenuItem
			// 
			this->äèàãğàììàToolStripMenuItem->Name = L"äèàãğàììàToolStripMenuItem";
			this->äèàãğàììàToolStripMenuItem->Size = System::Drawing::Size(278, 28);
			this->äèàãğàììàToolStripMenuItem->Text = L"Äèàãğàììà";
			this->äèàãğàììàToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::äèàãğàììàToolStripMenuItem_Click);
			// 
			// ñàìàÿÄîğîãàÿÓñëóãàToolStripMenuItem
			// 
			this->ñàìàÿÄîğîãàÿÓñëóãàToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.01739F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->ñàìàÿÄîğîãàÿÓñëóãàToolStripMenuItem->Name = L"ñàìàÿÄîğîãàÿÓñëóãàToolStripMenuItem";
			this->ñàìàÿÄîğîãàÿÓñëóãàToolStripMenuItem->Size = System::Drawing::Size(278, 28);
			this->ñàìàÿÄîğîãàÿÓñëóãàToolStripMenuItem->Text = L"Ñàìàÿ äîğîãàÿ îïëàòà";
			this->ñàìàÿÄîğîãàÿÓñëóãàToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::ñàìàÿÄîğîãàÿÓñëóãàToolStripMenuItem_Click);
			// 
			// ñàìûéÎïûòíûéÌàñòåğToolStripMenuItem
			// 
			this->ñàìûéÎïûòíûéÌàñòåğToolStripMenuItem->Name = L"ñàìûéÎïûòíûéÌàñòåğToolStripMenuItem";
			this->ñàìûéÎïûòíûéÌàñòåğToolStripMenuItem->Size = System::Drawing::Size(278, 28);
			this->ñàìûéÎïûòíûéÌàñòåğToolStripMenuItem->Text = L"Ñàìûé íåîïûòíûé ìàñòåğ";
			this->ñàìûéÎïûòíûéÌàñòåğToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::ñàìûéÎïûòíûéÌàñòåğToolStripMenuItem_Click);
			// 
			// âûõîäToolStripMenuItem
			// 
			this->âûõîäToolStripMenuItem->Name = L"âûõîäToolStripMenuItem";
			this->âûõîäToolStripMenuItem->Size = System::Drawing::Size(67, 24);
			this->âûõîäToolStripMenuItem->Text = L"Âûõîä";
			this->âûõîäToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::âûõîäToolStripMenuItem_Click);
			// 
			// tabPage3
			// 
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(1318, 530);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Äèàãğàììà";
			this->tabPage3->UseVisualStyleBackColor = true;
			this->tabPage3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::tabPage3_Paint);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->richTextBox1);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1318, 530);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Ñïèñîê";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->richTextBox1->Location = System::Drawing::Point(0, 4);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(1318, 526);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->listBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1318, 530);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Èñõîäíûå äàííûå";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// listBox1
			// 
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 25;
			this->listBox1->Location = System::Drawing::Point(-4, 4);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(1322, 504);
			this->listBox1->TabIndex = 0;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(0, 44);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1326, 559);
			this->tabControl1->TabIndex = 1;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"Data Files(*.dat) | *.dat";
			// 
			// íîâûéÂîïğîñToolStripMenuItem
			// 
			this->íîâûéÂîïğîñToolStripMenuItem->Name = L"íîâûéÂîïğîñToolStripMenuItem";
			this->íîâûéÂîïğîñToolStripMenuItem->Size = System::Drawing::Size(278, 28);
			this->íîâûéÂîïğîñToolStripMenuItem->Text = L"Íîâûé âîïğîñ";
			this->íîâûéÂîïğîñToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::íîâûéÂîïğîñToolStripMenuItem_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1326, 604);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Êóğñîâàÿ";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabControl1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void îòêğûòüToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 FILE *in;
//
int i;
char ctemp[80];
String ^s;
if (openFileDialog1->ShowDialog()==System::Windows::Forms::DialogResult::OK)
	{
	s=openFileDialog1->FileName;
	char *str_tmp=(char*)(void*)Marshal::StringToHGlobalAnsi(s);
	if ((in=fopen("spisok.dat","r"))==NULL)
	         {    MessageBox::Show("Ôàéë íå îòêğûò!","Îøèáêà!",
			MessageBoxButtons::OK,MessageBoxIcon::Error);
		return;
	         }
	}
else return;
//

âîïğîñûToolStripMenuItem->Enabled=true;
listBox1->Items->Clear();
fscanf(in,"%d",&NC);
masters = new z[NC];
for(i=0;i<NC;i++)
    {
    fscanf(in,"%s%s%ld%ld%s",masters[i].name, masters[i].usluga, 
		&masters[i].price, &masters[i].kolvo, masters[i].kvl);
    sprintf(ctemp,"%-20s %-20s %7ld %7ld %s",
                    			masters[i].name,masters[i].usluga, 
								masters[i].price,masters[i].kolvo,masters[i].kvl);
     s=gcnew String(ctemp);
     listBox1->Items->Add(s);
     }
fclose(in);


			 }
private: System::Void çàâåğøèòüToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void âûõîäToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }




private: System::Void ñàìàÿÄîğîãàÿÓñëóãàToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 			  int i=0;
struct z best;
char ss[80];
String ^s;

strcpy(best.usluga,masters[0].usluga);
best.price=masters[0].price;
for(i=1;i<NC;i++)
	if (masters[i].price>best.price)
		{
		strcpy(best.usluga,masters[i].usluga);
		best.price=masters[i].price;
		}
sprintf(ss,"%s\n %ld ğóáëåé",best.usluga,best.price);
s=gcnew String(ss); 
MessageBox::Show(s,"Ñàìàÿ äîğîãàÿ îïëàòà");
		 }
private: System::Void ñàìûéÎïûòíûéÌàñòåğToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 int i=0;

struct z min;
char ss[80];
String ^s;

strcpy(min.name,masters[0].name);
min.kolvo=masters[0].kolvo;
for(i=1;i<NC;i++)
	if (masters[i].kolvo<min.kolvo)
		{
		strcpy(min.name,masters[i].name);
		min.kolvo=masters[i].kolvo;
		}
sprintf(ss,"Îïûò ğàáîòû: %s\n %ld",min.name,min.kolvo);
s=gcnew String(ss); 
MessageBox::Show(s,"Ñàìûé íåîïûòíûé ìàñòåğ");


		 }
private: System::Void àëôàâèòíûéÑïèñîêToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
int i;
struct sp* nt;
char ss[80];
String ^s;
tabControl1->SelectTab(1); 
if(!spisok)
	  for(i=0;i<NC;i++)
		vstavka(masters,masters[i].name);
richTextBox1->ReadOnly=1;
richTextBox1->Clear();
richTextBox1->Text ="\nÀËÔÀÂÈÒÍÛÉ ÑÏÈÑÎÊ\n====================\n";
for(nt=spisok; nt!=0; nt=nt->sled)
	{
	sprintf(ss,"%-20s %10ld",nt->name,nt->price);
	s=gcnew String(ss,0,31);
	richTextBox1->Text = richTextBox1->Text+"\n"+s;
	} 

		 }
		   

private: System::Void tabPage3_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
Pen ^myPen= gcnew Pen(System::Drawing::Color::Black,3);	 
 SolidBrush ^myBrush= gcnew SolidBrush(Color::FromArgb(196,0,0,0));
 System::Drawing::Font^ myFont=gcnew System::Drawing::Font("Arial",8);

 int i,K;
 int iRed,iGreen,iBlue;
 int aStart,aEnd;
 long Sum;
 float xPos,yPos;
 struct sp *nt;

 Graphics ^g=tabPage3->CreateGraphics();
 g->Clear(System::Drawing::Color::White);
 if(!spisok)
	for(i=0;i<NC;i++)
		vstavka(masters,masters[i].name);
 K=0; Sum=0;
 for(nt=spisok; nt!=0; nt=nt->sled) 
	{
 	K++;
	Sum+=nt->price;
	}
 g->DrawEllipse(myPen,25,25,185,185);
 aEnd=0;

 for(nt=spisok,i=0; nt!=0; nt=nt->sled,i++)
	{		
	iRed=(((i+1)&4)>0)*255/(i/8+1);
	iGreen=(((i+1)&2)>0)*255/(i/8+1);
	iBlue=(((i+1)&1)>0)*255/(i/8+1);
	aStart=aEnd;
	aEnd+=nt->price*360/Sum;
	if(i==K-1)aEnd=360;
myBrush->Color::set(Color::FromArgb(196,iRed,iGreen,iBlue));
     g->FillPie(myBrush,25,25,185,185,aStart,aEnd-aStart);
     g->FillRectangle(myBrush,300,50+(i-1)*20,20,20);

     myBrush->Color::set(Color::FromArgb(196,0,0,0));
     xPos=30+(185-25)/2+(185-25)/1.5*Math::Cos(Math::PI*(aStart+aEnd)/360);
     yPos=30+(185-25)/2+(185-25)/1.5*Math::Sin(Math::PI*(aStart+aEnd)/360);

     g->DrawString(gcnew String(nt->name),myFont,myBrush,320,55+(i-1)*20);
     g->DrawString(Convert::ToString(nt->price*100/Sum)+"%",
					myFont,myBrush,xPos,yPos);
     }
		 }
private: System::Void äèàãğàììàToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 tabControl1->SelectTab(2);
		 }
private: System::Void íîâûéÂîïğîñToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}

