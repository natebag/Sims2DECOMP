/* cXPersonImpl::GetOldMotiveRef(int) - 0x801253C4 - 16 bytes */
/* rlwinm r4, r4, 2, 0, 29; addi r4, r4, 0xE8; add r3, r3, r4; blr */

class cXPersonImpl {
public:
    char _pad[0xE8];
    float m_oldMotives[16];

    float* GetOldMotiveRef(int index);
};

float* cXPersonImpl::GetOldMotiveRef(int index) {
    return &m_oldMotives[index];
}
