
#include <iostream>
#include <string>
using namespace std;
bool testprint = false;
bool testsaiser = false;
class Personne
{ // les atribut sont privat pour pas etre manipuler par main ou les autre class
    string nom, prenom, adress;
    unsigned int age;

  public:
    Personne() : nom("X"), prenom("X"), adress("X"), age(0)
    {
    }
    ~Personne() {}
   

    void saiser_personne()
    {
        if (testsaiser == false)
        {
            cout << "donner un nom : \t";
            string nom;
            cin >> nom;
            set_nom(nom);
            cout << "donner un prenom : \t";
            string prenom;
            cin >> prenom;
            set_prenom(prenom);
            cout << "donner un adress : \t";
            string adress;
            cin >> adress;
            set_adress(adress);
            cout << "donner un age : \t";
            unsigned int age;
            cin >> age;
            set_age(age);
            testsaiser = true;
        }
    }
    void print_personne()
    {
        if (testprint == false)
        {
            cout << "nom: " << nom << endl
                 << "prenom: " << prenom << endl
                 << "adress: " << adress << endl
                 << "age: " << age << endl;
            testprint = true;
        }
    }
    string get_nom() const { return nom; }
    string get_prenom() const { return prenom; }
    unsigned int get_age() const { return age; }
    string get_adresse() const { return adress; }

  protected:
    void set_nom(string n) { nom = n; }
    void set_prenom(string p) { prenom = p; }
    void set_adress(string adr) { adress = adr; }
    void set_age(unsigned int a) { age = a; }
};

class Employer
{
    string nom_employer;
    float salaire;

  public:
    Employer() : nom_employer("x"), salaire(0.0) {}
    ~Employer() {}
  
    void saiser_employer()
    {
        cout << "donner nom employer: \t";
        string nom_employer;
        cin >> nom_employer;
        set_nom_employeur(nom_employer);
        cout << "donner le salaire: \t";
        float salaire;
        cin >> salaire;
        set_salaire(salaire);
    }
    void print_employer()
    {
        cout << "nom_employer :" << nom_employer << endl
             << "salaire :" << salaire << endl;
    }
    string get_nom_employeur() const { return nom_employer; }
    float get_salaire() const { return salaire; }

  protected:
    void set_nom_employeur(string n) { nom_employer = n; }
    void set_salaire(float s) { salaire = s; }
};

class Etudient : virtual public Personne
{
    string numero, specialite, nom_ecole;

  public:
    Etudient() : numero("X"), specialite("X"), nom_ecole("X") {}
    ~Etudient() {}

  
    void saiser_etudient()
    {
        saiser_personne();
        cout << "donner le num d etudient :\t";
        string numero;
        cin >> numero;
        set_numero(numero);
        cout << "donner la spitialite : \t";
        string spitialite;
        cin >> spitialite;
        set_specialite(spitialite);
        cout << "donner le nom d ecole: \t";
        string nom_ecole;
        cin >> nom_ecole;
        set_nom_ecole(nom_ecole);
    }
    void print_etudient()
    {
        print_personne();
        cout << "numero :" << numero << endl
             << "specialite :" << specialite << endl
             << "nom_ecole :" << nom_ecole << endl;
    }

    string get_numero() const { return numero; }
    string get_specialite() const { return specialite; }
    string get_nom_ecole() const { return nom_ecole; }

  protected:
    void set_numero(string num) { numero = num; }
    void set_specialite(string spl) { specialite = spl; }
    void set_nom_ecole(string nom_ec) { nom_ecole = nom_ec; }
};

class Ensignant : virtual public Personne, public Employer
{
    unsigned int eannee;

  public:
    Ensignant() : eannee(0) {}
    ~Ensignant() {}
  
    void saiser_ensignant()
    {
        saiser_personne();
        saiser_employer();
        cout << "donner l eannee:\t";
        unsigned int eannee;
        cin >> eannee;
        set_eanee(eannee);
    }
    void print_ensignant()
    {
        print_personne();
        print_employer();
        cout << "eannee :" << eannee << endl;
    }

    unsigned int get_eanee() const { return eannee; }

  protected:
    void set_eanee(unsigned int e) { eannee = e; }
};

class Doctorant : public Etudient, public Ensignant
{
    int nombre_inscription;

  public:
    Doctorant() : nombre_inscription(0) {}
    ~Doctorant() {}
   
    void saiser_doctorant()
    {
        saiser_etudient();
        saiser_ensignant();
        cout << "donner le nombre_inscription:\t";
        unsigned int nombre_inscription;
        cin >> nombre_inscription;
        set_nombre_inscription(nombre_inscription);
    }
    void print_doctorant()
    {
        print_etudient();
        print_ensignant();
        cout << "nombre_inscription: " << nombre_inscription << endl
             << endl;
    }

    int get_nombre_inscription() const { return nombre_inscription; }
    void set_nombre_inscription(unsigned int e) { nombre_inscription = e; }
};

main()
{
    Doctorant D;
    D.saiser_doctorant();
    cout << "\n\n";
    D.print_doctorant();
    
}