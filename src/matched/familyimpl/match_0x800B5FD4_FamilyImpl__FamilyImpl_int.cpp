// 0x800B5FD4 FamilyImpl::FamilyImpl(int) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 30,3; lis 9,-32698; addi 9,9,-5024; addi 27,30,4; mr 28,4; stw 9,0x0(30); mr 3,27; li 29,0; bl _s800B5FD4_0; stw 28,0x8(30); addi 9,30,44; stw 29,0x24(30); li 0,-1; stw 29,0x28(30); mr 3,27; stw 29,0x4(9); li 4,0; stw 29,0xc(30); li 5,-1; stw 29,0x14(30); stw 29,0x18(30); stw 29,0x1c(30); stw 0,0x10(30); bl _s800B5FD4_1; li 0,1; stw 29,0x34(30); stw 0,0x20(30); mr 3,30; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"

extern "C" void _s800B5FD4_0();
extern "C" void _s800B5FD4_1();

struct FamilyImpl {
    void FamilyImpl();
};

void FamilyImpl::FamilyImpl() {
}
