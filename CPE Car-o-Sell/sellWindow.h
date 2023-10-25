#pragma once
#include "user.h"

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
		sellWindow(User^ user)
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
	private: System::Windows::Forms::TextBox^ brandTextBox;
	protected:
	private: System::Windows::Forms::TextBox^ modelTextBox;
	private: System::Windows::Forms::TextBox^ numberOfSeatsTextBox;
	private: System::Windows::Forms::TextBox^ plateNumberTextBox;
	private: System::Windows::Forms::TextBox^ transmissionTextBox;
	private: System::Windows::Forms::TextBox^ costTextBox;
	private: System::Windows::Forms::Button^ cancelButton;

	private: System::Windows::Forms::Button^ proceedButton;
	private: System::Windows::Forms::Button^ viewMyListButton;





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
			this->brandTextBox = (gcnew System::Windows::Forms::TextBox());
			this->modelTextBox = (gcnew System::Windows::Forms::TextBox());
			this->numberOfSeatsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->plateNumberTextBox = (gcnew System::Windows::Forms::TextBox());
			this->transmissionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->costTextBox = (gcnew System::Windows::Forms::TextBox());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->proceedButton = (gcnew System::Windows::Forms::Button());
			this->viewMyListButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// brandTextBox
			// 
			this->brandTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->brandTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->brandTextBox->Location = System::Drawing::Point(225, 233);
			this->brandTextBox->Name = L"brandTextBox";
			this->brandTextBox->Size = System::Drawing::Size(288, 28);
			this->brandTextBox->TabIndex = 0;
			this->brandTextBox->TextChanged += gcnew System::EventHandler(this, &sellWindow::brandTextBox_TextChanged);
			// 
			// modelTextBox
			// 
			this->modelTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->modelTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->modelTextBox->Location = System::Drawing::Point(225, 303);
			this->modelTextBox->Name = L"modelTextBox";
			this->modelTextBox->Size = System::Drawing::Size(288, 28);
			this->modelTextBox->TabIndex = 1;
			// 
			// numberOfSeatsTextBox
			// 
			this->numberOfSeatsTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->numberOfSeatsTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->numberOfSeatsTextBox->Location = System::Drawing::Point(225, 374);
			this->numberOfSeatsTextBox->Name = L"numberOfSeatsTextBox";
			this->numberOfSeatsTextBox->Size = System::Drawing::Size(288, 28);
			this->numberOfSeatsTextBox->TabIndex = 2;
			this->numberOfSeatsTextBox->TextChanged += gcnew System::EventHandler(this, &sellWindow::numberOfSeatsTextBox_TextChanged);
			// 
			// plateNumberTextBox
			// 
			this->plateNumberTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->plateNumberTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->plateNumberTextBox->Location = System::Drawing::Point(225, 445);
			this->plateNumberTextBox->Name = L"plateNumberTextBox";
			this->plateNumberTextBox->Size = System::Drawing::Size(288, 28);
			this->plateNumberTextBox->TabIndex = 3;
			// 
			// transmissionTextBox
			// 
			this->transmissionTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->transmissionTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->transmissionTextBox->Location = System::Drawing::Point(225, 517);
			this->transmissionTextBox->Name = L"transmissionTextBox";
			this->transmissionTextBox->Size = System::Drawing::Size(288, 28);
			this->transmissionTextBox->TabIndex = 4;
			// 
			// costTextBox
			// 
			this->costTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->costTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->costTextBox->Location = System::Drawing::Point(225, 588);
			this->costTextBox->Name = L"costTextBox";
			this->costTextBox->Size = System::Drawing::Size(288, 28);
			this->costTextBox->TabIndex = 5;
			// 
			// cancelButton
			// 
			this->cancelButton->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->cancelButton->FlatAppearance->BorderSize = 0;
			this->cancelButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cancelButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cancelButton->Location = System::Drawing::Point(169, 636);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(144, 36);
			this->cancelButton->TabIndex = 6;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = false;
			this->cancelButton->Click += gcnew System::EventHandler(this, &sellWindow::cancelButton_Click);
			// 
			// proceedButton
			// 
			this->proceedButton->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->proceedButton->FlatAppearance->BorderSize = 0;
			this->proceedButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->proceedButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->proceedButton->Location = System::Drawing::Point(421, 636);
			this->proceedButton->Name = L"proceedButton";
			this->proceedButton->Size = System::Drawing::Size(148, 36);
			this->proceedButton->TabIndex = 7;
			this->proceedButton->Text = L"Proceed";
			this->proceedButton->UseVisualStyleBackColor = false;
			this->proceedButton->Click += gcnew System::EventHandler(this, &sellWindow::proceedButton_Click);
			// 
			// viewMyListButton
			// 
			this->viewMyListButton->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->viewMyListButton->FlatAppearance->BorderSize = 0;
			this->viewMyListButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->viewMyListButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->viewMyListButton->Location = System::Drawing::Point(236, 688);
			this->viewMyListButton->Name = L"viewMyListButton";
			this->viewMyListButton->Size = System::Drawing::Size(256, 35);
			this->viewMyListButton->TabIndex = 8;
			this->viewMyListButton->Text = L"View my List";
			this->viewMyListButton->UseVisualStyleBackColor = false;
			this->viewMyListButton->Click += gcnew System::EventHandler(this, &sellWindow::viewMyListButton_Click);
			// 
			// sellWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(734, 761);
			this->Controls->Add(this->viewMyListButton);
			this->Controls->Add(this->proceedButton);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->costTextBox);
			this->Controls->Add(this->transmissionTextBox);
			this->Controls->Add(this->plateNumberTextBox);
			this->Controls->Add(this->numberOfSeatsTextBox);
			this->Controls->Add(this->modelTextBox);
			this->Controls->Add(this->brandTextBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"sellWindow";
			this->Text = L"sellWindow";
			this->Load += gcnew System::EventHandler(this, &sellWindow::sellWindow_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int GenerateUniqueTransactionID() {
			// Get the current timestamp
			System::DateTime now = System::DateTime::Now;

			// Format the timestamp as a unique ID (e.g., YYYYMMDDHHMMSS)
			System::String^ uniqueID = String::Format("{0:D4}{1:D2}{2:D2}{3:D2}{4:D2}{5:D2}",
				now.Year, now.Month, now.Day, now.Hour, now.Minute, now.Second);

			// Parse the unique ID to an integer (assuming it's unique within a second)
			int transactionID;
			if (System::Int32::TryParse(uniqueID, transactionID)) {
				return transactionID;
			}

			// If parsing fails (unlikely but possible if multiple transactions occur within a second),
			// you can handle the error or implement a more sophisticated ID generation method.
			// This is a simplified example.

			// Handle the error or generate a different ID as needed
			throw gcnew System::Exception("Unable to generate a unique transaction ID.");
		}
	private: System::Void sellWindow_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void brandTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void numberOfSeatsTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

public: bool switchBackToUserMain = false;
private: System::Void cancelButton_Click(System::Object ^ sender, System::EventArgs ^ e) {
	switchBackToUserMain = true;
	this->Close();
}
public: bool switchToSellList = false;
private: System::Void viewMyListButton_Click(System::Object^ sender, System::EventArgs^ e) {
	System::String^ currentUser = ScurrentUser;
	switchToSellList = true;
	this->Close();
}
public: String^ ScurrentUser;
private: System::Void proceedButton_Click(System::Object^ sender, System::EventArgs^ e) {
	System::String^ currentUser = ScurrentUser;
	MessageBox::Show(currentUser, "Message Box Title", MessageBoxButtons::OK, MessageBoxIcon::Information);
	System::String^ brand = brandTextBox->Text;
	System::String^ model = modelTextBox->Text;
	System::String^ seats = numberOfSeatsTextBox->Text;
	System::String^ plateNumber = plateNumberTextBox->Text;
	System::String^ transmission = transmissionTextBox->Text;
	System::String^ cost = costTextBox->Text;

	System::String^ transactionData = String::Format("\n{0},{1},{2},{3},{4},{5},{6},{7},{8},{9},{10},{11}",
		"", model, brand, transmission, cost, seats, plateNumber, " ", " ", " ", currentUser, "FALSE");

	System::IO::File::AppendAllText("Transaction.csv", transactionData);

	brandTextBox->Clear();
	modelTextBox->Clear();
	numberOfSeatsTextBox->Clear();
	plateNumberTextBox->Clear();
	transmissionTextBox->Clear();
	costTextBox->Clear();


	MessageBox::Show("Car is up for review.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
};
}