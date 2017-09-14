#include "Main.h"
#include "MixClass.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::IO;
using namespace Kursinis;



void Kursinis::ChangeValues(TrackBar^ track, Label^ l1, Label^ l2)//keièia teksto reikðmes pagal esanèius slankinklius
{
	int pvalue = track->Value;
	int vvalue = 100 - pvalue;
	l1->Text = Convert::ToString(pvalue);
	l2->Text = Convert::ToString(vvalue);
}

void Kursinis::MainFunc(double * num)//main faile perkeltos funkcijos per pointerá
{

	BeginMix *mixstart = new BeginMix(); // sukuriamas naujas objektas
	mixstart->Add(num); //objektui priskyriamos reikðmës
	EndMix mixend = mixstart->Calc();//iðgaunamas galutiniai elementai
	mixend.Show(); // parodo gautus skaièius
	mixend.Save(mixstart->Dissolve());//per Dissolve iðgaunami duomenys ið pirmos paveldëjimo klasës ir pasiûloma iðsisaugoti failà.
}

[STAThreadAttribute]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Kursinis::Main form;
	Application::Run(%form);



}


