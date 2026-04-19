// 0x802B4864 (32B) AptValue::setGCMark(bool)
// Set bit 1 of flags-word via rlwimi.

struct AptValueFlags {
    unsigned int _b0        : 1;
    unsigned int gcMark     : 1;
    unsigned int _rest      : 30;
};

class AptValue {
public:
    AptValueFlags m_flags;
    void setGCMark(bool v);
};

void AptValue::setGCMark(bool v) {
    m_flags.gcMark = v ? 1 : 0;
}
