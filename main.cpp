#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

string melangerLettres(string mot) {
    string melange;
    int position(0);
    while (mot.length() != 0) {
        position = rand() % mot.size();
        melange += mot[position];
        mot.erase(position, 1);
    }
    return (string) melange;
}

string getLettreDectionnaire(int deficlty) {
    string aleatoirMot;
    int positionMot(0);
    ifstream file;
    file.open("dicton.txt");
    string str;
    int maxLine(323577);
    int count(0);
    srand(time(NULL));
    positionMot = rand() % maxLine;
    while (std::getline(file, str) && count <= positionMot) {
        switch (deficlty) {
            case 1: {
                if (str.length() <= 4) {

                    aleatoirMot = str.substr(0, str.length() - 1);
                }
                break;
            }
            case 2: {
                if (str.length() <= 4) {

                    aleatoirMot = str.substr(0, str.length() - 1);
                }
                break;
            }
            case 3: {
                if (str.length() <= 5) {

                    aleatoirMot = str.substr(0, str.length() - 1);
                }
                break;
            }
            case 4: {
                if (str.length() <= 7) {

                    aleatoirMot = str.substr(0, str.length() - 1);
                }
                break;
            }
            default: {
                if (str.length() > 6 && count <= positionMot) {
                    aleatoirMot = str.substr(0, str.length() - 1);
                }
                break;
            }
        }
        count++;
    }
    return aleatoirMot;
}

int main() {
    string motMystere, motMelange, motUtilisateur;
    char rejouer[1] = {'o'};
    //Initialisation des nombres aléatoires
    srand(time(0));
    int jouerAvecQui(1);
    int nombreDuJeu(1);
    int totalResulat(0);

    do {
        int count(5);
        cout << "*********** regle du jeu *************** \n" << endl;
        cout << "1--> vous utilisateur vas etre enter un mot." << endl;
        cout << "2--> le nombre maximal de coups  est 5." << endl;
        cout << "************************** \n" << endl;
        cout << "1--> jouer avec le robot      2--> jouer avec un ami" << endl;
        cin >> jouerAvecQui;

        //1 : On demande de saisir un mot
        switch (jouerAvecQui) {
            case 1: {
                motMystere = getLettreDectionnaire(nombreDuJeu);

                ++nombreDuJeu;
                break;
            }
            case 2: {
                cout << "Saisissez un mot" << endl;
                cin >> motMystere;
                break;
            }

        }
        do {
            count -= 1;
            motMelange = melangerLettres(motMystere);
            cout << "Quel est ce mot ?  " << motMelange << endl;
            cin >> motUtilisateur;
            if (motUtilisateur == motMystere) {
                totalResulat += 10;
                cout << "Bravo ! vous avez +  " << totalResulat << " points" << endl;
            } else {

                if (count > 0) {
                    cout << "\nCe n'est pas le mot !\n" << endl;
                    cout << "vous reste " << count << " essais !" << endl;
                } else {
                    cout << "\nvous etes perdu :(\n" << endl;
                }
            }
        } while (motUtilisateur != motMystere && count > 0);

        cout << " voutre resultat total est : " << totalResulat << " points" << endl;

        cout << "vous volez rejouer o/n : " << endl;
        cin >> rejouer[0];
    } while (rejouer[0] == 'o' || rejouer[0] == 'O');
    cout << "vous etes quiter le jeu :(" << endl;
    return 0;
}