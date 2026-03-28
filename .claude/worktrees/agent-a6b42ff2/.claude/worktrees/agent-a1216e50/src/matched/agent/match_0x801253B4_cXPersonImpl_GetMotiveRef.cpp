/* cXPersonImpl::GetMotiveRef(int) - 0x801253B4 - 16 bytes */
/* rlwinm r4, r4, 2, 0, 29; addi r4, r4, 0xA8; add r3, r3, r4; blr */
/* Returns pointer to this->m_motives[index] */

class cXPersonImpl {
public:
    char _pad[0xA8];
    float m_motives[16];

    float* GetMotiveRef(int index);
};

float* cXPersonImpl::GetMotiveRef(int index) {
    return &m_motives[index];
}
