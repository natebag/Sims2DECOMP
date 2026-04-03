/* ObjectDataObjDefinition::AddRef(void) - 0x8015C778 - 20 bytes */

struct ObjectDataObjDefinition {
    char _pad[20];
    int m_refCount;

    int AddRef();
};

int ObjectDataObjDefinition::AddRef() {
    return ++m_refCount;
}
