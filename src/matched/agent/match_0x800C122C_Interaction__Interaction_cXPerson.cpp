// 0x800C122C Interaction::Interaction(cXPerson (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32698; mr 31,3; addi 9,9,-2280; mr 30,4; mr 29,5; stw 9,0x40(31); mr 28,6; addi 3,31,52; bl _s800C122C_0; li 11,0; li 0,2; li 9,100; stw 0,0x4(31); stw 9,0x28(31); cmpwi 29,0; stw 11,0x3c(31); stw 30,0x8(31); bne 0f; li 0,-1; stw 29,0x10(31); stw 0,0x14(31); b 1f; 0:; stw 29,0x10(31); stw 28,0x14(31); 1:; stw 29,0xc(31); lwz 11,0x3c(31); lis 9,-32706; lfs f0,-24768(9); li 0,0; li 9,0; rlwinm 11,11,0,0,30; sth 0,0x1e(31); mr 3,31; stfs f0,0x30(31); stw 11,0x3c(31); stw 9,0x24(31); sth 0,0x18(31); sth 0,0x1a(31); sth 0,0x1c(31); stw 9,0x38(31); sth 9,0x2c(31); stw 9,0x20(31); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800C122C_0();
extern "C" void f_800C122C() {}
