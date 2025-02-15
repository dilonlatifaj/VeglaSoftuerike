using namespace std;
#include <iostream>
#include <vector>
#include <fstream>
#define CMIMI_BAZE 11.5

enum KONTRATA {
    ORARI_I_PLOTE,
    GJYSEM_ORARI
};

struct Punetori {
    string emri;
    string mbiemri;
    KONTRATA kontrata;
    int oretEPunes[5];

    double kalkuloPagen() const {
        int normaEPlote;
        double cmimiNeBazeTeKontrates = CMIMI_BAZE;
        if (kontrata == GJYSEM_ORARI) {
            normaEPlote = 20;
            cmimiNeBazeTeKontrates /= 2;
        }
        else {
            normaEPlote = 40;
        }
        int shuma = 0;
        for (int i = 0; i < 5; i++) {
            shuma += oretEPunes[i];
        }
        if (shuma <= normaEPlote) {
            return shuma * cmimiNeBazeTeKontrates;
        }
        else {
            int overtime = shuma - normaEPlote;
            double cmimiPerOvertime = cmimiNeBazeTeKontrates * 1.2;
            return (normaEPlote * cmimiNeBazeTeKontrates) + (overtime * cmimiPerOvertime);
        }
    }
};

void shtoPunetorin(vector<Punetori>& lista) {
    Punetori p;
    int kontrataType;
    cout << "Emri: "; cin >> p.emri;
    cout << "Mbiemri: "; cin >> p.mbiemri;
    cout << "Lloji i kontrates (0 - Orari i plote, 1 - Gjysëm orari): "; cin >> kontrataType;
    p.kontrata = (kontrataType == 1) ? GJYSEM_ORARI : ORARI_I_PLOTE;

    for (int i = 0; i < 5; i++) {
        cout << "Oret per diten " << i + 1 << ": ";
        cin >> p.oretEPunes[i];
    }
    lista.push_back(p);
    cout << "Punetori u shtua me sukses!\n";
}

void shfaqPunetoret(const vector<Punetori>& lista) {
    if (lista.empty()) {
        cout << "Nuk ka punëtore të regjistruar!\n";
        return;
    }
    for (const auto& p : lista) {
        cout << "Punetori: " << p.emri << " " << p.mbiemri << " - Paga: " << p.kalkuloPagen() << " EUR\n";
    }
}

void ruajNeSkedar(const vector<Punetori>& lista) {
    ofstream file("punetoret.txt");
    if (!file) {
        cout << "Gabim në hapjen e skedarit!\n";
        return;
    }
    for (const auto& p : lista) {
        file << p.emri << " " << p.mbiemri << " " << p.kontrata << " ";
        for (int i = 0; i < 5; i++) {
            file << p.oretEPunes[i] << " ";
        }
        file << "\n";
    }
    file.close();
    cout << "Te dhenat u ruajten me sukses!\n";
}

void ngarkoNgaSkedari(vector<Punetori>& lista) {
    ifstream file("punetoret.txt");
    if (!file) {
        cout << "Skedari nuk ekziston ose nuk mund të hapet!\n";
        return;
    }
    while (!file.eof()) {
        Punetori p;
        int kontrataType;
        file >> p.emri >> p.mbiemri >> kontrataType;
        if (file.fail()) break; // Kontroll për fundin e skedarit
        p.kontrata = static_cast<KONTRATA>(kontrataType);
        for (int i = 0; i < 5; i++) {
            file >> p.oretEPunes[i];
        }
        lista.push_back(p);
    }
    file.close();
    cout << "Te dhenat u ngarkuan me sukses!\n";
}
int main () {
    vector<Punetori> lista;
    int zgjedhja;
    do {
        cout << "\n1. Shto punetor\n2. Shfaq punetoret\n3. Ruaj te dhenat\n4. Ngarko nga skedari\n5. Dil\nZgjedhni nje opsion: ";
        cin >> zgjedhja;
        switch (zgjedhja) {
        case 1: shtoPunetorin(lista); break;
        case 2: shfaqPunetoret(lista); break;
        case 3: ruajNeSkedar(lista); break;
        case 4: ngarkoNgaSkedari(lista); break;
        case 5: cout << "Dalje nga programi...\n"; break;
        default: cout << "Zgjedhje e gabuar, provo përsëri!\n";
        }
    } while (zgjedhja != 5);
    return 0;
}