#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

enum Pozicija
{
	golman = 1,
	odbrana,
	veza,
	napad
};

struct Podaci
{
	char ime[16];
	char prezime[16];
	int brgod;
};

bool isnumeric(char ime[32])
{
	int brojac = 0;
	int len = strlen(ime);
	for(int i=0; i<len; i++)
	{
		if(isdigit(ime[i]))
			brojac++;
	}
	if(brojac != 0)
	 return true;
	else return false;
}

struct Igrac
{
	Podaci podaci;
	int brdres;
	float cijena;
	Pozicija pozicija;
	//funkcije
	void SetPodaci()
	{
		cin.ignore();
		unosimena:
		cout<<"Unesite ime igraca: ";
		cin.getline(this->podaci.ime, 16, '\n');
		while(cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout<<"Error: Doslo je do greske."<<endl;
			goto unosimena;
		}
		for(int i=0; i<strlen(podaci.ime); i++)
		{
			if(isdigit(podaci.ime[i]) && (strlen(podaci.ime) < 16 && strlen(podaci.ime) > 2))
			{
				cout<<"Error: Brojevi u imenu su zabranjeni!"<<endl;
				goto unosimena;
			}
			else if((strlen(podaci.ime) > 15 || strlen(podaci.ime) < 3))	
			{
				cout<<"Error: Ime ne smije biti duze od 16 ili krace od 3 karaktera.";
				goto unosimena;
			}
			else if(islower(podaci.ime[0]))
			{
				podaci.ime[0] = toupper(podaci.ime[0]);
			}
			else if(podaci.ime[i] == ' ' && islower(podaci.ime[i+1]))
			{
				podaci.ime[i+1] = toupper(podaci.ime[i+1]);
			}		
		}
		/*-----------------------------------------------------------------------------------------*/
		int error;
		do
		{
			error = 0;
			cout<<"Unesite prezime igraca: ";
			cin.getline(this->podaci.prezime, 15, '\n');
			if(cin.fail())
			{
				error = 1;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout<<"Error: Doslo je do greske."<<endl;			
			}
			else if(strlen(podaci.prezime) > 16 || strlen(podaci.prezime) < 3)
			{
				error = 2;
				cout<<"Error: Nije dozvoljeno da prezime ima manje od 3 i vise od 16 karaktera!"<<endl;
			}
			else if(isnumeric(podaci.prezime) == true)
			{
				error = 3;
				cout<<"Error: Brojevi u prezimenu su zabranjeni!"<<endl;
			}	
		}while(error == 1 || error  == 2 || error == 3);
		for(int i=0; i<strlen(podaci.prezime); i++)
		{
			if(islower(podaci.prezime[0]))
			{
				podaci.prezime[0] = toupper(podaci.prezime[0]);
			}
			else if(podaci.prezime[i] == ' ' && islower(podaci.prezime[i+1]))
			{
				podaci.prezime[i+1] = toupper(podaci.prezime[i+1]);
			}
		}
		/*cout<<"Unesite prezime igraca: ";
		cin.getline(this->podaci.prezime, 15, '\n');*/
		/*while(1)
		{
			if(cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout<<"Error: Doslo je do greske."<<endl;
				cout<<"Unesite prezime igraca: ";
				cin.getline(this->podaci.prezime, 16, '\n');
			}
			if(!cin.fail())
			{
				break;
			}
		}*/
		/*while(cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout<<"Error: Doslo je do greske."<<endl;
			cout<<"Unesite prezime igraca: ";
			cin.getline(this->podaci.prezime, 16, '\n');
		}
		while(isnumeric(podaci.prezime, strlen(podaci.prezime)))
		{
			cout<<"Error: Brojevi u prezimenu su zabranjeni!"<<endl;
			cout<<"Ponovo unesite prezime igraca: ";
			cin.getline(this->podaci.prezime, 16, '\n');
		}
		while(strlen(podaci.prezime) > 16 || strlen(podaci.prezime) < 3)
		{
			cout<<"Ponovo unesite prezime igraca (ne smije biti krace od 3 ili duze od 16 karaktera): ";
			cin.getline(this->podaci.prezime, 16, '\n');
		}*/
		/*---------------------------------------------------------------------------------*/
		cout<<"Unesite godine igraca: ";
		cin>>this->podaci.brgod;
		while(cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout<<"Error! Ponovo unesite godine igraca: ";
			cin>>this->podaci.brgod;
		}
	}
	void SetBrDres()
	{
		cout<<"Unesite broj dresa igraca: ";
		cin>>this->brdres;
		while(cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout<<"Error! Ponovo unesite broj dresa igraca: ";
			cin>>this->brdres;
		}
	}
	void SetCijena()
	{
		cout<<"Unesite cijenu igraca: ";
		cin>>this->cijena;
		while(cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout<<"Error! Ponovo unesite cijenu igraca: ";
			cin>>this->cijena;
		}
	}
	void SetPozicija()
	{
		cout<<"[1] Golman | [2] Odbrana | [3] Veza | [4] Napad"<<endl<<"Unesite poziciju igraca: ";
		int x;
		cin>>x;
		this->pozicija = (Pozicija)x;	
	}
	void GetPodaci()
	{
		cout<<"Ime igraca: "<<this->podaci.ime<<endl;
		cout<<"Prezime igraca: "<<this->podaci.prezime<<endl;
		cout<<"Godine igraca: "<<this->podaci.brgod<<endl;
	}
	/*int GetBrDres()
	{
		return this->brdres;
	}*/
	void GetBrDres()
	{
		cout<<"Broj dresa igraca: "<<this->brdres<<endl;
	}
	void GetCijena()
	{
		cout<<"Cijena igraca: "<<this->cijena<<endl;
	}
	void GetPozicija()
	{
		cout<<"Pozicija igraca: ";
		if(this->pozicija == 1)
			cout<<"Golman"<<endl;
		else if(this->pozicija == 2)
			cout<<"Odbrana"<<endl;
		else if(this->pozicija == 3)
			cout<<"Veza"<<endl;
		else if(this->pozicija == 4)
			cout<<"Napad"<<endl;
		else cout<<"Undefined."<<endl;
	}
};

struct Klub
{
	Igrac igrac;
	char nazivKluba[32];
	char grad[32];
	//funkcija
	void UnosIgracaDatoteka()
	{
		fstream file;
		file.open("igraci.txt", ios::app);
		if(file.is_open())
		{
			file<<"Igrac: "<<igrac.podaci.ime<<" "<<igrac.podaci.prezime<<endl;
			file<<"Godina: "<<igrac.podaci.brgod<<endl;
			file<<"Broj dresa: "<<igrac.brdres<<endl;
			file<<"Cijena: "<<igrac.cijena<<endl;
			if(igrac.pozicija == 1)
				file<<"Pozicija: Golman"<<endl;
			else if(igrac.pozicija == 2)
				file<<"Pozicija: Odbrana"<<endl;
			else if(igrac.pozicija == 3)
				file<<"Pozicija: Veza"<<endl;
			else if(igrac.pozicija == 4)
				file<<"Pozicija: Napad"<<endl;
			else file<<"Pozicija: Undefined"<<endl;
			//file<<"Pozicija: "<<igrac.pozicija<<endl;
			cin.ignore();
			cout<<"Unesite naziv kluba: ";
			cin.getline(this->nazivKluba, 32);
			for(int i=0; i<strlen(nazivKluba); i++)
			{
				if(islower(nazivKluba[0]))
				{
					nazivKluba[0] = toupper(nazivKluba[0]);
				}
				else if(nazivKluba[i] == ' ' && islower(nazivKluba[i+1]))
				{
					nazivKluba[i+1] = toupper(nazivKluba[i+1]);
				}
			}
			cout<<"Unesite grad u kojem se klub nalazi: ";
			cin.getline(this->grad, 32);
			for(int i=0; i<strlen(grad); i++)
			{
				if(islower(grad[0]))
				{
					grad[0] = toupper(grad[0]);
				}
				else if(grad[i] == ' ' && islower(grad[i+1]))
				{
					grad[i+1] = toupper(grad[i+1]);
				}
			}			
			file<<"Klub: "<<nazivKluba<<" iz grada "<<grad<<endl;
			file<<"------------------------------------------"<<endl;
		}
		else cout<<"File ne postoji!";
		file.close();
	}
};

//globalne funkcije
void PregledIgraca()
{
	system("CLS");
	cout<<"~~Pregled svih igraca u sistemu~~"<<endl;
	string line;
	ifstream file;
	file.open("igraci.txt");
	if(file.is_open())
	{
		while(getline(file, line))
		{
			cout<<line<<endl;
		}
	}else cout<<"File ne postoji!";
	file.close();
}
void unosIgraca(Igrac &i)
{
	system("CLS");
	Klub k;
	cout<<"~~Unos igraca u sistem~~"<<endl;
	k.igrac.SetPodaci();
	k.igrac.SetBrDres();
	k.igrac.SetCijena();
	k.igrac.SetPozicija();
	k.igrac.GetPozicija();
	k.UnosIgracaDatoteka();
}
float rastCijene2(float cj, int godugovora)
{
	const float temp = cj;
	static float rez = 0;
	if(godugovora == 0)
	{
		cout<<"Cijena igraca nakon unesenog broja godina: "<<rez<<endl;
		rez = 0;
	}	
	else
	{
		rez = rez + temp + (temp/10)*godugovora;
		godugovora--;
		rastCijene2(cj, godugovora);
	}
}
float rastCijene(Igrac *i, int n)
{
	system("CLS");
	cout<<"~~Sistem za utvrdjivanje cijene igraca~~"<<endl;
	cout<<"Unesite ime igraca: ";
	cin.ignore();
	i = new Igrac;
	cin.getline(i->podaci.ime, 16);
	string rijec;
	int godugovora;
	float cj;
	ifstream file;
	file.open("igraci.txt");
	if(file.is_open())
	{
		while(!file.eof())
		{
			file>>rijec;
			if(rijec == i->podaci.ime)
			{
				while(rijec != "------------------------------------------")
				{
					file>>rijec;
					if(rijec == "Cijena:")
					{
						file>>cj;
						cout<<"Cijena unesenog igraca: "<<cj<<endl;
						cout<<"Unesite broj godina ugovora: ";
						cin>>godugovora;
						rastCijene2(cj, godugovora);
						delete i;
					}	
				}
			}
		}
	}else cout<<"File ne postoji!";
}
void menu(int &broj, Igrac &i)
{
	cout<<"~~Sistem kluba~~"<<endl;
	cout<<"[1] Unos igraca u sistem"<<endl;
	cout<<"[2] Ispis svih igraca u sistemu"<<endl;
	cout<<"[3] Cijena igraca nakon nekoliko godina"<<endl;
	cout<<"Unesite broj opcije: ";
	cin>>broj;
	while(cin.fail())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		system("CLS");
		menu(broj, i);
	}
	if(broj < 1 || broj > 3)
	{
		system("CLS");
		menu(broj, i);
	}
	else if(broj == 1)
	{
		unosIgraca(i);
		system("PAUSE");
		system("CLS");
		menu(broj, i);
	}
	else if(broj == 2)
	{
		PregledIgraca();
		system("PAUSE");
		system("CLS");
		menu(broj, i);
	}
	else if(broj == 3)
	{
		int n;
		Igrac *ig;
		rastCijene(ig, n);
		system("PAUSE");
		system("CLS");
		menu(broj, i);
	}
}

int main()
{
	int broj;
	Igrac *i = new Igrac;
	menu(broj, *i);
	delete i;
	return 0;
}
