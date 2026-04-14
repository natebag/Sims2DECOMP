void TArray_Init(void *);

struct TArray_Ctor {
    TArray_Ctor *ctor(void);
};

TArray_Ctor *TArray_Ctor::ctor(void) {
    TArray_Init(this);
    return this;
}

