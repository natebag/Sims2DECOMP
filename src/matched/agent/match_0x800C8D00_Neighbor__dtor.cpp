// 0x800C8D00 (88B) Neighbor::~Neighbor(void)
// Variant L: helper(m_10) + conditional operator_delete_array(m_194) + MainHeap delete branch.

void Neighbor_helper(void* arg);
void Neighbor_op_delete_arr(void* p);

class EAHeap {
public:
    void Free(void* p);
};
EAHeap* MainHeap();

struct Neighbor {
    char pad_0_f[16];
    void* m_field_10;
    char pad_14_193[384];
    void* m_field_194;
    void dtor(int flag);
};

void Neighbor::dtor(int flag) {
    Neighbor_helper(m_field_10);
    if (m_field_194 != 0) {
        Neighbor_op_delete_arr(m_field_194);
    }
    if (flag & 1) {
        MainHeap()->Free(this);
    }
}
