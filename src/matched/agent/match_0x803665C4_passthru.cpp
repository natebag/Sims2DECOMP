/* BIG_locateentry at 0x803665C4 (32B) */
// 0x803665C4 (32 bytes)
extern int BIG_locateentryz(void*, char*, int*, int*, int*);
int BIG_locateentry(void* p, char* name, int* a, int* b, int* c) {
    return BIG_locateentryz(p, name, a, b, c);
}
