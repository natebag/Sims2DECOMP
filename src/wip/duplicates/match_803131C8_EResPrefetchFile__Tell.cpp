// 0x803131C8 (8 bytes)
class EResPrefetchFile {
public:
    int Tell();
};

int EResPrefetchFile::Tell() {
    return *(int*)((char*)this + 0x40);
}
