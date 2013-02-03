// wrapper-test.cpp: Hauptprojektdatei.

#include "stdafx.h"
//#include "..\LuaWrapper\LuaWrapper.h"

using namespace System;
using namespace LuaWrapper;

int main(array<System::String ^> ^args)
{
	Lua lua;
	lua.openlibs();
	lua.dofile("hallo.lua");
	lua.close();

    std::system("pause");
    return 0;
}
