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
    using namespace System::Windows::Forms;


    public ref class carLogin : public System::Windows::Forms::Form

    {
    public:
        carLogin(void)
        {
            InitializeComponent();
            LoadUserCredentials("UserData.csv");
            loginSuccessful = false;
        }
        void SetLoginSuccessful(bool value)
        {
            loginSuccessful = value;
        }
        bool SetLoginSuccessful() {
            return SetLoginSuccessful();
        }
    private:
        System::Windows::Forms::TextBox^ usernameTextBox;
        System::Windows::Forms::TextBox^ passwordTextBox;



        System::Windows::Forms::Button^ exitButton;
        System::Windows::Forms::Button^ loginButton;
        System::Windows::Forms::Button^ signUpButton;

        array<String^, 2>^ userCredentials;

       



    private: System::ComponentModel::IContainer^ components;

           bool loginSuccessful;

        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(carLogin::typeid));
            this->usernameTextBox = (gcnew System::Windows::Forms::TextBox());
            this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
            this->loginButton = (gcnew System::Windows::Forms::Button());
            this->exitButton = (gcnew System::Windows::Forms::Button());
            this->signUpButton = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // usernameTextBox
            // 
            this->usernameTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->usernameTextBox->BackColor = System::Drawing::SystemColors::Window;
            this->usernameTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->usernameTextBox->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->usernameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->usernameTextBox->Location = System::Drawing::Point(171, 355);
            this->usernameTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->usernameTextBox->Name = L"usernameTextBox";
            this->usernameTextBox->Size = System::Drawing::Size(407, 42);
            this->usernameTextBox->TabIndex = 0;
            this->usernameTextBox->TextChanged += gcnew System::EventHandler(this, &carLogin::usernameTextBox_TextChanged);
            // 
            // passwordTextBox
            // 
            this->passwordTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->passwordTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->passwordTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->passwordTextBox->Location = System::Drawing::Point(171, 463);
            this->passwordTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->passwordTextBox->Name = L"passwordTextBox";
            this->passwordTextBox->PasswordChar = '*';
            this->passwordTextBox->Size = System::Drawing::Size(407, 42);
            this->passwordTextBox->TabIndex = 1;
            this->passwordTextBox->TextChanged += gcnew System::EventHandler(this, &carLogin::passwordTextBox_TextChanged);
            // 
            // loginButton
            // 
            this->loginButton->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->loginButton->FlatAppearance->BorderSize = 0;
            this->loginButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->loginButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->loginButton->Location = System::Drawing::Point(171, 549);
            this->loginButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->loginButton->Name = L"loginButton";
            this->loginButton->Size = System::Drawing::Size(407, 75);
            this->loginButton->TabIndex = 2;
            this->loginButton->Text = L"Login";
            this->loginButton->UseVisualStyleBackColor = false;
            this->loginButton->Click += gcnew System::EventHandler(this, &carLogin::loginButton_Click);
            // 
            // exitButton
            // 
            this->exitButton->Location = System::Drawing::Point(688, 3);
            this->exitButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->exitButton->Name = L"exitButton";
            this->exitButton->Size = System::Drawing::Size(51, 54);
            this->exitButton->TabIndex = 4;
            this->exitButton->Text = L"X";
            this->exitButton->Click += gcnew System::EventHandler(this, &carLogin::exitButton_Click);
            // 
            // signUpButton
            // 
            this->signUpButton->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->signUpButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->signUpButton->FlatAppearance->BorderSize = 0;
            this->signUpButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->signUpButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->signUpButton->Location = System::Drawing::Point(171, 639);
            this->signUpButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->signUpButton->Name = L"signUpButton";
            this->signUpButton->Size = System::Drawing::Size(407, 73);
            this->signUpButton->TabIndex = 6;
            this->signUpButton->Text = L"Sign Up";
            this->signUpButton->UseVisualStyleBackColor = false;
            // 
            // carLogin
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->ClientSize = System::Drawing::Size(750, 750);
            this->Controls->Add(this->signUpButton);
            this->Controls->Add(this->exitButton);
            this->Controls->Add(this->usernameTextBox);
            this->Controls->Add(this->passwordTextBox);
            this->Controls->Add(this->loginButton);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->Name = L"carLogin";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Login Form";
            this->Load += gcnew System::EventHandler(this, &carLogin::carLogin_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }


        System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e)
        {

            if (MessageBox::Show(L"Do you want to exit the application?", L"Exit", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
            {

                this->Close();
            }
        }
        //DATABASE HANDLING GAMIT CSV

        void LoadUserCredentials(const std::string& filename)
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
            userCredentials = gcnew array<String^, 2>(data.size(), numColumns);
            for (int i = 0; i < data.size(); i++) {
                for (int j = 0; j < numColumns; j++) {
                    userCredentials[i, j] = gcnew String(data[i][j].c_str());
                }
            }
        }

        bool CheckUserCredentials(String^ username, String^ password)
        {
            for (int i = 0; i < userCredentials->GetLength(0); i++) {
                if (String::Equals(userCredentials[i, 0], username) && String::Equals(userCredentials[i, 1], password)) {
                    return true;
                }
            }
            return false;
        }

        bool CheckAdminCredentials(String^ username, String^ password)
        {
            for (int i = 0; i < userCredentials->GetLength(0); i++) {
                if (String::Equals(userCredentials[i, 0], username) && String::Equals(userCredentials[i, 1], password) && String::Equals(userCredentials[i, 2], "TRUE")) {
                    return true;
                }
            }
            return false;
        }


        public: User^ user = nullptr;

        public: bool SwitchToMain = false;
        public: bool SwitchToAdmin = false;
        public: String^ currentUser;
        System::Void loginButton_Click(System::Object^ sender, System::EventArgs^ e)
        {
            String^ username = usernameTextBox->Text;
            String^ password = passwordTextBox->Text;
            bool authenticated = CheckUserCredentials(username, password);
            bool admin = CheckAdminCredentials(username, password);

            if (admin)
            {
                SwitchToAdmin = true;
                this->Close();
            }
            else if(authenticated){
                currentUser = username;
                SwitchToMain = true;
                this->Close();
            }
            else
            {
                MessageBox::Show(L"Incorrect username or Password or Account Not Found. Please try again.");
            }
        }




    private: System::Void carLogin_Load(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void usernameTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void passwordTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
    }

    private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void button1_Click_2(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void bindingNavigator1_RefreshItems(System::Object^ sender, System::EventArgs^ e) {
    }
};
}
