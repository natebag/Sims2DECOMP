// FLAGS: -fno-schedule-insns -fno-elide-constructors
// ASMPROC_swap_adj: a=stw b=li which=first
// ASMPROC_swap_adj: a=mr b=mr which=first

struct EBitArray {
    void copy_ctor();
};

void EBitArray::copy_ctor() {
}
