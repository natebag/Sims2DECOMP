// ObjectDataBehaviorConstants::IsTuning(void) const
// Address: 0x80159D88 | Size: 12 bytes
// lha r3, 4(r3); rlwinm r3, r3, 17, 31, 31; blr

class ObjectDataBehaviorConstants {
public:
    short m_flags;  // at offset 4
    
    int IsTuning() const;
};

int ObjectDataBehaviorConstants::IsTuning() const {
    return (m_flags >> 15) & 1;  // Extract bit 15
}
