/* ObjectDataID::ctor - 0x8015BAF4 (16 bytes) */

class ObjectDataID {
public:
    unsigned int m_id;
    unsigned short m_subId;
    ObjectDataID(unsigned int id, unsigned short subId);
};

ObjectDataID::ObjectDataID(unsigned int id, unsigned short subId) {
    m_id = id;
    m_subId = subId;
}
