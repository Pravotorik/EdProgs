#pragma once

namespace EdProgs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::OleDb;
	using namespace System::Globalization;

	/// <summary>
	/// Сводка для EditStandard
	/// </summary>
	public ref class EditStandard : public System::Windows::Forms::Form
    {
    private:
        int disciplineId;

    public:
        EditStandard(int id)
        {
            InitializeComponent();
           disciplineId = id;
        }

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~EditStandard()
		{
			if (components)
			{
				delete components;
			}
		}
		Form^ My2tables; // Ссылка на родительскую форму
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ Ok;


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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->Ok = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(229, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(205, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Внесите изменения";
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(30, 102);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(143, 37);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Standard";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(193, 102);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(441, 37);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(193, 170);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(441, 37);
			this->textBox2->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(30, 170);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(143, 37);
			this->label3->TabIndex = 3;
			this->label3->Text = L"ApprovalDate";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(193, 238);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(441, 37);
			this->textBox3->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(30, 238);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(143, 37);
			this->label4->TabIndex = 5;
			this->label4->Text = L"LifeSpan";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(193, 445);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(441, 37);
			this->textBox4->TabIndex = 12;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(30, 445);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(143, 37);
			this->label5->TabIndex = 11;
			this->label5->Text = L"DocName";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox5->Location = System::Drawing::Point(193, 377);
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(441, 37);
			this->textBox5->TabIndex = 10;
			// 
			// label6
			// 
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(30, 377);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(143, 37);
			this->label6->TabIndex = 9;
			this->label6->Text = L"QntAudHours";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox6->Location = System::Drawing::Point(193, 308);
			this->textBox6->Multiline = true;
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(441, 37);
			this->textBox6->TabIndex = 8;
			// 
			// label7
			// 
			this->label7->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(30, 308);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(143, 37);
			this->label7->TabIndex = 7;
			this->label7->Text = L"QntHours";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// textBox7
			// 
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox7->Location = System::Drawing::Point(193, 518);
			this->textBox7->Multiline = true;
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(441, 37);
			this->textBox7->TabIndex = 14;
			// 
			// label8
			// 
			this->label8->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(30, 518);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(143, 37);
			this->label8->TabIndex = 13;
			this->label8->Text = L"DieDate";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// Ok
			// 
			this->Ok->BackColor = System::Drawing::Color::LightSalmon;
			this->Ok->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Ok->Location = System::Drawing::Point(491, 596);
			this->Ok->Name = L"Ok";
			this->Ok->Size = System::Drawing::Size(143, 37);
			this->Ok->TabIndex = 15;
			this->Ok->Text = L"Ok";
			this->Ok->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->Ok->Click += gcnew System::EventHandler(this, &EditStandard::Ok_Click);
			// 
			// EditStandard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightBlue;
			this->ClientSize = System::Drawing::Size(665, 679);
			this->Controls->Add(this->Ok);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"EditStandard";
			this->Text = L"EditStandard";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: void SetFields(String^ standard, String^ approvalDate, int lifeSpan, int qntHours, int qntAudHours, String^ docName, String^ dieDate)
	{
		textBox1->Text = standard;
		textBox2->Text = approvalDate;
		textBox3->Text = lifeSpan.ToString();
		textBox4->Text = qntHours.ToString();
		textBox5->Text = qntAudHours.ToString();
		textBox6->Text = docName;
		textBox7->Text = dieDate;
	}

	private: System::Void Ok_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Проверка обязательных полей
		if (String::IsNullOrEmpty(textBox1->Text))
		{
			MessageBox::Show("Поле 'Standard' обязательно для заполнения!", "Ошибка");
			return;
		}

		OleDbConnection^ connection = gcnew OleDbConnection("Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:/Users/Nastya/Documents/АУпПРБ/4_семестр/ТП/курсовая/EdProgs/db/EdProgs.mdb");
		String^ query;

		// Если disciplineId > 0, значит мы редактируем запись, иначе добавляем новую
		if (disciplineId > 0)
		{
			query = "UPDATE DisciplineDetails SET Standard=@standard, ApprovalDate=@approvalDate, LifeSpan=@lifeSpan, QntHours=@qntHours, QntAudHours=@qntAudHours, DocName=@docName, DieDate=@dieDate WHERE IdDiscipline=@disciplineId";
		}
		else
		{
			query = "INSERT INTO DisciplineDetails (IdDiscipline, Standard, ApprovalDate, LifeSpan, QntHours, QntAudHours, DocName, DieDate) " +
				"VALUES (@disciplineId, @standard, @approvalDate, @lifeSpan, @qntHours, @qntAudHours, @docName, @dieDate)";
		}

		OleDbCommand^ command = gcnew OleDbCommand(query, connection);
		command->Parameters->AddWithValue("@disciplineId", disciplineId);
		command->Parameters->AddWithValue("@standard", textBox1->Text);

		// Проверка и преобразование даты
		DateTime approvalDate;
		if (String::IsNullOrEmpty(textBox2->Text))
		{
			MessageBox::Show("Поле 'ApprovalDate' обязательно для заполнения!", "Ошибка");
			return;
		}

		if (!DateTime::TryParseExact(textBox2->Text, "dd.MM.yyyy", CultureInfo::InvariantCulture, DateTimeStyles::None, approvalDate))
		{
			MessageBox::Show("Неверный формат даты в поле 'ApprovalDate'. Ожидается формат: дд.мм.гггг", "Ошибка");
			return;
		}
		command->Parameters->AddWithValue("@approvalDate", approvalDate);

		// Преобразование и валидация других полей
		try
		{
			command->Parameters->AddWithValue("@lifeSpan", Convert::ToInt32(textBox3->Text));
			command->Parameters->AddWithValue("@qntHours", Convert::ToInt32(textBox6->Text));
			command->Parameters->AddWithValue("@qntAudHours", Convert::ToInt32(textBox5->Text));
			command->Parameters->AddWithValue("@docName", textBox4->Text);

			DateTime dieDate;
			if (!DateTime::TryParseExact(textBox7->Text, "dd.MM.yyyy", CultureInfo::InvariantCulture, DateTimeStyles::None, dieDate))
			{
				MessageBox::Show("Неверный формат даты в поле 'DieDate'. Ожидается формат: дд.мм.гггг", "Ошибка");
				return;
			}
			command->Parameters->AddWithValue("@dieDate", dieDate);
		}
		catch (FormatException^)
		{
			MessageBox::Show("Неверный формат числа в одном из полей.", "Ошибка");
			return;
		}

		// Выполнение команды
		try
		{
			connection->Open();
			command->ExecuteNonQuery();
			MessageBox::Show("Данные успешно сохранены!", "Успех");
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Ошибка при сохранении данных: " + ex->Message, "Ошибка");
		}
		finally
		{
			connection->Close();
		}
	}

		 
	};
}
