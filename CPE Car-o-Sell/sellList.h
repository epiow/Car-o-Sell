#pragma once
#include <Windows.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "user.h"
#include "sellWindow.h"

namespace CPECaroSell {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for sellList
	/// </summary>
	public ref class sellList : public System::Windows::Forms::Form
	{
	public:
		String^ SLcurrentUser;
		sellList(User^ User) {
			InitializeComponent();
			LoadData("Transaction.csv");
			PopulateDataGridView(dataGridView1, dataApproval(sellListData));
		}
	
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~sellList()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ removeButton;
	protected:
	private: System::Windows::Forms::Button^ backButton;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ TransmissionIDColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ModelColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ BrandColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ TransmissionColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CostColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SeatColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PlateNoColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ RentalDateColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ RentalReturnColumn;
	array<String^, 2>^ sellListData;









	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(sellList::typeid));
			this->removeButton = (gcnew System::Windows::Forms::Button());
			this->backButton = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->TransmissionIDColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ModelColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->BrandColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TransmissionColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CostColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SeatColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PlateNoColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->RentalDateColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->RentalReturnColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// removeButton
			// 
			this->removeButton->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->removeButton->FlatAppearance->BorderSize = 0;
			this->removeButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->removeButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->removeButton->Location = System::Drawing::Point(33, 689);
			this->removeButton->Name = L"removeButton";
			this->removeButton->Size = System::Drawing::Size(144, 34);
			this->removeButton->TabIndex = 0;
			this->removeButton->Text = L"Remove";
			this->removeButton->UseVisualStyleBackColor = false;
			this->removeButton->Click += gcnew System::EventHandler(this, &sellList::removeButton_Click);
			// 
			// backButton
			// 
			this->backButton->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->backButton->FlatAppearance->BorderSize = 0;
			this->backButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->backButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->backButton->Location = System::Drawing::Point(565, 689);
			this->backButton->Name = L"backButton";
			this->backButton->Size = System::Drawing::Size(144, 34);
			this->backButton->TabIndex = 1;
			this->backButton->Text = L"Back";
			this->backButton->UseVisualStyleBackColor = false;
			this->backButton->Click += gcnew System::EventHandler(this, &sellList::backButton_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
				this->TransmissionIDColumn,
					this->ModelColumn, this->BrandColumn, this->TransmissionColumn, this->CostColumn, this->SeatColumn, this->PlateNoColumn, this->RentalDateColumn,
					this->RentalReturnColumn
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 247);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(718, 217);
			this->dataGridView1->TabIndex = 2;
			// 
			// TransmissionIDColumn
			// 
			this->TransmissionIDColumn->HeaderText = L"Transmission ID";
			this->TransmissionIDColumn->Name = L"TransmissionIDColumn";
			// 
			// ModelColumn
			// 
			this->ModelColumn->HeaderText = L"Model";
			this->ModelColumn->Name = L"ModelColumn";
			// 
			// BrandColumn
			// 
			this->BrandColumn->HeaderText = L"Brand ";
			this->BrandColumn->Name = L"BrandColumn";
			// 
			// TransmissionColumn
			// 
			this->TransmissionColumn->HeaderText = L"Transmission";
			this->TransmissionColumn->Name = L"TransmissionColumn";
			// 
			// CostColumn
			// 
			this->CostColumn->HeaderText = L"Cost";
			this->CostColumn->Name = L"CostColumn";
			// 
			// SeatColumn
			// 
			this->SeatColumn->HeaderText = L"Seat";
			this->SeatColumn->Name = L"SeatColumn";
			// 
			// PlateNoColumn
			// 
			this->PlateNoColumn->HeaderText = L"Plate #";
			this->PlateNoColumn->Name = L"PlateNoColumn";
			// 
			// RentalDateColumn
			// 
			this->RentalDateColumn->HeaderText = L"Rental Date";
			this->RentalDateColumn->Name = L"RentalDateColumn";
			// 
			// RentalReturnColumn
			// 
			this->RentalReturnColumn->HeaderText = L"Rental Return";
			this->RentalReturnColumn->Name = L"RentalReturnColumn";
			// 
			// sellList
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(742, 735);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->backButton);
			this->Controls->Add(this->removeButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"sellList";
			this->Text = L"sellList";
			this->Load += gcnew System::EventHandler(this, &sellList::sellList_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			
		}
#pragma endregion



		void sellList::LoadData(const std::string& filename)
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

			sellListData = gcnew array<String^, 2>(data.size(), numColumns);
			for (int i = 0; i < data.size(); i++) {
				for (int j = 0; j < numColumns; j++) {
					sellListData[i, j] = gcnew String(data[i][j].c_str());
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

			//  number of rows equal to SLcurrentUser
			int validRowCount = 0;
			for (int rowIdx = 0; rowIdx < rowCount; ++rowIdx) {
				if (String::Equals(data[rowIdx, colCount - 1], SLcurrentUser)) {
					validRowCount++;
				}
			}

			// new array
			array<String^, 2>^ extractedData = gcnew array<String^, 2>(validRowCount + 1, colCount); // +1 to include the header

			// Copy the header row
			for (int colIdx = 0; colIdx < colCount; ++colIdx) {
				extractedData[0, colIdx] = data[0, colIdx];
			}

			// Copy data with SLcurrentUser
			int extractedRowIdx = 1;
			for (int rowIdx = 1; rowIdx < rowCount; ++rowIdx) {
				if (String::Equals(data[rowIdx, colCount - 1], SLcurrentUser)) {
					for (int colIdx = 0; colIdx < colCount; ++colIdx) {
						extractedData[extractedRowIdx, colIdx] = data[rowIdx, colIdx];
					}
					extractedRowIdx++;
				}
			}

			return extractedData;
		}

		void sellList::PopulateDataGridView(DataGridView^ dataGridView, array<String^, 2>^ data) {
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

private: System::Void sellList_Load(System::Object^ sender, System::EventArgs^ e) {
}
public: bool switchBackTosellWindow = false;

private: System::Void backButton_Click(System::Object ^ sender, System::EventArgs ^ e) {
	String^ currentUser = SLcurrentUser;
	switchBackTosellWindow = true;

	this->Close();
}
private: System::Void removeButton_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ output = ""; // Initialize a string to store the column values

	for (int i = 0; i < dataGridView1->RowCount; i++) {
		DataGridViewRow^ row = dataGridView1->Rows[i];
		DataGridViewCell^ cell = row->Cells[2]; // Replace 'columnIndex' with the index of the column you want to retrieve

		if (cell != nullptr && cell->Value != nullptr) {
			output += cell->Value->ToString() + "\n"; // Append the cell value to the output string
		}
	}

	//// Display the output in a MessageBox or another control
	//MessageBox::Show(output);

	}
};
}
