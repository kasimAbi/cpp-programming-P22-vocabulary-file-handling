#include"header.h"
#include"fehler_abfangen.h"
#include"VokabelTrainer.h"
#include<time.h>
#include"Schnittstelle.h"
//main
void main()
{
	// initialisierungen/deklarationen
	char eingabe[GROESSE];
	int anzahl = 0, index = 0, aendern_reihe = 0, aendern_de_eng = 0, zufall_reihe = 0, zufall_de_eng = 0, fehler = 0, loeschen = 0, richtige[100] = { 0 };
	Vokabeln vokabel, *vokabel_array;
	schnittstelle schnitt_s;
	VoTrainer voTraining;
	time_t zeit;
	// Zufallsgenerator initialisieren
	srand(time(&zeit));
	// menü
	while (eingabe[0] != '4')
	{
		// menü
		cout << "waehlen sie:\n (1) Vokabeln eingeben.\n (2) Vokabeln aendern.\n (3) Vokabeln lernen.\n (4) Programm beenden.\n (5) Vokabeln anzeigen.\n\nwahl:  ";
		cin >> eingabe;
		switch (eingabe[0])
		{
		case '1':
			system("cls");
			cout << "Vokabeln eingeben.\n" << endl;
			// vokabeln eingeben und das wird dann mit adresse geschickt so das die zeichenkette direkt in der main gespeichert wird.
			eingeben(&vokabel);
			// die eingegebenen vokabeln in datei(text) hinzufügen.
			schnitt_s.vokabeln_in_datei_hinzufuegen(vokabel);
			// anzahl der gespeicherten vokabeln bekommen.
			anzahl = schnitt_s.get_anzahl();
			// die vokabeln von der text datei bekommen
			vokabel_array = schnitt_s.vokabeln_bekommen(vokabel_array);
			system("cls");
			cout << "ihre Vokabel wurde hinzugefuegt:\n\n";
			for (index = 0; index < schnitt_s.get_anzahl(); index++)
			{
				cout << "deutsch:  " << vokabel_array[index].deutsch << "\nenglisch:  " << vokabel_array[index].englisch << "\n\n";
			}
			free(vokabel_array);
			break;
		case '2':
			system("cls");
			// vokabeln von datei(text) die gespeichert wurden bekommen. und dann die anzahl der vorhandenen vokabeln.
			vokabel_array = schnitt_s.vokabeln_bekommen(vokabel_array);
			anzahl = schnitt_s.get_anzahl();
			// zum ändern abfragen wo was geändert werden soll.
			eine_vokabel_aendern(&vokabel, &aendern_reihe, &aendern_de_eng, anzahl, vokabel_array);
			// in der datei(text) ändern und anschließend die neuen vokabeln bekommen.
			schnitt_s.aendern(vokabel_array, aendern_reihe, aendern_de_eng, anzahl, vokabel);
			vokabel_array = schnitt_s.vokabeln_bekommen(vokabel_array);
			if (schnitt_s.get_anzahl() != 0)
			{
				system("cls");
				cout << "ihre Vokabeln:\n\n";
			}
			for (index = 0; index < schnitt_s.get_anzahl(); index++)
			{
				cout << "deutsch:  " << vokabel_array[index].deutsch << "\nenglisch:  " << vokabel_array[index].englisch << "\n\n";
			}
			// array speicher wieder freigeben
			free(vokabel_array);
			break;
		case '3':
			system("cls");
			vokabel_array = schnitt_s.vokabeln_bekommen(vokabel_array);
			anzahl = schnitt_s.get_anzahl();
			if (anzahl != 0)
			{
				// zum abfragen die reihe wählen. (durch zufall)
				zufall_reihe = rand() % anzahl;
				cout << "druecken sie enter wenn sie bereit sind.\n\n\n";
				system("pause");
			}
			while (eingabe[0] != 'n')
			{
				if (anzahl != 0)
				{
					// zum abfragen ob deutsche oder englische vokabeln.
					zufall_de_eng = rand() % 2;
					// fragt ab.
					abfragen(anzahl, zufall_reihe, zufall_de_eng, richtige, vokabel_array, loeschen);
					// löschen addresse wird mitgegeben und dadurch wird  geguckt ob die vokabel 3 mal richtig gemacht wurde. wenn ja dann löschen = 1.
					if (loeschen == 1)
					{
						// bei 3 richtigen diese vokabel entfernen
						schnitt_s.zeile_loeschen_s(zufall_reihe);
						// weil eine vokabel gelöscht wird.
						anzahl--;
						// vokabeln von datei holen. lööschen wieder zurücksetzen für nächsten durchgänge.
						vokabel_array = schnitt_s.vokabeln_bekommen(vokabel_array);
						loeschen = 0;
					}
					if (anzahl != 0)
					{
						// für nächste abfrage wenn vokabeln noch vorhanden sind.
						zufall_reihe = rand() % anzahl;
					}
					cout << "moechten sie weiter dran arbeiten?\n (n) nein.\n sonstiges ist ja.\n\nwahl:  ";
					cin >> eingabe;
				}
				else
				{
					system("cls");
					eingabe[0] = 'n';
					cout << "keine Vokabeln mehr vorhanden.\n\n\n";
				}
			}
			break;
		case '4':
			system("cls");
			cout << "Programm wird nun beendet.\n\n";
			break;
		case '5':
			system("cls");
			// vokabeln anzeigen. vokabeln erst von der datei(text) holen und sie dann ausgeben.
			vokabel_array = schnitt_s.vokabeln_bekommen(vokabel_array);
			anzahl = schnitt_s.get_anzahl();
			if (anzahl != 0)
			{
				for (index = 0; index < schnitt_s.get_anzahl(); index++)
				{
					cout << "deutsch:  " << vokabel_array[index].deutsch << "\nenglisch:  " << vokabel_array[index].englisch << "\n\n";
				}
			}
			else
			{
				cout << "es sind keine Vokabeln vorhanden.\n\n";
			}
			break;
		default:
			system("cls");
			cout << "Ungueltige Eingabe!\n\n";
		}
		cout << "\n\n\n";
		system("pause");
		system("cls");
	}
}