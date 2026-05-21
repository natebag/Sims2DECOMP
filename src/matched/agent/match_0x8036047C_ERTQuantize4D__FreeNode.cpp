// 0x8036047C ERTQuantize4D::FreeNode(unsigned short) (32B)

struct ERTQ4Node {
    unsigned short m_next;
    char _pad[70];
};

class ERTQuantize4D {
    char _pad0[0x1006];
    unsigned short m_freeHead;
    ERTQ4Node* m_nodes;
public:
    void FreeNode(unsigned short index);
};

void ERTQuantize4D::FreeNode(unsigned short index) {
    if (!index) return;
    int offset = index * 72;
    ((ERTQ4Node*)((char*)m_nodes + offset))->m_next = m_freeHead;
    m_freeHead = index;
}
