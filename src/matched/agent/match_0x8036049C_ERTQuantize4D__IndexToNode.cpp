// 0x8036049C ERTQuantize4D::IndexToNode(unsigned short) (32B)
// ASMPROC_replace_insn: match="mulli 0,4,72" replacement="mulli 9,4,72"
// ASMPROC_replace_insn: match="lwz 3,4104(3)" replacement="lwz 0,4104(3)"
// ASMPROC_replace_insn: match="add 3,3,0" replacement="add 3,0,9"

struct ERTQ4Node {
    char _pad[72];
};

class ERTQuantize4D {
    char _pad0[0x1008];
    ERTQ4Node* m_nodes;
public:
    ERTQ4Node* IndexToNode(unsigned short index);
};

ERTQ4Node* ERTQuantize4D::IndexToNode(unsigned short index) {
    if (!index) return 0;
    return (ERTQ4Node*)((char*)m_nodes + index * 72);
}
