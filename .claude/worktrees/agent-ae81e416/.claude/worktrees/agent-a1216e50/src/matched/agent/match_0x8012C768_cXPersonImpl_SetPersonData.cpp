/* cXPersonImpl::SetPersonData(int, short) - 0x8012C768 - 16 bytes */
/* rlwinm r4, r4, 1, 0, 30; addi r3, r3, 8; sthx r5, r3, r4; blr */

class cXPersonImpl {
public:
    char _pad[0x8];
    short m_personData[32];

    void SetPersonData(int index, short value);
};

void cXPersonImpl::SetPersonData(int index, short value) {
    m_personData[index] = value;
}
