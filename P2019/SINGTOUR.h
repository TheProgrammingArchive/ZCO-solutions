//
// Created by HP on 18-10-2022.
//

#ifndef ZCOPRAC_SINGTOUR_H
#define ZCOPRAC_SINGTOUR_H
#include <iostream>
#include <vector>
#include <array>

class SingTour{
private:
    std::vector<std::vector<int>> ranges = {};

public:
    void getInputs(){
        int tc;
        std::cin >> tc;

        for (int i = 0; i < tc; i++){
            int singers;
            std::cin >> singers;

            for (int j = 0; j < singers; j++){
                int l, u;
                std::cin >> l >> u;
                ranges.push_back({l, u});
            }
        }
    }

    /**
     * returns 1 if r1 is a subset of r2 and 2 if r2 is a subset or r1 and 0 if both are distinct sets
     * THE SETS ARE ALWAYS DISTINCT
     */
    bool find(const std::vector<int>& r, int e){
        bool found = false;
        for (int i = r[0]; i <= r[1]; i++){
            if (e == i){
                found = true;
                break;
            }
        }
        return found;
    }

    int getSubset(const std::vector<int>& r1, const std::vector<int>& r2){
        int subset = 0;
        for (int i = r1[0]; i <= r1[1]; i++){
            subset = 1;
            if (!find(r2, i)){
                subset = 0;
                break;
            }
        }

        for (int i = r2[0]; i <= r2[1]; i++){
            subset = 2;
            if (!find(r1, i)){
                subset = 0;
                break;
            }
        }

        return subset;
    }

    int* getScores(){
        int *arr = new int[ranges.size()]{0};

        for (int i = 0; i < ranges.size(); i++){
            for (int j = i + 1; j < ranges.size(); j++){
                int subset = getSubset(ranges[i], ranges[j]);

                if (subset == 1){
                    arr[j] = arr[j] + 2;
                }
                else if(subset == 2){
                    arr[i] = arr[i] + 2;
                }
                else{
                    arr[i] = arr[i] + 1;
                    arr[j] = arr[j] + 1;
                }
            }
        }

        return arr;
    }
};

#endif //ZCOPRAC_SINGTOUR_H
