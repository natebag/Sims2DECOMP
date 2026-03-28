/* ObjectDataObjDefinition::AddRef(void) - 0x8015C778 - 20 bytes */

class ObjectDataObjDefinition {
public:
    char _pad[0x14];
    int m_refCount;

    int AddRef(void);
};

int ObjectDataObjDefinition::AddRef(void) {
    return ++m_refCount;
}
