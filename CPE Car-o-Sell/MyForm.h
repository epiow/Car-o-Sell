#pragma once
#include <Windows.h>
#include <cstdlib>
#include "MyForm1.h"
namespace CPECaroSell {
    
    using namespace System;
    using namespace System::Windows::Forms;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
        }

    private:
        System::Windows::Forms::TextBox^ usernameTextBox;
        System::Windows::Forms::TextBox^ passwordTextBox;
        System::Windows::Forms::Button^ signUpButton;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::Button^ exitButton;
        System::Windows::Forms::Button^ loginButton;
        MyForm1^ myForm1;


      

        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            this->usernameTextBox = (gcnew System::Windows::Forms::TextBox());
            this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
            this->loginButton = (gcnew System::Windows::Forms::Button());
            this->signUpButton = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();

            System::Void signUpButton_Click(System::Object ^ sender, System::EventArgs ^ e);
            // exit
                        // Create the exitButton
            this->exitButton = (gcnew System::Windows::Forms::Button());
            this->exitButton->Location = System::Drawing::Point(750, 10); // Position at the top right corner
            this->exitButton->Name = L"exitButton";
            this->exitButton->Size = System::Drawing::Size(40, 40); // Set the size as needed
            this->exitButton->TabIndex = 4;
            this->exitButton->Text = L"X"; // Display an "X" to represent exit
            this->exitButton->Click += gcnew System::EventHandler(this, &MyForm::exitButton_Click);

            // Add the exitButton to the form's controls
            this->Controls->Add(this->exitButton);
            // usernameTextBox
            // 
            this->usernameTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->usernameTextBox->Location = System::Drawing::Point(29, 298);
            this->usernameTextBox->Name = L"usernameTextBox";
            this->usernameTextBox->Size = System::Drawing::Size(212, 22);
            this->usernameTextBox->TabIndex = 0;
            this->usernameTextBox->TextChanged += gcnew System::EventHandler(this, &MyForm::usernameTextBox_TextChanged);
            // 
            // passwordTextBox
            // 
            this->passwordTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->passwordTextBox->Location = System::Drawing::Point(29, 393);
            this->passwordTextBox->Name = L"passwordTextBox";
            this->passwordTextBox->PasswordChar = '*';
            this->passwordTextBox->Size = System::Drawing::Size(212, 22);
            this->passwordTextBox->TabIndex = 1;
            this->passwordTextBox->TextChanged += gcnew System::EventHandler(this, &MyForm::passwordTextBox_TextChanged);
            // 
            // loginButton
            // 
            this->loginButton->Location = System::Drawing::Point(29, 621);
            this->loginButton->Name = L"loginButton";
            this->loginButton->Size = System::Drawing::Size(115, 36);
            this->loginButton->TabIndex = 2;
            this->loginButton->Text = L"Login";
            this->loginButton->Click += gcnew System::EventHandler(this, &MyForm::loginButton_Click);
            // 
            // signUpButton
            // 
            this->signUpButton->Location = System::Drawing::Point(163, 621);
            this->signUpButton->Name = L"signUpButton";
            this->signUpButton->Size = System::Drawing::Size(115, 36);
            this->signUpButton->TabIndex = 3;
            this->signUpButton->Text = L"Sign up";
            this->signUpButton->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
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
            this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
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
            this->label2->Text = L"USERNAME";
            this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->ClientSize = System::Drawing::Size(800, 800);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->signUpButton);
            this->Controls->Add(this->usernameTextBox);
            this->Controls->Add(this->passwordTextBox);
            this->Controls->Add(this->loginButton);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Name = L"MyForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Login Form";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->ResumeLayout(false);
            this->PerformLayout();


            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->ResumeLayout(false);
            this->PerformLayout();
        }

        // Event handler for the Login button click event
        System::Void loginButton_Click(System::Object^ sender, System::EventArgs^ e)
        {
            String^ username = usernameTextBox->Text;
            String^ password = passwordTextBox->Text;

            // Perform basic authentication (replace with your logic)
            if (username == L"hello" && password == L"hello")
            {
                MessageBox::Show(L"Login successful!");
            }
            else
            {
                MessageBox::Show(L"Login failed. Please try again.");
            }
        }

        System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // Show a confirmation dialog
            if (MessageBox::Show(L"Do you want to exit the application?", L"Exit", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
            {
                // Close the application
                this->Close(); // Close the form
            }
        }
        System::Void MyForm::signUpButton_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // Create an instance of MyForm1 if it doesn't exist
            if (myForm1 == nullptr)
            {
                myForm1 = gcnew MyForm1();
            }

            // Show the MyForm1 form
            myForm1->Show();

            // Hide the current form (MyForm)
            this->Hide();
        }

    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
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
};
}
