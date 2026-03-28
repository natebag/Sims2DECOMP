#include <stdio.h>
int main() {
    FILE* f1 = fopen("../extracted/files/DATA/fonts.arc", "rb");
    FILE* f2 = fopen("/f/coding/Decompiles/Sims 2/extracted/files/DATA/fonts.arc", "rb");
    printf("../ path: %s\n", f1 ? "OK" : "FAIL");
    printf("/f/ path: %s\n", f2 ? "OK" : "FAIL");
    if (f1) fclose(f1);
    if (f2) fclose(f2);
    return 0;
}
