#include <iostream>
using namespace std;

template <typename T>
class polynome
{
    T *coef;
    int degree;

  public:
    polynome(T *tab, int taille)
    {
        coef = new T[taille];
        degree = taille - 1;
        for (int i = 0; i < taille; i++)
        {
            coef[i] = tab[i];
        }
    }
    polynome(T c=0, int deg=0)
    {
        coef = new T[deg + 1];
        degree = deg;
        for (int i = 0; i < degree; i++)
            coef[i] = 0;
        coef[degree] = c;
    }
    polynome(polynome<T> const &p)
    {
        degree = p.degree;
        coef = new T[degree + 1];
        for (int i = 0; i < degree; i++)
        {
            coef[i] = p.coef[i];
        }
    }
    ~polynome() { delete[] coef; }

    polynome &operator=(polynome const &p)
    {
        if (this != &p)
        {
            degree = p.degree;
            coef = new T[degree + 1];

            for (int i = 0; i < degree; i++)
            {
                coef[i] = p.coef[i];
            }
            return *this;
        }
    }

    polynome operator-() const
    {
        polynome p(p.coef, p.degree + 1);
        for (int i = 0; i < degree; i++)
        {
            p.coef[i] *= -1;
        }
        return p;
    }

    friend polynome operator+(polynome const &p, polynome const &q)
    {
    polynome const&plus_grand_deg =( p.degree>=q.degree)?p:q;
    polynome const&autre =( p.degree>=q.degree)?q:p;
    polynome somme = plus_grand_deg;

    for (int i = 0; i < autre.degree; i++)
    {
        somme.coef[i] += autre.coef[i];
    }
    return somme;
    }

    friend polynome operator-(polynome const &p, polynome const &q)
    {
        return p + (-q);
    }

    friend polynome operator*(polynome const &p, polynome const &q)
    {
        if (p.degree == 0 && p.coef[0] == 0 || q.degree == 0 && q.coef[0] == 0)
            return polynome(T(0), 0);

        polynome prod(T(0), p.degree + q.degree + 1);

        for (int i = 0; i <= p.degree; i++)
        {
            for (int j = 0; j <= q.degree; j++)
            {
                prod.coef[i + j] += p.coef[i] * q.coef[j];
            }
        }
        return prod;
    }

    polynome operator+=(polynome const &p)
    {
        *this = *this + p;
        return *this;
    }
    polynome operator-=(polynome const &p)
    {
        *this = *this - p;
        return *this;
    }
    polynome operator*=(polynome const &p)
    {
        *this = *this * p;
        return *this;
    }

    friend ostream &operator<<(ostream &stream, polynome const &p)
    {
        bool premier_coef = false;

        for (int i = 0; i < p.degree; i++)
        {
            if (p.coef[i] != 0 && premier_coef)
                stream << "+";
            if (p.coef[i] != 0)
            {
                premier_coef = true;
                stream << "x";
                if (i > 0)
                    stream << "^" << i;
            }
        }

        if (premier_coef)
            stream << "0";
        return stream;
    }
    polynome operator()(polynome const &q) const
    {
        polynome <T>composee = 0;
        for (int i = degree; i >= 0; i--)
        {
            composee = composee * q;
            composee += coef[i];
        }
        return composee;
    }
    T operator()(T const &x) const
    {
        T valeur = 0;

        for (int i = degree; i >= 0; i--)
        {
            valeur = valeur * x;
            valeur += coef[i];
        }
        return valeur;
    }
};

int main()
{
    int poly1[3] = {1,2,3};
    int poly2[3] = {2,4,6};
    
    polynome<int> amine(poly1,3);
    polynome<int> jamel(poly2,3);
    polynome <int>resault = amine + jamel ;
    cout << resault;
    
}