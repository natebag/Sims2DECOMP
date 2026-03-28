// 0x80022684 (8 bytes) �� mr r3, r5; blr
// Returns the 'size' parameter (r5 -> r3)

class EDummyFile {
public:
    unsigned int Read(void* buf, unsigned int size);
};

unsigned int EDummyFile::Read(void* buf, unsigned int size) {
    return size;
}
