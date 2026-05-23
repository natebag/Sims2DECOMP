typedef unsigned char u8;
extern int VT_Careers[];
u8* getMainHeap_c(void);
u8* allocHeap_c(u8*, int, int, int);
u8* Careers_CreateInstance() {
    u8* heap = getMainHeap_c();
    u8* obj = allocHeap_c(heap, 32, 1, 0);
    *(int**)(obj) = VT_Careers;
    return obj;
}
