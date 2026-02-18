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

    string getCorrectOptionText() {
        return options[correctAnswer - 1];
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
    vector<Question> quizQuestions;

    //Easy
    string options1[4] = {"Satoru Gojo", "Megumi Fushiguro", "Yuji Itadori", "Nobara Kugisaki"};
    quizQuestions.push_back(Question("Jujutsu Kaisen: Who is known as the \"Strongest Jujutsu Sorcerer\"?", options1, 1));

    string options2[4] = {"Monkey D. Luffy", "Gol D. Roger", "Shanks", "Portgas D. Ace"};
    quizQuestions.push_back(Question("One Piece: What is the name of Luffy's signature straw hat's original owner?", options2, 2));

    string options3[4] = {"Telepathy", "Super Strength", "Time Travel", "Shapeshifting"};
    quizQuestions.push_back(Question("Spy x Family: What is Anya’s secret power?", options3, 1));

    //Medium
    string options4[4] = {"Naruto Uzumaki", "Sasuke Uchiha", "Kakashi Hatake", "Sakura Haruno"};
    quizQuestions.push_back(Question("Naruto: Who was the leader of Team 7 when Naruto, Sasuke, and Sakura first graduated?", options4, 3));

    string options5[4] = {"Ten, Zetsu, Ren, Hatsu", "Ren, Hatsu, Cursed Energy, Domain Expansion", "Ten, Zetsu, Mana, Ki", "Nen, Chakra, Reiatsu, Haki"};
    quizQuestions.push_back(Question("Hunter x Hunter: What are the four basic principles of Nen?", options5, 1));

    string options6[4] = {"Power", "Denji", "Pochita", "Makima"};
    quizQuestions.push_back(Question("Chainsaw Man: What is the name of the orange dog-like devil with a chainsaw on its head?", options6, 3));

    //Hard
    string options7[4] = {"Shiganshina", "Trost", "Wall Rose", "Liberio"};
    quizQuestions.push_back(Question("Attack on Titan: What was the name of the town where the Colossal Titan first breached Wall Maria?", options7, 1));

    string options8[4] = {"White", "Black", "Red", "Orange"};
    quizQuestions.push_back(Question("Bleach: What is the name of Ichigo’s Inner Hollow?", options8, 1));

    string options9[4] = {"Future Gadget #7", "Future Gadget #8", "Future Gadget #6", "Phone Microwave"};
    quizQuestions.push_back(Question("Steins;Gate: What is the \"Phone Microwave\" (the time machine) officially called by Okabe?", options9, 2));

    string options10[4] = {"Law of Transmutation", "Equivalent Exchange", "Human Sacrifice", "Philosopher’s Rule"};
    quizQuestions.push_back(Question("Fullmetal Alchemist: What is the principle that states \"In order to obtain something, something of equal value must be lost\"?", options10, 2));


    //Quiz logic
    int score = 0;
    int answer;

    for (int i = 0; i < quizQuestions.size(); i++) {
        cout << "\nQuestion " << i + 1 << ":\n";
        quizQuestions[i].displayQuestion();
        cout << "Enter your answer (1-4): ";
        cin >> answer;

        if (quizQuestions[i].checkAnswer(answer)) {
            cout << "Correct! \n";
            score += 10; //Each question = 10 points
        }
        else{
            cout << "Wrong!  The correct answer was: " << quizQuestions[i].getCorrectOptionText() << "\n";
        }
    }

    // Final score
    cout << "\n==================================\n";
    cout << "Quiz Completed!\n";
    cout << "Your final score is: " << score << " out of " << quizQuestions.size() * 10 << "\n";

    string rank;
    if (score <= 30) {
        rank = " Rookie";
    }
    else if (score <= 60) {
        rank = " Pro Fighter";
    }
    else if (score <= 90) {
        rank = " Elite Warrior";
    }
    else {
        rank = " Anime Overlord";
    }


    cout << "Your rank is: " << rank << "\n";
    cout << "Thank you for playing, " << username << "! Hope you had fun testing your anime knowledge! \n";

    return 0;
}
