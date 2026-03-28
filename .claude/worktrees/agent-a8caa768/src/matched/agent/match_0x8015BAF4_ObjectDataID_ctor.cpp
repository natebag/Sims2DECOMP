/* ObjectDataID::ObjectDataID(unsigned int, unsigned short) - 0x8015BAF4 - 16 bytes */
/* mr r9, r3; stw r4, 0(r9); sth r5, 4(r9); blr */

class ObjectDataID {
public:
    unsigned int m_id;
    unsigned short m_type;

    ObjectDataID(unsigned int id, unsigned short type);
};

ObjectDataID::ObjectDataID(unsigned int id, unsigned short type) {
    m_id = id;
    m_type = type;
}
