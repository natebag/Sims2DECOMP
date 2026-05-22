// 0x8029E360 AptLoader::findFile(EAStringC (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); lwz 0,0x0(4); mr 31,3; mr 30,5; li 29,0; b 2f; 0:; lwz 9,0x0(9); lwz 4,0x0(30); lwz 3,0x4(9); addi 4,4,8; addi 3,3,8; bl _s8029E360_0; cmpwi 3,1; bne 1f; lwz 9,0x8(1); lwz 3,0x0(9); stw 3,0x0(31); cmpwi 3,0; beq 4f; bl _s8029E360_1; b 4f; 1:; lwz 9,0x8(1); lwz 0,0x4(9); 2:; stw 0,0x8(1); lwz 9,0x8(1); li 0,1; stw 29,0x10(1); cmpwi 9,0; bne 3f; li 0,0; 3:; cmpwi 0,0; bne 0b; stw 0,0x0(31); 4:; mr 3,31; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s8029E360_0();
extern "C" void _s8029E360_1();
extern "C" void f_8029E360() {}
