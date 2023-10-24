#pragma once
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "calendar.h"
#include "user.h"

namespace CPECaroSell {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class rentWindow : public System::Windows::Forms::Form
	{
	public:
		rentWindow(User^ user)
		{
			InitializeComponent();
			LoadData("Transaction.csv");
			PopulateDataGridView(dataGridView1, dataApproval(rentData));

			// Hide all columns
			for (int i = 0; i < dataGridView1->ColumnCount; i++) {
				dataGridView1->Columns[i]->Visible = false;
			}

			// Show the specific columns you want (indices 1, 2, 3, 4, 5, 6, and 10)
			dataGridView1->Columns[1]->Visible = true; // Brand
			dataGridView1->Columns[2]->Visible = true; // Transmission
			dataGridView1->Columns[3]->Visible = true; // Cost
			dataGridView1->Columns[4]->Visible = true; // Seats
			dataGridView1->Columns[5]->Visible = true; // Plate #
			// You can add other columns as needed
			dataGridView1->Columns[10]->Visible = true; // Approval
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~rentWindow()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:






private: System::Windows::Forms::Button^ exitButton;


	array<String^, 2>^ rentData;
	private: System::Windows::Forms::TextBox^ model;
	private: System::Windows::Forms::TextBox^ brand;
	private: System::Windows::Forms::TextBox^ transmission;
	private: System::Windows::Forms::TextBox^ cost;
	private: System::Windows::Forms::TextBox^ seats;
	private: System::Windows::Forms::TextBox^ platenum;






	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;




	protected:

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
	
		void LoadSelectedCell()
		{
			// Assuming 'dataGridView1' is your DataGridView control

			// Get the selected row
			DataGridViewRow^ selectedRow = dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex];

			// Check the 'Approval' column value (assuming it's at index 10)
			System::String^ approvalValue = selectedRow->Cells[10]->Value->ToString();

			// Only load the selected cell if 'Approval' is "TRUE"
			if (approvalValue->Trim()->Equals("TRUE", System::StringComparison::InvariantCultureIgnoreCase))
			{
				model->Text = selectedRow->Cells[0]->Value->ToString();
				brand->Text = selectedRow->Cells[1]->Value->ToString();
				transmission->Text = selectedRow->Cells[2]->Value->ToString();
				cost->Text = selectedRow->Cells[3]->Value->ToString();
				seats->Text = selectedRow->Cells[4]->Value->ToString();
				platenum->Text = selectedRow->Cells[5]->Value->ToString();
			}
		}

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(rentWindow::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->model = (gcnew System::Windows::Forms::TextBox());
			this->brand = (gcnew System::Windows::Forms::TextBox());
			this->transmission = (gcnew System::Windows::Forms::TextBox());
			this->cost = (gcnew System::Windows::Forms::TextBox());
			this->seats = (gcnew System::Windows::Forms::TextBox());
			this->platenum = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// exitButton
			// 
			resources->ApplyResources(this->exitButton, L"exitButton");
			this->exitButton->Name = L"exitButton";
			this->exitButton->Click += gcnew System::EventHandler(this, &rentWindow::exitButton_Click);
			// 
			// model
			// 
			this->model->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->model->BorderStyle = System::Windows::Forms::BorderStyle::None;
			resources->ApplyResources(this->model, L"model");
			this->model->Name = L"model";
			this->model->ReadOnly = true;
			this->model->TextChanged += gcnew System::EventHandler(this, &rentWindow::textBox1_TextChanged);
			// 
			// brand
			// 
			this->brand->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->brand->BorderStyle = System::Windows::Forms::BorderStyle::None;
			resources->ApplyResources(this->brand, L"brand");
			this->brand->Name = L"brand";
			this->brand->ReadOnly = true;
			// 
			// transmission
			// 
			this->transmission->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->transmission->BorderStyle = System::Windows::Forms::BorderStyle::None;
			resources->ApplyResources(this->transmission, L"transmission");
			this->transmission->Name = L"transmission";
			this->transmission->ReadOnly = true;
			this->transmission->TextChanged += gcnew System::EventHandler(this, &rentWindow::textBox3_TextChanged);
			// 
			// cost
			// 
			this->cost->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->cost->BorderStyle = System::Windows::Forms::BorderStyle::None;
			resources->ApplyResources(this->cost, L"cost");
			this->cost->Name = L"cost";
			this->cost->ReadOnly = true;
			// 
			// seats
			// 
			this->seats->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->seats->BorderStyle = System::Windows::Forms::BorderStyle::None;
			resources->ApplyResources(this->seats, L"seats");
			this->seats->Name = L"seats";
			this->seats->ReadOnly = true;
			// 
			// platenum
			// 
			this->platenum->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->platenum->BorderStyle = System::Windows::Forms::BorderStyle::None;
			resources->ApplyResources(this->platenum, L"platenum");
			this->platenum->Name = L"platenum";
			this->platenum->ReadOnly = true;
			this->platenum->TextChanged += gcnew System::EventHandler(this, &rentWindow::textBox6_TextChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->button1->FlatAppearance->BorderSize = 0;
			resources->ApplyResources(this->button1, L"button1");
			this->button1->Name = L"button1";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &rentWindow::rentBtn_Click_1);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			resources->ApplyResources(this->dataGridView1, L"dataGridView1");
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ControlDarkDark;
			this->dataGridView1->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::EnableWithoutHeaderText;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Bebas Neue", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Bebas Neue", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::Window;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->StandardTab = true;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &rentWindow::dataGridView1_CellContentClick);
			// 
			// rentWindow
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->platenum);
			this->Controls->Add(this->seats);
			this->Controls->Add(this->cost);
			this->Controls->Add(this->transmission);
			this->Controls->Add(this->brand);
			this->Controls->Add(this->model);
			this->Controls->Add(this->exitButton);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"rentWindow";
			this->Load += gcnew System::EventHandler(this, &rentWindow::rentWindow_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		

		void rentWindow::LoadData(const std::string& filename)
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

			rentData = gcnew array<String^, 2>(data.size(), numColumns);
			for (int i = 0; i < data.size(); i++) {
				for (int j = 0; j < numColumns; j++) {
					rentData[i, j] = gcnew String(data[i][j].c_str());
				}
			}

		}
			array<String^, 2>^ dataApproval(array<String^, 2>^ data) {
			if (data->Length == 0 || data->GetLength(0) == 0 || data->GetLength(1) == 0) {
				MessageBox::Show(L"No data to extract.");
				return nullptr;
			}

			int rowCount = data->GetLength(0);
			int colCount = data->GetLength(1);

			//  number of rows with "TRUE"
			int validRowCount = 0;
			for (int rowIdx = 0; rowIdx < rowCount; ++rowIdx) {
				if (String::Equals(data[rowIdx, colCount - 1], "TRUE")) {
					validRowCount++;
				}
			}

			// new array
			array<String^, 2>^ extractedData = gcnew array<String^, 2>(validRowCount + 1, colCount); // +1 to include the header

			// Copy the header row
			for (int colIdx = 0; colIdx < colCount; ++colIdx) {
				extractedData[0, colIdx] = data[0, colIdx];
			}

			// Copy data with "TRUE"
			int extractedRowIdx = 1;
			for (int rowIdx = 1; rowIdx < rowCount; ++rowIdx) {
				if (String::Equals(data[rowIdx, colCount - 1], "TRUE")) {
					for (int colIdx = 0; colIdx < colCount; ++colIdx) {
						extractedData[extractedRowIdx, colIdx] = data[rowIdx, colIdx];
					}
					extractedRowIdx++;
				}
			}

			return extractedData;
		}

		void PopulateDataGridView(DataGridView^ dataGridView, array<String^, 2>^ data) {
			if (data->Length == 0 || data->GetLength(0) == 0 || data->GetLength(1) == 0) {
				MessageBox::Show(L"No data to display.");
				return;
			}

			// Clear data
			dataGridView->Rows->Clear();
			dataGridView->Columns->Clear();

			//  Column names
			for (int colIdx = 0; colIdx < data->GetLength(1); ++colIdx) {
				dataGridView->Columns->Add(gcnew DataGridViewTextBoxColumn());
				dataGridView->Columns[dataGridView->Columns->Count - 1]->HeaderText = data[0, colIdx];
			}

			// Populate the DataGridView 
			for (int rowIdx = 1; rowIdx < data->GetLength(0); ++rowIdx) {
				dataGridView->Rows->Add();
				for (int colIdx = 0; colIdx < data->GetLength(1); ++colIdx) {
					dataGridView->Rows[rowIdx - 1]->Cells[colIdx]->Value = data[rowIdx, colIdx];
				}
			}
		}

private: System::Void platenum1_Click(System::Object^ sender, System::EventArgs^ e) {
}


private: System::Void rentWindow_Load(System::Object^ sender, System::EventArgs^ e) {
	

}


public: bool switchBackToUserMain = false;
public: int carNum = 0;

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	switchBackToUserMain = true;
    this->Close();
}

private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) {
    if (MessageBox::Show(L"Do you want to exit the application?", L"Exit", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
    {
		switchBackToUserMain = true;
        this->Close();	
    }
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void platenum3_Click(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void car1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void model1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void brand1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	LoadSelectedCell();
}
private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

public: String^ RcurrentUser;
public: bool switchToCalendar;
private: System::Void rentBtn_Click_1(System::Object^ sender, System::EventArgs^ e) {
	switchToCalendar = 1;
	System::String^ currentUser = RcurrentUser;

	// Check if a row is selected in the DataGridView
	if (dataGridView1->SelectedRows->Count == 1) {
		// Get the selected row
		DataGridViewRow^ selectedRow = dataGridView1->SelectedRows[0];

		// Retrieve relevant data from the selected row
		System::String^ model = selectedRow->Cells[0]->Value->ToString();
		System::String^ brand = selectedRow->Cells[1]->Value->ToString();

		// Create an instance of the calendar form
		CPECaroSell::calendar^ calendarView = gcnew CPECaroSell::calendar;
		calendarView->ShowDialog();
		
	}
	else {
		// Inform the user that they need to select a row from the DataGridView.
		MessageBox::Show("Please select a car from the list to rent.", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}
};
}
//public: String^ ScurrentUser;
//private: System::Void proceedButton_Click(System::Object^ sender, System::EventArgs^ e) {
//
//	System::String^ currentUser = ScurrentUser;
//
//	System::String^ brand = brandTextBox->Text;
//	System::String^ model = modelTextBox->Text;
//	System::String^ seats = numberOfSeatsTextBox->Text;
//	System::String^ plateNumber = plateNumberTextBox->Text;
//	System::String^ transmission = transmissionTextBox->Text;
//	System::String^ cost = costTextBox->Text;
//
//	System::String^ transactionData = String::Format("\n{0},{1},{2},{3},{4},{5},{6},{7},{8},{9},{10},{11}",
//		"", model, brand, transmission, cost, seats, plateNumber, " ", " ", " ", currentUser, "FALSE");
//
//	System::IO::File::AppendAllText("Transaction.csv", transactionData);
//
//	brandTextBox->Clear();
//	modelTextBox->Clear();
//	numberOfSeatsTextBox->Clear();
//	plateNumberTextBox->Clear();
//	transmissionTextBox->Clear();
//	costTextBox->Clear();
//
//
//	MessageBox::Show("Car is up for review.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
//}