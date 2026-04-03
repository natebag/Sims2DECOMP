// 0x8015CA2C (8 bytes)
class ObjectDataObjDefinition {
public:
    void SetResID(int p);
};

void ObjectDataObjDefinition::SetResID(int p) {
    *(short*)((char*)this + 0x18) = (short)p;
}
