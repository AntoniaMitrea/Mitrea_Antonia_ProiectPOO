#include <iostream>
#include <fstream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS

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

class FilmInPremiera : public Film {
private:
    char* dataPremiera;
    int taxaSuplimentara;
    
public: 
    char* getDataPremiera() {
        return this->dataPremiera;
    }
    
    int getTaxaSuplimentara() {
        return this->taxaSuplimentara;
    }
    
    void setDataPremiera(char* data) {
        if (strlen(data) > 0 ) {
            if (this->dataPremiera != NULL)
                delete[]this->dataPremiera;
        }
        this->dataPremiera = new char[strlen(data) + 1];
        strcpy(this->dataPremiera, data);
    }
    
    void setTaxaSuplimentara(int taxa) {
        if (taxa > 0)
            this->taxaSuplimentara = taxa;
    }
    
    FilmInPremiera() : Film() {
        this->dataPremiera = new char[strlen("14/02/2024") + 1];
        strcpy(this->dataPremiera, "14/02/2024");
        this->taxaSuplimentara = 50;
    }
    
    FilmInPremiera(char* data, int taxa) : Film() {
        this->dataPremiera = new char[strlen(data) + 1];
        strcpy(this->dataPremiera, data);
        
        this->taxaSuplimentara = taxa;
    }
    
    FilmInPremiera(string nume, char* gen, int an, int durata, float rating, float pret, char* data, int taxa) : Film(nume, gen, an, durata, rating, pret) {
        this->dataPremiera = new char[strlen(data) + 1];
        strcpy(this->dataPremiera, data);
        
        this->taxaSuplimentara = taxa;
    }
    
    FilmInPremiera(const FilmInPremiera& fp) : Film(fp) {
        this->dataPremiera = new char[strlen(fp.dataPremiera) + 1];
        strcpy(this->dataPremiera, fp.dataPremiera);
        
        this->taxaSuplimentara = fp.taxaSuplimentara;
    }
    
    friend ostream& operator<<(ostream& out, const FilmInPremiera& fp) {
        out << (Film)fp;
        out << "Data premierei = " << fp.dataPremiera << endl;
        out << "Taxa suplimentara = " << fp.taxaSuplimentara << " lei" << endl;
        out << endl;

        return out;
    }
    
    FilmInPremiera& operator=(const FilmInPremiera& fp) {
        if (this != &fp) {
            Film::operator=(fp);
            
            if (this->dataPremiera != NULL)
                delete[]this->dataPremiera;
            this->dataPremiera = new char[strlen(fp.dataPremiera) + 1];
            strcpy(this->dataPremiera, fp.dataPremiera);
            
            this->taxaSuplimentara = fp.taxaSuplimentara;
        }
        
        return *this;
    }
    
    ~FilmInPremiera() {
        if (this->dataPremiera != NULL)
            delete[]this->dataPremiera;
    }
};


class Camera {
protected:
    int nrPereti;
    int nrUsi;
    
public:
    virtual void afiseazaNrLocuri() = 0;
    
    Camera(){
        this->nrPereti = 4;
        this->nrUsi = 1;
    }
};

class Sala : public Camera {
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
    
    virtual void afiseazaNrLocuri() {
        cout << "Sala " << this->nrSala << " are " << this->nrLocuri << " locuri." << endl;
    }
};
float Sala::maximOreFunctionare = 15;

class Persoana {
protected:
    char sex;
    string loculNasterii;
    
public:
    virtual float calculeazaSalariu() = 0;
    
    Persoana() {
        this->sex = 'M';
        this->loculNasterii = "Bucuresti";
    }
    
    virtual ~Persoana() {
    }

};

class Angajat : public Persoana {
protected:
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
    
    Angajat(string nume, float salariu) : anAngajare(2022) {
        this->nume = nume;
        this->pozitie = new char[strlen("Operator") + 1];
        strcpy(this->pozitie, "Operator");
        this->varsta = 30;
        this->salariu = salariu;
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
    
    
    virtual float calculeazaSalariu() {
        return this->salariu - this->salariu * this->impozitSalariu / 100;
    }
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
    
class AngajatulLunii : public Angajat {
protected:
    int bonusCastigat;
    int luna;
    int an;
    
public:
    int getBonusCastigat() {
        return this->bonusCastigat;
    }
    
    int getLuna() {
        return this->luna;
    }
    
    int getAn() {
        return this->an;
    }
    
    void setBonusCastigat(int bonus) {
        if (bonus > 0)
            this->bonusCastigat = bonus;
    }
    
    void setLuna(int luna) {
        if (luna >= 1 && luna <= 12)
            this->luna = luna;
    }
    
    void setAn(int an) {
        if (an >= 2000 && an <= 2024)
            this->an = an;
    }
    
    AngajatulLunii() : Angajat() {
        this->bonusCastigat = 100;
        this->luna = 1;
        this->an = 2024;
    }  
    
    AngajatulLunii(int bonus, int luna, int an) : Angajat() {
        this->bonusCastigat = bonus;
        this->luna = luna;
        this->an = an;
    }
    
    AngajatulLunii(const AngajatulLunii& al) : Angajat(al) {
        this->bonusCastigat = al.bonusCastigat;
        this->luna = al.luna;
        this->an = al.an;
    }
	
	AngajatulLunii(string nume, char* pozitie, int varsta, float salariu, int anAngajare, int bonus, int luna, int anCastig) : Angajat(nume, pozitie, varsta, salariu, anAngajare) {
	    this->bonusCastigat = bonus;
	    this->luna = luna;
	    this->an = anCastig;
	}
	
	AngajatulLunii(string nume, float salariu, int bonus) : Angajat(nume, salariu) {
	    this->bonusCastigat = bonus;
	    this->luna = 1;
	    this->an = 2024;
	}
    
    friend ostream& operator<<(ostream& out, const AngajatulLunii& al) {
        out << (Angajat)al;
        out << "Bonus castigat = " << al.bonusCastigat << " lei" << endl;
        out << "Luna si anul in care a castigat = " << al.luna << "/" << al.an << endl;
        cout << endl;

        return out;
    }
    
    AngajatulLunii& operator=(const AngajatulLunii& al) {
        if (this != &al) {
            Angajat::operator=(al);
            this->bonusCastigat = al.bonusCastigat;
            this->an = al.an;
            this->luna = al.luna;
        }
        return *this;
        
    }
    
    AngajatulLunii operator++(int) {
         AngajatulLunii temporar = *this;
         this->bonusCastigat += 100;
         return temporar;
    }
    
    AngajatulLunii operator--(int) {
         AngajatulLunii temporar = *this;
         this->bonusCastigat -= 100;
         return temporar;
    }
    
    ~AngajatulLunii() {
    }
    
    virtual float calculeazaSalariu() {
        return this->salariu - this->salariu * this->impozitSalariu / 100 + this->bonusCastigat;
    }
    
};


int main()
{
    cout << "Persoana -> Angajat -> Angajatul Lunii" << endl << endl;
    
    
    cout << "CONSTRUCTOR FARA PARAMETRII" << endl;
    Angajat angajat1;
    cout << "Angajatul 1: " << endl << angajat1 << endl;
    
    cout << "CONSTRUCTOR CU TOTI PARAMETRII" << endl;
    char* pozitie = new char[strlen("Manager") + 1];
    strcpy(pozitie,"Manager");
    Angajat angajat2("Stoica Lavinia", pozitie, 36, 4500, 2018);
    cout << "Angajatul 2: " << endl << angajat2 << endl;
    
    cout << "CONSTRUCTOR CU DOAR O PARTE DINTRE PARAMETRII" << endl;
    Angajat angajat3("Stancu Corneliu", 45, 2023);
    cout << "Angajatul 3: " << endl << angajat3 << endl;
    
    cout << "CONSTRUCTOR DE COPIERE" << endl;
    Angajat angajat4 = angajat3;
    cout << "Angajatul 4: " << endl << angajat4 << endl;
    
    cout << "COMPARARE DE SALARII" << endl;
    comparareSalariu(angajat1, angajat2);
    cout << endl;
    
    cout << "OPERATOR +" << endl;
    angajat4 = angajat4 + 1000;
    cout << "Noul angajat 4: " << endl << angajat4 << endl;


    
    cout << "ANGAJATUL LUNII" << endl << endl;
    
    cout << "CONSTRUCTOR FARA PARAMETRII" << endl;
    AngajatulLunii AL1;
    cout << "Angajatul lunii nr. 1: " << endl << AL1;
    
    cout << "CONSTRUCTOR CU TOTI PARAMETRII" << endl;
    char* poz = new char[strlen("Manager") + 1];
    strcpy(poz,"Manager");
    AngajatulLunii AL2("Stoica Lavinia", poz, 36, 4500, 2018, 1000, 11, 2023);
    cout <<"Angajatul lunii nr. 2: " << endl << AL2;
    
    cout << "CONSTRUCTOR DE COPIERE" << endl;
    AngajatulLunii AL3 = AL2;
    cout << "Angajatul lunii nr. 3: " << endl << AL3;
    
    
    cout << "OPERATOR ++ " << endl;
    AL3++;
    cout << "Angajatul lunii nr. 3 modificat: " << endl << AL3;
    
    
    cout << "OPERATOR -- " << endl;
    AL3--;
    cout << "Angajatul lunii nr. 3 modificat: " << endl << AL3;
    
    
    
    cout << "CONCEPTUL DE LATE BINDING: " << endl << endl;
    
    Persoana** vector;
    vector = new Persoana* [10];
    vector[0] = new Angajat("Maria", 5000);
    vector[1] = new AngajatulLunii("Catalin", 6000, 100);
    vector[2] = new AngajatulLunii("Marius", 7000, 200);
    vector[3] = new Angajat("Darius", 6000);
    vector[4] = new Angajat("Laurentiu", 8000);
    vector[5] = new AngajatulLunii("Alexandra", 7000, 300);
    vector[6] = new Angajat("Matei", 4000);
    vector[7] = new AngajatulLunii("Cristian", 5000, 500);
    vector[8] = new AngajatulLunii("Ioana", 6500, 100);
    vector[9] = new Angajat("Antonia", 10000);
    
    for (int i = 0; i < 10; i++) 
        cout << i << ". Salariu net calculat = " << vector[i]->calculeazaSalariu() << " lei" << endl;
    cout << endl;
    
    cout << "DUBLARE IMPOZIT PE SALARIU" << endl;
    angajat1.dubleazaImpozitSalariu();
    cout << "Impozitul pe salariu: " << angajat1.getImpozitSalariu() << "%" << endl << endl;

}
