//
// Created by Philip Garrett on 22/10/2019.
//

#ifndef TP2INSTANCEGENERATOR_EXPERIMENTOGENERICO_H
#define TP2INSTANCEGENERATOR_EXPERIMENTOGENERICO_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class experimentoGenerico {

public:
    void sinArbitraje(string outputDirectory);
    void arbitrajePorUnUnicoCicloDeLongitudVariable(string outputDirectory);
    void arbitrajeVariable(string outputDirectory);

private:
    void writeToFile(string filePrefix, vector<vector<float> > &matriz);
};


#endif //TP2INSTANCEGENERATOR_EXPERIMENTOGENERICO_H
