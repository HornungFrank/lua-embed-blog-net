// stdafx.h : Includedatei f�r Standardsystem-Includedateien
// oder h�ufig verwendete projektspezifische Includedateien,
// die nur in unregelm��igen Abst�nden ge�ndert werden.

#pragma once
extern "C" {
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
	#include "lstate.h" // Deklaration f�r struct lua_State
}