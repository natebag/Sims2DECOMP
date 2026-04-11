void *EIF_Alloc(int);
void *EIF_Init(void *);

void *EIFloor_New(void) {
    void *p = EIF_Alloc(304);
    return EIF_Init(p);
}
