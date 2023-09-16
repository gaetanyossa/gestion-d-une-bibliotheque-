#include <iostream>
#include <string>

using namespace std;

// Structure pour représenter un livre
struct Livre {
    string titre;
    string auteur;
    bool emprunte;
};

const int MAX_LIVRES = 100;  // Maximum de livres dans la bibliothèque

// Fonction pour ajouter un livre à la bibliothèque
void ajouterLivre(Livre bibliothque[], int &nombreLivres) {
    if (nombreLivres < MAX_LIVRES) {
        Livre livre;
        cout << "Entrez le titre du livre : ";
        cin.ignore();
        getline(cin, livre.titre);
        cout << "Entrez le nom de l'auteur : ";
        getline(cin, livre.auteur);
        livre.emprunte = false;

        bibliothque[nombreLivres] = livre;
        nombreLivres++;

        cout << "Livre ajouté avec succès à la bibliothèque." << endl;
    } else {
        cout << "La bibliothèque est pleine. Impossible d'ajouter plus de livres." << endl;
    }
}

// Fonction pour afficher tous les livres dans la bibliothèque
void afficherLivres(const Livre bibliothque[], int nombreLivres) {
    if (nombreLivres > 0) {
        cout << "Liste des livres dans la bibliothèque : " << endl;
        for (int i = 0; i < nombreLivres; i++) {
            cout << "Titre : " << bibliothque[i].titre << endl;
            cout << "Auteur : " << bibliothque[i].auteur << endl;
            cout << "Emprunté : " << (bibliothque[i].emprunte ? "Oui" : "Non") << endl;
            cout << "--------------------" << endl;
        }
    } else {
        cout << "La bibliothèque est vide." << endl;
    }
}

// Fonction pour emprunter un livre
void emprunterLivre(Livre bibliothque[], int nombreLivres) {
    if (nombreLivres > 0) {
        string titre;
        cout << "Entrez le titre du livre à emprunter : ";
        cin.ignore();
        getline(cin, titre);

        for (int i = 0; i < nombreLivres; i++) {
            if (bibliothque[i].titre == titre && !bibliothque[i].emprunte) {
                bibliothque[i].emprunte = true;
                cout << "Le livre \"" << titre << "\" a été emprunté avec succès." << endl;
                return;
            }
        }
        cout << "Le livre \"" << titre << "\" n'est pas disponible pour l'emprunt ou n'existe pas." << endl;
    } else {
        cout << "La bibliothèque est vide." << endl;
    }
}

// Fonction pour retourner un livre
void retournerLivre(Livre bibliothque[], int nombreLivres) {
    if (nombreLivres > 0) {
        string titre;
        cout << "Entrez le titre du livre à retourner : ";
        cin.ignore();
        getline(cin, titre);

        for (int i = 0; i < nombreLivres; i++) {
            if (bibliothque[i].titre == titre && bibliothque[i].emprunte) {
                bibliothque[i].emprunte = false;
                cout << "Le livre \"" << titre << "\" a été retourné avec succès." << endl;
                return;
            }
        }
        cout << "Le livre \"" << titre << "\" n'a pas été trouvé ou n'a pas été emprunté." << endl;
    } else {
        cout << "La bibliothèque est vide." << endl;
    }
}

int main() {
    Livre bibliothque[MAX_LIVRES];
    int nombreLivres = 0;
    int choix;

    while (true) {
        cout << "Menu : " << endl;
        cout << "1. Ajouter un livre" << endl;
        cout << "2. Afficher la liste des livres" << endl;
        cout << "3. Emprunter un livre" << endl;
        cout << "4. Retourner un livre" << endl;
        cout << "5. Quitter" << endl;
        cout << "Choisissez une option : ";
        cin >> choix;

        switch (choix) {
            case 1:
                ajouterLivre(bibliothque, nombreLivres);
                break;
            case 2:
                afficherLivres(bibliothque, nombreLivres);
                break;
            case 3:
                emprunterLivre(bibliothque, nombreLivres);
                break;
            case 4:
                retournerLivre(bibliothque, nombreLivres);
                break;
            case 5:
                cout << "Au revoir!" << endl;
                return 0;
            default:
                cout << "Option invalide. Veuillez réessayer." << endl;
        }
    }

    return 0;
}

