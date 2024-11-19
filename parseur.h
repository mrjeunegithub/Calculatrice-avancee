#ifndef __PARSEUR__
    #define __PARSEUR__
    #include <string>
    using namespace std;
    double parseExpression(const string& expr, size_t& pos );
    double parseTerm (const string& expr, size_t& pos );
    double parseFactor (const string& expr, size_t& pos );
    double parseNumber (const string& expr, size_t& pos );
    double parseFunction (const string& expr, size_t& pos );
    double parsePower (const string& expr, size_t& pos );
    void clear();
#endif