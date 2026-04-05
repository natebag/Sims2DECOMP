// AptValue::getRefCount(void) const
// Address: 0x802B47D0 | Size: 12 bytes
// lwz r3, 0(r3); rlwinm r3, r3, 18, 20, 31; blr

class AptValue {
public:
    int m_refCountAndFlags;  // at offset 0
    
    int getRefCount() const;
};

int AptValue::getRefCount() const {
    return (m_refCountAndFlags >> 14) & 0xFFF;  // Extract bits 14-25
}
