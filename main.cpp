#define CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

using namespace std;

class Ferma
{
    unsigned int nrAnimale;
    unsigned int nrUtilajeInLucru;
    unsigned int nrUtilajeInStationare;
public:

    Ferma(int nrAnimale, int nrUtilajeInLucru)
    {
        this->nrAnimale = nrAnimale;
        this->nrUtilajeInLucru = nrUtilajeInLucru;
    }

    Ferma(int nrAnimale, int nrUtilajeInLucru, int nrUtilajeInStationare, int *preturiPiese)
    {
        this->nrAnimale = nrAnimale;
        this->nrUtilajeInLucru = nrUtilajeInLucru;
        this->nrUtilajeInStationare = nrUtilajeInStationare;
        this->setPreturiPiese(nrAnimale, preturiPiese);
    }

    void setPreturiPiese(int nrAnimale, int* preturiPiese)
    {
        this->preturiPiese = new int[nrAnimale];
        for (int i = 0; i < nrAnimale; i++)
            this->preturiPiese[i] = preturiPiese[i];
    }

    //destructor
    ~Ferma()
    {
        if (this->preturiPiese != NULL)
            delete[] preturiPiese;
    }

    //constructor copiere
    Ferma(const Ferma& s)
    {
        this->nrAnimale = s.nrAnimale;
        this->nrUtilajeInLucru = s.nrUtilajeInLucru;
        this->nrUtilajeInStationare = s.nrUtilajeInStationare;
        for (int i = 0; i < this->getNrAnimale(); i++)
        {
            this->preturiPiese[i] = s.preturiPiese[i];
        }
    }

    //operator atribuire
    Ferma operator=(const Ferma& s)
    {
        this->nrAnimale = s.nrAnimale;
        this->nrUtilajeInLucru = s.nrUtilajeInLucru;
        this->nrUtilajeInStationare = s.nrUtilajeInStationare;
        delete[]preturiPiese;
        this->preturiPiese = new int[s.nrAnimale];
        for (int i = 0; i < s.nrAnimale; i++)
        {
            this->preturiPiese[i] = s.preturiPiese[i];
        }
        return *this;
    }

    //getters
    int getNrAnimale()
    {
        return this->nrAnimale;
    }

    int getnrUtilajeInStationare()
    {
        return this->nrUtilajeInStationare;
    }

    int getnrUtilajeInLucru()
    {
        return this->nrUtilajeInLucru;
    }

    //operator iesire
    friend ostream& operator<< (ostream& out, const Ferma& s)
    {
        out<<"Nr Piese: " << s.nrAnimale<<endl;
        out<<"Nr masini in service: " << s.nrUtilajeInLucru<<endl;
        out<<"Nr Masini Reparate: "  << s.nrUtilajeInStationare<<endl;
        cout << "Preturi piese: "<<endl;
        for (int i = 0; i < s.nrAnimale; i++)
            out << s.preturiPiese[i]<<" ";
        return out;
    }

    //operator intrare
    friend istream& operator>> (istream& in, Ferma& s)
    {
        in >> s.nrAnimale;
        in >> s.nrUtilajeInLucru;
        in >> s.nrUtilajeInStationare;
        for (int i = 0; i < s.getNrAnimale(); i++)
        {
            in >> s.preturiPiese[i];
        }
        return in;
    }

    bool operator== (Ferma& s)
    {
        if (this->nrAnimale != s.nrAnimale || this->nrUtilajeInStationare != s.nrUtilajeInStationare || this->nrUtilajeInLucru != s.nrUtilajeInLucru || this->preturiPiese != s.preturiPiese)
            return false;
        else
            return true;
    }

    int * preturiPiese;
};



float media(Ferma& s)
{
    float media;
    float suma = 0;
    int n = s.getNrAnimale();
    for (int i = 0; i < n; i++)
        suma += s.preturiPiese[i];
    return suma / n;
}


void sortare(Ferma& s)
{
    int n = s.getNrAnimale();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n - 1; j++)
            if (s.preturiPiese[i] > s.preturiPiese[j])
                swap(s.preturiPiese[i], s.preturiPiese[j]);

}



int main()
{
    Ferma s1(5, 3, 2, new int [5] {6, 7, 8, 9, 10});
    cout<<s1<<endl;
    //Service s(5, 3);
    //cout<<s.getnrAnimale();
    /*
	//Service s1(5, 3, 2, new int [5] {6, 7, 8, 9, 10});
	//cout << s1;
	//Service s4;
	//cin >> s4;
	cout<<(s==s1);
	sortare(s);
	media(s);
     */
    return 0;
}
