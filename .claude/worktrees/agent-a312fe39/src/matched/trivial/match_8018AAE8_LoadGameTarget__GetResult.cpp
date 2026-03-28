// 0x8018AAE8 (8 bytes)
class LoadGameTarget {
public:
    int GetResult();
};

int LoadGameTarget::GetResult() {
    return *(int*)((char*)this + 0x10C);
}
