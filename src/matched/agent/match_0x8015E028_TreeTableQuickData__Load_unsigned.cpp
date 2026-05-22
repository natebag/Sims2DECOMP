// 0x8015E028 TreeTableQuickData::Load(unsigned (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; rlwinm 5,5,0,16,31; addi 3,1,8; bl _s8015E028_0; lwz 9,0x0(30); addi 4,1,8; lha 3,0x28(9); lwz 0,0x2c(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; li 3,-50; beq 0f; li 3,0; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8015E028_0();
extern "C" void f_8015E028() {}
