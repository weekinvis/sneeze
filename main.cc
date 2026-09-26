// pt. 1 lexer
#include "lexer.h"
#include "file.h"
#define pass void

int main(const int argc, const char * argv[])
{
    (pass)argv;
    (pass)argc;
    
    for(std::string s : readfile("teste.cow"))
    {
        tokenize(s);
    }


    return 0;
}
