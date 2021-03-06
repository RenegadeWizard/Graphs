//
//  EdgeTable.cpp
//  Graphs
//
//  Created by Krzysztof Sychla on 18.04.2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#include "EdgeTable.hpp"
#include <iostream>

EdgeTable::EdgeTable(int p,int **arr){
    n = 0;
    for(int i=0;i<p;i++)
        for(int j=0;j<p;j++)
            if(arr[i][j])
                n++;
    for(int i=0;i<2;i++)
        tab[i] = new int [n];
    int k=0;
    for(int i=0;i<p;i++)
        for(int j=0;j<p;j++)
            if(arr[i][j]){
                tab[0][k] = i;
                tab[1][k] = j;
                k++;
            }
    elem = p;
    temp1 = elem-1;
    visited = new bool [elem];
    sorted = new int [elem];
}

EdgeTable::~EdgeTable(){
//    for(int i=0;i<n;i++)
//        delete[] tab[i];
    delete[] tab;
    delete[] visited;
    delete[] sorted;
}

void EdgeTable::PrintTab(){
    for(int i=0;i<n;i++)
        std::cout<<tab[0][i]<<" "<<tab[1][i]<<"\n";
}

void EdgeTable::SortBFS(){
    int *b_count = new int [elem];
    int temp = elem;
    for(int i=0;i<elem;i++)
        b_count[i] = 0;
    for(int i=0;i<n;i++)
        b_count[tab[1][i]]++;
    for(int i=0;i<elem;i++);
    while(temp){
        for(int i=0;i<elem;i++){
            if(b_count[i]==-1)
                continue;
            if(b_count[i]==0){
                b_count[i] = -1;
                for(int j=0;j<n;j++)
                    if(tab[0][j]==i)
                        b_count[tab[1][j]]--;
                temp--;
            }
        }
    }
    delete[] b_count;
}

void EdgeTable::SortDFS(){
    for(int i=0;i<elem;i++)
        if(!visited[i])
            DFS(i);
}

void EdgeTable::DFS(int v){
    visited[v] = true;
    for(int i=0;i<n;i++)
        if(tab[0][i]==v && !visited[tab[1][i]])
            DFS(tab[1][i]);
    sorted[temp1--] = v;
}

void EdgeTable::PrintSorted(){
    for(int i=0;i<elem;i++){
        std::cout<<sorted[i]<<" ";
    }
    std::cout<<"\n";
}

