/* cXPersonImpl::GetMotive(int) - 0x801253A4 - 16 bytes */
/* rlwinm r4, r4, 2, 0, 29; addi r3, r3, 0xA8; lfsx f0, r3, r4? no... */
/* Actually: 54 84 10 3A = rlwinm r4,r4,2,0,29; 38 63 00 A8 = addi r3,r3,0xA8; 7C 23 24 2E = lfsx f1,r3,r4; blr */
/* Returns this->m_motives[index] as float in f1 */

class cXPersonImpl {
public:
    char _pad[0xA8];
    float m_motives[16];

    float GetMotive(int index);
};

float cXPersonImpl::GetMotive(int index) {
    return m_motives[index];
}
