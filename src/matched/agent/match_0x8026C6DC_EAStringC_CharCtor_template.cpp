// 0x8026C6DC template match (48B)
// EAStringC::EAStringC(char*) template — matches 12 functions:
// 0x8026c6dc, 0x80281ff8, 0x8028fc98, 0x80298e58, 0x802a1d80,
// 0x802a8b1c, 0x802aef34, 0x802b00a0, 0x802b933c, 0x802ba2a8, 0x802bb724

struct EAStringC {
    char* m_ptr;
    EAStringC(char* str);
};

extern void InitFromBuffer(EAStringC* self, char* str);

EAStringC::EAStringC(char* str) {
    InitFromBuffer(this, str);
}
