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
		sellList(void)
		{
			InitializeComponent();
			PopulateDataGridView(SLcurrentUser);

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










	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void sellList::PopulateDataGridView(String^ currentUser)
		{
			std::ifstream file("Transaction.csv");
			std::vector<std::vector<std::string>> data;
			if (!file.is_open()) {
				MessageBox::Show(L"Error. Unable to open Transaction.csv file.");
				return;
			}

			std::string line;
			if (std::getline(file, line)) {
				std::stringstream ss(line);
				std::string columnName;

				while (std::getline(ss, columnName, ',')) {
					dataGridView1->Columns->Add(gcnew String(columnName.c_str()), gcnew String(columnName.c_str()));
				}
			}

			// Read the remaining data and filter rows by 'Seller'
			while (std::getline(file, line)) {
				std::vector<std::string> row;
				std::stringstream ss(line);
				std::string cell;

				while (std::getline(ss, cell, ',')) {
					row.push_back(cell);
				}

				// Assuming 'Seller' column is at index 10 (0-based index)
				if (row.size() > 10 && gcnew String(row[10].c_str()) == currentUser) {
					data.push_back(row);
				}
			}

			file.close();

			int rowCount = data.size();
			int columnCount = (rowCount > 0) ? data[0].size() : 0;

			// Ensure that the DataGridView has at least one row
			dataGridView1->RowCount = (rowCount > 0) ? rowCount : 1;
			dataGridView1->ColumnCount = columnCount;

			if (rowCount > 0) {
				for (int i = 0; i < rowCount; i++) {
					for (int j = 0; j < columnCount; j++) {
						dataGridView1->Rows[i]->Cells[j]->Value = gcnew String(data[i][j].c_str());
					}
				}
			}
			else {
				// Handle the case where there are no matching rows, e.g., display a message.
			}
		}

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
