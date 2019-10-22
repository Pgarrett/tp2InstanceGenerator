#include "longitudDeCicloVariable.h"

using namespace std;

void longitudDeCicloVariable::generate(string outputDirectory){
    vector<int> cantNodos = vector<int>();
    cantNodos.push_back(300);
    cantNodos.push_back(500);
    cantNodos.push_back(800);
    cantNodos.push_back(1000);
    vector<int> longCiclos = vector<int>();
    for (int i = 10; i < 1000; i++ ) {
        longCiclos.push_back(i);
    }
    for (unsigned int i = 0; i < longCiclos.size(); i++){
        for (unsigned int j = 0; j < cantNodos.size(); j++){
            if (cantNodos[j] + 1 >= longCiclos[i]){
                vector<vector<float> > matriz(cantNodos[j], vector<float>(cantNodos[j], 0));
                /* Prepara instancias para la experimentacion */
                int n = cantNodos[j];
                int longitud = longCiclos[i];
                int hasta = cantNodos[j];
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
                string path = outputDirectory + to_string(n) + "/" + to_string(n) + "_" + to_string(longitud) + ".txt";
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
    }
}

#include "longitudDeCicloVariable.h"
