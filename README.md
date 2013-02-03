# Lua-Wrapper für .NET #
Hier soll ein Lua-Wrapper für .NET entstehen. Dieser soll die die C-Bibliothek
von Lua als DLL/Assembly für andere .NET Projekte verfügbar machen.

## Vorüberlegungen ##
Die Entwicklung wird mit C++ in <a 
href="http://www.microsoft.com/visualstudio/deu/products/visual-studio-2010-express">
Visual C++ 2010 Express</a> durchgeführt. Da C eine Untermenge von C++ ist
erwarte ich vergleichsweise geringe Probleme.

Die fertige DLL oder besser das fertige Assembly kann dank
<a href="http://de.wikipedia.org/wiki/.NET#CLR.2C_CIL">CIL</a> in jeder anderen
.NET Sprache benutzt werden.

Gegebenenfalls kann später auch 
<a href="http://www.mono-project.com/Main_Page">mono</a> in die Überlegungen
einbezogen werden. Womit der Wrapper zusätzlich auf den gängisten
Betriebssystemen genutzt werden kann.

## Teile des Repository ##
### Lua-5.2.1 ###
Project um den Lua-Quellcode als statische Bibliothek zu kompilieren. Der
enthaltene Quellcode unterliegt dem Urheberrecht von PUC-Rio und ist unter
einer gesonderten <a href="http://www.lua.org/license.html">Lizenz</a>
freigegeben.

### LuaWrapper ###
Projekt um die Wrapper DLL zu erstellen. Diese überführt die Funktionen der
Lua-Bibliothek in ein objektorientiertes Design.

### wrapper-test ###
CLR-Konsolenanwendung zum Testen der DLL.