// FLAGS: -fno-elide-constructors
// 0x801E97D0 match_801E97D0_AptVar__Hash (56B)
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
