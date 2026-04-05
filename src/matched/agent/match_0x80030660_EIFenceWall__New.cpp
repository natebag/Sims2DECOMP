void *FW_Alloc(int);
void *FW_Init(void *);

void *EIFenceWall_New(void) {
    void *p = FW_Alloc(952);
    return FW_Init(p);
}
