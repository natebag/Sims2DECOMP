// 0x803067C4 EFrameAllocGroup::EFrameAllocGroup(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32697; mr 29,3; addi 9,9,-24288; stw 9,0x0(29); li 4,2; bl _s803067C4_0; addi 31,29,4; lis 9,-32697; li 30,1; addi 9,9,-20760; stw 9,0x0(29); 0:; mr 3,31; li 4,4096; bl _s803067C4_1; addi 31,31,24; cmpwi 30,0; addi 30,30,-1; bne 0b; li 0,0; mr 3,29; stw 0,0x34(29); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s803067C4_0();
extern "C" void _s803067C4_1();
extern "C" void f_803067C4() {}
