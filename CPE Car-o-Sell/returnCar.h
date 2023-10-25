#pragma once
#include <Windows.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "user.h"
#include <msclr/marshal_cppstd.h>

namespace CPECaroSell {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for returnCar
	/// </summary>
	public ref class returnCar : public System::Windows::Forms::Form
	{
	public:
		returnCar(void)
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
		~returnCar()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::TextBox^ transactID;
	private: System::Windows::Forms::TextBox^ model;
	private: System::Windows::Forms::TextBox^ brand;

	private: System::Windows::Forms::TextBox^ cost;
	private: System::Windows::Forms::TextBox^ seats;
	private: System::Windows::Forms::TextBox^ platenum;
	private: System::Windows::Forms::TextBox^ rentaldate;
	private: System::Windows::Forms::TextBox^ returndate;
	private: System::Windows::Forms::TextBox^ renter;
	private: System::Windows::Forms::TextBox^ seller;
	private: System::Windows::Forms::Button^ Return;











	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ transmission;


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
		
	private: void ClearInputFields() {
		transactID->Text = "";
		model->Text = "";
		brand->Text = "";
		transmission->Text = "";
		cost->Text = "";
		seats->Text = "";
		platenum->Text = "";
		renter->Text = "";
		seller->Text = "";
	}
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

			   returnData = gcnew array<String^, 2>(data.size(), numColumns);
			   for (int i = 0; i < data.size(); i++) {
				   for (int j = 0; j < numColumns; j++) {
					   returnData[i, j] = gcnew String(data[i][j].c_str());
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
			   dataGridView1->Columns[0]->Visible = true; // Transaction ID
			   dataGridView1->Columns[1]->Visible = true; // Model
			   dataGridView1->Columns[2]->Visible = true; // Brand
			   dataGridView1->Columns[3]->Visible = true; // Transmission
			   dataGridView1->Columns[4]->Visible = true; // Cost
			   dataGridView1->Columns[5]->Visible = true; // Seats
			   dataGridView1->Columns[6]->Visible = true; // Platenum
			   dataGridView1->Columns[7]->Visible = true; // Rental Date
			   dataGridView1->Columns[8]->Visible = true; // Return Date

		   }
		   //way to get selected cell from dataGrid
		   void LoadSelectedCell()
		   {
			   transactID->Text = dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[0]->Value->ToString();
			   model->Text = dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[1]->Value->ToString();
			   brand->Text = dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[2]->Value->ToString();
			   transmission->Text = dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[3]->Value->ToString();
			   cost->Text = dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[4]->Value->ToString();
			   seats->Text = dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[5]->Value->ToString();
			   platenum->Text = dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[6]->Value->ToString();
			   renter->Text = dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[7]->Value->ToString();
			   seller->Text = dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[8]->Value->ToString();
		   }


		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(returnCar::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->transactID = (gcnew System::Windows::Forms::TextBox());
			this->model = (gcnew System::Windows::Forms::TextBox());
			this->brand = (gcnew System::Windows::Forms::TextBox());
			this->cost = (gcnew System::Windows::Forms::TextBox());
			this->seats = (gcnew System::Windows::Forms::TextBox());
			this->platenum = (gcnew System::Windows::Forms::TextBox());
			this->rentaldate = (gcnew System::Windows::Forms::TextBox());
			this->returndate = (gcnew System::Windows::Forms::TextBox());
			this->renter = (gcnew System::Windows::Forms::TextBox());
			this->seller = (gcnew System::Windows::Forms::TextBox());
			this->Return = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->transmission = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
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
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Rockwell Condensed", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
			this->dataGridView1->Location = System::Drawing::Point(318, 115);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->RowHeadersWidth = 5;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(846, 636);
			this->dataGridView1->StandardTab = true;
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &returnCar::dataGridView1_CellContentClick);
			// 
			// transactID
			// 
			this->transactID->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->transactID->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->transactID->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->transactID->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 5.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->transactID->ForeColor = System::Drawing::SystemColors::WindowText;
			this->transactID->Location = System::Drawing::Point(175, 166);
			this->transactID->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->transactID->Name = L"transactID";
			this->transactID->ReadOnly = true;
			this->transactID->Size = System::Drawing::Size(100, 20);
			this->transactID->TabIndex = 23;
			// 
			// model
			// 
			this->model->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->model->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->model->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->model->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 5.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->model->ForeColor = System::Drawing::SystemColors::WindowText;
			this->model->Location = System::Drawing::Point(175, 207);
			this->model->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->model->Name = L"model";
			this->model->ReadOnly = true;
			this->model->Size = System::Drawing::Size(100, 20);
			this->model->TabIndex = 24;
			// 
			// brand
			// 
			this->brand->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->brand->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->brand->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->brand->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 5.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->brand->ForeColor = System::Drawing::SystemColors::WindowText;
			this->brand->Location = System::Drawing::Point(175, 249);
			this->brand->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->brand->Name = L"brand";
			this->brand->ReadOnly = true;
			this->brand->Size = System::Drawing::Size(100, 20);
			this->brand->TabIndex = 25;
			// 
			// cost
			// 
			this->cost->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->cost->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->cost->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->cost->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 5.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cost->ForeColor = System::Drawing::SystemColors::WindowText;
			this->cost->Location = System::Drawing::Point(175, 329);
			this->cost->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->cost->Name = L"cost";
			this->cost->ReadOnly = true;
			this->cost->Size = System::Drawing::Size(100, 20);
			this->cost->TabIndex = 27;
			// 
			// seats
			// 
			this->seats->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->seats->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->seats->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->seats->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 5.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->seats->ForeColor = System::Drawing::SystemColors::WindowText;
			this->seats->Location = System::Drawing::Point(175, 368);
			this->seats->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->seats->Name = L"seats";
			this->seats->ReadOnly = true;
			this->seats->Size = System::Drawing::Size(100, 20);
			this->seats->TabIndex = 28;
			// 
			// platenum
			// 
			this->platenum->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->platenum->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->platenum->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->platenum->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 5.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->platenum->ForeColor = System::Drawing::SystemColors::WindowText;
			this->platenum->Location = System::Drawing::Point(175, 409);
			this->platenum->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->platenum->Name = L"platenum";
			this->platenum->ReadOnly = true;
			this->platenum->Size = System::Drawing::Size(100, 20);
			this->platenum->TabIndex = 29;
			// 
			// rentaldate
			// 
			this->rentaldate->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->rentaldate->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->rentaldate->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->rentaldate->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 5.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rentaldate->ForeColor = System::Drawing::SystemColors::WindowText;
			this->rentaldate->Location = System::Drawing::Point(175, 449);
			this->rentaldate->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->rentaldate->Name = L"rentaldate";
			this->rentaldate->ReadOnly = true;
			this->rentaldate->Size = System::Drawing::Size(100, 20);
			this->rentaldate->TabIndex = 30;
			// 
			// returndate
			// 
			this->returndate->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->returndate->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->returndate->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->returndate->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 5.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->returndate->ForeColor = System::Drawing::SystemColors::WindowText;
			this->returndate->Location = System::Drawing::Point(175, 492);
			this->returndate->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->returndate->Name = L"returndate";
			this->returndate->ReadOnly = true;
			this->returndate->Size = System::Drawing::Size(100, 20);
			this->returndate->TabIndex = 31;
			// 
			// renter
			// 
			this->renter->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->renter->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->renter->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->renter->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 5.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->renter->ForeColor = System::Drawing::SystemColors::WindowText;
			this->renter->Location = System::Drawing::Point(175, 529);
			this->renter->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->renter->Name = L"renter";
			this->renter->ReadOnly = true;
			this->renter->Size = System::Drawing::Size(100, 20);
			this->renter->TabIndex = 32;
			// 
			// seller
			// 
			this->seller->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->seller->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->seller->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->seller->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 5.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->seller->ForeColor = System::Drawing::SystemColors::WindowText;
			this->seller->Location = System::Drawing::Point(175, 572);
			this->seller->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->seller->Name = L"seller";
			this->seller->ReadOnly = true;
			this->seller->Size = System::Drawing::Size(100, 20);
			this->seller->TabIndex = 33;
			// 
			// Return
			// 
			this->Return->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->Return->FlatAppearance->BorderSize = 0;
			this->Return->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Return->Font = (gcnew System::Drawing::Font(L"Bebas Neue", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Return->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->Return->Location = System::Drawing::Point(99, 647);
			this->Return->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->Return->Name = L"Return";
			this->Return->Size = System::Drawing::Size(107, 32);
			this->Return->TabIndex = 37;
			this->Return->Text = L"RETURN";
			this->Return->UseVisualStyleBackColor = false;
			this->Return->Click += gcnew System::EventHandler(this, &returnCar::return_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Bebas Neue", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button1->Location = System::Drawing::Point(99, 709);
			this->button1->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(107, 32);
			this->button1->TabIndex = 38;
			this->button1->Text = L"BACK";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// transmission
			// 
			this->transmission->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->transmission->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->transmission->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->transmission->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 5.999999F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->transmission->ForeColor = System::Drawing::SystemColors::WindowText;
			this->transmission->Location = System::Drawing::Point(175, 288);
			this->transmission->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->transmission->Name = L"transmission";
			this->transmission->ReadOnly = true;
			this->transmission->Size = System::Drawing::Size(100, 20);
			this->transmission->TabIndex = 39;
			// 
			// returnCar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1184, 761);
			this->Controls->Add(this->transmission);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Return);
			this->Controls->Add(this->seller);
			this->Controls->Add(this->renter);
			this->Controls->Add(this->returndate);
			this->Controls->Add(this->rentaldate);
			this->Controls->Add(this->platenum);
			this->Controls->Add(this->seats);
			this->Controls->Add(this->cost);
			this->Controls->Add(this->brand);
			this->Controls->Add(this->model);
			this->Controls->Add(this->transactID);
			this->Controls->Add(this->dataGridView1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->Name = L"returnCar";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"returnCar";
			this->Load += gcnew System::EventHandler(this, &returnCar::returnCar_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	array<String^, 2>^ returnData;
	public: String^ ReturnCurrentUser;


		  array<String^, 2>^ selectUser(array<String^, 2>^ data, String^ targetUsername) {
			  if (data->Length == 0 || data->GetLength(0) == 0 || data->GetLength(1) == 0) {
				  MessageBox::Show(L"No data to extract.");
				  return nullptr;
			  }

			  int rowCount = data->GetLength(0);
			  int colCount = data->GetLength(1);

			  // Count the number of rows with the target username
			  int validRowCount = 0;
			  for (int rowIdx = 1; rowIdx < rowCount; ++rowIdx) { // Start from 1 to skip the header row
				  if (String::Equals(data[rowIdx, 9], targetUsername)) { // Assuming the username is in column 10 (index 9)
					  validRowCount++;
				  }
			  }

			  // Create a new array for the extracted data, including the header row
			  array<String^, 2>^ extractedData = gcnew array<String^, 2>(validRowCount + 1, colCount);

			  // Copy the header row
			  for (int colIdx = 0; colIdx < colCount; ++colIdx) {
				  extractedData[0, colIdx] = data[0, colIdx];
			  }

			  // Copy rows with the target username to the new array
			  int extractedRowIdx = 1;
			  for (int rowIdx = 1; rowIdx < rowCount; ++rowIdx) { // Start from 1 to skip the header row
				  if (String::Equals(data[rowIdx, 9], targetUsername)) { // Assuming the username is in column 10 (index 9)
					  for (int colIdx = 0; colIdx < colCount; ++colIdx) {
						  extractedData[extractedRowIdx, colIdx] = data[rowIdx, colIdx];
					  }
					  extractedRowIdx++;
				  }
			  }

			  return extractedData;
		  }



		  void EditRenturnCarInCSV(String^ platenum) {
			  std::ifstream inputFile("Transaction.csv");
			  std::ofstream tempFile("temp.csv");

			  if (!inputFile.is_open() || !tempFile.is_open()) {
				  MessageBox::Show(L"Error. Unable to open files for editing.");
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

				  // Check if the "platenum" in the row (assuming it's in a specific column, e.g., column 6)
				  if (row.size() >= 6 && String::Equals(gcnew String(row[6].c_str()), platenum)) {
					  // Set the "rentDate" and "returnDate" values to blank (empty strings).
					  if (row.size() >= 8) {
						  row[0] = ""; // Blank transaction ID
						  row[7] = ""; // Blank rentDate
						  row[8] = ""; // Blank returnDate
						  row[9] = ""; // Blank renter
					  }
				  }

				  // Reconstruct the line and write it to the temporary file.
				  for (size_t i = 0; i < row.size(); ++i) {
					  tempFile << row[i];
					  if (i < row.size() - 1) {
						  tempFile << ",";
					  }
				  }
				  tempFile << "\n";
			  }

			  inputFile.close();
			  tempFile.close();

			  // Replace the original file with the temporary file.
			  std::remove("Transaction.csv"); // Delete the original file.
			  std::rename("temp.csv", "Transaction.csv"); // Rename the temporary file to the original file.

			  MessageBox::Show(L"Rent dates edited successfully.");
		  }

	private: System::Void returnCar_Load(System::Object^ sender, System::EventArgs^ e){
	

		LoadData("Transaction.csv");
		PopulateDataGridView(dataGridView1, selectUser(returnData, ReturnCurrentUser));
	}
private: System::Void return_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ platenum = dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[6]->Value->ToString();
	EditRenturnCarInCSV(platenum);
	LoadData("Transaction.csv");
	PopulateDataGridView(dataGridView1, selectUser(returnData, ReturnCurrentUser));
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	LoadSelectedCell();
}
};
}
