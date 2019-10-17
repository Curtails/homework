/*
 * This file is part of the Task manager project.
 * Copyright (C) 2019 Curtails
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once
#include <windows.h>
#include <iostream>
#include <cstdio>
#include "Tlhelp32.h"
#include "tchar.h"
#include <stdio.h>
#include <string.h>
#include "process.h"

namespace test {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm()
		{
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:



	private: System::Windows::Forms::ToolStripMenuItem^ 关于ToolStripMenuItem;
	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader2;
	private: System::Windows::Forms::ColumnHeader^ columnHeader3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button2;


	
	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->关于ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->关于ToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(501, 27);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// 关于ToolStripMenuItem
			// 
			this->关于ToolStripMenuItem->Name = L"关于ToolStripMenuItem";
			this->关于ToolStripMenuItem->Size = System::Drawing::Size(91, 23);
			this->关于ToolStripMenuItem->Text = L"注意事项";
			this->关于ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::关于ToolStripMenuItem_Click);
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->columnHeader1, this->columnHeader2,
					this->columnHeader3
			});
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(13, 62);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(477, 448);
			this->listView1->TabIndex = 1;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listView1_SelectedIndexChanged);
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"进程";
			this->columnHeader1->Width = 167;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"PID";
			this->columnHeader2->Width = 94;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"线程数";
			this->columnHeader3->Width = 206;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(414, 516);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 28);
			this->button1->TabIndex = 2;
			this->button1->Text = L"结束";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 30);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(378, 25);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"C:\\Windows\\System32\\notepad.exe";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(414, 31);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 25);
			this->button2->TabIndex = 4;
			this->button2->Text = L"运行";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(501, 556);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"一个简单的任务管理器";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

		}
	private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

		}

		   //结束按钮
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		process obj;
		int Index = 0;
		for (int i = 0; i < p_num; i++) {
			
			if (listView1->SelectedItems->Count > 0) {
				Index = listView1->SelectedItems[0]->Index;
				listView1->Items[Index]->Remove();
				obj.close(temp1[i]);
			}
		}

	}
		   //开始按钮
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			string str;
			ConvertToString(textBox1->Text, str);	//system::string 转 std::string

			std::wstring widstr = std::wstring(str.begin(), str.end());
			const wchar_t* pwidstr = widstr.c_str();	//std::string 转 wchar_t

			process obj;	//实例对象
			wcscpy_s(obj.test, pwidstr);	//赋值路径
			obj.open();	//创建进程
					
			string str1;
			obj.Wchar_tToString(str1, obj.p_name);	//进程名(wchat) 转std::string

			String^ net_s1 = gcnew String(str1.c_str());	//std::string 转System::String

			listView1->Items->Add(net_s1);		//使用Add方法向控件中添加数据
			listView1->Items[p_num]->SubItems->Add(obj.p_id.ToString());
			listView1->Items[p_num]->SubItems->Add(obj.p_threadid.ToString());
			temp1[p_num] = obj.p_id;	//进程id存储
			p_num++;
		}

		   //textbox值改变
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

		}
	private: System::Void 关于ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			MessageBox::Show("输入路径(路径不能含有空格)点击运行按钮运行进程 选中进程点击结束按钮结束进程", "注意事项");
			
	}
};
}
