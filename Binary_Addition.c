// Implement a function that adds two numbers together and returns their sum in binary. The conversion can be done before, or after the addition.

// The binary number returned should be a string.

// Examples:(Input1, Input2 --> Output (explanation)))

// 1, 1 --> "10" (1 + 1 = 2 in decimal or 10 in binary)
// 5, 9 --> "1110" (5 + 9 = 14 in decimal or 1110 in binary)
char *binary_add (unsigned a, unsigned b, char *binary)
{
     unsigned long long summ = (unsigned long long)a + b;
    int i = 0;
    if(summ == 0){
        binary[i] = '0';
        i++;
        binary[i] = '\0';
    }
    else{
        while(summ > 0){
            binary[i] = (summ % 2) + '0' ;
            summ = summ / 2;
            i++;
        }
        binary[i] = '\0';
        long long len = strlen(binary);
        char tmp[len];
        //переворачиваем строку
        for(int i = 0; i < len; i++){
            tmp[i] = binary[i];
        }
        int j = 0;
        for(int i = len - 1; i >= 0; i--){
            binary[j] = tmp[i];
            j++;
        }
        
        binary[j] = '\0';
    }
    printf("%s", binary);
  
    return binary;
}