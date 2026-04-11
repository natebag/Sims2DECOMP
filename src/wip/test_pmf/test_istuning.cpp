// FLAGS: -fno-elide-constructors -msdata=eabi -G 8
// Test IsTuning with the OLD verify_match.sh default flags (pre c5a88985)

class ObjectDataBehaviorConstants {
public:
    short m_flags;  // at offset 4

    int IsTuning() const;
};

int ObjectDataBehaviorConstants::IsTuning() const {
    return (m_flags >> 15) & 1;
}
