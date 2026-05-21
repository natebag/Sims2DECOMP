// 0x802CFDEC ERTQuantize::IndexToNode(unsigned short) (32B)
//
// Free-list pop counterpart: returns nodes_ptr + idx*56 if idx is non-zero,
// else returns 0.
//
// WALL CLASS: register-allocation 3-way swap
//   DOL: mulli r9,...; lwz r0,...; add r3,r0,r9
//   GCC: mulli r0,...; lwz r3,...; add r3,r3,r0
//   GCC reuses r3 for the lwz (clobbering this) which forces add operand
//   order differently. Three replace_insn rewrites force DOL's r9/r0/r3
//   assignment.
//
// Recipe (3 replace_insn, no new mutator):
//   1. mulli 0,4,56  -> mulli 9,4,56
//   2. lwz 3,4236(3) -> lwz 0,4236(3)
//   3. add 3,3,0     -> add 3,0,9
//
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
