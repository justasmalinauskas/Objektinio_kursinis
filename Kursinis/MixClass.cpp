#include "MixClass.h"

namespace Kursinis
{
	using namespace System;
	using namespace System::Data;
	using namespace System::Windows::Forms;
	using namespace System::IO;

	bool BeginMix::Add(double *num)//priskyria skaièius ið programos prie pirmojo miðinio klasës
	{
		Ns = num[0];
		Ps = num[1];
		Vs = num[2];
		Nd = num[3];
		Pd = num[4];
		Vd = num[5];
		Ld = num[6];
		return true;
	}

	void BeginMix::Show()//siunèia á ekranà praneðimà apie pirmàjá miðiná
	{
		String^ ret = "";
		ret += "Pagrindinio chemikalo kiekis(mg/ml): ";
		ret += Ns;
		ret += " \n";
		ret += "Pirmojo skiedþiamojo chemikalo santykis pradinëje medþiagoje (%): ";
		ret += GetPrecent(Ps);
		ret += " \n";
		ret += "Antrojo skiedþiamojo chemikalo santykis pradinëje medþiagoje (%): ";
		ret += GetPrecent(Vs);
		ret += " \n";
		ret + "Norimas pasigaminti galutinës medþiagos kiekis(ml): ";
		ret += Ld;
		ret += " \n";
		ret += "Norimas pagrindinio chemikalo kiekis(mg/ml): ";
		ret += Nd;
		ret += " \n";
		ret += "Pirmojo skiedþiamojo chemikalo santykis galutinëje medþiagoje (%): ";
		ret += GetPrecent(Pd);
		ret += " \n";
		ret += "Antrojo skiedþiamojo chemikalo santykis galutinëje medþiagoje (%): ";
		ret += GetPrecent(Vd);
		MessageBox::Show(ret, "Begin Mix", MessageBoxButtons::OK);
	}


	EndMix BeginMix::Calc()//skaièiuoja koks santykis chemikalø reikalingas ir ákelia juos á atskirà klasæ
	{
		if (Ns == 0)
			Nu = 0;
		else
			Nu = Nd*Ld / Ns;//randa pagr chemeikalo reikalingà kieká
		Pu = (Ld*Pd) - (Nu*Ps);//randa 1 pagalbinio chemikalo reikalingà kieká
		Vu = (Ld*Vd) - (Nu*Vs);//randa 2 pagalbinio chemikalo reikalingà kieká
							   //EndMix *end =
		double* num = new double[3];
		num[0] = Nu;
		num[1] = Pu;
		num[2] = Vu;
		EndMix mix;
		mix.Add(num);
		return mix;
	}

	double * BeginMix::Dissolve()//iðskaldo, á pointerá, jog bûtø galima kartu su EndMix klasës nariais iðsaugoti á failà
	{
		double* ret = new double[7];
		ret[0] = Ns;
		ret[1] = Ps;
		ret[2] = Vs;
		ret[3] = Nd;
		ret[4] = Pd;
		ret[5] = Vd;
		ret[6] = Ld;
		return ret;
	}

	bool EndMix::Add(double *num)//priskyria per antrajo miðinio klasæ
	{
		Nu = num[0];
		Pu = num[1];
		Vu = num[2];
		return true;
	}

	void EndMix::Show()//siunèia á ekranà praneðimà apie antràjá miðiná
	{
		String^ ret = "";
		ret += "Pagrindinio chemikalo reikia pripilti á naujà miðiná (ml): ";
		ret += Nu;
		ret += " \n";
		ret += "Pirmojo skiedþiamojo chemikalo reikia pripilti á naujà miðiná (ml): ";
		ret += Pu;
		ret += " \n";
		ret += "Antrojo skiedþiamojo chemikalo reikia pripilti á naujà miðiná (ml): ";
		ret += Vu;
		MessageBox::Show(ret, "End Mix", MessageBoxButtons::OK);
	}

	void EndMix::Save(double *num)//iðsaugojimo á failà funkcija
	{
		Ns = num[0];
		Ps = num[1];
		Vs = num[2];
		Nd = num[3];
		Pd = num[4];
		Vd = num[5];
		Ld = num[6];
		if (MessageBox::Show(
			"Ar norite iðsaugoti informacijà á tekstiná failà?",
			"Ar iðsaugoti faile?", MessageBoxButtons::YesNo,
			MessageBoxIcon::Question) == ::System::Windows::Forms::DialogResult::Yes)
		{
			String^ ret = "";
			ret += "Pagrindinio chemikalo kiekis(mg/ml): ";
			ret += Ns;
			ret += " \n";
			ret += "Pirmojo skiedþiamojo chemikalo santykis pradinëje medþiagoje (%): ";
			ret += GetPrecent(Ps);
			ret += " \n";
			ret += "Antrojo skiedþiamojo chemikalo santykis pradinëje medþiagoje (%): ";
			ret += GetPrecent(Vs);
			ret += " \n";
			ret + "Norimas pasigaminti galutinës medþiagos kiekis(ml): ";
			ret += Ld;
			ret += " \n";
			ret += "Norimas pagrindinio chemikalo kiekis(mg/ml): ";
			ret += Nd;
			ret += " \n";
			ret += "Pirmojo skiedþiamojo chemikalo santykis galutinëje medþiagoje (%): ";
			ret += GetPrecent(Pd);
			ret += " \n";
			ret += "Antrojo skiedþiamojo chemikalo santykis galutinëje medþiagoje (%): ";
			ret += GetPrecent(Vd);
			ret += " \n";
			ret += "Pagrindinio chemikalo reikia pripilti á naujà miðiná (ml): ";
			ret += Nu;
			ret += " \n";
			ret += "Pirmojo skiedþiamojo chemikalo reikia pripilti á naujà miðiná (ml): ";
			ret += Pu;
			ret += " \n";
			ret += "Antrojo skiedþiamojo chemikalo reikia pripilti á naujà miðiná (ml): ";
			ret += Vu;

			SaveFileDialog^ sfd = gcnew SaveFileDialog(); //sukuria failo iðsaugojimo kintamajá
			try
			{
				sfd->Filter = "Tekstinis áraðas|*.txt"; // parenkamas failo iðsaugojimo formatas
				sfd->FileName = "MyMix"; // pradinis failo vardas
				sfd->Title = "Iðsaugoti áraðà"; //iðsaugojimo lango pavadinimas
				if (sfd->ShowDialog() == DialogResult::OK)
				{
					String^ path = sfd->FileName; //failo kelio ir pavadinimo nustatymas
					StreamWriter^ writer = gcnew StreamWriter(File::Create(path)); //failo sukurimas nurodytame kelyje ir pavadinimu kaip nurodyta
					try
					{
						writer->Write(ret); //áraðoma informacija ið ateinanèio kintamojo á failà

					}
					finally
					{
						delete writer;
					}
				}
			}
			finally
			{
				delete sfd;
			}
		}
	}
}