/* ERBinary::GetTypeKey(void) const - 0x80368568 (12 bytes) */
// TU: e_rbinary

extern unsigned int ERBinary_typeInfo_key;

struct ERBinary {
    unsigned int GetTypeKey() const;
};

unsigned int ERBinary::GetTypeKey() const {
    return ERBinary_typeInfo_key;
}
