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

void printMap(vector<vector<char>> &map, int px, int py) {

    cout << "\nDungeon Map\n";

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {

            if (i == px && j == py)
                cout << "P ";
            else
                cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    srand(time(0));   // random seed

    vector<vector<char>> map = {
        {'.','.','T','.'},
        {'.','.','.','.'},
        {'.','.','X','.'},
        {'.','.','.','O'}
    };

    // Random enemy spawn
    int ex = rand() % 4;
    int ey = rand() % 4;

    while(map[ex][ey] != '.') {
        ex = rand() % 4;
        ey = rand() % 4;
    }

    map[ex][ey] = 'E';

    Player player;

    int x = 0;
    int y = 0;

    char move;

    cout << "===== Dungeon Escape Game =====\n";
    cout << "Reach the exit (O) to win!\n\n";

    cout << "Map Symbols:\n";
    cout << "P = Player\n";
    cout << "E = Enemy\n";
    cout << "T = Treasure\n";
    cout << "X = Trap\n";
    cout << "O = Exit\n";
    cout << ". = Empty Path\n\n";

    cout << "Controls:\n";
    cout << "W = Move Up\n";
    cout << "S = Move Down\n";
    cout << "A = Move Left\n";
    cout << "D = Move Right\n\n";

    while (true) {

        printMap(map, x, y);

        cout << "\nHealth: " << player.getHealth();
        cout << "\nScore: " << player.getScore() << endl;

        cout << "\nMove (W/A/S/D): ";
        cin >> move;

        int nx = x;
        int ny = y;

        if (move == 'w') nx--;
        else if (move == 's') nx++;
        else if (move == 'a') ny--;
        else if (move == 'd') ny++;

        if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) {
            cout << "You hit a wall!\n";
            continue;
        }

        x = nx;
        y = ny;

        char event = map[x][y];

        if (event == 'T') {
            cout << "You found treasure! +20 score\n";
            player.addScore(20);
            map[x][y] = '.';
        }

        else if (event == 'X') {
            cout << "You stepped on a trap! -20 health\n";
            player.takeDamage(20);
            map[x][y] = '.';
        }

        else if (event == 'E') {

            Enemy enemy;

            cout << "\nEnemy appeared!\n";

            while (enemy.isAlive() && player.isAlive()) {

                int choice;

                cout << "\n1. Attack\n";
                cout << "2. Run\n";
                cout << "Choose: ";
                cin >> choice;

                if (choice == 1) {

                    enemy.takeDamage(player.getAttack());
                    cout << "You hit the enemy!\n";

                    if (enemy.isAlive()) {
                        player.takeDamage(enemy.getAttack());
                        cout << "Enemy attacked you!\n";
                    }

                }

                else if (choice == 2) {

                    if (rand() % 2 == 0) {
                        cout << "You escaped successfully!\n";
                        break;
                    }
                    else {
                        cout << "Escape failed! Enemy attacked!\n";
                        player.takeDamage(enemy.getAttack());
                    }

                }

            }

            if (!player.isAlive()) {
                cout << "\nYou died! Game Over\n";
                break;
            }

            if (!enemy.isAlive()) {
                cout << "Enemy defeated! +30 score\n";
                player.addScore(30);
                map[x][y] = '.';
            }

        }

        else if (event == 'O') {
            cout << "\nYou found the exit!\n";
            cout << "You escaped the dungeon!\n";
            player.addScore(50);
            break;
        }

        if (!player.isAlive()) {
            cout << "\nYou died in the dungeon!\n";
            break;
        }
    }

    cout << "\nFinal Score: " << player.getScore() << endl;

    return 0;
}