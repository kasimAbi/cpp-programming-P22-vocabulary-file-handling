#pragma once
#ifndef VokabelTrainer_h
#define VokabelTrainer_h
// bibliotheken einbinden.
#include"header.h"
#include"fehler_abfangen.h"
#include<fstream>
// klasse VoTrainer
class VoTrainer
{
private:
	// private deklarationen
	Vokabeln *vokabeln;
	fstream datei_schreiben;		//deklaration eines Objektes datei_schreiben der Klasse fstream

public:
	// funktionsdeklarationen
	void vokabel_in_datei(Vokabeln);
	Vokabeln* vokabel_einfuegen_in_main_und_klasse_array(int, Vokabeln*);
	void vokabeln_aendern(Vokabeln*, int, int, int, Vokabeln vokabel);
	void anzahl_vokabeln(int*);
	void zeile_loeschen(int, int);
};
#endif