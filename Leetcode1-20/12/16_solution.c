
    int singleIntToRoman(int intput, char *output, char* romanChar);
    char* intToRoman(int num) {
        //3888 = "MMMDCCCLXXXVIII";
        //3 + 12 + 1 = 16
        char romanChar[10] = "**MDCLXVI";
        char *result = calloc(1, sizeof(char) * 16);
        char *pResult = result;
        int fillCount = 0;
        int singleNumber = 0;
        char *p = romanChar;
        int divisor = 1000;
        while (divisor >= 1) {
            singleNumber = num / divisor;
            if (singleNumber) {
                fillCount = singleIntToRoman(singleNumber, pResult, p);
                pResult += fillCount;
                num -= singleNumber * divisor;
            }
            p++;
            p++;
            divisor /= 10;
        }
        return result;
    }

    int singleIntToRoman(int intput, char *output, char* romanChar){
        //    printf("
  input(%d) output(%s) max(%c) middle(%c) min(%c)",intput, output, max, middle, min);
        char *p = output;
        char max = *romanChar++;
        char middle = *romanChar++;
        char min = *romanChar;
        switch (intput) {
            case 0:
                break;
            case 1:
                *p++ = min;
                break;
            case 2:
                *p++ = min;
                *p++ = min;
                break;
            case 3:
                *p++ = min;
                *p++ = min;
                *p++ = min;
                break;
            case 4:
                *p++ = min;
                *p++ = middle;
                break;
            case 5:
                *p++ = middle;
                break;
            case 6:
                *p++ = middle;
                *p++ = min;
                break;
            case 7:
                *p++ = middle;
                *p++ = min;
                *p++ = min;
                break;
            case 8:
                *p++ = middle;
                *p++ = min;
                *p++ = min;
                *p++ = min;
                break;
            case 9:
                *p++ = min;
                *p++ = max;
                break;
            default:
                break;
        }
        return (int)(p-output);
    }
