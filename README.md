# Projekt PROI

## Dane zespołu

Numer zespołu: Z08

Skład zespołu: Bartosz Kowalski

## Tematyka i krótki opis

W ramach projektu stworzona została prosta aplikacja do obsługi pracowników firmy.

Aplikacja pozwala na operowanie na dwóch rodzajach pracowników:
- Employee - zwykły pracownik
- Manager - menedżer - od pracownika różni się możliwością przypisania do niego pracowników

Program pozwala między innymi na:
- Dodawanie, edytowanie oraz usuwanie pracowników
- Przypisywanie zwykłych pracowników do menedżerów
- Zapis oraz odczyt bazy danych z pliku

## Struktura

Kod źródłowy aplikacji składa się z 8 plików z rozszerzeniem .cpp oraz z 7 plików nagłówkowych .h.
Każdy z 7 plików nagłówkowych .h wraz z odpowiadającym mu plikiem .cpp odpowiadają jednej z siedmiu klas:
- Date - klasa reprezentująca datę
- Person - klasa reprezentująca osobę, dziedzicząca po klasie Date
- Employee - klasa reprezentująca zwykłego pracownika, dziedzicząca po klasie Person
- Manager - klasa reprezentująca menedżera, dziedzicząca po klasie Employee
- Database - klasa reprezentująca bazę danych, która zawiera w sobie obiekty klas Employee oraz Manager
- FileHandler - klasa obsługująca zapis bazy danych do pliku oraz odczyt bazy danych z pliku do programu
- Interface - klasa pozwalająca na interakcję użytkownika z programem

# Opis klas

## Date

Klasa Date reprezentuje datę w postaci DD-MM-YYYY, bez uwzględniania zer wiodących.
Jej atrybuty to:
- day - oznacza dzień - w postaci usigned int
- month - oznacza miesiąc - w postaci unsigned int
- year - oznacza rok - w postaci unsigned int
Klasa zawiera również publiczne metody pozwalające zwrócić dzień, miesiąc, rok, ustawić dzień, miesiąc, rok oraz metodę wypisującą datę.
Znaleźć w niej również można operatory porównania (<, >, <=, >=, ==, !=) oraz przypisania.

## Person

Klasa Person reprezentuje osobę, w celu stworzenia na jej podstawie kolejnych klas dziedziczących, na przykład Employee.
Atrybutami klasy Person są:
- name - oznacza imię - w postaci string
- surname - oznacza nazwisko - w postaci string
- birth_date - oznacza datę urodzenia - w postaci Date
- pesel - oznacza PESEL - w postaci string
- gender - oznacza płeć - w postaci string
Klasa zawiera również publiczne metody pozwalające zwrócić wartości wszystch atrybutów, pozwalające ustawić wartości wszystkich atrybutów oraz metodę wypisującą informacje o osobie.

## Employee

Klasa Employee reprezentuje zwykłego pracownika w firmie, dziedziczy ona po klasie Person wszystkie jej atrybuty oraz metody.
Ponadto atrybutami klasy Employee są:
- employee_id - oznacza ID pracownika w firmie, przydzielane automatycznie od 1 - w postaci unsigned int
- salary - oznacza miesięczną pensję brutto - w postaci unsigned int
- date_employeed - oznacza datę dołączenia pracownika do firmy - w postaci Date
- type - oznacza typ pracownika, w celu rozpoznania przez program, zawsze o wartości "Employee" - w postaci string
Klasa zawiera również publiczne metody pozwalające zwrócić wartości wszystkich atrybutów, pozwalające ustawić wartości wszystkich atrybutów, poza atrybutem type.
Zawiera ona również operatory porównania (<, >, <=, >=, ==, !=), porównujące obiekty klasy Employee pod względem ich ID, oraz funkcje wirtualne wykorzystywane przez klasę Manager dziedziczącą po klasie Employee.

## Manager

Klasa Manager reprezentuje pracownika na stanowisku menedżerskim w firmie, dziedziczy ona po klasie Employee wszystkie jej atrybuty oraz metody.
Klasa Manager różni się od klasy Employee listą przypisanych do menedżera pracowników oraz metodami do obsługi tej listy.
Ponadto atrybutami klasy Manager są:
- employees - oznacza listę identyfikatorów pracowników podlegających temu menedżerowi - w postaci wektora zmiennych typu int
- employees_number - oznacza liczbę pracowników podlegających temu menedżerowi - w postaci int
Klasa zawiera wszystkie dziedzicone po klasie Employee metody, zawiera również publiczne metody:
- get_employees() - zwraca wektor identyfikatorów pracowników podlegających menedżerowi
- get_employees_number() - zwraca liczbę pracowników podlegających menedżerowi
- assign_employee() - za argument przyjmuje identyfikator pracownika i jeżeli pracownik o danym id nie jest do nikogo przypisany, to dopisuje podane id do wektora employees
- dismiss_employee_by_id() - za argument przyjmuje idektyfikator pracownika i jeżeli pracownik o danym id jest przypisany do danego menedżera to jego idektyfikator zostaje usunięty z wektora employees

## Database

Klasa Database reprezentuje bazę danych w postaci wektora obiektów typu std::unique_ptr.
Wykorzystywana ona jest praktyczie w każdym momencie działania programu do obsługi zmian w bazie danych wprowadzanych przez użytkownika.
Klasa Database posiada dwa atrybuty:
- database - wektor obiektów typu std::unique_ptr&lt;Employee> - jest wektorem zawierającym wskazania na wszystkich pracowników, zarówno klasy Employee, jak i klasy Manager
- max_employees - zmienna typu int - zapamiętuje ilu pracowników zostało już stworzonych, aby po usunięciu któregoś z nich, unikatowy identyfikator pracownika nie miał prawa się powtórzyć i zostać przypisany do nowego pracownika
Klasa Database posiada również publiczne metody:
- add_employee() - przyjmująca za argumenty typ pracownika (Employee lub Manager) oraz atrybuty takie jak imię, czy datę urodzenia, oraz dodająca pracownika do bazy danych, nadając mu automatycznie unikalny indeks pracowniczy
- remove_employee() - przyjmująca za argument identyfikator pracownika i usuwająca pracownika z bazy, jeżeli taki pracownik istnieje. Jeżeli usunięty pracownik był przypisany do jakiegoś menedżera, to inna metoda innej klasy usuwa indeks pracownika z listy.
- print_employee() - przyjmująca za argument identyfikator pracownika i wypisująca jego dane
- print_all_employees() - wypisująca wszystkich pracowników
- get_db_ptr() - zwracająca wskaźnik na bazę danych
- clear_database() - czyszcząca bazę danych i resetująca do wartości 0 atrybut max_employes
- assign_employee_by_id() - przyjmująca za argument identyfikator menedżera oraz pracownika i jeżeli pracownik nie jest przypisany do żadnego menedżera to przypisująca podanego pracownika do podanego menedżera
- dismiss_employee_by_id() - przyjmująca za argument identyfikator menedżera oraz pracownika i jeżeli pracownik jest przypisany do danego menedżera to usuwająca podanego pracownika z listy pracowników danego menedżera
- get_employees_number() - zwraca liczbę pracowników w bazie danych

## FileHandler

Klasa FileHandler jest klasą obsługującą zapis do pliku oraz odczyt z pliku baz danych.
Wykorzystywana jest ona do zapisu do pliku i odczytu z pliku baz danych w postaci pliku z rozszerzeniem .txt w momencie, gdy użytkownik tego zażąda.
Jedynym jej atrybutem jest database - wskaźnik na bazę danych, która jest aktualnie obsługiwana przez program - w postaci Database*
Posiada ona trzy publiczne metody:
- save() - przyjmująca za argument ścieżkę do pliku i zapisująca bazę danych do pliku o podanej ścieżce
- load() - przyjmująca za argument ścieżkę do pliku i odczytujące bazę danych z pliku o podanej ścieżce
- input_db_ptr() - przyjmująca za argument wskazanie na bazę danych, którą będzie obsługiwać

## Interface

Klasa Interface jest klasą pośredniczącą między użytkownikiem a programem, obsługującą jego żądania i przekazującą żądania do obiektów klas Database oraz FileHandler.
Posiada ona dwa atrybuty:
- database - wskazanie na aktualnie obsługiwaną bazę danych - w postaci Database*
- file_handler - wskazanie na aktualnie obsługiwany obiekt klasy FileHandler - w postaci FileHandler*
Posiada ona również publiczne metody:
- input_db_ptr() - przyjmująca za argument wskazanie na bazę danych, którą będzie obsługiwać
- input_fh_ptr() - przyjmująca za argument wskazanie na obiekt klasy FileHandler, którą będzie obsługiwać
- main_menu() - wyświetla interfejs menu głównego
- clear_screen() - czyści ekran
- add_person() - wyświetla interfejs dodawania pracownika
- remove_preson() - wyświetla interfejs usuwania pracownika
- edit_person() - wyświetla interfejs edytowania pracownika
- show_all() - wyświetla wszystkich pracowników
- show_employees() - wyświetla wszystkich pracowników klasy Employee
- show_managers() - wyświetla wszystkich menedżerów
- save_database() - wysyła żądanie do obiektu klasy FileHandler w celu zapisania do pliku aktualnej bazy danych
- load_database() - wysyła żądanie do obiektu klasy FileHandler w celu odczytania z pliku zapisanej bazy danych
- quit_app() - kończy działanie programu

# Testy

Program został testowany na bieżąco w momencie dodawania nowych metod oraz został ostatecznie przetestowany pod kątem sytuacji zarówno standardowych, jak i niestandarowych pod zakończeniu pisania kodu.

Do testowania programu został stworzony plik "test.txt".

# Uruchomienie

Aby uruchomić program należy przede wszystkim posiadać kompilator C++ oraz umieścić wszystkie pliki:
- .cpp
- .h
- makefile
w jednym folderze, a następnie w terminalu wpisać następujące komendy:
- make
- ./app.out
