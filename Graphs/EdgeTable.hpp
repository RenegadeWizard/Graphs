//
//  EdgeTable.hpp
//  Graphs
//
//  Created by Krzysztof Sychla on 18.04.2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#pragma once
#include <stdio.h>

class EdgeTable{
public:
    void BFS();
    void DFS(int v);
    void PrintTab();
    bool GetVisited(int v){return visited[v];}
    EdgeTable(int p,int **arr);
    ~EdgeTable();
private:
    int n = 0;
    int elem;
    int temp = n-1;
    int **tab = new int *[2];
    bool *visited = new bool [n];
    int *sorted = new int [n];
};
