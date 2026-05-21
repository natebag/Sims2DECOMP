// 0x803604BC ERTQuantize4D::NodeToIndex(ERTQ4Node*) (44B)
// ASMPROC_replace_insn: match="lwz 3,4104(3)" replacement="lwz 9,4104(3)"
// ASMPROC_replace_insn: match="subf 3,3,4" replacement="subf 9,9,4"
// ASMPROC_replace_insn: match="mullw 3,3,0" replacement="mullw 9,9,0"
// ASMPROC_replace_insn: match="rlwinm 3,3,29,16,31" replacement="rlwinm 3,9,29,16,31"

struct ERTQ4Node {
    char _pad[72];
};

class ERTQuantize4D {
    char _pad0[0x1008];
    ERTQ4Node* m_nodes;
public:
    unsigned short NodeToIndex(ERTQ4Node* node);
};

unsigned short ERTQuantize4D::NodeToIndex(ERTQ4Node* node) {
    if (!node) return 0;
    return (unsigned short)(node - m_nodes);
}
