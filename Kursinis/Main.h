#pragma once
#include "MixClass.h"

namespace Kursinis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	void ChangeValues(TrackBar^ track, Label^ l1, Label^ l2);
	void MainFunc(double* num);

	/// <summary>
	/// Summary for Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}





	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::NumericUpDown^  Nstart;
	private: System::Windows::Forms::Panel^  panel1;



	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::NumericUpDown^  liquiddesired;

	private: System::Windows::Forms::Label^  label7;





	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::NumericUpDown^  Ndesired;

	private: System::Windows::Forms::Button^  button1;



	private: System::Windows::Forms::Label^  Vvalue1;

	private: System::Windows::Forms::TrackBar^  PVslider1;
	private: System::Windows::Forms::Label^  Pvalue1;
	private: System::Windows::Forms::Label^  Pvalue2;
	private: System::Windows::Forms::Label^  Vvalue2;

	private: System::Windows::Forms::TrackBar^  PVslider2;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Nstart = (gcnew System::Windows::Forms::NumericUpDown());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Pvalue1 = (gcnew System::Windows::Forms::Label());
			this->Vvalue1 = (gcnew System::Windows::Forms::Label());
			this->PVslider1 = (gcnew System::Windows::Forms::TrackBar());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->Pvalue2 = (gcnew System::Windows::Forms::Label());
			this->liquiddesired = (gcnew System::Windows::Forms::NumericUpDown());
			this->Vvalue2 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->PVslider2 = (gcnew System::Windows::Forms::TrackBar());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->Ndesired = (gcnew System::Windows::Forms::NumericUpDown());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Nstart))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PVslider1))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->liquiddesired))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PVslider2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Ndesired))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(179, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Pagrindinio chemikalo kiekis (mg/ml)";
			// 
			// Nstart
			// 
			this->Nstart->Location = System::Drawing::Point(5, 16);
			this->Nstart->Name = L"Nstart";
			this->Nstart->Size = System::Drawing::Size(120, 21);
			this->Nstart->TabIndex = 2;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->Nstart);
			this->panel1->Controls->Add(this->Pvalue1);
			this->panel1->Controls->Add(this->Vvalue1);
			this->panel1->Controls->Add(this->PVslider1);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(383, 97);
			this->panel1->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 40);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(366, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Pirmojo ir antrojo skiedþiamojo chemikalo santykis pradinëje medþiagoje (%)";
			// 
			// Pvalue1
			// 
			this->Pvalue1->AutoSize = true;
			this->Pvalue1->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->Pvalue1->Location = System::Drawing::Point(6, 65);
			this->Pvalue1->Name = L"Pvalue1";
			this->Pvalue1->Size = System::Drawing::Size(42, 15);
			this->Pvalue1->TabIndex = 12;
			this->Pvalue1->Text = L"label8";
			// 
			// Vvalue1
			// 
			this->Vvalue1->AutoSize = true;
			this->Vvalue1->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->Vvalue1->Location = System::Drawing::Point(327, 65);
			this->Vvalue1->Name = L"Vvalue1";
			this->Vvalue1->Size = System::Drawing::Size(42, 15);
			this->Vvalue1->TabIndex = 3;
			this->Vvalue1->Text = L"label8";
			// 
			// PVslider1
			// 
			this->PVslider1->Location = System::Drawing::Point(54, 59);
			this->PVslider1->Maximum = 100;
			this->PVslider1->Name = L"PVslider1";
			this->PVslider1->Size = System::Drawing::Size(267, 45);
			this->PVslider1->TabIndex = 1;
			this->PVslider1->ValueChanged += gcnew System::EventHandler(this, &Main::PVslider1_ValueChanged);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->Pvalue2);
			this->panel2->Controls->Add(this->liquiddesired);
			this->panel2->Controls->Add(this->Vvalue2);
			this->panel2->Controls->Add(this->label7);
			this->panel2->Controls->Add(this->PVslider2);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->Ndesired);
			this->panel2->Location = System::Drawing::Point(12, 122);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(383, 138);
			this->panel2->TabIndex = 4;
			// 
			// Pvalue2
			// 
			this->Pvalue2->AutoSize = true;
			this->Pvalue2->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->Pvalue2->Location = System::Drawing::Point(6, 62);
			this->Pvalue2->Name = L"Pvalue2";
			this->Pvalue2->Size = System::Drawing::Size(42, 15);
			this->Pvalue2->TabIndex = 15;
			this->Pvalue2->Text = L"label8";
			// 
			// liquiddesired
			// 
			this->liquiddesired->Location = System::Drawing::Point(7, 107);
			this->liquiddesired->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->liquiddesired->Name = L"liquiddesired";
			this->liquiddesired->Size = System::Drawing::Size(120, 21);
			this->liquiddesired->TabIndex = 14;
			// 
			// Vvalue2
			// 
			this->Vvalue2->AutoSize = true;
			this->Vvalue2->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->Vvalue2->Location = System::Drawing::Point(327, 62);
			this->Vvalue2->Name = L"Vvalue2";
			this->Vvalue2->Size = System::Drawing::Size(42, 15);
			this->Vvalue2->TabIndex = 14;
			this->Vvalue2->Text = L"label8";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(6, 88);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(250, 13);
			this->label7->TabIndex = 13;
			this->label7->Text = L"Norimas pasigaminti galutinës medþiagos kiekis (ml)";
			// 
			// PVslider2
			// 
			this->PVslider2->Location = System::Drawing::Point(54, 56);
			this->PVslider2->Maximum = 100;
			this->PVslider2->Name = L"PVslider2";
			this->PVslider2->Size = System::Drawing::Size(267, 45);
			this->PVslider2->TabIndex = 13;
			this->PVslider2->ValueChanged += gcnew System::EventHandler(this, &Main::PVslider2_ValueChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(4, 40);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(367, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Pirmojo ir antrojo skiedþiamojo chemikalo santykis galutinëje medþiagoje (%)";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(3, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(221, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Norimas pagrindinio chemikalo kiekis (mg/ml)";
			// 
			// Ndesired
			// 
			this->Ndesired->Location = System::Drawing::Point(6, 16);
			this->Ndesired->Name = L"Ndesired";
			this->Ndesired->Size = System::Drawing::Size(120, 21);
			this->Ndesired->TabIndex = 8;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 273);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(383, 33);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Skaièiuoti";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Main::button1_Click);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(407, 318);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"Main";
			this->Text = L"Main";
			this->Load += gcnew System::EventHandler(this, &Main::Main_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Nstart))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PVslider1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->liquiddesired))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PVslider2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Ndesired))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)//viskà sukelia á pointerá ir po to siunèia já á main.cpp esanèià funkcijà.
{
	double *num = new double[7];
	num[0] = Convert::ToDouble(Nstart->Value);
	num[1] = Convert::ToDouble(Pvalue1->Text) / 100.0;
	num[2] = Convert::ToDouble(Vvalue1->Text) / 100.0;
	num[3] = Convert::ToDouble(Ndesired->Value);
	num[4] = Convert::ToDouble(Pvalue2->Text) / 100.0;
	num[5] = Convert::ToDouble(Vvalue2->Text) / 100.0;
	num[6] = Convert::ToDouble(liquiddesired->Value);
	MainFunc(num);
}
private: System::Void apieToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
{

}
private: System::Void PVslider1_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
{
	ChangeValues(PVslider1, Pvalue1, Vvalue1);

}
private: System::Void PVslider2_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
{
	ChangeValues(PVslider2, Pvalue2, Vvalue2);
}
private: System::Void Main_Load(System::Object^  sender, System::EventArgs^  e)//paleidus programà visi label pasikeièia á slankiklyje esanèià numatytà reikðmæ
{
	ChangeValues(PVslider1, Pvalue1, Vvalue1);
	ChangeValues(PVslider2, Pvalue2, Vvalue2);
}
};
}


