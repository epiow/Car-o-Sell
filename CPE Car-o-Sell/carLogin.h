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

        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ label2;
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
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->exitButton = (gcnew System::Windows::Forms::Button());
            this->signUpButton = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // usernameTextBox
            // 
            this->usernameTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->usernameTextBox->Location = System::Drawing::Point(29, 298);
            this->usernameTextBox->Name = L"usernameTextBox";
            this->usernameTextBox->Size = System::Drawing::Size(212, 22);
            this->usernameTextBox->TabIndex = 0;
            this->usernameTextBox->TextChanged += gcnew System::EventHandler(this, &carLogin::usernameTextBox_TextChanged);
            // 
            // passwordTextBox
            // 
            this->passwordTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->passwordTextBox->Location = System::Drawing::Point(29, 393);
            this->passwordTextBox->Name = L"passwordTextBox";
            this->passwordTextBox->PasswordChar = '*';
            this->passwordTextBox->Size = System::Drawing::Size(212, 22);
            this->passwordTextBox->TabIndex = 1;
            this->passwordTextBox->TextChanged += gcnew System::EventHandler(this, &carLogin::passwordTextBox_TextChanged);
            // 
            // loginButton
            // 
            this->loginButton->Location = System::Drawing::Point(29, 621);
            this->loginButton->Name = L"loginButton";
            this->loginButton->Size = System::Drawing::Size(115, 36);
            this->loginButton->TabIndex = 2;
            this->loginButton->Text = L"Login";
            this->loginButton->Click += gcnew System::EventHandler(this, &carLogin::loginButton_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Rockwell Condensed", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(20, 260);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(124, 35);
            this->label1->TabIndex = 4;
            this->label1->Text = L"USERNAME";
            this->label1->Click += gcnew System::EventHandler(this, &carLogin::label1_Click);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Rockwell Condensed", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(23, 355);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(124, 35);
            this->label2->TabIndex = 5;
            this->label2->Text = L"PASSWORD";
            this->label2->Click += gcnew System::EventHandler(this, &carLogin::label2_Click);
            // 
            // exitButton
            // 
            this->exitButton->Location = System::Drawing::Point(750, 10);
            this->exitButton->Name = L"exitButton";
            this->exitButton->Size = System::Drawing::Size(40, 40);
            this->exitButton->TabIndex = 4;
            this->exitButton->Text = L"X";
            this->exitButton->Click += gcnew System::EventHandler(this, &carLogin::exitButton_Click);
            // 
            // signUpButton
            // 
            this->signUpButton->Location = System::Drawing::Point(165, 621);
            this->signUpButton->Name = L"signUpButton";
            this->signUpButton->Size = System::Drawing::Size(107, 35);
            this->signUpButton->TabIndex = 6;
            this->signUpButton->Text = L"Sign Up";
            this->signUpButton->UseVisualStyleBackColor = true;
            // 
            // carLogin
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->ClientSize = System::Drawing::Size(800, 800);
            this->Controls->Add(this->signUpButton);
            this->Controls->Add(this->exitButton);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->usernameTextBox);
            this->Controls->Add(this->passwordTextBox);
            this->Controls->Add(this->loginButton);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
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
