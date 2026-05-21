// 0x802C5AE8 EBoundTreeNode::Write(EStream&) (76B)

struct EBound3 {
    float a, b, c, d, e, f;
};

struct EStream {
    char dummy[0x48];
};

struct EStorable {
    char dummy[4];
};

struct EBoundTreeNode {
    void* vtable;
    EBound3 m_bound;
    EBoundTreeNode* m_child;
    EStorable* m_storable1;
    EStorable* m_storable2;
    void Write(EStream& s);
};

extern EStream& operator<<(EStream& s, EBound3& b);
extern EStream& operator<<(EStream& s, EBoundTreeNode* n);
extern EStream& operator<<(EStream& s, EStorable* n);

void EBoundTreeNode::Write(EStream& s) {
    s << m_bound << m_child << m_storable1 << m_storable2;
}
