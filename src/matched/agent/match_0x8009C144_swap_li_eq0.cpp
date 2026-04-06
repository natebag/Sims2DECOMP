// 0x8009C144 (56b)
extern int someFunc(void*, void*, int);
int wrapper(void* a, void* b) {
    return someFunc(b, a, 0) == 0;
}
