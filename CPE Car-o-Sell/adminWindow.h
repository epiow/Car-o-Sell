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
			PopulateDataGridView("Transaction.csv");
			
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


	private: System::Windows::Forms::TextBox^ cost;
	private: System::Windows::Forms::Button^ addBtn;
	private: System::Windows::Forms::Button^ delBtn;
	private: System::Windows::Forms::Button^ editBtn;








	private: System::Windows::Forms::Button^ exitButton;


	private: System::Windows::Forms::TextBox^ model;
	private: System::Windows::Forms::ComboBox^ approval;
	private: System::Windows::Forms::ComboBox^ transmission;





	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

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
		approval->Text = "";
	}
		void adminWindow::PopulateDataGridView(const std::string& filename)
		{
			std::ifstream file(filename);
			std::vector<std::vector<std::string>> data;
			if (!file.is_open()) {
				MessageBox::Show(L"Error. Unable to open user credentials file.");
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

			// Read the remaining data
			while (std::getline(file, line)) {
				std::vector<std::string> row;
				std::stringstream ss(line);
				std::string cell;

				while (std::getline(ss, cell, ',')) {
					row.push_back(cell);
				}

				data.push_back(row);
			}

			file.close();
			int rowCount = data.size();
			int columnCount = (rowCount > 0) ? data[1].size() : 0;

			dataGridView1->RowCount = rowCount;
			dataGridView1->ColumnCount = columnCount;

			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < columnCount; j++) {
					dataGridView1->Rows[i]->Cells[j]->Value = gcnew String(data[i][j].c_str());

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
			approval->Text = dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[9]->Value->ToString();
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
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::Window;
			this->dataGridView1->Location = System::Drawing::Point(315, 143);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->RowHeadersWidth = 5;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(669, 487);
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
			this->delBtn->Location = System::Drawing::Point(210, 553);
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
			this->editBtn->Location = System::Drawing::Point(128, 598);
			this->editBtn->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->editBtn->Name = L"editBtn";
			this->editBtn->Size = System::Drawing::Size(74, 32);
			this->editBtn->TabIndex = 37;
			this->editBtn->Text = L"Edit";
			this->editBtn->UseVisualStyleBackColor = false;
			// 
			// addBtn
			// 
			this->addBtn->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->addBtn->FlatAppearance->BorderSize = 0;
			this->addBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->addBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addBtn->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->addBtn->Location = System::Drawing::Point(31, 553);
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
			this->returnDate->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 6.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->returnDate->Location = System::Drawing::Point(189, 468);
			this->returnDate->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
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
			this->platenum->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
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
			this->rentDate->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
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
			this->seats->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->seats->Name = L"seats";
			this->seats->Size = System::Drawing::Size(104, 23);
			this->seats->TabIndex = 29;
			// 
			// cost
			// 
			this->cost->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->cost->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 6.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cost->Location = System::Drawing::Point(189, 306);
			this->cost->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
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
			this->brand->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
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
			this->transactID->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->transactID->Name = L"transactID";
			this->transactID->Size = System::Drawing::Size(104, 23);
			this->transactID->TabIndex = 22;
			// 
			// exitButton
			// 
			this->exitButton->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->exitButton->Location = System::Drawing::Point(943, 22);
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
			this->model->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 6.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->model->Location = System::Drawing::Point(189, 184);
			this->model->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
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
			// 
			// transmission
			// 
			this->transmission->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->transmission->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->transmission->FormattingEnabled = true;
			this->transmission->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Auto", L"Manual" });
			this->transmission->Location = System::Drawing::Point(189, 266);
			this->transmission->Name = L"transmission";
			this->transmission->Size = System::Drawing::Size(104, 21);
			this->transmission->TabIndex = 42;
			// 
			// adminWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScrollMargin = System::Drawing::Size(0, 25);
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1023, 651);
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

private: System::Void addBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ tID_text = this->transactID->Text;
	String^ model_text = this->model->Text;
	String^ brand_text = this->brand->Text;
	String^ transmission_text = this->transmission->Text;
	String^ cost_text = this->cost->Text;
	String^ seats_text = this->seats->Text;
	String^ plateNo_text = this->platenum->Text;
	String^ rent_text = this->rentDate->Text;
	String^ return_text = this->returnDate->Text;
	String^ approval_text = this->approval->Text;

	if (approval_text == "") {
		approval_text = "FALSE";
	}

	try {
		System::IO::StreamWriter^ file = gcnew System::IO::StreamWriter("Transaction.csv", true); // Open the file in append mode

		file->Write(tID_text + ",");
		file->Write(model_text + ",");
		file->Write(brand_text + ",");
		file->Write(transmission_text + ",");
		file->Write(cost_text + ",");
		file->Write(seats_text + ",");
		file->Write(plateNo_text + ",");
		file->Write(rent_text + ",");
		file->Write(return_text + ",");
		file->Write(approval_text);
		file->WriteLine("");

		file->Close();

		MessageBox::Show(L"Car successfully added.");

		//dataGridView1->Dispose();

		this->transactID->Text = "";
		this->model->Text = "";
		this->brand->Text = "";
		this->transmission->Text = "";
		this->cost->Text = "";
		this->seats->Text = "";
		this->platenum->Text = "";
		this->rentDate->Text = "";
		this->returnDate->Text = "";
		this->approval->Text = "";

		PopulateDataGridView("Transaction.csv");
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

private: System::Void delBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	// PAAYOS PLS TENKS
	// Get the selected cell, and then retrieve the row index
	DataGridViewCell^ selectedCell = dataGridView1->CurrentCell;

	if (selectedCell != nullptr) {
		int rowIndex = selectedCell->RowIndex;

		// Get the plate number from the clicked row
		String^ plateToDelete = dataGridView1->Rows[rowIndex]->Cells[6]->Value->ToString(); // Assuming the "Plate #" column is at index 6

		for (int i = 0; i < dataGridView1->Rows->Count; i++) {
			String^ plateInRow = dataGridView1->Rows[i]->Cells["Plate #"]->Value->ToString();

			if (plateInRow == plateToDelete) {
				dataGridView1->Rows->RemoveAt(i);
				break; // Assuming there's only one row with the given plate number, you can break out of the loop
			}
		}

		MessageBox::Show(L"Car successfully deleted.");

		//dataGridView1->Dispose();

		this->transactID->Text = "";
		this->model->Text = "";
		this->brand->Text = "";
		this->transmission->Text = "";
		this->cost->Text = "";
		this->seats->Text = "";
		this->platenum->Text = "";
		this->rentDate->Text = "";
		this->returnDate->Text = "";
		this->approval->Text = "";

		PopulateDataGridView("Transaction.csv");
	}
}
};
}
