// 0x802D792C ESemaphore::Release(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 30,1; bl _s802D792C_0; cmpwi 3,0; bne 0f; li 30,0; 0:; lwz 9,0xc(31); lwz 0,0x8(31); cmpw 9,0; bge 1f; addi 3,31,12; bl _s802D792C_1; 1:; mr 3,30; bl _s802D792C_2; li 3,1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s802D792C_0();
extern "C" void _s802D792C_1();
extern "C" void _s802D792C_2();

struct ESemaphore {
    void Release();
};

void ESemaphore::Release() {
}
