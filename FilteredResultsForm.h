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
        FilteredResultsForm(DataTable^ data, String^ filterYear) {
            InitializeComponent();
            this->dataGridView1->DataSource = data;
            ApplyDataGridViewFormatting(); // Применяем форматирование
            this->label1->Text = "Стандарты, которые действуют до: " + filterYear + " года";
        }

    private:
        System::Windows::Forms::Button^ back;
    private: System::Windows::Forms::Label^ label1;
           System::Windows::Forms::DataGridView^ dataGridView1;

        // Метод для применения форматирования DataGridView
        void ApplyDataGridViewFormatting() {

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

        void InitializeComponent() {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FilteredResultsForm::typeid));
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->back = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->SuspendLayout();
            // 
            // dataGridView1
            // 
            this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::Window;
            this->dataGridView1->ColumnHeadersHeight = 34;
            this->dataGridView1->GridColor = System::Drawing::SystemColors::Control;
            this->dataGridView1->Location = System::Drawing::Point(36, 107);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->RowHeadersWidth = 62;
            this->dataGridView1->Size = System::Drawing::Size(1520, 384);
            this->dataGridView1->TabIndex = 0;
            // 
            // back
            // 
            this->back->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->back->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->back->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->back->Location = System::Drawing::Point(1433, 516);
            this->back->Name = L"back";
            this->back->Size = System::Drawing::Size(150, 46);
            this->back->TabIndex = 1;
            this->back->Text = L"Назад";
            this->back->UseVisualStyleBackColor = false;
            this->back->Click += gcnew System::EventHandler(this, &FilteredResultsForm::back_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->label1->Location = System::Drawing::Point(30, 34);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(540, 33);
            this->label1->TabIndex = 2;
            this->label1->Text = L"Стандарты, которые деуйствуют до :";
            // 
            // FilteredResultsForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->AutoSize = true;
            this->BackColor = System::Drawing::Color::Lavender;
            this->ClientSize = System::Drawing::Size(1601, 574);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->back);
            this->Controls->Add(this->dataGridView1);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"FilteredResultsForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
            this->Text = L"Результаты фильтрации";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
    };
}
#pragma endregion