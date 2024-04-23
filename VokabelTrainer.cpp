#define _CRT_SECURE_NO_WARNINGS
#include"header.h"
#include"fehler_abfangen.h"
#include"VokabelTrainer.h"
// in die datei schreiben
void VoTrainer::vokabel_in_datei(Vokabeln vokabel)
{
	int erfolg = 0, ok = 1;
	// app: datei zum schreiben/ erstellen öffnen. neue daten werden hinten angehängt.
	datei_schreiben.open("test.txt", ios::app);
	// gibt rückgabewert (true/false/1/0) an erfolg zurück ob es geöffnet werden konnte oder nciht
	erfolg = datei_schreiben.good();
	if (erfolg == 0)
	{
		fehlermeldung();
	}
	else
	{
		// wenn geöffnet werden konnte dann wird das in die datei geschrieben
		datei_schreiben << vokabel.deutsch << "\n";
		datei_schreiben << vokabel.englisch << "\n";
		// datei schließen
		datei_schreiben.close();
	}
}
// in vokabeln in klasse (array) einfügen und vokabeln in main bekommen.
Vokabeln* VoTrainer::vokabel_einfuegen_in_main_und_klasse_array(int anzahl, Vokabeln *vokabel_array)
{
	int erfolg = 0, ok = 1, index = 1, index2 = 0;
	Vokabeln zwischenspeicher;
	char eingabe[GROESSE];
	free(vokabeln);
	if (anzahl == 0)
	{
		// für den fall das datei nicht geöffnet werden könnte und damit das programm dann nciht abstürzt
		vokabeln = new Vokabeln[1];
		vokabel_array = new Vokabeln[1];
	}
	else
	{
		// ansonsten soll er plätze reservieren
		vokabeln = new Vokabeln[anzahl];
		vokabel_array = new Vokabeln[anzahl];
		// in: datei wird zum lesen geöffnet.
		datei_schreiben.open("test.txt", ios::in);
		erfolg = datei_schreiben.good();
		if (erfolg == 0)
		{
			;
		}
		else
		{
			while (erfolg != 0)
			{
				// speichert eine variable von datei in größe als zeichenkette und dateipositionszeiger geht dann weiter runter
				datei_schreiben.getline(eingabe, GROESSE);
				erfolg = datei_schreiben.good();
				if (erfolg != 0)
				{
					if (index % 2 == 0)
					{
						// speichert eingabe in struktur
						strcpy(zwischenspeicher.englisch, eingabe);
						// dann fügt es zwischenspeicher(struktur Vokabeln) in variabeln(struktur Vokabeln als array in klasse)
						vokabeln[index2] = zwischenspeicher;
						vokabel_array[index2] = zwischenspeicher;
						// index2 weil er nur jedesmal index2 hochzählt wenn er in variabeln array etwas reinschreibt
						index2++;
					}
					else
					{
						//speichert eingabe (welches von datei geholt wurde) in struktur
						strcpy(zwischenspeicher.deutsch, eingabe);
					}
				}
				index++;
			}
			// datei schließen
			datei_schreiben.close();
		}
	}
	return vokabel_array;
}

// anzahl der zeichenketten in der datei zählen
void VoTrainer::anzahl_vokabeln(int* anzahl)
{
	// initialisierungen/ deklarationen.
	int erfolg = 0, ok = 1, zahl = 0, index = 0;
	char eingabe[GROESSE];
	datei_schreiben.open("test.txt", ios::in);
	erfolg = datei_schreiben.good();
	if (erfolg == 0)
	{
		*anzahl = 0;
	}
	else
	{
		while (erfolg != 0)
		{
			//liest kompletten String
			//datei_schreiben >> eingabe;             
			//liest nur bis zum ersten Leerzeichen
			datei_schreiben.getline(eingabe, GROESSE);
			//Prüfen, ob lesen erfolgreich
			//erfolg = 0 bei Erreichen Fileende
			erfolg = datei_schreiben.good();
			//wenn Dateende nicht erreicht
			// zahl erhöhen für anzahl
			if (erfolg != 0)
			{
				zahl++;
			}
		}
		datei_schreiben.close();
		// geteilt durch zwei weil oben jede zeile dazu addiert wird.
		zahl /= 2;
		*anzahl = zahl;
		datei_schreiben.close();
	}
}
// ändern von einem fehler
void VoTrainer::vokabeln_aendern(Vokabeln* vokabel_array, int reihenwahl, int de_eng, int anzahl, Vokabeln vokabel)
{
	// initialisierungen/ deklarationen.
	int erfolg = 0, ok = 0, index = 0;
	datei_schreiben.open("test.txt", ios::out);
	erfolg = datei_schreiben.good();
	if (erfolg == 0)
	{
		;
	}
	else
	{
		for (index = 0; index < anzahl; index++)
		{
			// reihenwahl ist das welche vokabel geändert werden soll und de/eng ist das ob deutsches oder englisches wort geändert werden soll
			if (index == reihenwahl - 1)
			{
				if (de_eng == 1)
				{
					// das geänderte in vokabel array speichern und in datei speichern.
					datei_schreiben << vokabel.deutsch << "\n";
					datei_schreiben << vokabeln[index].englisch << "\n";
				}
				else
				{
					// hier das selbe
					datei_schreiben << vokabeln[index].deutsch << "\n";
					datei_schreiben << vokabel.englisch << "\n";
				}
			}
			else
			{
				// daten reinschreiben
				datei_schreiben << vokabeln[index].deutsch << "\n";
				datei_schreiben << vokabeln[index].englisch << "\n";
			}
		}
		datei_schreiben.close();
	}
}

void VoTrainer::zeile_loeschen(int zufall_reihe, int anzahl)
{
	// initialisierungen/ deklarationen
	int erfolg = 0, ok = 1, index = 0;
	char eingabe_de[GROESSE];
	char eingabe_eng[GROESSE];
	Vokabeln zwischenspeicher;
	// out: löscht inhalt und öffnet zum schreiben.
	datei_schreiben.open("test.txt", ios::out);
	erfolg = datei_schreiben.good();
	if (erfolg == 0)
	{
		// fehlermeldung
		;
	}
	else
	{
		// anzahl - 1 weil es am ende eine vokabel weniger gibt.
		for (index = 0; index < anzahl - 1; index++)
		{
			// wenn index die zu löschende vokabel erreicht dann ersetzt er die stelle mit der nächsten bis zum schluss.
			if (index >= zufall_reihe)
			{
				vokabeln[index] = vokabeln[index + 1];
			}
		}
		for (index = 0; index < anzahl - 1; index++)
		{
			// vokabeln neu in datei(text) schreiben.
			zwischenspeicher = vokabeln[index];
			datei_schreiben << zwischenspeicher.deutsch << "\n";
			datei_schreiben << zwischenspeicher.englisch << "\n";
		}
		anzahl--;
		free(vokabeln);
		// array von klasse wieder füllen.
		vokabeln = new Vokabeln[anzahl + 1];
		datei_schreiben.close();
		// in: öffnet zum lesen.
		datei_schreiben.open("test.txt", ios::in);
		erfolg = datei_schreiben.good();
		if (erfolg == 0)
		{
			fehlermeldung();
		}
		else
		{
			index = 0;
			while (erfolg != 0)
			{
				//liest kompletten String
				//datei_schreiben >> eingabe;             
				//liest nur bis zum ersten Leerzeichen
				datei_schreiben.getline(eingabe_de, GROESSE);
				datei_schreiben.getline(eingabe_eng, GROESSE);
				//Prüfen, ob lesen erfolgreich
				//erfolg = 0 bei Erreichen Fileende
				erfolg = datei_schreiben.good();
				//wenn Dateende nicht erreicht
				// zahl erhöhen für anzahl
				if (erfolg != 0)
				{
					strcpy(vokabeln[index].deutsch, eingabe_de);
					strcpy(vokabeln[index].englisch, eingabe_eng);
				}
				index++;
			}
			// datei(text) schließen.
			datei_schreiben.close();
		}
	}
}