// 0x80176880 UI3D::UI3D(void) (360 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 25,0x24(1); stw 0,0x44(1); lis 9,-32698; mr 30,3; li 0,0; addi 9,9,25904; stw 9,0x1c(30); addi 11,30,12; stw 0,0x0(30); lis 9,-32698; stw 0,0x4(30); addi 25,9,25928; stw 0,0x8(30); li 28,0; stw 0,0x8(11); addi 26,1,24; stw 0,0xc(30); addi 27,1,8; li 31,0; li 29,16; 0:; li 3,40; bl _s80176880_0; lwz 0,0x8(30); stw 25,0x24(3); cmpwi 0,0; stw 31,0x0(3); stw 31,0x4(3); stw 31,0x8(3); stw 31,0xc(3); stw 31,0x10(3); stw 31,0x14(3); stw 31,0x18(3); stw 31,0x1c(3); stw 31,0x20(3); bne 1f; stw 3,0x8(30); b 2f; 1:; stw 3,0x4(28); stw 28,0x0(3); 2:; mr 28,3; addic. 29,29,-1; bne 0b; lis 9,-32706; lis 10,-32709; addi 9,9,9092; addi 29,10,4228; lwz 11,0x0(9); lwz 12,0x4(9); cmpwi 30,0; stw 30,0x10(1); stw 11,0x18(1); stw 12,0x1c(1); beq 3f; mr 4,26; addi 3,1,8; li 5,8; bl _s80176880_1; b 4f; 3:; stw 30,0x8(1); 4:; stw 29,0x14(1); addi 31,30,12; lwz 11,0x8(1); lwz 0,-31488(13); lwz 8,0xc(27); lwz 9,0x4(27); cmpwi 0,0; lwz 10,0x8(27); stw 11,0xc(30); stw 9,0x4(31); stw 10,0x8(31); stw 8,0xc(31); bne 5f; li 3,16; bl _s80176880_2; bl _s80176880_3; stw 3,-31488(13); 5:; lwz 3,-31488(13); lis 6,-32706; mr 5,31; addi 6,6,9100; li 4,75; bl _s80176880_4; mr 3,30; lwz 0,0x44(1); mtspr 8,0; lmw 25,0x24(1); addi 1,1,64"
extern "C" void _s80176880_0();
extern "C" void _s80176880_1();
extern "C" void _s80176880_2();
extern "C" void _s80176880_3();
extern "C" void _s80176880_4();
extern "C" void f_80176880() {}
