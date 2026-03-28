// 0x80159C0C (12 bytes)
// ObjectDataBehaviorConstants::CountValues(void) const
// lhz r3, 4(r3); rlwinm r3, r3, 0, 17, 31; blr
class ObjectDataBehaviorConstants {
public:
    int m_pad0;
    unsigned short m_data;
    int CountValues() const;
};

int ObjectDataBehaviorConstants::CountValues() const {
    return m_data & 0x7FFF;
}
