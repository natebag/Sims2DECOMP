// TArray<ENDummyPoint, TArrayDefaultAllocator>::Init(void)
// Address: 0x80266E54 | Size: 60 bytes
// SN compiler: doesn't save LR itself, relies on caller's LR save

extern int gCurrentAllocContext;

extern void ENDummyPoint_AllocInit(void);
extern void ENDummyPoint_AllocFinish(void);

int TArray_ENDummyPoint_Init(int self) {
    int old = gCurrentAllocContext;
    ENDummyPoint_AllocInit();
    gCurrentAllocContext = self;
    ENDummyPoint_AllocFinish();
    return old;
}
