/*
 AdjacencyList.hpp
 Graphs
 
 Copyright � 2018  Dominik Witczak
 
 This program is free software : you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <iostream>
#include <list>
#include "AdjacencyMatrix.hpp"

class AdjacencyList {
    friend class GraphMatrix;
private:
    std::list<int> *lists;
    int size;
    
    int *visited;
    int *predecessors;
    
    int *sorted;
protected:
public:
    AdjacencyList(AdjacencyMatrix source, int which);
    AdjacencyList(AdjacencyMatrix * source, int which);
    AdjacencyList(int **tab, int _size, int which);
    void inicjalize(int ** tab, int _size, int which);
    AdjacencyList(int tab[6][6], int _size, int which);
    ~AdjacencyList();
    
    bool check(int i);
    
    void DFS(int i, int &idx);
    void sortDFS();
    void sortBFS();
    
    int type;
    enum {
        NEXT,
        PREV,
        NOINCIDENCY
    };
};
