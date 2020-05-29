#include "v03.h"
int main()
{
    ofstream fr("kursiokai.txt");
    string failas0 = "Pirmas.txt";
    string ats = "Atsakymai1.1.txt";
    string ats1 = "Atsakymai1.2.txt";
    Vector <pazymiai> N;
    int n, k = 1000, rekursija = 1, namudarbuskc = 5, rekursija2 = 1;
    Vector <pazymiai> M;
    int x = 1, a = 0;
    char MV;
    string failas5;
    srand(time(NULL));
    cout << "Ar norite duomenis nuskaityt is failo?" << endl;
    string nuskaitymas, line, dummyline;
    bool nuskaitymas2 = false;
    while (1)
    {
        cin >> nuskaitymas;
        if (nuskaitymas == "taip")
        {
            nuskaitymas2 = true;
            break;
        }
        else if (nuskaitymas == "ne")
        {
            nuskaitymas2 = false;
            break;
        }
        else {
            cin.clear();
            cin.ignore(500, '\n');
            cout << "KLAIDA. Irasykite 'taip' arba 'ne' " << endl;
        }
    }
    bool nuskaitymas5 = false;
    if (nuskaitymas2 == true)
    {
        cout << "Jei norite atlikti testavima spauskite 't', jei norite skaityti is turimo failo 'f'" << endl;
        while (1)
        {
            cin >> failas5;
            if (failas5 == "t")
            {
                nuskaitymas2 = false;
                nuskaitymas5 = true;
                break;
            }
            else if (failas5 == "f")
            {
                nuskaitymas5 = false;
                break;
            }
            else {
                cin.clear();
                cin.ignore(500, '\n');
                cout << "KLAIDA. Iveskite tinkama raide " << endl;
            }
        }
    }
    string failas;
    ifstream fd;
    if (nuskaitymas2 == true)
    {
        while (1)
        {
            if (nuskaitymas2 == true)
            {
                cout << "Iveskite failo pavadinima" << endl;
                cin >> failas;
            }
            fd.open(failas);
            try {
                if (fd.is_open())
                {
                    throw(1);
                }
                else throw(1.0);
            }
            catch (int)
            {
                cout << "Failas rastas" << endl;
                break;
            }
            catch (double)
            {
                cout << "Failas nerastras bandykite dar karta" << endl;
            }
        }
    }
    cout << "Jei galutini bala norite skauciuoti su mediana spauskite M, jei vidurkiu V " << endl;
    while (1)
    {
        cin >> MV;
        if (MV == 'M' || MV == 'V')
        {
            break;
        }
        else {
            cin.clear();
            cin.ignore(500, '\n');
            cout << "KLAIDA. Iveskite tinkama raide " << endl;
        }

    }
    string Skaityt;
    using hrClock = std::chrono::high_resolution_clock;
    std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    string Gavimas("Pirmas.txt");
    int N1 = 0, B1 = 0;
    if (nuskaitymas5 == true)
    {
        Gen(rekursija, k, failas0, namudarbuskc, mt);
        Nuskaitymas(Gavimas, dummyline, line, M, a, MV, x, N, N1, B1, ats, ats1, rekursija2);
    }
    if (nuskaitymas2 == true)
    {
        getline(fd, dummyline);
        while (getline(fd, line))
        {
            stringstream ss(line);
            int numOfWords = countWords(line) - 3;
            int exam, suma = 0;
            double mediana = 0;
            M.push_back(pazymiai());
            ss >> Skaityt;
            M[a].SetPavarde(Skaityt);
            ss >> Skaityt;
            M[a].SetVardas(Skaityt);
            int temp;
            for (int i = 0; i < numOfWords; i++)
            {
                ss >> temp;
                suma += temp;
                M[a].SetPazymys(temp); //
            }
            ss >> exam;
            if (MV == 'V')
                M[a].SetGalutinis(0.4 * (suma / numOfWords) + (0.6 * exam));
            else if (MV == 'M')
            {
                M[a].Sort();
                if (numOfWords % 2 != 0)
                {
                    int k = 0, kint;
                    k = numOfWords / 2;
                    kint = numOfWords;
                    kint -= k;
                    mediana = M[a].GetPazymys(kint - 1);
                }
                else
                {
                    int k = 0;
                    k = numOfWords / 2;
                    mediana = (M[a].GetPazymys(k - 1) + M[a].GetPazymys(k)) / 2;
                }
                M[a].SetGalutinis((0.4 * mediana) + (0.6 * exam));
            }
            a++;
            x = a;
        }
    }
    else if (nuskaitymas2 == false && nuskaitymas5 == false) {
        string Kint;
        for (int i = 0; i < x; i++)
        {
            M.push_back(pazymiai());
            cout << "Iveskite studento varda" << endl;
            cin >> Kint;
            M[i].SetVardas(Kint);
            cin.ignore();
            cin.clear();
            cout << "Iveskite studento pavarde" << endl;
            cin >> Kint;
            M[i].SetPavarde(Kint);
            cout << "Ar norite namu darbu rezultatus sugeneruoti atsitiktinai?" << endl;
            string atsakymas;
            while (1)
            {
                cin >> atsakymas;
                if (atsakymas == "taip" || atsakymas == "ne")
                {
                    break;
                }
                else {
                    cin.clear();
                    cin.ignore(500, '\n');
                    cout << "KLAIDA. Irasykite 'taip' arba 'ne' " << endl;
                }
            }
            int a = 0;
            double kiekis = 0, mediana = 0;
            double skc;
            if (atsakymas == "ne")
            {
                cout << "Iveskite studento namu darbu rezultatus. Jei visus rezultatus suvedete iveskite '-1'" << endl;
                while (1)
                {
                    cin >> skc;
                    if (skc > 10 || skc < -1)
                    {
                        cout << "Tokio pazymio nera, rasykite toliau " << endl;
                    }
                    if (a == 0 && skc == 0)
                    {
                        cin.clear();
                        cin.ignore(500, '\n');
                        cout << "KLAIDA. Iveskite tinkama skaiciu " << endl;
                    }
                    else
                    {
                        if (!cin.fail() && skc <= 10 && skc >= 1 && skc == (int)skc)
                        {
                            M[i].SetPazymys(skc);
                            a++;
                            kiekis += skc;
                        }
                        else if (skc != (int)skc)cout << "KLAIDA. Iveskite naturalujy skaiciu" << endl;
                    }
                    if (cin.fail() || skc == 0)
                    {
                        cin.clear();
                        cin.ignore(500, '\n');
                        cout << "KLAIDA. Iveskite tinkama skaiciu " << endl;
                    }
                    if (a != 0 && skc == -1)
                        break;
                }
            }
            else {
                cout << "Kiek norite kad studentas turetu pazymiu? " << endl;
                double n;
                while (1)
                {
                    cin >> n;
                    if (!cin.fail() && n > 0 && n == (int)n)
                    {
                        break;
                    }
                    else
                    {
                        cin.clear();
                        cin.ignore(500, '\n');
                        cout << "KLAIDA. skaicius negalimas ";
                    }
                }
                for (int j = 0; j < n; j++)
                {
                    a++;
                    M[i].SetPazymys(rand() % 10 + 1);
                    cout << M[i].GetPazymys(j) << endl;
                    kiekis += M[i].GetPazymys(j);
                }
            }
            cout << "Ar norite sugeneruoti egzamino rezultata?" << endl;
            string klausimas2;
            while (1)
            {
                cin >> klausimas2;
                if (klausimas2 == "taip" || klausimas2 == "ne")
                {
                    break;
                }
                else {
                    cin.clear();
                    cin.ignore(500, '\n');
                    cout << "KLAIDA. Irasykite 'taip' arba 'ne' " << endl;
                }
            }
            double egzaminas;
            if (klausimas2 == "ne")
            {
                cout << "Iveskite studento egzamino rezultata" << endl;
                while (1)
                {
                    cin >> egzaminas;
                    if (!cin.fail() && egzaminas <= 10 && egzaminas == (int)egzaminas && egzaminas > 0 && egzaminas == (int)egzaminas)
                    {
                        break;
                    }
                    else
                    {
                        cin.clear();
                        cin.ignore(500, '\n');
                        cout << "KLAIDA. Iveskite tinkama egzamino rezultata desimtbaleje sistemoje " << endl;
                    }
                }

            }
            else if (klausimas2 == "taip")
            {
                egzaminas = rand() % 10 + 1;
                cout << egzaminas << endl;
            }
            if (MV == 'V')
                M[i].SetGalutinis(0.4 * (kiekis / a) + (0.6 * egzaminas));
            else if (MV == 'M')
            {
                M[i].Sort();
                // sort(M[i].pazymys.begin(), M[i].pazymys.end());
                if (a % 2 != 0)
                {
                    int k = 0;
                    k = a / 2;
                    a -= k;
                    mediana = M[i].GetPazymys(a - 1);
                }
                else
                {
                    int k = 0;
                    k = a / 2;
                    mediana = (M[i].GetPazymys(k - 1) + M[i].GetPazymys(k)) / 2;
                }
                M[i].SetGalutinis((0.4 * mediana) + (0.6 * egzaminas));
            }
            cout << "Ar yra daugiau studentu? Jei taip rasykite 'taip' " << endl;
            string klausimas;
            cin >> klausimas;
            if (klausimas == "taip")
            {
                x++;
                a = 0;
                kiekis = 0;
            }
        }
    }
    string rikiavimas;
    if (nuskaitymas5 == false)
    {
        cout << "Kaip norite surikiuoti sarasa pagal vardus ar pavardes?" << endl;
        while (1)
        {
            cin >> rikiavimas;
            if (rikiavimas == "vardus" || rikiavimas == "pavardes")
            {
                break;
            }
            else {
                cin.clear();
                cin.ignore(500, '\n');
                cout << "KLAIDA. Pasirinkite ar rikiuoti pagal vardus ar pavardes" << endl;
            }

        }
        if (rikiavimas == "vardus")
            sort(M.begin(), M.end(), Rikiavimas);
        else sort(M.begin(), M.end(), Rikiavimas1);
    }
    if (nuskaitymas5 == false)
    {
        fr << "Pavarde";
        fr << setw(14);
        fr << "Vardas";
        fr << setw(24);
        if (MV == 'M')
        {
            fr << "Galutinis (Med.)" << endl;
            for (int i = 0; i < x; i++)
            {
                fr << M[i].GetPavarde();
                fr << setw(14);
                fr << M[i].GetVardas();
                fr << setw(20);
                fr << fixed << setprecision(2) << M[i].GetGalutinis() << endl;
            }
        }
        else if (MV == 'V')
        {
            fr << "Galutinis(Vid.)" << endl;
            for (int i = 0; i < x; i++)
            {
                fr << M[i].GetPavarde();
                fr << setw(14);
                fr << M[i].GetVardas();
                fr << setw(20);
                fr << fixed << setprecision(2) << M[i].GetGalutinis() << endl;
            }
        }
    }
}
