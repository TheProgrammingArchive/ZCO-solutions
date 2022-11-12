//
// Created by HP on 29-10-2022.
//

#ifndef ZCOPRAC_PALINDROME_H
#define ZCOPRAC_PALINDROME_H

class Palindrome{
private:
    std::vector<int> series = {};
    int size = series.size();

public:
    void getInput(){
        series = {34, 45,34,66,99,34,99,99,34,34,99};
    }

    bool isPalindrome(int s, int e){
        bool pal = false;

        std::vector<int> cmp = {};
        for (int i = s; i <= e; i++){
            cmp.push_back(series[i]);
        }

        std::vector<int> k = cmp;
        std::reverse(cmp.begin(), cmp.end());

        if (k == cmp){
            pal = true;
        }
        return pal;
    }

    int getPairs(){
        int cs = 0;
        int ci = series.size();

        for (int i = 0; i < series.size(); i++){
            for (int j = i; j < series.size(); ++j) {
                if (abs(i - j) == 0) {
                    continue;
                }

                else{
                    if (isPalindrome(i, j)){
                        cs = cs + 1;
                        ci = ci - (abs(j - i) + 1);

                        for (int k = i; k <= j; k++){
                            std::reverse(series.begin(), series.end());
                            series.pop_back();
                            std::reverse(series.begin(), series.end());
                        }

                        i = 0;
                    }
                }
            }
        }

        return ci + cs;
    }
};

#endif //ZCOPRAC_PALINDROME_H
