#pragma once

#include <Windows.h>
#include <cstdio>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <shobjidl.h> 
using namespace std;

#define DEBUG false

struct Point2;
enum class Color;
struct Part;
struct PartConnector; 
struct Window_Args;
enum class Part_Type;

//#ifndef MODULES_H
//#define MODULES_H
//#include "Point2.h"
//#include "Color.h"
//#include "Part.h"
//#include "PartConnector.h"
//#endif // !MODULES_H

/* ���������

	MessageBoxW(NULL, L"�����", L"������", MB_ICONERROR);
	MessageBoxW(NULL, L"�����", L"��������������", MB_ICONEXCLAMATION);
	MessageBoxW(NULL, L"�����", L"����������", MB_ICONINFORMATION);
	MessageBoxW(NULL, L"�����", L"������", MB_ICONQUESTION);
*/
