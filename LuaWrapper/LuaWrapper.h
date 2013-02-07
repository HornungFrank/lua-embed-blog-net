/**
* ** LuaWrapper::Lua **
*
* Klassendeklaration der Hauptklasse.
**/

#pragma once
#include "Lua_Library.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace LuaWrapper {

	public ref class Lua
	{
	private:
		/**
		* Klassenmember
		**/
		lua_State* state;
		
		/**
		* Luafunktionen
		**/
		void close();

		/**
		* Hilfsmethoden
		**/
		const char* string2pChar(System::String^);

	public:
		/**
		* Klassenkonstanten für Bitmaske
		**/
		static const int BASIC		= 1;
		static const int COROUTINE	= 2;
		static const int PACKAGE	= 4;
		static const int STRING		= 8;
		static const int TABLE		= 16;
		static const int MATH		= 32;
		static const int BIT32		= 64;
		static const int IO			= 128;
		static const int OS			= 256;
		static const int DEBUG		= 512;
		static const int ALL		= 1023;

		/**
		* Konstruktor & Destruktor
		**/
		Lua();
		~Lua();

		/**
		* Luafunktionen
		**/
		void loadDefaultLibs();
		void loadDefaultLibs(const int);
		void loadLib(luaL_Reg);
		bool dofile(System::String^);
	};
}
