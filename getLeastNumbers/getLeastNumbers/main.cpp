//
//  main.cpp
//  getLeastNumbers
//
//  Created by wjl on 16/3/19.
//  Copyright © 2016年 Martin. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
#include <set>
using namespace std;
typedef multiset<int,greater<int>> intSet;
typedef multiset<int,greater<int>> ::iterator setIterator;

void getLeastNumbers(vector<int> data, intSet leastNumbers, int k){
    
    if (k < 0 || data.size() < k ) {
        return;
    }
    
    vector<int>::iterator iter = data.begin();
    for (; iter != data.end(); iter++) {
        if (leastNumbers.size() < k) {
            leastNumbers.insert(*iter);
        }
        else{
            setIterator iterGreatest = leastNumbers.begin();
            if (*iter < *iterGreatest) {
                leastNumbers.erase(iterGreatest);
                leastNumbers.insert(*iter);
            }
        }
    }
    
}