#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

ifstream f("profesori");
ifstream e("elevi");
ifstream l("date_logare");

int tasta;
char a1[20][100], a2[20][100], a3[20][100];
int k1 = 0, k2 = 0, k3 = 0;
int lunion = 0, vinerion = 0, vinerifiz = 0, joifiz = 0, miercurifiz = 0, martifiz = 0, lunifiz = 0;

struct logare
{
    char nume[31], prenume[31], user[30], parola[20];
    int logat = 0;
} log;

struct profesori
{
    char nume[31], prenume[31];
    int modul;
    unsigned int nrtlf;
    float salariu;
} p[6];

struct elevi
{
    char prenume[100], nume[100], emailp[51], zi[20], tipcurs[20];
    int modul, absente;
} elv[30];

struct abonati
{
    char nume[70], prenume[70], nrtlfa[11];
} abo[30];

int nr_elev;
int nr_prod;

void citiree()
{
    nr_elev = 0;

    for (int i = 0; i < 30; i++)
    {
        e >> elv[i].nume;
        e >> elv[i].prenume;
        e >> elv[i].emailp;
        e >> elv[i].modul;
        e >> elv[i].absente;
        e >> elv[i].zi;
        e >> elv[i].tipcurs;

        if (elv[i].modul == 1)
        {
            strcpy(a1[k1], elv[i].nume);
            strcat(a1[k1], " ");
            strcat(a1[k1], elv[i].prenume);
            k1++;
        }
        if (elv[i].modul == 2)
        {
            strcpy(a2[k2], elv[i].nume);
            strcat(a2[k2], " ");
            strcat(a2[k2], elv[i].prenume);
            k2++;
        }
        if (elv[i].modul == 3)
        {
            strcpy(a3[k3], elv[i].nume);
            strcat(a3[k3], " ");
            strcat(a3[k3], elv[i].prenume);
            k3++;
        }

        if (elv[i].modul == 1)
        {
            if (strcmp(elv[i].tipcurs, "online") == 0)
            {
                if (strcmp(elv[i].zi, "luni") == 0)
                    lunion++;
                if (strcmp(elv[i].zi, "vineri") == 0)
                    vinerion++;
            }
            else if (strcmp(elv[i].tipcurs, "fizic") == 0)
            {
                if (strcmp(elv[i].zi, "luni") == 0)
                    lunifiz++;
                if (strcmp(elv[i].zi, "vineri") == 0)
                    vinerifiz++;
                if (strcmp(elv[i].zi, "marti") == 0)
                    martifiz++;
                if (strcmp(elv[i].zi, "miercuri") == 0)
                    miercurifiz++;
                if (strcmp(elv[i].zi, "joi") == 0)
                    joifiz++;
            }
        }
        nr_elev++;
    }
}

void mod1()
{
    system("CLS");
    cout << "--- Elevi Modulul 1 ---" << endl;
    for (int i = 0; i < k1; i++)
        cout << i + 1 << ". " << a1[i] << endl;
}

void mod2()
{
    system("CLS");
    cout << "--- Elevi Modulul 2 ---" << endl;
    for (int i = 0; i < k2; i++)
        cout << i + 1 << ". " << a2[i] << endl;
}

void mod3()
{
    system("CLS");
    cout << "--- Elevi Modulul 3 ---" << endl;
    for (int i = 0; i < k3; i++)
        cout << i + 1 << ". " << a3[i] << endl;
}

void afisare_module()
{
    system("CLS");
    int m;
    cout << "Introduceti numarul modulului dorit (1, 2 sau 3): ";
    cin >> m;
    if (m == 1)
        mod1();
    if (m == 2)
        mod2();
    if (m == 3)
        mod3();
}

void stergere()
{
    system("CLS");

    for (int i = 0; i < nr_elev; i++)
    {
        if (elv[i].absente >= 5)
        {
            for (int j = i + 1; j < nr_elev; j++)
            {
                strcpy(elv[i].nume, elv[j].nume);
                strcpy(elv[i].prenume, elv[j].prenume);
                strcpy(elv[i].emailp, elv[j].emailp);
                elv[i].modul = elv[j].modul;
                elv[i].absente = elv[j].absente;
            }
            nr_elev--;
            i--;
        }
    }
    system("CLS");
    cout << left << setw(15) << "NUME"
         << setw(15) << "PRENUME"
         << setw(8)  << "MODUL"
         << setw(30) << "EMAIL PARINTE"
         << setw(10) << "ABSENTE" << endl;
    cout << string(78, '-') << endl;

    for (int i = 0; i < nr_elev; i++)
    {
        cout << left << setw(15) << elv[i].nume
             << setw(15) << elv[i].prenume
             << setw(8)  << elv[i].modul
             << setw(30) << elv[i].emailp
             << setw(10) << elv[i].absente << endl;
    }
    system("pause");
}

void cautare_elev()
{
    system("CLS");
    int m;
    char l;
    cout << "1. Introduceti prima litera din numele elevului: ";
    cin >> l;
    cin.get();
    cout << "2. Introduceti modulul la care se afla elevul: ";
    cin >> m;
    int ok = 0;

    cout << endl << left << setw(15) << "NUME" << setw(15) << "PRENUME" << endl;
    cout << string(30, '-') << endl;

    for (int i = 0; i < nr_elev; i++)
    {
        if (elv[i].nume[0] == l && elv[i].modul == m)
        {
            cout << left << setw(15) << elv[i].nume << setw(15) << elv[i].prenume << endl;
            ok = 1;
        }
    }
    if (ok == 0)
    {
        do
        {
            cout << "\nNu exista elev in baza de date caruia sa ii corespunda aceste date." << endl;
            cout << "1. Cautati din nou" << endl;
            cout << "0. Inapoi la meniul anterior" << endl;
            cout << "Optiune: ";
            int tasta;
            cin >> tasta;
            switch (tasta)
            {
                case 1:
                    cautare_elev();
                    system("pause");
                    break;
            }
            if (tasta == 0)
                system("CLS");

        } while (tasta != 0);
    }
}

void sortare_elv()
{
    system("CLS");
    for (int i = 0; i < k1; i++)
    {
        for (int j = i + 1; j < k1; j++)
        {
            char aux[256] = "";
            if (strcmp(a1[i], a1[j]) > 0)
            {
                strcpy(aux, a1[i]);
                strcpy(a1[i], a1[j]);
                strcpy(a1[j], aux);
            }
        }
    }

    for (int i = 0; i < k2; i++)
    {
        for (int j = i + 1; j < k2; j++)
        {
            char aux[256] = "";
            if (strcmp(a2[i], a2[j]) > 0)
            {
                strcpy(aux, a2[i]);
                strcpy(a2[i], a2[j]);
                strcpy(a2[j], aux);
            }
        }
    }

    for (int i = 0; i < k3; i++)
    {
        for (int j = i + 1; j < k3; j++)
        {
            char aux[256] = "";
            if (strcmp(a3[i], a3[j]) > 0)
            {
                strcpy(aux, a3[i]);
                strcpy(a3[i], a3[j]);
                strcpy(a3[j], aux);
            }
        }
    }

    cout << left << setw(30) << "NUME COMPLET" << setw(8) << "MODUL" << endl;
    cout << string(38, '-') << endl;

    for (int i = 0; i < k1; i++)
        cout << left << setw(30) << a1[i] << setw(8) << "1" << endl;

    for (int i = 0; i < k2; i++)
        cout << left << setw(30) << a2[i] << setw(8) << "2" << endl;

    for (int i = 0; i < k3; i++)
        cout << left << setw(30) << a3[i] << setw(8) << "3" << endl;
}

void afisaree()
{
    system("CLS");
    cout << left << setw(15) << "NUME"
         << setw(15) << "PRENUME"
         << setw(8)  << "MODUL"
         << setw(30) << "EMAIL PARINTE"
         << setw(10) << "ABSENTE"
         << setw(12) << "ZI"
         << setw(15) << "TIP CURS" << endl;
    cout << string(105, '-') << endl;

    for (int i = 0; i < 30; i++)
    {
        cout << left << setw(15) << elv[i].nume
             << setw(15) << elv[i].prenume
             << setw(8)  << elv[i].modul
             << setw(30) << elv[i].emailp
             << setw(10) << elv[i].absente
             << setw(12) << elv[i].zi
             << setw(15) << elv[i].tipcurs << endl;
    }

    do
    {
        cout << endl;
        cout << "1. Sortare ordine alfabetica si modul" << endl;
        cout << "2. Stergeti elevii care au 5 sau mai multe absente" << endl;
        cout << "3. Cautare elev" << endl;
        cout << "4. Afisare elevi pe module" << endl;
        cout << "0. EXIT" << endl;
        cout << "Optiune: ";
        int tasta;
        cin >> tasta;
        switch (tasta)
        {
            case 1:
                sortare_elv();
                system("pause");
                break;
            case 2:
                stergere();
                system("pause");
                break;
            case 3:
                cautare_elev();
                system("pause");
                break;
            case 4:
                afisare_module();
                system("pause");
                break;
        }
    } while (tasta != 0);
    e.close();
}

void citirep()
{
    for (int i = 0; i < 6; i++)
    {
        f >> p[i].nume;
        f >> p[i].modul;
        f >> p[i].nrtlf;
        f >> p[i].salariu;
    }
}

void afisare_mod1()
{
    cout << "--- Profesori Modulul 1 ---" << endl;
    for (int i = 0; i < 6; i++)
        if (p[i].modul == 1)
            cout << p[i].nume << endl;
}

void afisare_mod2()
{
    cout << "--- Profesori Modulul 2 ---" << endl;
    for (int i = 0; i < 6; i++)
        if (p[i].modul == 2)
            cout << p[i].nume << endl;
}

void afisare_mod3()
{
    cout << "--- Profesori Modulul 3 ---" << endl;
    for (int i = 0; i < 6; i++)
        if (p[i].modul == 3)
            cout << p[i].nume << endl;
}

void afisarep()
{
    system("CLS");
    cout << left << setw(20) << "NUME"
         << setw(10) << "MODUL"
         << setw(15) << "NUMAR TELEFON" << endl;
    cout << string(45, '-') << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << left << setw(20) << p[i].nume
             << setw(10) << p[i].modul
             << setw(15) << p[i].nrtlf << endl;
    }

    int tasta;
    do
    {
        cout << "\nDoriti sa vizualizati separat modulul la care preda fiecare profesor? (da/nu): ";
        char txt[3];
        cin >> txt;
        if (stricmp(txt, "da") == 0)
        {
            system("CLS");
            do
            {
                cout << "1. Profesori modulul 1" << endl;
                cout << "2. Profesori modulul 2" << endl;
                cout << "3. Profesori modulul 3" << endl;
                cout << "0. Inapoi" << endl;
                cout << "Optiune: ";
                cin >> tasta;
                switch (tasta)
                {
                    case 1:
                        system("CLS");
                        afisare_mod1();
                        system("pause");
                        break;
                    case 2:
                        system("CLS");
                        afisare_mod2();
                        system("pause");
                        break;
                    case 3:
                        system("CLS");
                        afisare_mod3();
                        system("pause");
                        break;
                }
            } while (tasta != 0);
        }
        else
        {
            tasta = 0;
        }

    } while (tasta != 0);
}

int nrab = 0;

void citire_abonati()
{
    ifstream abon("abonati_site");
    nrab = 0;
    for (int i = 0; i < 30; i++)
    {
        abon >> abo[i].nume >> abo[i].prenume >> abo[i].nrtlfa;
        nrab++;
    }
    abon.close();
}

void sortare_abonati()
{
    char aux1[30] = "", aux2[30] = "", aux3[11] = "";
    system("CLS");
    for (int i = 0; i < nrab; i++)
    {
        for (int j = i + 1; j < nrab; j++)
        {
            if (strcmp(abo[i].nume, abo[j].nume) >= 1)
            {
                strcpy(aux1, abo[i].nume);
                strcpy(abo[i].nume, abo[j].nume);
                strcpy(abo[j].nume, aux1);

                strcpy(aux2, abo[i].prenume);
                strcpy(abo[i].prenume, abo[j].prenume);
                strcpy(abo[j].prenume, aux2);

                strcpy(aux3, abo[i].nrtlfa);
                strcpy(abo[i].nrtlfa, abo[j].nrtlfa);
                strcpy(abo[j].nrtlfa, aux3);
            }
        }
    }

    cout << left << setw(20) << "NUME"
         << setw(20) << "PRENUME"
         << setw(15) << "TELEFON" << endl;
    cout << string(55, '-') << endl;

    for (int i = 0; i < nrab; i++)
    {
        cout << left << setw(20) << abo[i].nume
             << setw(20) << abo[i].prenume
             << setw(15) << abo[i].nrtlfa << endl;
    }
}

void gasire_abonat()
{
    system("CLS");
    cout << "Abonati care sunt si elevi:" << endl;
    cout << left << setw(20) << "NUME" << setw(20) << "PRENUME" << endl;
    cout << string(40, '-') << endl;

    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (strcmp(elv[i].nume, abo[j].nume) == 0 && strcmp(abo[j].prenume, elv[i].prenume) == 0)
                cout << left << setw(20) << elv[i].nume << setw(20) << elv[i].prenume << endl;
        }
    }
}

void afisare_abonati()
{
    int tasta;
    system("CLS");
    cout << left << setw(20) << "NUME"
         << setw(20) << "PRENUME"
         << setw(15) << "TELEFON" << endl;
    cout << string(55, '-') << endl;

    for (int i = 0; i < 30; i++)
    {
        cout << left << setw(20) << abo[i].nume
             << setw(20) << abo[i].prenume
             << setw(15) << abo[i].nrtlfa << endl;
    }

    do
    {
        cout << endl;
        cout << "1. Sortare alfabetica abonati" << endl;
        cout << "2. Cautare abonati care sunt si elevi" << endl;
        cout << "0. EXIT" << endl;
        cout << "Optiune: ";
        cin >> tasta;
        switch (tasta)
        {
            case 1:
                sortare_abonati();
                system("pause");
                break;
            case 2:
                gasire_abonat();
                system("pause");
                break;
        }
    } while (tasta != 0);
}

void salveaza_abonati()
{
    ofstream abon("abonati_site");
    for (int i = 0; i < nrab; i++)
    {
        abon << abo[i].nume << " " << abo[i].prenume << " " << abo[i].nrtlfa;
        if (i != nrab - 1)
            abon << endl;
    }
    abon.close();
}

void login()
{
    int tasta;
    l >> log.nume >> log.prenume >> log.user >> log.parola;
    int exit = 0;
    char num[30], prenum[30], usern[40], parol[20];

    while (exit == 0)
    {
        system("CLS");
        cout << "Introduceti numele: ";
        cin >> num;
        cout << "Introduceti prenumele: ";
        cin >> prenum;
        cout << "Introduceti user-ul: ";
        cin >> usern;
        cout << "Introduceti parola: ";
        cin >> parol;

        if (strcmp(log.nume, num) == 0 && strcmp(log.prenume, prenum) == 0)
        {
            if (strcmp(log.user, usern) == 0 && strcmp(log.parola, parol) == 0)
            {
                log.logat = 1;
                exit = 1;

                do
                {
                    system("CLS");
                    cout << "V-ati logat cu succes!\n" << endl;
                    cout << "1. Afisare elevi" << endl;
                    cout << "2. Vizualizare profesori" << endl;
                    cout << "3. Afisare abonati site" << endl;
                    cout << "0. EXIT" << endl;
                    cout << "Optiune: ";
                    cin >> tasta;
                    switch (tasta)
                    {
                        case 1:
                            afisaree();
                            system("pause");
                            break;
                        case 2:
                            afisarep();
                            system("pause");
                            break;
                        case 3:
                            afisare_abonati();
                            system("pause");
                            break;
                    }
                } while (tasta != 0);
            }
            else
            {
                do
                {
                    cout << "\nUser sau parola incorecte!" << endl;
                    cout << "1. Incercati din nou" << endl;
                    cout << "0. EXIT" << endl;
                    cout << "Optiune: ";
                    cin >> tasta;
                    switch (tasta)
                    {
                        case 1:
                            login();
                            system("pause");
                            break;
                    }
                } while (tasta != 0);
            }
        }
        else
        {
            do
            {
                cout << "\nNume sau prenume incorecte!" << endl;
                cout << "1. Incercati din nou" << endl;
                cout << "0. EXIT" << endl;
                cout << "Optiune: ";
                cin >> tasta;
                switch (tasta)
                {
                    case 1:
                        login();
                        system("pause");
                        break;
                }
            } while (tasta != 0);
        }
    }
}

void curs_online()
{
    int tasta;
    system("CLS");
    char zi[20];
    cout << "Introduceti ziua in care doriti sa participati la curs: ";
    cin >> zi;
    cin.get();

    if (stricmp(zi, "marti") == 0 || stricmp(zi, "miercuri") == 0 || stricmp(zi, "joi") == 0)
    {
        do
        {
            cout << "Nu exista cursuri online in ziua aceasta." << endl;
            cout << "1. Incercati din nou" << endl;
            cout << "0. EXIT" << endl;
            cout << "Optiune: ";
            cin >> tasta;
            switch (tasta)
            {
                case 1:
                    curs_online();
                    system("pause");
                    break;
            }
        } while (tasta != 0);
    }
    else
    {
        if (stricmp(zi, "luni") == 0 && lunion >= 9)
        {
            cout << "Nu mai sunt locuri disponibile la acest curs." << endl;
            do
            {
                cout << "1. Incercati din nou" << endl;
                cout << "0. EXIT" << endl;
                cout << "Optiune: ";
                cin >> tasta;
                switch (tasta)
                {
                    case 1:
                        curs_online();
                        system("pause");
                        break;
                }
            } while (tasta != 0);
        }
        else if (stricmp(zi, "vineri") == 0 && vinerion >= 9)
        {
            cout << "Nu mai sunt locuri disponibile la acest curs." << endl;
            do
            {
                cout << "1. Incercati din nou" << endl;
                cout << "0. EXIT" << endl;
                cout << "Optiune: ";
                cin >> tasta;
                switch (tasta)
                {
                    case 1:
                        curs_online();
                        system("pause");
                        break;
                }
            } while (tasta != 0);
        }
        else
        {
            cout << "\nV-ati inscris cu succes la curs!" << endl;
            cout << "Va vom trimite prin SMS la numarul de telefon introdus alte detalii necesare." << endl;
            cout << "Apasati orice tasta pentru a reveni la meniul anterior.\n";
        }
    }
}

void curs_fizice()
{
    int tasta;
    system("CLS");
    char zi[20];
    cout << "Introduceti ziua in care doriti sa participati la curs: ";
    cin >> zi;
    cin.get();

    if (stricmp(zi, "sambata") == 0 || stricmp(zi, "duminica") == 0)
    {
        cout << "Nu exista cursuri fizice in ziua aceasta." << endl;
        cout << "1. Incercati din nou | 0. EXIT: ";
        do
        {
            cin >> tasta;
            switch (tasta)
            {
                case 1:
                    curs_fizice();
                    system("pause");
                    break;
            }
        } while (tasta != 0);
    }
    else
    {
        bool ocupat = false;
        if (stricmp(zi, "luni") == 0 && lunifiz >= 9) ocupat = true;
        else if (stricmp(zi, "marti") == 0 && martifiz >= 9) ocupat = true;
        else if (stricmp(zi, "miercuri") == 0 && miercurifiz >= 9) ocupat = true;
        else if (stricmp(zi, "joi") == 0 && joifiz >= 9) ocupat = true;
        else if (stricmp(zi, "vineri") == 0 && vinerifiz >= 9) ocupat = true;

        if (ocupat)
        {
            cout << "Nu mai sunt locuri disponibile la acest curs." << endl;
            do
            {
                cout << "1. Incercati din nou | 0. EXIT: ";
                cin >> tasta;
                switch (tasta)
                {
                    case 1:
                        curs_fizice();
                        system("pause");
                        break;
                }
            } while (tasta != 0);
        }
        else
        {
            cout << "\nV-ati inscris cu succes la curs!" << endl;
            cout << "Va vom trimite prin SMS detalii pentru inceperea cursurilor." << endl;
            cout << "Apasati orice tasta pentru a reveni la meniul anterior.\n";
        }
    }
}

void inscriere()
{
    int tasta;
    system("CLS");
    char numar[20];
    char nume[70], prenume[70];

    cout << "Introduceti numele dvs: ";
    cin >> nume;
    cout << "Introduceti prenumele dvs: ";
    cin >> prenume;
    cout << "Introduceti numarul de telefon: ";
    cin >> numar;

    if (numar[0] != '0' || numar[1] != '7')
    {
        do
        {
            cout << "Numarul de telefon nu este valabil pentru Romania." << endl;
            cout << "1. Incercati din nou | 0. EXIT: ";
            cin >> tasta;
            switch (tasta)
            {
                case 1:
                    inscriere();
                    system("pause");
                    break;
            }
        } while (tasta != 0);
    }
    else if (strlen(numar) != 10)
    {
        do
        {
            cout << "Numar de telefon invalid (trebuie sa aiba 10 cifre)." << endl;
            cout << "1. Incercati din nou | 0. EXIT: ";
            cin >> tasta;
            switch (tasta)
            {
                case 1:
                    inscriere();
                    system("pause");
                    break;
            }
        } while (tasta != 0);
    }
    else
    {
        int ok = 0;
        citire_abonati();
        for (int i = 0; i < 30 && ok == 0; i++)
        {
            if (strcmp(numar, abo[i].nrtlfa) == 0)
            {
                ok = 1;
                cout << "Abonat deja existent." << endl;
                do
                {
                    cout << "1. Incercati din nou | 0. EXIT: ";
                    cin >> tasta;
                    switch (tasta)
                    {
                        case 1:
                            inscriere();
                            system("pause");
                            break;
                    }
                } while (tasta != 0);
            }
        }
        if (ok == 0)
        {
            cout << "\nV-ati abonat cu succes!" << endl;
            citire_abonati();
            strcpy(abo[nrab].nume, nume);
            strcpy(abo[nrab].prenume, prenume);
            strcpy(abo[nrab].nrtlfa, numar);
            nrab++;
            salveaza_abonati();

            cout << "\nParticipati la cursurile de arhitectura?\n1. Da\n0. EXIT\nOptiune: ";
            cin >> tasta;
            system("CLS");
            if (tasta == 1)
            {
                do
                {
                    system("CLS");
                    cout << "1. Cursuri online" << endl;
                    cout << "2. Cursuri fizice" << endl;
                    cout << "0. EXIT" << endl;
                    cout << "Optiune: ";
                    cin >> tasta;
                    switch (tasta)
                    {
                        case 1:
                            curs_online();
                            system("pause");
                            break;
                        case 2:
                            curs_fizice();
                            system("pause");
                            break;
                    }
                } while (tasta != 0);
            }
        }
    }
}

void pret_curs()
{
    system("CLS");
    cout << "========================== TARIFE SI PROGRAM ==========================" << endl;
    cout << left << setw(20) << "TIP CURS" << setw(18) << "PRET" << setw(35) << "ORAR" << endl;
    cout << string(73, '-') << endl;
    cout << left << setw(20) << "Online" << setw(18) << "600 lei / luna" << setw(35) << "Luni / Vineri (15:00 - 20:00)" << endl;
    cout << left << setw(20) << "Fizic"  << setw(18) << "750 lei / luna" << setw(35) << "Luni - Vineri (15:00 - 20:00)" << endl;
    cout << string(73, '-') << endl;
    cout << "\nPentru a va inscrie, reveniti la meniul principal si selectati tasta 1." << endl;
    cout << "Apasati orice tasta pentru a reveni...\n";
}

void afisare_site()
{
    int tasta;
    do
    {
        system("CLS");
        cout << "1. Inscriere cursuri" << endl;
        cout << "2. Despre profesori" << endl;
        cout << "3. Pret cursuri" << endl;
        cout << "0. Inapoi la meniul principal" << endl;
        cout << "Optiune: ";
        cin >> tasta;
        switch (tasta)
        {
            case 1:
                inscriere();
                system("pause");
                break;
            case 2:
                afisarep();
                system("pause");
                break;
            case 3:
                pret_curs();
                system("pause");
                break;
        }
    } while (tasta != 0);
}

int main()
{
    system("color 20");
    cout << endl << endl;
    std::cout << "                                 __    __ __    __ __    __  _____  ________ _______ __    __ " << std::endl;
    std::cout << "                                 |  \\  |  |  |  |  |  |  |  |/  _  \\|__    __|   ____|  |  /  / " << std::endl;
    std::cout << "                                 |   \\ |  |  |  |  |  |  |  / \\  |  |  |  |  |    |  | /  / " << std::endl;
    std::cout << "                                 |    \\|  |  |  |  |  |  |  | |  |  |  |  |  |____|  |/  /  " << std::endl;
    std::cout << "                                 |        |  |  |  |  |  |  | |  |  |  |  |   ____|     <   " << std::endl;
    std::cout << "                                 |  |\\    |  |  |  |  |  |  | |  |  |  |  |  |    |  |\\  \\  " << std::endl;
    std::cout << "                                 |  | \\   |  \\__/  |\\  \\/  /|  \\_/  |  |  |  |____|  | \\  \\ " << std::endl;
    std::cout << "                                 |__|  \\__|\\______/  \\____/  \\_____/   |__|  |_______|__|  \\__\\ " << std::endl;
    cout << endl;
    cout << "                                   ___" << endl;
    cout << "                                  /--/" << endl;
    cout << "                                 /  /" << endl;
    cout << "                                /  /" << endl;
    cout << "                               /  /" << endl;
    cout << "                              /  /" << endl;
    cout << "                             /--/" << endl;
    cout << "                             \\ /" << endl << endl;

    citirep();
    citiree();
    citire_abonati();

    cout << "                     Apasati orice tasta pentru a afisa meniul principal...\n";
    system("pause");

    int tasta_main;
    do
    {
        system("CLS");
        cout << "1. Meniu administrare" << endl;
        cout << "2. Meniu acasa (Site)" << endl;
        cout << "0. EXIT" << endl;
        cout << "Optiune: ";
        cin >> tasta_main;
        switch (tasta_main)
        {
            case 1:
                login();
                system("pause");
                break;
            case 2:
                afisare_site();
                system("pause");
                break;
        }
    } while (tasta_main != 0);

    return 0;
}