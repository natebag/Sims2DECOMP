// 0x802D7C48 (88B) ENgcSNFile::ENgcSNFile(void)
// SI ctor — EFile base + vtable @ +0x28 + MainHeap()->MallocAligned(2048, 32, 0, 0).

extern char vt_ENgcSNFile[];

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

class ENgcSNFile : public EFile {
public:
    char pad04_27[0x28 - 4];
    void* m_vt_at_28;
    char pad2C_33[0x34 - 0x2C];
    void* m_buffer_34;
    ENgcSNFile();
};

ENgcSNFile::ENgcSNFile() {
    m_vt_at_28 = (void*)vt_ENgcSNFile;
    m_buffer_34 = MainHeap()->MallocAligned(2048, 32, 0, 0);
}
