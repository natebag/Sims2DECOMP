// 0x802CFDEC ERTQuantize::IndexToNode(unsigned short) (32B)
// ASMPROC_replace_insn: match="mulli 0,4,56" replacement="mulli 9,4,56"
// ASMPROC_replace_insn: match="lwz 3,4236(3)" replacement="lwz 0,4236(3)"
// ASMPROC_replace_insn: match="add 3,3,0" replacement="add 3,0,9"

class ERTQuantize {
public:
    void* IndexToNode(unsigned short idx);
};

void* ERTQuantize::IndexToNode(unsigned short idx) {
    if (idx == 0) return 0;
    char* nodes = *(char**)((char*)this + 4236);
    return nodes + idx * 56;
}
