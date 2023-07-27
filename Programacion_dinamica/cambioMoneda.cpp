#include <iostream>
#include <vector>

using namespace std;

class CambioModenas {
private:
    int numCoins;
    vector<int> coinValues;
    vector<vector<int>> dpTable;

public:
    CambioModenas(const vector<int>& coins) : coinValues(coins) {
        numCoins = coins.size();
    }

    int minCoins(int amount) {
        const int INF = 1000000000;
        dpTable.resize(numCoins + 1,vector<int>(amount + 1, 0));

        for (int i = 1; i <= amount; i++) {
            dpTable[0][i] = INF;
        }

        for (int i = 1; i <= numCoins; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coinValues[i - 1] <= j) {
                    dpTable[i][j] = min(dpTable[i - 1][j], 1 + dpTable[i][j - coinValues[i - 1]]);
                } else {
                    dpTable[i][j] = dpTable[i - 1][j];
                }
            }
        }

        return dpTable[numCoins][amount] == INF ? -1 : dpTable[numCoins][amount];
    }

    void printDPTable() {
        cout<<"DP Table:"<<endl;
        for (int i = 0; i <= numCoins; i++) {
            for (int j = 0; j < dpTable[i].size(); j++) {
                cout<<dpTable[i][j] << " ";
            }
            cout<<endl;
        }
    }

    vector<int> getCoinCount(int amount) {
        vector<int> coinCount(numCoins, 0);
        int i = numCoins;
        int j = amount;

        while (i != 0 && j != 0) {
            if (dpTable[i][j] == dpTable[i - 1][j]) {
                i--;
            } else {
                coinCount[i - 1]++;
                j -= coinValues[i - 1];
            }
        }

        return coinCount;
    }
};

int main() {
    vector<int> monedas = {1, 4,6};
    int amount = 8,n,m;
    cout<<"Monto: ";cin>>amount;
    cout<<"Numero de mondenas: ";cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        monedas.push_back(m);
    }

    CambioModenas Omonedas(monedas);
    int MinMonedas = Omonedas.minCoins(amount);
    cout<<"Número mínimo de monedas necesarias: "<<MinMonedas<<endl;

    Omonedas.printDPTable(); // Mostrar la tabla de programación dinámica

    vector<int> coinCount = Omonedas.getCoinCount(amount);
    cout << "Número de monedas de cada tipo utilizadas: ";
    for (int count : coinCount) {
        cout<<count <<" ";
    }
    cout<<endl;

    return 0;
}
