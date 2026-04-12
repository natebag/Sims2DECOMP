// 0x80293FA8 AptCIH::SetInCtor (16b)
typedef unsigned int uint;

struct AptCIH {
    char _pad[92];
    struct {
        uint _hi : 21;
        uint inCtor : 1;
        uint _lo : 10;
    } m_flags;
};

void AptCIH__SetInCtor(AptCIH *self, uint val) {
    self->m_flags.inCtor = val;
}
