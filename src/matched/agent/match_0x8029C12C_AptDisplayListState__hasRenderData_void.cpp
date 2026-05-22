// 0x8029C12C AptDisplayListState::hasRenderData(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 31,0x0(3); cmpwi 31,0; beq 2f; 0:; mr 3,31; bl _s8029C12C_0; cmpwi 3,0; beq 1f; li 3,1; b 3f; 1:; lwz 31,0x54(31); cmpwi 31,0; bne 0b; 2:; li 3,0; 3:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8029C12C_0();
extern "C" void f_8029C12C() {}
