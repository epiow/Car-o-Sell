#pragma once
#include <Windows.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
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
	public ref class userMainwindow : public System::Windows::Forms::Form
	{
	public:
		userMainwindow(void)
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
		~userMainwindow()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ sellBtn;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(userMainwindow::typeid));
			this->sellBtn = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// sellBtn
			// 
			this->sellBtn->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->sellBtn->FlatAppearance->BorderSize = 0;
			this->sellBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->sellBtn->Font = (gcnew System::Drawing::Font(L"Cooper Black", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sellBtn->Location = System::Drawing::Point(167, 456);
			this->sellBtn->Margin = System::Windows::Forms::Padding(2);
			this->sellBtn->Name = L"sellBtn";
			this->sellBtn->Size = System::Drawing::Size(416, 49);
			this->sellBtn->TabIndex = 1;
			this->sellBtn->Text = L"SELLING\?";
			this->sellBtn->UseVisualStyleBackColor = false;
			this->sellBtn->Click += gcnew System::EventHandler(this, &userMainwindow::sellBtn_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(10, 11);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"<---";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &userMainwindow::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Cooper Black", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(167, 348);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(416, 48);
			this->button2->TabIndex = 3;
			this->button2->Text = L"RENTING\?";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &userMainwindow::button2_Click);
			// 
			// userMainwindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDark;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(740, 650);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->sellBtn);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"userMainwindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &userMainwindow::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

	public: User ^ user = nullptr;
	
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

	}

	public: bool switchToLogin = false;
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		switchToLogin = true;
		this->Close();
	}

	public: bool switchToRentForm = false;
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		switchToRentForm = true;
		this->Close();
	}
	public: bool switchToSellWindow = false;
	private: System::Void sellBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		switchToSellWindow = true;
		this->Close();
}
};
}
