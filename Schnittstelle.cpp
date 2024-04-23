#include"header.h"
#include"fehler_abfangen.h"
#include"VokabelTrainer.h"
#include<time.h>
#include"Schnittstelle.h"

VoTrainer voTraining;
// vokabeln in datei(text) speicehrn.
void schnittstelle::vokabeln_in_datei_hinzufuegen(Vokabeln vokabel)
{
	// vokabeln in datei hinzufügen.
	voTraining.vokabel_in_datei(vokabel);
}
// wenn anzahl = 0 dann konnte die datei nciht geöffnet werden.
int schnittstelle::get_anzahl()
{
	// anzahl bekommen
	voTraining.anzahl_vokabeln(&anzahl);
	return anzahl;
}
// vokabeln in main bekommen.
Vokabeln* schnittstelle::vokabeln_bekommen(Vokabeln *vokabel_array)
{
	// speicher füllen. also array in klasse füllen so gesehen. die daten werden von der datei rausgeholt
	voTraining.anzahl_vokabeln(&anzahl);
	vokabel_array = voTraining.vokabel_einfuegen_in_main_und_klasse_array(anzahl, vokabel_array);
	return vokabel_array;
}
// ändern funktion aufrufen.
void schnittstelle::aendern(Vokabeln* vokabel_array, int reihenwahl, int de_eng, int anzahl, Vokabeln vokabel)
{
	// vokabeln ändern in datei.
	voTraining.vokabeln_aendern(vokabel_array, reihenwahl, de_eng, anzahl, vokabel);
}
// eine zeile bzw vokabel löschen.
void schnittstelle::zeile_loeschen_s(int zufall_reihe)
{
	// zeile löschen wenn eine frage 3 mal richtig beantwortet wurde.
	voTraining.anzahl_vokabeln(&anzahl);
	voTraining.zeile_loeschen(zufall_reihe, anzahl);
}