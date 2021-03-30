#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <ctime>
#include <windows.h>
using namespace std;
//ф-я выводит информацию о программе
void about(int k) {
    while (true) {
        system("cls");
        cout << "Приложение для поиска музыки" << endl << "Версия (выпуск) 1.0" << endl << "Коршакова Ирина, группа 4932" << endl << endl  << "Для того, чтобы вернуться в главное меню нажмите 0: ";
        cin >> k;
        if (k == 0) break;
    }
}

//ф-я выводит совет по выбору музыки
void advice(int k) {
    while (true) {
        system("cls");
        cout << "Очень рекомендую поп-рок музыку от LP!" << endl << endl << "Для того, чтобы вернуться в главное меню нажмите 0: ";
        cin >> k;
        if (k == 0) break;
    }
}
//ф-я выводит из файла песни альбома
void find_songs(string sin) {
    system("cls");
    std::ifstream file;
    static char buff[1024][1024];
    int i = 0;
    file.open(sin);
    if (!file.good()) cout << "Файл не найден или не может быть открыт" << endl;
    else{
        cout << endl;
        while (!file.eof()) {
            file.getline(buff[i], sizeof(buff)); 
            cout << i + 1 << ". " << buff[i] << endl; ++i;
        }
    }
    file.close();
    cin.ignore();
    cout << endl;
    while (true) {
        cout << "Если при нажатии 0, вы не возвращаетесь назад, нажмите его еще раз, пока не вернетесь." << endl << endl << "Для того, чтобы вернуться нажмите 0. Ввод: ";
        cin >> sin;
        if (sin == "0") break;
    }   
    system("cls");
}
//ф-я выводит из файла список альбомов
void find_albums(string sin) {
    system("cls");
    std::ifstream file;
    static char buff[1024][1024];
    int i = 0;
    file.open(sin);
    if (!file.good()) cout << "Файл не найден или не может быть открыт" << endl;
    else {
        cout << endl;
        while (!file.eof()){
            file.getline(buff[i], sizeof(buff)); 
            cout << i+1 << ". " << buff[i] << endl; ++i;
        }
    }
    file.close();
    cin.ignore();
    cout << endl;
    while (true) {
        cout << "Если при нажатии 0, вы не возвращаетесь назад, нажмите его еще раз, пока не вернетесь." << endl << endl << "Для того, чтобы вернуться нажмите 0.\nЧтобы посмотреть песни альбома, введите его название.\nПробелы заменить символом '_'\nВвод: ";
        cin >> sin;
        sin = sin + ".txt";
        if (sin != "0.txt") find_songs(sin);
        if (sin == "0.txt") break;
    }   
    system("cls");
}
//ф-я выводит информацию об исполнителе из файла
void find_singer(string sin) {
    system("cls");
    std::ifstream file;
    static char buff[1024][1024];
    int i = 0;
    file.open(sin);
    if (!file.good()) cout << "Файл не найден или не может быть открыт" << endl;
    else{
        cout << endl;
        while (!file.eof()) {
            file.getline(buff[i], sizeof(buff)); 
            cout << buff[i] << endl;  ++i;
        }
    }
    file.close();
    cin.ignore();
    cout << endl;
    while (true) {
        cout << "Если при нажатии 0, вы не возвращаетесь назад, нажмите его еще раз, пока не вернетесь." << endl << endl << "Для того, чтобы вернуться нажмите 0.\nЧтобы посмотреть альбомы исполнителя, введите имя исполнителя еще раз.\nПробелы заменить символом '_'\nВвод: ";
        cin >> sin;
        sin = sin + "album.txt";
        if (sin != "0album.txt") find_albums(sin);
        else return;
    }
    system("cls");
}
//ф-я выводит список исполнителей из файла
void list() {
    system("cls");
    ifstream file;
    file.open("List.txt");
    string sin;
    static char buff[1024][1024];
    int i = 0;
    if (!file.is_open()) printf("Не удалось открыть файл со списком исполнителей");
    else{
        cout << endl;
        cout << "Список исполнителей:" << endl;
        while (!file.eof()) {
            file.getline(buff[i], sizeof(buff)); 
            cout << i+1 << ". " <<  buff[i] << endl; ++i;
        }
    }
    cout << "0. Возврат в меню исполнителей" << endl;
    file.close();
    cin.ignore();
    cout << endl;
    while (true) {
        cout << "Для того, чтобы вернуться нажмите 0.\nЧтобы найти информацию об исполнителе, введите его имя\nВвод: ";
        cin >> sin;
        sin = sin + ".txt";
        if (sin != "0.txt") find_singer(sin);
        else return;
    }
    system("cls");
}
//ф-я меню исполнителей
void singers() {
    int s;
    system("cls");
    while (true) {
        system("cls");
        cout << endl;
        cout << "+-------------------------------------+" << endl;
        cout << "|          Меню исполнителей          |" << endl;
        cout << "|-------------------------------------|" << endl;
        cout << "|  1)  Просмотр исполнителей          |" << endl;
        cout << "|  0)  Выход в главное меню           |" << endl;
        cout << "+-------------------------------------+" << endl << endl << "Выберите действие. Ввод: ";
        cin >> s;
        if (s == 0) break;
        if (s == 1) list();
    }
}
//ф-я проверки строки на наличие цифр
bool ischislo(string str) {
    bool is_num = false;
    for (auto c: str) {
        if (c >= '0' && c <= '9'){ is_num = true; break;}
    }
    return is_num;
}
//ф-я добавления информации об исполнителе в соответствующие файлы
void insert() {
    cout << "Если имя исполнителя или альбома состоит из нескольких слов, то пробелы заменить на '_'.\nЗа раз можно добавить 1 исполнителя." << endl;
    ofstream file;
    file.open("List.txt", ios::app);
    string name;
    cout << "Введите исполнителя: ";
    cin >> name;
    while (ischislo(name)) {
        cout << "Имя исполнителя не должно содержать цифр (Бзиг кодера)." << endl << "Введите исполнителя: ";
        cin >> name;
    }
    if (!file.is_open()) printf("Не удалось открыть файл со списком исполнителей");
    else
        file << "\n" << name;
    string about;
    cout << "Напишите что-нибудь об исполнителе. В конце не забудьте поставить точку: ";
    getline(cin, about, '.');
    while (ischislo(about)) {
        cout << "Не должно быть цифр (Бзиг кодера)." << endl << "Введите информацию об исполнителе заново: ";
        getline(cin, about, '.');
    }
    ofstream out(name); 
    out << about;
    out.close();
    string album;
    cout << "Введите альбом исполнителя: ";
    cin >> album;
    while (ischislo(album)) {
        cout << "Название альбома не должно содержать цифр (Бзиг кодера)." << endl << "Введите альбом исполнителя: ";
        cin >> album;
    }
    ofstream ou(name + "album");
    ou << album;
    ou.close();
    string songs;
    cout << "Введите песни исполнителя этого альбома. В конце не забудьте поставить точку: ";
    getline(cin, songs, '.');
    while (ischislo(songs)) {
        cout << "Название песни не должно содержать цифр (Бзиг кодера)." << endl << "Введите названия песен: ";
        getline(cin, songs, '.');
    }
    ofstream o(album);
    o << songs;
    o.close();
    cout << "0. Вернуться" << endl;
    file.close();
    cin.ignore();
}
//ф-я удаления информации об исполнителе
void delete_singer() {
    string name;
    string line;
    cout << "Введите исполнителя, которого хотите удалить." << endl << "Ввод: ";
    cin >> name;
    ifstream f("List.txt"); ofstream j("e.txt");
    if (!f.is_open()) printf("Не удалось открыть файл.");
    else{
        while (getline(f, line)) {
            if (line != name) j  << line << "\n";
        }
    }
    f.close(); j.close();
    string s = name + ".txt";
    remove("List.txt"); rename("e.txt", "List.txt");
    string r = name + "album.txt";
    remove(r.c_str()); remove(s.c_str());
}
//ф-я очистки файла с альбомами
void clean_album() {
    string n;
    cout << "Введите исполнителя, альбомы которого хотите удалить." << endl << "Ввод: ";
    cin >> n;
    fstream file; file.open(n+"album.txt", ios::out); file << ""; file.close();
}
//ф-я очистки файла с песнями
void clean_songs() {
    string alb;
    cout << "Введите название альбома (пробелы заменяются на '_'), песни которого хотите удалить." << endl << "Ввод: ";
    cin >> alb;
    fstream file; file.open(alb+".txt", ios::out); file << ""; file.close();
}
//ф-я очистки списка исполнителей
void clean_list() {
    fstream file; file.open("List.txt", ios::out); file << ""; file.close();
}
//ф-я очистки информации об исполнителе
void clean_about() {
    string a;
    cout << "Введите исполнителя, информацию о котором хотите удалить." << endl << "Ввод: ";
    cin >> a;
    fstream file; file.open(a + ".txt", ios::out); file << ""; file.close();
}
//ф-я редактировния информации об исполнителе
void edit_singer() {
    cout << "Введите имя исполнителя, чтобы отредактировать его. Ввод: " << endl;
    string name; string red; string line;
    cin >> name;
    cout << "Введите отредактированное имя исполнителя. Ввод: " << endl;   
    cin >> red;
    while (ischislo(red)) {
        cout << "Имя исполнителя не должно содержать цифр (Бзиг кодера)." << endl << "Введите отредактированное имя исполнителя. Ввод: ";
        cin >> red;
    }
    ifstream f("List.txt"); ofstream j("e.txt");
    if (!f.is_open()) printf("Не удалось открыть файл.");
    else{
        while (getline(f, line)) {
            if (line != name)  j << line << "\n";
            else j << red << "\n";
        }
    }
    f.close(); j.close();
    remove("List.txt"); rename("e.txt", "List.txt");
    string t = name + ".txt"; string q = red + ".txt";
    rename(t.c_str(),q.c_str());
    string tt = name + "album.txt"; string qq = red + "album.txt";
    rename(tt.c_str(), qq.c_str());
}
//ф-я возващает кол-во строк в файле
int CountLinesInFile(string filename){
    ifstream F(filename, ios::in);
    if (!F) return -1;
    int count = 0;
    char buffer[1000]; 
    while (!F.eof()){
        count++;
        F.getline(buffer, 1000);
    }
    F.close();
    return count;
}
//ф-я записывает в массив строки из файла
int GetStringsFromFileS(string filename, string** _lines) {
    string* lines;
    int n = CountLinesInFile(filename);
    if (n == -1) return -1;
    ifstream F(filename);
    if (!F) return -1;
    try {lines = new string[n];}
    catch (bad_alloc e){
        cout << e.what() << endl; 
        F.close();
        return -2; 
    }
    char buffer[1000]; 
    for (int i = 0; i < n; i++){
        F.getline(buffer, 1000);
        int len;
        for (len = 0; buffer[len] != '\0'; len++);
        lines[i].assign(buffer, len);
    }
    F.close();
    *_lines = lines;
    return n;
}
//ф-я записывает строки в файл из массива
bool SetStringsToFileS(string filename, string* lines, int count) {
    ofstream F(filename);
    if (!F) return false;
    for (int i = 0; i < count - 1; i++)
        F << lines[i] << endl;
    F << lines[count - 1];
    F.close();
    return true;
}
//ф-я сортирует данные в файле по алфавиту
bool SortStringsInFile(string filename) {
    int count;
    string* lines = nullptr; string s;
    count = GetStringsFromFileS(filename, &lines);
    if (count < 0) return false;
    for (int i = 0; i < count - 1; i++)
        for (int j = i; j >= 0; j--)
            if (lines[j] > lines[j + 1]) {
                s = lines[j];
                lines[j] = lines[j + 1];
                lines[j + 1] = s;
            }
    bool res = SetStringsToFileS(filename, lines, count);
    if (lines != nullptr) delete[] lines;
    return res;
}
//ф-я меню изменений в файлах
void refresh() {
    int k;
    system("cls");
    while (true) {
        //system("cls");
        cout << endl;
        cout << "+-------------------------------------+" << endl;
        cout << "|               Функции               |" << endl;
        cout << "|-------------------------------------|" << endl;
        cout << "|  1)  Добавить исполнителя           |" << endl;
        cout << "|  2)  Удалить исполнителя из списка  |" << endl;
        cout << "|  3)  Очистить файл с альбомами      |" << endl;
        cout << "|  4)  Очистить файл с песнями        |" << endl;
        cout << "|  5)  Очистить файл с исполнителями  |" << endl;
        cout << "|  6)  Очистить файл об исполнителе   |" << endl;
        cout << "|  7)  Редактировать имя исполнителя  |" << endl;
        cout << "|  8)  Сортировка исполнителей        |" << endl;
        cout << "|  9)  Сортировка песен в альбоме     |" << endl;
        cout << "|  0)  Выход в главное меню           |" << endl;
        cout << "+-------------------------------------+" << endl << endl << "Выберите действие. Ввод: ";
        cin >> k;
        if (k == 0) break;
        if (k == 1) { system("cls"); insert(); system("cls"); cout << "Новый исполнитель успешно добавлен!" << endl; }
        if (k == 2) { system("cls"); delete_singer(); system("cls"); cout << "Исполнитель успешно удален!" << endl; }
        if (k == 3) { system("cls");  clean_album(); system("cls"); cout << "Очищено!" << endl; }
        if (k == 4) { system("cls"); clean_songs(); system("cls"); cout << "Очищено!" << endl;}
        if (k == 5) { system("cls"); clean_list(); system("cls"); cout << "Очищено!" << endl;}
        if (k == 6) { system("cls"); clean_about(); system("cls"); cout << "Очищено!" << endl;}
        if (k == 7) { system("cls"); edit_singer(); system("cls"); cout << "Имя исполнителя отредактировано!" << endl;}
        if (k == 8) { system("cls"); string filename = "List.txt"; SortStringsInFile(filename);  system("cls"); cout << "Отсортировано!" << endl;}
        if (k == 9) {
            system("cls");
            string f; cout << "Введите название альбома (пробелы заменяйте на '_'): ";
            cin >> f; string filename = f+".txt";
            SortStringsInFile(filename); system("cls"); cout << "Отсортировано!" << endl; 
        }
    }
    cout << endl;
}
//главная ф-я с основным меню пользователя + сохранение в файл времени запуска приложения
int main(){
    setlocale(LC_ALL, "Russian"); SetConsoleCP(1251); SetConsoleOutputCP(1251);
    system("color f4");
    time_t t = time(0); 
    struct tm* now = localtime(&t);
    ofstream file;
    file.open("time.txt", ios::app);
    if (!file.is_open()) printf("Не удалось открыть файл.");
    else{  file << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-' << now->tm_mday << "  " << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec << endl;}
    file.close();
    int k;
    while (true) {       
        cout << endl;
        cout << "+-------------------------------------+ " << endl;
        cout << "|            Главное меню             |" << endl;
        cout << "|-------------------------------------|" << endl;
        cout << "|  1)  Меню исполнителей              |" << endl;
        cout << "|  2)  Советы по выбору исполнителей  |" << endl;
        cout << "|  3)  Панель мастера обновления ПО   |" << endl;
        cout << "|  4)  Информация о программе         |" << endl;
        cout << "|  0)  Выход из программы             |" << endl;
        cout << "+-------------------------------------+" << endl << endl << "Выберите действие. Ввод: ";
        cin >> k;
        if (k == 0) break;
        if (k == 1) singers();
        if (k == 2) advice(k);
        if (k == 3) refresh();
        if (k == 4) about(k);
        system("cls");
    }
    cout << endl;
    system("pause");
    return 0; 
}