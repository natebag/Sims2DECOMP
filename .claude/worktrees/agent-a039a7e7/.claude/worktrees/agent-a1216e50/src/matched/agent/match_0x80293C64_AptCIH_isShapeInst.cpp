extern int AptCIH_GetType(void *);
extern int AptCIH_isInstOfType(void *);

struct AptCIH {
    char pad[0x60];
    int isShapeInst() const;
};

int AptCIH::isShapeInst() const
{
    int result = 0;
    if (AptCIH_GetType((void*)this) == 0x0C) {
        result = !AptCIH_isInstOfType((void*)this);
    }
    return result;
}
