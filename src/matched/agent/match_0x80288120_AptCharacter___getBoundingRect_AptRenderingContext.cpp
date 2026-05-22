// 0x80288120 AptCharacter::_getBoundingRect(AptRenderingContext (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 31,4; mr 29,5; mr. 28,6; beq 0f; mr 3,31; bl _s80288120_0; mr 3,31; mr 4,28; bl _s80288120_1; 0:; lwz 0,0x0(30); cmpwi 0,10; beq 1f; bgt 2f; cmpwi 0,1; bne 2f; mr 4,29; addi 5,30,8; mr 3,31; bl _s80288120_2; b 2f; 1:; mr 4,29; addi 5,30,8; mr 3,31; bl _s80288120_3; 2:; cmpwi 28,0; beq 3f; mr 3,31; bl _s80288120_4; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80288120_0();
extern "C" void _s80288120_1();
extern "C" void _s80288120_2();
extern "C" void _s80288120_3();
extern "C" void _s80288120_4();
extern "C" void f_80288120() {}
