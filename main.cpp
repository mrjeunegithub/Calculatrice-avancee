#include <iostream>
#include <string>
#include <cmath>

#include "parseur.h"

using namespace std;

int main(int argc, char** argv){
    clear();
    int choice = 1;
    string input;
    size_t pos = 0;

    std::cout <<"Binvenue dans cette calculatrice à expression litterale" <<std::endl;
    
    cout<<"entrer votre expression mathematique: \033[33m";
    getline(cin,input);
    cout<<"\033[0m"<<endl;
    double output = parseExpression(input, pos);
    cout << "\033[32mResultat\033[0m \t: \033[31m" << output <<"\033[0m"<< endl;
    cout<<""<<endl;
    

    return 0;
}

