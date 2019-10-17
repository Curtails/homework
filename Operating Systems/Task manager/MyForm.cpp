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
#include "MyForm.h"
#include "process.h"

using namespace test;//使锟斤拷MyForm.h锟叫讹拷锟斤拷锟斤拷锟斤拷锟秸硷拷

[STAThread]//锟斤拷锟竭筹拷锟斤拷锟皆ｏ拷锟斤拷些锟斤拷锟揭拷锟斤拷叱锟�

int main()
{
	Application::EnableVisualStyles();
	System::Windows::Forms::Application::Run(gcnew test::MyForm());

	return 0;
}