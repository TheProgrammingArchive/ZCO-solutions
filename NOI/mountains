#include <iostream>
#include <vector>

class Penguinz0{
private:
    std::vector<int> mountains = {};

public:
    Penguinz0(){
        int n;
        std::cin >> n;
        for (int i = 0; i < n; i++){
            int x;
            std::cin >> x;
            mountains.push_back(x);
        }
    }

    int singularPermutation(int k) const{
        int left_places = 0;
        for (int i = 0; i < k; i++){
            if (mountains[i] < mountains[k]){
                left_places = left_places + 1;
            }
        }

        int right_places = 0;
        for (int i = k + 1; i < mountains.size(); i++){
            if (mountains[i] < mountains[k]){
                right_places = right_places + 1;
            }
        }

        return left_places * right_places;
    }

    int possiblePermutations() const{
        int total_ways = 0;
        for (int i = 1; i < mountains.size() - 1; i++){
            total_ways = total_ways + singularPermutation(i);
        }

        return total_ways;
    }
};
