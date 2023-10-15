#pragma once
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>


namespace CPECaroSell {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for calendar
	/// </summary>
	public ref class calendar : public System::Windows::Forms::Form
	{
	public:
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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;




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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->endDate = (gcnew System::Windows::Forms::TextBox());
			this->startDate = (gcnew System::Windows::Forms::TextBox());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// monthCalendar1
			// 
			this->monthCalendar1->Location = System::Drawing::Point(25, 21);
			this->monthCalendar1->MaxDate = System::DateTime(2040, 12, 31, 0, 0, 0, 0);
			this->monthCalendar1->MaxSelectionCount = 14;
			this->monthCalendar1->MinDate = System::DateTime(2023, 1, 1, 0, 0, 0, 0);
			this->monthCalendar1->Name = L"monthCalendar1";
			this->monthCalendar1->TabIndex = 0;
			this->monthCalendar1->DateSelected += gcnew System::Windows::Forms::DateRangeEventHandler(this, &calendar::monthCalendar1_DateSelected);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Rockwell Condensed", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(9, 254);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(113, 33);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Start Date:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Rockwell Condensed", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(9, 296);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(102, 33);
			this->label2->TabIndex = 2;
			this->label2->Text = L"End Date:";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->endDate);
			this->panel1->Controls->Add(this->startDate);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->monthCalendar1);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Location = System::Drawing::Point(-4, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(366, 350);
			this->panel1->TabIndex = 3;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Rockwell Condensed", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(247, 296);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(82, 39);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Rockwell Condensed", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(247, 254);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(82, 39);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Enter";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// endDate
			// 
			this->endDate->Font = (gcnew System::Drawing::Font(L"Rockwell Condensed", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->endDate->Location = System::Drawing::Point(128, 296);
			this->endDate->Name = L"endDate";
			this->endDate->ReadOnly = true;
			this->endDate->Size = System::Drawing::Size(100, 35);
			this->endDate->TabIndex = 4;
			this->endDate->Text = L"mm/dd/yyyy";
			// 
			// startDate
			// 
			this->startDate->Font = (gcnew System::Drawing::Font(L"Rockwell Condensed", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->startDate->Location = System::Drawing::Point(128, 254);
			this->startDate->Name = L"startDate";
			this->startDate->ReadOnly = true;
			this->startDate->Size = System::Drawing::Size(100, 35);
			this->startDate->TabIndex = 3;
			this->startDate->Text = L"mm/dd/yyyy";
			// 
			// calendar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(350, 350);
			this->Controls->Add(this->panel1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
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

};
}
