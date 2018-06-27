/*
 GraphMatrix.hpp
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

#include "AdjacencyMatrix.hpp"
#include "AdjacencyList.hpp"


class GraphMatrix {
private:
    long long int * * matrix;
    int n;
    
    int *visited;
    int *predecessors_count;
    
    int *sorted;
    
protected:
public:
    GraphMatrix(AdjacencyMatrix source);
    GraphMatrix(AdjacencyMatrix * source);
    void inicjalize(int ** tab, int _size);
    GraphMatrix(int tab[6][6], int _size);
    ~GraphMatrix();
    
    void writeN() { std::cout << "n = " << n << "\n"; }
    
    void DFS(int i, int &idx);
    void sortDFS();
    void sortBFS();
};
