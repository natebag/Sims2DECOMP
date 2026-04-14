// 0x8039CB14 TArray<EVec3>::TArray(TArray&) (64B)

extern void TArray_Init(void*);

struct TArray {
    TArray& operator=(TArray&);
    TArray(TArray&);
};

TArray::TArray(TArray& other) {
    TArray_Init(this);
    operator=(other);
}
