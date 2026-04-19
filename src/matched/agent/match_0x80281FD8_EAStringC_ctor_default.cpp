// 0x80281FD8 (32B) EAStringC::EAStringC(void) default constructor
// Assign this->rep to a shared empty-string rep and bump its refcount.

struct EAStringRep {
    short refcount;
    short _pad;
    int  _pad2[3];  // 16 bytes total, > SDA threshold
};

extern EAStringRep g_emptyStringRep;

class EAStringC {
public:
    EAStringRep* m_rep;
    EAStringC(void);
};

EAStringC::EAStringC(void) {
    m_rep = &g_emptyStringRep;
    g_emptyStringRep.refcount = g_emptyStringRep.refcount + 1;
}
