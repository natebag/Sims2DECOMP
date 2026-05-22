// 0x8034D15C ENgcSFXStreamer::Free(unsigned (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,4; cmpwi 31,-1; beq 2f; mulli 30,31,68; bl _s8034D15C_0; lis 9,-32690; addi 29,9,-19244; lwzx 3,30,29; add 31,30,29; cmpwi 3,0; beq 1f; lwz 0,0x24(31); cmpwi 0,0; beq 1f; li 4,7; li 28,0; bl _s8034D15C_1; lwzx 3,30,29; bl _s8034D15C_2; lwz 0,0x40(31); lwz 3,0x38(31); rlwinm 0,0,0,1,31; stw 28,0x24(31); cmpwi 3,0; stw 0,0x40(31); beq 0f; lwz 0,0x24(3); cmpwi 0,0; beq 0f; lwz 3,0x0(3); li 4,7; bl _s8034D15C_3; lwz 9,0x38(31); lwz 3,0x0(9); bl _s8034D15C_4; lwz 11,0x38(31); lwz 0,0x40(11); rlwinm 0,0,0,1,31; stw 0,0x40(11); lwz 9,0x38(31); stw 28,0x24(9); 0:; lwz 3,0x34(31); cmpwi 3,0; beq 1f; lwz 0,0x24(3); cmpwi 0,0; beq 1f; lwz 3,0x0(3); li 4,7; bl _s8034D15C_5; lwz 9,0x34(31); lwz 3,0x0(9); bl _s8034D15C_6; lwz 11,0x34(31); li 10,0; lwz 0,0x40(11); rlwinm 0,0,0,1,31; stw 0,0x40(11); lwz 9,0x34(31); stw 10,0x24(9); 1:; bl _s8034D15C_7; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8034D15C_0();
extern "C" void _s8034D15C_1();
extern "C" void _s8034D15C_2();
extern "C" void _s8034D15C_3();
extern "C" void _s8034D15C_4();
extern "C" void _s8034D15C_5();
extern "C" void _s8034D15C_6();
extern "C" void _s8034D15C_7();
extern "C" void f_8034D15C() {}
