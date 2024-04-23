#pragma once
// bibliotheken einbinden.
#include"VokabelTrainer.h"
#include"header.h"
class schnittstelle
{
private:
	// private deklaration/initialisierung.
	int anzahl = 0;
public:
	// funktionsdeklarationen.
	void vokabeln_in_datei_hinzufuegen(Vokabeln);
	int get_anzahl();
	void aendern(Vokabeln*, int, int, int, Vokabeln vokabel);
	Vokabeln* vokabeln_bekommen(Vokabeln*);
	void zeile_loeschen_s(int);
};
