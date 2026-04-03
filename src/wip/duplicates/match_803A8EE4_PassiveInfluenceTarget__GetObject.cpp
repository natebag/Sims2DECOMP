// 0x803A8EE4 (8 bytes)
class PassiveInfluenceTarget {
public:
    int GetObject();
};

int PassiveInfluenceTarget::GetObject() {
    return *(int*)((char*)this + 0x4);
}
