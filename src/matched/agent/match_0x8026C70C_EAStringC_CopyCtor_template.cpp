// EAStringC::EAStringC(EAStringC&) template — matches 3 functions:
// 0x8026c70c, 0x80282028, 0x802a1db0

struct EAStringC {
    char* m_ptr;
    EAStringC(EAStringC& other);
};

EAStringC::EAStringC(EAStringC& other) {
    m_ptr = other.m_ptr;
    unsigned short* ref = (unsigned short*)m_ptr;
    ref[0] = ref[0] + 1;
}
