// Dies ist die Haupt-DLL.

#include "stdafx.h"
#include "LuaWrapper.h"

namespace LuaWrapper {
	Lua::Lua()
	{
		this->state = luaL_newstate();
	}

	void Lua::close()
	{
		lua_close(this->state);
	}

	bool Lua::dofile(System::String^ filename)
	{
		IntPtr p = Marshal::StringToHGlobalAnsi(filename);
		char *pNewCharStr = static_cast<char*>(p.ToPointer());

		return luaL_dofile(this->state, pNewCharStr);
	}

	void Lua::openlibs()
	{
		luaL_openlibs(this->state);
	}
}