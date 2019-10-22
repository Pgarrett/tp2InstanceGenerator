#include "instanciasFavorablesDesfavorables.h"

using namespace std;

void instanciasFavorablesDesfavorables::writeToFile(string filePrefix, vector<vector<float> > &matriz) {
    for (int n = 10; n < 1400; n+=5){
        ofstream resultados;
        string path = filePrefix + to_string(n) + ".txt";
        resultados.open(path);
        resultados << n << endl;
        for (int f = 0; f < n; f++){
            for (int c = 0; c < n; c++){
                resultados << matriz[f][c];
                if (c < n -1) {
                    resultados << " ";
                } else {
                    resultados << endl;
                }
            }
        }
        resultados.close();
        if (n % 200 == 0) {
            cout << "\t\t\tWrote " << n << " out of 1400 cases." << endl;
        }
    }
}


void instanciasFavorablesDesfavorables::bellmanFavorable(string outputDirectory) {
    vector<vector<float> > matriz(1400, vector<float>(1400, 1));
    for (int n = 10; n < 1400; n+=5){
        /* Crea instancias de i nodos con pesos en las aristas entre 0.3 y 1.0, por lo tanto, no hay arbitraje*/
        float currency;
        for (int f = 0; f < n; f++){
            for (int c = 0; c < n; c++){
                if (f != c){
                    currency = 0.3 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.7)));
                    matriz[f][c] = currency;
                }
            }
        }
    }
    writeToFile(outputDirectory + "bellmanFavorable_n_", matriz);
}

void instanciasFavorablesDesfavorables::floydFavorable(string outputDirectory) {
    for (int n = 10; n < 1400; n+=5){
        vector<vector<float> > matriz(n, vector<float>(n, 1));
        int longitud = n/4;
        int hasta = n/4;
        float casiCero = 0.1;
        /* Inicializa la matriz con un valor muy cercano a cero */
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                matriz[i][j] = casiCero;
        /* Pone la diagonal con peso = 1 */
        for (int i = 0; i < n; i++) matriz[i][i] = 1;
        /* Crea un ciclo con ganancia de tamaño longitud de indices random */
        vector<int> ciclo;
        int i,j,inicial;
        inicial = rand() % (hasta);
        i = inicial;
        longitud-=2;
        ciclo.push_back(inicial);
        do{
            j = rand() % (hasta);
            while (find(ciclo.begin(), ciclo.end(), j) != ciclo.end()){
                j = rand() % (hasta);
            }
            matriz[i][j] = 1.00000000001;
            i = j;
            ciclo.push_back(j);
            longitud--;
        } while (longitud > 0);
        matriz[j][inicial] = 2.0;
        ofstream resultados;
        string path = outputDirectory + "floydFavorable_n_" + to_string(n) + ".txt";
        resultados.open(path);
        resultados << n << endl;
        for (int f = 0; f < n; f++){
            for (int c = 0; c < n; c++){
                resultados << matriz[f][c];
                if (c < n -1) {
                    resultados << " ";
                } else {
                    resultados << endl;
                }
            }
        }
        resultados.close();
        if (n % 200 == 0) {
            cout << "\t\t\tWrote " << n << " out of 1400 cases." << endl;
        }
    }
}