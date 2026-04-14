// 0x8002268C (8 bytes) — mr r3, r5; blr
// Returns the 'size' parameter (r5 -> r3)

class EDummyFile {
public:
    unsigned int Write(void* buf, unsigned int size);
};

unsigned int EDummyFile::Write(void* buf, unsigned int size) {
    return size;
}
