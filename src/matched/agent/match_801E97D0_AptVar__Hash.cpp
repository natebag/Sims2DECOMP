struct AptVar {
    static int Hash(char* str);
};

int AptVar::Hash(char* str) {
    int hash = 0;
    int i = 0;
    while (str[i] != 0) {
        hash += (signed char)str[i];
        i++;
    }
    return hash;
}
