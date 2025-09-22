#pragma once
#include "FilteredResultsForm.h"
#include "GlobalSettings.h"

#include <msclr/marshal.h>
#include <stdlib.h>
#include <string.h>

namespace EdProgs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::IO; // Для Path и File
	using namespace System::Diagnostics; // Для Process

	using namespace System::Data::OleDb;
	
	//	using namespace System::Data::OleDb::Command;

		/// <summary>
		/// Сводка для ProgsList
		/// </summary>
	public ref class ProgsList : public System::Windows::Forms::Form
	{
	private:   OleDbConnection^ connection; // Объявляем переменную для подключения к базе данных

	public:
		ProgsList(void)
		{
			InitializeComponent();
			// Инициализация адаптеров
			this->adapterDiscipline = gcnew OleDbDataAdapter();
			this->adapterDetails = gcnew OleDbDataAdapter();

			// Инициализация DataSet и таблиц
			this->dataSet1 = gcnew DataSet();
			this->dataTable = gcnew DataTable();

			// Инициализация BindingSource
			this->bindingSource1 = gcnew BindingSource();
			this->bindingSource1->DataSource = this->dataSet1;


			// Включение полного выделения строки
			this->dataGridView1->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
			// Отключение стандартного выделения
			this->dataGridView1->RowHeadersVisible = false;
			// Настройка цвета выделения по умолчанию
			this->dataGridView1->DefaultCellStyle->SelectionBackColor = Color::LightSalmon;

			// Кнопка "Фильтровать"
			this->buttonFilter->Click += gcnew System::EventHandler(this, &ProgsList::buttonFilter_Click);
			
			this->bindingSource1->PositionChanged += gcnew EventHandler(this, &ProgsList::bindingSource1_PositionChanged);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ProgsList()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Data::OleDb::OleDbDataAdapter^ adapterDiscipline;
	private: System::Data::OleDb::OleDbDataAdapter^ adapterDetails;
	private: System::Data::OleDb::OleDbDataAdapter^ adapter; // DataAdapter для работы с базой данных
	private: System::Data::DataSet^ dataSet1;
	private: System::Data::DataTable^ dataTable; // DataTable для хранения данных
	private: System::Windows::Forms::BindingSource^ bindingSource1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ textBoxYear;
	private: System::Windows::Forms::BindingNavigator^ bindingNavigator1;

	private: System::Windows::Forms::ToolStripLabel^ bindingNavigatorCountItem;

	private: System::Windows::Forms::ToolStripButton^ bindingNavigatorMoveFirstItem;
	private: System::Windows::Forms::ToolStripButton^ bindingNavigatorMovePreviousItem;
	private: System::Windows::Forms::ToolStripSeparator^ bindingNavigatorSeparator;
	private: System::Windows::Forms::ToolStripTextBox^ bindingNavigatorPositionItem;
	private: System::Windows::Forms::ToolStripSeparator^ bindingNavigatorSeparator1;
	private: System::Windows::Forms::ToolStripButton^ bindingNavigatorMoveNextItem;
	private: System::Windows::Forms::ToolStripButton^ bindingNavigatorMoveLastItem;
	private: System::Windows::Forms::ToolStripSeparator^ bindingNavigatorSeparator2;
	private: System::Windows::Forms::ToolStripButton^ bindingNavigatorWord;
	private: System::Windows::Forms::Button^ buttonFilter;

	private: System::Windows::Forms::Button^ HomePage;
	private: System::ComponentModel::IContainer^ components;




		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ProgsList::typeid));
			   this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
			   this->dataSet1 = (gcnew System::Data::DataSet());
			   this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->buttonFilter = (gcnew System::Windows::Forms::Button());
			   this->textBoxYear = (gcnew System::Windows::Forms::TextBox());
			   this->bindingNavigator1 = (gcnew System::Windows::Forms::BindingNavigator(this->components));
			   this->bindingNavigatorCountItem = (gcnew System::Windows::Forms::ToolStripLabel());
			   this->bindingNavigatorMoveFirstItem = (gcnew System::Windows::Forms::ToolStripButton());
			   this->bindingNavigatorMovePreviousItem = (gcnew System::Windows::Forms::ToolStripButton());
			   this->bindingNavigatorSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
			   this->bindingNavigatorPositionItem = (gcnew System::Windows::Forms::ToolStripTextBox());
			   this->bindingNavigatorSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			   this->bindingNavigatorMoveNextItem = (gcnew System::Windows::Forms::ToolStripButton());
			   this->bindingNavigatorMoveLastItem = (gcnew System::Windows::Forms::ToolStripButton());
			   this->bindingNavigatorSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			   this->bindingNavigatorWord = (gcnew System::Windows::Forms::ToolStripButton());
			   this->HomePage = (gcnew System::Windows::Forms::Button());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet1))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			   this->panel1->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingNavigator1))->BeginInit();
			   this->bindingNavigator1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // bindingSource1
			   // 
			   this->bindingSource1->DataSource = this->dataSet1;
			   this->bindingSource1->Position = 0;
			   // 
			   // dataSet1
			   // 
			   this->dataSet1->DataSetName = L"NewDataSet";
			   // 
			   // dataGridView1
			   // 
			   this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->dataGridView1->AutoGenerateColumns = false;
			   this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			   this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			   this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::Window;
			   this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView1->DataSource = this->bindingSource1;
			   this->dataGridView1->Location = System::Drawing::Point(42, 112);
			   this->dataGridView1->Name = L"dataGridView1";
			   this->dataGridView1->RowHeadersWidth = 62;
			   this->dataGridView1->Size = System::Drawing::Size(1100, 449);
			   this->dataGridView1->TabIndex = 2;
			   this->dataGridView1->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ProgsList::dataGridView1_CellDoubleClick);
			   // 
			   // panel1
			   // 
			   this->panel1->AutoSize = true;
			   this->panel1->Controls->Add(this->buttonFilter);
			   this->panel1->Controls->Add(this->textBoxYear);
			   this->panel1->Controls->Add(this->bindingNavigator1);
			   this->panel1->Location = System::Drawing::Point(10, 8);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(1266, 78);
			   this->panel1->TabIndex = 3;
			   // 
			   // buttonFilter
			   // 
			   this->buttonFilter->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			   this->buttonFilter->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				   static_cast<System::Int32>(static_cast<System::Byte>(255)));
			   this->buttonFilter->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->buttonFilter->Location = System::Drawing::Point(872, 25);
			   this->buttonFilter->Name = L"buttonFilter";
			   this->buttonFilter->Size = System::Drawing::Size(130, 33);
			   this->buttonFilter->TabIndex = 3;
			   this->buttonFilter->Text = L"Фильтровать";
			   this->buttonFilter->UseVisualStyleBackColor = false;
			   // 
			   // textBoxYear
			   // 
			   this->textBoxYear->BackColor = System::Drawing::Color::White;
			   this->textBoxYear->Font = (gcnew System::Drawing::Font(L"Arial", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textBoxYear->Location = System::Drawing::Point(792, 26);
			   this->textBoxYear->Multiline = true;
			   this->textBoxYear->Name = L"textBoxYear";
			   this->textBoxYear->Size = System::Drawing::Size(67, 30);
			   this->textBoxYear->TabIndex = 3;
			   this->textBoxYear->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			   // 
			   // bindingNavigator1
			   // 
			   this->bindingNavigator1->AddNewItem = nullptr;
			   this->bindingNavigator1->BackColor = System::Drawing::Color::Transparent;
			   this->bindingNavigator1->CountItem = this->bindingNavigatorCountItem;
			   this->bindingNavigator1->DeleteItem = nullptr;
			   this->bindingNavigator1->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->bindingNavigator1->ImageScalingSize = System::Drawing::Size(24, 24);
			   this->bindingNavigator1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {
				   this->bindingNavigatorMoveFirstItem,
					   this->bindingNavigatorMovePreviousItem, this->bindingNavigatorSeparator, this->bindingNavigatorPositionItem, this->bindingNavigatorCountItem,
					   this->bindingNavigatorSeparator1, this->bindingNavigatorMoveNextItem, this->bindingNavigatorMoveLastItem, this->bindingNavigatorSeparator2,
					   this->bindingNavigatorWord
			   });
			   this->bindingNavigator1->Location = System::Drawing::Point(0, 0);
			   this->bindingNavigator1->MoveFirstItem = this->bindingNavigatorMoveFirstItem;
			   this->bindingNavigator1->MoveLastItem = this->bindingNavigatorMoveLastItem;
			   this->bindingNavigator1->MoveNextItem = this->bindingNavigatorMoveNextItem;
			   this->bindingNavigator1->MovePreviousItem = this->bindingNavigatorMovePreviousItem;
			   this->bindingNavigator1->Name = L"bindingNavigator1";
			   this->bindingNavigator1->Padding = System::Windows::Forms::Padding(0, 0, 3, 0);
			   this->bindingNavigator1->PositionItem = this->bindingNavigatorPositionItem;
			   this->bindingNavigator1->Size = System::Drawing::Size(1266, 78);
			   this->bindingNavigator1->Stretch = true;
			   this->bindingNavigator1->TabIndex = 2;
			   this->bindingNavigator1->Text = L"bindingNavigator1";
			   // 
			   // bindingNavigatorCountItem
			   // 
			   this->bindingNavigatorCountItem->Name = L"bindingNavigatorCountItem";
			   this->bindingNavigatorCountItem->Size = System::Drawing::Size(65, 73);
			   this->bindingNavigatorCountItem->Text = L"для {0}";
			   this->bindingNavigatorCountItem->ToolTipText = L"Общее число элементов";
			   // 
			   // bindingNavigatorMoveFirstItem
			   // 
			   this->bindingNavigatorMoveFirstItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			   this->bindingNavigatorMoveFirstItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bindingNavigatorMoveFirstItem.Image")));
			   this->bindingNavigatorMoveFirstItem->Name = L"bindingNavigatorMoveFirstItem";
			   this->bindingNavigatorMoveFirstItem->RightToLeftAutoMirrorImage = true;
			   this->bindingNavigatorMoveFirstItem->Size = System::Drawing::Size(34, 73);
			   this->bindingNavigatorMoveFirstItem->Text = L"Переместить в начало";
			   // 
			   // bindingNavigatorMovePreviousItem
			   // 
			   this->bindingNavigatorMovePreviousItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			   this->bindingNavigatorMovePreviousItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bindingNavigatorMovePreviousItem.Image")));
			   this->bindingNavigatorMovePreviousItem->Name = L"bindingNavigatorMovePreviousItem";
			   this->bindingNavigatorMovePreviousItem->RightToLeftAutoMirrorImage = true;
			   this->bindingNavigatorMovePreviousItem->Size = System::Drawing::Size(34, 73);
			   this->bindingNavigatorMovePreviousItem->Text = L"Переместить назад";
			   // 
			   // bindingNavigatorSeparator
			   // 
			   this->bindingNavigatorSeparator->Name = L"bindingNavigatorSeparator";
			   this->bindingNavigatorSeparator->Size = System::Drawing::Size(6, 78);
			   // 
			   // bindingNavigatorPositionItem
			   // 
			   this->bindingNavigatorPositionItem->AccessibleName = L"Положение";
			   this->bindingNavigatorPositionItem->AutoSize = false;
			   this->bindingNavigatorPositionItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			   this->bindingNavigatorPositionItem->Name = L"bindingNavigatorPositionItem";
			   this->bindingNavigatorPositionItem->Size = System::Drawing::Size(50, 31);
			   this->bindingNavigatorPositionItem->Text = L"0";
			   this->bindingNavigatorPositionItem->ToolTipText = L"Текущее положение";
			   // 
			   // bindingNavigatorSeparator1
			   // 
			   this->bindingNavigatorSeparator1->Name = L"bindingNavigatorSeparator1";
			   this->bindingNavigatorSeparator1->Size = System::Drawing::Size(6, 78);
			   // 
			   // bindingNavigatorMoveNextItem
			   // 
			   this->bindingNavigatorMoveNextItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			   this->bindingNavigatorMoveNextItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bindingNavigatorMoveNextItem.Image")));
			   this->bindingNavigatorMoveNextItem->Name = L"bindingNavigatorMoveNextItem";
			   this->bindingNavigatorMoveNextItem->RightToLeftAutoMirrorImage = true;
			   this->bindingNavigatorMoveNextItem->Size = System::Drawing::Size(34, 73);
			   this->bindingNavigatorMoveNextItem->Text = L"Переместить вперед";
			   // 
			   // bindingNavigatorMoveLastItem
			   // 
			   this->bindingNavigatorMoveLastItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			   this->bindingNavigatorMoveLastItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bindingNavigatorMoveLastItem.Image")));
			   this->bindingNavigatorMoveLastItem->Name = L"bindingNavigatorMoveLastItem";
			   this->bindingNavigatorMoveLastItem->RightToLeftAutoMirrorImage = true;
			   this->bindingNavigatorMoveLastItem->Size = System::Drawing::Size(34, 73);
			   this->bindingNavigatorMoveLastItem->Text = L"Переместить в конец";
			   // 
			   // bindingNavigatorSeparator2
			   // 
			   this->bindingNavigatorSeparator2->Name = L"bindingNavigatorSeparator2";
			   this->bindingNavigatorSeparator2->Size = System::Drawing::Size(6, 78);
			   // 
			   // bindingNavigatorWord
			   // 
			   this->bindingNavigatorWord->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			   this->bindingNavigatorWord->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bindingNavigatorWord.Image")));
			   this->bindingNavigatorWord->ImageTransparentColor = System::Drawing::Color::Magenta;
			   this->bindingNavigatorWord->Name = L"bindingNavigatorWord";
			   this->bindingNavigatorWord->Size = System::Drawing::Size(34, 73);
			   this->bindingNavigatorWord->Text = L"Открыть файл";
			   this->bindingNavigatorWord->Click += gcnew System::EventHandler(this, &ProgsList::bindingNavigatorWord_Click);
			   // 
			   // HomePage
			   // 
			   this->HomePage->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				   static_cast<System::Int32>(static_cast<System::Byte>(255)));
			   this->HomePage->Cursor = System::Windows::Forms::Cursors::Default;
			   this->HomePage->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->HomePage->Location = System::Drawing::Point(1107, 595);
			   this->HomePage->Name = L"HomePage";
			   this->HomePage->Size = System::Drawing::Size(130, 30);
			   this->HomePage->TabIndex = 6;
			   this->HomePage->Text = L"Назад";
			   this->HomePage->UseVisualStyleBackColor = false;
			   this->HomePage->Click += gcnew System::EventHandler(this, &ProgsList::HomePage_Click);
			   // 
			   // ProgsList
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 20);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->AutoSize = true;
			   this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			   this->BackColor = System::Drawing::Color::Lavender;
			   this->ClientSize = System::Drawing::Size(1189, 638);
			   this->Controls->Add(this->HomePage);
			   this->Controls->Add(this->panel1);
			   this->Controls->Add(this->dataGridView1);
			   this->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->Name = L"ProgsList";
			   this->Padding = System::Windows::Forms::Padding(10);
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Список всех записей";
			   this->Shown += gcnew System::EventHandler(this, &ProgsList::ProgsList_Load);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet1))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingNavigator1))->EndInit();
			   this->bindingNavigator1->ResumeLayout(false);
			   this->bindingNavigator1->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }

		  private: System::Void bindingSource1_PositionChanged(System::Object^ sender, System::EventArgs^ e)
		  {
			  try
			  {
				  // Снимаем выделение со всех строк
				  this->dataGridView1->ClearSelection();

				  // Проверяем, что позиция в допустимых пределах
				  if (this->bindingSource1->Position >= 0 &&
					  this->bindingSource1->Position < this->bindingSource1->Count)
				  {
					  int rowIndex = this->bindingSource1->Position;

					  // Проверяем, что строка существует в DataGridView
					  if (rowIndex >= 0 && rowIndex < this->dataGridView1->Rows->Count)
					  {
						  // Выделяем строку
						  this->dataGridView1->Rows[rowIndex]->Selected = true;

						  // Устанавливаем цвет выделения
						  this->dataGridView1->Rows[rowIndex]->DefaultCellStyle->SelectionBackColor = Color::LightSalmon;

						  // Прокручиваем к выделенной строке
						  if (!this->dataGridView1->Rows[rowIndex]->Displayed)
						  {
							  this->dataGridView1->FirstDisplayedScrollingRowIndex = rowIndex;
						  }
					  }
				  }
			  }
			  catch (Exception^ ex)
			  {
				  // Можно добавить логирование ошибки
				  Debug::WriteLine("Ошибка в bindingSource1_PositionChanged: " + ex->Message);
			  }

			  // Получаем DataRowView из BindingSource
			  DataRowView^ rowView = (DataRowView^)this->bindingSource1->Current;

			  // Находим соответствующую строку в DataGridView
			  for each (DataGridViewRow ^ row in this->dataGridView1->Rows)
			  {
				  if (row->DataBoundItem == rowView)
				  {
					  row->Selected = true;
					  row->DefaultCellStyle->SelectionBackColor = Color::LightSalmon;
					  this->dataGridView1->FirstDisplayedScrollingRowIndex = row->Index;
					  break;
				  }
			  }
		  }

	private: System::Void ProgsList_Load(System::Object^ sender, System::EventArgs^ e) {
		try {
			
			EdProgs::String^ connectionString = GetConnectionString();

			// Подключение к базе данных
			OleDbConnection^ connection = gcnew OleDbConnection(connectionString);

			// Инициализация адаптеров
			this->adapterDiscipline = gcnew OleDbDataAdapter("SELECT * FROM Discipline", connection);
			this->adapterDetails = gcnew OleDbDataAdapter("SELECT * FROM DisciplineDetails", connection);

			// Инициализация DataSet
			this->dataSet1 = gcnew DataSet();

			// Заполнение таблиц данными
			this->adapterDiscipline->Fill(this->dataSet1, "Discipline");
			this->adapterDetails->Fill(this->dataSet1, "DisciplineDetails");

			// Создание DataTable для объединенных данных
			DataTable^ dataTable = gcnew DataTable();

			// Запрос для выборки данных
			String^ selectQuery = "SELECT Discipline.Name, DisciplineDetails.Standard, DisciplineDetails.ApprovalDate, DisciplineDetails.LifeSpan, DisciplineDetails.QntHours, DisciplineDetails.QntAudHours, DisciplineDetails.DocName FROM Discipline INNER JOIN DisciplineDetails ON Discipline.Id = DisciplineDetails.IdDiscipline";

			// DataAdapter для выполнения запроса
			OleDbDataAdapter^ adapter = gcnew OleDbDataAdapter(selectQuery, connection);

			// Заполнение DataTable данными из базы
			adapter->Fill(dataTable);

			// Добавление нового столбца DieDate в DataTable
			DataColumn^ dieDateColumn = gcnew DataColumn("DieDate", System::DateTime::typeid);
			dataTable->Columns->Add(dieDateColumn);

			// Вычисление значения для DieDate на основе LifeSpan и ApprovalDate
			for each (DataRow ^ row in dataTable->Rows)
			{
				int lifeSpan = Convert::ToInt32(row["LifeSpan"]);
				if (lifeSpan == 0) continue;
				DateTime approvalDate = Convert::ToDateTime(row["ApprovalDate"]);
				DateTime dieDate = approvalDate.AddYears(lifeSpan); // Добавляем LifeSpan лет к ApprovalDate
				row["DieDate"] = dieDate; // Записываем вычисленное значение в столбец DieDate
			}

			// Привязка DataTable к DataGridView
			this->dataGridView1->DataSource = dataTable;

			// Свяжите BindingSource с DataTable
			bindingSource1->DataSource = dataTable;

			// Свяжите BindingNavigator с BindingSource
			bindingNavigator1->BindingSource = bindingSource1;

			/*
				Отрисовка таблицы
			*/

			
			if (dataGridView1->Columns->IndexOf(dataGridView1->Columns[""]) == -1) {
				DataGridViewCheckBoxColumn^ checkBoxColumn = gcnew DataGridViewCheckBoxColumn();

				checkBoxColumn->FalseValue = false;
				checkBoxColumn->TrueValue = true;
				this->dataGridView1->Columns->Add(checkBoxColumn);
				this->dataGridView1->RowHeadersVisible = false;
				this->dataGridView1->AllowUserToAddRows = false;

				this->dataGridView1->AutoGenerateColumns = true;
				this->dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;

				this->dataGridView1->DefaultCellStyle->Font = gcnew System::Drawing::Font("Baskerville Old Face", 10);

				// Заголовки столбцов
				this->dataGridView1->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font("Baskerville Old Face", 11, FontStyle::Bold);

				// Чередующиеся цвета строк		
				this->dataGridView1->RowsDefaultCellStyle->BackColor = Color::White;
				this->dataGridView1->AlternatingRowsDefaultCellStyle->BackColor = Color::LightBlue;
				this->dataGridView1->ClearSelection(); // снять выделение

			}

			// Закрытие соединения с базой данных
			connection->Close();

		}
		catch (Exception^ ex) {
			MessageBox::Show("Ошибка при загрузке данных: " + ex->Message);
		}
	}


		   private: System::Void buttonFilter_Click(System::Object^ sender, System::EventArgs^ e) {
			   String^ year = this->textBoxYear->Text;

			   if (String::IsNullOrEmpty(year)) {
				   MessageBox::Show("Введите год!");
				   return;
			   }

			   DataTable^ filteredData = FilterDataByYear(year);

			   if (filteredData->Rows->Count > 0) {
				   // Передаем год в конструктор формы
				   FilteredResultsForm^ resultsForm = gcnew FilteredResultsForm(filteredData, year);
				   resultsForm->Show();
			   }
			   else {
				   MessageBox::Show("Записи за указанный год не найдены.");
			   }
		   }

	
	private: DataTable^ FilterDataByYear(String^ year) {

		EdProgs::String^ connectionString = GetConnectionString();

		try {
			// Подключение к базе данных
			OleDbConnection^ connection = gcnew OleDbConnection(connectionString);

			// SQL-запрос (без DieDate, так как его нет в базе)
			String^ selectQuery = "SELECT Discipline.Name, DisciplineDetails.Standard, DisciplineDetails.ApprovalDate, DisciplineDetails.LifeSpan, DisciplineDetails.QntHours, DisciplineDetails.QntAudHours, DisciplineDetails.DocName FROM Discipline INNER JOIN DisciplineDetails ON Discipline.Id = DisciplineDetails.IdDiscipline";

			// DataAdapter для выполнения запроса
			OleDbDataAdapter^ adapter = gcnew OleDbDataAdapter(selectQuery, connection);

			// Заполнение DataTable данными из базы
			DataTable^ dataTable = gcnew DataTable();
			adapter->Fill(dataTable);

			// Закрытие соединения с базой данных
			connection->Close();

			// Добавление нового столбца DieDate в DataTable
			DataColumn^ dieDateColumn = gcnew DataColumn("DieDate", System::DateTime::typeid);
			dataTable->Columns->Add(dieDateColumn);

			// Вычисление значения для DieDate на основе LifeSpan и ApprovalDate
			for each (DataRow ^ row in dataTable->Rows)
			{
				int lifeSpan = Convert::ToInt32(row["LifeSpan"]);
				DateTime approvalDate = Convert::ToDateTime(row["ApprovalDate"]);
				DateTime dieDate = approvalDate.AddYears(lifeSpan); // Добавляем LifeSpan лет к ApprovalDate
				row["DieDate"] = dieDate; // Записываем вычисленное значение в столбец DieDate
			}

			// Фильтрация данных по году (после вычисления DieDate)
			DataTable^ filteredTable = dataTable->Clone(); // Создаем копию структуры DataTable
			for each (DataRow ^ row in dataTable->Rows)
			{
				DateTime dieDate = Convert::ToDateTime(row["DieDate"]);
				if (dieDate.Year == Convert::ToInt32(year)) // Фильтруем по году
				{
					filteredTable->ImportRow(row); // Добавляем строку в отфильтрованную таблицу
				}
			}

			return filteredTable; // Возвращаем отфильтрованную таблицу
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ошибка: " + ex->Message);
			return gcnew DataTable(); // Возвращаем пустую таблицу в случае ошибки
		}
	}

private: System::Void bindingNavigatorWord_Click(System::Object^ sender, System::EventArgs^ e)
{

	try
	{
		// 1. Проверка наличия выбранной строки
		if (dataGridView1->CurrentRow == nullptr || dataGridView1->CurrentRow->IsNewRow)
		{
			MessageBox::Show("Выберите существующую запись с документом", "Ошибка выбора",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// 2. Проверка наличия значения в ячейке
		if (dataGridView1->CurrentRow->Cells["DocName"]->Value == nullptr)
		{
			MessageBox::Show("Документ не указан для выбранной записи", "Данные отсутствуют",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// 3. Получение имени файла
		String^ docName = dataGridView1->CurrentRow->Cells["DocName"]->Value->ToString();

		if (String::IsNullOrWhiteSpace(docName))
		{
			MessageBox::Show("Имя документа не может быть пустым", "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// 4. Формирование пути
		System::String^ documentsFolder = EdProgs::GetDocumentsFolder();

		String^ fullPath = Path::Combine(documentsFolder, docName);

		// 5. Проверка существования файла
		if (!File::Exists(fullPath))
		{
			MessageBox::Show("Файл не найден:\n" + fullPath, "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// 6. Попытка открытия файла
		try
		{
			ProcessStartInfo^ startInfo = gcnew ProcessStartInfo(fullPath);
			startInfo->UseShellExecute = true;
			Process::Start(startInfo);
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Не удалось открыть документ:\n" + ex->Message, "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Критическая ошибка:\n" + ex->Message, "Ошибка",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

	
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, DataGridViewCellEventArgs^ e) {
		try {
			// Проверяем, что клик не в заголовке и не в новой строке
			if (e->RowIndex >= 0 && e->ColumnIndex >= 0 &&
				dataGridView1->Columns[e->ColumnIndex]->Name == "CheckBoxColumn") {

				DataGridViewCheckBoxCell^ cell = dynamic_cast<DataGridViewCheckBoxCell^>(dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]);
				if (cell != nullptr) {
					// Переключаем состояние CheckBox
					cell->Value = cell->Value == nullptr ? true : !(bool)cell->Value;

					// Выделяем строку и устанавливаем цвет
					dataGridView1->Rows[e->RowIndex]->Selected = true;
					dataGridView1->Rows[e->RowIndex]->DefaultCellStyle->SelectionBackColor = Color::LightSalmon;

					// Обновляем отображение
					dataGridView1->InvalidateCell(cell);

					// Обновляем textBoxYear
					if ((bool)cell->Value && dataGridView1->Rows[e->RowIndex]->Cells["Id"]->Value != nullptr) {
						textBoxYear->Text = dataGridView1->Rows[e->RowIndex]->Cells["Id"]->Value->ToString();
					}
					else {
						textBoxYear->Text = "";
					}
				}
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ошибка в CellContentClick: " + ex->Message);
		}
	}

	private: System::Void dataGridView1_CellDoubleClick(System::Object^ sender, DataGridViewCellEventArgs^ e) {
		try {
			// Проверяем, что клик не в заголовке и не в новой строке
			if (e->RowIndex >= 0 && e->ColumnIndex >= 0) {
				DataGridViewRow^ row = dataGridView1->Rows[e->RowIndex];

				// Устанавливаем цвет выделения
				row->DefaultCellStyle->SelectionBackColor = Color::LightSalmon;
				row->Selected = true;

				// Отмечаем CheckBox
				DataGridViewCheckBoxCell^ cell = dynamic_cast<DataGridViewCheckBoxCell^>(row->Cells["CheckBoxColumn"]);
				if (cell != nullptr) {
					cell->Value = true;
					dataGridView1->InvalidateCell(cell);
				}
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ошибка в CellDoubleClick: " + ex->Message);
		}
	}

	private: System::Void HomePage_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};

}
