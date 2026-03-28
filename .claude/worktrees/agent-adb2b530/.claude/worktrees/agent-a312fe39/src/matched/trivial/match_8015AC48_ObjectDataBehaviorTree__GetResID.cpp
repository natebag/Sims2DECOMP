// 0x8015AC48 (8 bytes)
class ObjectDataBehaviorTree {
public:
    short GetResID();
};

short ObjectDataBehaviorTree::GetResID() {
    return *(short*)((char*)this + 0x4);
}
