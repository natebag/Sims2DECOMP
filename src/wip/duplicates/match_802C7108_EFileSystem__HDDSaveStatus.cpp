// 0x802C7108 (8 bytes)
class EFileSystem {
public:
    int HDDSaveStatus();
};

int EFileSystem::HDDSaveStatus() {
    return *(int*)((char*)this + 0x20);
}
