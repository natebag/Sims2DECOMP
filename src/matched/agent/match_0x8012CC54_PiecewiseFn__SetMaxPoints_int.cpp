// 0x8012CC54 PiecewiseFn::SetMaxPoints(int) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; lwz 3,0x0(31); cmpwi 3,0; beq 0f; bl _s8012CC54_0; 0:; lwz 3,0x4(31); li 30,0; stw 30,0x0(31); cmpwi 3,0; beq 1f; bl _s8012CC54_1; 1:; stw 30,0x4(31); cmpwi 29,0; stw 30,0x8(31); stw 29,0xc(31); ble 2f; rlwinm 3,29,3,0,28; bl _s8012CC54_2; lwz 9,0xc(31); stw 3,0x0(31); addi 9,9,-1; rlwinm 3,9,2,0,29; bl _s8012CC54_3; stw 3,0x4(31); b 3f; 2:; stw 30,0xc(31); 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8012CC54_0();
extern "C" void _s8012CC54_1();
extern "C" void _s8012CC54_2();
extern "C" void _s8012CC54_3();
extern "C" void f_8012CC54() {}
