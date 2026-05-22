// 0x80145C38 EdithResFile::EdithResFile(void) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); mr 30,3; li 29,8; addi 31,30,208; bl _s80145C38_0; lis 9,-32698; addi 28,1,8; addi 9,9,17672; stw 9,0xc(30); 0:; addi 3,31,4; addi 4,31,12; li 5,8; addi 31,31,20; bl _s80145C38_1; cmpwi 29,0; addi 29,29,-1; bne 0b; li 0,0; addi 4,1,16; stw 0,0xd0(30); li 5,8; mr 3,28; bl _s80145C38_2; li 5,-1; mr 3,28; li 4,0; bl _s80145C38_3; mr 4,28; addi 3,30,212; bl _s80145C38_4; lis 9,-32698; mr 3,30; addi 9,9,19720; stw 9,0xc(30); bl _s80145C38_5; lis 5,-32706; mr 3,30; addi 5,5,-10368; li 4,2; bl _s80145C38_6; mr 3,30; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s80145C38_0();
extern "C" void _s80145C38_1();
extern "C" void _s80145C38_2();
extern "C" void _s80145C38_3();
extern "C" void _s80145C38_4();
extern "C" void _s80145C38_5();
extern "C" void _s80145C38_6();
extern "C" void f_80145C38() {}
