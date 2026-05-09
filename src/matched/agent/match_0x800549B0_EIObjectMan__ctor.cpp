// EIObjectMan::EIObjectMan(EHouse*) at 0x800549B0 (68 bytes)
// Standard ctor: zero field0, default-construct m_tree at +4, store m_pHouse at +16.

class ERedBlackTree {
public:
    ERedBlackTree();
    char _pad[12];
};

class EHouse;

class EIObjectMan {
public:
    int m_field0;           // offset 0
    ERedBlackTree m_tree;   // offset 4 (assumed 12 bytes by member-init order)
    EHouse* m_pHouse;       // offset 16
    EIObjectMan(EHouse* pHouse);
};

EIObjectMan::EIObjectMan(EHouse* pHouse)
    : m_field0(0)
    , m_pHouse(pHouse) {
}
