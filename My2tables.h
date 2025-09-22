#pragma once

#include <cliext/list> // Для List в C++/CLI

#include "AddDisc.h"
#include "EditDisc.h"
#include "AddStandard.h"
#include "EditStandard.h"
#include "GlobalSettings.h"

namespace EdProgs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::OleDb;
	using namespace System::Diagnostics;

	extern int DiscId;
	/// <summary>
	/// Сводка для My2tables
	/// </summary>
	public ref class My2tables : public System::Windows::Forms::Form
	{
	public:
		My2tables(void)
		{
			InitializeComponent();
			this->Load += gcnew System::EventHandler(this, &My2tables::My2tables_Load);
			System::Void comboBox1_SelectedIndexChanged();
			this->dataGridView1->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &My2tables::dataGridView1_CellDoubleClick);
			this->bindingSource1->PositionChanged += gcnew EventHandler(this, &My2tables::bindingSource1_PositionChanged);


			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~My2tables()
		{
			if (components)
			{
				delete components;
			}
			if (adapterDetails)
			{
				delete adapterDetails;
			}
			if (adapterDisciplines)
			{
				delete adapterDisciplines;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::BindingSource^ bindingSource1;
	private: System::Data::DataSet^ dataSet1;
	private: System::Data::DataSet^ dataSet2;
	private: System::Windows::Forms::BindingSource^ bindingSource2;
	private: System::Windows::Forms::BindingNavigator^ bindingNavigator1;
	private: System::Windows::Forms::ToolStripButton^ bindingNavigatorAddNewItem;
	private: System::Windows::Forms::ToolStripLabel^ bindingNavigatorCountItem;

	private: System::Windows::Forms::ToolStripButton^ bindingNavigatorMoveFirstItem;
	private: System::Windows::Forms::ToolStripButton^ bindingNavigatorMovePreviousItem;
	private: System::Windows::Forms::ToolStripSeparator^ bindingNavigatorSeparator;
	private: System::Windows::Forms::ToolStripTextBox^ bindingNavigatorPositionItem;
	private: System::Windows::Forms::ToolStripSeparator^ bindingNavigatorSeparator1;
	private: System::Windows::Forms::ToolStripButton^ bindingNavigatorMoveNextItem;
	private: System::Windows::Forms::ToolStripButton^ bindingNavigatorMoveLastItem;
	private: System::Windows::Forms::ToolStripSeparator^ bindingNavigatorSeparator2;
	private: System::ComponentModel::IContainer^ components; // 
	private: System::Data::DataTable^ dataTable1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ToolStripButton^ bindingNavigatorEditItem;

		   // Адаптер данных
		   OleDbDataAdapter^ adapterDetails;
	private: System::Windows::Forms::Button^ addDisc;
	private: System::Windows::Forms::Button^ delDics;
	private: System::Windows::Forms::Button^ editDisc;
	private: System::Windows::Forms::Button^ exit;
	private: System::Windows::Forms::ToolStripButton^ bindingNavigatorDeleteItem;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;

		   OleDbDataAdapter^ adapterDisciplines;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(My2tables::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->dataSet1 = (gcnew System::Data::DataSet());
			this->dataTable1 = (gcnew System::Data::DataTable());
			this->bindingNavigator1 = (gcnew System::Windows::Forms::BindingNavigator(this->components));
			this->bindingNavigatorAddNewItem = (gcnew System::Windows::Forms::ToolStripButton());
			this->bindingNavigatorCountItem = (gcnew System::Windows::Forms::ToolStripLabel());
			this->bindingNavigatorMoveFirstItem = (gcnew System::Windows::Forms::ToolStripButton());
			this->bindingNavigatorMovePreviousItem = (gcnew System::Windows::Forms::ToolStripButton());
			this->bindingNavigatorSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->bindingNavigatorPositionItem = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->bindingNavigatorSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->bindingNavigatorMoveNextItem = (gcnew System::Windows::Forms::ToolStripButton());
			this->bindingNavigatorMoveLastItem = (gcnew System::Windows::Forms::ToolStripButton());
			this->bindingNavigatorSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->bindingNavigatorEditItem = (gcnew System::Windows::Forms::ToolStripButton());
			this->bindingNavigatorDeleteItem = (gcnew System::Windows::Forms::ToolStripButton());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->bindingSource2 = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->dataSet2 = (gcnew System::Data::DataSet());
			this->addDisc = (gcnew System::Windows::Forms::Button());
			this->delDics = (gcnew System::Windows::Forms::Button());
			this->editDisc = (gcnew System::Windows::Forms::Button());
			this->exit = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataTable1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingNavigator1))->BeginInit();
			this->bindingNavigator1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet2))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			this->dataGridView1->AutoGenerateColumns = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::Window;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Cursor = System::Windows::Forms::Cursors::Default;
			this->dataGridView1->DataSource = this->bindingSource1;
			this->dataGridView1->Location = System::Drawing::Point(40, 118);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(1485, 408);
			this->dataGridView1->TabIndex = 0;
			this->bindingSource1->DataSource = this->dataSet1;
			this->bindingSource1->Position = 0;
			this->dataSet1->DataSetName = L"NewDataSet";
			this->dataSet1->Tables->AddRange(gcnew cli::array< System::Data::DataTable^  >(1) { this->dataTable1 });
			this->dataTable1->TableName = L"DisciplineDetails";
			this->bindingNavigator1->AddNewItem = this->bindingNavigatorAddNewItem;
			this->bindingNavigator1->BackColor = System::Drawing::Color::Transparent;
			this->bindingNavigator1->CountItem = this->bindingNavigatorCountItem;
			this->bindingNavigator1->DeleteItem = nullptr;
			this->bindingNavigator1->Dock = System::Windows::Forms::DockStyle::None;
			this->bindingNavigator1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->bindingNavigator1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(12) {
				this->bindingNavigatorMoveFirstItem,
					this->bindingNavigatorMovePreviousItem, this->bindingNavigatorSeparator, this->bindingNavigatorPositionItem, this->bindingNavigatorCountItem,
					this->bindingNavigatorSeparator1, this->bindingNavigatorMoveNextItem, this->bindingNavigatorMoveLastItem, this->bindingNavigatorSeparator2,
					this->bindingNavigatorAddNewItem, this->bindingNavigatorEditItem, this->bindingNavigatorDeleteItem
			});
			this->bindingNavigator1->Location = System::Drawing::Point(40, 65);
			this->bindingNavigator1->MoveFirstItem = this->bindingNavigatorMoveFirstItem;
			this->bindingNavigator1->MoveLastItem = this->bindingNavigatorMoveLastItem;
			this->bindingNavigator1->MoveNextItem = this->bindingNavigatorMoveNextItem;
			this->bindingNavigator1->MovePreviousItem = this->bindingNavigatorMovePreviousItem;
			this->bindingNavigator1->Name = L"bindingNavigator1";
			this->bindingNavigator1->Padding = System::Windows::Forms::Padding(0, 0, 3, 0);
			this->bindingNavigator1->PositionItem = this->bindingNavigatorPositionItem;
			this->bindingNavigator1->Size = System::Drawing::Size(394, 33);
			this->bindingNavigator1->TabIndex = 1;
			this->bindingNavigator1->Text = L"bindingNavigator1";
			this->bindingNavigatorAddNewItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->bindingNavigatorAddNewItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bindingNavigatorAddNewItem.Image")));
			this->bindingNavigatorAddNewItem->Name = L"bindingNavigatorAddNewItem";
			this->bindingNavigatorAddNewItem->Size = System::Drawing::Size(34, 28);
			this->bindingNavigatorAddNewItem->Text = L"Добавить";
			this->bindingNavigatorAddNewItem->Click += gcnew System::EventHandler(this, &My2tables::bindingNavigatorAddNewItem_Click);
			this->bindingNavigatorCountItem->Name = L"bindingNavigatorCountItem";
			this->bindingNavigatorCountItem->Size = System::Drawing::Size(65, 28);
			this->bindingNavigatorCountItem->Text = L"для {0}";
			this->bindingNavigatorCountItem->ToolTipText = L"Общее число элементов";
			this->bindingNavigatorMoveFirstItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->bindingNavigatorMoveFirstItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bindingNavigatorMoveFirstItem.Image")));
			this->bindingNavigatorMoveFirstItem->Name = L"bindingNavigatorMoveFirstItem";
			this->bindingNavigatorMoveFirstItem->Size = System::Drawing::Size(34, 28);
			this->bindingNavigatorMoveFirstItem->Text = L"Переместить в начало";
			this->bindingNavigatorMovePreviousItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->bindingNavigatorMovePreviousItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bindingNavigatorMovePreviousItem.Image")));
			this->bindingNavigatorMovePreviousItem->Name = L"bindingNavigatorMovePreviousItem";
			this->bindingNavigatorMovePreviousItem->Size = System::Drawing::Size(34, 28);
			this->bindingNavigatorMovePreviousItem->Text = L"Переместить назад";
			this->bindingNavigatorSeparator->Name = L"bindingNavigatorSeparator";
			this->bindingNavigatorSeparator->Size = System::Drawing::Size(6, 33);
			this->bindingNavigatorPositionItem->AccessibleName = L"Положение";
			this->bindingNavigatorPositionItem->AutoSize = false;
			this->bindingNavigatorPositionItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->bindingNavigatorPositionItem->Name = L"bindingNavigatorPositionItem";
			this->bindingNavigatorPositionItem->Size = System::Drawing::Size(50, 31);
			this->bindingNavigatorPositionItem->Text = L"0";
			this->bindingNavigatorPositionItem->ToolTipText = L"Текущее положение";
			this->bindingNavigatorSeparator1->Name = L"bindingNavigatorSeparator1";
			this->bindingNavigatorSeparator1->Size = System::Drawing::Size(6, 33);
			this->bindingNavigatorMoveNextItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->bindingNavigatorMoveNextItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bindingNavigatorMoveNextItem.Image")));
			this->bindingNavigatorMoveNextItem->Name = L"bindingNavigatorMoveNextItem";
			this->bindingNavigatorMoveNextItem->Size = System::Drawing::Size(34, 28);
			this->bindingNavigatorMoveNextItem->Text = L"Переместить вперед";
			this->bindingNavigatorMoveLastItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->bindingNavigatorMoveLastItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bindingNavigatorMoveLastItem.Image")));
			this->bindingNavigatorMoveLastItem->Name = L"bindingNavigatorMoveLastItem";
			this->bindingNavigatorMoveLastItem->Size = System::Drawing::Size(34, 28);
			this->bindingNavigatorMoveLastItem->Text = L"Переместить в конец";
			this->bindingNavigatorSeparator2->Name = L"bindingNavigatorSeparator2";
			this->bindingNavigatorSeparator2->Size = System::Drawing::Size(6, 33);
			this->bindingNavigatorEditItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->bindingNavigatorEditItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bindingNavigatorEditItem.Image")));
			this->bindingNavigatorEditItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->bindingNavigatorEditItem->Name = L"bindingNavigatorEditItem";
			this->bindingNavigatorEditItem->Size = System::Drawing::Size(34, 28);
			this->bindingNavigatorEditItem->Text = L"Редактировать";
			this->bindingNavigatorEditItem->Click += gcnew System::EventHandler(this, &My2tables::bindingNavigatorEditItem_Click);
			this->bindingNavigatorDeleteItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->bindingNavigatorDeleteItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bindingNavigatorDeleteItem.Image")));
			this->bindingNavigatorDeleteItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->bindingNavigatorDeleteItem->Name = L"bindingNavigatorDeleteItem";
			this->bindingNavigatorDeleteItem->Size = System::Drawing::Size(34, 28);
			this->bindingNavigatorDeleteItem->Text = L"toolStripButton1";
			this->bindingNavigatorDeleteItem->ToolTipText = L"Удалить";
			this->bindingNavigatorDeleteItem->Click += gcnew System::EventHandler(this, &My2tables::bindingNavigatorDeleteItem_Click);
			this->comboBox1->DataSource = this->bindingSource2;
			this->comboBox1->DropDownHeight = 200;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->IntegralHeight = false;
			this->comboBox1->Location = System::Drawing::Point(40, 45);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(379, 31);
			this->comboBox1->TabIndex = 2;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &My2tables::comboBox1_SelectedIndexChanged);
			this->bindingSource2->DataSource = this->dataSet2;
			this->bindingSource2->Position = 0;
			this->dataSet2->DataSetName = L"NewDataSet";
			this->addDisc->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->addDisc->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->addDisc->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->addDisc->Location = System::Drawing::Point(510, 38);
			this->addDisc->Name = L"addDisc";
			this->addDisc->Size = System::Drawing::Size(158, 40);
			this->addDisc->TabIndex = 3;
			this->addDisc->Text = L"Добавить";
			this->addDisc->UseVisualStyleBackColor = false;
			this->addDisc->Click += gcnew System::EventHandler(this, &My2tables::addDisc_Click);
			this->delDics->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->delDics->Font = (gcnew System::Drawing::Font(L"Arial", 10));
			this->delDics->Location = System::Drawing::Point(916, 38);
			this->delDics->Name = L"delDics";
			this->delDics->Size = System::Drawing::Size(158, 40);
			this->delDics->TabIndex = 4;
			this->delDics->Text = L"Удалить";
			this->delDics->UseVisualStyleBackColor = false;
			this->delDics->Click += gcnew System::EventHandler(this, &My2tables::delDics_Click);
			this->editDisc->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->editDisc->Font = (gcnew System::Drawing::Font(L"Arial", 10));
			this->editDisc->Location = System::Drawing::Point(696, 38);
			this->editDisc->Name = L"editDisc";
			this->editDisc->Size = System::Drawing::Size(190, 40);
			this->editDisc->TabIndex = 5;
			this->editDisc->Text = L"Редактировать";
			this->editDisc->UseVisualStyleBackColor = false;
			this->editDisc->Click += gcnew System::EventHandler(this, &My2tables::editDisc_Click);
			this->exit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->exit->Cursor = System::Windows::Forms::Cursors::Default;
			this->exit->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->exit->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->exit->Location = System::Drawing::Point(1540, 802);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(158, 40);
			this->exit->TabIndex = 6;
			this->exit->Text = L"Назад";
			this->exit->UseVisualStyleBackColor = false;
			this->exit->Click += gcnew System::EventHandler(this, &My2tables::exit_Click);
			this->groupBox1->BackColor = System::Drawing::Color::Lavender;
			this->groupBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->groupBox1->Controls->Add(this->editDisc);
			this->groupBox1->Controls->Add(this->delDics);
			this->groupBox1->Controls->Add(this->addDisc);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->groupBox1->ImeMode = System::Windows::Forms::ImeMode::Off;
			this->groupBox1->Location = System::Drawing::Point(70, 32);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(1562, 100);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Disciplines";
			this->groupBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &My2tables::GroupBox_Paint);
			this->groupBox2->Controls->Add(this->dataGridView1);
			this->groupBox2->Controls->Add(this->bindingNavigator1);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->groupBox2->Location = System::Drawing::Point(70, 192);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(1562, 566);
			this->groupBox2->TabIndex = 8;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Standards";
			this->groupBox2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &My2tables::GroupBox_Paint);
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::Lavender;
			this->ClientSize = System::Drawing::Size(1749, 871);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->exit);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"My2tables";
			this->StartPosition = System::Windows::Forms::FormStartPosition::WindowsDefaultBounds;
			this->Text = L"Редактирование";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataTable1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingNavigator1))->EndInit();
			this->bindingNavigator1->ResumeLayout(false);
			this->bindingNavigator1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet2))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}

	private: System::Void GroupBox_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		GroupBox^ box = (GroupBox^)sender;

		// Настройки стиля
		Color borderColor = Color::FromArgb(64, 0, 64);
		float borderWidth = 1.5f;
		float cornerRadius = 12.0f;
		float textPadding = 8.0f;
		float textIndent = 4.0f;

		// Получаем размеры текста
		SizeF textSize = e->Graphics->MeasureString(box->Text, box->Font);
		float textHeight = textSize.Height;
		float textWidth = textSize.Width;

		// Основные координаты
		float left = 0.0f;
		float top = textHeight / 2.0f;
		float right = box->Width - 1.0f;
		float bottom = box->Height - 1.0f;

		// 1. Сначала рисуем фон и рамку
		System::Drawing::Drawing2D::GraphicsPath^ path = gcnew  System::Drawing::Drawing2D::GraphicsPath();

		// Левый верхний угол
		path->AddArc(left, top, cornerRadius, cornerRadius, 180.0f, 90.0f);

		// Верхняя линия до текста
		path->AddLine(left + cornerRadius, top, textPadding - textIndent, top);

		// Верхняя линия после текста
		path->AddLine(textPadding + textWidth + textIndent, top, right - cornerRadius, top);

		// Правый верхний угол
		path->AddArc(right - cornerRadius, top, cornerRadius, cornerRadius, 270.0f, 90.0f);

		// Правая сторона
		path->AddLine(right, top + cornerRadius, right, bottom - cornerRadius);

		// Правый нижний угол
		path->AddArc(right - cornerRadius, bottom - cornerRadius, cornerRadius, cornerRadius, 0.0f, 90.0f);

		// Нижняя сторона
		path->AddLine(right - cornerRadius, bottom, left + cornerRadius, bottom);

		// Левый нижний угол
		path->AddArc(left, bottom - cornerRadius, cornerRadius, cornerRadius, 90.0f, 90.0f);

		// Левая сторона
		path->AddLine(left, bottom - cornerRadius, left, top + cornerRadius);

		path->CloseFigure();

		// Заливка фона
		e->Graphics->FillPath(gcnew SolidBrush(box->BackColor), path);

		// Рисуем рамку
		Pen^ borderPen = gcnew Pen(borderColor, borderWidth);
		e->Graphics->DrawPath(borderPen, path);
		delete borderPen;

		// 2. Теперь рисуем текст поверх всего
		// Создаем прямоугольник для текста с фоном
		RectangleF textBackRect = RectangleF(
			textPadding - 2.0f,
			0.0f,
			textWidth + 4.0f,
			textHeight
		);

		// Заливаем фон под текстом
		e->Graphics->FillRectangle(gcnew SolidBrush(box->BackColor), textBackRect);

		// Рисуем текст
		e->Graphics->DrawString(
			box->Text,
			box->Font,
			gcnew SolidBrush(box->ForeColor),
			textPadding,
			0.0f
		);

		delete path;
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


	}

		   // Метод для обновления данных в ComboBox
		   void RefreshComboBox() {
			   try {
				   // Получение строки подключения из функции GetConnectionString
				   System::String^ connectionString = EdProgs::GetConnectionString();

				   // Очищаем текущие данные
				   if (comboBox1->DataSource != nullptr) {
					   comboBox1->DataSource = nullptr;
					   comboBox1->Items->Clear();
				   }

				   // Загружаем обновленные данные из БД
				   DataSet^ ds = gcnew DataSet();
				   OleDbDataAdapter^ adapter = gcnew OleDbDataAdapter("SELECT Id, Name FROM Discipline ORDER BY Name", connectionString);
				   adapter->Fill(ds, "Discipline");

				   // Привязываем новые данные
				   comboBox1->DataSource = ds->Tables["Discipline"];
				   comboBox1->DisplayMember = "Name";
				   comboBox1->ValueMember = "Id";
			   }
			   catch (Exception^ ex) {
				   MessageBox::Show("Ошибка при обновлении списка дисциплин: " + ex->Message);
			   }
		   }

		   void RefreshComboBox(int Id) {
			   try {
				   // Получение строки подключения из функции GetConnectionString
				   System::String^ connectionString = EdProgs::GetConnectionString();

				   // Очищаем текущие данные
				   if (comboBox1->DataSource != nullptr) {
					   comboBox1->DataSource = nullptr;
					   comboBox1->Items->Clear();
				   }

				   // Загружаем обновленные данные из БД
				   DataSet^ ds = gcnew DataSet();
				   OleDbDataAdapter^ adapter = gcnew OleDbDataAdapter("SELECT Id, Name FROM Discipline ORDER BY Id DESC ", connectionString);
				   adapter->Fill(ds, "Discipline");

				   // Привязываем новые данные
				   comboBox1->DataSource = ds->Tables["Discipline"];
				   comboBox1->DisplayMember = "Name";
				   comboBox1->ValueMember = "Id";
			   }
			   catch (Exception^ ex) {
				   MessageBox::Show("Ошибка при обновлении списка дисциплин: " + ex->Message);
			   }
		   }

		   void RefreshDataGridView()
		   {
			   try
			   {
				   // Получение строки подключения из функции GetConnectionString
				   System::String^ connectionString = EdProgs::GetConnectionString();

				   
				   DataSet^ ds = gcnew DataSet();
				   OleDbDataAdapter^ adapter = gcnew OleDbDataAdapter("SELECT Id, Standard, ApprovalDate, LifeSpan, QntHours, QntAudHours, DocName, DieDate FROM DisciplineDetails", connectionString);
				   adapter->Fill(ds, "DisciplineDetails");

				   // Обновляем источник данных
				   bindingSource1->DataSource = ds->Tables["DisciplineDetails"];
				   dataGridView1->DataSource = bindingSource1; // Убедитесь, что привязываете источник данных
			   }
			   catch (Exception^ ex)
			   {
				   MessageBox::Show("Ошибка при обновлении списка стандартов: " + ex->Message,
					   "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   }
		   }

		   void RefreshDataGridView(int Id)
		   {
			   try
			   {
				   // Получение строки подключения из функции GetConnectionString
				   System::String^ connectionString = EdProgs::GetConnectionString();

				   String^ filteredQuery =
					   "SELECT Standard, ApprovalDate, LifeSpan, QntHours, " +
					   "QntAudHours, IdDiscipline, DocName, DieDate " +
					   "FROM DisciplineDetails " +
					   "WHERE IdDiscipline = @disciplineId";

				   // 2. Очищаем предыдущие данные
				   this->dataSet1->Tables["DisciplineDetails"]->Clear();

				   // 3. Создаем и настраиваем адаптер
				   this->adapterDetails = gcnew OleDbDataAdapter(filteredQuery, connectionString);
				   this->adapterDetails->SelectCommand->Parameters->AddWithValue("@disciplineId", Id);

				   // 4. Заполняем DataSet
				   this->adapterDetails->Fill(this->dataSet1, "DisciplineDetails");

				   // 5. Обновляем DataGridView
				   this->bindingSource1->DataSource = this->dataSet1->Tables["DisciplineDetails"];
				   this->dataGridView1->DataSource = this->bindingSource1;
			   }
			   catch (Exception^ ex)
			   {
				   MessageBox::Show("Ошибка при обновлении списка стандартов: " + ex->Message,
					   "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   }
		   }

	private:
		bool isInitialized = false; // Добавляем флаг инициализации

		System::Void My2tables_Load(System::Object^ sender, System::EventArgs^ e)
		{

			try
			{
				// 1. Подключение к базе данных
				System::String^ connectionString = EdProgs::GetConnectionString();

				// 2. Загрузка данных для ComboBox (список дисциплин)
				this->dataSet2 = gcnew DataSet();
				this->adapterDisciplines = gcnew OleDbDataAdapter("SELECT Id, Name FROM Discipline ORDER BY Name", connectionString);
				this->adapterDisciplines->Fill(this->dataSet2, "Discipline");

				// 3. Настройка привязки для ComboBox
				this->comboBox1->DataSource = this->dataSet2->Tables["Discipline"];
				this->comboBox1->DisplayMember = "Name";
				this->comboBox1->ValueMember = "Id";
				this->comboBox1->DropDownStyle = ComboBoxStyle::DropDownList;

				// 4. Загрузка данных для DataGridView (все детали дисциплин)
				this->dataSet1 = gcnew DataSet();
				this->adapterDetails = gcnew OleDbDataAdapter("SELECT * FROM DisciplineDetails", connectionString);
				this->adapterDetails->Fill(this->dataSet1, "DisciplineDetails");

				// 5. Настройка привязки данных для DataGridView
				this->bindingSource1->DataSource = this->dataSet1->Tables["DisciplineDetails"];
				this->dataGridView1->DataSource = this->bindingSource1;
				this->bindingNavigator1->BindingSource = this->bindingSource1;

				// 6. Настройка отображения
				this->dataGridView1->AutoGenerateColumns = true;
				this->dataGridView1->RowHeadersVisible = false;
				this->dataGridView1->AllowUserToAddRows = false;
				this->dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;

				this->dataGridView1->Columns["Id"]->Visible = false;
				this->dataGridView1->Columns["IdDiscipline"]->Visible = false;

				// 7. Настройка стилей
				this->dataGridView1->DefaultCellStyle->Font =
					gcnew System::Drawing::Font("Baskerville Old Face", 10);
				this->dataGridView1->ColumnHeadersDefaultCellStyle->Font =
					gcnew System::Drawing::Font("Baskerville Old Face", 11, FontStyle::Bold);
				this->dataGridView1->AlternatingRowsDefaultCellStyle->BackColor = Color::LightBlue;

				isInitialized = true; // Устанавливаем флаг после успешной инициализации
			}
			catch (OleDbException^ dbEx)
			{
				MessageBox::Show("Ошибка БД: " + dbEx->Message,
					"Ошибка",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Ошибка: " + ex->Message,
					"Ошибка",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);
			}
		}

	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (!isInitialized || comboBox1->SelectedValue == nullptr || comboBox1->SelectedValue == DBNull::Value)
			return;

		try
		{
			// Получение строки подключения из функции GetConnectionString
			System::String^ connectionString = EdProgs::GetConnectionString();

			int selectedId = Convert::ToInt32(comboBox1->SelectedValue);

			// Очищаем предыдущие данные
			this->dataSet1->Tables["DisciplineDetails"]->Clear();

			// Создаем новый адаптер с фильтрованным запросом
			String^ filteredQuery =
				"SELECT Id, Standard, ApprovalDate, LifeSpan, QntHours, " +
				"QntAudHours, DocName, DieDate, IdDiscipline " + // Добавлено IdDiscipline
				"FROM DisciplineDetails " +
				"WHERE IdDiscipline = @disciplineId";

			// Проверяем наличие данных
			if (this->adapterDetails != nullptr)
			{
				delete this->adapterDetails;
			}

			this->adapterDetails = gcnew OleDbDataAdapter(filteredQuery, connectionString);
			this->adapterDetails->SelectCommand->Parameters->AddWithValue("@disciplineId", selectedId);

			// Заполняем dataset отфильтрованными данными
			this->adapterDetails->Fill(this->dataSet1, "DisciplineDetails");

			// Обновляем привязку
			this->bindingSource1->DataSource = this->dataSet1->Tables["DisciplineDetails"];
			this->dataGridView1->DataSource = this->bindingSource1;

			// Убедимся, что столбец IdDiscipline существует и видим
			if (this->dataGridView1->Columns["IdDiscipline"] != nullptr)
			{
				this->dataGridView1->Columns["IdDiscipline"]->Visible = false; // Или false, если не нужно показывать
			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Ошибка при фильтрации данных: " + ex->Message,
				"Ошибка",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error);
		}
	}

	private: System::Void addDisc_Click(System::Object^ sender, System::EventArgs^ e) {

		AddDisc^ addForm = gcnew AddDisc(this);
		addForm->ShowDialog(); // Модальное окно

		// После закрытия формы обновляем ComboBox
		if (addForm->DialogResult == System::Windows::Forms::DialogResult::OK) {

			RefreshComboBox(DiscId);
			RefreshDataGridView(DiscId);
		}
	}

	private: System::Void delDics_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Проверяем, что в ComboBox что-то выбрано
		if (comboBox1->SelectedIndex == -1)
		{
			MessageBox::Show("Выберите дисциплину для удаления!", "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		OleDbConnection^ connection = nullptr;
		OleDbTransaction^ transaction = nullptr;

		try
		{
			// Получаем ID и название выбранной дисциплины
			int selectedId = Convert::ToInt32(comboBox1->SelectedValue);
			String^ selectedName = comboBox1->Text;

			// Запрашиваем подтверждение
			System::Windows::Forms::DialogResult result = MessageBox::Show(
				String::Format("Вы уверены, что хотите удалить дисциплину \"{0}\" и все связанные стандарты?", selectedName),
				"Подтверждение удаления",
				MessageBoxButtons::YesNo,
				MessageBoxIcon::Question,
				MessageBoxDefaultButton::Button2);

			if (result != System::Windows::Forms::DialogResult::Yes)
				return;

			// Получение строки подключения из функции GetConnectionString
			System::String^ connectionString = EdProgs::GetConnectionString();

			connection = gcnew OleDbConnection(connectionString);
			connection->Open();

			// Начинаем транзакцию для безопасного удаления
			transaction = connection->BeginTransaction();

			// 1. Удаляем связанные записи из DisciplineDetails
			OleDbCommand^ deleteDetailsCmd = gcnew OleDbCommand(
				"DELETE FROM DisciplineDetails WHERE IdDiscipline = ?", connection, transaction);
			deleteDetailsCmd->Parameters->AddWithValue("?", selectedId);
			deleteDetailsCmd->ExecuteNonQuery();

			// 2. Удаляем саму дисциплину
			OleDbCommand^ deleteDiscCmd = gcnew OleDbCommand(
				"DELETE FROM Discipline WHERE Id = ?", connection, transaction);
			deleteDiscCmd->Parameters->AddWithValue("?", selectedId);
			deleteDiscCmd->ExecuteNonQuery();

			// Подтверждаем транзакцию
			transaction->Commit();

			// Обновляем данные в интерфейсе
			RefreshComboBox();
			if (comboBox1->Items->Count > 0)
			{
				int selectedId = Convert::ToInt32(comboBox1->SelectedValue);
				RefreshDataGridView(selectedId);
			}
			else
			{
				RefreshDataGridView(); // Без параметров, чтобы показать все стандарты
			}

			MessageBox::Show("Дисциплина и связанные стандарты успешно удалены!", "Успех",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (Exception^ ex)
		{
			// Откатываем транзакцию в случае ошибки
			if (transaction != nullptr)
				transaction->Rollback();

			MessageBox::Show("Ошибка при удалении дисциплины: " + ex->Message, "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		finally
		{
			// Закрываем соединение
			if (connection != nullptr && connection->State == ConnectionState::Open)
				connection->Close();
		}
	}

	private: System::Void editDisc_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Проверяем, что в ComboBox выбрана дисциплина
		if (comboBox1->SelectedValue == nullptr || comboBox1->SelectedValue == DBNull::Value)
		{
			MessageBox::Show("Выберите дисциплину для редактирования!", "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try
		{
			// Получаем ID и название выбранной дисциплины
			int selectedId = Convert::ToInt32(comboBox1->SelectedValue);
			String^ selectedName = comboBox1->Text;

			// Создаем форму редактирования
			EditDisc^ editForm = gcnew EditDisc(selectedId, selectedName, this);

			// Открываем форму модально
			if (editForm->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				// Обновляем список дисциплин
				int selectedId = Convert::ToInt32(comboBox1->SelectedValue);
				RefreshComboBox();
				comboBox1->SelectedValue = selectedId;
				RefreshDataGridView(selectedId);
			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Ошибка при редактировании дисциплины: " + ex->Message, "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}


	private: System::Void bindingNavigatorAddNewItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (comboBox1->SelectedValue == nullptr || comboBox1->SelectedValue == DBNull::Value)
		{
			MessageBox::Show("Выберите дисциплину для добавления!", "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try
		{
			int selectedId = Convert::ToInt32(comboBox1->SelectedValue);
			String^ selectedName = comboBox1->Text;

			// Убедитесь, что конструктор AddStandard правильно определен
			AddStandard^ addForm = gcnew AddStandard(selectedId, selectedName, this);

			if (addForm->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				int selectedId = Convert::ToInt32(comboBox1->SelectedValue);
				RefreshDataGridView(selectedId);
			}
		}
		catch (FormatException^ ex)
		{
			MessageBox::Show("Ошибка формата ID дисциплины: " + ex->Message, "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Ошибка при добавлении стандарта: " + ex->Message, "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}

	private: System::Void dataGridView1_CellDoubleClick(System::Object^ sender, DataGridViewCellEventArgs^ e)
	{
		// Проверяем, что клик не по заголовку и не по пустой области

		if (e->RowIndex >= 0 && e->ColumnIndex >= 0)
		{
			// Сбрасываем выделение и цвет всех строк
			for each (DataGridViewRow ^ row in dataGridView1->Rows)
			{
				// Возвращаем стандартные цвета (белый или lightBlue для чередующихся строк)
				if (row->Index % 2 == 0)
					row->DefaultCellStyle->BackColor = Color::White;
				else
					row->DefaultCellStyle->BackColor = Color::LightBlue;

				row->Selected = false;
			}

			// Получаем выбранную строку
			DataGridViewRow^ selectedRow = dataGridView1->Rows[e->RowIndex];

			// Устанавливаем цвет выделения
			selectedRow->DefaultCellStyle->BackColor = Color::LightSalmon;

			// Добавляем строку в SelectedRows
			selectedRow->Selected = true;
		}
	}

	private: System::Void bindingNavigatorEditItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (dataGridView1->SelectedRows->Count <= 0) {
			MessageBox::Show("Выберите стандарт для редактирования!", "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try {
			// Получаем выбранный ряд
			DataGridViewRow^ selectedRow = dataGridView1->SelectedRows[0];

			// Проверяем наличие обязательных полей
			if (selectedRow->Cells["IdDiscipline"]->Value == nullptr ||
				selectedRow->Cells["IdDiscipline"]->Value == DBNull::Value) {
				MessageBox::Show("Неверные данные в выбранной строке: отсутствует ID!", "Ошибка",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			int selectedId = safe_cast<int>(selectedRow->Cells["IdDiscipline"]->Value);

			// Получаем название стандарта (может быть пустым)
			String^ selectedName = "";
			if (selectedRow->Cells["Standard"]->Value != nullptr &&
				selectedRow->Cells["Standard"]->Value != DBNull::Value) {
				selectedName = safe_cast<String^>(selectedRow->Cells["Standard"]->Value);
			}

			// Передаем текущий ID и имя стандарта в форму редактирования
			EditStandard^ editForm = gcnew EditStandard(selectedId, selectedName, this);

			if (editForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				// Обновляем данные после успешного редактирования и выводим все дисциплины
				RefreshDataGridView();

				MessageBox::Show("Стандарт успешно отредактирован!", "Успех",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}
		catch (FormatException^ ex) {
			MessageBox::Show("Ошибка формата ID записи: " + ex->Message, "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ошибка при редактировании стандарта: " + ex->Message, "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

		   void DeleteStandardById(int id)
		   {
			   try {
				   // Создаем подключение к базе данных
				   System::String^ connectionString = EdProgs::GetConnectionString();
				   OleDbConnection^ connection = gcnew OleDbConnection(connectionString);
				   connection->Open();

				   // Создаем команду для удаления записи
				   String^ query = "DELETE FROM disciplineDetails WHERE Id = ?";
				   OleDbCommand^ command = gcnew OleDbCommand(query, connection);

				   // Добавляем параметр Id
				   command->Parameters->Add("Id", OleDbType::Integer)->Value = id;

				   // Выполняем команду
				   int rowsAffected = command->ExecuteNonQuery();

				   if (rowsAffected > 0) {
					   MessageBox::Show("Запись успешно удалена!", "Успех",
						   MessageBoxButtons::OK, MessageBoxIcon::Information);
				   }
				   else {
					   MessageBox::Show("Запись с указанным Id не найдена.", "Ошибка",
						   MessageBoxButtons::OK, MessageBoxIcon::Warning);
				   }

				   // Закрываем подключение
				   connection->Close();
			   }
			   catch (OleDbException^ ex) {
				   MessageBox::Show("Ошибка при удалении записи: " + ex->Message, "Ошибка",
					   MessageBoxButtons::OK, MessageBoxIcon::Error);
			   }
			   catch (Exception^ ex) {
				   MessageBox::Show("Произошла ошибка: " + ex->Message, "Ошибка",
					   MessageBoxButtons::OK, MessageBoxIcon::Error);
			   }
		   }

	private: System::Void bindingNavigatorDeleteItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (dataGridView1->SelectedRows->Count <= 0) {
			MessageBox::Show("Выберите запись для удаления!", "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try {
			// Получаем выбранный ряд
			DataGridViewRow^ selectedRow = dataGridView1->SelectedRows[0];

			int selectedId = safe_cast<int>(selectedRow->Cells["Id"]->Value);
			String^ selectedName = safe_cast<String^>(selectedRow->Cells["Standard"]->Value);
			
			// Подтверждение удаления
			System::Windows::Forms::DialogResult result = MessageBox::Show("Вы уверены, что хотите удалить " + selectedName + "?'", "Подтверждение удаления",
				MessageBoxButtons::YesNo, MessageBoxIcon::Question);

			if (result == System::Windows::Forms::DialogResult::Yes) {
				DeleteStandardById(selectedId);

				// Обновляем данные в DataGridView и ComboBox
				RefreshDataGridView();
				RefreshComboBox();

			}
		}
		catch (FormatException^ ex) {
			MessageBox::Show("Ошибка формата ID записи: " + ex->Message, "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ошибка при удалении записи: " + ex->Message, "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}


	private: System::Void exit_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}


	};
}