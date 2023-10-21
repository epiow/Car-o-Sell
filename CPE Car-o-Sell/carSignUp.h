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

	private: System::Windows::Forms::TextBox^ emailTextBox;

        System::Windows::Forms::TextBox^ passwordTextBox;
        System::Windows::Forms::Button^ signUpButton;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
		   System::Windows::Forms::Button^ cancelButton;

        void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(carSignUp::typeid));
			this->emailTextBox = (gcnew System::Windows::Forms::TextBox());
			this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->signUpButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// emailTextBox
			// 
			this->emailTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->emailTextBox->Font = (gcnew System::Drawing::Font(L"SansSerif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->emailTextBox->Location = System::Drawing::Point(211, 315);
			this->emailTextBox->Name = L"emailTextBox";
			this->emailTextBox->Size = System::Drawing::Size(331, 28);
			this->emailTextBox->TabIndex = 1;
			// 
			// passwordTextBox
			// 
			this->passwordTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->passwordTextBox->Font = (gcnew System::Drawing::Font(L"SansSerif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->passwordTextBox->Location = System::Drawing::Point(211, 487);
			this->passwordTextBox->Name = L"passwordTextBox";
			this->passwordTextBox->Size = System::Drawing::Size(331, 28);
			this->passwordTextBox->TabIndex = 2;
			this->passwordTextBox->UseSystemPasswordChar = true;
			// 
			// signUpButton
			// 
			this->signUpButton->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->signUpButton->FlatAppearance->BorderSize = 0;
			this->signUpButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->signUpButton->Font = (gcnew System::Drawing::Font(L"Designer", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->signUpButton->Location = System::Drawing::Point(211, 634);
			this->signUpButton->Name = L"signUpButton";
			this->signUpButton->Size = System::Drawing::Size(136, 41);
			this->signUpButton->TabIndex = 3;
			this->signUpButton->Text = L"Sign Up";
			this->signUpButton->UseVisualStyleBackColor = false;
			this->signUpButton->Click += gcnew System::EventHandler(this, &carSignUp::signUpButton_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->cancelButton->FlatAppearance->BorderSize = 0;
			this->cancelButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cancelButton->Font = (gcnew System::Drawing::Font(L"Designer", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cancelButton->Location = System::Drawing::Point(406, 634);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(127, 41);
			this->cancelButton->TabIndex = 4;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = false;
			this->cancelButton->Click += gcnew System::EventHandler(this, &carSignUp::cancelButton_Click);
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"SansSerif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->textBox1->Location = System::Drawing::Point(211, 400);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(331, 28);
			this->textBox1->TabIndex = 5;
			// 
			// textBox2
			// 
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"SansSerif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->textBox2->Location = System::Drawing::Point(211, 574);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(331, 28);
			this->textBox2->TabIndex = 6;
			// 
			// carSignUp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(750, 750);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->signUpButton);
			this->Controls->Add(this->passwordTextBox);
			this->Controls->Add(this->emailTextBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
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
