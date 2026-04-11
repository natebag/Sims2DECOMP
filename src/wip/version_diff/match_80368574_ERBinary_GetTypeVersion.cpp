/* ERBinary::GetTypeVersion(void) const - 0x80368574 (12 bytes) */
// TU: e_rbinary

extern unsigned int ERBinary_typeInfo_version;

struct ERBinary {
    unsigned int GetTypeVersion() const;
};

unsigned int ERBinary::GetTypeVersion() const {
    return ERBinary_typeInfo_version;
}
