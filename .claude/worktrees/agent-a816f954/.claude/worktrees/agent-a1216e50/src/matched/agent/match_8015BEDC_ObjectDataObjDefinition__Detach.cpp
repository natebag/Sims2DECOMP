/* ObjectDataObjDefinition::Detach - 0x8015BEDC (12 bytes) */

class ObjectDataObjDefinition {
public:
    char pad[0x1A];
    unsigned char m_attached;
    void Detach();
};

void ObjectDataObjDefinition::Detach() {
    m_attached = 0;
}
