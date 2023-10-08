#pragma once

namespace CPECaroSell {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for carSignUp
	/// </summary>
	public ref class carSignUp : public System::Windows::Forms::Form
	{
	public:
		carSignUp(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

    private:
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::TextBox^ usernameTextBox;
        System::Windows::Forms::TextBox^ passwordTextBox;
        System::Windows::Forms::Button^ signUpButton;
        System::Windows::Forms::Button^ cancelButton;

        void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->usernameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->signUpButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(16, 11);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(142, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Sign Up for an Account";
			// 
			// usernameTextBox
			// 
			this->usernameTextBox->Location = System::Drawing::Point(16, 43);
			this->usernameTextBox->Margin = System::Windows::Forms::Padding(4);
			this->usernameTextBox->Name = L"usernameTextBox";
			this->usernameTextBox->Size = System::Drawing::Size(265, 22);
			this->usernameTextBox->TabIndex = 1;
			// 
			// passwordTextBox
			// 
			this->passwordTextBox->Location = System::Drawing::Point(16, 75);
			this->passwordTextBox->Margin = System::Windows::Forms::Padding(4);
			this->passwordTextBox->Name = L"passwordTextBox";
			this->passwordTextBox->Size = System::Drawing::Size(265, 22);
			this->passwordTextBox->TabIndex = 2;
			this->passwordTextBox->UseSystemPasswordChar = true;
			// 
			// signUpButton
			// 
			this->signUpButton->Location = System::Drawing::Point(16, 107);
			this->signUpButton->Margin = System::Windows::Forms::Padding(4);
			this->signUpButton->Name = L"signUpButton";
			this->signUpButton->Size = System::Drawing::Size(125, 28);
			this->signUpButton->TabIndex = 3;
			this->signUpButton->Text = L"Sign Up";
			this->signUpButton->Click += gcnew System::EventHandler(this, &carSignUp::signUpButton_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->Location = System::Drawing::Point(157, 107);
			this->cancelButton->Margin = System::Windows::Forms::Padding(4);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(125, 28);
			this->cancelButton->TabIndex = 4;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->Click += gcnew System::EventHandler(this, &carSignUp::cancelButton_Click);
			// 
			// carSignUp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(299, 155);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->signUpButton);
			this->Controls->Add(this->passwordTextBox);
			this->Controls->Add(this->usernameTextBox);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"carSignUp";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Sign Up";
			this->Load += gcnew System::EventHandler(this, &carSignUp::carSignUp_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

        System::Void signUpButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
            // TO DO - INSERT FUNCTIONALITY WITH CSV FILE ADDING USERS
		}

	private:

		System::ComponentModel::Container ^components;

        System::Void cancelButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
            this->Close();
		}
#pragma endregion
	private: System::Void carSignUp_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
