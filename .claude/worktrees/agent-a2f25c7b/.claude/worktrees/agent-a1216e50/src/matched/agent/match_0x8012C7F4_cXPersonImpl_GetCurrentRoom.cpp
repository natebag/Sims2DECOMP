/* cXPersonImpl::GetCurrentRoom(void) const - 0x8012C7F4 - 8 bytes */
/* lhz r3, 0x41C(r3); blr */

class cXPersonImpl {
public:
    char _pad[0x41C];
    unsigned short m_currentRoom;

    unsigned short GetCurrentRoom(void) const;
};

unsigned short cXPersonImpl::GetCurrentRoom(void) const {
    return m_currentRoom;
}
