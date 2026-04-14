/* cXPersonImpl::SetMotive(int, float) - 0x801253D4 - 16 bytes */
/* rlwinm r4, r4, 2, 0, 29; addi r3, r3, 0xA8; stfsx f1, r3, r4; blr */

class cXPersonImpl {
public:
    char _pad[0xA8];
    float m_motives[16];

    void SetMotive(int index, float value);
};

void cXPersonImpl::SetMotive(int index, float value) {
    m_motives[index] = value;
}
