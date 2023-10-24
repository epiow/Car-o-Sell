#pragma once
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
//#include "rentWindow.h"


namespace CPECaroSell {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	/// <summary>
	/// Summary for calendar
	/// </summary>
	public ref class calendar : public System::Windows::Forms::Form
	{
	public:
		String^ CcurrentUser;
		calendar(void)
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
		~calendar()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MonthCalendar^ monthCalendar1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ startDate;

	private: System::Windows::Forms::TextBox^ endDate;
	private: System::Windows::Forms::Button^ calendarEnter;
	private: System::Windows::Forms::Button^ calendarCancel;



	private: System::Windows::Forms::DataGridView^ dataGridView1;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(calendar::typeid));
			this->monthCalendar1 = (gcnew System::Windows::Forms::MonthCalendar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->calendarCancel = (gcnew System::Windows::Forms::Button());
			this->calendarEnter = (gcnew System::Windows::Forms::Button());
			this->endDate = (gcnew System::Windows::Forms::TextBox());
			this->startDate = (gcnew System::Windows::Forms::TextBox());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// monthCalendar1
			// 
			this->monthCalendar1->Location = System::Drawing::Point(19, 17);
			this->monthCalendar1->Margin = System::Windows::Forms::Padding(7);
			this->monthCalendar1->MaxDate = System::DateTime(2040, 12, 31, 0, 0, 0, 0);
			this->monthCalendar1->MaxSelectionCount = 14;
			this->monthCalendar1->MinDate = System::DateTime(2023, 1, 1, 0, 0, 0, 0);
			this->monthCalendar1->Name = L"monthCalendar1";
			this->monthCalendar1->TabIndex = 0;
			this->monthCalendar1->DateChanged += gcnew System::Windows::Forms::DateRangeEventHandler(this, &calendar::monthCalendar1_DateChanged);
			this->monthCalendar1->DateSelected += gcnew System::Windows::Forms::DateRangeEventHandler(this, &calendar::monthCalendar1_DateSelected);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Rockwell Condensed", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(7, 206);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(89, 26);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Start Date:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Rockwell Condensed", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(7, 240);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(80, 26);
			this->label2->TabIndex = 2;
			this->label2->Text = L"End Date:";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->panel1->Controls->Add(this->calendarCancel);
			this->panel1->Controls->Add(this->calendarEnter);
			this->panel1->Controls->Add(this->endDate);
			this->panel1->Controls->Add(this->startDate);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->monthCalendar1);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Location = System::Drawing::Point(-3, 1);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(274, 284);
			this->panel1->TabIndex = 3;
			// 
			// calendarCancel
			// 
			this->calendarCancel->Font = (gcnew System::Drawing::Font(L"Rockwell Condensed", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->calendarCancel->Location = System::Drawing::Point(185, 240);
			this->calendarCancel->Margin = System::Windows::Forms::Padding(2);
			this->calendarCancel->Name = L"calendarCancel";
			this->calendarCancel->Size = System::Drawing::Size(62, 32);
			this->calendarCancel->TabIndex = 6;
			this->calendarCancel->Text = L"Cancel";
			this->calendarCancel->UseVisualStyleBackColor = true;
			// 
			// calendarEnter
			// 
			this->calendarEnter->Font = (gcnew System::Drawing::Font(L"Rockwell Condensed", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->calendarEnter->Location = System::Drawing::Point(185, 206);
			this->calendarEnter->Margin = System::Windows::Forms::Padding(2);
			this->calendarEnter->Name = L"calendarEnter";
			this->calendarEnter->Size = System::Drawing::Size(62, 32);
			this->calendarEnter->TabIndex = 5;
			this->calendarEnter->Text = L"Enter";
			this->calendarEnter->UseVisualStyleBackColor = true;
			this->calendarEnter->Click += gcnew System::EventHandler(this, &calendar::calendarEnter_Click);
			// 
			// endDate
			// 
			this->endDate->Font = (gcnew System::Drawing::Font(L"Rockwell Condensed", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->endDate->Location = System::Drawing::Point(96, 240);
			this->endDate->Margin = System::Windows::Forms::Padding(2);
			this->endDate->Name = L"endDate";
			this->endDate->ReadOnly = true;
			this->endDate->Size = System::Drawing::Size(76, 29);
			this->endDate->TabIndex = 4;
			this->endDate->Text = L"mm/dd/yyyy";
			// 
			// startDate
			// 
			this->startDate->Font = (gcnew System::Drawing::Font(L"Rockwell Condensed", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->startDate->Location = System::Drawing::Point(96, 206);
			this->startDate->Margin = System::Windows::Forms::Padding(2);
			this->startDate->Name = L"startDate";
			this->startDate->ReadOnly = true;
			this->startDate->Size = System::Drawing::Size(76, 29);
			this->startDate->TabIndex = 3;
			this->startDate->Text = L"mm/dd/yyyy";
			// 
			// calendar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(262, 284);
			this->Controls->Add(this->panel1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"calendar";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"calendar";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	

	


private: System::Void monthCalendar1_DateSelected(System::Object^ sender, System::Windows::Forms::DateRangeEventArgs^ e) {
	startDate->Text = monthCalendar1->SelectionRange->Start.Date.ToString("MM-dd-yyyy");
	endDate->Text = monthCalendar1->SelectionRange->End.Date.ToString("MM-dd-yyyy");
}
private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show(L"Do you want to cancel the rent?", L"Exit", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
	{
		this->Close();
	}
}


private: System::Void monthCalendar1_DateChanged(System::Object^ sender, System::Windows::Forms::DateRangeEventArgs^ e) {

}

private: System::Void calendarEnter_Click(System::Object^ sender, System::EventArgs^ e) {
	// Specify the file path
	String^ currentUser = CcurrentUser;
	String^ filePath = "Transaction.csv";

	// Retrieve the selected rental and return dates
	DateTime startDate = monthCalendar1->SelectionStart;
	DateTime endDate = monthCalendar1->SelectionEnd;

	// Retrieve the "Plate #" of the car to be rented (replace "desiredPlateNumber" with the actual value)
	String^ desiredPlateNumber = "EPI0000"; // Replace with the actual "Plate #" you want to rent.

	// Open and read the CSV file
	cli::array<String^>^ lines = File::ReadAllLines(filePath);

	// Find the row that corresponds to the desired car based on the "Plate #"
	int i = 1;
	for each (String ^ line in lines) {
		array<String^>^ columns = line->Split(',');
		
		// Assuming the "Plate #" is in the sixth column (index 6)
		if (columns->Length > 6 && columns[6]->Trim() == desiredPlateNumber) {
			// Update the "Rental Date" and "Return Date" columns (modify the indices accordingly)
			columns[7] = startDate.ToShortDateString();
			columns[8] = endDate.ToShortDateString();
			columns[9] = currentUser;

			// Reconstruct the updated line
			lines[i] = String::Join(",", columns);
			i++;
			// Save the modified data back to the file
			File::WriteAllLines(filePath, lines);

			// You can break the loop here since you found the desired car
			break;
		}
	}
}


};
}
