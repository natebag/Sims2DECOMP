// 0x800AB54C (8 bytes)
class Behavior {
public:
    int GetSemiGlobalNamespaceID();
};

int Behavior::GetSemiGlobalNamespaceID() {
    return *(int*)((char*)(*(int*)((char*)this + 0x4)) + 0x8);
}
