// 0x80337E08 PADClampCircle (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 31,3; li 30,0; lis 26,-32702; lis 27,-32702; lis 28,-32702; lis 29,-32702; 0:; lbz 0,0xa(31); addi 3,31,2; addi 4,31,3; li 5,15; li 6,225; addi 30,30,1; cmpwi 0,0; bne 1f; lfs f1,0x1aa8(26); lfs f2,0x1aac(27); bl _s80337E08_0; lfs f1,0x1ab0(28); addi 3,31,4; lfs f2,0x1ab4(29); addi 4,31,5; li 5,15; li 6,225; bl _s80337E08_1; addi 3,31,6; li 4,30; li 5,180; bl _s80337E08_2; addi 3,31,7; li 4,30; li 5,180; bl _s80337E08_3; 1:; addi 31,31,12; cmplwi 30,3; ble 0b; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s80337E08_0();
extern "C" void _s80337E08_1();
extern "C" void _s80337E08_2();
extern "C" void _s80337E08_3();
extern "C" void f_80337E08() {}
