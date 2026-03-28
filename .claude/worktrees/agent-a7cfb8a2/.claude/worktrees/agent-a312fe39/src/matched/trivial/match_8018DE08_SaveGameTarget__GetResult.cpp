// 0x8018DE08 (8 bytes)
class SaveGameTarget {
public:
    int GetResult();
};

int SaveGameTarget::GetResult() {
    return *(int*)((char*)this + 0x110);
}
