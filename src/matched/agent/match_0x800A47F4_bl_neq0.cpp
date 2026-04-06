// 0x800A47F4 (56b)
extern int someFunc(void*, void*, int, int);
int wrapper(void* a, void* b) {
    return someFunc(a, b, 0, -1) != 0;
}
