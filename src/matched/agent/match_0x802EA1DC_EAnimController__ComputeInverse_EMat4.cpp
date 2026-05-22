// 0x802EA1DC EAnimController::ComputeInverse(EMat4 (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,3; mr 31,5; bl _s802EA1DC_0; lwz 0,0x34(28); cmpw 0,31; beq 2f; lwz 4,0x24(28); stw 31,0x34(28); cmpwi 4,0; li 31,0; beq 0f; lwz 31,0x18(4); 0:; lis 9,-32693; rlwinm 4,31,6,0,25; addi 9,9,3420; li 5,16; lwz 3,0x34(9); mulli 3,3,24; addi 3,3,4; add 3,3,9; bl _s802EA1DC_1; cmpwi 31,0; lwz 29,0x10(28); mr 30,3; stw 3,0x14(28); addi 31,31,-1; beq 2f; 1:; mr 3,30; mr 4,29; bl _s802EA1DC_2; addi 30,30,64; cmpwi 31,0; addi 29,29,64; addi 31,31,-1; bne 1b; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802EA1DC_0();
extern "C" void _s802EA1DC_1();
extern "C" void _s802EA1DC_2();
extern "C" void f_802EA1DC() {}
