#pragma once

#include "My2tables.h"
#include "ProgsList.h"

namespace EdProgs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	int DiscId;
	/// <summary>
	/// Сводка для HomePage
	/// </summary>
	public ref class HomePage : public System::Windows::Forms::Form
	{
	public:
		HomePage(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~HomePage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ edit;
	private: System::Windows::Forms::Button^ look;
	private: System::Windows::Forms::Button^ button1;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(HomePage::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->edit = (gcnew System::Windows::Forms::Button());
			this->look = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(121, 65);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(388, 200);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Работа с учебно-программной документацией";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->Click += gcnew System::EventHandler(this, &HomePage::label1_Click);
			// 
			// edit
			// 
			this->edit->BackColor = System::Drawing::Color::LightSalmon;
			this->edit->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->edit->Location = System::Drawing::Point(86, 319);
			this->edit->Name = L"edit";
			this->edit->Size = System::Drawing::Size(200, 45);
			this->edit->TabIndex = 1;
			this->edit->Text = L"Редактирование";
			this->edit->UseVisualStyleBackColor = false;
			this->edit->Click += gcnew System::EventHandler(this, &HomePage::edit_Click);
			// 
			// look
			// 
			this->look->BackColor = System::Drawing::Color::LightSalmon;
			this->look->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->look->Location = System::Drawing::Point(327, 319);
			this->look->Name = L"look";
			this->look->Size = System::Drawing::Size(200, 45);
			this->look->TabIndex = 2;
			this->look->Text = L"Просмотр";
			this->look->UseVisualStyleBackColor = false;
			this->look->Click += gcnew System::EventHandler(this, &HomePage::look_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::MistyRose;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(223, 392);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(170, 45);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Выход";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &HomePage::button1_Click);
			// 
			// HomePage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(634, 500);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->look);
			this->Controls->Add(this->edit);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(660, 560);
			this->Name = L"HomePage";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Education Prog Account";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void edit_Click(System::Object^ sender, System::EventArgs^ e) {
		My2tables^ f1 = gcnew My2tables();
		f1->Owner = this;
		f1->ShowDialog();
	}
	private: System::Void look_Click(System::Object^ sender, System::EventArgs^ e) {
		ProgsList^ f1 = gcnew ProgsList();
		f1->ShowDialog();
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::DialogResult result = MessageBox::Show(
			"Вы действительно хотите выйти?",
			"Подтверждение выхода",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question);

		if (result == System::Windows::Forms::DialogResult::Yes) {
	// Корректное завершение
			Application::Exit();
		}
	}
	};
}
