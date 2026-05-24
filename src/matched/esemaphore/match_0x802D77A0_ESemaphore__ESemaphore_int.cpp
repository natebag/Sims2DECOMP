// 0x802D77A0 ESemaphore::ESemaphore(int, (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 29,4; mr 28,5; bl _s802D77A0_0; lis 9,-32697; li 0,0; addi 9,9,-23736; stw 0,0x8(30); stw 9,0x0(30); mr 4,29; mr 5,28; stw 0,0x4(30); mr 3,30; bl _s802D77A0_1; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s802D77A0_0();
extern "C" void _s802D77A0_1();

struct ESemaphore {
    void ESemaphore();
};

void ESemaphore::ESemaphore() {
}
