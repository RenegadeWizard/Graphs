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
    void preorder();
    void postorder();
    EdgeTable(int ile);
private:
    int n;
    int **tab = new int *[n];
};
