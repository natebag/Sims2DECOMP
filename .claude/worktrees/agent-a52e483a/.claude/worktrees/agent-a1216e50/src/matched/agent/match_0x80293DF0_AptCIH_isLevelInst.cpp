extern int AptCIH_GetType_l(void *);
extern int AptCIH_isInstOfType_l(void *);

struct AptCIH_l {
    char pad[0x60];
    int isLevelInst() const;
};

int AptCIH_l::isLevelInst() const
{
    int result = 0;
    if (AptCIH_GetType_l((void*)this) == 0x13) {
        result = !AptCIH_isInstOfType_l((void*)this);
    }
    return result;
}
