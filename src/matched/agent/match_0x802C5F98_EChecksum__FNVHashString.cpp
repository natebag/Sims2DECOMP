// 0x802C5F98 (56B) EChecksum::FNVHashString(char*, unsigned int)
// FNV-1 hash: prime 0x01000193, hoisted outside loop (lis/ori before mullw).
// unsigned char c for null checks (lbz+cmpwi no extsb); (signed char)c for XOR (extsb+xor).
// Scheduler: extsb r0 before lbzu r9 (data dep on r9); xor deferred after lbzu/cmpwi.
// Static method — r3=str, r4=seed; mr r10,r3 then mr r3,r4 at entry.

struct EChecksum_FNV {
    static unsigned int FNVHashString(char* str, unsigned int hash);
};

unsigned int EChecksum_FNV::FNVHashString(char* str, unsigned int hash) {
    unsigned char c = (unsigned char)*str;
    if (!c) return hash;
    do {
        hash *= 0x01000193u;
        hash ^= (unsigned int)(signed char)c;
        c = (unsigned char)*++str;
    } while (c);
    return hash;
}
