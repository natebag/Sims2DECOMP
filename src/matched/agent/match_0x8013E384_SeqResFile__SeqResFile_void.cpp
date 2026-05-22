// 0x8013E384 SeqResFile::SeqResFile(void) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); mr 30,3; li 29,8; addi 31,30,208; bl _s8013E384_0; lis 9,-32698; addi 28,1,8; addi 9,9,17672; stw 9,0xc(30); 0:; addi 3,31,4; addi 4,31,12; li 5,8; addi 31,31,20; bl _s8013E384_1; cmpwi 29,0; addi 29,29,-1; bne 0b; li 0,0; addi 4,28,8; stw 0,0xd0(30); li 5,8; mr 3,28; bl _s8013E384_2; mr 3,28; li 4,0; li 5,-1; bl _s8013E384_3; addi 3,30,212; mr 4,28; bl _s8013E384_4; mr 3,30; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s8013E384_0();
extern "C" void _s8013E384_1();
extern "C" void _s8013E384_2();
extern "C" void _s8013E384_3();
extern "C" void _s8013E384_4();
extern "C" void f_8013E384() {}
