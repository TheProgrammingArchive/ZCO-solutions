//
// Created by HP on 01-11-2022.
//

#ifndef ZCOPRAC_VACATION_H
#define ZCOPRAC_VACATION_H
#include <iostream>
#include <vector>

class Vacation{
private:
    int** grid = nullptr;
    int N_, M_ = 0;
    std::vector<std::vector<int>> case_vector_ = {};

public:

    void getInputs(){
        // N - Rows, M - Columns
        int N, M = 0;
        std::cin >> N >> M;
        this->N_ = N;
        this->M_ = M;

        grid = new int*[M];
        for (int k = 0; k < M; k++){
            grid[k] = new int[N]{0};
        }

        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                int val = 0;
                std::cin >> val;
                grid[j][i] = val;
            }
        }

        int cases = 0;
        std::cin >> cases;

        std::vector<std::vector<int>> case_vector = {};
        for (int i = 0; i < cases; i++){
            std::vector<int> l1 = {};
            int x, y, p, q = 0;
            std::cin >> x >> y >> p >> q;
            l1.push_back(x);
            l1.push_back(y);
            l1.push_back(p);
            l1.push_back(q);
            case_vector.push_back(l1);
        }
        this->case_vector_ = case_vector;
    }

    int getCost(int start_x, int start_y, int end_x, int end_y){
        if (start_x == end_x && start_y == end_y){
            return grid[start_x][start_y];
        }
        int cost = 1;
        for (int i = start_x; i <= end_x; i++){
            for (int j = start_y; j <= end_y; j++){
                cost = cost * grid[j][i];
            }
        }
        return cost;
    }

    void solve(){
        for (int i = 0; i < case_vector_.size(); i++){
            auto data = case_vector_[i];
            std::cout << getCost(data[0] - 1, data[1] - 1, data[2] - 1, data[3] - 1) << '\n';
        }
    }

    int** matrix(){
        return grid;
    }
};

#endif //ZCOPRAC_VACATION_H
