#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#include "biblioteka.h"

struct REKORD
{
	int id;
	char* marka;
	char* model;
	int rokProdukcji;
	char* kolor;
	int przebieg;
	int cena;
	struct REKORD* next;
	struct REKORD* prev;
};

struct REKORD* first = NULL;
struct REKORD* last = NULL;

void AddRekord(void);
void ShowList(void);
void ShowListOpposite(void);
void WriteList(char*);
void ReadList(char*);
void DeleteRekord(struct REKORD*);
void Website(void);
void ChangeRekord(struct REKORD*, struct REKORD*);
void ReverseList(void);
struct REKORD* AllocateMemory(struct REKORD*);
struct REKORD* FindInt(int, struct REKORD*);
struct REKORD* FindString(char*, struct REKORD*);
int GetIdMax(void);
int CountElements(void);
void SortAlphabetic(void);

void main()
{
	int menu = 0;
	int nr, nr2;
	char nazwa[255];
	struct REKORD* tmp;

	while (1){

		switch (menu){
			case 0:
				printf("1. Operacje na plikach\n");
				printf("2. Modyfikacja listy\n");
				printf("3. Wyswietlanie listy\n");
				printf("4. Wyjscie\n\n");

				scanf("%d", &menu);
			
				system("cls");
				break;

			case 1: // Operacje na plikach
				printf("OPERACJE NA PLIKACH\n\n");
				printf("1. Zapisz liste\n");
				printf("2. Wczytaj liste\n");
				printf("3. Powrot\n\n");

				scanf("%d", &menu);

				system("cls");
				menu += 10;
				break;

				case 11: // Zapisz lsite
					if (first == NULL) {

						printf("Brak listy\n\n");
						menu = 0;
						break;
					}

					printf("Nazwa pliku: ");
					scanf("%s", &nazwa);
					system("cls");

					WriteList(nazwa);

					menu = 0;
					break;

				case 12: // Wczytaj liste
					//TODO: zmienic
					//printf("Nazwa pliku: ");
					//scanf("%s", &nazwa);
					system("cls");

					ReadList("auta.csv");

					menu = 0;
					break;

				case 13: // Powrot
					system("cls");
					menu = 0;
					break;

			case 2: // Modyfikacja listy
				printf("MODYFIKACJA LISTY\n\n");
				printf("1.Dodaj rekord\n");
				printf("2.Usun rekord\n");
				printf("3.Zamien rekord\n");
				printf("4.Odwrocenie listy\n");
				printf("5. Posortuj Alfabetycznie\n");
				printf("6.Powrot\n\n");

				scanf("%d", &menu);

				system("cls");
				menu += 20;
				break;

				case 21: // AddRekord rekord
					AddRekord();

					system("cls");
					menu = 0;
					break;

				case 22: // Usun rekord
					if (first == NULL) {

						printf("Brak listy\n\n");
						menu = 2;
						break;
					}

					ShowList();

					printf("\nPodaj id rekord do usuniecia: ");
					scanf("%d", &nr);
					system("cls");

					if (FindInt(nr, first) != NULL) {

						DeleteRekord(FindInt(nr, first));
						printf("Usunieto rekord o id %d\n\n", nr);
					}

					menu = 0;
					break;


				case 23: // Zamien rekord
					
					if (first == NULL || first == last) {

						printf("Brak listy lub za malo elementow w liscie\n\n");
						menu = 2;
						break;
					}

					printf("Podaj rekordy ktore chcesz zamienic: \nRekord 1: ");
					scanf("%d", &nr);
					printf("Rekord 2: ");
					scanf("%d", &nr2);

					system("cls");

					if (FindInt(nr, first) != NULL || FindInt(nr2, first) != NULL) {

						ChangeRekord(FindInt(nr, first), FindInt(nr2, first));
						printf("Zamienionano rekord %d z %d rekordem.\n\n", nr, nr2);
					}

					menu = 0;
					break;

				case 24: // Odwrocenie listy

					if (first == NULL) {

						printf("Brak listy\n\n");
						menu = 2;
						break;
					}

					ReverseList();

					system("cls");
					menu = 0;
					break;

				case 25: //sortowanie alfabetyczne

					SortAlphabetic();

					system("cls");
					menu = 0;
					break;

				case 26:

					system("cls");
					menu = 0;
					break;

			case 3: // Wyswietlanie listy
				if (first == NULL) {

					printf("Brak listy\n\n");
					menu = 0;
					break;
				}

				printf("WYSWIETLANIE LISTY\n\n");
				printf("1. Wyswietl -> (Od poczatku)\n");
				printf("2. Wyswietl <- (Od konca)\n");
				printf("3. Wyswietl rekord\n");
				printf("4. Wyswietl w przegladarce\n");
				printf("5. Powrot\n\n");

				scanf("%d", &menu);

				system("cls");
				menu += 30;
				break;

				case 31: // Wyswietl ->
					ShowList();

					system("pause");
					system("cls");
					menu = 0;
					break;

				case 32: // Wyswietl <-
					ShowListOpposite();

					system("pause");
					system("cls");
					menu = 0;
					break;

				case 33: // Wyswietl rekord 
					//TODO: wysylanie id,rok,przebieg
					printf("WYSWIETL REKORD\n\n");
					printf("1. Po numerze\n");
					printf("2. Po nazwie\n");
					printf("3. Powrot\n\n");

					scanf("%d", &menu);

					system("cls");
					menu += 330;
					break;

					case 331://Wyswietl po numerze
						printf("Podaj nr: ");
						scanf("%d", &nr);

						system("cls");
						tmp = FindInt(nr, first);

						while (tmp != NULL) {

							printf("%s\t%s\t%d\t%s\t%d\t%d\n", tmp->marka, tmp->model, tmp->rokProdukcji, tmp->kolor, tmp->przebieg, tmp->cena);
							tmp = FindInt(nr, tmp->next);
						}

						system("pause");
						system("cls");
						menu = 0;
						break;

					case 332://Wyswietl po nazwie
						printf("Podaj nazwe: ");
						scanf("%s", &nazwa);

						system("cls");
						tmp = FindString(nazwa, first);

						while (tmp != NULL) {

							printf("%s\t%s\t%d\t%s\t%d\t%d\n", tmp->marka, tmp->model, tmp->rokProdukcji, tmp->kolor, tmp->przebieg, tmp->cena);
							tmp = FindString(nazwa, tmp->next);
						}

						system("pause");
						system("cls");
						menu = 0;
						break;

					case 333:
						system("cls");
						menu = 0;
						break;

				case 34: // Wyswietl w przegladarce
					Website();
					system("tabela.html");

					menu = 0;
					break;
				case 35: // Powrot
					system("cls");
					menu = 0;
					break;

			case 4:
				exit(1);
				break;

			default:
				printf("Blad\n\n");
				menu = 0;
				break;
		}
	}
}

void AddRekord(void) {

	struct REKORD* new = NULL;

	new = AllocateMemory(new);
	
	printf("Podaj marke: ");
	scanf("%s", new->marka);
	printf("Podaj model: ");
	scanf("%s", new->model);
	printf("Podaj rok produkcji: ");
	scanf("%d", &new->rokProdukcji);
	printf("Podaj kolor: ");
	scanf("%s", new->kolor);
	printf("Podaj przebieg: ");
	scanf("%d", &new->przebieg);
	printf("Podaj cene: ");
	scanf("%d", &new->cena);

	if (first == NULL) {

		new->next = NULL;
		new->id = 1;
		new->prev = NULL;

		first = new;
		last = new;
	}
	else {

		new->next = NULL;
		new->prev = last;
		new->id = GetIdMax() + 1;

		last->next = new;
		last = new;
	}

}

void ShowList(void) {

	struct REKORD* temp;

	temp = first;

	printf("ID\tMarka\tModel\tRokProdukcji\tKolor\tPrzebieg\tCena\n\n");
	while (temp != NULL)
	{
		printf("%d\t%s\t%s\t%d\t\t%s\t%d\t\t%d\n",temp->id,temp->marka, temp->model, temp->rokProdukcji, temp->kolor, temp->przebieg, temp->cena);
		temp = temp->next;
	}
	printf("\n");
}

void ShowListOpposite(void) {

	struct REKORD* temp;

	temp = last;

	printf("ID\tMarka\tModel\tRokProdukcji\tKolor\tPrzebieg\tCena\n\n");
	while (temp != NULL)
	{
		printf("%d\t%s\t%s\t%d\t\t%s\t%d\t\t%d\n", temp->id, temp->marka, temp->model, temp->rokProdukcji, temp->kolor, temp->przebieg, temp->cena);
		temp = temp->prev;
	}
	printf("\n");
}

void WriteList(char* nazwa) {

	struct REKORD* temp;
	FILE* zapis;

	temp = first;
	zapis = fopen(nazwa,"w");

	while (temp != NULL)
	{
		fprintf(zapis, "%s;%s;%d;%s;%d;%d\n", temp->marka, temp->model, temp->rokProdukcji, temp->kolor, temp->przebieg, temp->cena);
		temp = temp->next;
	}

	fclose(zapis);

	printf("Plik zapisano pod nazwa %s.\n\n", nazwa);
}

void ReadList(char* nazwa) {

	int i;
	int linie = 0;
	struct REKORD* temp = NULL;
	FILE* odczyt;

	odczyt = fopen(nazwa, "r");

	if (odczyt == NULL){

		printf("Plik nie istnieje\n\n");
		return 0;
	}

	while (!feof(odczyt))
		if (fgetc(odczyt) == '\n')
			linie++;

	rewind(odczyt);
	
	if (first == NULL) {

		temp = AllocateMemory(temp);

		temp->next = NULL;
		temp->id = 1;
		fscanf(odczyt, "%99[^;];%99[^;];%d;%99[^;];%d;%d\n", temp->marka, temp->model, &temp->rokProdukcji, temp->kolor, &temp->przebieg, &temp->cena);
		temp->prev = NULL;

		first = temp;
		last = temp;
		linie--;
	}

	for ( i = 0; i < linie; i++){

		temp = AllocateMemory(temp);

		temp->next = NULL;
		fscanf(odczyt, "%99[^;];%99[^;];%d;%99[^;];%d;%d\n", temp->marka, temp->model, &temp->rokProdukcji, temp->kolor, &temp->przebieg, &temp->cena);
		temp->prev = last;
		temp->id = GetIdMax() + 1;

		last->next = temp;
		last = temp;
	}

	fclose(odczyt);

	printf("Wczytano plik %s\n\n", nazwa);
}

struct REKORD* FindInt(int wanted, struct REKORD* startingRekord) {

	struct REKORD* temp;

	temp = startingRekord; 

	while (temp!=NULL){

		if (temp->id == wanted)
			return temp;

		temp = temp->next;
	}

	if (startingRekord == first)
		printf("Brak rekordu z numerem %d\n\n", wanted);

	return NULL;
}

struct REKORD* FindString(char* wanted, struct REKORD* startingRekord) {

	struct REKORD* temp;

	temp = startingRekord;

	while (temp != NULL) {

		if (strcmp(temp->marka, wanted) == 0)
			return temp;

		temp = temp->next;
	}

	if (startingRekord == first)
		printf("Brak rekordu z nazwa %s\n\n", wanted);

	return NULL;
}

void DeleteRekord(struct REKORD* toDelete) {
	
	if (toDelete == first) {

		first = toDelete->next;
		first->prev = NULL;
	}
	else if (toDelete == last) {

		last = toDelete->prev;
		last->next = NULL;
	}
	else {

		toDelete->prev->next = toDelete->next;
		toDelete->next->prev = toDelete->prev;
	}

	free(toDelete);
}

void ChangeRekord(struct REKORD* old, struct REKORD* new) {

	if (old == NULL || new == NULL) {

		return NULL;
	}

	struct REKORD* temp;
	temp = (struct REKORD*)malloc(sizeof(struct REKORD));

	if (old->next == new || old->prev == new) { //je¿eli rekordy wystepuja obok siebie
		if (old->prev == new) {

			temp = old;
			old = new;
			new = temp;
		}

		if (old == first && new == last) {

			old->prev = new;
			old->next = NULL;

			new->prev = NULL;
			new->next = old;

			last = old;
			first = new;
		}
		else if (old == first) {
			
			old->prev = new;
			old->next = new->next;

			new->next->prev = old;
			new->prev = NULL;
			new->next = old;

			first = new;
		}
		else if (new == last) {

			new->prev = old->prev;
			new->next = old;

			old->prev->next = new;
			old->prev = new;
			old->next = NULL;

			last = old;
		}
		else { //jezeli sa obok siebie ale w srodku
			
			temp->prev = old->prev;

			old->prev->next = new;
			old->prev = new;
			old->next = new->next;

			new->next->prev = old;
			new->prev = temp->prev;
			new->next = old;
		}
	}
	else { // nie sa obok siebie

		if ((old == first && new == last) || (old == last && new == first)) {
			
			if (old == last && new == first) {

				temp = old;
				old = new;
				new = temp;
			}
			
			temp->next = old->next;

			old->next->prev = new;
			old->prev = new->prev;
			old->next = NULL;

			new->prev->next = old;
			new->prev = NULL;
			new->next = temp->next;

			last = old;
			first = new;
		}
		else if (old == first || new == first) {

			if (new == first) {

				temp = old;
				old = new;
				new = temp;
			}
		
			temp->next = old->next;

			old->next->prev = new;
			old->prev = new->prev;
			old->next = new->next;

			new->prev->next = old;
			new->next->prev = old;
			new->prev = NULL;
			new->next = temp->next;

			first = new;
		}
		else if (old == last || new == last) {

			if (old == last) {

				temp = old;
				old = new;
				new = temp;
			}
			
			temp->prev = old->prev;

			old->prev->next = new;
			old->prev = new->prev;
			old->next = new->next;

			new->prev->next = old;
			new->next->prev = old;
			new->prev = temp->prev;
			new->next = NULL;

			last = new;
		}
		else {

			new->next->prev = old;
			new->prev->next = old;
			old->next->prev = new;
			old->prev->next = new;

			temp->prev = old->prev;
			temp->next = old->next;

			old->prev = new->prev;
			old->next = new->next;

			new->prev = temp->prev;
			new->next = temp->next;
		}
	}
}

void Website() {

	struct REKORD* temp;
	FILE* zapis2;

	temp = first;
	zapis2 = fopen("tabela.html", "w");

	fprintf(zapis2, "<html>\n");
	fprintf(zapis2, "<head>\n");
	fprintf(zapis2, "<script type=\"text/javascript\" src=\"https://www.gstatic.com/charts/loader.js\"></script>\n");
	fprintf(zapis2, "<script type=\"text/javascript\">\n");
	fprintf(zapis2, "google.charts.load('current', {'packages':['table']});\n");
	fprintf(zapis2, "google.charts.setOnLoadCallback(drawTable);\n");
	fprintf(zapis2, "function drawTable() {\n");
	fprintf(zapis2, "var data = new google.visualization.DataTable();\n");
	fprintf(zapis2, "data.addColumn('string', 'Marka');\n");
	fprintf(zapis2, "data.addColumn('string', 'Model');\n");
	fprintf(zapis2, "data.addColumn('number', 'RokProdukcji');\n");
	fprintf(zapis2, "data.addColumn('string', 'Kolor');\n");
	fprintf(zapis2, "data.addColumn('number', 'Przebieg');\n");
	fprintf(zapis2, "data.addColumn('number', 'Cena');\n");
	//fprintf(zapis2, "data.addColumn('boolean', 'Full Time Employee');\n");
	fprintf(zapis2, "data.addRows([\n");
	
	while (temp != NULL)
	{
		fprintf(zapis2, "['%s', '%s', {f: '%d'}, '%s', {f: '%d'}, {f: '%d'}],\n", temp->marka, temp->model, temp->rokProdukcji, temp->kolor, temp->przebieg, temp->cena);
		temp = temp->next;
	}
	
	fprintf(zapis2, "] );\n");
	fprintf(zapis2, "var table = new google.visualization.Table(document.getElementById('table_div'));\n");
	fprintf(zapis2, "table.draw(data, { showRowNumber: true, width: '50%c', height: '50%c' });\n",37,37);
	fprintf(zapis2, "}\n");
	fprintf(zapis2, "</script>\n");
	fprintf(zapis2, "</head>\n");
	fprintf(zapis2, "<body>\n");
	fprintf(zapis2, "<div id = \"table_div\"></div>\n");
	fprintf(zapis2, "</body>\n");
	fprintf(zapis2, "</html>\n");
		
	fclose(zapis2);
}

struct REKORD* AllocateMemory(struct REKORD* temp) {

	temp= (struct REKORD*)malloc(sizeof(struct REKORD));
	temp->marka = (char*)malloc(sizeof(char) * 100);
	temp->model = (char*)malloc(sizeof(char) * 100);
	temp->kolor = (char*)malloc(sizeof(char) * 100);

	return temp;
}

void ReverseList(void) {

	int firstElement = 1;
	int lastElement = CountElements();

	while ((lastElement > firstElement))
		ChangeRekord(FindInt(firstElement++, first), FindInt(lastElement--, first));

}

int CountElements(void) {

	int numberOfElements = 0;
	struct REKORD* temp = first;

	while (temp != NULL){

		numberOfElements++;
		temp = temp->next;
	}
	
	return numberOfElements;
}

int GetIdMax(void) {

	int idMax = 0;
	struct REKORD* temp = first;

	while (temp != NULL) {

		if (idMax < temp->id)
			idMax = temp->id;
		temp = temp->next;
	}

	return idMax;
}

void SortAlphabetic(void) {

	struct REKORD* temp = first;
	struct REKORD* temp2 = first->next;


	while (temp2 != NULL)
	{
		if (strcoll(temp->marka, temp2->marka) > 0)
		{
			ChangeRekord(temp, temp2);
			temp = first;
			temp2 = first->next;
		}
		else
		{
			temp = temp->next;
			temp2 = temp2->next;
		}
	}
}