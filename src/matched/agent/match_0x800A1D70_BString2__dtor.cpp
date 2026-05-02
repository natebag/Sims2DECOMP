// 0x800A1D70 (88B) BString2::~BString2(void)
// Variant L: SI deleting-dtor — conditional delete_ref (when MainHeap()->m_field_0 != 0) + MainHeap delete branch.

class EAHeap {
public:
    int m_field_0;
    void Free(void* p);
};
EAHeap* MainHeap();

void BString2_delete_ref(void* obj);
void __builtin_delete(void* p);

struct BString2 {
    char data[1];
    void dtor(int flag);
};

void BString2::dtor(int flag) {
    if (MainHeap()->m_field_0 != 0) {
        BString2_delete_ref(this);
    }
    if (flag & 1) {
        MainHeap()->Free(this);
    }
}
