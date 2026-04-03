// 0x800A64E0 (8 bytes)
class MemFile {
public:
    int Writable();
};

int MemFile::Writable() {
    return *(int*)((char*)this + 0x10C);
}
