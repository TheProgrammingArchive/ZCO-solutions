//
// Created by HP on 28-12-2022.
//

#ifndef ZCOPRAC_MOVINGINTERVALS_H
#define ZCOPRAC_MOVINGINTERVALS_H
#include <iostream>
#include <vector>
#include <map>

class MovingIntervals{
private:
    int cakes, children, method;
    std::vector<std::pair<int, int>> ranges = {};
    std::map<int, int> place_children_map = {};
    std::vector<int> conflicts = {};

    // w = 1: add, w = 0 subtract
    void change_map(int i1, int j1, int w){
        for (int k = i1; k <= j1; k++){
            if (w == 1){
                place_children_map[k] += 1;
            }
            else{
                if (place_children_map[k] > 0){
                    place_children_map[k] -= 1;
                }
            }
        }
    }

    void generate_conflicts(){
        for (int i = 0; i < ranges.size(); i++){
            for (int j = i + 1; j < ranges.size(); j++){
                if (isConflictingIntersection(ranges[i], ranges[j])){
                    int cn;
                    if (ranges[i].second - ranges[i].first > ranges[j].second - ranges[j].first){
                        cn = j;
                    }
                    else{
                        cn = i;
                    }
                    conflicts.push_back(cn);
                }
            }
        }
    }

    bool isRegionFree(int i1, int j1){
        bool free = true;
        for (int i = i1; i <= j1; i++){
            if (place_children_map[i] > 0){
                free = false;
            }
        }
        return free;
    }

public:
    bool isConflictingIntersection(const std::pair<int, int>& p1, const std::pair<int, int>& p2){
        int upper, tl;
        bool conflict = false;

        if (p1.first < p2.first){
            upper = p1.second;
            tl = p2.first;
        }
        else if (p1.first > p2.second){
            upper = p2.second;
            tl = p1.first;
        }
        else{
            return true;
        }

        for (int i = std::min(p1.first, p2.first); i <= upper; i++){
            if (i == tl){
                conflict = true;
                break;
            }
        }
        return conflict;
    }

    MovingIntervals(){
        std::cin >> cakes >> children >> method;

        for (int i = 0; i < children; i++){
            int s, e;
            std::cin >> s >> e;
            ranges.push_back({s, e});
        }
    }

    std::string solve() {
        if (method == 0) {
            for (int i = 0; i < ranges.size(); i++) {
                for (int j = i + 1; j < ranges.size(); j++) {
                    if (isConflictingIntersection(ranges[i], ranges[j])) {
                        return "Bad";
                    }
                }
            }
            return "Good";
        }

        else {
            for (auto x : ranges) {
                change_map(x.first, x.second, 1);
            }
            generate_conflicts();

            for (int conflict : conflicts){
                int cakes_req = ranges[conflict].second - ranges[conflict].first + 1;
                change_map(ranges[conflict].first, ranges[conflict].second, 0);

                // Trying to move child preference
                bool possible = false;
                for (int k = 1; k <= cakes - (cakes_req - 1); k++){
                    if (isRegionFree(k, k + (cakes_req - 1))){
                        possible = true;
                        break;
                    }
                }
                if (possible){
                    return "Good";
                }
            }
            return "Bad";
        }
    }

    void test(){
        for (int i = 1; i <= cakes; i++){
            std::cout << place_children_map[i];
        }
        std::cout << std::endl;

        for (int k : conflicts){
            std::cout << k << ' ';
        }
    }
};

#endif //ZCOPRAC_MOVINGINTERVALS_H
