#include "Main.h"
#include "MixClass.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::IO;
using namespace Kursinis;



void Kursinis::ChangeValues(TrackBar^ track, Label^ l1, Label^ l2)//kei�ia teksto reik�mes pagal esan�ius slankinklius
{
	int pvalue = track->Value;
	int vvalue = 100 - pvalue;
	l1->Text = Convert::ToString(pvalue);
	l2->Text = Convert::ToString(vvalue);
}

void Kursinis::MainFunc(double * num)//main faile perkeltos funkcijos per pointer�
{

	BeginMix *mixstart = new BeginMix(); // sukuriamas naujas objektas
	mixstart->Add(num); //objektui priskyriamos reik�m�s
	EndMix mixend = mixstart->Calc();//i�gaunamas galutiniai elementai
	mixend.Show(); // parodo gautus skai�ius
	mixend.Save(mixstart->Dissolve());//per Dissolve i�gaunami duomenys i� pirmos paveld�jimo klas�s ir pasi�loma i�sisaugoti fail�.
}

[STAThreadAttribute]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Kursinis::Main form;
	Application::Run(%form);



}


