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
    private: System::Windows::Forms::BindingNavigator^ bindingNavigator1;
    private: System::ComponentModel::IContainer^ components;
    private: System::Windows::Forms::ToolStripButton^ bindingNavigatorAddNewItem;
    private: System::Windows::Forms::ToolStripLabel^ bindingNavigatorCountItem;
    private: System::Windows::Forms::ToolStripButton^ bindingNavigatorDeleteItem;
    private: System::Windows::Forms::ToolStripButton^ bindingNavigatorMoveFirstItem;
    private: System::Windows::Forms::ToolStripButton^ bindingNavigatorMovePreviousItem;
    private: System::Windows::Forms::ToolStripSeparator^ bindingNavigatorSeparator;
    private: System::Windows::Forms::ToolStripTextBox^ bindingNavigatorPositionItem;
    private: System::Windows::Forms::ToolStripSeparator^ bindingNavigatorSeparator1;
    private: System::Windows::Forms::ToolStripButton^ bindingNavigatorMoveNextItem;
    private: System::Windows::Forms::ToolStripButton^ bindingNavigatorMoveLastItem;
    private: System::Windows::Forms::ToolStripSeparator^ bindingNavigatorSeparator2;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
           bool loginSuccessful;



        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(carLogin::typeid));
            this->usernameTextBox = (gcnew System::Windows::Forms::TextBox());
            this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
            this->loginButton = (gcnew System::Windows::Forms::Button());
            this->exitButton = (gcnew System::Windows::Forms::Button());
            this->signUpButton = (gcnew System::Windows::Forms::Button());
            this->bindingNavigator1 = (gcnew System::Windows::Forms::BindingNavigator(this->components));
            this->bindingNavigatorAddNewItem = (gcnew System::Windows::Forms::ToolStripButton());
            this->bindingNavigatorCountItem = (gcnew System::Windows::Forms::ToolStripLabel());
            this->bindingNavigatorDeleteItem = (gcnew System::Windows::Forms::ToolStripButton());
            this->bindingNavigatorMoveFirstItem = (gcnew System::Windows::Forms::ToolStripButton());
            this->bindingNavigatorMovePreviousItem = (gcnew System::Windows::Forms::ToolStripButton());
            this->bindingNavigatorSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
            this->bindingNavigatorPositionItem = (gcnew System::Windows::Forms::ToolStripTextBox());
            this->bindingNavigatorSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
            this->bindingNavigatorMoveNextItem = (gcnew System::Windows::Forms::ToolStripButton());
            this->bindingNavigatorMoveLastItem = (gcnew System::Windows::Forms::ToolStripButton());
            this->bindingNavigatorSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingNavigator1))->BeginInit();
            this->bindingNavigator1->SuspendLayout();
            this->SuspendLayout();
            // 
            // usernameTextBox
            // 
            this->usernameTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->usernameTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->usernameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->usernameTextBox->Location = System::Drawing::Point(170, 351);
            this->usernameTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->usernameTextBox->Name = L"usernameTextBox";
            this->usernameTextBox->Size = System::Drawing::Size(407, 46);
            this->usernameTextBox->TabIndex = 0;
            this->usernameTextBox->TextChanged += gcnew System::EventHandler(this, &carLogin::usernameTextBox_TextChanged);
            // 
            // passwordTextBox
            // 
            this->passwordTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->passwordTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->passwordTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->passwordTextBox->Location = System::Drawing::Point(170, 461);
            this->passwordTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->passwordTextBox->Name = L"passwordTextBox";
            this->passwordTextBox->PasswordChar = '*';
            this->passwordTextBox->Size = System::Drawing::Size(407, 46);
            this->passwordTextBox->TabIndex = 1;
            this->passwordTextBox->TextChanged += gcnew System::EventHandler(this, &carLogin::passwordTextBox_TextChanged);
            // 
            // loginButton
            // 
            this->loginButton->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->loginButton->FlatAppearance->BorderColor = System::Drawing::Color::WhiteSmoke;
            this->loginButton->FlatAppearance->BorderSize = 0;
            this->loginButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->loginButton->Font = (gcnew System::Drawing::Font(L"Tahoma", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->loginButton->ForeColor = System::Drawing::SystemColors::ControlText;
            this->loginButton->Location = System::Drawing::Point(170, 550);
            this->loginButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->loginButton->Name = L"loginButton";
            this->loginButton->Size = System::Drawing::Size(407, 72);
            this->loginButton->TabIndex = 2;
            this->loginButton->Text = L"Sign In";
            this->loginButton->UseVisualStyleBackColor = false;
            this->loginButton->Click += gcnew System::EventHandler(this, &carLogin::loginButton_Click);
            // 
            // exitButton
            // 
            this->exitButton->Location = System::Drawing::Point(690, 11);
            this->exitButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->exitButton->Name = L"exitButton";
            this->exitButton->Size = System::Drawing::Size(48, 50);
            this->exitButton->TabIndex = 4;
            this->exitButton->Text = L"X";
            this->exitButton->Click += gcnew System::EventHandler(this, &carLogin::exitButton_Click);
            // 
            // signUpButton
            // 
            this->signUpButton->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->signUpButton->FlatAppearance->BorderColor = System::Drawing::Color::White;
            this->signUpButton->FlatAppearance->BorderSize = 0;
            this->signUpButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->signUpButton->Font = (gcnew System::Drawing::Font(L"Tahoma", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->signUpButton->Location = System::Drawing::Point(170, 638);
            this->signUpButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->signUpButton->Name = L"signUpButton";
            this->signUpButton->Size = System::Drawing::Size(407, 75);
            this->signUpButton->TabIndex = 6;
            this->signUpButton->Text = L"Sign Up";
            this->signUpButton->UseVisualStyleBackColor = false;
            // 
            // bindingNavigator1
            // 
            this->bindingNavigator1->AddNewItem = this->bindingNavigatorAddNewItem;
            this->bindingNavigator1->CountItem = this->bindingNavigatorCountItem;
            this->bindingNavigator1->DeleteItem = this->bindingNavigatorDeleteItem;
            this->bindingNavigator1->ImageScalingSize = System::Drawing::Size(20, 20);
            this->bindingNavigator1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(11) {
                this->bindingNavigatorMoveFirstItem,
                    this->bindingNavigatorMovePreviousItem, this->bindingNavigatorSeparator, this->bindingNavigatorPositionItem, this->bindingNavigatorCountItem,
                    this->bindingNavigatorSeparator1, this->bindingNavigatorMoveNextItem, this->bindingNavigatorMoveLastItem, this->bindingNavigatorSeparator2,
                    this->bindingNavigatorAddNewItem, this->bindingNavigatorDeleteItem
            });
            this->bindingNavigator1->Location = System::Drawing::Point(0, 0);
            this->bindingNavigator1->MoveFirstItem = this->bindingNavigatorMoveFirstItem;
            this->bindingNavigator1->MoveLastItem = this->bindingNavigatorMoveLastItem;
            this->bindingNavigator1->MoveNextItem = this->bindingNavigatorMoveNextItem;
            this->bindingNavigator1->MovePreviousItem = this->bindingNavigatorMovePreviousItem;
            this->bindingNavigator1->Name = L"bindingNavigator1";
            this->bindingNavigator1->PositionItem = this->bindingNavigatorPositionItem;
            this->bindingNavigator1->Size = System::Drawing::Size(749, 27);
            this->bindingNavigator1->TabIndex = 7;
            this->bindingNavigator1->Text = L"bindingNavigator1";
            this->bindingNavigator1->RefreshItems += gcnew System::EventHandler(this, &carLogin::bindingNavigator1_RefreshItems);
            // 
            // bindingNavigatorAddNewItem
            // 
            this->bindingNavigatorAddNewItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
            this->bindingNavigatorAddNewItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bindingNavigatorAddNewItem.Image")));
            this->bindingNavigatorAddNewItem->Name = L"bindingNavigatorAddNewItem";
            this->bindingNavigatorAddNewItem->RightToLeftAutoMirrorImage = true;
            this->bindingNavigatorAddNewItem->Size = System::Drawing::Size(24, 24);
            this->bindingNavigatorAddNewItem->Text = L"Add new";
            // 
            // bindingNavigatorCountItem
            // 
            this->bindingNavigatorCountItem->Name = L"bindingNavigatorCountItem";
            this->bindingNavigatorCountItem->Size = System::Drawing::Size(35, 24);
            this->bindingNavigatorCountItem->Text = L"of {0}";
            this->bindingNavigatorCountItem->ToolTipText = L"Total number of items";
            // 
            // bindingNavigatorDeleteItem
            // 
            this->bindingNavigatorDeleteItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
            this->bindingNavigatorDeleteItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bindingNavigatorDeleteItem.Image")));
            this->bindingNavigatorDeleteItem->Name = L"bindingNavigatorDeleteItem";
            this->bindingNavigatorDeleteItem->RightToLeftAutoMirrorImage = true;
            this->bindingNavigatorDeleteItem->Size = System::Drawing::Size(24, 24);
            this->bindingNavigatorDeleteItem->Text = L"Delete";
            // 
            // bindingNavigatorMoveFirstItem
            // 
            this->bindingNavigatorMoveFirstItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
            this->bindingNavigatorMoveFirstItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bindingNavigatorMoveFirstItem.Image")));
            this->bindingNavigatorMoveFirstItem->Name = L"bindingNavigatorMoveFirstItem";
            this->bindingNavigatorMoveFirstItem->RightToLeftAutoMirrorImage = true;
            this->bindingNavigatorMoveFirstItem->Size = System::Drawing::Size(24, 24);
            this->bindingNavigatorMoveFirstItem->Text = L"Move first";
            // 
            // bindingNavigatorMovePreviousItem
            // 
            this->bindingNavigatorMovePreviousItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
            this->bindingNavigatorMovePreviousItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bindingNavigatorMovePreviousItem.Image")));
            this->bindingNavigatorMovePreviousItem->Name = L"bindingNavigatorMovePreviousItem";
            this->bindingNavigatorMovePreviousItem->RightToLeftAutoMirrorImage = true;
            this->bindingNavigatorMovePreviousItem->Size = System::Drawing::Size(24, 24);
            this->bindingNavigatorMovePreviousItem->Text = L"Move previous";
            // 
            // bindingNavigatorSeparator
            // 
            this->bindingNavigatorSeparator->Name = L"bindingNavigatorSeparator";
            this->bindingNavigatorSeparator->Size = System::Drawing::Size(6, 27);
            // 
            // bindingNavigatorPositionItem
            // 
            this->bindingNavigatorPositionItem->AccessibleName = L"Position";
            this->bindingNavigatorPositionItem->AutoSize = false;
            this->bindingNavigatorPositionItem->Name = L"bindingNavigatorPositionItem";
            this->bindingNavigatorPositionItem->Size = System::Drawing::Size(38, 23);
            this->bindingNavigatorPositionItem->Text = L"0";
            this->bindingNavigatorPositionItem->ToolTipText = L"Current position";
            // 
            // bindingNavigatorSeparator1
            // 
            this->bindingNavigatorSeparator1->Name = L"bindingNavigatorSeparator1";
            this->bindingNavigatorSeparator1->Size = System::Drawing::Size(6, 27);
            // 
            // bindingNavigatorMoveNextItem
            // 
            this->bindingNavigatorMoveNextItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
            this->bindingNavigatorMoveNextItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bindingNavigatorMoveNextItem.Image")));
            this->bindingNavigatorMoveNextItem->Name = L"bindingNavigatorMoveNextItem";
            this->bindingNavigatorMoveNextItem->RightToLeftAutoMirrorImage = true;
            this->bindingNavigatorMoveNextItem->Size = System::Drawing::Size(24, 24);
            this->bindingNavigatorMoveNextItem->Text = L"Move next";
            // 
            // bindingNavigatorMoveLastItem
            // 
            this->bindingNavigatorMoveLastItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
            this->bindingNavigatorMoveLastItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bindingNavigatorMoveLastItem.Image")));
            this->bindingNavigatorMoveLastItem->Name = L"bindingNavigatorMoveLastItem";
            this->bindingNavigatorMoveLastItem->RightToLeftAutoMirrorImage = true;
            this->bindingNavigatorMoveLastItem->Size = System::Drawing::Size(24, 24);
            this->bindingNavigatorMoveLastItem->Text = L"Move last";
            // 
            // bindingNavigatorSeparator2
            // 
            this->bindingNavigatorSeparator2->Name = L"bindingNavigatorSeparator2";
            this->bindingNavigatorSeparator2->Size = System::Drawing::Size(6, 27);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Rockwell Condensed", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(316, 308);
            this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(100, 29);
            this->label1->TabIndex = 4;
            this->label1->Text = L"USERNAME";
            this->label1->Click += gcnew System::EventHandler(this, &carLogin::label1_Click);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Rockwell Condensed", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(317, 417);
            this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(99, 29);
            this->label2->TabIndex = 5;
            this->label2->Text = L"PASSWORD";
            this->label2->Click += gcnew System::EventHandler(this, &carLogin::label2_Click);
            // 
            // carLogin
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->ClientSize = System::Drawing::Size(749, 750);
            this->Controls->Add(this->bindingNavigator1);
            this->Controls->Add(this->signUpButton);
            this->Controls->Add(this->exitButton);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->usernameTextBox);
            this->Controls->Add(this->passwordTextBox);
            this->Controls->Add(this->loginButton);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->Name = L"carLogin";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Login Form";
            this->Load += gcnew System::EventHandler(this, &carLogin::carLogin_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingNavigator1))->EndInit();
            this->bindingNavigator1->ResumeLayout(false);
            this->bindingNavigator1->PerformLayout();
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

        //FIXED!!
        /*System::Void signUpButton_Click(System::Object^ sender, System::EventArgs^ e)
        {
            carSignUp^ signUpWin = gcnew carSignUp();
            signUpWin->Show();
        }*/


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


        public: User^ user = nullptr;

        public: bool SwitchToMain = false;
        System::Void loginButton_Click(System::Object^ sender, System::EventArgs^ e)
        {
            String^ username = usernameTextBox->Text;
            String^ password = passwordTextBox->Text;
            bool authenticated = CheckUserCredentials(username, password);

            if (authenticated)
            {
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
