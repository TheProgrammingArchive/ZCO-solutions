//
// Created by HP on 29-12-2022.
//

#ifndef ZCOPRAC_STRINGIMPORTANCE_H
#define ZCOPRAC_STRINGIMPORTANCE_H
#include <iostream>
#include <limits>
#include <vector>
#include <map>

class StringImportance{
private:
    int k;
    std::vector<char> problem_string = {};
    std::map<int, int> index_substring_overlap = {};

    void update_map(int i1, int j1){
        for (int i = i1; i <= j1; i++){
            index_substring_overlap[i] += 1;
        }
    }

public:
    int max_overlaps(int i1, int j1){
        int max = 0;
        for (int i = i1; i <= j1; i++){
            if (index_substring_overlap[i] > max){
                max = index_substring_overlap[i];
            }
        }

        return max;
    }

    StringImportance(){
        int n;
        std::cin >> n >> k;

        for (int i = 0; i < n; i++){
            char c;
            std::cin >> c;
            problem_string.push_back(c);
        }
    }

    void mark_good_substrings(){
        for (int i = 0; i < problem_string.size(); i++){
            for (int j = i + 1; j < problem_string.size(); ++j) {
                if (problem_string[i] == 'X' && problem_string[j] == 'Z' && (j - i + 1) % 3 == 0){
                    update_map(i, j);
                }
            }
        }
    }

    int min_importance(){
        mark_good_substrings();

        int min = 2147483647;
        for (int i = 0; i < problem_string.size() - (k - 1); i++){
            int overlaps = max_overlaps(i, i + (k - 1));
            if (overlaps < min){
                min = overlaps;
            }
        }

        return min;
    }

    void test(){
        for (int i = 0; i < problem_string.size(); i++){
            std::cout << index_substring_overlap[i];
        }
    }
};

#endif //ZCOPRAC_STRINGIMPORTANCE_H
