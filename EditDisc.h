#pragma once
#include "GlobalSettings.h"

namespace EdProgs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::OleDb;
	using namespace System::Drawing;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для EditDisc
	/// </summary>
	public ref class EditDisc : public System::Windows::Forms::Form
	{
	public:
		EditDisc(int discId, String^ discName, Form^ parentForm)
		{
			InitializeComponent();
			disciplineId = discId;
			textBox1->Text = discName;
			this->My2tables = parentForm;
		}


		//
		//TODO: добавьте код конструктора
		//

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~EditDisc()
		{
			if (components)
			{
				delete components;
			}
		}


	private:
		int disciplineId; // ID редактируемой дисциплины
		Form^ My2tables; // Ссылка на родительскую форму
		//String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:/Users/Nastya/Documents/АУпПРБ/4_семестр/ТП/курсовая/EdProgs/db/EdProgs.mdb";
		
		System::String^ connectionString = EdProgs::GetConnectionString();

		
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(EditDisc::typeid));
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
			this->label1->Location = System::Drawing::Point(23, 72);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(576, 32);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введите измененное название дисциплины";
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
			this->exit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->exit->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Bold));
			this->exit->Location = System::Drawing::Point(29, 298);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(156, 48);
			this->exit->TabIndex = 2;
			this->exit->Text = L"Назад";
			this->exit->UseVisualStyleBackColor = false;
			this->exit->Click += gcnew System::EventHandler(this, &EditDisc::exit_Click);
			// 
			// OK
			// 
			this->OK->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->OK->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->OK->Location = System::Drawing::Point(437, 298);
			this->OK->Name = L"OK";
			this->OK->Size = System::Drawing::Size(156, 48);
			this->OK->TabIndex = 3;
			this->OK->Text = L"Ok";
			this->OK->UseVisualStyleBackColor = false;
			this->OK->Click += gcnew System::EventHandler(this, &EditDisc::OK_Click);
			// 
			// EditDisc
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Lavender;
			this->ClientSize = System::Drawing::Size(661, 424);
			this->Controls->Add(this->OK);
			this->Controls->Add(this->exit);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"EditDisc";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Редактирование дисциплины";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void OK_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(textBox1->Text)) {
			MessageBox::Show("Введите название дисциплины!");
			return;
		}

		try {

			OleDbConnection^ connection = gcnew OleDbConnection(connectionString);
			OleDbCommand^ cmd;  // Объявляем команду здесь, перед использованием

			if (disciplineId == -1) {
				// Добавление новой дисциплины
				cmd = gcnew OleDbCommand(
					"INSERT INTO Discipline (Name) VALUES (@name)", connection);
				cmd->Parameters->AddWithValue("@name", textBox1->Text);
			}
			else {
				// Обновление существующей дисциплины
				cmd = gcnew OleDbCommand(
					"UPDATE Discipline SET Name = @name WHERE Id = @id", connection);
				cmd->Parameters->AddWithValue("@name", textBox1->Text);
				cmd->Parameters->AddWithValue("@id", disciplineId);
			}

			connection->Open();
			cmd->ExecuteNonQuery();  // Теперь cmd доступна
			connection->Close();

			MessageBox::Show("Изменения успешно сохранены!", "Успех",
				MessageBoxButtons::OK, MessageBoxIcon::Information);

			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ошибка при сохранении: " + ex->Message, "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
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
