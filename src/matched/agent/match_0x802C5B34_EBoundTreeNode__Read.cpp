// 0x802C5B34 EBoundTreeNode::Read(EStream&) (92B)

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
    void Read(EStream& stream);
};

extern EStream& operator>>(EStream& s, EBound3& b);
extern EStream& operator>>(EStream& s, EBoundTreeNode*& n);
extern EStream& operator>>(EStream& s, EStorable*& n);

extern char g_EBoundTreeNode_version[16];

void EBoundTreeNode::Read(EStream& stream) {
    if (*(unsigned short*)g_EBoundTreeNode_version == 0) {
        stream >> m_bound >> m_child >> m_storable1 >> m_storable2;
    }
}
