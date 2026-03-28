extern int AptCIH_GetType_t(void *);
extern int AptCIH_isInstOfType_t(void *);

struct AptCIH_t {
    char pad[0x60];
    int isTextInst() const;
};

int AptCIH_t::isTextInst() const
{
    int result = 0;
    if (AptCIH_GetType_t((void*)this) == 0x0F) {
        result = !AptCIH_isInstOfType_t((void*)this);
    }
    return result;
}
