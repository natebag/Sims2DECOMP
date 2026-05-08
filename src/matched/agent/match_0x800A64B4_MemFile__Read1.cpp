// 0x800A64B4 MemFile::Read1(signed char*) (44B)

class MemFile {
public:
    void ReadBlock(void* p, int* size);
    void Read1(signed char* dst);
};

void MemFile::Read1(signed char* dst) {
    int size = 1;
    ReadBlock(dst, &size);
}
