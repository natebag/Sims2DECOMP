// 0x802C70D0 (8 bytes)
class EFileSystem {
public:
    int HDDStatus();
};

int EFileSystem::HDDStatus() {
    return *(int*)((char*)this + 0x18);
}
