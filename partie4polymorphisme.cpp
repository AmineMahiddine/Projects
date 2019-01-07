// le cour de polymorphisme etait le 06-01-2019
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class personne{
public:
virtual void afficher()=0;
};
class peintre:public personne{
    string nom,profition;
    public:
    peintre(string n):nom(n){this->profition="peintre";};
    void afficher(){
        cout<<nom<<", je suis "<<profition<<"\n";
    } 
};
class plombier:public personne{
    string nom,profition;
    public:
    plombier(string n):nom(n){this->profition="plombier";};
    void afficher(){
        cout<<nom<<", je suis "<<profition<<"\n";
    } 
};
class minuisier:public personne{
    string nom,profition;
    public:
    minuisier(string n):nom(n){this->profition="minuisier";};
    void afficher(){
        cout<<nom<<", je suis "<<profition<<"\n";
    } 
};
class macon:public personne{
    string nom,profition;
    public:
    macon(string n):nom(n){this->profition="macon";};
    void afficher(){
        cout<<nom<<", je suis "<<profition<<"\n";
    } 
};
main(){
    
// int n=5;
// personne **tab = new personne*[n];
// tab[0]=new peintre("amine");
// tab[1]=new plombier("jamel");
// tab[2]=new minuisier("kamel");
// tab[3]=new macon("brahim");
// tab[4]=new peintre("kadour");

// for(int i = 0; i < n; i++)
// {
//     tab[i]->afficher();
// }
//  delete[] tab;

int n=5;
vector<personne*>tab;
tab[0]=new peintre("amine");
tab[1]=new plombier("jamel");
tab[2]=new minuisier("kamel");
tab[3]=new macon("brahim");
tab[4]=new peintre("kadour");

for(int i = 0; i < n; i++)
{
    tab[i]->afficher();
}
// pas necesiter de delete le pointer
}