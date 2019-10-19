﻿/*
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
//#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include "process.h"
using namespace std;

int main()
{

	cout << "run wordpad.exe" << endl;
	process obj;
	obj.open();

	int n;
	cout << "input 1 to end" << endl;
	cin >> n;
	if (n) {
	
		obj.close(obj.p_id);
	}
	return 0;
}
