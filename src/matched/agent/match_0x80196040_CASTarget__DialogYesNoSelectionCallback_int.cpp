// 0x80196040 CASTarget::DialogYesNoSelectionCallback(int) (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; mfcr 12; stmw 27,0xc(1); stw 0,0x24(1); stw 12,0x8(1); mr 30,3; cmpwi 4,4,0; li 4,1; bl _s80196040_0; li 29,0; lis 9,-32701; li 11,0; addi 28,9,28636; addi 27,28,4; addi 10,28,-4; b 1f; 0:; addi 29,31,12; addi 11,11,1; 1:; cmpwi 11,47; bgt 3f; mr 31,29; lwz 9,0x1424(30); lwzx 0,10,31; cmpw 0,9; bne 0b; addi 3,30,5020; bl _s80196040_1; bne cr4,2f; lwzx 4,31,28; mr 3,30; bl _s80196040_2; b 3f; 2:; lwzx 4,27,29; mr 3,30; bl _s80196040_3; 3:; li 0,0; stw 0,0x1424(30); lwz 0,0x24(1); lwz 12,0x8(1); mtspr 8,0; lmw 27,0xc(1); mtcrf 8,12; addi 1,1,32"
extern "C" void _s80196040_0();
extern "C" void _s80196040_1();
extern "C" void _s80196040_2();
extern "C" void _s80196040_3();
extern "C" void f_80196040() {}
