extern int AptCIH_GetType_st(void *);
extern int AptCIH_isInstOfType_st(void *);

struct AptCIH_st {
    char pad[0x60];
    int isStaticTextInst() const;
};

int AptCIH_st::isStaticTextInst() const
{
    int result = 0;
    if (AptCIH_GetType_st((void*)this) == 0x10) {
        result = !AptCIH_isInstOfType_st((void*)this);
    }
    return result;
}
