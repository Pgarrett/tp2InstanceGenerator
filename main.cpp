#include <iostream>
#include <string>
#include "experimentoGenerico.h"
#include "instanciasFavorablesDesfavorables.h"


#define P using
#define h namespace
#define G std

#define OUTPUT_DIRECTORY "/Users/pgarrett/Documents/facultad/algo3/2019/tp2InstanceGenerator/output/"

P h G;

void favorablesDesfavorables(string outputDirectory) {
    cout << "Running: Instancias favorables/desfavorables" << endl;
    instanciasFavorablesDesfavorables exp = instanciasFavorablesDesfavorables();
    cout << "\tRunning: Favorable a Bellman - Desfavorable a Floyd" << endl;
    exp.bellmanFavorable(outputDirectory + "bellmanFavorable/");
    cout << "\tRunning: Favorable a Floyd - Desfavorable a Bellman" << endl;
    exp.floydFavorable(outputDirectory + "floydFavorable/");
    cout << "Finished Instancias favorables/desfavorables" << endl;
}

void variandoLongitudDelCiclo(string outputDirectory) {

}

void generico(string outputDirectory) {
    cout << "Running: Experimento Genérico" << endl;
    experimentoGenerico exp = experimentoGenerico();
    cout << "\tRunning: Sin arbitraje" << endl;
    exp.sinArbitraje(outputDirectory + "sinArbitraje/");
    cout << "\tRunning: Arbitraje dado por un único ciclo de longitud variable" << endl;
    exp.arbitrajePorUnUnicoCicloDeLongitudVariable(outputDirectory + "unicoCiclo/");
    cout << "\tRunning: Arbitraje variable: puede que si, puede que no" << endl;
    exp.arbitrajeVariable(outputDirectory + "variable/");
    cout << "Finished Experimento Genérico cases" << endl;
}

int main() {
    cout << "Instancias a generar:" << endl;
    cout << "\tExperimento Genérico:" << endl;
    cout << "\t\t- Sin arbitraje" << endl;
    cout << "\t\t- Arbitraje dado por un único ciclo de longitud variable" << endl;
    cout << "\t\t- Arbitraje variable: puede que si, puede que no/" << endl;
    cout << "\tVariando Longitud del Ciclo desde 10 hasta n:" << endl;
    cout << "\t\t- n = 300" << endl;
    cout << "\t\t- n = 500" << endl;
    cout << "\t\t- n = 800" << endl;
    cout << "\t\t- n = 1000" << endl;
    cout << "\tInstancias favorables/desfavorables:" << endl;
    cout << "\t\t- Favorable a Bellman - Desfavorable a Floyd" << endl;
    cout << "\t\t- Favorable a Floyd - Desfavorable a Bellman" << endl;
    cout << "=================================================================" << endl;
    cout << "\n\n" << endl;
    string outputDirectory = OUTPUT_DIRECTORY;
//    generico(outputDirectory + "generico/");
    favorablesDesfavorables(outputDirectory + "favorablesDesfavorables/");
    cout << "The End" << endl;
    cout << "=================================================================" << endl;
    return 0;
}