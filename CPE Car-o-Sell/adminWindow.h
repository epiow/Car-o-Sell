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
	using namespace System::IO;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for adminWindow
	/// </summary>
	public ref class adminWindow : public System::Windows::Forms::Form
	{
	public:
		adminWindow(void)
		{
			InitializeComponent();
			LoadData("Transaction.csv");
			PopulateDataGridView(dataGridView1, adminData);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~adminWindow()
		{
			if (components)
			{
				delete components;
			}
		}

		array<String^, 2>^ adminData;

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:







	private: System::Windows::Forms::TextBox^ brand;







	private: System::Windows::Forms::TextBox^ transactID;
	private: System::Windows::Forms::TextBox^ returnDate;


	private: System::Windows::Forms::TextBox^ platenum;
	private: System::Windows::Forms::TextBox^ rentDate;





	private: System::Windows::Forms::TextBox^ seats;


	private: System::Windows::Forms::TextBox^ cost;
	private: System::Windows::Forms::Button^ addBtn;
	private: System::Windows::Forms::Button^ delBtn;
	private: System::Windows::Forms::Button^ editBtn;








	private: System::Windows::Forms::Button^ exitButton;


	private: System::Windows::Forms::TextBox^ model;
	private: System::Windows::Forms::ComboBox^ approval;
	private: System::Windows::Forms::ComboBox^ transmission;
	private: System::Windows::Forms::TextBox^ renter;
	private: System::Windows::Forms::TextBox^ seller;






	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
	private: void ClearInputFields() {
		transactID->Text = "";
		model->Text = "";
		brand->Text = "";
		transmission->Text = "";
		cost->Text = "";
		seats->Text = "";
		platenum->Text = "";
		rentDate->Text = "";
		returnDate->Text = "";
		renter->Text = "";
		seller->Text = "";
		approval->Text = "";
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

			   adminData = gcnew array<String^, 2>(data.size(), numColumns);
			   for (int i = 0; i < data.size(); i++) {
				   for (int j = 0; j < numColumns; j++) {
					   adminData[i, j] = gcnew String(data[i][j].c_str());
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
			   rentDate->Text = dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[7]->Value->ToString();
			   returnDate->Text = dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[8]->Value->ToString();
			   renter->Text = dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[9]->Value->ToString();
			   seller->Text = dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[10]->Value->ToString();
			   approval->Text = dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[11]->Value->ToString();
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

		   void EditRowInCSV(const std::string& filename, DataGridView^ dataGridView, String^ tID, String^ model, String^ brand, String^ transmission, String^ cost, String^ seats, String^ platenum, String^ rentDate, String^ returnDate, String^ renter, String^ seller, String^ approval)
		   {
			   // Check if a row is selected in the DataGridView.
			   if (dataGridView->SelectedRows->Count == 0) {
				   MessageBox::Show(L"Please select a row to edit.");
				   return;
			   }

			   int selectedRowIndex = dataGridView->SelectedRows[0]->Index;
			   String^ oldPlatenum = dataGridView->Rows[selectedRowIndex]->Cells[6]->Value->ToString();

			   std::ifstream inputFile(filename);
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

				   // Check if the "platenum" in the row (assuming it's in a specific column, e.g., column 6) matches the "platenum" from the selected row in the DataGridView.
				   if (row.size() >= 6 && String::Equals(gcnew String(row[6].c_str()), oldPlatenum)) {
					   // Update the values in this row with the provided values.
					   row[0] = msclr::interop::marshal_as<std::string>(tID);
					   row[1] = msclr::interop::marshal_as<std::string>(model);
					   row[2] = msclr::interop::marshal_as<std::string>(brand);
					   row[3] = msclr::interop::marshal_as<std::string>(transmission);
					   row[4] = msclr::interop::marshal_as<std::string>(cost);
					   row[5] = msclr::interop::marshal_as<std::string>(seats);
					   row[6] = msclr::interop::marshal_as<std::string>(platenum);
					   row[7] = msclr::interop::marshal_as<std::string>(rentDate);
					   row[8] = msclr::interop::marshal_as<std::string>(returnDate);
					   row[9] = msclr::interop::marshal_as<std::string>(renter);
					   row[10] = msclr::interop::marshal_as<std::string>(seller);
					   row[11] = msclr::interop::marshal_as<std::string>(approval);
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
			   std::remove(filename.c_str()); // Delete the original file.
			   std::rename("temp.csv", filename.c_str()); // Rename the temporary file to the original file.

			   MessageBox::Show(L"Row edited successfully.");
		   }

		   void InitializeComponent(void)
		   {
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(adminWindow::typeid));
			   this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			   this->delBtn = (gcnew System::Windows::Forms::Button());
			   this->editBtn = (gcnew System::Windows::Forms::Button());
			   this->addBtn = (gcnew System::Windows::Forms::Button());
			   this->returnDate = (gcnew System::Windows::Forms::TextBox());
			   this->platenum = (gcnew System::Windows::Forms::TextBox());
			   this->rentDate = (gcnew System::Windows::Forms::TextBox());
			   this->seats = (gcnew System::Windows::Forms::TextBox());
			   this->cost = (gcnew System::Windows::Forms::TextBox());
			   this->brand = (gcnew System::Windows::Forms::TextBox());
			   this->transactID = (gcnew System::Windows::Forms::TextBox());
			   this->exitButton = (gcnew System::Windows::Forms::Button());
			   this->model = (gcnew System::Windows::Forms::TextBox());
			   this->approval = (gcnew System::Windows::Forms::ComboBox());
			   this->transmission = (gcnew System::Windows::Forms::ComboBox());
			   this->renter = (gcnew System::Windows::Forms::TextBox());
			   this->seller = (gcnew System::Windows::Forms::TextBox());
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
			   this->dataGridView1->Location = System::Drawing::Point(331, 142);
			   this->dataGridView1->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			   this->dataGridView1->Name = L"dataGridView1";
			   this->dataGridView1->ReadOnly = true;
			   this->dataGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			   this->dataGridView1->RowHeadersWidth = 5;
			   this->dataGridView1->RowTemplate->Height = 24;
			   this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			   this->dataGridView1->Size = System::Drawing::Size(846, 636);
			   this->dataGridView1->StandardTab = true;
			   this->dataGridView1->TabIndex = 0;
			   this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &adminWindow::dataGridView1_CellContentClick);
			   // 
			   // delBtn
			   // 
			   this->delBtn->BackColor = System::Drawing::SystemColors::ControlLightLight;
			   this->delBtn->FlatAppearance->BorderSize = 0;
			   this->delBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->delBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->delBtn->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			   this->delBtn->Location = System::Drawing::Point(215, 624);
			   this->delBtn->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			   this->delBtn->Name = L"delBtn";
			   this->delBtn->Size = System::Drawing::Size(83, 32);
			   this->delBtn->TabIndex = 38;
			   this->delBtn->Text = L"Delete";
			   this->delBtn->UseVisualStyleBackColor = false;
			   this->delBtn->Click += gcnew System::EventHandler(this, &adminWindow::delBtn_Click);
			   // 
			   // editBtn
			   // 
			   this->editBtn->BackColor = System::Drawing::SystemColors::ControlLightLight;
			   this->editBtn->FlatAppearance->BorderSize = 0;
			   this->editBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->editBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->editBtn->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			   this->editBtn->Location = System::Drawing::Point(153, 692);
			   this->editBtn->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			   this->editBtn->Name = L"editBtn";
			   this->editBtn->Size = System::Drawing::Size(74, 32);
			   this->editBtn->TabIndex = 37;
			   this->editBtn->Text = L"Edit";
			   this->editBtn->UseVisualStyleBackColor = false;
			   this->editBtn->Click += gcnew System::EventHandler(this, &adminWindow::editBtn_Click);
			   // 
			   // addBtn
			   // 
			   this->addBtn->BackColor = System::Drawing::SystemColors::ControlLightLight;
			   this->addBtn->FlatAppearance->BorderSize = 0;
			   this->addBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->addBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->addBtn->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			   this->addBtn->Location = System::Drawing::Point(66, 624);
			   this->addBtn->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			   this->addBtn->Name = L"addBtn";
			   this->addBtn->Size = System::Drawing::Size(81, 32);
			   this->addBtn->TabIndex = 36;
			   this->addBtn->Text = L"Add";
			   this->addBtn->UseVisualStyleBackColor = false;
			   this->addBtn->Click += gcnew System::EventHandler(this, &adminWindow::addBtn_Click);
			   // 
			   // returnDate
			   // 
			   this->returnDate->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->returnDate->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 5.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->returnDate->Location = System::Drawing::Point(185, 455);
			   this->returnDate->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			   this->returnDate->Name = L"returnDate";
			   this->returnDate->Size = System::Drawing::Size(100, 20);
			   this->returnDate->TabIndex = 35;
			   this->returnDate->TextChanged += gcnew System::EventHandler(this, &adminWindow::returnDate_TextChanged);
			   // 
			   // platenum
			   // 
			   this->platenum->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->platenum->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 5.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->platenum->Location = System::Drawing::Point(185, 380);
			   this->platenum->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			   this->platenum->Name = L"platenum";
			   this->platenum->Size = System::Drawing::Size(100, 20);
			   this->platenum->TabIndex = 34;
			   this->platenum->TextChanged += gcnew System::EventHandler(this, &adminWindow::platenum_TextChanged);
			   // 
			   // rentDate
			   // 
			   this->rentDate->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->rentDate->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 5.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->rentDate->Location = System::Drawing::Point(185, 418);
			   this->rentDate->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			   this->rentDate->Name = L"rentDate";
			   this->rentDate->Size = System::Drawing::Size(100, 20);
			   this->rentDate->TabIndex = 33;
			   // 
			   // seats
			   // 
			   this->seats->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->seats->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 5.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->seats->Location = System::Drawing::Point(185, 342);
			   this->seats->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			   this->seats->Name = L"seats";
			   this->seats->Size = System::Drawing::Size(100, 20);
			   this->seats->TabIndex = 29;
			   this->seats->TextChanged += gcnew System::EventHandler(this, &adminWindow::seats_TextChanged);
			   // 
			   // cost
			   // 
			   this->cost->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->cost->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 5.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->cost->Location = System::Drawing::Point(185, 305);
			   this->cost->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			   this->cost->Name = L"cost";
			   this->cost->Size = System::Drawing::Size(100, 20);
			   this->cost->TabIndex = 27;
			   this->cost->TextChanged += gcnew System::EventHandler(this, &adminWindow::cost_TextChanged);
			   // 
			   // brand
			   // 
			   this->brand->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->brand->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 5.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->brand->Location = System::Drawing::Point(185, 229);
			   this->brand->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			   this->brand->Name = L"brand";
			   this->brand->Size = System::Drawing::Size(100, 20);
			   this->brand->TabIndex = 23;
			   this->brand->TextChanged += gcnew System::EventHandler(this, &adminWindow::brand_TextChanged);
			   // 
			   // transactID
			   // 
			   this->transactID->BackColor = System::Drawing::SystemColors::ControlLightLight;
			   this->transactID->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->transactID->Cursor = System::Windows::Forms::Cursors::IBeam;
			   this->transactID->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 5.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->transactID->ForeColor = System::Drawing::SystemColors::WindowText;
			   this->transactID->Location = System::Drawing::Point(185, 153);
			   this->transactID->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			   this->transactID->Name = L"transactID";
			   this->transactID->Size = System::Drawing::Size(100, 20);
			   this->transactID->TabIndex = 22;
			   this->transactID->TextChanged += gcnew System::EventHandler(this, &adminWindow::transactID_TextChanged);
			   // 
			   // exitButton
			   // 
			   this->exitButton->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			   this->exitButton->Location = System::Drawing::Point(1121, 36);
			   this->exitButton->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			   this->exitButton->Name = L"exitButton";
			   this->exitButton->Size = System::Drawing::Size(30, 32);
			   this->exitButton->TabIndex = 18;
			   this->exitButton->Text = L"X";
			   this->exitButton->Click += gcnew System::EventHandler(this, &adminWindow::exitButton_Click);
			   // 
			   // model
			   // 
			   this->model->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->model->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 5.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->model->Location = System::Drawing::Point(185, 191);
			   this->model->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			   this->model->Name = L"model";
			   this->model->Size = System::Drawing::Size(100, 20);
			   this->model->TabIndex = 40;
			   // 
			   // approval
			   // 
			   this->approval->BackColor = System::Drawing::SystemColors::ControlLightLight;
			   this->approval->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->approval->FormattingEnabled = true;
			   this->approval->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"TRUE", L"FALSE" });
			   this->approval->Location = System::Drawing::Point(185, 569);
			   this->approval->Name = L"approval";
			   this->approval->Size = System::Drawing::Size(100, 21);
			   this->approval->TabIndex = 41;
			   // 
			   // transmission
			   // 
			   this->transmission->BackColor = System::Drawing::SystemColors::ControlLightLight;
			   this->transmission->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->transmission->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->transmission->FormattingEnabled = true;
			   this->transmission->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Auto", L"Manual" });
			   this->transmission->Location = System::Drawing::Point(185, 267);
			   this->transmission->Name = L"transmission";
			   this->transmission->Size = System::Drawing::Size(100, 20);
			   this->transmission->TabIndex = 42;
			   // 
			   // renter
			   // 
			   this->renter->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->renter->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 5.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->renter->Location = System::Drawing::Point(185, 494);
			   this->renter->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			   this->renter->Name = L"renter";
			   this->renter->Size = System::Drawing::Size(100, 20);
			   this->renter->TabIndex = 43;
			   // 
			   // seller
			   // 
			   this->seller->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->seller->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 5.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->seller->Location = System::Drawing::Point(185, 531);
			   this->seller->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			   this->seller->Name = L"seller";
			   this->seller->Size = System::Drawing::Size(100, 20);
			   this->seller->TabIndex = 44;
			   // 
			   // adminWindow
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->AutoScrollMargin = System::Drawing::Size(0, 25);
			   this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			   this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			   this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->ClientSize = System::Drawing::Size(1200, 800);
			   this->Controls->Add(this->seller);
			   this->Controls->Add(this->renter);
			   this->Controls->Add(this->transmission);
			   this->Controls->Add(this->approval);
			   this->Controls->Add(this->editBtn);
			   this->Controls->Add(this->delBtn);
			   this->Controls->Add(this->model);
			   this->Controls->Add(this->exitButton);
			   this->Controls->Add(this->addBtn);
			   this->Controls->Add(this->dataGridView1);
			   this->Controls->Add(this->transactID);
			   this->Controls->Add(this->returnDate);
			   this->Controls->Add(this->brand);
			   this->Controls->Add(this->rentDate);
			   this->Controls->Add(this->platenum);
			   this->Controls->Add(this->cost);
			   this->Controls->Add(this->seats);
			   this->DoubleBuffered = true;
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			   this->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			   this->Name = L"adminWindow";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"adminWindow";
			   this->Load += gcnew System::EventHandler(this, &adminWindow::adminWindow_Load);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	public: User^ user = nullptr;

	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {


		LoadSelectedCell();

	}

	private: System::Void adminWindow_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	public: bool switchToLogin = false;
	private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) {
		switchToLogin = true;
		this->Close();
	}
	public: String^ ScurrentUser;
	private: System::Void addBtn_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ tID = this->transactID->Text;
		String^ model = this->model->Text;
		String^ brand = this->brand->Text;
		String^ transmission = this->transmission->Text;
		String^ cost = this->cost->Text;
		String^ seats = this->seats->Text;
		String^ platenum = this->platenum->Text;
		String^ rentDate = this->rentDate->Text;
		String^ returnDate = this->returnDate->Text;
		String^ renter = this->renter->Text;
		String^ seller = this->seller->Text;
		String^ approval = this->approval->Text;

		System::String^ transactionData = String::Format("\n{0},{1},{2},{3},{4},{5},{6},{7},{8},{9},{10},{11}",
			tID, model, brand, transmission, cost, seats, platenum, rentDate, returnDate, renter, seller, approval);

		System::IO::File::AppendAllText("Transaction.csv", transactionData);

		ClearInputFields();
		MessageBox::Show(L"Car successfully added.");
		LoadData("Transaction.csv");
		PopulateDataGridView(dataGridView1, adminData);
	}

	private: System::Void delBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		
	
			String^ platenum = this->platenum->Text;
			DeleteRowFromCSV("Transaction.csv", dataGridView1);
			ClearInputFields();
			LoadData("Transaction.csv");
			PopulateDataGridView(dataGridView1, adminData);

		
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}


private: System::Void brand_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void returnDate_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void transactID_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void cost_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void seats_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void platenum_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void editBtn_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ tID = this->transactID->Text;
	String^ model = this->model->Text;
	String^ brand = this->brand->Text;
	String^ transmission = this->transmission->Text;
	String^ cost = this->cost->Text;
	String^ seats = this->seats->Text;
	String^ platenum = this->platenum->Text;
	String^ rentDate = this->rentDate->Text;
	String^ returnDate = this->returnDate->Text;
	String^ renter = this->renter->Text;
	String^ seller = this->seller->Text;
	String^ approval = this->approval->Text;

	EditRowInCSV("Transaction.csv", dataGridView1,tID, model, brand, transmission, cost, seats, platenum, rentDate,returnDate, renter, seller, approval);
	ClearInputFields();
	LoadData("Transaction.csv");
	PopulateDataGridView(dataGridView1, adminData);

}
};
}
