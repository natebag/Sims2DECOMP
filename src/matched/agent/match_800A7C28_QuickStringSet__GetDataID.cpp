/* QuickStringSet::GetDataID(void) at 0x800A7C28 (56B) */
// FLAGS: -O2 -msdata=eabi -G 8

struct ObjectDataID {
    unsigned int m_id;
    unsigned short m_type;

    ObjectDataID(unsigned int id, unsigned short type);
    ObjectDataID(const ObjectDataID& o);
};

class QuickStringSet {
public:
    char _pad[0x18];

    ObjectDataID GetDataID() const;
};

ObjectDataID QuickStringSet::GetDataID() const {
    return ObjectDataID((unsigned int)-1, (unsigned short)0);
}
