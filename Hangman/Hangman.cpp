#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;


// функция выбора режима игры
int InputMode()
{
    int mode;

    while (true)
    {
        cout << "Введите количество игроков (1 / 2):" << endl;
        cin >> mode;

        if (mode == 1 || mode == 2)
        {
            cout << endl;
            break;
        }
        else
            cout << "Ошибка! Введите соответствующую цифру" << endl << endl;
    }

    return mode;
}

// функция выбора сложности
int InputDifficulty()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int dif;

    while (true)
    {
        cout << "Выберите сложность игры (1 / 2 / 3):" << endl;
        SetConsoleTextAttribute(hConsole, 2);
        cout << "1 - Легкая (9 ошибок)";
        SetConsoleTextAttribute(hConsole, 7);
        cout << " / ";
        SetConsoleTextAttribute(hConsole, 6);
        cout << "2 - Средняя (6 ошибок)";
        SetConsoleTextAttribute(hConsole, 7);
        cout << " / ";
        SetConsoleTextAttribute(hConsole, 4);
        cout << "3 - Сложная (3 ошибки)" << endl;
        SetConsoleTextAttribute(hConsole, 7);
        cin >> dif;

        if (dif == 1 || dif == 2 || dif == 3)
        {
            if (dif == 1)
                dif = 9;
            if (dif == 2)
                dif = 6;
            cout << endl;
            break;
        }
        else
            cout << "Ошибка! Введите соответствующую цифру" << endl << endl;
    }

    return dif;
}

// функция выбора темы
int InputTheme()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int theme;

    while (true)
    {
        cout << "Выберите тему (1 / 2 / 3 / 4 / 5):" << endl;
        SetConsoleTextAttribute(hConsole, 1);
        cout << "1 - Наука";
        SetConsoleTextAttribute(hConsole, 7);
        cout << " / ";
        SetConsoleTextAttribute(hConsole, 3);
        cout << "2 - Спорт";
        SetConsoleTextAttribute(hConsole, 7);
        cout << " / ";
        SetConsoleTextAttribute(hConsole, 1);
        cout << "3 - География";
        SetConsoleTextAttribute(hConsole, 7);
        cout << " / ";
        SetConsoleTextAttribute(hConsole, 3);
        cout << "4 - Фауна";
        SetConsoleTextAttribute(hConsole, 7);
        cout << " / ";
        SetConsoleTextAttribute(hConsole, 1);
        cout << "5 - Флора" << endl;
        SetConsoleTextAttribute(hConsole, 7);
        cin >> theme;

        if (theme == 0 || theme == 1 || theme == 2 || theme == 3 || theme == 4 || theme == 5)
        {
            cout << endl;
            break;
        }
        else
            cout << "Ошибка! Введите соответствующую цифру" << endl << endl;
    }

    return theme;
}

// функция извлечения рандомного слова из файла
vector <char> FileWord(string filename)
{
    vector <string> words;
    ifstream file(filename);
    string line;

    while (getline(file, line))
        words.push_back(line);

    srand(time(nullptr));
    int ind = rand() % words.size();
    string randword = words[ind];

    vector <char> arrword;
    for (char let : randword)
        arrword.push_back(let);

    return arrword;
}

// функция ввода слова
vector <char> InputWord()
{
    cout << "Загадайте слово (без пробелов):" << endl;
    string inword;
    cin >> inword;

    vector <char> arrword;
    for (char let : inword)
        arrword.push_back(let);

    return arrword;
}

// функция вывода схематического рисунка
void PrintHungman(int difficulty, int wrongs)
{
    if (difficulty == 9)
    {
        if (wrongs == 0)
        {
            cout << " --------------------" << endl << "|                    |" << endl;
            cout << "|                    |" << endl << "|                    |" << endl;
            cout << "|                    |" << endl << "|                    |" << endl;
            cout << "|                    |" << endl << "|                    |" << endl;
            cout << "|                    |" << endl << " --------------------" << endl << endl;
        }
        if (wrongs == 1)
        {
            cout << " --------------------" << endl << "|                    |" << endl;
            cout << "|                    |" << endl << "|                    |" << endl;
            cout << "|                    |" << endl << "|                    |" << endl;
            cout << "|                    |" << endl << "|                    |" << endl;
            cout << "|  -----             |" << endl << " --------------------" << endl << endl;
        }
        if (wrongs == 2)
        {
            cout << " --------------------" << endl << "|                    |" << endl;
            cout << "|                    |" << endl << "|                    |" << endl;
            cout << "|                    |" << endl << "|    |               |" << endl;
            cout << "|    |               |" << endl << "|    |               |" << endl;
            cout << "|  -----             |" << endl << " --------------------" << endl << endl;
        }
        if (wrongs == 3)
        {
            cout << " --------------------" << endl << "|                    |" << endl;
            cout << "|    |               |" << endl << "|    |               |" << endl;
            cout << "|    |               |" << endl << "|    |               |" << endl;
            cout << "|    |               |" << endl << "|    |               |" << endl;
            cout << "|  -----             |" << endl << " --------------------" << endl << endl;
        }
        if (wrongs == 4)
        {
            cout << " --------------------" << endl << "|                    |" << endl;
            cout << "|    |--------       |" << endl << "|    |               |" << endl;
            cout << "|    |               |" << endl << "|    |               |" << endl;
            cout << "|    |               |" << endl << "|    |               |" << endl;
            cout << "|  -----             |" << endl << " --------------------" << endl << endl;
        }
        if (wrongs == 5)
        {
            cout << " --------------------" << endl << "|                    |" << endl;
            cout << "|    |-------|       |" << endl << "|    |       |       |" << endl;
            cout << "|    |               |" << endl << "|    |               |" << endl;
            cout << "|    |               |" << endl << "|    |               |" << endl;
            cout << "|  -----             |" << endl << " --------------------" << endl << endl;
        }
        if (wrongs == 6)
        {
            cout << " --------------------" << endl << "|                    |" << endl;
            cout << "|    |-------|       |" << endl << "|    |       |       |" << endl;
            cout << "|    |       0       |" << endl << "|    |               |" << endl;
            cout << "|    |               |" << endl << "|    |               |" << endl;
            cout << "|  -----             |" << endl << " --------------------" << endl << endl;
        }
        if (wrongs == 7)
        {
            cout << " --------------------" << endl << "|                    |" << endl;
            cout << "|    |-------|       |" << endl << "|    |       |       |" << endl;
            cout << "|    |       0       |" << endl << "|    |      {|}      |" << endl;
            cout << "|    |               |" << endl << "|    |               |" << endl;
            cout << "|  -----             |" << endl << " --------------------" << endl << endl;
        }
        if (wrongs == 8)
        {
            cout << " --------------------" << endl << "|                    |" << endl;
            cout << "|    |-------|       |" << endl << "|    |       |       |" << endl;
            cout << "|    |       0       |" << endl << "|    |     \\{|}/     |" << endl;
            cout << "|    |               |" << endl << "|    |               |" << endl;
            cout << "|  -----             |" << endl << " --------------------" << endl << endl;
        }
        if (wrongs == 9)
        {
            cout << " --------------------" << endl << "|                    |" << endl;
            cout << "|    |-------|       |" << endl << "|    |       |       |" << endl;
            cout << "|    |       0       |" << endl << "|    |     \\{|}/     |" << endl;
            cout << "|    |       |       |" << endl << "|    |               |" << endl;
            cout << "|  -----             |" << endl << " --------------------" << endl << endl;
        }
    }

    if (difficulty == 6)
    {
        if (wrongs == 0)
        {
            cout << " --------------------" << endl << "|                    |" << endl;
            cout << "|                    |" << endl << "|                    |" << endl;
            cout << "|                    |" << endl << "|                    |" << endl;
            cout << "|                    |" << endl << "|                    |" << endl;
            cout << "|                    |" << endl << " --------------------" << endl << endl;
        }
        if (wrongs == 1)
        {
            cout << " --------------------" << endl << "|                    |" << endl;
            cout << "|    |               |" << endl << "|    |               |" << endl;
            cout << "|    |               |" << endl << "|    |               |" << endl;
            cout << "|    |               |" << endl << "|    |               |" << endl;
            cout << "|  -----             |" << endl << " --------------------" << endl << endl;
        }
        if (wrongs == 2)
        {
            cout << " --------------------" << endl << "|                    |" << endl;
            cout << "|    |--------       |" << endl << "|    |               |" << endl;
            cout << "|    |               |" << endl << "|    |               |" << endl;
            cout << "|    |               |" << endl << "|    |               |" << endl;
            cout << "|  -----             |" << endl << " --------------------" << endl << endl;
        }
        if (wrongs == 3)
        {
            cout << " --------------------" << endl << "|                    |" << endl;
            cout << "|    |-------|       |" << endl << "|    |       |       |" << endl;
            cout << "|    |               |" << endl << "|    |               |" << endl;
            cout << "|    |               |" << endl << "|    |               |" << endl;
            cout << "|  -----             |" << endl << " --------------------" << endl << endl;
        }
        if (wrongs == 4)
        {
            cout << " --------------------" << endl << "|                    |" << endl;
            cout << "|    |-------|       |" << endl << "|    |       |       |" << endl;
            cout << "|    |       0       |" << endl << "|    |               |" << endl;
            cout << "|    |               |" << endl << "|    |               |" << endl;
            cout << "|  -----             |" << endl << " --------------------" << endl << endl;
        }
        if (wrongs == 5)
        {
            cout << " --------------------" << endl << "|                    |" << endl;
            cout << "|    |-------|       |" << endl << "|    |       |       |" << endl;
            cout << "|    |       0       |" << endl << "|    |     \\{|}/     |" << endl;
            cout << "|    |               |" << endl << "|    |               |" << endl;
            cout << "|  -----             |" << endl << " --------------------" << endl << endl;
        }
        if (wrongs == 6)
        {
            cout << " --------------------" << endl << "|                    |" << endl;
            cout << "|    |-------|       |" << endl << "|    |       |       |" << endl;
            cout << "|    |       0       |" << endl << "|    |     \\{|}/     |" << endl;
            cout << "|    |       |       |" << endl << "|    |               |" << endl;
            cout << "|  -----             |" << endl << " --------------------" << endl << endl;
        }
    }

    if (difficulty == 3)
    {
        if (wrongs == 0)
        {
            cout << " --------------------" << endl << "|                    |" << endl;
            cout << "|                    |" << endl << "|                    |" << endl;
            cout << "|                    |" << endl << "|                    |" << endl;
            cout << "|                    |" << endl << "|                    |" << endl;
            cout << "|                    |" << endl << " --------------------" << endl << endl;
        }
        if (wrongs == 1)
        {
            cout << " --------------------" << endl << "|                    |" << endl;
            cout << "|    |--------       |" << endl << "|    |               |" << endl;
            cout << "|    |               |" << endl << "|    |               |" << endl;
            cout << "|    |               |" << endl << "|    |               |" << endl;
            cout << "|  -----             |" << endl << " --------------------" << endl << endl;
        }
        if (wrongs == 2)
        {
            cout << " --------------------" << endl << "|                    |" << endl;
            cout << "|    |-------|       |" << endl << "|    |       |       |" << endl;
            cout << "|    |       0       |" << endl << "|    |               |" << endl;
            cout << "|    |               |" << endl << "|    |               |" << endl;
            cout << "|  -----             |" << endl << " --------------------" << endl << endl;
        }
        if (wrongs == 3)
        {
            cout << " --------------------" << endl << "|                    |" << endl;
            cout << "|    |-------|       |" << endl << "|    |       |       |" << endl;
            cout << "|    |       0       |" << endl << "|    |     \\{|}/     |" << endl;
            cout << "|    |               |" << endl << "|    |               |" << endl;
            cout << "|  -----             |" << endl << " --------------------" << endl << endl;
        }
    }
}

// функция вывода короны
void PrintCrown()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 6);
    cout << "         (";
    SetConsoleTextAttribute(hConsole, 4);
    cout << "*";
    SetConsoleTextAttribute(hConsole, 6);
    cout << ")" << endl;
    cout << "|)       / \\       (|" << endl;
    cout << "|\\      /   \\      /|" << endl;
    cout << "| \\    /     \\    / |" << endl;
    cout << "| |    |     |    | |" << endl;
    cout << "|  \\  /  ";
    SetConsoleTextAttribute(hConsole, 4);
    cout << "/-\\";
    SetConsoleTextAttribute(hConsole, 6);
    cout << "  \\  /  |" << endl;
    cout << " \\  \\/  ";
    SetConsoleTextAttribute(hConsole, 4);
    cout << "| ";
    SetConsoleTextAttribute(hConsole, 10);
    cout << "*";
    SetConsoleTextAttribute(hConsole, 4);
    cout << " |";
    SetConsoleTextAttribute(hConsole, 6);
    cout << "  \\/  /" << endl;
    cout << " |       ";
    SetConsoleTextAttribute(hConsole, 4);
    cout << "\\-/";
    SetConsoleTextAttribute(hConsole, 6);
    cout << "       |" << endl;
    cout << " /                 \\" << endl;
    cout << "| ";
    SetConsoleTextAttribute(hConsole, 4);
    cout << "o";
    SetConsoleTextAttribute(hConsole, 10);
    cout << " 0 ";
    SetConsoleTextAttribute(hConsole, 4);
    cout << "o";
    SetConsoleTextAttribute(hConsole, 10);
    cout << " 0 ";
    SetConsoleTextAttribute(hConsole, 4);
    cout << "o";
    SetConsoleTextAttribute(hConsole, 10);
    cout << " 0 ";
    SetConsoleTextAttribute(hConsole, 4);
    cout << "o";
    SetConsoleTextAttribute(hConsole, 10);
    cout << " 0 ";
    SetConsoleTextAttribute(hConsole, 4);
    cout << "o";
    SetConsoleTextAttribute(hConsole, 6);
    cout << " |" << endl;
    cout << "---------------------" << endl << endl;
}

// функция вывода подсказки
void PrintPrompt(int theme, int mode, string clue)
{
    if (mode == 1)
    {
        if (theme == 0)
            cout << "Music Artists" << endl << endl;
        if (theme == 1)
            cout << "Science" << endl << endl;
        if (theme == 2)
            cout << "Sport" << endl << endl;
        if (theme == 3)
            cout << "Geography" << endl << endl;
        if (theme == 4)
            cout << "Fauna" << endl << endl;
        if (theme == 5)
            cout << "Flora" << endl << endl;
    }
    else
        cout << clue << endl << endl;
}

// функция вывода прогресса
void PrintProgress(vector<char> progress, int attemps, int mode, int theme, string clue)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (attemps == 0)
    {
        if (theme == 0)
            PrintCrown();

        SetConsoleTextAttribute(hConsole, 7);
        cout << "Тема загаданного слова: " << endl;
        SetConsoleTextAttribute(hConsole, 3);
        PrintPrompt(theme, mode, clue);
        SetConsoleTextAttribute(hConsole, 7);
    }

    cout << "На данный момент слово выглядит так: " << endl;
    SetConsoleTextAttribute(hConsole, 11);
    cout << "[ ";
    for (char let : progress)
        cout << let << " ";
    cout << "]" << endl << endl;
}

// функция вывода использованных букв
void PrintUsed(vector<char> used)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << "Использованные буквы: " << endl;
    SetConsoleTextAttribute(hConsole, 14);
    cout << "[ ";
    for (char let : used)
        cout << char(let - 32) << " ";
    cout << "]" << endl << endl;
}

// основная функция поиска буквы в слове
void Search(vector<char> word, vector<char>& progress, vector<char>& used,
    int& attemps, int& wrongs, int& unsolved, int difficulty, int mode, int theme, string clue)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 7);
    cout << "=========================================" << endl << endl;

    PrintHungman(difficulty, wrongs);
    SetConsoleTextAttribute(hConsole, 6);
    cout << "Осталось ошибочных попыток: " << difficulty - wrongs << endl << endl;

    // ввод буквы
    SetConsoleTextAttribute(hConsole, 7);
    cout << "Введите букву (или несколько букв сразу): " << endl;
    char att;
    cin >> att;

    // неучет регистра
    char attreg;
    if ((att >= 'A' && att <= 'Z') || (att >= 'А' && att <= 'Я'))
        attreg = att + 32;
    else
        attreg = att;

    // проверка на повтор
    for (char let : used)
    {
        if (let == attreg)
        {
            SetConsoleTextAttribute(hConsole, 5);
            cout << "Буква <" << att << "> уже была введена" << endl << endl;

            SetConsoleTextAttribute(hConsole, 7);
            PrintProgress(progress, attemps, mode, theme, clue);

            SetConsoleTextAttribute(hConsole, 7);
            PrintUsed(used);

            return;
        }
    }

    attemps++;
    used.push_back(attreg); // добавление буквы в массив использованых букв

    // поиск в слове
    bool found = false;
    for (int ind = 0; ind < size(word); ind++)
    {
        // учет регистра
        char wordreg;
        if ((word[ind] >= 'A' && word[ind] <= 'Z') || (word[ind] >= 'А' && word[ind] <= 'Я'))
            wordreg = word[ind] + 32;
        else
            wordreg = word[ind];

        if (attreg == wordreg)
        {
            progress[ind] = word[ind];
            found = true;
            unsolved--;
        }
    }

    // если слово отгадано
    if (unsolved == 0)
    {
        SetConsoleTextAttribute(hConsole, 2);
        cout << "Буква <" << att << "> есть в слове" << endl << endl;

        SetConsoleTextAttribute(hConsole, 7);
        PrintProgress(progress, attemps, mode, theme, clue);

        SetConsoleTextAttribute(hConsole, 7);
        cout << "=========================================" << endl << endl << endl;

        SetConsoleTextAttribute(hConsole, 2);
        cout << "ПОЗДРАВЛЯЕМ! ВЫ ОТГАДАЛИ СЛОВО ;)" << endl << endl;

        return;
    }

    // если буква в слове
    if (found)
    {
        SetConsoleTextAttribute(hConsole, 2);
        cout << "Буква <" << att << "> есть в слове" << endl << endl;

        SetConsoleTextAttribute(hConsole, 7);
        PrintProgress(progress, attemps, mode, theme, clue);

        SetConsoleTextAttribute(hConsole, 7);
        PrintUsed(used);
    }

    // если ошибочные попытки кончились
    else if (wrongs == difficulty)
    {
        wrongs++;

        SetConsoleTextAttribute(hConsole, 4);
        cout << "Буква <" << att << "> в слове отсутствует" << endl << endl;

        SetConsoleTextAttribute(hConsole, 7);
        PrintProgress(progress, attemps, mode, theme, clue);

        SetConsoleTextAttribute(hConsole, 7);
        cout << "=========================================" << endl << endl << endl;

        SetConsoleTextAttribute(hConsole, 4);
        cout << "ПОПЫТКИ КОНЧИЛИСЬ! СЛОВО НЕ ОТГАДАНО ;(" << endl << endl;

        return;
    }

    // если буквы нет в слове
    else
    {
        wrongs++;

        SetConsoleTextAttribute(hConsole, 4);
        cout << "Буква <" << att << "> в слове отсутствует" << endl << endl;

        SetConsoleTextAttribute(hConsole, 7);
        PrintProgress(progress, attemps, mode, theme, clue);

        SetConsoleTextAttribute(hConsole, 7);
        PrintUsed(used);
    }
}

// функция вывода ачивок
void PrintAchievments(int wrongs, int difficulty, int theme)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (theme == 0)
    {
        SetConsoleTextAttribute(hConsole, 13);
        cout << "!!! Выполнена ачивка <Кроличья нора> !!!" << endl << "(Догадаться найти супер-секретный режим)" << endl << endl;
    }
    if (wrongs == 0)
    {
        SetConsoleTextAttribute(hConsole, 14);
        cout << "!!! Выполнена ачивка <Целочка> !!!" << endl << "(Отгадать слово без единой ошибки)" << endl << endl;
    }
    if ((difficulty == 9 && wrongs == 9) || (difficulty == 6 && wrongs == 6) || (difficulty == 3 && wrongs == 3))
    {
        SetConsoleTextAttribute(hConsole, 14);
        cout << "!!!  Выполнена ачивка <Ювелир>  !!!" << endl << "(Отгадать слово в последний момент)" << endl << endl;
    }
}

int main()
{
    // установка цвета и кодировки
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // приветствие
    SetConsoleTextAttribute(hConsole, 11);
    cout << "!!! ДОБРО ПОЖАЛОВАТЬ В КОНСОЛЬНУЮ ИГРУ <ВИСЕЛИЦА> !!!" << endl << endl << endl;
    SetConsoleTextAttribute(hConsole, 7);

    // режим игры
    int mode;
    mode = InputMode();

    // сложность игры
    int difficulty;
    difficulty = InputDifficulty();

    // тема игры
    int theme = -1;

    // подсказка для режима двоих
    string clue = " ";

    // генерация слова
    vector <char> word;
    if (mode == 1)
    {
        theme = InputTheme();

        if (theme == 0)
            word = FileWord("Secret.txt");
        if (theme == 1)
            word = FileWord("Science.txt");
        if (theme == 2)
            word = FileWord("Sport.txt");
        if (theme == 3)
            word = FileWord("Geography.txt");
        if (theme == 4)
            word = FileWord("Fauna.txt");
        if (theme == 5)
            word = FileWord("Flora.txt");
    }
    else
    {
        word = InputWord();

        cout << endl << "Укажите тему загаданного Вами слова (без пробелов):" << endl;
        cin >> clue;
    }
  
    system("cls"); // очистка консоли

    // создание массива прогресса
    vector <char> progress;
    for (char let : word)
        progress.push_back('*');

    int attemps = 0; // попытки
    PrintProgress(progress, attemps, mode, theme, clue);

    vector <char> used; // использованные буквы
    int wrongs = 0; // ошибки
    int unsolved = size(progress); // неразгаданные буквы

    // начало отгадывания
    while (wrongs <= difficulty && unsolved > 0)
        Search(word, progress, used, attemps, wrongs, unsolved, difficulty, mode, theme, clue);

    // вывод итогов игры
    if ((difficulty == 9 && wrongs == 10) || (difficulty == 6 && wrongs == 7) || (difficulty == 3 && wrongs == 4))
    {
        SetConsoleTextAttribute(hConsole, 12);

        cout << " --------------------" << endl << "|                    |" << endl;
        cout << "|    |-------|       |" << endl << "|    |       |       |" << endl;
        cout << "|    |       0       |" << endl << "|    |     \\{|}/     |" << endl;
        cout << "|    |       |       |" << endl << "|    |      / \\      |" << endl;
        cout << "|  -----             |" << endl << " --------------------" << endl << endl;
    }

    SetConsoleTextAttribute(hConsole, 7);
    cout << "Загаданное слово: ";
    SetConsoleTextAttribute(hConsole, 11);
    for (char let : word)
        cout << let;
    cout << endl;

    SetConsoleTextAttribute(hConsole, 7);
    cout << "Было потрачено попыток: ";
    SetConsoleTextAttribute(hConsole, 6);
    cout << attemps << endl << endl;

    SetConsoleTextAttribute(hConsole, 7);
    PrintAchievments(wrongs, difficulty, theme);

    SetConsoleTextAttribute(hConsole, 7);
    cout << endl << "=========================================" << endl;
    SetConsoleTextAttribute(hConsole, 0);

    return 0;
}
