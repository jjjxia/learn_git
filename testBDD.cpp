#include <iostream>
#include <iomanip>
#include "souffle/problog/formula/CuddManager.h"
#include <cudd.h>


int main() {
    WeightedBDDManager manager;

    auto x1 = manager.createVar(1);
    auto x2 = manager.createVar(2);
    auto x3 = manager.createVar(3);
    auto x4 = manager.createVar(4);
    manager.setVariableWeight(1, 0.3, 0.7);
    manager.setVariableWeight(2, 0.2, 0.8);
    manager.setVariableWeight(3, 0.1, 0.9);
    manager.setVariableWeight(4, 0.25, 0.75);

    auto f1 = manager.makeAnd(x1, manager.makeNot(x2));
    auto f2 = manager.makeAnd(x3, x4);
    auto f3 = manager.makeOr(f1,f2);

    manager.printInfo(f3, "f");

    double wmc = manager.computeWeightedModelCount(f3);
    std::cout << "WMC = " << wmc << std::endl;
    std::cout <<manager.toString(f3) << std::endl;
    return 0;
}
