/* ERBinary::GetReadVersion(void) - 0x8036858C (12 bytes) */
// TU: e_rbinary

extern unsigned int ERBinary_readVersion;

struct ERBinary {
    static unsigned int GetReadVersion();
};

unsigned int ERBinary::GetReadVersion() {
    return ERBinary_readVersion;
}
