//
// Created by HP on 20-10-2022.
//

#ifndef ZCOPRAC_RAYS_H
#define ZCOPRAC_RAYS_H
#include <iostream>
#include <list>
#include <vector>

class Rays{
private:
    std::vector<int> reqs = {};

public:
    Rays(std::vector<int> among){
        this->reqs = among;
    }

    /**
     * -1 white, -2 black, 0 none
     */
    int** generateMatrix(int row, int col, std::vector<int> wcoords, std::vector<int> bcoords){
        int** matrix = new int*[row];
        for (int i = 0; i < row; i++){
            matrix[i] = new int[col]{0};
        }

        for (int i = 0; i < wcoords.size(); i=i+2){
            matrix[wcoords[i] - 1][wcoords[i+1] - 1] = -1;
        }

        for (int i = 0; i < bcoords.size(); i=i+2) {
            matrix[bcoords[i] - 1][bcoords[i+1] - 1] = -2;
        }

        return matrix;
    }

    int getdist(int ic, int j1, int** matrix){
        int wc = 0;
        int dist = 0;
        for (int i = j1; i < reqs[1]; i++){
            if (matrix[ic][i] == -2){
                dist = i - j1 + 1;
                break;
            }
            else if(matrix[ic][i] == -1){
                wc = wc + 1;
                if (wc >= 2){
                    dist = i - j1 + 1;
                    break;
                }
            }
            else{
                dist = dist + 1;
            }
        }
        return dist;
    }

    int getRayDistance(){
        std::vector<int> w = {};
        std::vector<int> b = {};
        for (int k = 4; k < static_cast<int>(reqs[2])*2 + 4; k++){
            w.push_back(static_cast<int>(reqs[k]));
        }

        for (int y = static_cast<int>(reqs[2])*2 + 4; y < reqs.size(); y++){
            b.push_back(static_cast<int>(reqs[y]));
        }

        int **matrix = generateMatrix(reqs[0], reqs[1], w, b);

        int sum = 0;
        for (int i = 0; i < reqs[0]; ++i){
            int wcount = 0;
            int dist = 0;
            int starts = 1;

            for (int j = 0; j < reqs[1]; ++j) {
                if (matrix[i][j] == -1 || matrix[i][j] == -2){
                    continue;
                }
                else{
                    sum = sum + getdist(i, j, matrix);
                }
            }
        }
        return sum;
    }
};

#endif //ZCOPRAC_RAYS_H
