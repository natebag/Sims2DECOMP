extern int AptCIH_GetType_m(void *);
extern int AptCIH_isInstOfType_m(void *);

struct AptCIH_m {
    char pad[0x60];
    int isMorphInst() const;
};

int AptCIH_m::isMorphInst() const
{
    int result = 0;
    if (AptCIH_GetType_m((void*)this) == 0x11) {
        result = !AptCIH_isInstOfType_m((void*)this);
    }
    return result;
}
