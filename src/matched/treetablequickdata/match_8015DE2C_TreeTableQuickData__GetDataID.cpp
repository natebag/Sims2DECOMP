/* TreeTableQuickData::GetDataID(void) const - 0x8015DE2C - 52 bytes */
/* Returns m_dataID (at offset 0x18) by copy construction */

class ObjectDataID {
public:
    ObjectDataID(const ObjectDataID& other);
    unsigned int m_typeHash;
    unsigned short m_index;
};

class TreeTableQuickData {
public:
    char _pad[0x18];
    ObjectDataID m_dataID;

    ObjectDataID GetDataID() const;
};

ObjectDataID TreeTableQuickData::GetDataID() const {
    return m_dataID;
}