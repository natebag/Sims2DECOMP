// 0x801F44C4 INVTarget::SetOnMsgInvCurrentCell(char (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; mr 3,4; bl _s801F44C4_0; lwz 0,0x84(31); lis 9,-32697; lwz 10,0x618c(9); addi 11,13,-28700; rlwinm 0,0,2,0,29; stwx 3,11,0; cmpwi 10,0; beq 0f; mr 3,31; bl _s801F44C4_1; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801F44C4_0();
extern "C" void _s801F44C4_1();
extern "C" void f_801F44C4() {}
