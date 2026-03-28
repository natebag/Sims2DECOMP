// 0x802C7118 (8 bytes)
class EFileSystem {
public:
    int GetDefaultType();
};

int EFileSystem::GetDefaultType() {
    return *(int*)((char*)this + 0x10);
}
