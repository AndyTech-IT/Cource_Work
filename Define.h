#pragma once

#ifndef LIBS_H

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

#endif

#ifndef CLASSES_H
#define CLASSES_H

struct Point2;
enum class Color;
struct Part;
struct PartConnector; 
struct Window_Args;
enum class Part_Type;

#endif

//#ifndef MODULES_H
//#define MODULES_H
//#include "Point2.h"
//#include "Color.h"
//#include "Part.h"
//#include "PartConnector.h"
//#endif // !MODULES_H

/* Сообщения

	MessageBoxW(NULL, L"Текст", L"Ошибка", MB_ICONERROR);
	MessageBoxW(NULL, L"Текст", L"Предупреждение", MB_ICONEXCLAMATION);
	MessageBoxW(NULL, L"Текст", L"Информация", MB_ICONINFORMATION);
	MessageBoxW(NULL, L"Текст", L"Вопрос", MB_ICONQUESTION);
*/
