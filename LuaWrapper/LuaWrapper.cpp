/**
* ** LuaWrapper::Lua **
*
* Klassendefinition der Hauptklasse.
**/

#include "stdafx.h"
#include "LuaWrapper.h"

namespace LuaWrapper {
	/**
	* Leerer Konstruktor um automatisch alle Standardbibliotheken zu laden.
	**/
	Lua::Lua()
	{
		this->state = luaL_newstate();
	};

	/**
	* Destuktor
	**/
	Lua::~Lua()
	{
		this->close();
	}

	/**
	* Zerstört den erzeugten Lua-State der Instanz
	**/
	void Lua::close()
	{
		lua_close(this->state);
	}

	/**
	* Übergibt zur Ausführung einen Dateipfad
	**/

	bool Lua::dofile(System::String^ filename)
	{
		return luaL_dofile(this->state, this->string2pChar(filename));
	}

	/**
	* Läd alle Standardbibliotheken
	**/
	void Lua::loadDefaultLibs()
	{
		this->loadDefaultLibs(ALL);
	}

	/**
	* Läd alle durch die Bitmaske definierten Standardbibliotheken
	**/
	void Lua::loadDefaultLibs(const Int32 bitmask)
	{
		static const luaL_Reg libs[] = 
		{
			{ "_G", luaopen_base},
			{ LUA_COLIBNAME, luaopen_coroutine},
			{ LUA_LOADLIBNAME, luaopen_package},
			{ LUA_STRLIBNAME, luaopen_string},
			{ LUA_TABLIBNAME, luaopen_table},
			{ LUA_MATHLIBNAME, luaopen_math},
			{ LUA_BITLIBNAME, luaopen_bit32},
			{ LUA_IOLIBNAME, luaopen_io},
			{ LUA_OSLIBNAME , luaopen_os},
			{ LUA_DBLIBNAME, luaopen_debug},
			{ NULL, NULL}
		};

		Int32 i, iter;
		for (i = 1, iter = 0; libs[iter].func; i <<= 1, iter++)
		{
			if (bitmask & i)
			{
				this->loadLib(libs[iter]);
			}
		}
	}

	/**
	* Läd die übergebene Bibliothek
	**/
	void Lua::loadLib(luaL_Reg lib)
	{
		luaL_requiref(this->state, lib.name, lib.func, true );
		lua_pop(this->state, 1);
	}

	/**
	* Hilfsfunktion: Gibt einen Pointer auf einen unmanaged const char* zurück
	* und erwartet einen managed Syste::String^.
	**/
	const char* Lua::string2pChar(System::String^ string)
	{
		IntPtr p = Marshal::StringToHGlobalAnsi(string);
		return static_cast<char*>(p.ToPointer());
	}
}