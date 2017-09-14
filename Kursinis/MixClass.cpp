#include "MixClass.h"

namespace Kursinis
{
	using namespace System;
	using namespace System::Data;
	using namespace System::Windows::Forms;
	using namespace System::IO;

	bool BeginMix::Add(double *num)//priskyria skai�ius i� programos prie pirmojo mi�inio klas�s
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

	void BeginMix::Show()//siun�ia � ekran� prane�im� apie pirm�j� mi�in�
	{
		String^ ret = "";
		ret += "Pagrindinio chemikalo kiekis(mg/ml): ";
		ret += Ns;
		ret += " \n";
		ret += "Pirmojo skied�iamojo chemikalo santykis pradin�je med�iagoje (%): ";
		ret += GetPrecent(Ps);
		ret += " \n";
		ret += "Antrojo skied�iamojo chemikalo santykis pradin�je med�iagoje (%): ";
		ret += GetPrecent(Vs);
		ret += " \n";
		ret + "Norimas pasigaminti galutin�s med�iagos kiekis(ml): ";
		ret += Ld;
		ret += " \n";
		ret += "Norimas pagrindinio chemikalo kiekis(mg/ml): ";
		ret += Nd;
		ret += " \n";
		ret += "Pirmojo skied�iamojo chemikalo santykis galutin�je med�iagoje (%): ";
		ret += GetPrecent(Pd);
		ret += " \n";
		ret += "Antrojo skied�iamojo chemikalo santykis galutin�je med�iagoje (%): ";
		ret += GetPrecent(Vd);
		MessageBox::Show(ret, "Begin Mix", MessageBoxButtons::OK);
	}


	EndMix BeginMix::Calc()//skai�iuoja koks santykis chemikal� reikalingas ir �kelia juos � atskir� klas�
	{
		if (Ns == 0)
			Nu = 0;
		else
			Nu = Nd*Ld / Ns;//randa pagr chemeikalo reikaling� kiek�
		Pu = (Ld*Pd) - (Nu*Ps);//randa 1 pagalbinio chemikalo reikaling� kiek�
		Vu = (Ld*Vd) - (Nu*Vs);//randa 2 pagalbinio chemikalo reikaling� kiek�
							   //EndMix *end =
		double* num = new double[3];
		num[0] = Nu;
		num[1] = Pu;
		num[2] = Vu;
		EndMix mix;
		mix.Add(num);
		return mix;
	}

	double * BeginMix::Dissolve()//i�skaldo, � pointer�, jog b�t� galima kartu su EndMix klas�s nariais i�saugoti � fail�
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

	bool EndMix::Add(double *num)//priskyria per antrajo mi�inio klas�
	{
		Nu = num[0];
		Pu = num[1];
		Vu = num[2];
		return true;
	}

	void EndMix::Show()//siun�ia � ekran� prane�im� apie antr�j� mi�in�
	{
		String^ ret = "";
		ret += "Pagrindinio chemikalo reikia pripilti � nauj� mi�in� (ml): ";
		ret += Nu;
		ret += " \n";
		ret += "Pirmojo skied�iamojo chemikalo reikia pripilti � nauj� mi�in� (ml): ";
		ret += Pu;
		ret += " \n";
		ret += "Antrojo skied�iamojo chemikalo reikia pripilti � nauj� mi�in� (ml): ";
		ret += Vu;
		MessageBox::Show(ret, "End Mix", MessageBoxButtons::OK);
	}

	void EndMix::Save(double *num)//i�saugojimo � fail� funkcija
	{
		Ns = num[0];
		Ps = num[1];
		Vs = num[2];
		Nd = num[3];
		Pd = num[4];
		Vd = num[5];
		Ld = num[6];
		if (MessageBox::Show(
			"Ar norite i�saugoti informacij� � tekstin� fail�?",
			"Ar i�saugoti faile?", MessageBoxButtons::YesNo,
			MessageBoxIcon::Question) == ::System::Windows::Forms::DialogResult::Yes)
		{
			String^ ret = "";
			ret += "Pagrindinio chemikalo kiekis(mg/ml): ";
			ret += Ns;
			ret += " \n";
			ret += "Pirmojo skied�iamojo chemikalo santykis pradin�je med�iagoje (%): ";
			ret += GetPrecent(Ps);
			ret += " \n";
			ret += "Antrojo skied�iamojo chemikalo santykis pradin�je med�iagoje (%): ";
			ret += GetPrecent(Vs);
			ret += " \n";
			ret + "Norimas pasigaminti galutin�s med�iagos kiekis(ml): ";
			ret += Ld;
			ret += " \n";
			ret += "Norimas pagrindinio chemikalo kiekis(mg/ml): ";
			ret += Nd;
			ret += " \n";
			ret += "Pirmojo skied�iamojo chemikalo santykis galutin�je med�iagoje (%): ";
			ret += GetPrecent(Pd);
			ret += " \n";
			ret += "Antrojo skied�iamojo chemikalo santykis galutin�je med�iagoje (%): ";
			ret += GetPrecent(Vd);
			ret += " \n";
			ret += "Pagrindinio chemikalo reikia pripilti � nauj� mi�in� (ml): ";
			ret += Nu;
			ret += " \n";
			ret += "Pirmojo skied�iamojo chemikalo reikia pripilti � nauj� mi�in� (ml): ";
			ret += Pu;
			ret += " \n";
			ret += "Antrojo skied�iamojo chemikalo reikia pripilti � nauj� mi�in� (ml): ";
			ret += Vu;

			SaveFileDialog^ sfd = gcnew SaveFileDialog(); //sukuria failo i�saugojimo kintamaj�
			try
			{
				sfd->Filter = "Tekstinis �ra�as|*.txt"; // parenkamas failo i�saugojimo formatas
				sfd->FileName = "MyMix"; // pradinis failo vardas
				sfd->Title = "I�saugoti �ra��"; //i�saugojimo lango pavadinimas
				if (sfd->ShowDialog() == DialogResult::OK)
				{
					String^ path = sfd->FileName; //failo kelio ir pavadinimo nustatymas
					StreamWriter^ writer = gcnew StreamWriter(File::Create(path)); //failo sukurimas nurodytame kelyje ir pavadinimu kaip nurodyta
					try
					{
						writer->Write(ret); //�ra�oma informacija i� ateinan�io kintamojo � fail�

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