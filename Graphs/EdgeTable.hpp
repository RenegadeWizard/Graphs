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
    void SortBFS();
    void SortDFS();
    void DFS(int v);
    void PrintTab();
    bool GetVisited(int v){return visited[v];}
    void PrintSorted();
    EdgeTable(int p,int **arr);
    ~EdgeTable();
private:
    int n;
    int elem;
    int temp1;
    int **tab = new int *[2];
    bool *visited;
    int *sorted;
};
