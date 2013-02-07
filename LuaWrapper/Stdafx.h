// stdafx.h : Includedatei für Standardsystem-Includedateien
// oder häufig verwendete projektspezifische Includedateien,
// die nur in unregelmäßigen Abständen geändert werden.

#pragma once
extern "C" {
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
	#include "lstate.h" // Deklaration für struct lua_State
}