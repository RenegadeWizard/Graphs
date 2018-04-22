//
//  main.cpp
//  Graphs
//
//  Created by Krzysztof Sychla on 18.04.2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "AdjacencyMatrix.hpp"
#include "EdgeTable.hpp"


int main(int argc, const char * argv[]) {
    int tab[6][6] = {{0,1,1,0,1,0},
                    {0,0,1,1,0,0},
                    {0,0,0,1,0,0},
                    {0,0,0,0,1,0},
                    {0,0,0,0,0,1},
                    {0,0,0,0,0,0}};
    
    int n_tab[] = {1,1,0,1,0,0,1,0,0,1,0,0,1,0,1};
    AdjacencyMatrix *macierz = new AdjacencyMatrix(6);
    macierz->fill(n_tab);
    macierz->printTab();
    for(int i=0;i<6;i++)
        if(!macierz->GetVisited(i))
            macierz->DFS(i);
//    macierz->printSorted();
    delete macierz;
    return 0;
}
