// 0x8030F528 EREdithTreeSet::Deallocate(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lis 30,-32693; lwz 4,0x14(31); addi 3,30,27900; li 29,0; bl _s8030F528_0; lwz 4,0x1c(31); stw 29,0x14(31); cmpwi 4,0; beq 0f; addi 3,30,27900; bl _s8030F528_1; stw 29,0x1c(31); 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s8030F528_0();
extern "C" void _s8030F528_1();

struct EREdithTreeSet {
    void Deallocate();
};

void EREdithTreeSet::Deallocate() {
}
