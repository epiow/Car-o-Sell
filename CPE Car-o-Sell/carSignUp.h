#pragma once
#include <iostream>
#include <fstream>
#include <msclr/marshal_cppstd.h>
#include <Windows.h>
#include <cstdlib>
#include "userMainWindow.h"
#include "carSignUp.h"
#include "user.h"
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

        System::Windows::Forms::TextBox^ usernameTextBox;
        System::Windows::Forms::TextBox^ passwordTextBox;
        System::Windows::Forms::Button^ signUpButton;
	private: System::Windows::Forms::TextBox^ confirmPasswordTextBox;
		   System::Windows::Forms::Button^ cancelButton;

        void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(carSignUp::typeid));
			this->usernameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->signUpButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->confirmPasswordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// usernameTextBox
			// 
			this->usernameTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->usernameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->usernameTextBox->Location = System::Drawing::Point(213, 364);
			this->usernameTextBox->Name = L"usernameTextBox";
			this->usernameTextBox->Size = System::Drawing::Size(329, 28);
			this->usernameTextBox->TabIndex = 1;
			// 
			// passwordTextBox
			// 
			this->passwordTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->passwordTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passwordTextBox->Location = System::Drawing::Point(213, 451);
			this->passwordTextBox->Name = L"passwordTextBox";
			this->passwordTextBox->Size = System::Drawing::Size(329, 28);
			this->passwordTextBox->TabIndex = 2;
			this->passwordTextBox->UseSystemPasswordChar = true;
			this->passwordTextBox->TextChanged += gcnew System::EventHandler(this, &carSignUp::passwordTextBox_TextChanged);
			// 
			// signUpButton
			// 
			this->signUpButton->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->signUpButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->signUpButton->FlatAppearance->BorderSize = 0;
			this->signUpButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->signUpButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->signUpButton->Location = System::Drawing::Point(213, 599);
			this->signUpButton->Name = L"signUpButton";
			this->signUpButton->Size = System::Drawing::Size(136, 39);
			this->signUpButton->TabIndex = 3;
			this->signUpButton->Text = L"Sign Up";
			this->signUpButton->UseVisualStyleBackColor = false;
			this->signUpButton->Click += gcnew System::EventHandler(this, &carSignUp::signUpButton_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->cancelButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->cancelButton->FlatAppearance->BorderSize = 0;
			this->cancelButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cancelButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cancelButton->Location = System::Drawing::Point(403, 599);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(139, 39);
			this->cancelButton->TabIndex = 4;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = false;
			this->cancelButton->Click += gcnew System::EventHandler(this, &carSignUp::cancelButton_Click);
			// 
			// confirmPasswordTextBox
			// 
			this->confirmPasswordTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->confirmPasswordTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->confirmPasswordTextBox->Location = System::Drawing::Point(213, 535);
			this->confirmPasswordTextBox->Name = L"confirmPasswordTextBox";
			this->confirmPasswordTextBox->Size = System::Drawing::Size(329, 28);
			this->confirmPasswordTextBox->TabIndex = 2;
			this->confirmPasswordTextBox->UseSystemPasswordChar = true;
			this->confirmPasswordTextBox->TextChanged += gcnew System::EventHandler(this, &carSignUp::confirmPasswordTextBox_TextChanged);
			// 
			// carSignUp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(750, 750);
			this->Controls->Add(this->confirmPasswordTextBox);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->signUpButton);
			this->Controls->Add(this->passwordTextBox);
			this->Controls->Add(this->usernameTextBox);
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
			String^ confirmPassword = confirmPasswordTextBox->Text;

			// Check if the username already exists in the CSV file
			bool isDuplicate = CheckForDuplicateUsername("UserData.csv", newUsername);
			bool isPasswordMatch = IsPasswordMatch(newPassword, confirmPassword);

			if (isDuplicate)
			{
				MessageBox::Show(L"Username already exists. Please choose a different username.");
			}
			else if (!isPasswordMatch) {
				MessageBox::Show(L"Your password is not the same.");
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
		bool IsPasswordMatch(String^ newPassword, String^ confirmPassword) {
			return newPassword == confirmPassword;
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
			file << msclr::interop::marshal_as<std::string>(newUsername) << "," << msclr::interop::marshal_as<std::string>(newPassword) << ",FALSE" << std::endl;

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
private: System::Void passwordTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void confirmPasswordTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
