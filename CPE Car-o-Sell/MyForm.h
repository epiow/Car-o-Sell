#pragma once

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
        System::Windows::Forms::Button^ loginButton;

        void InitializeComponent(void)
        {
            this->usernameTextBox = (gcnew System::Windows::Forms::TextBox());
            this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
            this->loginButton = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // usernameTextBox
            // 
            this->usernameTextBox->Location = System::Drawing::Point(187, 139);
            this->usernameTextBox->Name = L"usernameTextBox";
            this->usernameTextBox->Size = System::Drawing::Size(293, 22);
            this->usernameTextBox->TabIndex = 0;
            // 
            // passwordTextBox
            // 
            this->passwordTextBox->Location = System::Drawing::Point(187, 265);
            this->passwordTextBox->Name = L"passwordTextBox";
            this->passwordTextBox->PasswordChar = '*';
            this->passwordTextBox->Size = System::Drawing::Size(293, 22);
            this->passwordTextBox->TabIndex = 1;
            // 
            // loginButton
            // 
            this->loginButton->Location = System::Drawing::Point(259, 368);
            this->loginButton->Name = L"loginButton";
            this->loginButton->Size = System::Drawing::Size(155, 61);
            this->loginButton->TabIndex = 2;
            this->loginButton->Text = L"Login";
            this->loginButton->Click += gcnew System::EventHandler(this, &MyForm::loginButton_Click);
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(667, 541);
            this->Controls->Add(this->usernameTextBox);
            this->Controls->Add(this->passwordTextBox);
            this->Controls->Add(this->loginButton);
            this->Name = L"MyForm";
            this->Text = L"Login Form";
            this->ResumeLayout(false);
            this->PerformLayout();

        }

        // Event handler for the Login button click event
        System::Void loginButton_Click(System::Object^ sender, System::EventArgs^ e)
        {
            String^ username = usernameTextBox->Text;
            String^ password = passwordTextBox->Text;

            // Perform basic authentication (replace with your logic)
            if (username == L"admin" && password == L"password")
            {
                MessageBox::Show(L"Login successful!");
            }
            else
            {
                MessageBox::Show(L"Login failed. Please try again.");
            }
        }
    };
}
