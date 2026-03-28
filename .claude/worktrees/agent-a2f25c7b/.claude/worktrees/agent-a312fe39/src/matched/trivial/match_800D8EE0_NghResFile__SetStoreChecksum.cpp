// 0x800D8EE0 (8 bytes)
class NghResFile {
public:
    void SetStoreChecksum(int p);
};

void NghResFile::SetStoreChecksum(int p) {
    *(int*)((char*)this + 0x18C) = p;
}
