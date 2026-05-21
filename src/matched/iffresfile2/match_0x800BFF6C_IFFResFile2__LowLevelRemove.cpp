// 0x800BFF6C (124B) IFFResFile2::LowLevelRemove(IFFResNode*)

struct IFFResNode {
    int m_0;
    char m_pad[8];
    void* m_C;
};

struct IFFResData {
    char m_pad0[4];
    void* m_4;
    int m_8;
};

extern "C" void* MainHeap__Fv();
extern "C" void Free__6EAHeapFPv(void* heap, void* ptr);

class IFFResFile2 {
public:
    int LowLevelRemove(IFFResNode* node);
    int InvalBlockHeader(int id);
};

int IFFResFile2::LowLevelRemove(IFFResNode* node) {
    int id = node->m_0;
    if (id != -1) {
        int rc = InvalBlockHeader(id);
        if (rc != 0) return rc;
    }
    IFFResData* data = (IFFResData*)node->m_C;
    if (data != 0) {
        if (data->m_8 != 0) {
            void* h1 = MainHeap__Fv();
            Free__6EAHeapFPv(h1, data->m_4);
        }
        void* h2 = MainHeap__Fv();
        Free__6EAHeapFPv(h2, data);
    }
    node->m_C = 0;
    return 0;
}
