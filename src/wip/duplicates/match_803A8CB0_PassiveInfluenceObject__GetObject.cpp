// 0x803A8CB0 (8 bytes)
class PassiveInfluenceObject {
public:
    int GetObject();
};

int PassiveInfluenceObject::GetObject() {
    return *(int*)((char*)this + 0x4);
}
