#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Character {
protected:
    int health;
    int attack;

public:
    Character(int h, int a) {
        health = h;
        attack = a;
    }

    int getHealth() {
        return health;
    }

    int getAttack() {
        return attack;
    }

    void takeDamage(int dmg) {
        health -= dmg;
    }

    bool isAlive() {
        return health > 0;
    }
};

class Player : public Character {
private:
    int score;

public:
    Player() : Character(100, 20) {
        score = 0;
    }

    void addScore(int s) {
        score += s;
    }

    int getScore() {
        return score;
    }
};

class Enemy : public Character {
public:
    Enemy() : Character(40, 15) {}
};

void printMap(vector<vector<char>> &map, int x1, int y1, int x2, int y2) {

    cout << "\nDungeon Map\n";

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {

            if (i == x1 && j == y1)
                cout << "1 ";
            else if (i == x2 && j == y2)
                cout << "2 ";
            else
                cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    srand(time(0));

    vector<vector<char>> map = {
        {'.','.','T','.'},
        {'.','.','.','.'},
        {'.','.','X','.'},
        {'.','.','.','O'}
    };

    // Random Enemy (2 enemies for fun)
    for (int i = 0; i < 2; i++) {
        int ex = rand() % 4;
        int ey = rand() % 4;

        while (map[ex][ey] != '.') {
            ex = rand() % 4;
            ey = rand() % 4;
        }

        map[ex][ey] = 'E';
    }

    Player player1, player2;

    // Random player spawn
    int x1 = rand() % 4, y1 = rand() % 4;
    while (map[x1][y1] != '.') {
        x1 = rand() % 4;
        y1 = rand() % 4;
    }

    int x2 = rand() % 4, y2 = rand() % 4;
    while (map[x2][y2] != '.' || (x1 == x2 && y1 == y2)) {
        x2 = rand() % 4;
        y2 = rand() % 4;
    }

    // Random first turn
    bool isPlayer1Turn = rand() % 2;

    char move;

    cout << "===== Multiplayer Dungeon Escape =====\n";

    while (true) {

        printMap(map, x1, y1, x2, y2);

        Player* currentPlayer;
        int* cx;
        int* cy;

        if (isPlayer1Turn) {
            cout << "\n--- Player 1 Turn ---\n";
            currentPlayer = &player1;
            cx = &x1;
            cy = &y1;
        } else {
            cout << "\n--- Player 2 Turn ---\n";
            currentPlayer = &player2;
            cx = &x2;
            cy = &y2;
        }

        cout << "Health: " << currentPlayer->getHealth();
        cout << "\nScore: " << currentPlayer->getScore() << endl;

        cout << "Move (W/A/S/D): ";
        cin >> move;

        int nx = *cx;
        int ny = *cy;

        if (move == 'w') nx--;
        else if (move == 's') nx++;
        else if (move == 'a') ny--;
        else if (move == 'd') ny++;

        if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) {
            cout << "Wall hit!\n";
            continue;
        }

        *cx = nx;
        *cy = ny;

        char event = map[nx][ny];

        if (event == 'T') {
            cout << "Treasure found! +20\n";
            currentPlayer->addScore(20);
            map[nx][ny] = '.';
        }

        else if (event == 'X') {
            cout << "Trap! -20 health\n";
            currentPlayer->takeDamage(20);
            map[nx][ny] = '.';
        }

        else if (event == 'E') {

            Enemy enemy;
            cout << "\nEnemy Encounter!\n";

            while (enemy.isAlive() && currentPlayer->isAlive()) {

                int choice;
                cout << "1.Attack  2.Run : ";
                cin >> choice;

                if (choice == 1) {
                    enemy.takeDamage(currentPlayer->getAttack());
                    cout << "You attacked!\n";

                    if (enemy.isAlive()) {
                        currentPlayer->takeDamage(enemy.getAttack());
                        cout << "Enemy attacked back!\n";
                    }
                }

                else {
                    if (rand() % 2 == 0) {
                        cout << "Escaped!\n";
                        break;
                    } else {
                        cout << "Escape failed!\n";
                        currentPlayer->takeDamage(enemy.getAttack());
                    }
                }
            }

            if (!currentPlayer->isAlive()) {
                cout << "Player died!\n";
                break;
            }

            if (!enemy.isAlive()) {
                cout << "Enemy defeated! +30\n";
                currentPlayer->addScore(30);
                map[nx][ny] = '.';
            }
        }

        else if (event == 'O') {
            cout << "\nExit found!\n";
            currentPlayer->addScore(50);
            break;
        }

        if (!currentPlayer->isAlive()) {
            cout << "Game Over\n";
            break;
        }

        isPlayer1Turn = !isPlayer1Turn;
    }

    cout << "\nFinal Scores:\n";
    cout << "Player 1: " << player1.getScore() << endl;
    cout << "Player 2: " << player2.getScore() << endl;

    if (player1.getScore() > player2.getScore())
        cout << "Player 1 Wins!\n";
    else if (player2.getScore() > player1.getScore())
        cout << "Player 2 Wins!\n";
    else
        cout << "Draw!\n";

    return 0;
}