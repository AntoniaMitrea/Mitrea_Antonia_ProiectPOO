#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Film {
private:
    string nume;
    char* gen;
    const int anAparitie;
    int durata;
    float rating;
    float pret;
    static float reducereElevi;
    
public:
    string getNume() {
        return this->nume; }
    
    char* getGen() {
        return this->gen; }
    
    const int getAnAparitie() {
        return this->anAparitie; }
    
    int getDurata() {
        return this->durata; }
    
    float getRating() {
        return this->rating; }
    
    float getPret() {
        return this->pret; }
    
    static float getReducereElevi() {
        return reducereElevi; }
    
    void setNume(string nume) {
        if (nume.length() > 0) {
            this->nume = nume;
        }
    }
    
    void setGen(const char* gen) {
        if (strlen(gen) > 0) {
            if (this->gen != NULL) {
                delete[]this->gen;
            }
            this->gen = new char[strlen(gen) + 1];
            strcpy(this->gen, gen);
        }
    }
    
    void setDurata(int durata) {
        if (durata > 0) {
            this->durata = durata;
        }
    }
    
    void setRating(float rating) {
        if (rating > 0 && rating <=10) {
            this->rating = rating;
        }
    }
    
    void setPret(int pret) {
        if (pret > 0) {
            this->pret = pret;
        }
    }
    
    static void setReducereElevi(float reducere) {
        reducereElevi = reducere;
    }

    void afisare() {
        cout << "Nume = " << this->nume << endl;
        cout << "Gen = " << this->gen << endl;
        cout << "Anul aparitiei = " << this->anAparitie << endl;
        cout << "Durata = " << this->durata << " minute" << endl;
        cout << "Rating = " << this->rating << " / 10 " << endl;
        cout << "Pret = " << this->pret << " lei" << endl;
        cout << "Reducere pentru elevi = " << this->reducereElevi << "%" << endl;
        cout << endl;
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
    
    Film(const Film &film) : anAparitie(film.anAparitie) {
        this->nume = film.nume;
        this->gen = new char[strlen(film.gen) + 1];
        strcpy(this->gen, film.gen);
        this->durata = film.durata;
        this->rating = film.rating;
        this->pret = film.pret;
        }
    
    ~Film() {
        if (this->gen != NULL) {
            delete[]this->gen;
            this->gen = NULL;
        }
    }
    
    Film& operator=(const Film& film) {
        if (this != &film) {
            this->nume = film.nume;
            this->durata = film.durata;
            this->rating = film.rating;
            this->pret = film.pret;

            if (this->gen != NULL) {
                delete[]this->gen;
            }

            this->gen = new char[strlen(film.gen) + 1];
            strcpy(this->gen, film.gen);

        }
        return *this;
    }
    
    friend ostream& operator<<(ostream& consola, const Film& film) {
        consola << "Nume = " << film.nume << endl;
        consola << "Gen = " << film.gen << endl;
        consola << "Anul aparitiei = " << film.anAparitie << endl;
        consola << "Durata = " << film.durata << " minute" << endl;
        consola << "Rating = " << film.rating << " / 10" << endl;
        consola << "Pret = " << film.pret << " lei" << endl;
        consola << "Reducere pentru elevi = " << film.reducereElevi << "%" << endl;
        consola << endl;
        return consola;
    }
    
    friend ofstream& operator<<(ofstream& consola, const Film& film) {
        consola << film.nume << endl;
        consola << film.gen << endl;
        consola << film.anAparitie << endl;
        consola << film.durata << endl;
        consola << film.rating << endl;
        consola << film.pret << endl;
        consola << film.reducereElevi << endl;
        
        return consola;
    }
    
    friend fstream& operator<<(fstream& consola, const Film& film) {
        consola << film.durata << endl;
        //scriereB.write((char*)&var, sizeof(int));
        
        return consola;
    }
    
    friend istream& operator>>(istream& in, Film& film) {
        cout << "Nume = "; in >> film.nume;
        
        char temporar[50];
        cout << "Gen = "; in >> temporar;
        if (film.gen != NULL) {
            delete[]film.gen;
        }
        film.gen = new char[strlen(temporar) + 1];
        strcpy(film.gen, temporar);
        
        cout << "Durata = "; in >> film.durata;
        cout << "Rating = "; in >> film.rating;
        cout << "Pret = "; in >> film.pret;
        return in;
    }
    
    friend ifstream& operator>>(ifstream& in, Film& film) {
        in >> film.nume;
        
        char temporar[30];
        in >> temporar;
        if (film.gen != NULL) {
            delete[]film.gen;
        }
        film.gen = new char[strlen(temporar) + 1];
        strcpy(film.gen, temporar);
        
        int x;
        in >> x;
        
        in >> film.durata;
        in >> film.rating;
        in >> film.pret;
        in >> film.reducereElevi;
        
        return in;
    }
    
    Film operator++(int) {
         Film temporar = *this;
         this->rating += 0.1;
         return temporar;
    }
    
    Film operator--(int) {
         Film temporar = *this;
         this->rating -= 0.1;
         return temporar;
    }
    
    static void eliminaReducere() {
        reducereElevi = 0;
    }
    
    friend void calculPretBiletElev(Film film);
    
};
float Film::reducereElevi = 50;

void calculPretBiletElev(Film film) {
    float p;
    p = film.pret * (film.reducereElevi / 100);
    cout << "Pentrul filmul '" << film.nume << "' pretul unui bilet pentru elevi este de " << p << " lei" << endl << endl;
}

class Sala{
private:
    int nrSala;
    int nrLocuri;
    const float suprafata;
    string supraveghetor;
    static float maximOreFunctionare;
    int* esteDisponibila;
    
public:
    int getNrSala() {
        return this->nrSala; }
    
    int getNrLocuri() {
        return this->nrLocuri; }
    
    const float getSuprafata() {
        return this->suprafata; }
    
    string getSupraveghetor() {
        return this->supraveghetor; }
    
    static float getMaximOreFunctionare() {
        return maximOreFunctionare; }
    
    int* getDisponibilitate() {
        return this->esteDisponibila; }
    
    void setNrSala(int nr) {
        if (nr > 0) {
            this->nrSala = nr;
        }
    }

    void setNrLocuri(int nr) {
        if (nr > 0) {
            this->nrLocuri = nr;
        }
    }
    
    void setSupraveghetor(string sup) {
        if (sup.length() > 0) {
            this->supraveghetor = sup;
        }
    }
    
    static void setMaximOreFunctionare(float maxim) {
        maximOreFunctionare = maxim;
    }
    
    void setDisponibilitate(const int* disp) {
        if (*(disp) == 0 || *(disp) == 1) {
            if (this->esteDisponibila != NULL) {
                delete[]this->esteDisponibila;
            }
            this->esteDisponibila = new int;
            *(this->esteDisponibila) = *(disp);
        }
    }
    
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
        cout << endl;    
    }
    
    Sala():suprafata(100) {
        this->nrSala = 1;
        this->nrLocuri = 75;
        this->supraveghetor = "Ivan Mircea";
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
    
    Sala(const Sala &sala) : suprafata(sala.suprafata) {
        this->nrSala = sala.nrSala;
        this->nrLocuri = sala.nrLocuri;
        this->supraveghetor = sala.supraveghetor;
        this->esteDisponibila = new int;
        *(this->esteDisponibila) = *(sala.esteDisponibila);
    }
    
    ~Sala() {
        if (this->esteDisponibila != NULL) {
            delete[]this->esteDisponibila;
            this->esteDisponibila = NULL;
        }
    }
    
    Sala& operator=(const Sala& sala) {
        if (this != &sala) {
            this->nrSala = sala.nrSala;
            this->nrLocuri = sala.nrLocuri;
            this->supraveghetor = sala.supraveghetor;

            if (this->esteDisponibila != NULL) {
                delete[]this->esteDisponibila;
            }

            this->esteDisponibila = new int;
            *(this->esteDisponibila) = *(sala.esteDisponibila);

        }
        return *this;
    }
    
    friend ostream& operator<<(ostream& consola, const Sala& sala) {
        cout << "Numarul salii = " << sala.nrSala << endl;
        cout << "Numarul de locuri = " << sala.nrLocuri << endl;
        cout << "Suprafata = " << sala.suprafata << " mp" << endl;
        cout << "Supraveghetor = " << sala.supraveghetor << endl;
        cout << "Maxim ore de functionare = " << sala.maximOreFunctionare << " ore" << endl;
        if (*(sala.esteDisponibila) == 1)
            cout << "Este disponibila" << endl;
        else
            cout << "Nu este disponibila" << endl;
        cout << endl;
        
        return consola;
    }
    
    friend istream& operator>>(istream& in, Sala& sala) {
        cout << "Numarul salii = "; in >> sala.nrSala;
        cout << "Numarul de locuri = "; in >> sala.nrLocuri;
        cout << "Supraveghetor = "; in >> sala.supraveghetor;
        
        if (sala.esteDisponibila != NULL) {
            delete[]sala.esteDisponibila;
        }
        sala.esteDisponibila = new int;
        cout << "Disponibilitate (0 sau 1) = "; in >> *(sala.esteDisponibila);
        return in;
    }
    
    bool operator<=(Sala sala) {
         return this->suprafata < sala.suprafata;
    }
    
    bool operator>=(Sala sala) {
        return this->suprafata >= sala.suprafata;
    }
    
    static void injumatatesteProgram() {
        maximOreFunctionare = maximOreFunctionare / 2;
    }
};
float Sala::maximOreFunctionare = 15;

class Angajat{
private:
    string nume;
    char* pozitie;
    int varsta;
    float salariu;
    static float impozitSalariu;
    const int anAngajare;

public:
    string getNume() {
        return this->nume; }
    
    char* getPozitie() {
        return this->pozitie; }
    
    int getVarsta() {
        return this->varsta; }
    
    float getSalariu() {
        return this->salariu; }
    
    const int getAnAngajare() {
        return this->anAngajare; }
    
    static float getImpozitSalariu() {
        return impozitSalariu; }
    
    void setNume(string nume) {
        if (nume.length() > 0) {
            this->nume = nume;
        }
    }
    
    void setPozitie(const char* pozitie) {
        if (strlen(pozitie) > 0) {
            if (this->pozitie != NULL) {
                delete[]this->pozitie;
            }
            this->pozitie = new char[strlen(pozitie) + 1];
            strcpy(this->pozitie, pozitie);
        }
    }
    
    void setVarsta(int varsta) {
        if (varsta > 18) {
            this->varsta = varsta;
        }
    }
    
    void setSalariu(float salariu) {
        if (salariu > 3000) {
            this->salariu = salariu;
        }
    }
    
    static void setImpozitSalariu(float impozit) {
        impozitSalariu = impozit;
    }

    void afisare() {
        cout << "Nume = " << this->nume << endl;
        cout << "Pozitie = " << this->pozitie << endl;
        cout << "Varsta = " << this->varsta << " ani" << endl;
        cout << "Salariu = " << this->salariu << " lei" << endl;
        cout << "Impozit pe salariu = " << this->impozitSalariu << "%" << endl;
        cout << "Anul angajarii = " << this->anAngajare << endl;
        cout << endl;
    }
    
    Angajat():anAngajare(2015) {
        this->nume = "Popescu Ion";
        this->pozitie = new char[strlen("Director") + 1];
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
    
    Angajat(const Angajat &angajat) : anAngajare(angajat.anAngajare) {
        this->nume = angajat.nume;
        this->pozitie = new char[strlen(angajat.pozitie) + 1];
        strcpy(this->pozitie, angajat.pozitie);
        this->varsta = angajat.varsta;
        this->salariu = angajat.salariu;
    }
    
    ~Angajat() {
        if (this->pozitie != NULL) {
            delete[]this->pozitie;
            this->pozitie = NULL;
        }
    }
    
    Angajat& operator=(const Angajat& ang) {
        if (this != &ang) {
            this->nume = ang.nume;
            this->varsta = ang.varsta;
            this->salariu = ang.salariu;

            if (this->pozitie != NULL) {
                delete[]this->pozitie;
            }
            this->pozitie = new char[strlen(ang.pozitie) + 1];
            strcpy(this->pozitie, ang.pozitie);
        }
        return *this;
    }
    
    friend ostream& operator<<(ostream& consola, const Angajat& ang) {
        consola << "Nume = " << ang.nume << endl;
        consola << "Pozitie = " << ang.pozitie << endl;
        consola << "Varsta = " << ang.varsta << " ani" << endl;
        consola << "Salariu = " << ang.salariu << " lei" << endl;
        consola << "Impozit pe salariu = " << ang.impozitSalariu << "%" << endl;
        consola << "Anul angajarii = " << ang.anAngajare << endl;
        consola << endl;
        return consola;
    }
    
    friend ofstream& operator<<(ofstream& consola, const Angajat& ang) {
        consola << ang.nume << endl;
        consola << ang.pozitie << endl;
        consola << ang.varsta << endl;
        consola << ang.salariu << endl;
        consola << ang.impozitSalariu << endl;
        consola << ang.anAngajare << endl;
        
        return consola;
    }
    
    friend istream& operator>>(istream& in, Angajat& ang) {
        cout << "Nume = "; in >> ang.nume;
        
        char temporar[15];
        cout << "Pozitie = "; in >> temporar;
        if (ang.pozitie != NULL) {
            delete[]ang.pozitie;
        }
        ang.pozitie = new char[strlen(temporar) + 1];
        strcpy(ang.pozitie, temporar);
        
        cout << "Varsta = "; in >> ang.varsta;
        cout << "Salariu = "; in >> ang.salariu;
        return in;
    }
    
    friend ifstream& operator>>(ifstream& in, Angajat& ang) {
        in >> ang.nume;
        
        char temporar[30];
        in >> temporar;
        if (ang.pozitie != NULL) {
            delete[]ang.pozitie;
        }
        ang.pozitie = new char[strlen(temporar) + 1];
        strcpy(ang.pozitie, temporar);
        
        in >> ang.varsta;
        in >> ang.salariu;
        
        int x;
        in >> x;
        in >> x;
        
        return in;
    }
    
    Angajat& operator+=(int val) {
        this->salariu = this->salariu + val;
        return *this;
    }
    
    Angajat operator+(int val) {
        Angajat temporar = *this;
        temporar.salariu = temporar.salariu + val;
        return temporar;
        
    }
    
    Angajat& operator-=(int val) {
        this->salariu = this->salariu - val;
        return *this;
    }
    
    Angajat operator-(int val) {
        Angajat temporar = *this;
        temporar.salariu = temporar.salariu - val;
        return temporar;
        
    }
    
    static void dubleazaImpozitSalariu() {
        impozitSalariu = impozitSalariu * 2;
    }
    
    friend void comparareSalariu (Angajat ang1, Angajat ang2);
};
float Angajat::impozitSalariu = 42;

void comparareSalariu (Angajat ang1, Angajat ang2) {
    if (ang1.salariu > ang2.salariu) {
        cout << "Angajatul " << ang1.nume << " are salariul mai mare decat angajatul " << ang2.nume << endl;
    }
    else if (ang1.salariu < ang2.salariu) {
        cout << "Angajatul " << ang1.nume << " are salariul mai mic decat angajatul " << ang2.nume << endl;
    }
    else {
        cout << "Angajatii " << ang1.nume << " si " << ang2.nume << " au salariile egale" << endl;
    }
    
    cout << ang1.nume << ": " << ang1.salariu << " lei" << endl;
    cout << ang2.nume << ": " << ang2.salariu << " lei" << endl;
}

class Premiu {
private:
    Film filmCastigator;
    string nume;
    float valoare;
    int anAcordare;

public:
    Film getFilmCastigator() {
        return this->filmCastigator; }
        
    string getNume() {
        return this->nume; }
    
    float getValoare() {
        return this->valoare; }
    
    int getAnAcordare() {
        return this->anAcordare; }
        
    void setFilmCastigator(Film f){
        this->filmCastigator = f; }
    
    void setNume(string nume) {
        if (nume.length() > 0)
            this->nume = nume;
    }
    
    void setValoare(float val) {
        if (val > 0)
            this->valoare = val;
    }
    
    void setAnAcordare(int an) {
        if (an > 1800 && an < 2024)
            this->anAcordare = an;
    }
    
    Premiu() {
        this->nume = "Premiul Oscar";
        this->valoare = 5000;
        this->anAcordare = 2023;
        Film f;
        this->filmCastigator = f;
    }
    
    Premiu(Film f, string nume, float valoare, int an) {
        this->filmCastigator = f;
        this->nume = nume;
        this->valoare = valoare;
        this->anAcordare = an;
    }
    
    Premiu(const Premiu& p) {
        this->nume = p.nume;
        this->valoare = p.valoare;
        this->anAcordare = p.anAcordare;
        this->filmCastigator = p.filmCastigator;
    }
    
    friend ostream& operator<<(ostream& consola, const Premiu& p) {
        consola << "Nume premiu = " << p.nume << endl;
        consola << "Valoare = " << p.valoare << " lei" << endl;
        consola << "An acordare = " << p.anAcordare << endl;
        consola << "Filmul castigator: " << endl << p.filmCastigator;
        consola << endl;
        
        return consola;
    }
    
    Premiu& operator=(const Premiu& p) {
        if (this != &p) {
            this->nume = p.nume;
            this->valoare = p.valoare;
            this->anAcordare = p.anAcordare;
            this->filmCastigator = p.filmCastigator;
        }
        return *this;
    }
    
    Premiu operator++(int) {
         Premiu temporar = *this;
         this->valoare += 1000;
         return temporar;
    }
    
    Premiu operator--(int) {
         Premiu temporar = *this;
         this->valoare -= 1000;
         return temporar;
    }
};


int main()
{
    Film film1;
    cout << "Filmul 1: " << endl;
    cout << film1;
    
    calculPretBiletElev(film1);
    
    
    /*
    film1.setNume("Titanic TEST");
    film1.setGen("Dragoste TEST");
    film1.setDurata(100);
    film1.setRating(9.5);
    film1.setPret(25);
    film1.setReducereElevi(10);
    
    cout << "Filmul 1 (cu valorile introduse prin setter): " << endl;
    cout << "Nume = " << film1.getNume() << endl;
    cout << "Gen = " << film1.getGen() << endl;
    cout << "Anul aparitie = " << film1.getAnAparitie() << endl;
    cout << "Durata = " << film1.getDurata() << " minute" << endl;
    cout << "Rating = " << film1.getRating() << " / 10" << endl;
    cout << "Pret = " << film1.getPret() << " lei" << endl;
    cout << "Reducere pentru elevi = " << film1.getReducereElevi() << "%" << endl;
    cout << endl;
    */
    
    char* gen = new char[strlen("Science Fiction") + 1];
    strcpy(gen,"Science Fiction");
    Film film2("Matrix", gen, 1999, 136, 8.7, 25);
    cout << "Filmul 2:" << endl;
    cout << film2;
    
    /*
    film2 = film1;
    cout << "Testare operator = " << endl << "Noul film 2:" << endl;
    cout << film2;
    */
    
    film2--;
    cout << "Testare operator -- " << endl << "Noul film 2 (cu rating scazut): " << endl;
    cout << film2;
    
    
    Film film3("The Conjuring", 2013, 112, 7.5);
    film3.afisare();
    
    
    
    Sala sala1;
    cout << "Sala 1: " << endl;
    cout << sala1;
    
    /*
    sala1.setNrSala(22);
    sala1.setNrLocuri(1000);
    sala1.setSupraveghetor("Ivan Mircea TEST");
    sala1.setMaximOreFunctionare(24);
    //sala1.setDisponibilitate(0);
    
    cout << "Sala 1 (cu valorile introduse prin setter): " << endl;
    cout << "Numarul salii = " << sala1.getNrSala() << endl;
    cout << "Numarul de locuri = " << sala1.getNrLocuri() << endl;
    cout << "Suprafata = " << sala1.getSuprafata() << " mp " << endl;
    cout << "Supraveghetor = " << sala1.getSupraveghetor() << endl;
    cout << "Maxim ore de functionare = " << sala1.getMaximOreFunctionare() << " ore" << endl;
    if (*(sala1.getDisponibilitate()) == 1) {
        cout << "Este disponibila" << endl;
    }
    else {
        cout << "Nu este disponibila" << endl;
    }
    cout << endl;
    */
    
    int* esteDisponibila = new int;
    *(esteDisponibila) = 0;
    Sala sala2(2, 90, 130, "Mihai Gabriel", esteDisponibila);
    cout << "Sala 2:" << endl;
    cout << sala2;
    
    cout << "Testare operator <=" << endl;
    if (sala1<=sala2) {
        cout << "Sala 2 are suprafata mai mare sau egala cu suprafata salii 1" << endl;
    }
    else {
        cout << "Sala 1 are suprafata mai mare sau egala cu suprafata salii 2" << endl;
    }
    cout << endl;
    
    /*
    Sala sala3(3, 200, "Stancu Corneliu");
    sala3.afisare();
    */
    
    
    Angajat angajat1;
    cout << "Angajatul 1: " << endl;
    cout << angajat1;
    
    /*
    angajat1.setNume("Popescu Ion TEST");
    angajat1.setPozitie("Director TEST");
    angajat1.setVarsta(55);
    angajat1.setSalariu(6000);
    angajat1.setImpozitSalariu(50);
    
    cout << "Angajatul 1 (cu valorile introduse prin setter): " << endl;
    cout << "Nume = " << angajat1.getNume() << endl;
    cout << "Pozitie = " << angajat1.getPozitie() << endl;
    cout << "Varsta = " << angajat1.getVarsta() << " ani" << endl;
    cout << "Salariu = " << angajat1.getSalariu() << " lei" << endl;
    cout << "Impozit pe salariu = " << angajat1.getImpozitSalariu() << "%" << endl;
    cout << "Anul angajarii = " << angajat1.getAnAngajare() << endl;
    cout << endl;
    */
    
    char* pozitie = new char[strlen("Manager") + 1];
    strcpy(pozitie,"Manager");
    Angajat angajat2("Stoica Lavinia", pozitie, 36, 4500, 2018);
    cout << "Angajatul 2: " << endl;
    cout << angajat2;
    
    angajat2 = angajat2 + 1000;
    cout << "Testare operator +" << endl << "Noul angajat 2 (cu salariu marit): " << endl;
    cout << angajat2;
    
    cout << "Comparare de salarii: " << endl;
    comparareSalariu(angajat2, angajat1);
    cout << endl;
    
    
    Angajat angajat3("Stancu Corneliu", 45, 2023);
    angajat3.afisare();
    
    
    film1.eliminaReducere();
    cout << "Reducerea pentru elevi a fost eliminata: " << endl;
    cout << "Reducere pentru elevi: " << film1.getReducereElevi() << "%" << endl;
    cout << endl;
    
    sala1.injumatatesteProgram();
    cout << "Maximul orelor de functionare a fost injumatatit: " << endl;
    cout << "Maxim ore de functionare: " << sala1.getMaximOreFunctionare() << " ore" << endl;
    cout << endl;
    
    angajat1.dubleazaImpozitSalariu();
    cout << "Impozitul pe salariu a fost dublat: " << endl;
    cout << "Impozitul pe salariu: " << angajat1.getImpozitSalariu() << "%" << endl;
    cout << endl;
    
    /*
    cout << "************* Faza 4 ***************" << endl << endl;
    
    cout << "Introduceti datele pentru vectorul de filme:" << endl;
    Film vFilme[3];
    for (int i=0; i<3; i++) {
        cout << "Introduceti datele pentru filmul " << i << endl;
        cin >> vFilme[i];
        cout << endl;
    }
    
    cout << "Introduceti datele pentru vectorul de sali:" << endl;
    Sala vSali[3];
    for (int i=0; i<3; i++) {
        cout << "Introduceti datele pentru sala " << i  << endl;
        cin >> vSali[i];
        cout << endl;
    }
    
    cout << "Introduceti datele pentru vectorul de angajati:" << endl;
    Angajat vAngajati[3];
    for (int i=0; i<3; i++) {
        cout << "Introduceti datele pentru angajatul " << i << endl;
        cin >> vAngajati[i];
        cout << endl;
    }
    
    cout << "Vectorul de filme introduse:" << endl;
    for (int i=0; i<3; i++) {
        cout << vFilme[i];
        cout << endl;
    }
    
    cout << "Vectorul de sali introduse:" << endl;
    for (int i=0; i<3; i++) {
        cout << vSali[i];
        cout << endl;
    }
    
    cout << "Vectorul de angajati introdusi:" << endl;
    for (int i=0; i<3; i++) {
        cout << vAngajati[i];
        cout << endl;
    }
    
    
    Film mFilme[2][2];
    
    cout << "Introduceti elementele matricei de filme: " << endl << endl;
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            cin >> mFilme[i][j];
            cout << endl;
        }
    }
    
    cout << endl << "Elementele matricei introduse sunt: " << endl << endl;
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            cout << mFilme[i][j] << endl;
        }
    }
    */
    
    
    //cout << "************* Faza 5 ***************" << endl << endl;
    
    /*
    cout << "Testare constructor fara parametrii: " << endl;
    Premiu premiu1;
    cout << "Premiul 1: " << endl << premiu1;
    
    cout << "Testare constructor cu parametrii: " << endl;
    Premiu premiu2(film2, "Premiul Nobel", 10000, 2000);
    cout << "Premiul 2: " << endl << premiu2;
    
    cout << "Testare constructor de copiere: " << endl;
    Premiu premiu3 = premiu2;
    cout << "Premiul 3: " << endl << premiu3;
    
    cout << "Testare getteri: " << endl;
    cout << "Premiul 3: " << endl;
    cout << "Nume = " << premiu3.getNume() << endl;
    cout << "Valoare = " << premiu3.getValoare() << " lei" << endl;
    cout << "An acordare = " << premiu3.getAnAcordare() << endl;
    cout << "Filmul castigator: " << endl << premiu3.getFilmCastigator() << endl;
    
    cout << "Testare setteri: " << endl;
    premiu3.setNume("Premiul Antonia");
    premiu3.setValoare(7000);
    premiu3.setAnAcordare(2003);
    premiu3.setFilmCastigator(film3);
    cout << "Premiul 3: " << endl << premiu3;
    
    cout << "Testare operator = " << endl;
    Premiu premiu4;
    premiu4 = premiu3;
    cout << "Premiul 4: " << endl << premiu4;
    
    cout << "Testare operator ++ " << endl;
    cout << "Valorea premiul 4: " << premiu4.getValoare() << " lei" << endl;
    premiu4++;
    cout << "Valoarea premiului 4 dupa crestere: " << premiu4.getValoare() << " lei" << endl;
    premiu4--;
    premiu4--;
    cout << "Valoarea premiului 4 dupa scadere de 2 ori: " << premiu4.getValoare() << " lei" << endl;
    */
    
    cout << "****************** Faza 6 ********************" << endl << endl;

    ofstream scriereT("fisierText.out", ios::out);
    scriereT << film3;
    scriereT << angajat3;
    cout << "Obiectele au fost scrise in fisier" << endl << endl;
    
    scriereT.close();
    
    ifstream citireT("fisierText.in", ios::in);
    Film film4;
    citireT >> film4;
    cout << "Filmul 4 citit din fisier: " << endl << film4;
    
    Angajat angajat4;
    citireT >> angajat4;
    cout << "Angajatul 4 citit din fisier: " << endl <<angajat4;
    
    citireT.close();
}
