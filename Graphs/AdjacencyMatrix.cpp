//
//  AdjacencyMatrix.cpp
//  Graphs
//
//  Created by Krzysztof Sychla on 18.04.2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#include "AdjacencyMatrix.hpp"

AdjacencyMatrix::AdjacencyMatrix(int ile){
    n = ile;
    for(int i = 0;i < n;i++)
        tab[i] = new int [n];
}

AdjacencyMatrix::~AdjacencyMatrix(){
    for(int i=0;i<n;i++)
        delete[] tab[i];
    delete[] tab;
}

void AdjacencyMatrix::fill(int array[]){
    int *ptr = array;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i>j){
                tab[i][j] = *ptr;
                ptr++;
            }else{
                tab[i][j] = 0;
            }
        }
    }
}

void AdjacencyMatrix::preorder(){
    return;
}

void AdjacencyMatrix::postorder(){
    return;
}
