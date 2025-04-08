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
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 16, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(121, 65);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(388, 200);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Добро пожаловать в программу, которая упростит работу с учебно-программной докуме"
				L"нтацией";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// edit
			// 
			this->edit->BackColor = System::Drawing::Color::LightSalmon;
			this->edit->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
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
			this->look->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->look->Location = System::Drawing::Point(327, 319);
			this->look->Name = L"look";
			this->look->Size = System::Drawing::Size(200, 45);
			this->look->TabIndex = 2;
			this->look->Text = L"Просмотр";
			this->look->UseVisualStyleBackColor = false;
			this->look->Click += gcnew System::EventHandler(this, &HomePage::look_Click);
			// 
			// HomePage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(638, 504);
			this->Controls->Add(this->look);
			this->Controls->Add(this->edit);
			this->Controls->Add(this->label1);
			this->MaximumSize = System::Drawing::Size(660, 560);
			this->Name = L"HomePage";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"HomePage";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void edit_Click(System::Object^ sender, System::EventArgs^ e) {
		My2tables^ f1 = gcnew My2tables();
		f1->Show();
	}
	private: System::Void look_Click(System::Object^ sender, System::EventArgs^ e) {
		ProgsList^ f1 = gcnew ProgsList();
		f1->Show();
	}
	};
}
