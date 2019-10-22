//
// Created by Philip Garrett on 22/10/2019.
//

#ifndef TP2INSTANCEGENERATOR_INSTANCIASFAVORABLESDESFAVORABLES_H
#define TP2INSTANCEGENERATOR_INSTANCIASFAVORABLESDESFAVORABLES_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class instanciasFavorablesDesfavorables {

public:
    void bellmanFavorable(string outputDirectory);
    void floydFavorable(string outputDirectory);

private:
    void writeToFile(string filePrefix, vector<vector<float> > &matriz);
};



#endif //TP2INSTANCEGENERATOR_INSTANCIASFAVORABLESDESFAVORABLES_H
