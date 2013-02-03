// LuaWrapper.h

#pragma once
#include "lua.hpp"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace LuaWrapper {

	public ref class Lua
	{
	private:
		lua_State *state;
    
	public:
		Lua();
		void close();
		bool dofile(System::String^ filename);
		void openlibs();
	};
}
