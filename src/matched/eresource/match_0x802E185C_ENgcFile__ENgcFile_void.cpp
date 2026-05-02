// 0x802E185C (88B) ENgcFile::ENgcFile(void)
// SI ctor — EFile base + vtable @ +0x28 + MainHeap()->MallocAligned(4096, 2048, 0, 0) → field +0x6C.

extern char vt_ENgcFile[];

class EFile {
public:
    void* m_base_vt;
    EFile();
};

class EAHeap {
public:
    void* MallocAligned(unsigned int size, unsigned int align, unsigned int flag, int idx);
};

extern EAHeap* MainHeap();

class ENgcFile : public EFile {
public:
    char pad04_27[0x28 - 4];
    void* m_vt_at_28;
    char pad2C_6B[0x6C - 0x2C];
    void* m_buffer_6C;
    ENgcFile();
};

ENgcFile::ENgcFile() {
    m_vt_at_28 = (void*)vt_ENgcFile;
    m_buffer_6C = MainHeap()->MallocAligned(4096, 2048, 0, 0);
}
