#pragma once

namespace EdProgs {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Data::OleDb;

    public ref class ShowIdDisc : public System::Windows::Forms::Form
    {
    public:
        property String^ SelectedId {
            String^ get() { return textBox1->Text; }
        }

        ShowIdDisc(void)
        {
            InitializeComponent();
            LoadDisciplines();
            this->adapterDiscipline = gcnew OleDbDataAdapter();
        }

    protected:
        ~ShowIdDisc()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Button^ button1;
        System::Windows::Forms::TextBox^ textBox1;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::DataGridView^ dataGridView1;
        System::Windows::Forms::BindingSource^ bindingSource1;
        System::Data::DataSet^ dataSet1;
        OleDbConnection^ connection;
        System::ComponentModel::IContainer^ components;
        OleDbDataAdapter^ adapterDiscipline;

        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
            this->dataSet1 = (gcnew System::Data::DataSet());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet1))->BeginInit();
            this->SuspendLayout();
            // 
            // button1
            // 
            this->button1->DialogResult = System::Windows::Forms::DialogResult::OK;
            this->button1->Location = System::Drawing::Point(412, 33);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(61, 43);
            this->button1->TabIndex = 0;
            this->button1->Text = L"OK";
            this->button1->UseVisualStyleBackColor = true;
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(284, 33);
            this->textBox1->Multiline = true;
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(82, 43);
            this->textBox1->TabIndex = 1;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(27, 36);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(179, 20);
            this->label1->TabIndex = 2;
            this->label1->Text = L"Выберите дисциплину";
            // 
            // dataGridView1
            // 
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Location = System::Drawing::Point(43, 144);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->ReadOnly = true;
            this->dataGridView1->RowHeadersWidth = 62;
            this->dataGridView1->RowTemplate->Height = 28;
            this->dataGridView1->Size = System::Drawing::Size(759, 497);
            this->dataGridView1->TabIndex = 3;
            this->dataGridView1->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ShowIdDisc::dataGridView1_CellDoubleClick);
            this->dataGridView1->CellContentClick += gcnew DataGridViewCellEventHandler(this, &ShowIdDisc::dataGridView1_CellContentClick);
            this->dataGridView1->RowHeadersVisible = false;
            this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->dataGridView1->DefaultCellStyle->Font = gcnew System::Drawing::Font("Baskerville Old Face", 10);
            this->dataGridView1->RowsDefaultCellStyle->BackColor = System::Drawing::Color::White;
            this->dataGridView1->AlternatingRowsDefaultCellStyle->BackColor = System::Drawing::Color::LightBlue;
            this->dataGridView1->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font("Baskerville Old Face", 11, System::Drawing::FontStyle::Bold);
            // 
            // dataSet1
            // 
            this->dataSet1->DataSetName = L"NewDataSet";
            // 
            // ShowIdDisc
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(847, 674);
            this->Controls->Add(this->dataGridView1);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->button1);
            this->Name = L"ShowIdDisc";
            this->Text = L"Выбор дисциплины";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }

        void LoadDisciplines() {
            try {
                String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:/Users/Nastya/Documents/АУпПРБ/4_семестр/ТП/курсовая/EdProgs/db/EdProgs.mdb";
                OleDbConnection^ connection = gcnew OleDbConnection(connectionString);

                DataTable^ dataTable = gcnew DataTable();
                OleDbDataAdapter^ adapter = gcnew OleDbDataAdapter("SELECT * FROM Discipline", connection);
                adapter->Fill(dataTable);

                dataGridView1->AutoGenerateColumns = false;
                dataGridView1->Columns->Clear();

                // CheckBox column
                DataGridViewCheckBoxColumn^ checkBoxColumn = gcnew DataGridViewCheckBoxColumn();
                checkBoxColumn->Name = "CheckBoxColumn";
                checkBoxColumn->Width = 40;
                checkBoxColumn->FlatStyle = FlatStyle::Standard;
                checkBoxColumn->TrueValue = true;
                checkBoxColumn->FalseValue = false;
                dataGridView1->DefaultCellStyle->SelectionBackColor = Color::LightSteelBlue;
                dataGridView1->Columns->Add(checkBoxColumn);

                // Other columns
                for each (DataColumn ^ column in dataTable->Columns) {
                    DataGridViewTextBoxColumn^ textColumn = gcnew DataGridViewTextBoxColumn();
                    textColumn->HeaderText = column->ColumnName;
                    textColumn->Name = column->ColumnName;
                    textColumn->DataPropertyName = column->ColumnName;
                    dataGridView1->Columns->Add(textColumn);
                }

                dataGridView1->DataSource = dataTable;
                dataGridView1->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
                dataGridView1->ClearSelection();
                connection->Close();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Ошибка: " + ex->Message);
            }
        }

    private:
        // Обработчик клика по CheckBox
        System::Void dataGridView1_CellContentClick(System::Object^ sender, DataGridViewCellEventArgs^ e) {
            if (e->RowIndex >= 0 && e->ColumnIndex == 0) {
                DataGridViewCheckBoxCell^ cell = (DataGridViewCheckBoxCell^)dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex];
                cell->Value = !Convert::ToBoolean(cell->Value);
                dataGridView1->Rows[e->RowIndex]->Selected = true;
                dataGridView1->RefreshEdit();
                dataGridView1->DefaultCellStyle->SelectionBackColor = Color::LightSalmon;

                // Если checkbox отмечен, подставляем ID в textBox1
                if (Convert::ToBoolean(cell->Value)) {
                    this->textBox1->Text = dataGridView1->Rows[e->RowIndex]->Cells["Id"]->Value->ToString();
                }
                else {
                    // Если checkbox снят, очищаем textBox1
                    this->textBox1->Text = "";
                }
            }
        }

        // Обработчик двойного клика по строке
        System::Void dataGridView1_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
            if (e->RowIndex >= 0) {
                try {
                    DataGridViewRow^ row = this->dataGridView1->Rows[e->RowIndex];
                    this->textBox1->Text = row->Cells["Id"]->Value->ToString();

                    // Также отмечаем соответствующий checkbox
                    DataGridViewCheckBoxCell^ cell = (DataGridViewCheckBoxCell^)row->Cells[0];
                    cell->Value = true;
                    dataGridView1->RefreshEdit();
                }
                catch (Exception^ ex) {
                    MessageBox::Show("Ошибка при загрузке данных: " + ex->Message);
                }
            }
        }
    };
}