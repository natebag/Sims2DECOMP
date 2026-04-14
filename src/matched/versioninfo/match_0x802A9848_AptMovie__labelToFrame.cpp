// 0x802A9848 AptMovie::labelToFrame (56b)

struct EAStringC;
struct AptValue;
struct AptNativeHash {
    AptValue *Lookup(EAStringC *key);
};

struct AptValue {
    int toInteger(void);
};

struct AptMovie {
    char _pad[8];
    AptNativeHash *m_labels;
};

int AptMovie__labelToFrame(AptMovie *self, EAStringC *label) {
    AptValue *val = self->m_labels->Lookup(label);
    if (!val) return -1;
    return val->toInteger();
}
