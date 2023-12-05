#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_INVENTARI = 10;

int menu() {
    int opcio;
    // Menú d'opcions per a l'usuari.
    cout << "1. Entrar objecte del joc" << endl;
    cout << "2. Eliminar objecte del joc" << endl;
    cout << "3. Entrar una quantitat determinada d'objectes" << endl;
    cout << "4. Buidar tot l'inventari" << endl;
    cout << "0. Sortir" << endl;
    cout << "Entra la teva opcio (0-4): ";
    cin >> opcio;
    return opcio;
}

// Funció per inserir un element a l'inventari.
void inserirElement(vector<string>& inventari, const string& element) {
    if (inventari.size() < MAX_INVENTARI) {
        inventari.push_back(element);
        cout << "Element afegit a l'inventari." << endl;
    }
    else {
        cout << "L'inventari esta ple. No es pot afegir mes elements." << endl;
    }
}

// Funció per eliminar un element de l'inventari basant-se en el nom.
void treureElement(vector<string>& inventari, const string& nomElement) {
    auto it = find(inventari.begin(), inventari.end(), nomElement);
    if (it != inventari.end()) {
        inventari.erase(it);
        cout << "Element eliminat de l'inventari." << endl;
    }
    else {
        cout << "L'element no es troba a l'inventari." << endl;
    }
}

// Funció per buscar un element a l'inventari i mostrar la seva posició.
void buscarElement(const vector<string>& inventari, const string& nomElement) {
    auto it = find(inventari.begin(), inventari.end(), nomElement);
    if (it != inventari.end()) {
        int posicio = distance(inventari.begin(), it);
        cout << "L'element es troba a la posicio " << posicio << " de l'inventari." << endl;
    }
    else {
        cout << "L'element no es troba a l'inventari." << endl;
    }
}

// Funció per llistar tots els elements de l'inventari.
void llistarElements(const vector<string>& inventari) {
    cout << "Elements a l'inventari:" << endl;
    for (const string& element : inventari) {
        cout << "- " << element << endl;
    }
}

int main() {
    vector<string> inventari;

    while (true) {
        int opcio = menu();

        switch (opcio) {
        case 1: {
            // Trucada a la funció per inserir un element a l'inventari.
            string nouElement;
            cout << "Entra el nom de l'objecte: ";
            cin >> nouElement;
            inserirElement(inventari, nouElement);
            break;
        }
        case 2: {
            // Trucada a la funció per eliminar un element de l'inventari.
            string nomElement;
            cout << "Entra el nom de l'objecte que vols eliminar: ";
            cin >> nomElement;
            treureElement(inventari, nomElement);
            break;
        }
        case 3: {
            // Trucada a la funció per buscar un element a l'inventari.
            string nomElement;
            cout << "Entra el nom de l'objecte que vols buscar: ";
            cin >> nomElement;
            buscarElement(inventari, nomElement);
            break;
        }
        case 4: {
            // Trucada a la funció per llistar els elements de l'inventari.
            llistarElements(inventari);
            break;
        }
        case 0: {
            // Finalitzar el programa si l'usuari tria sortir.
            cout << "Adeu! Fi del programa." << endl;
            return 0;
        }
        default: {
            // Missatge en cas que l'usuari ingressi una opció no vàlida.
            cout << "Opcio no valida. Torna a intentar-ho." << endl;
        }
        }
    }

    return 0;
}
