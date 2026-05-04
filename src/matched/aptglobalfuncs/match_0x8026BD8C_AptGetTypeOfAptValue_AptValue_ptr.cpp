typedef unsigned int uint;

extern char g_AptTypeStringBuffer;
extern char g_AptTypeFormat[];
extern int sprintf(char *, char *, ...);

struct AptValue {
    uint m_data;
};

char *AptGetTypeOfAptValue(AptValue *val) {
    sprintf(&g_AptTypeStringBuffer, g_AptTypeFormat, val->m_data & 0x7f);
    return &g_AptTypeStringBuffer;
}
