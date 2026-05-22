// 0x8032EE70 XOSFontGetWordSize(char (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); li 0,0; mr 30,4; stw 0,0x0(30); mr 31,5; stw 0,0x0(31); lbz 0,0x0(3); cmpwi 0,0; beq 2f; li 29,1; 0:; extsb 0,0; cmpwi 0,10; beq 2f; cmpwi 0,32; bne 1f; lwz 0,0x0(31); cmpwi 0,0; bne 2f; stw 29,0x0(31); addi 4,1,8; bl _s8032EE70_0; lwz 0,0x0(30); lwz 9,0x8(1); add 0,0,9; stw 0,0x0(30); b 2f; 1:; addi 4,1,8; bl _s8032EE70_1; lwz 0,0x8(1); lwz 11,0x0(30); add 11,11,0; stw 11,0x0(30); lwz 9,0x0(31); addi 9,9,1; stw 9,0x0(31); lbz 0,0x0(3); cmpwi 0,0; bne 0b; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s8032EE70_0();
extern "C" void _s8032EE70_1();
extern "C" void f_8032EE70() {}
