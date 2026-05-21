// 0x802CFDCC ERTQuantize::FreeNode(unsigned short) (32B)
//
// Free-list push: inserts `idx` at the head of the freelist by writing the
// previous head to `nodes[idx]` and setting head = idx.
//
// WALL CLASS: sthx operand-order swap (commutative base/index)
//   sthx rS, rA, rB stores rS to (rA + rB). The (rA, rB) pair is
//   semantically commutative — same memory address — but the byte encoding
//   distinguishes the two register positions. DOL emits `sthx 0,9,11`;
//   GCC emits `sthx 0,11,9`. One swap_operands directive fixes it.
//
// ASMPROC_swap_operands: match="sthx 0,11,9" pos=1,2

class ERTQuantize {
public:
    void FreeNode(unsigned short idx);
};

void ERTQuantize::FreeNode(unsigned short idx) {
    if (idx == 0) return;
    unsigned short head = *(unsigned short*)((char*)this + 4234);
    char* nodes = *(char**)((char*)this + 4236);
    *(unsigned short*)(nodes + idx * 56) = head;
    *(unsigned short*)((char*)this + 4234) = idx;
}
