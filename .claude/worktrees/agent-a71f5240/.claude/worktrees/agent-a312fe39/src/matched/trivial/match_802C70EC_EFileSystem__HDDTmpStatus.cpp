// 0x802C70EC (8 bytes)
class EFileSystem {
public:
    int HDDTmpStatus();
};

int EFileSystem::HDDTmpStatus() {
    return *(int*)((char*)this + 0x1C);
}
