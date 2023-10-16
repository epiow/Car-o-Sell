#pragma once
#include <iostream>
#include <fstream>
#include <msclr/marshal_cppstd.h>
#include <Windows.h>
#include <cstdlib>
#include "userMainWindow.h"
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
			this->label1->Click += gcnew System::EventHandler(this, &carSignUp::label1_Click);
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
		
		System::Void carSignUp::signUpButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			// Get the username and password entered by the user
			String^ newUsername = usernameTextBox->Text;
			String^ newPassword = passwordTextBox->Text;

			// Check if the username already exists in the CSV file
			bool isDuplicate = CheckForDuplicateUsername("UserData.csv", newUsername);

			if (isDuplicate)
			{
				MessageBox::Show(L"Username already exists. Please choose a different username.");
			}
			else
			{
				// Append the new username and password to the CSV file
				AddUserToCSV("UserData.csv", newUsername, newPassword);

				MessageBox::Show(L"Account created successfully!");
				this->Close();
			}
		}

		// Function to check for a duplicate username in the CSV file
		bool carSignUp::CheckForDuplicateUsername(String^ filename, String^ newUsername)
		{
			std::ifstream file(msclr::interop::marshal_as<std::string>(filename));

			if (!file.is_open())
			{
				// File not found or unable to open
				return false;
			}

			std::string line;
			while (std::getline(file, line))
			{
				std::istringstream iss(line);
				std::string username;
				if (std::getline(iss, username, ','))
				{
					// Convert the read username to a managed string
					String^ managedUsername = gcnew String(username.c_str());

					// Check if the read username matches the new username
					if (String::Equals(managedUsername, newUsername))
					{
						file.close();
						return true; // Username already exists
					}
				}
			}

			file.close();
			return false; // Username does not exist
		}

		// Function to add a new user to the CSV file
		void carSignUp::AddUserToCSV(String^ filename, String^ newUsername, String^ newPassword)
		{
			std::ofstream file(msclr::interop::marshal_as<std::string>(filename), std::ios::app);

			if (!file.is_open())
			{
				// File not found or unable to open
				MessageBox::Show(L"Error: Unable to create a new user account.");
				return;
			}

			// Write the new username and password to the file
			file << msclr::interop::marshal_as<std::string>(newUsername) << "," << msclr::interop::marshal_as<std::string>(newPassword) << std::endl;

			file.close();
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
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
