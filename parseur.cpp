#include <iostream>
#include <string>
#include <cmath>
#include "parseur.h"

using namespace std;

double parseExpression(const string& expr, size_t& pos ){
    double result = parseTerm(expr, pos);
    while(pos < expr.length()){
        if (expr[pos] == '+'){
            
            pos++;
            result += parseTerm(expr, pos);
        }else if(expr[pos] == '-'){
            
            pos++;
            result -= parseTerm(expr, pos);
        }else{
            break;
        }
    }
    return result;
}

double parseTerm(const string& expr, size_t& pos ){
    double result = parsePower(expr, pos);
    while (pos < expr.length()){
        if(expr[pos] == '*'){
           
            pos++;
            result *= parsePower(expr, pos);
        }else if(expr[pos] == '/'){
            
            pos++;
            result /= parsePower(expr, pos);
        }else{
            break;
        }
    }
    return result;
}

double parsePower (const string& expr, size_t& pos ){
    double base = parseFactor(expr, pos);
    while(pos < expr.length() && expr[pos] == '^'){
        
        pos++;
        double exponent = parseFactor(expr, pos);
        base = pow(base, exponent);
    }
    return base;
}

double parseFactor(const string& expr, size_t& pos ){
    if (pos < expr.length() && expr[pos] == '('){
       
        pos++;
        double result = parseExpression(expr, pos);
        pos++;
        return result;
    }else if(isalpha(expr[pos])){
        
        return parseFunction(expr, pos);
    }else{
       
        return parseNumber(expr, pos);
    }
}

double parseFunction(const string& expr, size_t& pos ){
    if (expr.substr(pos, 3) == "sin"){
        pos += 3;
        pos++;
        double result = parseExpression(expr, pos);
        pos++;
        return sin(result);
    }else if(expr.substr(pos, 3) == "cos"){
       
        pos += 3;
        pos++;
        double result = parseExpression(expr, pos);
        pos++;
        return cos(result);
    }else if(expr.substr(pos, 3) == "tan"){
        pos += 3;
        pos++;
        double result = parseExpression(expr, pos);
        pos++;
        return tan(result);
    }else if(expr.substr(pos, 2) == "ln"){
        
        pos += 2;
        pos++;
        double result = parseExpression(expr, pos);
        pos++;
        return log(result);
    }else if(expr.substr(pos, 3) == "log"){
        pos += 3;
        pos++;
        double result = parseExpression(expr, pos);
        pos++;
        return log10(result);
    }else if(expr.substr(pos, 3) == "exp"){
        
        pos += 3;
        pos++;
        double result = parseExpression(expr, pos);
        pos++;
        return exp(result);
    }
    return 0;
}

double parseNumber(const string& expr, size_t& pos){
    size_t start = pos;
    while(pos < expr.length() && (isdigit(expr[pos]) || expr[pos] == '.' )){
        pos++;
    }
    return atof(expr.substr(start, pos - start).c_str());
}

void clear(){
    #ifdef _WIN32
        system("CLS");
    #else
        system("clear");
    #endif
}



