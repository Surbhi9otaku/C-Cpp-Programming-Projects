#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Question {
private:
    string questionText;
    string options[4];
    int correctAnswer;

public:
    Question(string q, string opt[], int ans) {
        questionText = q;
        for (int i = 0; i < 4; i++) {
            options[i] = opt[i];
        }
        correctAnswer = ans;
    }

    void displayQuestion() {
        cout << questionText << endl;
        for (int i = 0; i < 4; i++) {
            cout << i + 1 << "." << options[i] << endl;
        }
    }

    bool checkAnswer(int userChoice) {
        return userChoice == correctAnswer;
    }
};

int main() {

    cout << "==================================\n";
    cout << "   Welcome to Surbhi9otaku Quiz\n";
    cout << "   Test Your Anime Knowledge!\n";
    cout << "==================================\n\n";

    string username;
    cout << "Enter your name: ";
    getline(cin, username);
    cout << "\nWelcome, " << username << "! Let's start the quiz.\n\n";

    // Create questions

    return 0;
}