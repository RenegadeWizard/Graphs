/*
 GraphMatrix.cpp
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

#include "GraphMatrix.hpp"


GraphMatrix::GraphMatrix(AdjacencyMatrix source)
{
    inicjalize(source.tab, source.n);
}

GraphMatrix::GraphMatrix(AdjacencyMatrix *source)
{
//    std::cout << "n = " << source->n << "\n";
    inicjalize(source->tab, source->n);
//    std::cout << "n = " << n << "\n";
    
}

void GraphMatrix::inicjalize(int **tab, int _size)
{
    n = _size;
//    std::cout << "n = " << n << "\n";
    //intiazlize Adjacency Lists
    AdjacencyList    *succesors = new AdjacencyList(tab, _size, AdjacencyList::NEXT),
    *predecessors = new AdjacencyList(tab, _size, AdjacencyList::PREV),
    *noincidences = new AdjacencyList(tab, _size, AdjacencyList::NOINCIDENCY);
    //initialzie the container (matrix)
    matrix = new long long int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new long long int[n + 3];
    }
    
    //initialize Succesors, Predecessors and NoIncidences columns
    for (int i = 0; i < n; i++) {
        //Succesors
        if (succesors->lists[i].empty())
            matrix[i][0] = 0;
        else
            matrix[i][0] = succesors->lists[i].front() + 1;
        //Predecessors
        if (predecessors->lists[i].empty())
            matrix[i][1] = 0;
        else
            matrix[i][1] = predecessors->lists[i].front() + 1;
        //NoIncidences
        if (noincidences->lists[i].empty())
            matrix[i][2] = 0;
        else
            matrix[i][2] = noincidences->lists[i].front() + 1;
    }
    
    for (int i = 0; i < n; i++) {
        //fill the succesors of i-th element <1, n>
        for (std::list<int>::const_iterator iter = succesors->lists[i].begin(), end = succesors->lists[i].end(); iter != end; ++iter) {
            //for (auto iter : succesors.lists[i]){
            std::list<int>::const_iterator next = iter;
            next++;
            if (next != succesors->lists[i].end()) {
                //assign the value of next succesor
                matrix[i][*iter + 3] = *next + 1;
            }
            else {
                //assign the value of itself
                matrix[i][*iter + 3] = *iter + 1;
            }
        }
        
        //fill the predecessors of i-th element <-n, -1>
        for (std::list<int>::const_iterator iter = predecessors->lists[i].begin(), end = predecessors->lists[i].end(); iter != end; ++iter) {
            //for (auto iter : succesors.lists[i]){
            std::list<int>::const_iterator next = iter;
            next++;
            if (next != predecessors->lists[i].end()) {
                //assign the value of next succesor
                matrix[i][*iter + 3] = -*next - 1;
                iter;
            }
            else {
                //assign the value of itself
                matrix[i][*iter + 3] = -*iter - 1;
            }
        }
        
        //fill elem with no incidences to i-th element <n+1, 2n>
        for (std::list<int>::const_iterator iter = noincidences->lists[i].begin(), end = noincidences->lists[i].end(); iter != end; ++iter) {
            //for (auto iter : succesors.lists[i]){
            std::list<int>::const_iterator next = iter;
            next++;
            if (next != noincidences->lists[i].end()) {
                //assign the value of next succesor
                matrix[i][*iter + 3] = n + *next + 1;
                iter;
            }
            else {
                //assign the value of itself
                matrix[i][*iter + 3] = n + *iter + 1;
            }
        }
    }
    
    //Write the matrix for debugging
//    std::cout << "idx\tS\tP\tN\t ";
//    for (int i = 0; i < n; i++)
//        std::cout << i + 1 << "\t";
//    std::cout << "\n";
    
//    for (int i = 0; i < n; i++) {
//        std::cout << i + 1 << " |\t";
//        for (int j = 0; j < 3; j++) {
//            std::cout << matrix[i][j] << "\t";
//        }
//        std::cout << "|";
//        for (int j = 3; j < n + 3; j++) {
//            std::cout << matrix[i][j] << "\t";
//        }
//        std::cout << "\n";
//    }
//
//    std::cout << "n = " << n << "\n";
    
    delete succesors;
    delete predecessors;
    delete noincidences;
    
//    std::cout << "n = " << n << "\n";
    
}

GraphMatrix::GraphMatrix(int tab[6][6], int _size)
{
    n = _size;
    //intiazlize Adjacency Lists
    AdjacencyList    *succesors = new AdjacencyList (tab, _size, AdjacencyList::NEXT),
    *predecessors = new AdjacencyList (tab, _size, AdjacencyList::PREV),
    *noincidences = new AdjacencyList (tab, _size, AdjacencyList::NOINCIDENCY);
    //initialzie the container (matrix)
    matrix = new long long int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new long long int[n + 3];
    }
    
    //initialize Succesors, Predecessors and NoIncidences columns
    for (int i = 0; i < n; i++) {
        //Succesors
        if (succesors->lists[i].empty())
            matrix[i][0] = 0;
        else
            matrix[i][0] = succesors->lists[i].front() + 1;
        //Predecessors
        if (predecessors->lists[i].empty())
            matrix[i][1] = 0;
        else
            matrix[i][1] = predecessors->lists[i].front() + 1;
        //NoIncidences
        if (noincidences->lists[i].empty())
            matrix[i][2] = 0;
        else
            matrix[i][2] = noincidences->lists[i].front() + 1;
    }
    
    for (int i = 0; i < n; i++) {
        //fill the succesors of i-th element <1, n>
        for (std::list<int>::const_iterator iter = succesors->lists[i].begin(), end = succesors->lists[i].end() ; iter != end; ++iter) {
            //for (auto iter : succesors.lists[i]){
            std::list<int>::const_iterator next = iter;
            next++;
            if (next != succesors->lists[i].end()) {
                //assign the value of next succesor
                matrix[i][*iter + 3] = *next + 1;
            }
            else {
                //assign the value of itself
                matrix[i][*iter + 3] = *iter + 1;
            }
        }
        
        //fill the predecessors of i-th element <-n, -1>
        for (std::list<int>::const_iterator iter = predecessors->lists[i].begin(), end = predecessors->lists[i].end(); iter != end; ++iter) {
            //for (auto iter : succesors.lists[i]){
            std::list<int>::const_iterator next = iter;
            next++;
            if (next != predecessors->lists[i].end()) {
                //assign the value of next succesor
                matrix[i][*iter + 3] = - *next - 1;
                iter;
            }
            else {
                //assign the value of itself
                matrix[i][*iter + 3] = - *iter - 1;
            }
        }
        
        //fill elem with no incidences to i-th element <n+1, 2n>
        for (std::list<int>::const_iterator iter = noincidences->lists[i].begin(), end = noincidences->lists[i].end(); iter != end; ++iter) {
            //for (auto iter : succesors.lists[i]){
            std::list<int>::const_iterator next = iter;
            next++;
            if (next != noincidences->lists[i].end()) {
                //assign the value of next succesor
                matrix[i][*iter + 3] = n + *next + 1;
                iter;
            }
            else {
                //assign the value of itself
                matrix[i][*iter + 3] = n + *iter + 1;
            }
        }
    }
    
    //Write the matrix for debugging
//    std::cout << "idx\tS\tP\tN\t ";
//    for (int i = 0; i < n; i++)
//        std::cout << i + 1 << "\t";
//    std::cout << "\n";
    
//    for (int i = 0; i < n; i++) {
//        std::cout << i+1 << " |\t";
//        for (int j = 0; j < 3; j++) {
//            std::cout << matrix[i][j] << "\t";
//        }
//        std::cout << "|";
//        for (int j = 3; j < n + 3; j++) {
//            std::cout << matrix[i][j] << "\t";
//        }
//        std::cout << "\n";
//    }
    
    delete succesors;
    delete predecessors;
    delete noincidences;
}

GraphMatrix::~GraphMatrix()
{
}


void GraphMatrix::DFS(int i, int &idx)
{
    //NOTE : this function and all the helping structures is inexing from 0, but Graph Matrix Requires to index from 1,
    //this means I had to manipulate the indexes on the run.
    if (visited == NULL)
        return;
//    printf("\n%d\n", i);
    visited[i] = 1;
    long long int iter = matrix[i][0];
    //for every succesor
    int twice = 0;
    while (twice != 2 && iter != 0) {
        if (!visited[iter - 1])
            DFS(iter - 1, idx);
//        printf("%d ", iter);
        iter = matrix[i][2 + iter];
        if (iter == matrix[i][2 + iter])
            twice++;
    }
//    printf("\n");
    sorted[--idx] = i;
}

void GraphMatrix::sortDFS()
{
//    std::cout << "sortDFS\n";
//    std::cout << "n = " << n << "\n";
    visited = new int[n];
    for (int i = 0; i < n; i++) {
//        std::cout << "\tinicjalizuje "<<i<<" element tablicy\n";
        visited[i] = 0;
    }
    sorted = new int[n];
    
    int idx = n;
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            DFS(i, idx);
    }
    
//    for (int i = 0; i < n; i++)
//        std::cout << sorted[i] + 1 << " ";
//    std::cout << "\n";
    delete visited;
    delete sorted;
}



void GraphMatrix::sortBFS()
{
    //initialize arrays
    predecessors_count = new int[n];
    for (int i = 0; i < n; i++)
        predecessors_count[i] = 0;
    sorted = new int[n];
    
    //fill the ancestors list
    for (int i = 0; i < n; i++) {
        long long int iter = matrix[i][0];
        int twice = 0;
        bool first_iteration = true;
        
        while (twice != 2 && iter != 0) {
            predecessors_count[iter-1]++;
            iter = matrix[i][2 + iter];
            //so the last element is handled
            if (iter == matrix[i][2 + iter])
                twice++;
            //if the list is one-element, dont write it twice
            if (iter == matrix[i][2 + iter] && first_iteration)
                twice = 2;
            first_iteration = false;
        }
    }
    
    
    //sort
    for (int idx = 0; idx < n;) {
        //find an elem with no ancestors;
        int k = 0;
        while (predecessors_count[k] != 0 && k < n - 1)
            k++;
        
        //Indicate as sorted
        sorted[idx++] = k;
        predecessors_count[k]--; // indicate as -1, so you ingore it later
        
        //for every succesor of k, decrement it predecessors count
        int iter = matrix[k][0];
        int twice = 0;
        bool first_iteration = true;
        while (twice != 2 && iter != 0) {
            predecessors_count[iter-1]--;
            iter = matrix[k][2 + iter];
            //so the last element is handled
            if (iter == matrix[k][2 + iter])
                twice++;
            //if the list is one-element, dont write it twice
            if (iter == matrix[k][2 + iter] && first_iteration)
                twice = 2;
            first_iteration = false;
        }
    }
    //write the sorted Graph
//    for (int i = 0; i < n; i++)
//        std::cout << sorted[i] + 1 << " ";
//    std::cout << "\n";
    
//    delete visited;
//    delete sorted;
}
