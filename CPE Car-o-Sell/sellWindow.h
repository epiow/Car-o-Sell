#pragma once

namespace CPECaroSell {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for sellWindow
	/// </summary>
	public ref class sellWindow : public System::Windows::Forms::Form
	{
	public:
		sellWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~sellWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ exitButton;
	private: System::Windows::Forms::TextBox^ modelTextBox;
	protected:

	protected:


	private: System::Windows::Forms::TextBox^ brandTextBox;
	private: System::Windows::Forms::TextBox^ numberOfSeatsTextBox;
	private: System::Windows::Forms::TextBox^ TransmissionTextBox;
	private: System::Windows::Forms::TextBox^ costTextBox;
	private: System::Windows::Forms::Button^ proceedButton;











	private: System::Windows::Forms::Button^ cancelButton;






	private: System::Windows::Forms::TextBox^ PlateNoTextBox;



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(sellWindow::typeid));
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->modelTextBox = (gcnew System::Windows::Forms::TextBox());
			this->brandTextBox = (gcnew System::Windows::Forms::TextBox());
			this->numberOfSeatsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->TransmissionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->costTextBox = (gcnew System::Windows::Forms::TextBox());
			this->proceedButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->PlateNoTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// exitButton
			// 
			this->exitButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exitButton->Location = System::Drawing::Point(673, 12);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(49, 50);
			this->exitButton->TabIndex = 0;
			this->exitButton->Text = L"x";
			this->exitButton->UseVisualStyleBackColor = true;
			// 
			// modelTextBox
			// 
			this->modelTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->modelTextBox->Font = (gcnew System::Drawing::Font(L"SansSerif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->modelTextBox->Location = System::Drawing::Point(225, 304);
			this->modelTextBox->Name = L"modelTextBox";
			this->modelTextBox->Size = System::Drawing::Size(287, 28);
			this->modelTextBox->TabIndex = 6;
			// 
			// brandTextBox
			// 
			this->brandTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->brandTextBox->Font = (gcnew System::Drawing::Font(L"SansSerif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->brandTextBox->Location = System::Drawing::Point(225, 235);
			this->brandTextBox->Name = L"brandTextBox";
			this->brandTextBox->Size = System::Drawing::Size(287, 28);
			this->brandTextBox->TabIndex = 7;
			// 
			// numberOfSeatsTextBox
			// 
			this->numberOfSeatsTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->numberOfSeatsTextBox->Font = (gcnew System::Drawing::Font(L"SansSerif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->numberOfSeatsTextBox->Location = System::Drawing::Point(225, 375);
			this->numberOfSeatsTextBox->Name = L"numberOfSeatsTextBox";
			this->numberOfSeatsTextBox->Size = System::Drawing::Size(287, 28);
			this->numberOfSeatsTextBox->TabIndex = 8;
			// 
			// TransmissionTextBox
			// 
			this->TransmissionTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->TransmissionTextBox->Font = (gcnew System::Drawing::Font(L"SansSerif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->TransmissionTextBox->Location = System::Drawing::Point(225, 518);
			this->TransmissionTextBox->Name = L"TransmissionTextBox";
			this->TransmissionTextBox->Size = System::Drawing::Size(287, 28);
			this->TransmissionTextBox->TabIndex = 9;
			// 
			// costTextBox
			// 
			this->costTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->costTextBox->Font = (gcnew System::Drawing::Font(L"SansSerif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->costTextBox->Location = System::Drawing::Point(225, 588);
			this->costTextBox->Name = L"costTextBox";
			this->costTextBox->Size = System::Drawing::Size(287, 28);
			this->costTextBox->TabIndex = 10;
			this->costTextBox->TextChanged += gcnew System::EventHandler(this, &sellWindow::costTextBox_TextChanged);
			// 
			// proceedButton
			// 
			this->proceedButton->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->proceedButton->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->proceedButton->FlatAppearance->BorderSize = 0;
			this->proceedButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->proceedButton->Font = (gcnew System::Drawing::Font(L"Designer", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->proceedButton->Location = System::Drawing::Point(409, 658);
			this->proceedButton->Name = L"proceedButton";
			this->proceedButton->Size = System::Drawing::Size(160, 32);
			this->proceedButton->TabIndex = 11;
			this->proceedButton->Text = L"PROCEED";
			this->proceedButton->UseVisualStyleBackColor = false;
			// 
			// cancelButton
			// 
			this->cancelButton->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->cancelButton->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->cancelButton->FlatAppearance->BorderSize = 0;
			this->cancelButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cancelButton->Font = (gcnew System::Drawing::Font(L"Designer", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cancelButton->Location = System::Drawing::Point(166, 658);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(131, 32);
			this->cancelButton->TabIndex = 12;
			this->cancelButton->Text = L"CANCEL";
			this->cancelButton->UseVisualStyleBackColor = false;
			// 
			// PlateNoTextBox
			// 
			this->PlateNoTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->PlateNoTextBox->Font = (gcnew System::Drawing::Font(L"SansSerif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->PlateNoTextBox->Location = System::Drawing::Point(225, 444);
			this->PlateNoTextBox->Name = L"PlateNoTextBox";
			this->PlateNoTextBox->Size = System::Drawing::Size(287, 28);
			this->PlateNoTextBox->TabIndex = 13;
			this->PlateNoTextBox->TextChanged += gcnew System::EventHandler(this, &sellWindow::textBox6_TextChanged);
			// 
			// sellWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(734, 711);
			this->Controls->Add(this->PlateNoTextBox);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->proceedButton);
			this->Controls->Add(this->costTextBox);
			this->Controls->Add(this->TransmissionTextBox);
			this->Controls->Add(this->numberOfSeatsTextBox);
			this->Controls->Add(this->brandTextBox);
			this->Controls->Add(this->modelTextBox);
			this->Controls->Add(this->exitButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"sellWindow";
			this->Text = L"sellWindow";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void costTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
