// 0x802CFDCC ERTQuantize::FreeNode(unsigned short) (32B)
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
