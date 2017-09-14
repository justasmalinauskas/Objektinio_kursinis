#pragma once
#include <string>
namespace Kursinis
{
	using namespace System;


	class Mix
	{
	protected:
		double Ns, Ps, Vs, Nd, Pd, Vd, Ld, Nu, Pu, Vu;
	private:
	public:
		Mix() {}
		virtual bool Add() { return false; };
		virtual void Show() = 0;
	};

	class EndMix : public Mix
	{
	private:
		double GetPrecent(double num)
		{
			return num * 100;
		}
	public:
		bool Add(double *num);
		void Show();
		void Save(double *num);
	};

	class BeginMix : public Mix
	{
	private:
		double GetPrecent(double num)//reikalinga, norint atsakimø praneðimuose ir failuose gauti procentus, o ne santyká
		{
			return num * 100;
		}
	public:
		bool Add(double *num);
		void Show();
		EndMix Calc();
		double* Dissolve();
	};
}
