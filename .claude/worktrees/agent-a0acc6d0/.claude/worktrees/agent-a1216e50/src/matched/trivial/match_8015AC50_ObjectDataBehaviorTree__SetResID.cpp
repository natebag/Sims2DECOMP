// 0x8015AC50 (8 bytes)
class ObjectDataBehaviorTree {
public:
    void SetResID(int p);
};

void ObjectDataBehaviorTree::SetResID(int p) {
    *(short*)((char*)this + 0x4) = (short)p;
}
