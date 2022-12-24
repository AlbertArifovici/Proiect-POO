#define CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

using namespace std;

class Ferma
{
    unsigned int nrHambare;
    unsigned int nrUtilajeInLucru;
    unsigned int nrUtilajeInStationare;
public:

    Ferma(int nrHambare, int nrUtilajeInLucru)
    {
        this->nrHambare = nrHambare;
        this->nrUtilajeInLucru = nrUtilajeInLucru;
    }

    Ferma(int nrHambare, int nrUtilajeInLucru, int nrUtilajeInStationare, int *nrAnimaleInHambare)
    {
        this->nrHambare = nrHambare;
        this->nrUtilajeInLucru = nrUtilajeInLucru;
        this->nrUtilajeInStationare = nrUtilajeInStationare;
        this->setNrAnimaleInHambare(nrHambare, nrAnimaleInHambare);
    }

    void setNrAnimaleInHambare(int nrHambare, int* nrAnimaleInHambare)
    {
        this->nrAnimaleInHambare = new int[nrHambare];
        for (int i = 0; i < nrHambare; i++)
            this->nrAnimaleInHambare[i] = nrAnimaleInHambare[i];
    }

    //destructor
    ~Ferma()
    {
        if (this->nrAnimaleInHambare != NULL)
            delete[] nrAnimaleInHambare;
    }

    //constructor copiere
    Ferma(const Ferma& s)
    {
        this->nrHambare = s.nrHambare;
        this->nrUtilajeInLucru = s.nrUtilajeInLucru;
        this->nrUtilajeInStationare = s.nrUtilajeInStationare;
        for (int i = 0; i < this->getnrHambare(); i++)
        {
            this->nrAnimaleInHambare[i] = s.nrAnimaleInHambare[i];
        }
    }

    //operator atribuire
    Ferma operator=(const Ferma& s)
    {
        this->nrHambare = s.nrHambare;
        this->nrUtilajeInLucru = s.nrUtilajeInLucru;
        this->nrUtilajeInStationare = s.nrUtilajeInStationare;
        delete[]nrAnimaleInHambare;
        this->nrAnimaleInHambare = new int[s.nrHambare];
        for (int i = 0; i < s.nrHambare; i++)
        {
            this->nrAnimaleInHambare[i] = s.nrAnimaleInHambare[i];
        }
        return *this;
    }

    //getters
    int getnrHambare()
    {
        return this->nrHambare;
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
        out<<"Nr hambare: " << s.nrHambare<<endl;
        out<<"Nr utilaje in lucru: " << s.nrUtilajeInLucru<<endl;
        out<<"Nr utilaje in stationare: "  << s.nrUtilajeInStationare<<endl;
        cout<<endl;
        for (int i = 0; i < s.nrHambare; i++)
            out << "Nr animale in hambarul " << i << ": " << s.nrAnimaleInHambare[i]<<endl;
        return out;
    }

    //operator intrare
    friend istream& operator>> (istream& in, Ferma& s)
    {
        in >> s.nrHambare;
        in >> s.nrUtilajeInLucru;
        in >> s.nrUtilajeInStationare;
        for (int i = 0; i < s.getnrHambare(); i++)
        {
            in >> s.nrAnimaleInHambare[i];
        }
        return in;
    }

    bool operator== (Ferma& s)
    {
        if (this->nrHambare != s.nrHambare || this->nrUtilajeInStationare != s.nrUtilajeInStationare || this->nrUtilajeInLucru != s.nrUtilajeInLucru || this->nrAnimaleInHambare != s.nrAnimaleInHambare)
            return false;
        else
            return true;
    }

    int *nrAnimaleInHambare;
};

//metode specifice
float mediaAnimale(Ferma& s)
{
    float media;
    float suma = 0;
    int n = s.getnrHambare();
    for (int i = 0; i < n; i++)
        suma += s.nrAnimaleInHambare[i];
    return suma / n;
}


void sortareHambare(Ferma& s)
{
    int n = s.getnrHambare();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n ; j++)
            if (s.nrAnimaleInHambare[i] > s.nrAnimaleInHambare[j])
                swap(s.nrAnimaleInHambare[i], s.nrAnimaleInHambare[j]);

}

int main()
{
    Ferma s1(5, 3, 2, new int [5] {10,9,8,7,6});
    cout<<s1<<endl;
    cout<<"Media animalelor per hambar: "<<mediaAnimale(s1)<<endl;
    cout<<endl;
    sortareHambare(s1);
    cout<<s1<<endl;
    return 0;
}
