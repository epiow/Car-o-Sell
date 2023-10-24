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
	
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:







	private: System::Windows::Forms::TextBox^ brand;







	private: System::Windows::Forms::TextBox^ transactID;
	private: System::Windows::Forms::TextBox^ returnDate;


	private: System::Windows::Forms::TextBox^ platenum;
	private: System::Windows::Forms::TextBox^ rentDate;





	private: System::Windows::Forms::TextBox^ seats;

	private: System::Windows::Forms::TextBox^ transmission;
	private: System::Windows::Forms::TextBox^ cost;





	private: System::Windows::Forms::Button^ add;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ exitButton;


	private: System::Windows::Forms::TextBox^ model;
	private: System::Windows::Forms::ComboBox^ approval;

	
		   array<String^, 2>^ adminData;
		  


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		

#pragma region Windows Form Designer generated code

		


		void adminWindow::LoadData(const std::string& filename)
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

			//  column names
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
			approval->Text = dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[9]->Value->ToString();
		}


		
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(adminWindow::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->add = (gcnew System::Windows::Forms::Button());
			this->returnDate = (gcnew System::Windows::Forms::TextBox());
			this->platenum = (gcnew System::Windows::Forms::TextBox());
			this->rentDate = (gcnew System::Windows::Forms::TextBox());
			this->seats = (gcnew System::Windows::Forms::TextBox());
			this->transmission = (gcnew System::Windows::Forms::TextBox());
			this->cost = (gcnew System::Windows::Forms::TextBox());
			this->brand = (gcnew System::Windows::Forms::TextBox());
			this->transactID = (gcnew System::Windows::Forms::TextBox());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->model = (gcnew System::Windows::Forms::TextBox());
			this->approval = (gcnew System::Windows::Forms::ComboBox());
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
			this->dataGridView1->Location = System::Drawing::Point(315, 143);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->RowHeadersWidth = 5;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(658, 487);
			this->dataGridView1->StandardTab = true;
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &adminWindow::dataGridView1_CellContentClick);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Designer", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button2->Location = System::Drawing::Point(210, 553);
			this->button2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(83, 32);
			this->button2->TabIndex = 38;
			this->button2->Text = L"Delete";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Designer", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button1->Location = System::Drawing::Point(128, 598);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(74, 32);
			this->button1->TabIndex = 37;
			this->button1->Text = L"Edit";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// add
			// 
			this->add->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->add->FlatAppearance->BorderSize = 0;
			this->add->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->add->Font = (gcnew System::Drawing::Font(L"Designer", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->add->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->add->Location = System::Drawing::Point(31, 553);
			this->add->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->add->Name = L"add";
			this->add->Size = System::Drawing::Size(81, 32);
			this->add->TabIndex = 36;
			this->add->Text = L"Add";
			this->add->UseVisualStyleBackColor = false;
			// 
			// returnDate
			// 
			this->returnDate->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->returnDate->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 6.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->returnDate->Location = System::Drawing::Point(189, 468);
			this->returnDate->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->returnDate->Name = L"returnDate";
			this->returnDate->Size = System::Drawing::Size(104, 23);
			this->returnDate->TabIndex = 35;
			// 
			// platenum
			// 
			this->platenum->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->platenum->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 6.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->platenum->Location = System::Drawing::Point(189, 387);
			this->platenum->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->platenum->Name = L"platenum";
			this->platenum->Size = System::Drawing::Size(104, 23);
			this->platenum->TabIndex = 34;
			// 
			// rentDate
			// 
			this->rentDate->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->rentDate->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 6.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rentDate->Location = System::Drawing::Point(189, 428);
			this->rentDate->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->rentDate->Name = L"rentDate";
			this->rentDate->Size = System::Drawing::Size(104, 23);
			this->rentDate->TabIndex = 33;
			// 
			// seats
			// 
			this->seats->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->seats->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 6.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->seats->Location = System::Drawing::Point(189, 345);
			this->seats->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->seats->Name = L"seats";
			this->seats->Size = System::Drawing::Size(104, 23);
			this->seats->TabIndex = 29;
			// 
			// transmission
			// 
			this->transmission->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->transmission->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 6.749999F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->transmission->Location = System::Drawing::Point(189, 265);
			this->transmission->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->transmission->Name = L"transmission";
			this->transmission->Size = System::Drawing::Size(104, 23);
			this->transmission->TabIndex = 28;
			// 
			// cost
			// 
			this->cost->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->cost->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 6.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cost->Location = System::Drawing::Point(189, 306);
			this->cost->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->cost->Name = L"cost";
			this->cost->Size = System::Drawing::Size(104, 23);
			this->cost->TabIndex = 27;
			// 
			// brand
			// 
			this->brand->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->brand->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 6.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->brand->Location = System::Drawing::Point(189, 225);
			this->brand->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->brand->Name = L"brand";
			this->brand->Size = System::Drawing::Size(104, 23);
			this->brand->TabIndex = 23;
			// 
			// transactID
			// 
			this->transactID->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->transactID->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->transactID->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->transactID->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 6.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->transactID->ForeColor = System::Drawing::SystemColors::WindowText;
			this->transactID->Location = System::Drawing::Point(189, 143);
			this->transactID->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->transactID->Name = L"transactID";
			this->transactID->Size = System::Drawing::Size(104, 23);
			this->transactID->TabIndex = 22;
			// 
			// exitButton
			// 
			this->exitButton->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->exitButton->Location = System::Drawing::Point(943, 22);
			this->exitButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(30, 32);
			this->exitButton->TabIndex = 18;
			this->exitButton->Text = L"X";
			this->exitButton->Click += gcnew System::EventHandler(this, &adminWindow::exitButton_Click);
			// 
			// model
			// 
			this->model->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->model->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 6.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->model->Location = System::Drawing::Point(189, 184);
			this->model->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->model->Name = L"model";
			this->model->Size = System::Drawing::Size(104, 23);
			this->model->TabIndex = 40;
			// 
			// approval
			// 
			this->approval->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->approval->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->approval->FormattingEnabled = true;
			this->approval->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"TRUE", L"FALSE" });
			this->approval->Location = System::Drawing::Point(189, 510);
			this->approval->Name = L"approval";
			this->approval->Size = System::Drawing::Size(104, 21);
			this->approval->TabIndex = 41;
			this->approval->SelectedIndexChanged += gcnew System::EventHandler(this, &adminWindow::approval_SelectedIndexChanged);
			// 
			// adminWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScrollMargin = System::Drawing::Size(0, 25);
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1000, 650);
			this->Controls->Add(this->approval);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->model);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->add);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->transactID);
			this->Controls->Add(this->returnDate);
			this->Controls->Add(this->brand);
			this->Controls->Add(this->rentDate);
			this->Controls->Add(this->platenum);
			this->Controls->Add(this->transmission);
			this->Controls->Add(this->cost);
			this->Controls->Add(this->seats);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
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

private: System::Void approval_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
