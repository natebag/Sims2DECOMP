// 0x8023637C ERLevel::RegisterFloor(EOrderTableData (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; addis 29,31,3; lwz 0,-23928(29); cmpwi 0,0; beq 0f; bl _s8023637C_0; mr 30,3; lwz 4,0x24(30); mr 3,31; bl _s8023637C_1; lwz 9,-23928(29); rlwinm 3,3,2,0,29; lwzx 0,3,9; stw 0,0x28(30); lwz 9,-23928(29); stwx 30,3,9; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8023637C_0();
extern "C" void _s8023637C_1();
extern "C" void f_8023637C() {}
