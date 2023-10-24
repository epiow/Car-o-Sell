#pragma once
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "calendar.h"
#include "user.h"

namespace CPECaroSell {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class rentWindow : public System::Windows::Forms::Form
	{
	public:
		rentWindow(User^ user)
		{
			InitializeComponent();
			Loadcarinfo("Transaction.csv");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~rentWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ car1;
	protected:
	private: System::Windows::Forms::Label^ model1;
	private: System::Windows::Forms::Label^ brand1;
	private: System::Windows::Forms::Label^ platenum1;

	private: System::Windows::Forms::Label^ seats1;

	private: System::Windows::Forms::Label^ cost1;

	private: System::Windows::Forms::Label^ transmission1;
    
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Panel^ panel1;
    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::Label^ label8;
    private: System::Windows::Forms::Label^ label9;
    private: System::Windows::Forms::Label^ label10;
    private: System::Windows::Forms::Label^ platenum2;

    private: System::Windows::Forms::Label^ seats2;

    private: System::Windows::Forms::Label^ cost2;

    private: System::Windows::Forms::Label^ transmission2;

    private: System::Windows::Forms::Label^ brand2;

    private: System::Windows::Forms::Label^ model2;

    private: System::Windows::Forms::Panel^ panel2;
    private: System::Windows::Forms::Label^ label17;
    private: System::Windows::Forms::Label^ label18;
    private: System::Windows::Forms::Label^ label19;
    private: System::Windows::Forms::Label^ label20;
    private: System::Windows::Forms::Label^ label21;
    private: System::Windows::Forms::Label^ platenum3;
    private: System::Windows::Forms::Label^ seats3;



    private: System::Windows::Forms::Label^ cost3;

    private: System::Windows::Forms::Label^ transmission3;

    private: System::Windows::Forms::Label^ brand3;
    private: System::Windows::Forms::Label^ model3;


    private: System::Windows::Forms::Panel^ panel3;
    private: System::Windows::Forms::Label^ label28;
    private: System::Windows::Forms::Label^ label29;
    private: System::Windows::Forms::Label^ label30;
    private: System::Windows::Forms::Label^ label31;
    private: System::Windows::Forms::Label^ label32;
    private: System::Windows::Forms::Label^ platenum4;

    private: System::Windows::Forms::Label^ seats4;

    private: System::Windows::Forms::Label^ cost4;

    private: System::Windows::Forms::Label^ transmission4;

    private: System::Windows::Forms::Label^ brand4;

    private: System::Windows::Forms::Label^ model4;

    private: System::Windows::Forms::Panel^ panel4;
    private: System::Windows::Forms::Label^ label39;
    private: System::Windows::Forms::Label^ label40;
    private: System::Windows::Forms::Label^ label41;
    private: System::Windows::Forms::Label^ label42;
    private: System::Windows::Forms::Label^ label43;
    private: System::Windows::Forms::Label^ platenum5;

    private: System::Windows::Forms::Label^ seats5;

    private: System::Windows::Forms::Label^ cost5;

    private: System::Windows::Forms::Label^ transmission5;

    private: System::Windows::Forms::Label^ brand5;

private: System::Windows::Forms::Label^ model5;

    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::Button^ button3;
    private: System::Windows::Forms::Button^ button4;
    private: System::Windows::Forms::Button^ button5;
private: System::Windows::Forms::Button^ exitButton;


 array<String^, 2>^ carinfo;


	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(rentWindow::typeid));
			this->car1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->platenum1 = (gcnew System::Windows::Forms::Label());
			this->seats1 = (gcnew System::Windows::Forms::Label());
			this->cost1 = (gcnew System::Windows::Forms::Label());
			this->transmission1 = (gcnew System::Windows::Forms::Label());
			this->brand1 = (gcnew System::Windows::Forms::Label());
			this->model1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->platenum2 = (gcnew System::Windows::Forms::Label());
			this->seats2 = (gcnew System::Windows::Forms::Label());
			this->cost2 = (gcnew System::Windows::Forms::Label());
			this->transmission2 = (gcnew System::Windows::Forms::Label());
			this->brand2 = (gcnew System::Windows::Forms::Label());
			this->model2 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->platenum3 = (gcnew System::Windows::Forms::Label());
			this->seats3 = (gcnew System::Windows::Forms::Label());
			this->cost3 = (gcnew System::Windows::Forms::Label());
			this->transmission3 = (gcnew System::Windows::Forms::Label());
			this->brand3 = (gcnew System::Windows::Forms::Label());
			this->model3 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->platenum4 = (gcnew System::Windows::Forms::Label());
			this->seats4 = (gcnew System::Windows::Forms::Label());
			this->cost4 = (gcnew System::Windows::Forms::Label());
			this->transmission4 = (gcnew System::Windows::Forms::Label());
			this->brand4 = (gcnew System::Windows::Forms::Label());
			this->model4 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->platenum5 = (gcnew System::Windows::Forms::Label());
			this->seats5 = (gcnew System::Windows::Forms::Label());
			this->cost5 = (gcnew System::Windows::Forms::Label());
			this->transmission5 = (gcnew System::Windows::Forms::Label());
			this->brand5 = (gcnew System::Windows::Forms::Label());
			this->model5 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->car1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// car1
			// 
			this->car1->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->car1->Controls->Add(this->label1);
			this->car1->Controls->Add(this->label2);
			this->car1->Controls->Add(this->label3);
			this->car1->Controls->Add(this->label4);
			this->car1->Controls->Add(this->label5);
			this->car1->Controls->Add(this->platenum1);
			this->car1->Controls->Add(this->seats1);
			this->car1->Controls->Add(this->cost1);
			this->car1->Controls->Add(this->transmission1);
			this->car1->Controls->Add(this->brand1);
			this->car1->Controls->Add(this->model1);
			resources->ApplyResources(this->car1, L"car1");
			this->car1->Name = L"car1";
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label1->Name = L"label1";
			this->label1->Click += gcnew System::EventHandler(this, &rentWindow::label1_Click);
			// 
			// label2
			// 
			resources->ApplyResources(this->label2, L"label2");
			this->label2->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label2->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label2->Name = L"label2";
			// 
			// label3
			// 
			resources->ApplyResources(this->label3, L"label3");
			this->label3->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label3->Name = L"label3";
			// 
			// label4
			// 
			resources->ApplyResources(this->label4, L"label4");
			this->label4->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label4->Name = L"label4";
			// 
			// label5
			// 
			resources->ApplyResources(this->label5, L"label5");
			this->label5->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label5->Name = L"label5";
			// 
			// platenum1
			// 
			resources->ApplyResources(this->platenum1, L"platenum1");
			this->platenum1->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->platenum1->Name = L"platenum1";
			this->platenum1->Click += gcnew System::EventHandler(this, &rentWindow::platenum1_Click);
			// 
			// seats1
			// 
			resources->ApplyResources(this->seats1, L"seats1");
			this->seats1->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->seats1->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->seats1->Name = L"seats1";
			// 
			// cost1
			// 
			resources->ApplyResources(this->cost1, L"cost1");
			this->cost1->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->cost1->Name = L"cost1";
			// 
			// transmission1
			// 
			resources->ApplyResources(this->transmission1, L"transmission1");
			this->transmission1->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->transmission1->Name = L"transmission1";
			// 
			// brand1
			// 
			resources->ApplyResources(this->brand1, L"brand1");
			this->brand1->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->brand1->Name = L"brand1";
			// 
			// model1
			// 
			resources->ApplyResources(this->model1, L"model1");
			this->model1->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->model1->Name = L"model1";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->label9);
			this->panel1->Controls->Add(this->label10);
			this->panel1->Controls->Add(this->platenum2);
			this->panel1->Controls->Add(this->seats2);
			this->panel1->Controls->Add(this->cost2);
			this->panel1->Controls->Add(this->transmission2);
			this->panel1->Controls->Add(this->brand2);
			this->panel1->Controls->Add(this->model2);
			resources->ApplyResources(this->panel1, L"panel1");
			this->panel1->Name = L"panel1";
			// 
			// label6
			// 
			resources->ApplyResources(this->label6, L"label6");
			this->label6->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label6->Name = L"label6";
			// 
			// label7
			// 
			resources->ApplyResources(this->label7, L"label7");
			this->label7->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label7->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label7->Name = L"label7";
			// 
			// label8
			// 
			resources->ApplyResources(this->label8, L"label8");
			this->label8->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label8->Name = L"label8";
			// 
			// label9
			// 
			resources->ApplyResources(this->label9, L"label9");
			this->label9->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label9->Name = L"label9";
			// 
			// label10
			// 
			resources->ApplyResources(this->label10, L"label10");
			this->label10->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label10->Name = L"label10";
			// 
			// platenum2
			// 
			resources->ApplyResources(this->platenum2, L"platenum2");
			this->platenum2->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->platenum2->Name = L"platenum2";
			// 
			// seats2
			// 
			resources->ApplyResources(this->seats2, L"seats2");
			this->seats2->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->seats2->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->seats2->Name = L"seats2";
			// 
			// cost2
			// 
			resources->ApplyResources(this->cost2, L"cost2");
			this->cost2->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->cost2->Name = L"cost2";
			// 
			// transmission2
			// 
			resources->ApplyResources(this->transmission2, L"transmission2");
			this->transmission2->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->transmission2->Name = L"transmission2";
			// 
			// brand2
			// 
			resources->ApplyResources(this->brand2, L"brand2");
			this->brand2->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->brand2->Name = L"brand2";
			// 
			// model2
			// 
			resources->ApplyResources(this->model2, L"model2");
			this->model2->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->model2->Name = L"model2";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->panel2->Controls->Add(this->label17);
			this->panel2->Controls->Add(this->label18);
			this->panel2->Controls->Add(this->label19);
			this->panel2->Controls->Add(this->label20);
			this->panel2->Controls->Add(this->label21);
			this->panel2->Controls->Add(this->platenum3);
			this->panel2->Controls->Add(this->seats3);
			this->panel2->Controls->Add(this->cost3);
			this->panel2->Controls->Add(this->transmission3);
			this->panel2->Controls->Add(this->brand3);
			this->panel2->Controls->Add(this->model3);
			resources->ApplyResources(this->panel2, L"panel2");
			this->panel2->Name = L"panel2";
			// 
			// label17
			// 
			resources->ApplyResources(this->label17, L"label17");
			this->label17->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label17->Name = L"label17";
			// 
			// label18
			// 
			resources->ApplyResources(this->label18, L"label18");
			this->label18->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label18->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label18->Name = L"label18";
			// 
			// label19
			// 
			resources->ApplyResources(this->label19, L"label19");
			this->label19->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label19->Name = L"label19";
			// 
			// label20
			// 
			resources->ApplyResources(this->label20, L"label20");
			this->label20->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label20->Name = L"label20";
			// 
			// label21
			// 
			resources->ApplyResources(this->label21, L"label21");
			this->label21->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label21->Name = L"label21";
			// 
			// platenum3
			// 
			resources->ApplyResources(this->platenum3, L"platenum3");
			this->platenum3->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->platenum3->Name = L"platenum3";
			// 
			// seats3
			// 
			resources->ApplyResources(this->seats3, L"seats3");
			this->seats3->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->seats3->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->seats3->Name = L"seats3";
			// 
			// cost3
			// 
			resources->ApplyResources(this->cost3, L"cost3");
			this->cost3->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->cost3->Name = L"cost3";
			// 
			// transmission3
			// 
			resources->ApplyResources(this->transmission3, L"transmission3");
			this->transmission3->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->transmission3->Name = L"transmission3";
			// 
			// brand3
			// 
			resources->ApplyResources(this->brand3, L"brand3");
			this->brand3->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->brand3->Name = L"brand3";
			// 
			// model3
			// 
			resources->ApplyResources(this->model3, L"model3");
			this->model3->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->model3->Name = L"model3";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->panel3->Controls->Add(this->label28);
			this->panel3->Controls->Add(this->label29);
			this->panel3->Controls->Add(this->label30);
			this->panel3->Controls->Add(this->label31);
			this->panel3->Controls->Add(this->label32);
			this->panel3->Controls->Add(this->platenum4);
			this->panel3->Controls->Add(this->seats4);
			this->panel3->Controls->Add(this->cost4);
			this->panel3->Controls->Add(this->transmission4);
			this->panel3->Controls->Add(this->brand4);
			this->panel3->Controls->Add(this->model4);
			resources->ApplyResources(this->panel3, L"panel3");
			this->panel3->Name = L"panel3";
			// 
			// label28
			// 
			resources->ApplyResources(this->label28, L"label28");
			this->label28->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label28->Name = L"label28";
			// 
			// label29
			// 
			resources->ApplyResources(this->label29, L"label29");
			this->label29->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label29->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label29->Name = L"label29";
			// 
			// label30
			// 
			resources->ApplyResources(this->label30, L"label30");
			this->label30->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label30->Name = L"label30";
			// 
			// label31
			// 
			resources->ApplyResources(this->label31, L"label31");
			this->label31->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label31->Name = L"label31";
			// 
			// label32
			// 
			resources->ApplyResources(this->label32, L"label32");
			this->label32->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label32->Name = L"label32";
			// 
			// platenum4
			// 
			resources->ApplyResources(this->platenum4, L"platenum4");
			this->platenum4->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->platenum4->Name = L"platenum4";
			// 
			// seats4
			// 
			resources->ApplyResources(this->seats4, L"seats4");
			this->seats4->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->seats4->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->seats4->Name = L"seats4";
			// 
			// cost4
			// 
			resources->ApplyResources(this->cost4, L"cost4");
			this->cost4->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->cost4->Name = L"cost4";
			// 
			// transmission4
			// 
			resources->ApplyResources(this->transmission4, L"transmission4");
			this->transmission4->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->transmission4->Name = L"transmission4";
			// 
			// brand4
			// 
			resources->ApplyResources(this->brand4, L"brand4");
			this->brand4->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->brand4->Name = L"brand4";
			// 
			// model4
			// 
			resources->ApplyResources(this->model4, L"model4");
			this->model4->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->model4->Name = L"model4";
			// 
			// panel4
			// 
			resources->ApplyResources(this->panel4, L"panel4");
			this->panel4->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->panel4->Controls->Add(this->label39);
			this->panel4->Controls->Add(this->label40);
			this->panel4->Controls->Add(this->label41);
			this->panel4->Controls->Add(this->label42);
			this->panel4->Controls->Add(this->label43);
			this->panel4->Controls->Add(this->platenum5);
			this->panel4->Controls->Add(this->seats5);
			this->panel4->Controls->Add(this->cost5);
			this->panel4->Controls->Add(this->transmission5);
			this->panel4->Controls->Add(this->brand5);
			this->panel4->Controls->Add(this->model5);
			this->panel4->Name = L"panel4";
			// 
			// label39
			// 
			resources->ApplyResources(this->label39, L"label39");
			this->label39->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label39->Name = L"label39";
			// 
			// label40
			// 
			resources->ApplyResources(this->label40, L"label40");
			this->label40->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label40->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label40->Name = L"label40";
			// 
			// label41
			// 
			resources->ApplyResources(this->label41, L"label41");
			this->label41->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label41->Name = L"label41";
			// 
			// label42
			// 
			resources->ApplyResources(this->label42, L"label42");
			this->label42->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label42->Name = L"label42";
			// 
			// label43
			// 
			resources->ApplyResources(this->label43, L"label43");
			this->label43->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label43->Name = L"label43";
			// 
			// platenum5
			// 
			resources->ApplyResources(this->platenum5, L"platenum5");
			this->platenum5->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->platenum5->Name = L"platenum5";
			// 
			// seats5
			// 
			resources->ApplyResources(this->seats5, L"seats5");
			this->seats5->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->seats5->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->seats5->Name = L"seats5";
			// 
			// cost5
			// 
			resources->ApplyResources(this->cost5, L"cost5");
			this->cost5->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->cost5->Name = L"cost5";
			// 
			// transmission5
			// 
			resources->ApplyResources(this->transmission5, L"transmission5");
			this->transmission5->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->transmission5->Name = L"transmission5";
			// 
			// brand5
			// 
			resources->ApplyResources(this->brand5, L"brand5");
			this->brand5->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->brand5->Name = L"brand5";
			// 
			// model5
			// 
			resources->ApplyResources(this->model5, L"model5");
			this->model5->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->model5->Name = L"model5";
			// 
			// button1
			// 
			resources->ApplyResources(this->button1, L"button1");
			this->button1->Name = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &rentWindow::button1_Click);
			// 
			// button2
			// 
			resources->ApplyResources(this->button2, L"button2");
			this->button2->Name = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &rentWindow::button1_Click);
			// 
			// button3
			// 
			resources->ApplyResources(this->button3, L"button3");
			this->button3->Name = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &rentWindow::button1_Click);
			// 
			// button4
			// 
			resources->ApplyResources(this->button4, L"button4");
			this->button4->Name = L"button4";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &rentWindow::button1_Click);
			// 
			// button5
			// 
			resources->ApplyResources(this->button5, L"button5");
			this->button5->Name = L"button5";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &rentWindow::button1_Click);
			// 
			// exitButton
			// 
			resources->ApplyResources(this->exitButton, L"exitButton");
			this->exitButton->Name = L"exitButton";
			this->exitButton->Click += gcnew System::EventHandler(this, &rentWindow::exitButton_Click);
			// 
			// rentWindow
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->car1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"rentWindow";
			this->Load += gcnew System::EventHandler(this, &rentWindow::rentWindow_Load);
			this->car1->ResumeLayout(false);
			this->car1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	
		void Loadcarinfo(const std::string& filename)
		{
			std::ifstream file(filename);

			if (!file.is_open()) {
				MessageBox::Show(L"Error. Unable to open user credentials file.");
				return;
			}

			std::vector<std::vector<std::string>> data;
			std::string line;
			while (std::getline(file, line)) {
				std::vector<std::string> row;
				std::istringstream iss(line);
				std::string cell;
				while (std::getline(iss, cell, ',')) {
					row.push_back(cell);
				}
				data.push_back(row);
			}

			file.close();
			int numColumns = data.empty() ? 0 : data[0].size();
			for (const auto& row : data) {
				if (row.size() != numColumns) {
					MessageBox::Show(L"Error. Inconsistent number of columns in user credentials file.");
					return;
				}
			}
			// CONVERSION TO ARRAY FROM CSV ^__^
			carinfo = gcnew array<String^, 2>(data.size(), numColumns);
			for (int i = 0; i < data.size(); i++) {
				for (int j = 0; j < numColumns; j++) {
					carinfo[i, j] = gcnew String(data[i][j].c_str());
				}
			}
		}
private: System::Void platenum1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void rentWindow_Load(System::Object^ sender, System::EventArgs^ e) {
	model1->Text = carinfo[1, 0];
	brand1->Text = carinfo[1, 1];
	transmission1->Text = carinfo[1, 2];
	cost1->Text = carinfo[1, 3];
	seats1->Text = carinfo[1, 4];
	platenum1->Text = carinfo[1, 5];
    model2->Text = carinfo[2, 0];
    brand2->Text = carinfo[2, 1];
    transmission2->Text = carinfo[2, 2];
    cost2->Text = carinfo[2, 3];
    seats2->Text = carinfo[2, 4];
    platenum2->Text = carinfo[2, 5];
    model3->Text = carinfo[3, 0];
    brand3->Text = carinfo[3, 1];
    transmission3->Text = carinfo[3, 2];
    cost3->Text = carinfo[3, 3];
    seats3->Text = carinfo[3, 4];
    platenum3->Text = carinfo[3, 5];
    model4->Text = carinfo[4, 0];
    brand4->Text = carinfo[4, 1];
    transmission4->Text = carinfo[4, 2];
    cost4->Text = carinfo[4, 3];
    seats4->Text = carinfo[4, 4];
    platenum4->Text = carinfo[4, 5];
    model5->Text = carinfo[5, 0];
    brand5->Text = carinfo[5, 1];
    transmission5->Text = carinfo[5, 2];
    cost5->Text = carinfo[5, 3];
    seats5->Text = carinfo[5, 4];
    platenum5->Text = carinfo[5, 5];

}


public: bool switchBackToUserMain = false;

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	switchBackToUserMain = true;
    this->Close();
}

private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) {
    if (MessageBox::Show(L"Do you want to exit the application?", L"Exit", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
    {
		switchBackToUserMain = true;
        this->Close();	
    }
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
