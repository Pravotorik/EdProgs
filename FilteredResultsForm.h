#pragma once

namespace EdProgs {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Форма для отображения отфильтрованных результатов
    /// </summary>
    public ref class FilteredResultsForm : public System::Windows::Forms::Form {
    public:
        FilteredResultsForm(DataTable^ data) {
            InitializeComponent();
            this->dataGridView1->DataSource = data;
            ApplyDataGridViewFormatting(); // Применяем форматирование
        }

    private:
        System::Windows::Forms::Button^ back;
        System::Windows::Forms::DataGridView^ dataGridView1;

        // Метод для применения форматирования DataGridView
        void ApplyDataGridViewFormatting() {
            // Добавляем столбец с CheckBox
            DataGridViewCheckBoxColumn^ checkBoxColumn = gcnew DataGridViewCheckBoxColumn();
            checkBoxColumn->HeaderText = "Выбрать"; // Заголовок столбца
            checkBoxColumn->FalseValue = false;
            checkBoxColumn->TrueValue = true;
            this->dataGridView1->Columns->Add(checkBoxColumn);

            // Настройка внешнего вида DataGridView
            this->dataGridView1->RowHeadersVisible = false;
            this->dataGridView1->AllowUserToAddRows = false;
            this->dataGridView1->AutoGenerateColumns = true;
            this->dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;
            this->dataGridView1->DefaultCellStyle->Font = gcnew System::Drawing::Font("Baskerville Old Face", 10);

            // Настройка стиля заголовков столбцов
            this->dataGridView1->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font("Baskerville Old Face", 11, FontStyle::Bold);

            // Настройка цветов строк
            this->dataGridView1->RowsDefaultCellStyle->BackColor = Color::White;
            this->dataGridView1->AlternatingRowsDefaultCellStyle->BackColor = Color::LightBlue;
        }

    private:
        // Обработчик события нажатия на кнопку "Назад"
        System::Void back_Click(System::Object^ sender, System::EventArgs^ e) {
            this->Close(); // Закрываем текущую форму
        }

        // Метод InitializeComponent (автоматически генерируется в FilteredResultsForm.Designer.h)
        void InitializeComponent() {
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->back = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->SuspendLayout();
            // 
            // dataGridView1
            // 
            this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
            this->dataGridView1->ColumnHeadersHeight = 34;
            this->dataGridView1->GridColor = System::Drawing::SystemColors::Control;
            this->dataGridView1->Location = System::Drawing::Point(19, 35);
            this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->RowHeadersWidth = 62;
            this->dataGridView1->Size = System::Drawing::Size(902, 286);
            this->dataGridView1->TabIndex = 0;
            // 
            // back
            // 
            this->back->Font = (gcnew System::Drawing::Font(L"Baskerville Old Face", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->back->Location = System::Drawing::Point(846, 337);
            this->back->Margin = System::Windows::Forms::Padding(2);
            this->back->Name = L"back";
            this->back->Size = System::Drawing::Size(75, 30);
            this->back->TabIndex = 1;
            this->back->Text = L"Назад";
            this->back->UseVisualStyleBackColor = true;
            this->back->Click += gcnew System::EventHandler(this, &FilteredResultsForm::back_Click);
            // 
            // FilteredResultsForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::LightBlue;
            this->ClientSize = System::Drawing::Size(946, 369);
            this->Controls->Add(this->back);
            this->Controls->Add(this->dataGridView1);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->Margin = System::Windows::Forms::Padding(2);
            this->Name = L"FilteredResultsForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Результаты фильтрации";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);

        }
    };
}
#pragma endregion