#pragma once
#include <iostream>
#include <string>
#include "NNetwork.h"
#include "Reader.h"
#include <msclr/marshal_cppstd.h>
#include <vector>

using namespace std;

namespace NNetworkGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		NNetwork* net = nullptr;
		Reader* rea = new Reader();
		int inputSize = 0;
		int outputSize = 0;
		int maxHeightNeuron = 0;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;

		   vector<int>* layers = new vector<int>();

	public:
		MyForm(void)
		{
			InitializeComponent();
			initializeTab();
			this->chart1->Series["Epochs"]->Color = System::Drawing::Color::DeepSkyBlue;
			this->chart1->Series["Epochs"]->BorderWidth = 3;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			delete net;
			net = nullptr;
			delete rea;
			rea = nullptr;
			delete layers;
			layers = nullptr;
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			this->chart1->BackColor = System::Drawing::Color::Transparent;
			this->chart1->BorderlineColor = System::Drawing::Color::Transparent;
			this->chart1->BorderSkin->BackColor = System::Drawing::Color::Black;
			this->chart1->BorderSkin->BorderWidth = 10;
			chartArea1->AxisX->Title = L"Epochy";
			chartArea1->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			chartArea1->AxisY->Title = L"MSE";
			chartArea1->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			chartArea1->Name = L"ChartArea1";
			chartArea1->ShadowColor = System::Drawing::Color::LightGray;
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Enabled = false;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(395, 4);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->IsVisibleInLegend = false;
			series1->Legend = L"Legend1";
			series1->Name = L"Epochs";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(783, 587);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(13, 109);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(306, 33);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(12, 176);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(307, 33);
			this->textBox2->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(9, 86);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(170, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Tréningové vstupné dáta";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(9, 153);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(139, 20);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Tréningové výsledky";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 12);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(253, 65);
			this->label3->TabIndex = 5;
			this->label3->Text = L"ClimaBike";
			// 
			// trackBar1
			// 
			this->trackBar1->BackColor = System::Drawing::Color::DimGray;
			this->trackBar1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar1->Location = System::Drawing::Point(13, 250);
			this->trackBar1->Maximum = 1000;
			this->trackBar1->Minimum = 10;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(306, 45);
			this->trackBar1->TabIndex = 6;
			this->trackBar1->Value = 10;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(9, 227);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(97, 20);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Počet epôch :";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(112, 227);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(27, 20);
			this->label5->TabIndex = 8;
			this->label5->Text = L"10";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::DeepSkyBlue;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DodgerBlue;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(12, 301);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(127, 49);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Pridaj skrytú vrstvu";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::DarkGray;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->Location = System::Drawing::Point(12, 407);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->Size = System::Drawing::Size(240, 204);
			this->dataGridView1->TabIndex = 10;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::DeepSkyBlue;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DodgerBlue;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(343, 109);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(46, 287);
			this->button2->TabIndex = 11;
			this->button2->Text = L"N\r\na\r\nč\r\ní\r\nt\r\na\r\nj\r\n \r\nd\r\ná\r\nt\r\na";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->button3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(258, 407);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(61, 204);
			this->button3->TabIndex = 12;
			this->button3->Text = L"T\r\nR\r\nÉ\r\nN\r\nU\r\nJ";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Tomato;
			this->button4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(201, 301);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(118, 49);
			this->button4->TabIndex = 13;
			this->button4->Text = L"Inicializuj";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->BackColor = System::Drawing::Color::AliceBlue;
			this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numericUpDown1->Location = System::Drawing::Point(146, 301);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(49, 46);
			this->numericUpDown1->TabIndex = 14;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(259, 357);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(60, 39);
			this->textBox3->TabIndex = 15;
			// 
			// progressBar1
			// 
			this->progressBar1->BackColor = System::Drawing::Color::LightGray;
			this->progressBar1->ForeColor = System::Drawing::Color::Cyan;
			this->progressBar1->Location = System::Drawing::Point(343, 597);
			this->progressBar1->Maximum = 1000;
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(714, 14);
			this->progressBar1->Step = 1;
			this->progressBar1->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->progressBar1->TabIndex = 16;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(178)));
			this->label6->Location = System::Drawing::Point(2, 357);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(251, 40);
			this->label6->TabIndex = 17;
			this->label6->Text = L"Rýchlosť učenia :";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Lime;
			this->label7->Location = System::Drawing::Point(1063, 591);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(0, 21);
			this->label7->TabIndex = 18;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1177, 633);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->chart1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"ClimaBike";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		private: void initializeTab() {
			dataGridView1->Columns->Add("Column", "Vrstva");
			dataGridView1->Columns->Add("Column", "Pocet Neuronov");
		}
		private: bool checkAbilityToInitialize() {
			return (rea->getDReaded() && rea->getRReaded()&&layers->size() > 0/* && (int)trackBar1->Value > 0.0)*/) ? 1 : 0;
		}
		private: void setTable() {
			dataGridView1->Rows->Clear();
			//dataGridView1->Columns->Clear();
			dataGridView1->Refresh();
			//initializeTab();
			/*if (rea->getRReaded()) {
				dataGridView1->Rows->Add();
				dataGridView1->Rows[0]->Cells[0]->Value = gcnew String("Vystupna");
				dataGridView1->Rows[0]->Cells[1]->Value = gcnew String(to_string(outputSize).c_str());
			}*/
			int var = 1;
			for (int i = 0; i < layers->size(); i++) {
				dataGridView1->Rows->Add();
				string v = "Vrstva " + to_string(var);
				dataGridView1->Rows[dataGridView1->RowCount - 1]->Cells[0]->Value = gcnew String(v.c_str());
				dataGridView1->Rows[dataGridView1->RowCount - 1]->Cells[1]->Value = gcnew String(to_string(layers->at(i)).c_str());
				var++;
			}
			/*if (rea->getDReaded()) {
				dataGridView1->Rows->Add();
				dataGridView1->Rows[0]->Cells[0]->Value = gcnew String("Vstupna");			
				dataGridView1->Rows[0]->Cells[1]->Value = gcnew String(to_string(inputSize).c_str());
			}*/
			
		}

		private: void updateIniButton(){
			if (checkAbilityToInitialize()) {
				button4->BackColor = BackColor.Lime;
			}
			else {
				button4->BackColor = BackColor.Tomato;
			}
		}
		private: void fillChart(float error) {
			chart1->Series["Epochs"]->Points->AddY(error);
			chart1->Refresh();
		}
		/*private: void drawNet() {
			int minPosX = 340;
			int minPosY = 340;
			int maxPosX = 1360;
			int maxPosY = 750;
			int neuronSize = 50;
			int spaceX = 50;
			int spaceY = 10;
			if ((maxPosX - minPosX) / maxHeightNeuron < (maxPosY - minPosY) / maxHeightNeuron) {
				neuronSize = (((maxPosX - minPosX) / (maxHeightNeuron +2))) * 1;
				spaceX = ((maxPosX - minPosX) / (maxHeightNeuron)) * 0.2;
				spaceY = ((maxPosX - minPosX) / (maxHeightNeuron )) * 0.2;
			}
			else {
				neuronSize = ((maxPosY - minPosY) / (maxHeightNeuron +2)) * 1;
				spaceX = ((maxPosY - minPosY) / (maxHeightNeuron )) * 0.2;
				spaceY = ((maxPosY - minPosY) / (maxHeightNeuron )) * 0.2;
			}
		
			auto vAct = net->getActivations();
			auto vWei = net->getWeights();
			minPosX += 50 / 2;
			minPosY += 50 / 2;
		
			Graphics^ g = this->CreateGraphics();			
			for (int i = 0; i < vAct.size(); i++) {
				for (int j = 0; j < vAct.at(i).size(); j++) {
					//g->DrawEllipse(Pens::Red, minPosX + j * (spaceX + neuronSize) , i * (spaceY + neuronSize) + minPosY, neuronSize, neuronSize);
					SolidBrush^ v = gcnew SolidBrush(Color::DeepSkyBlue);
					int centerX = (minPosX + j * (spaceX + neuronSize/2)) - (neuronSize/2);
					int centerY = (minPosY + i * (spaceY + neuronSize/2)) - (neuronSize/2);
					g->FillEllipse(v,centerX,centerY,	neuronSize * (vAct.at(i).at(j) + 0.3), neuronSize * (vAct.at(i).at(j) + 0.3));
				}
			}		
			
		}
			  */

#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
	label5->Text = gcnew String(to_string(trackBar1->Value).c_str());
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!rea->getDReaded()) {
		String^ trainDataInputs = textBox1->Text;
		if (trainDataInputs->Length != 0) {
			std::string convertedInputs = msclr::interop::marshal_as< std::string >(trainDataInputs);
			rea->readCsv(convertedInputs, true);
			textBox1->BackColor = BackColor.Lime;
			textBox1->Text = "Data Nacítané.";
			//layers->push_back(rea->getData().at(0).size());	
			inputSize = rea->getData().at(0).size();			
		}
		else {
			textBox1->BackColor = BackColor.Tomato;
		}
	}
	if (!rea->getRReaded()) {
		String^ trainDataOutputs = textBox2->Text;
		if (trainDataOutputs->Length != 0) {
			std::string convertedOutputs = msclr::interop::marshal_as< std::string >(trainDataOutputs);
			rea->readCsv(convertedOutputs, false);
			textBox2->BackColor = BackColor.Lime;
			textBox2->Text = "Data Nacítané.";
			//layers->push_back(rea->getResults().at(0).size());
			outputSize = rea->getResults().at(0).size();			
		}
		else {
			textBox2->BackColor = BackColor.Tomato;
		}
	}
	updateIniButton();
	setTable();
}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { // Pridaj vrstvu
	layers->push_back((int)numericUpDown1->Value);
	updateIniButton();
	setTable();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) { // Trenuj
	std::string lRVar = msclr::interop::marshal_as< std::string >(textBox3->Text);
	if (!checkAbilityToInitialize() || !net || lRVar.empty()) {
		return;
	}
	label7->Text = gcnew String("Ucim sa!");
	label7->Refresh();
	float learningRate = stof(lRVar);
	int epochs = (int)trackBar1->Value;
	progressBar1->Maximum = epochs-1;
	for (int i = 0; i < epochs; i++) {
		float error = 0;
		
		for (int j = 0; j < rea->getData().size(); j++) {
			net->setData(rea->getData().at(j), rea->getResults().at(j));
			net->feedForward();
			net->backProp(learningRate);
			error += net->calculateSumError();
		}
		float v = error / (rea->getData().size() * rea->getResults().at(0).size()); 
		//cout << v << endl;		 
		if (i != 0) { fillChart(v); }
		rea->shuffle();
		progressBar1->Value = i;
		//drawNet();
	}
	label7->Text = gcnew String("Uz viem!");
	label7->Refresh();
}

private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) { // Inicializuj
	if (checkAbilityToInitialize()) {
		vector<int> la;
		int in = inputSize;
		la.push_back(in);
		for (int i = 0; i < layers->size(); i++) {
			la.push_back(layers->at(i));
		}
		in = outputSize;
		la.push_back(in);
		net = new NNetwork(la);
		net->initializeNNetworkwork();
		for (int i = 0; i < layers->size(); i++) {
			if (maxHeightNeuron < layers->at(i))
				{ maxHeightNeuron = layers->at(i); }
		}
		if (maxHeightNeuron < layers->size()) {
			maxHeightNeuron = layers->size();
		}
		//drawNet();	
	}	
	
	
}

};
}
