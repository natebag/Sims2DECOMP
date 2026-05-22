// 0x801821D0 UIUserDrawCBTable::ExecuteCallback(ERC (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; mr 4,5; bl _s801821D0_0; mr. 3,3; beq 3f; lwz 0,0x0(31); cmpw 3,0; beq 2f; lwz 0,0x4(31); cmpw 3,0; bne 0f; lwz 0,0x0(3); stw 0,0x4(31); b 1f; 0:; lwz 9,0x4(3); lwz 0,0x0(3); stw 0,0x0(9); 1:; lwz 9,0x0(3); li 11,0; lwz 0,0x4(3); stw 0,0x4(9); stw 11,0x0(3); lwz 0,0x0(31); stw 0,0x4(3); lwz 9,0x0(31); stw 3,0x0(9); stw 3,0x0(31); 2:; lwz 9,0xc(3); lis 5,-32696; mr 4,30; addi 5,5,32164; lwz 0,0xc(9); mr 3,9; mtspr 8,0; blrl; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801821D0_0();
extern "C" void f_801821D0() {}
