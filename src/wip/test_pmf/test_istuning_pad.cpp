// FLAGS: -fno-elide-constructors
// Try to match IsTuning with padding for offset 4 + various bit-extract expressions

class ObjectDataBehaviorConstants {
public:
    char pad[4];
    short m_flags;

    int IsTuning() const;
};

int ObjectDataBehaviorConstants::IsTuning() const {
    return ((unsigned short)m_flags) >> 15;
}
