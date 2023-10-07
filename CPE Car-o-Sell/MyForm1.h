#pragma once

namespace CPECaroSell {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
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

            // label1
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(12, 9);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(119, 13);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Sign Up for an Account";

            // usernameTextBox
            this->usernameTextBox->Location = System::Drawing::Point(12, 35);
            this->usernameTextBox->Name = L"usernameTextBox";
            this->usernameTextBox->Size = System::Drawing::Size(200, 20);
            this->usernameTextBox->TabIndex = 1;
            this->usernameTextBox->Text = L"";

            // passwordTextBox
            this->passwordTextBox->Location = System::Drawing::Point(12, 61);
            this->passwordTextBox->Name = L"passwordTextBox";
            this->passwordTextBox->Size = System::Drawing::Size(200, 20);
            this->passwordTextBox->TabIndex = 2;
            this->passwordTextBox->UseSystemPasswordChar = true;
            this->passwordTextBox->Text = L"";

            // signUpButton
            this->signUpButton->Location = System::Drawing::Point(12, 87);
            this->signUpButton->Name = L"signUpButton";
            this->signUpButton->Size = System::Drawing::Size(94, 23);
            this->signUpButton->TabIndex = 3;
            this->signUpButton->Text = L"Sign Up";
            this->signUpButton->Click += gcnew System::EventHandler(this, &MyForm1::signUpButton_Click);

            // cancelButton
            this->cancelButton->Location = System::Drawing::Point(118, 87);
            this->cancelButton->Name = L"cancelButton";
            this->cancelButton->Size = System::Drawing::Size(94, 23);
            this->cancelButton->TabIndex = 4;
            this->cancelButton->Text = L"Cancel";
            this->cancelButton->Click += gcnew System::EventHandler(this, &MyForm1::cancelButton_Click);

            // MyForm1
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(224, 126);
            this->Controls->Add(this->cancelButton);
            this->Controls->Add(this->signUpButton);
            this->Controls->Add(this->passwordTextBox);
            this->Controls->Add(this->usernameTextBox);
            this->Controls->Add(this->label1);
            this->Name = L"MyForm1";
            this->Text = L"Sign Up";
            this->ResumeLayout(false);
            this->PerformLayout();
        }

        System::Void signUpButton_Click(System::Object^ sender, System::EventArgs^ e)
			{
            // Handle sign-up logic here
            // For example, you can validate user input and create a new user account

            // After successful sign-up, you can close this form or perform other actions as needed
            this->Close();
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

        System::Void cancelButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
            // Handle cancel button click event
            // For example, you can close this form without performing sign-up
            this->Close();
		}
#pragma endregion
	};
}
