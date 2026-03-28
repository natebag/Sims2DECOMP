// 0x8015CA24 (8 bytes)
class ObjectDataObjDefinition {
public:
    short GetResID();
};

short ObjectDataObjDefinition::GetResID() {
    return *(short*)((char*)this + 0x18);
}
