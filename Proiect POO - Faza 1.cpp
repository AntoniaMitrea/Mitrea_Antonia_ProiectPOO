#include <iostream>
#include <cstring>

using namespace std;

class Film {
public:
    string nume;
    char* gen;
    const int anAparitie;
    int durata;
    float rating;
    float pret;
    static float reducereElevi;
    
    void afisare() {
        cout << "Nume = " << this->nume << endl;
        cout << "Gen = " << this->gen << endl;
        cout << "Anul aparitiei = " << this->anAparitie << endl;
        cout << "Durata = " << this->durata << " minute" << endl;
        cout << "Rating = " << this->rating << " / 10 " << endl;
        cout << "Pret = " << this->pret << " lei" << endl;
        cout << "Reducere pentru elevi = " << this->reducereElevi << "%" << endl;
        cout << endl << endl;
    }
    
    Film():anAparitie(1997) {
        this->nume = "Titanic";
        this->gen = new char[strlen("Dragoste")+1];
        strcpy(this->gen, "Dragoste");
        this->durata = 196;
        this->rating = 7.9;
        this->pret = 20;   
    }
    
    Film(string nume, char* gen, const int an, int durata, float rating, float pret) : anAparitie(an){
        this->nume = nume;
        this->gen = new char[strlen(gen)+1];
        strcpy(this->gen, gen);
        this->durata = durata;
        this->rating = rating;
        this->pret = pret;
    }
    
    Film (string nume, const int an, int durata, float rating) : anAparitie(an){
        this->nume = nume;
        this->gen = new char[strlen("Horror")+1];
        strcpy(this->gen, "Horror");
        this->durata = durata;
        this->rating = rating;
        this->pret = 15;
    }
    
    static void eliminaReducere() {
        reducereElevi = 0;
    }
    
};
float Film::reducereElevi = 50;

class Sala{
public:
    int nrSala;
    int nrLocuri;
    const float suprafata;
    string supraveghetor;
    static float maximOreFunctionare;
    int* esteDisponibila;
    
    void afisare() {
        cout << "Numarul salii = " << this->nrSala << endl;
        cout << "Numarul de locuri = " << this->nrLocuri << endl;
        cout << "Suprafata = " << this->suprafata << " mp" << endl;
        cout << "Supraveghetor = " << this->supraveghetor << endl;
        cout << "Maxim ore de functionare = " << this->maximOreFunctionare << " ore" << endl;
        
        if (*(this->esteDisponibila) == 1)
            cout << "Este disponibila" << endl;
        else
            cout << "Nu este disponibila" << endl;
        
        cout << endl << endl;    
    }
    
    Sala():suprafata(100) {
        this->nrSala = 1;
        this->nrLocuri = 75;
        this->supraveghetor = "Popescu Ion";
        this->esteDisponibila = new int;
        *(this->esteDisponibila) = 1;
    }
    
    Sala(int nrSala, int nrLocuri, const float supraf, string supraveghetor, int* esteDisponibila) : suprafata(supraf) {
        this->nrSala = nrSala;
        this->nrLocuri = nrLocuri;
        this->supraveghetor = supraveghetor;
        this->esteDisponibila = new int;
        *(this->esteDisponibila) = *(esteDisponibila);
    }
    
    Sala(int nrSala, const float supraf, string supraveghetor) : suprafata(supraf) {
        this->nrSala = nrSala;
        this->nrLocuri = 100;
        this->supraveghetor = supraveghetor;
        this->esteDisponibila = new int;
        *(this->esteDisponibila) = 1;
    }
    
    static void modificaProgram(float programNou) {
        maximOreFunctionare = programNou;
    }
};
float Sala::maximOreFunctionare = 15;

class Angajat{
public:
    string nume;
    char* pozitie;
    int varsta;
    float salariu;
    static float impozitSalariu;
    const int anAngajare;

    void afisare() {
        cout << "Nume = " << this->nume << endl;
        cout << "Pozitie = " << this->pozitie << endl;
        cout << "Varsta = " << this->varsta << " ani" << endl;
        cout << "Salariu = " << this->salariu << " lei" << endl;
        cout << "Impozit pe salariu = " << this->impozitSalariu << "%" << endl;
        cout << "Anul angajarii = " << this->anAngajare << endl;
        cout << endl << endl;
    }
    
    Angajat():anAngajare(2015) {
        this->nume = "Popescu Ion";
        this->pozitie = new char[strlen("paznic") + 1];
        strcpy(this->pozitie,"Director");
        this->varsta = 50;
        this->salariu = 7000;
    }
    
    Angajat(string nume, char* pozitie, int varsta, float salariu, const int an) : anAngajare(an) {
        this->nume = nume;
        this->pozitie = new char[strlen(pozitie) + 1];
        strcpy(this->pozitie, pozitie);
        this->varsta = varsta;
        this->salariu = salariu;
    }
    
    Angajat(string nume, int varsta, const int an) : anAngajare(an) {
        this->nume = nume;
        this->pozitie = new char[strlen("Paznic") + 1];
        strcpy(this->pozitie, "Paznic");
        this->varsta = varsta;
        this->salariu = 2000;
    }
    
    static void modificaImpozitSalariu(float impozitNou) {
        impozitSalariu = impozitNou;
    }
        
    
};
float Angajat::impozitSalariu = 42;

int main()
{
    Film film1;
    film1.afisare();

    char* gen = new char[strlen("Science Fiction") + 1];
    strcpy(gen,"Science Fiction");
    Film film2("Matrix", gen, 1999, 136, 8.7, 25);
    film2.afisare();
    
    Film film3("The Conjuring", 2013, 112, 7.5);
    film3.afisare();
    
    
    
    Sala sala1;
    sala1.afisare();
    
    int* esteDisponibila = new int;
    *(esteDisponibila) = 0;
    Sala sala2(2, 90, 130, "Mihai Gabriel", esteDisponibila);
    sala2.afisare();
    
    Sala sala3(3, 200, "Stancu Corneliu");
    sala3.afisare();
    
    
    
    Angajat angajat1;
    angajat1.afisare();
    
    char* pozitie = new char[strlen("Manager") + 1];
    strcpy(pozitie,"Manager");
    Angajat angajat2("Stoica Lavinia", pozitie, 36, 4500, 2018);
    angajat2.afisare();
    
    Angajat angajat3("Stancu Corneliu", 45, 2023);
    angajat3.afisare();
    
    
    
    film1.eliminaReducere();
    cout << "Reducerea pentru elevi a fost eliminata: " << endl;
    film1.afisare();
    
    sala1.modificaProgram(18);
    cout << "Maximul orelor de functionare a fost modificat: " << endl;
    sala1.afisare();
    
    angajat1.modificaImpozitSalariu(50);
    cout << "Impozitul pe salariu a fost modificat: " << endl;
    angajat1.afisare();
}

