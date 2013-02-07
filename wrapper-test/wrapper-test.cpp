// wrapper-test.cpp: Hauptprojektdatei.

#include "stdafx.h"

using namespace System;
using namespace std;
using namespace LuaWrapper;

int main(array<System::String ^> ^args)
{
	Lua lua;
	// L‰d alle Lua-Standardbibliotheken auﬂer Debug
	lua.loadDefaultLibs(Lua::ALL ^ Lua::DEBUG);
	lua.dofile("hallo.lua");

    system("pause");
    return 0;
}
