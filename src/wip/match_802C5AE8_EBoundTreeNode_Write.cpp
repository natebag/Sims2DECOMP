// 0x802C5AE8 (76 bytes)
// 0x802C5AE8 EBoundTreeNode::Write (76b)

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

extern EStream& operator<<(EStream &s, EBound3 &b);
extern EStream& operator<<(EStream &s, EBoundTreeNode *n);
extern EStream& operator<<(EStream &s, EStorable *st);

class EBoundTreeNode {
    char pad[4];
    EBound3 m_bound;
    int m_field_1C;
    int m_field_20;
    int m_field_24;
public:
    void Write(EStream &s);
};

void EBoundTreeNode::Write(EStream &s) {
    s << this->m_bound;
    s << (EBoundTreeNode*)this->m_field_1C;
    s << (EStorable*)this->m_field_20;
    s << (EStorable*)this->m_field_24;
}
