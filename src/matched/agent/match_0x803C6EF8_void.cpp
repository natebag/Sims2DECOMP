// 0x803C6EF8 void (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; mr 29,5; cmpw 31,30; beq 2f; lis 0,-21846; subf 9,31,30; ori 0,0,43691; li 6,0; mullw 9,9,0; srawi 9,9,2; cmpwi 9,1; beq 1f; 0:; srawi 9,9,1; addi 6,6,1; cmpwi 9,1; bne 0b; 1:; mr 3,31; mr 4,30; li 5,0; rlwinm 6,6,1,0,30; mr 7,29; bl _s803C6EF8_0; mr 3,31; mr 4,30; mr 5,29; bl _s803C6EF8_1; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s803C6EF8_0();
extern "C" void _s803C6EF8_1();
extern "C" void f_803C6EF8() {}
