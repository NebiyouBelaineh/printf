int _printint(int num) {
    int rev = 0;
    char str[20]; 

    
    if (num < 0) {
        putchar('-');
        num = -num;
    }

    
    int i = 0;
    do {
        str[i++] = num % 10 + '0';
        num /= 10;
    } while (num != 0);

    
    while (i > 0) {
        putchar(str[--i]);
    }

    return i; 
}
