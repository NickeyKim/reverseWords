//
//  main.c
//  reverseWords
//
//  Created by NAKHOE KIM on 1/16/16.
//  Copyright © 2016 NAKHOE KIM. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool reverseWords(char str[])
{
    char *buffer;
    int slen, tokenReadPos, wordReadPos, wordEnd, writePos =0;
    
    slen = (int)strlen(str);
    tokenReadPos = slen-1;
    buffer = (char *)malloc(slen+1);
    
    if (!buffer)
        return false;
    while ( tokenReadPos >=0){
        if(str[tokenReadPos] == ' '){
            buffer[writePos] = str[tokenReadPos];
            writePos++;
            tokenReadPos--;
        }
        else{
            wordEnd = tokenReadPos;
            while ( tokenReadPos >= 0 && str[tokenReadPos] != ' '){
                tokenReadPos--;
            }//tokenReadPos is at the space which infront of the word
            wordReadPos = tokenReadPos +1;
            while (wordReadPos <= wordEnd){
                buffer[writePos] = str[wordReadPos];
                writePos++;
                wordReadPos++;
            }
        }
    }
    buffer[writePos++] = '\0';
    strlcpy(str, buffer, slen+1);
    free(buffer);
    return true;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    char newstr[] = "piglet quantum";
    printf("old: %s\n", newstr);
    reverseWords(newstr);
    printf("new: %s\n", newstr);
    return 0;
}
