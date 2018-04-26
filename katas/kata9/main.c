#include <stdio.h>

int validUtf8(int* data, int dataSize) 
{
    unsigned int shifted;
    unsigned int shiftedData;
    int currentCharIndex;

    for (int dataIndex = 0; dataIndex < dataSize; dataIndex++)
    // Iterate over data array
    {
        shifted = data[dataIndex] >> 3u;    // Shift to right 3 times ot get the first 5 bits

        if (shifted <= 15)          // 0XXXX: 1 byte character
        {
            // Automatically valid
            continue;
        }
        else if (shifted <= 23)     // 10XXX: invalid byte
        {
            return 0;
        }
        else if (shifted <= 27)     // 110XX: 2 byte character
        {
            currentCharIndex = 1;
        }
        else if (shifted <= 29)     // 1110X: 3 byte character
        {
            currentCharIndex = 2;
        }
        else if (shifted <= 30)     // 11110: 4 byte character
        {
            currentCharIndex = 3;
        }
        else 
        {
            return 0;
        }

        for (int j = dataIndex + 1; j <= dataIndex + currentCharIndex; j++)
        // Iterate over the next currentCharIndex bytes
        {
            if (j >= dataSize)
            // If 'j' is out of bounds, the last byte was invalid
            {
                return 0;
            }
            shiftedData = data[j] >> 6u;        // Shift 6 times ot get the first 2 bits

            if (shiftedData != 2)               // The 1st tow bits must be 10.
                return 0;
        }
        
        dataIndex += currentCharIndex;          // Advance the index to the next set of bytes
    }

    return 1;
}

int main()
{
    int d[] = {240,162,138,147, 1, 197};
    int s = 6;
    printf("result %d\n", validUtf8(d, s));

    return 0;
}