#define _CRT_SECURE_NO_WARNINGS
#include"header.h"
#include"fehler_abfangen.h"
#include"VokabelTrainer.h"
// in die datei schreiben
void VoTrainer::vokabel_in_datei(Vokabeln vokabel)
{
	int erfolg = 0, ok = 1;
	// app: datei zum schreiben/ erstellen �ffnen. neue daten werden hinten angeh�ngt.
	datei_schreiben.open("test.txt", ios::app);
	// gibt r�ckgabewert (true/false/1/0) an erfolg zur�ck ob es ge�ffnet werden konnte oder nciht
	erfolg = datei_schreiben.good();
	if (erfolg == 0)
	{
		fehlermeldung();
	}
	else
	{
		// wenn ge�ffnet werden konnte dann wird das in die datei geschrieben
		datei_schreiben << vokabel.deutsch << "\n";
		datei_schreiben << vokabel.englisch << "\n";
		// datei schlie�en
		datei_schreiben.close();
	}
}
// in vokabeln in klasse (array) einf�gen und vokabeln in main bekommen.
Vokabeln* VoTrainer::vokabel_einfuegen_in_main_und_klasse_array(int anzahl, Vokabeln *vokabel_array)
{
	int erfolg = 0, ok = 1, index = 1, index2 = 0;
	Vokabeln zwischenspeicher;
	char eingabe[GROESSE];
	free(vokabeln);
	if (anzahl == 0)
	{
		// f�r den fall das datei nicht ge�ffnet werden k�nnte und damit das programm dann nciht abst�rzt
		vokabeln = new Vokabeln[1];
		vokabel_array = new Vokabeln[1];
	}
	else
	{
		// ansonsten soll er pl�tze reservieren
		vokabeln = new Vokabeln[anzahl];
		vokabel_array = new Vokabeln[anzahl];
		// in: datei wird zum lesen ge�ffnet.
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
				// speichert eine variable von datei in gr��e als zeichenkette und dateipositionszeiger geht dann weiter runter
				datei_schreiben.getline(eingabe, GROESSE);
				erfolg = datei_schreiben.good();
				if (erfolg != 0)
				{
					if (index % 2 == 0)
					{
						// speichert eingabe in struktur
						strcpy(zwischenspeicher.englisch, eingabe);
						// dann f�gt es zwischenspeicher(struktur Vokabeln) in variabeln(struktur Vokabeln als array in klasse)
						vokabeln[index2] = zwischenspeicher;
						vokabel_array[index2] = zwischenspeicher;
						// index2 weil er nur jedesmal index2 hochz�hlt wenn er in variabeln array etwas reinschreibt
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
			// datei schlie�en
			datei_schreiben.close();
		}
	}
	return vokabel_array;
}

// anzahl der zeichenketten in der datei z�hlen
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
			//Pr�fen, ob lesen erfolgreich
			//erfolg = 0 bei Erreichen Fileende
			erfolg = datei_schreiben.good();
			//wenn Dateende nicht erreicht
			// zahl erh�hen f�r anzahl
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
// �ndern von einem fehler
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
			// reihenwahl ist das welche vokabel ge�ndert werden soll und de/eng ist das ob deutsches oder englisches wort ge�ndert werden soll
			if (index == reihenwahl - 1)
			{
				if (de_eng == 1)
				{
					// das ge�nderte in vokabel array speichern und in datei speichern.
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
	// out: l�scht inhalt und �ffnet zum schreiben.
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
			// wenn index die zu l�schende vokabel erreicht dann ersetzt er die stelle mit der n�chsten bis zum schluss.
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
		// array von klasse wieder f�llen.
		vokabeln = new Vokabeln[anzahl + 1];
		datei_schreiben.close();
		// in: �ffnet zum lesen.
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
				//Pr�fen, ob lesen erfolgreich
				//erfolg = 0 bei Erreichen Fileende
				erfolg = datei_schreiben.good();
				//wenn Dateende nicht erreicht
				// zahl erh�hen f�r anzahl
				if (erfolg != 0)
				{
					strcpy(vokabeln[index].deutsch, eingabe_de);
					strcpy(vokabeln[index].englisch, eingabe_eng);
				}
				index++;
			}
			// datei(text) schlie�en.
			datei_schreiben.close();
		}
	}
}