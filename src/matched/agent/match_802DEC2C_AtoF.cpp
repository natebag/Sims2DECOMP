double AtoF_inner(char* str, int base);
double AtoF(char* str) {
    return AtoF_inner(str, 0);
}
