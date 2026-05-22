// 0x803C6790 void (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); mr 28,3; lis 0,-21846; subf 4,28,4; ori 0,0,43691; mullw 4,4,0; mr 27,5; srawi 29,4,2; cmpwi 29,1; ble 1f; addi 0,29,-2; rlwinm 9,0,1,31,31; add 0,0,9; srawi 30,0,1; mulli 9,30,12; add 31,9,28; 0:; lwz 0,0x4(31); mr 3,28; lwz 11,0x8(31); mr 4,30; lwz 9,0x0(31); mr 5,29; stw 0,0xc(1); addi 6,1,8; stw 9,0x8(1); mr 7,27; stw 11,0x10(1); bl _s803C6790_0; cmpwi 30,0; beq 1f; addi 31,31,-12; addi 30,30,-1; b 0b; 1:; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"
extern "C" void _s803C6790_0();
extern "C" void f_803C6790() {}
