#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

const int N = 5; // строки
const int M = 5; // столбцы

// Подсчёт коло-ва планет
int countPlanets(char sector[N][M]) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (sector[i][j] == 'O') count++;
        }
    }
    return count;
}

// Поиск ближайшей планеты к чёрной дыре
void findClosestPlanet(char sector[N][M]) {
    int blackX = -1, blackY = -1;
    // находим чёрную дыру
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (sector[i][j] == 'X') {
                blackX = i;
                blackY = j;
            }
        }
    }

    if (blackX == -1) {
        cout << "Чёрная дыра не найдена!" << endl;
        return;
    }

    double minDist = 1e9;
    int planetX = -1, planetY = -1;

    // ищем ближайшую планету
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (sector[i][j] == 'O') {
                double dist = sqrt(pow(i - blackX, 2) + pow(j - blackY, 2));
                if (dist < minDist) {
                    minDist = dist;
                    planetX = i;
                    planetY = j;
                }
            }
        }
    }

    if (planetX != -1) {
        cout << "Ближайшая планета к чёрной дыре находится в ("
            << planetX << ", " << planetY << ")" << endl;
        cout << "Расстояние: " << minDist << endl;
    }
    else {
        cout << "Планет не найдено!" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    char sector[N][M];

    // Генерация карты
    char symbols[3] = { '*', 'O', 'X' };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            sector[i][j] = symbols[rand() % 3];
        }
    }

    // Вывод карты
    cout << "Карта звездного сектора:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << sector[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nКоличество планет: " << countPlanets(sector) << endl;
    findClosestPlanet(sector);


    //ЭТО ВАРИАНТ КОДА ГДЕ МОЖНО САМОМУ ЗАДОВАТЬ РАЗМЕР КАРТЫ. ВАЖНО: НАДО ДОБАВИТЬ #include <vector>
    /*
     int N, M;
    cout << "Введите длину поля: ";
    cin >> N;
    cout << "Введите ширину поля: ";
    cin >> M;

    vector<vector<char>> sector(N, vector<char>(M));

    char symbols[3] = {'*', 'O', 'X'};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            sector[i][j] = symbols[rand() % 3];
        }
    }

    cout << "Карта звездного сектора:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << sector[i][j] << " ";
        }
        cout << endl;
    }
    */
    return 0;
}
