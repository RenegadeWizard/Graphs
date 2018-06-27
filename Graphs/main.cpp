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
#include "Timer.hpp"
#include "AdjacencyList.hpp"
#include "GraphMatrix.hpp"

int main(int argc, const char * argv[]) {
    
    int sizes[] = {500,1000,1500,2000,2500,3000,3500,4000,4500,5000};
    int size_sizes = sizeof(sizes)/sizeof(*sizes);
    
//    Timer timer;
//    std::fstream dane;
//    std::fstream wynik_BFS;
//    std::fstream wynik_DFS;
//    dane.open("dane.txt",std::ios_base::in);
//    wynik_BFS.open("BFS.txt",std::ios_base::out);
//    wynik_DFS.open("DFS.txt",std::ios_base::out);
//
////    std::cout<<"BFS"<<"\n";
//
//    for(int i=0;i<size_sizes;i++){
//        int *n_tab = new int[(sizes[i]*(sizes[i]-1))/2];
//        for(int j=0;j<(sizes[i]*(sizes[i]-1))/2;j++){
//            dane >> n_tab[j];
//        }
//
//        AdjacencyMatrix *macierz = new AdjacencyMatrix(sizes[i]);
//        macierz->fill(n_tab);
//        EdgeTable *tablica = new EdgeTable(sizes[i],macierz->GetTab());
//        AdjacencyList *lista = new AdjacencyList(*macierz,0);
//        GraphMatrix *graf = new GraphMatrix(*macierz);
//
////------------------------------------------------------------------
////
////        Macierz Sąsiedztwa
////        std::cout<<"Macierz sąsiedztwa "<<sizes[i]<<"\n";
////
////        timer.StartTimer();
////        macierz->SortBFS();
////        timer.EndTimer();
////
////        std::cout<<"BFS: "<<timer.GetDelta()<<"\n";
////        wynik<<timer.GetDelta();
////
////        timer.StartTimer();
////        macierz->SortDFS();
////        timer.EndTimer();
////        std::cout<<"DFS: "<<timer.GetDelta()<<"\n";
////------------------------------------------------------------------
////
////        Tablica krawędzi
////        std::cout<<"Tablica krawędzi "<<sizes[i]<<"\n";
////
////        timer.StartTimer();
////        tablica->SortBFS();
////        timer.EndTimer();
////        std::cout<<"BFS: "<<timer.GetDelta()<<"\n";
////
////        timer.StartTimer();
////        tablica->SortDFS();
////        timer.EndTimer();
////        std::cout<<"DFS: "<<timer.GetDelta()<<"\n";
////------------------------------------------------------------------
////
////        Lista Następników
////        std::cout<<"Lista następników "<<sizes[i]<<"\n";
////
////        timer.StartTimer();
////        lista->sortBFS();
////        timer.EndTimer();
////        std::cout<<"BFS: "<<timer.GetDelta()<<"\n";
////
////        timer.StartTimer();
////        lista->sortDFS();
////        timer.EndTimer();
////        std::cout<<"DFS: "<<timer.GetDelta()<<"\n";
////------------------------------------------------------------------
////
////        Macierz grafu
////        std::cout<<"Macierz grafu "<<sizes[i]<<"\n";
////
////        timer.StartTimer();
////        graf->sortBFS();
////        timer.EndTimer();
////        std::cout<<"BFS: "<<timer.GetDelta()<<"\n";
////
////        timer.StartTimer();
////        graf->sortDFS();
////        timer.EndTimer();
////        std::cout<<"DFS: "<<timer.GetDelta()<<"\n";
////------------------------------------------------------------------
//
////        BFS
//
////        wynik_BFS<<sizes[i];
//
////        Macierz sąsiedztwa
////        std::cout<<sizes[i]<<" - Macierz sąsiedztwa"<<"\n";
//        timer.StartTimer();
//        macierz->SortBFS();
//        timer.EndTimer();
//        wynik_BFS<<timer.GetDelta();
//
////        Tablica krawędzi
////        std::cout<<sizes[i]<<" - Tablica krawędzi"<<"\n";
//        timer.StartTimer();
//        tablica->SortBFS();
//        timer.EndTimer();
//        wynik_BFS<<" "<<timer.GetDelta();
//
////        Lista następników
////        std::cout<<sizes[i]<<" - Lista następników"<<"\n";
//        timer.StartTimer();
//        lista->sortBFS();
//        timer.EndTimer();
//        wynik_BFS<<" "<<timer.GetDelta();
//
////        Macierz grafu
////        std::cout<<sizes[i]<<" - Macierz grafu"<<"\n";
//        timer.StartTimer();
//        graf->sortBFS();
//        timer.EndTimer();
//        wynik_BFS<<" "<<timer.GetDelta()<<"\n";
//
//
//        delete macierz;
//        delete tablica;
//        delete lista;
//        delete graf;
//        delete[] n_tab;
//    }
//    dane.close();
//    dane.open("dane.txt",std::ios_base::in);
////    std::cout<<"DFS"<<"\n";
//    for(int i=0;i<size_sizes;i++){
//        int *n_tab = new int[(sizes[i]*(sizes[i]-1))/2];
//        for(int j=0;j<(sizes[i]*(sizes[i]-1))/2;j++){
//            dane >> n_tab[j];
//        }
//
//        AdjacencyMatrix *macierz = new AdjacencyMatrix(sizes[i]);
//        macierz->fill(n_tab);
//        EdgeTable *tablica = new EdgeTable(sizes[i],macierz->GetTab());
//        AdjacencyList *lista = new AdjacencyList(*macierz,0);
//        GraphMatrix *graf = new GraphMatrix(*macierz);
//
////        DFS
////        wynik_DFS<<sizes[i];
//
////        Macierz sąsiedztwa
////        std::cout<<sizes[i]<<" - Macierz sąsiedztwa"<<"\n";
//        timer.StartTimer();
//        macierz->SortDFS();
//        timer.EndTimer();
//        wynik_DFS<<timer.GetDelta();
//
////        Tablica krawędzi
////        std::cout<<sizes[i]<<" - Tablica krawędzi"<<"\n";
//        timer.StartTimer();
//        tablica->SortDFS();
//        timer.EndTimer();
//        wynik_DFS<<" "<<timer.GetDelta();
//
////        Lista następników
////        std::cout<<sizes[i]<<" - Lista następników"<<"\n";
//        timer.StartTimer();
//        lista->sortDFS();
//        timer.EndTimer();
//        wynik_DFS<<" "<<timer.GetDelta();
//
////        Macierz grafu
////        std::cout<<sizes[i]<<" - Macierz grafu"<<"\n";
//        timer.StartTimer();
//        graf->sortDFS();
//        timer.EndTimer();
//        wynik_DFS<<" "<<timer.GetDelta()<<"\n";
//
//
//        delete macierz;
//        delete tablica;
//        delete lista;
//        delete graf;
//        delete[] n_tab;
//
//
//
//    }
//    dane.close();
//    wynik_BFS.close();
//    wynik_DFS.close();
//
    
    
    return 0;
}
