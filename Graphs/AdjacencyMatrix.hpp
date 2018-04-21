//
//  AdjacencyMatrix.hpp
//  Graphs
//
//  Created by Krzysztof Sychla on 18.04.2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#pragma once
#include <stdio.h>

class AdjacencyMatrix{
public:
    void fill(int tab[]);
    void preorder();
    void postorder();
    void DFS();
    int GetN(){return n;}
    void printTab();
    AdjacencyMatrix(int ile);
    ~AdjacencyMatrix();
private:
    int n;
    int **tab = new int *[n];
};
