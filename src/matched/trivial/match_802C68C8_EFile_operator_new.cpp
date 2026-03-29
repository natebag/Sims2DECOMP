// 0x802C68C8 (8 bytes)
class EFile {
public:
    void* operator new(unsigned int size, void* ptr);
};

void* EFile::operator new(unsigned int size, void* ptr) {
    return ptr;
}
