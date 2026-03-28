// 0x8015CA3C (8 bytes)
class ObjectDataObjDefinition {
public:
    int GetData();
};

int ObjectDataObjDefinition::GetData() {
    return *(int*)((char*)this + 0x1C);
}
