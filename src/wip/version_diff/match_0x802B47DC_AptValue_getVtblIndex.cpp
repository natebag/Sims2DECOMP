// AptValue::getVtblIndex(void) const
// Address: 0x802B47DC | Size: 12 bytes
// lwz r3, 0(r3); clrlwi r3, r3, 26; blr

class AptValue {
public:
    int m_refCountAndVtblIndex;  // at offset 0
    
    int getVtblIndex() const;
};

int AptValue::getVtblIndex() const {
    return m_refCountAndVtblIndex & 0x3F;  // Extract low 6 bits
}
