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




















	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code



		   void LoadData(const std::string& filename)
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

			   sellerData = gcnew array<String^, 2>(data.size(), numColumns);
			   for (int i = 0; i < data.size(); i++) {
				   for (int j = 0; j < numColumns; j++) {
					   sellerData[i, j] = gcnew String(data[i][j].c_str());
				   }
			   }

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
			   for (int i = 0; i < dataGridView1->ColumnCount; i++) {
				   dataGridView1->Columns[i]->Visible = false;
			   }
			   dataGridView1->Columns[0]->Visible = true; //Transaction ID
			   dataGridView1->Columns[1]->Visible = true; // Model
			   dataGridView1->Columns[2]->Visible = true; // Brand
			   dataGridView1->Columns[3]->Visible = true; // Transmission
			   dataGridView1->Columns[4]->Visible = true; // Cost
			   dataGridView1->Columns[5]->Visible = true; // Seats
			   dataGridView1->Columns[6]->Visible = true; // Platenum
			   dataGridView1->Columns[11]->Visible = true; // Approval
		   }


		array<String^, 2>^ sellerData;


		  array<String^, 2>^ selectUser(array<String^, 2>^ data, String^ targetUsername) {
			  if (data->Length == 0 || data->GetLength(0) == 0 || data->GetLength(1) == 0) {
				  MessageBox::Show(L"No data to extract.");
				  return nullptr;
			  }

			  int rowCount = data->GetLength(0);
			  int colCount = data->GetLength(1);

			 
			  int validRowCount = 0;
			  for (int rowIdx = 1; rowIdx < rowCount; ++rowIdx) { 
				  if (String::Equals(data[rowIdx, 10], targetUsername)) { 
					  validRowCount++;
				  }
			  }

			  array<String^, 2>^ extractedData = gcnew array<String^, 2>(validRowCount + 1, colCount);

			  for (int colIdx = 0; colIdx < colCount; ++colIdx) {
				  extractedData[0, colIdx] = data[0, colIdx];
			  }

			  int extractedRowIdx = 1;
			  for (int rowIdx = 1; rowIdx < rowCount; ++rowIdx) { 
				  if (String::Equals(data[rowIdx, 10], targetUsername)) { 
					  for (int colIdx = 0; colIdx < colCount; ++colIdx) {
						  extractedData[extractedRowIdx, colIdx] = data[rowIdx, colIdx];
					  }
					  extractedRowIdx++;
				  }
			  }

			  return extractedData;
		  }

		  void DeleteRowFromCSV(const std::string& filename, DataGridView^ dataGridView)
		  {
			  // Check if a row is selected in the DataGridView.
			  if (dataGridView->SelectedRows->Count == 0) {
				  MessageBox::Show(L"Please select a row to delete.");
				  return;
			  }

			  int selectedRowIndex = dataGridView->SelectedRows[0]->Index;
			  String^ platenum = dataGridView->Rows[selectedRowIndex]->Cells[6]->Value->ToString();

			  std::ifstream inputFile(filename);
			  std::ofstream tempFile("temp.csv");

			  if (!inputFile.is_open() || !tempFile.is_open()) {
				  MessageBox::Show(L"Error. Unable to open files for deletion.");
				  return;
			  }

			  std::string line;

			  while (std::getline(inputFile, line)) {
				  std::vector<std::string> row;
				  std::istringstream iss(line);
				  std::string cell;

				  while (std::getline(iss, cell, ',')) {
					  row.push_back(cell);
				  }

				  // Check if the value from the "platenum" column (assuming it's in a specific column, e.g., column 6) matches the selected "platenum" value.
				  if (row.size() >= 6 && String::Equals(gcnew String(row[6].c_str()), platenum)) {
					  continue;  // Skip this row (don't write it to the temporary file).
				  }

				  tempFile << line << "\n"; // Write the line to the temporary file.
			  }

			  inputFile.close();
			  tempFile.close();

			  // Replace the original file with the temporary file.
			  std::remove(filename.c_str()); // Delete the original file.
			  std::rename("temp.csv", filename.c_str()); // Rename the temporary file to the original file.

			  MessageBox::Show(L"Row deleted successfully.");
		  }
	

		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(sellList::typeid));
			this->removeButton = (gcnew System::Windows::Forms::Button());
			this->backButton = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
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
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
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
			this->dataGridView1->Location = System::Drawing::Point(11, 244);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->RowHeadersWidth = 5;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(720, 428);
			this->dataGridView1->StandardTab = true;
			this->dataGridView1->TabIndex = 26;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &sellList::dataGridView1_CellContentClick_1);
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


		LoadData("Transaction.csv");
		PopulateDataGridView(dataGridView1, selectUser(sellerData, SLcurrentUser));
	}
public: bool switchBackTosellWindow = false;

private: System::Void backButton_Click(System::Object ^ sender, System::EventArgs ^ e) {
	String^ currentUser = SLcurrentUser;
	switchBackTosellWindow = true;

	this->Close();
}
private: System::Void removeButton_Click(System::Object^ sender, System::EventArgs^ e) {
DeleteRowFromCSV("Transaction.csv", dataGridView1);
LoadData("Transaction.csv");
PopulateDataGridView(dataGridView1, selectUser(sellerData, SLcurrentUser));

	}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void dataGridView1_CellContentClick_1(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
};
}
