#pragma once

namespace EdProgs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::OleDb;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AddDisc
	/// </summary>
	public ref class AddDisc : public System::Windows::Forms::Form
	{
	public:
		AddDisc(Form^ parentForm) {
			InitializeComponent();
			this->My2tables = parentForm;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AddDisc()
		{
			if (components)
			{
				delete components;
			}
		}
		Form^ My2tables; // Ссылка на родительскую форму
		String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:/Users/Nastya/Documents/АУпПРБ/4_семестр/ТП/курсовая/EdProgs/db/EdProgs.mdb";

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ exit;
	private: System::Windows::Forms::Button^ OK;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;
		
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->exit = (gcnew System::Windows::Forms::Button());
			this->OK = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(61, 75);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(498, 32);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введите название новой дисциплины";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(29, 144);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(564, 56);
			this->textBox1->TabIndex = 1;
			// 
			// exit
			// 
			this->exit->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->exit->Location = System::Drawing::Point(29, 298);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(156, 48);
			this->exit->TabIndex = 2;
			this->exit->Text = L"Назад";
			this->exit->UseVisualStyleBackColor = true;
			this->exit->Click += gcnew System::EventHandler(this, &AddDisc::exit_Click);
			// 
			// OK
			// 
			this->OK->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->OK->Location = System::Drawing::Point(437, 298);
			this->OK->Name = L"OK";
			this->OK->Size = System::Drawing::Size(156, 48);
			this->OK->TabIndex = 3;
			this->OK->Text = L"Ok";
			this->OK->UseVisualStyleBackColor = true;
			this->OK->Click += gcnew System::EventHandler(this, &AddDisc::OK_Click);
			// 
			// AddDisc
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(661, 424);
			this->Controls->Add(this->OK);
			this->Controls->Add(this->exit);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"AddDisc";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AddDisc";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void OK_Click(System::Object^ sender, System::EventArgs^ e) {
			if (String::IsNullOrWhiteSpace(textBox1->Text)) {
				MessageBox::Show("Введите название дисциплины!");
				return;
			}

			try {
				// 1. Получаем новый ID (максимальный + 1)
				int newId = GetMaxId() + 1;
				String^ name = textBox1->Text;

				// 2. Добавляем в базу данных
				OleDbConnection^ conn = gcnew OleDbConnection(connectionString);
				OleDbCommand^ cmd = gcnew OleDbCommand("INSERT INTO Discipline (Id, Name) VALUES (@id, @name)", conn);
				cmd->Parameters->AddWithValue("@id", newId);
				cmd->Parameters->AddWithValue("@name", name);

				conn->Open();
				cmd->ExecuteNonQuery();
				conn->Close();

				// 3. Закрываем форму с результатом OK
				this->DialogResult = System::Windows::Forms::DialogResult::OK;
				this->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Ошибка при сохранении: " + ex->Message);
			}
		}

		// Получаем максимальный ID из таблицы Discipline
		int GetMaxId() {
			int maxId = 0;
			OleDbConnection^ conn = gcnew OleDbConnection(connectionString);
			OleDbCommand^ cmd = gcnew OleDbCommand("SELECT MAX(Id) FROM Discipline", conn);

			try {
				conn->Open();
				Object^ result = cmd->ExecuteScalar();
				if (result != nullptr && result != DBNull::Value) {
					maxId = Convert::ToInt32(result);
				}
			}
			finally {
				if (conn->State == ConnectionState::Open)
					conn->Close();
			}

			return maxId;
		}

		System::Void exit_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	};
}
