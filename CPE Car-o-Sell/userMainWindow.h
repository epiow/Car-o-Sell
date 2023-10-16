#pragma once
#include "rentWindow.h"
#include <Windows.h>
#include <cstdlib>
#include "carSignUp.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

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
	private: System::Windows::Forms::Button^ rentBtn;
	private: System::Windows::Forms::Button^ sellBtn;
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
			this->rentBtn = (gcnew System::Windows::Forms::Button());
			this->sellBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// rentBtn
			// 
			this->rentBtn->Font = (gcnew System::Drawing::Font(L"Cooper Black", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rentBtn->Location = System::Drawing::Point(231, 225);
			this->rentBtn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->rentBtn->Name = L"rentBtn";
			this->rentBtn->Size = System::Drawing::Size(272, 151);
			this->rentBtn->TabIndex = 0;
			this->rentBtn->Text = L"RENT";
			this->rentBtn->UseVisualStyleBackColor = true;
			this->rentBtn->Click += gcnew System::EventHandler(this, &userMainwindow::button1_Click);
			// 
			// sellBtn
			// 
			this->sellBtn->Font = (gcnew System::Drawing::Font(L"Cooper Black", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sellBtn->Location = System::Drawing::Point(231, 475);
			this->sellBtn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->sellBtn->Name = L"sellBtn";
			this->sellBtn->Size = System::Drawing::Size(272, 158);
			this->sellBtn->TabIndex = 1;
			this->sellBtn->Text = L"SELL";
			this->sellBtn->UseVisualStyleBackColor = true;
			// 
			// userMainwindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDark;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(987, 800);
			this->Controls->Add(this->sellBtn);
			this->Controls->Add(this->rentBtn);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"userMainwindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &userMainwindow::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		rentWindow^ obj = gcnew rentWindow();
		obj->ShowDialog();
		this->Close();
	}
	};
}
