// 0x8015CF80 SmartDataFactory::CreateObject(unsigned (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 31,4; mr. 29,6; li 3,0; beq 3f; mr 3,30; bl _s8015CF80_0; mr 5,3; cmpwi 5,4; bne 2f; lis 0,11243; ori 0,0,9254; cmpw 31,0; beq 0f; lis 0,-24789; ori 0,0,49436; cmpw 31,0; bne 1f; 0:; li 5,3; b 2f; 1:; li 5,0; 2:; mr 3,30; mr 4,31; mr 6,29; bl _s8015CF80_1; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8015CF80_0();
extern "C" void _s8015CF80_1();
extern "C" void f_8015CF80() {}
