// 0x80032D68 ESim::CensorOrderTableCallback(ELevelDrawData (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lwz 29,0x24(4); mr 28,3; lwz 31,0x98(28); lwz 0,0x528(29); cmpwi 0,0; beq 0f; lwz 11,0x70(31); lis 9,-32707; lfs f1,0x118c(9); lwz 0,0x25c(11); lha 3,0x258(11); mtspr 8,0; add 3,31,3; blrl; lwz 11,0x3d0(29); lwz 9,0x4(11); lwz 0,0x18c(9); lha 3,0x188(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(3); mr 4,31; lha 0,0xd8(9); lwz 9,0xdc(9); add 3,3,0; mtspr 8,9; blrl; lwz 30,0x70(31); mr 3,29; lha 29,0x258(30); addi 30,30,600; add 29,31,29; bl _s80032D68_0; lwz 0,0x4(30); mr 3,29; mtspr 8,0; blrl; 0:; li 0,0; stw 0,0xa8(28); stw 0,0xac(28); stw 0,0xb4(28); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80032D68_0();
extern "C" void f_80032D68() {}
