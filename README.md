Platformă de Management - Cursuri de Arhitectură

Aceasta este o aplicație consolă scrisă în C++ concepută pentru a gestiona activitatea unei școli de arhitectură. Proiectul simulează atât o platformă publică (un "site" pentru utilizatori), cât și o bază de date cu acces restricționat pentru administratori.

Funcționalități principale

Aplicația este structurată în două secțiuni principale:

    1. Meniul Acasă (Interfața publică / Site)

    Înscriere cursuri: Utilizatorii se pot abona și se pot înscrie la cursuri de arhitectură (în format Online sau Fizic).
    Sistem de locuri limitate: Verifică disponibilitatea locurilor pentru fiecare zi a săptămânii.
    Detalii profesori: Afișează informații despre profesorii disponibili pentru fiecare modul.
    Tarife și Program: Afișează o grilă cu prețurile și orarul cursurilor.

    2. Meniul Administrare (Acces pe bază de cont)

    Sistem de Login: Acces protejat prin user și parolă.
    Gestiune Elevi: Afișare elevi grupați pe module (1, 2 sau 3).
    Sortare alfabetică a elevilor.
    Căutare rapidă după prima literă a numelui și numărul modulului.
    Ștergerea automată a elevilor care au acumulat 5 sau mai multe absențe.
    Gestiune Profesori: Vizualizarea listei de profesori și a modulelor la care predau.
    Gestiune Abonați: Afișarea bazei de date cu abonații site-ului, sortare alfabetică și identificarea abonaților care sunt deja elevi.

Structura fișierelor

    Pentru ca aplicația să ruleze corect, are nevoie de următoarele fișiere text în același folder cu executabilul (fără extensia .txt în nume, exact cum sunt apelate în cod):

    date_logare - Conține datele de autentificare pentru admin (format: Nume Prenume User Parola).
    elevi - Baza de date cu elevii.
    profesori - Baza de date cu profesorii.
    abonati_site - Fișierul în care se salvează noii abonați.

Tehnologii utilizate

Limbaj: C++

    Concepte: Programare procedurală, structuri (struct), manipularea fișierelor (<fstream>), algoritmi de sortare, manipulare de șiruri de caractere (<cstring>).

    Sistem de operare: Windows (aplicația folosește comenzi specifice precum system("CLS") și system("color 20")).

Cum să rulezi proiectul

    Asigură-te că ai un compilator C++ instalat (ex: MinGW pentru Windows).

    Creează fișierele de date menționate mai sus (elevi, profesori, etc.) și populează-le cu date de test.

    Compilează codul sursă:

    g++ main.cpp -o arhitectura


    Rulează executabilul generat:

    ./arhitectura.exe
# NuvotekStudioArhitectura
