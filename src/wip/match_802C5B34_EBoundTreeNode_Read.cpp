// 0x802C5B34 EBoundTreeNode::Read (92b)

class EBound3 {
public:
    float m_corners;
    float m_corners_004;
    float m_corners_008;
    float m_corners_00C;
};

struct EStream {
    char dummy[0x48];
};
struct EStorable {
    char dummy[4];
};

class EBoundTreeNode;

extern EStream& operator>>(EStream &s, EBound3 &b);
extern EStream& operator>>(EStream &s, EBoundTreeNode *&n);
extern EStream& operator>>(EStream &s, EStorable *&st);

extern short g_EBoundTreeNode_version;

class EBoundTreeNode {
    char pad[4];
    EBound3 m_bound;
    EBoundTreeNode *m_child;
    EStorable *m_storable1;
    EStorable *m_storable2;
public:
    void Read(EStream &stream);
};

void EBoundTreeNode::Read(EStream &stream) {
    if (g_EBoundTreeNode_version == 0) {
        stream >> m_bound;
        stream >> m_child;
        stream >> m_storable1;
        stream >> m_storable2;
    }
}
