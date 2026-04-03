// 0x80313338 (8 bytes)
class EResPrefetchFile {
public:
    int GetResMan();
};

int EResPrefetchFile::GetResMan() {
    return *(int*)((char*)this + 0x2C);
}
