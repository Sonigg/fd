#include <iostream>
#include <fstream>
#include <string>

int potato = 0; std::string names ="0";

namespace Mi {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)//функция при запуске
		{
            Foods(potato,names);
			InitializeComponent();
			Potato_v(potato,names);

		}
	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	public:
	 System::Windows::Forms::TextBox^ textBox1;
	 System::Windows::Forms::Button^ button;
	 System::Windows::Forms::Button^ button2;
	 System::Windows::Forms::TextBox^ name;
	protected:
	 System::Windows::Forms::Label^ label;

	 System::ComponentModel::Container^ components;

		void InitializeComponent(void)//отрисовка компонентов
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->name = (gcnew System::Windows::Forms::TextBox());
			this->label = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(170, 38);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(28, 27);
			this->textBox1->TabIndex = 0;
			this->textBox1->TabStop = false;
			// 
			// button
			// 
			this->button->BackColor = System::Drawing::Color::Azure;
			this->button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button->Location = System::Drawing::Point(214, 32);
			this->button->Name = L"button";
			this->button->Size = System::Drawing::Size(55, 40);
			this->button->TabIndex = 1;
			this->button->TabStop = false;
			this->button->Text = L"+";
			this->button->UseVisualStyleBackColor = false;
			this->button->Click += gcnew System::EventHandler(this, &MyForm::button_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Azure;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(289, 32);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(55, 40);
			this->button2->TabIndex = 2;
			this->button2->TabStop = false;
			this->button2->Text = L"-";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// name
			// 
			this->name->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->name->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->name->Location = System::Drawing::Point(31, 40);
			this->name->Name = L"name";
			this->name->Size = System::Drawing::Size(100, 27);
			this->name->TabIndex = 3;
			// 
			// label
			// 
			this->label->AutoSize = true;
			this->label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label->Location = System::Drawing::Point(137, 38);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(27, 29);
			this->label->TabIndex = 4;
			this->label->Text = L"=";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(415, 486);
			this->Controls->Add(this->label);
			this->Controls->Add(this->name);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Food";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void Potato_v(int potato,std::string names)//вывод переменной 
		{ 
			textBox1->Text =System::Convert::ToString(potato);
			//name->Text = System::Convert::ToString(names); тут ошибка

		}

		void Foods(int &potato,std::string &names) {//берет значение из txt при запуске
			std::fstream ist;
			ist.open("Текст.txt", std::ifstream::in);
			ist >> potato >> names;
			ist.close();
		}

		void End(int potato,std::string names) {//вносит изменения в txt
			std::fstream ist;
			ist.open("Текст.txt", std::ifstream::out);
			ist << potato << " " << names;
			ist.close();
		}

		System::Void button_Click(System::Object^ sender, System::EventArgs^ e) {//кнопка плюс
			potato++;
			End(potato,names);
			Potato_v(potato,names);
		};
		System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {//кнопка минус
			if (potato == 0) {}
			else {
				potato--;
				End(potato,names);
				Potato_v(potato,names);
			}
		};
    };
}
