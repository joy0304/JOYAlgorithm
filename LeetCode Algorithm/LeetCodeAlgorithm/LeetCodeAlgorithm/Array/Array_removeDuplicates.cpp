
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    
    if (nums.size() < 2) {
        return (int)nums.size();
    }
    int index = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i-1]) {
            nums[index++] = nums[i-1];
        }
    }
    return index + 1;
}

//int main(){
//    
//    vector<int> Test;
//    Test.push_back(1);
//    Test.push_back(1);
//    Test.push_back(1);
//    Test.push_back(2);
//    Test.push_back(3);
//    Test.push_back(4);
//    Test.push_back(5);
//    Test.push_back(7);
//    Test.push_back(7);
//    
//    int result = removeDuplicates(Test);
//    std::cout << result << endl;
//}