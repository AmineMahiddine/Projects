//ce travaille a etait realiser par mahiddine mohamed amine
// les fonction virtual sont pour eviter l ambigueter des fonction
//les constructor sont utuliser pour l initialisation des objet
//il y 3 example d utulisation de programe
//contact  aminemahiddine.code@gmail.com

#include <iostream>
#include <string>
using namespace std;
bool test = false;
class Personne
{ // les atribut sont privat pour pas etre manipuler par main ou les autre class
    string nom, prenom, adress;
    unsigned int age;

  public:
    Personne() : nom("X"), prenom("X"), adress("X"), age(0)
    {
    }
    ~Personne() {}
    void remplire_presonne(string nom, string prenom, string adress, unsigned int age)
    {
        this->nom = nom;
        this->prenom = prenom;
        this->adress = adress;
        this->age = age;
    }
    void print_personne()
    {
        if (test == false)
        {
            cout << "nom: " << nom << endl
                 << "prenom: " << prenom << endl
                 << "adress: " << adress << endl
                 << "age: " << age << endl;
            test = true;
        }
    }

    void set_nom(string n) { nom = n; }
    void set_prenom(string p) { prenom = p; }
    void set_adresse(string adr) { adress = adr; }
    void set_age(unsigned int a) { age = a; }
    string get_nom() const { return nom; }
    string get_prenom() const { return prenom; }
    unsigned int get_age() const { return age; }
    string get_adresse() const { return adress; }
};

class Employer
{
    string nom_employer;
    float salaire;

  public:
    Employer() : nom_employer("x"), salaire(0.0) {}
    ~Employer() {}
    void remplire_employer(string nom_employer, float salaire)
    {
        this->nom_employer = nom_employer;
        this->salaire = salaire;
    }
    void print_employer()
    {
        cout << "nom_employer :" << nom_employer << endl
             << "salaire :" << salaire << endl;
    }
    string get_nom_employeur() const { return nom_employer; }
    float get_salaire() const { return salaire; }
    void set_nom_employeur(string n) { nom_employer = n; }
    void set_salaire(float s) { salaire = s; }
};

class Etudient : virtual public Personne
{
    string numero, specialite, nom_ecole;

  public:
    Etudient() : numero("X"), specialite("X"), nom_ecole("X") {}
    ~Etudient() {}

    void remplire_etudient(string numero, string specialite, string nom_ecole)
    {
        this->numero = numero;
        this->specialite = specialite;
        this->nom_ecole = nom_ecole;
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
    void remplire_ensignant(unsigned int eannee)
    {
        this->eannee = eannee;
    }
    void print_ensignant()
    {
        print_personne();
        print_employer();
        cout << "eannee :" << eannee << endl;
    }

    void set_eanee(unsigned int e) { eannee = e; }
    unsigned int get_eanee() const { return eannee; }
};

class Doctorant : public Etudient, public Ensignant
{
    int nombre_inscription;

  public:
    Doctorant() : nombre_inscription(0) {}
    ~Doctorant() {}
    void remplire_doctorant(int nombre_inscription)
    {
        this->nombre_inscription = nombre_inscription;
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
    // exemple 1
    Doctorant amine;
    amine.remplire_presonne("amine", "mahiddine", "boumerdes", 20);
    amine.remplire_etudient("171731042674", "informatique", "umbb");
    amine.remplire_employer("mr.amine", 200000);
    amine.remplire_ensignant(2018);
    amine.remplire_doctorant(2);
    amine.print_doctorant();

    //exemple 2
    // Ensignant djerbi;
    // djerbi.remplire_presonne("djerbi","rechid","boumerdes",20);
    // djerbi.remplire_employer("mr djerbi",200000);
    // djerbi.remplire_ensignant(2018);
    // djerbi.print_ensignant();

    //example 3
    // Doctorant amine;
    // amine.set_nom("amine");
    // amine.set_prenom("mahiddine");
    // amine.set_adresse("adress");
    // amine.set_age(20);
    // amine.set_numero("171731042674");
    // amine.set_specialite("info");
    // amine.set_nom_ecole("unbb");
    // amine.set_nom_employeur("mr amine");
    // amine.set_salaire(200000);
    // amine.set_eanee(2018);
    // amine.set_nombre_inscription(2);
    
    // amine.print_doctorant();  
}
