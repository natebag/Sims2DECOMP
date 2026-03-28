int AtoI_inner(char* str, int base);
int AtoI(char* str) {
    return AtoI_inner(str, 0);
}
