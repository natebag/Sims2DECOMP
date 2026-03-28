// 0x800AB540 (8 bytes)
class Behavior {
public:
    int GetNamespaceID();
};

int Behavior::GetNamespaceID() {
    return *(int*)((char*)(*(int*)((char*)this + 0x4)) + 0x4);
}
