/* cXPersonImpl::GetPersonData(int) const - 0x8012C758 - 16 bytes */
/* rlwinm r4, r4, 1, 0, 30; addi r3, r3, 8; lhax r3, r3, r4; blr */
/* Returns this->m_personData[index] as signed halfword */

class cXPersonImpl {
public:
    char _pad[0x8];
    short m_personData[32];

    short GetPersonData(int index) const;
};

short cXPersonImpl::GetPersonData(int index) const {
    return m_personData[index];
}
