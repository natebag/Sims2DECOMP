/* ObjectDataID::operator=(ObjectDataID &) - 0x8015BB1C - 24 bytes */
/* lwz r11, 0(r4); mr r9, r3; stw r11, 0(r9); lhz r0, 4(r4); sth r0, 4(r9); blr */

class ObjectDataID {
public:
    unsigned int m_id;
    unsigned short m_type;

    ObjectDataID& operator=(ObjectDataID &other);
};

ObjectDataID& ObjectDataID::operator=(ObjectDataID &other) {
    m_id = other.m_id;
    m_type = other.m_type;
    return *this;
}
