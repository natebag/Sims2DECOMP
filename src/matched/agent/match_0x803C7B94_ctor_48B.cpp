void TA_Init(void *);

struct TA_Ctor {
    TA_Ctor *ctor(void);
};

TA_Ctor *TA_Ctor::ctor(void) {
    TA_Init(this);
    return this;
}
