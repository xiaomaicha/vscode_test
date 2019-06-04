#include <stdio.h>
#include <assert.h>
#include <string.h>

void print(const char* arg){
    assert(arg != NULL);
    int len = strlen(arg);
    char *buf = new char[len + 1]; 
    snprintf(buf, sizeof(buf), "%s", arg);

    assert(strcmp(arg, "test") != 0); 
    puts(buf);

    delete [] buf;
}

int main(int argc, char *argv[]){
    if (argc == 2){ 
        print(argv[1]); 
    }   
    
    return 0;   
}