// 0x8030FAEC EREdithTreeSet::New(void) (48 B)
// PRAGMA_STUB: EREdithTreeSet::New(void)
void *New_Init(void);
void *New_Alloc(void *, int, int);
void *New_Construct(void *);

void *EREdithTreeSet_New(void) {
    void *r = New_Init();
    r = New_Alloc(r, 32, 0);
    return New_Construct(r);
}
