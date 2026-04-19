// 0x802B4844 (32B) AptValue::setIsDefined(bool)
// Set bit 4 of flags-word at offset 0 via rlwimi (bool-normalize + insert).

struct AptValueFlags {
    unsigned int _b0        : 1;  // bit 0
    unsigned int gcMark     : 1;  // bit 1
    unsigned int _b2_b3     : 2;  // bits 2-3
    unsigned int isDefined  : 1;  // bit 4
    unsigned int _rest      : 27;
};

class AptValue {
public:
    AptValueFlags m_flags;
    void setIsDefined(bool v);
};

void AptValue::setIsDefined(bool v) {
    m_flags.isDefined = v ? 1 : 0;
}
