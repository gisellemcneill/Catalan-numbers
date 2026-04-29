//
// Created by Giselle McNeill on 3/4/26.
//

#include <iostream>
using namespace std;

//recursive catalan functions
int catalan(int n) {

    if (n == 0) { //base case C(0) = 1
        return 1;
    }

    int sum = 0;

    //iterate until i = 0 -> n-1
        for (int i = 0; i <= n - 1; i++) {
            sum += catalan(i) * catalan(n- i - 1);//recursive call
        }

    return sum;
}

//argc: the number of items stored in the array
//ex: ./catalan 10
//argc = 2. argv[0] = ./catalan and argv[1] = 10
//argv[]: pointers that point to items in an array
int main(int argc, char* argv[]) {

    //make sure input is not too many inputs or missing a number
    if (argc != 2) {
        std::cerr << "Correct Usage: ./catalan <n>" << std::endl;
        return 1;
    }

    //atoi = skip whitespace and turn "number" into a int
    int n = atoi(argv[1]);

    if (n < 0) {
        std::cerr << "Error: n must be non-negative";
        return 1;
    }

    int result = catalan(n);

    std::cout<< result << std::endl;

    return 0;
}
