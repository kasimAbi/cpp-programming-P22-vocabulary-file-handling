#pragma once
// library einbidnen für fehler abfangen.
#pragma comment(lib, "FehlerAbfangen")
#include"fehler_abfangen.h"
// max_plaetze definieren.
#define max_plaetze 255
// struktur erstellen.
struct Vokabeln
{
	char englisch[GROESSE];
	char deutsch[GROESSE];
};
// VokabelTrainer erst jz einbinden weil die struktur dort benutzt wird.
#include"VokabelTrainer.h"
// funktionsdeklarationen.
void eingeben(Vokabeln*);
void fehlermeldung(void);
void abfragen(int, int, int, int*, Vokabeln*, int&);
void eine_vokabel_aendern(Vokabeln *vokabel, int*, int*, int, Vokabeln *vokabel_array);