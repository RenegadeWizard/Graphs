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
    
    int sizes[] = {1000,2000,5000,10000,20000,30000,40000,60000,80000,100000};
    int size_sizes = sizeof(sizes)/sizeof(*sizes);
    
    for(int i=0;i<size_sizes;i++){
//        zaczytywanie danych z pliku
        int *n_tab = new int [sizes[i]];
        
        AdjacencyMatrix *macierz = new AdjacencyMatrix(sizes[i]);
        macierz->fill(n_tab);
        EdgeTable *tablica = new EdgeTable(sizes[i],macierz->GetTab());
        
//        Timer start
        macierz->BFS();
//        Timer stop
        
        
//        Timer start
        for(int i=0;i<6;i++)
            if(!macierz->GetVisited(i))
                macierz->DFS(i);
//        Timer stop
        
        
//        Timer start
        tablica->BFS();
//        Timer stop
        
        
//        Timer start
        for(int i=0;i<6;i++)
            if(!tablica->GetVisited(i))
                tablica->DFS(i);
//        Timer stop
        
        
        delete macierz;
        delete tablica;
        delete[] n_tab;
    }
    
    return 0;
}
