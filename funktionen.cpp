#define _CRT_SECURE_NO_WARNINGS
#include"header.h"
#include"fehler_abfangen.h"
#include"VokabelTrainer.h"

// vokabel eingeben funktion
void eingeben(Vokabeln* vokabel)
{
	// Initialisieren/Deklarieren
	char eingabe[GROESSE];
	cout << "Deutsch:   ";
	cin >> eingabe;
	// vokabel als array zeichenkette speichern.
	strcpy(vokabel->deutsch, eingabe);
	cout << "Englisch:  ";
	cin >> eingabe;
	strcpy(vokabel->englisch, eingabe);
}
// fehlermeldung für nciht geöffnet werdende dateien.
void fehlermeldung()
{
	system("cls");
	cout << "Datei konnte nciht geoeffnet werden.\n\n\n";
	system("pause");
}
// funktion um zu bestimmen welche vokabel man ändern möchte
void eine_vokabel_aendern(Vokabeln *vokabel, int *reihe, int *de_eng, int anzahl, Vokabeln *vokabel_array)
{
	int ok = 0, index = 0;
	char eingabe[GROESSE];
	// anzahl bestimmen
	if (anzahl == 0)
	{
		cout << "es sind keine Eintraege vorhanden.\n" << endl;
	}
	else
	{
		// ok = 0 setzen für while schleife
		ok = 0;
		system("cls");
		while (ok == 0)
		{
			// vokabeln ausgeben damit der nutzer einen überblick hat
			cout << "welches moechten sie gerne aendern?" << endl;
			for (index = 0; index < anzahl; index++)
			{
				cout << index + 1 << ". " << vokabel_array[index].deutsch << "\n-. " << vokabel_array[index].englisch << endl << endl;
			}
			cout << "ihre wahl:  ";
			cin >> eingabe;
			if (pruefen_gueltig_integer(eingabe) == 1)
			{
				// reihe ist halt welche vokabel man ändern möchte. danach muss man zwischen eng/de entscheiden
				*reihe = wandeln_integer(eingabe);
				if (*reihe >= 1 && *reihe <= anzahl)
				{
					ok = 0;
					system("cls");
					while (ok == 0)
					{
						cout << " (1) deutsch.\n (2) englisch\n\nwas moechten sie aendern:  ";
						cin >> eingabe;
						if (pruefen_gueltig_integer(eingabe) == 1)
						{
							// hier entscheidet man zwischen de/eng von der reihe
							*de_eng = wandeln_integer(eingabe);
							if (*de_eng != 1 && *de_eng != 2)
							{
								system("cls");
								cout << "fehler gemacht.\n\n";
								ok = 0;
							}
							else
							{
								system("cls");
								cout << "was moechten sie reinschreiben:  ";
								cin >> eingabe;
								// ändert vokabel und gibt array geändert wieder zurück
								if (*de_eng == 1)
								{
									// speichert die englische vokabel normal rein weil sie nciht geändert werden muss und dann die geändert wurde.
									strcpy(vokabel->englisch, vokabel_array[*reihe - 1].englisch);
									strcpy(vokabel->deutsch, eingabe);
								}
								else
								{
									// speichert die deustche vokabel normal rein weil sie nciht geändert werden muss und dann die geändert wurde.
									strcpy(vokabel->deutsch, vokabel_array[*reihe - 1].deutsch);
									strcpy(vokabel->englisch, eingabe);
								}
								// um while schleife zu beenden.
								ok = 1;
							}
						}
						else
						{
							// fehlermeldung
							ok = 0;
							system("cls");
							cout << "ungueltige zahl.\n\n";
						}
					}
				}
				else
				{
					// fehlermeldung
					ok = 0;
					system("cls");
					cout << "ist nicht im wertebereich.\n\n";
				}
			}
			else
			{
				// fehlermeldung
				ok = 0;
				system("cls");
				cout << "ungueltige zahl.\n\n";
			}
		}
	}
}
// vokabeln abfragen
void abfragen(int anzahl, int zufall_reihe, int zufall_de_eng, int* richtige, Vokabeln* vokabel_array, int &loeschen)
{
	// initialisierungen/ deklarationen
	int laenge = 0, laenge_2 = 0, fehler = 0, index = 0;
	char eingabe[GROESSE];
	system("cls");
	if (zufall_de_eng == 0 && anzahl != 0)
	{
		// für die deutsche abfrage
		cout << "deutsch:   " << vokabel_array[zufall_reihe].deutsch << endl;
		cout << "englisch:  ";
		cin >> eingabe;
		// länge der beiden vokabeln bestimmen.
		laenge = strlen(eingabe);
		laenge_2 = strlen(vokabel_array[zufall_reihe].englisch);
		if (laenge != laenge_2)
		{
			//system("cls");
			cout << "die laenge passt nciht überein darum kann das nciht stimmen,\nsie koennen auch einen rechtschreibfehler haben.\n";
			fehler = 1;
			richtige[zufall_reihe] = 0;
		}
		else
		{
			for (index = 0; index < laenge; index++)
			{
				// prüfen ob die zeichen übereinstimmen
				if (toupper(eingabe[index]) == toupper(vokabel_array[zufall_reihe].englisch[index]))
				{
					;
				}
				else
				{
					// system("cls");
					cout << "sie lagen falsch.\n";
					fehler = 1;
					// um for schleife zu beenden.
					index = laenge + 1;
					richtige[zufall_reihe] = 0;
				}
			}
		}
	}
	else
	{
		if (anzahl != 0)
		{
			// für die englische abfrage
			cout << "englisch:  " << vokabel_array[zufall_reihe].englisch << endl;
			cout << "deutsch:   ";
			cin >> eingabe;
			laenge = strlen(eingabe);
			laenge_2 = strlen(vokabel_array[zufall_reihe].deutsch);
			if (laenge != laenge_2)
			{
				// system("cls");
				cout << "die laenge passt nciht überein darum kann das nciht stimmen,\nsie koennen auch einen rechtschreibfehler haben.\n";
				fehler = 1;
				richtige[zufall_reihe] = 0;
			}
			else
			{
				for (index = 0; index < laenge; index++)
				{
					// prüfen ob die zeichen übereinstimmen
					if (toupper(eingabe[index]) == toupper(vokabel_array[zufall_reihe].deutsch[index]))
					{
						;
					}
					else
					{
						// system("cls");
						cout << "sie lagen falsch.\n";
						fehler = 1;
						// um vor schleife zu beenden
						index = laenge + 1;
						richtige[zufall_reihe] = 0;
					}
				}
			}
		}
	}
	// wenn alles richtig ist
	if (fehler == 0)
	{
		// richtige hoch zählen wegen der aufgabe mit 3 richtigen
		richtige[zufall_reihe]++;
		cout << "sie haben diese frage " << richtige[zufall_reihe] << "x richtig beantwortet.\n\n";
		if (richtige[zufall_reihe] == 3)
		{
			for (index = zufall_reihe; index < anzahl; index++)
			{
				// die richtigen variablen sortieren und den platz für die eine entfernte variable mit der danach ersetzen
				richtige[index] = richtige[index + 1];
			}
			loeschen = 1;
		}
	}
}