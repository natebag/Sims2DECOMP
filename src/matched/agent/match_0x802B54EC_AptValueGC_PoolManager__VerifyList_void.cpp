// 0x802B54EC AptValueGC_PoolManager::VerifyList(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s802B54EC_0; mr. 3,3; beq 1f; 0:; mr 4,3; mr 3,31; bl _s802B54EC_1; mr. 3,3; bne 0b; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802B54EC_0();
extern "C" void _s802B54EC_1();
extern "C" void f_802B54EC() {}
