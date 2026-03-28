// 0x800D8EE8 (8 bytes)
class NghResFile {
public:
    int GetStoreChecksum();
};

int NghResFile::GetStoreChecksum() {
    return *(int*)((char*)this + 0x18C);
}
