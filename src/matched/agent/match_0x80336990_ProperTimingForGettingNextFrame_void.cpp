// 0x80336990 ProperTimingForGettingNextFrame(void) (300 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); lis 9,-32691; addi 30,9,14656; lwz 0,0x88(30); andi. 9,0,1; beq 0f; bl _s80336990_0; cmpwi 3,0; b 1f; 0:; andi. 9,0,2; beq 2f; bl _s80336990_1; cmpwi 3,1; 1:; bne 5f; li 3,1; b 6f; 2:; lis 9,-32702; lfs f0,0x4c(30); lfs f12,0x1a98(9); fmuls f0,f0,f12; fctiwz f13,f0; stfd f13,0x8(1); lwz 31,0xc(1); bl _s80336990_2; cmpwi 3,1; bne 3f; lwz 11,0xc8(30); lwz 12,0xcc(30); mr 10,31; srawi 9,31,31; li 5,0; mulhwu 3,12,10; li 6,5000; mullw 0,12,9; mullw 11,10,11; mullw 4,12,10; add 3,3,0; add 3,3,11; crxor 6,6,6; bl _s80336990_3; stw 4,0xd4(30); b 4f; 3:; lwz 11,0xc8(30); lwz 12,0xcc(30); mr 10,31; srawi 9,31,31; li 5,0; mulhwu 3,12,10; li 6,5994; mullw 0,12,9; mullw 11,10,11; mullw 4,12,10; add 3,3,0; add 3,3,11; crxor 6,6,6; bl _s80336990_4; stw 4,0xd4(30); 4:; lis 9,-32691; addi 9,9,14656; lwz 11,0xd4(9); lwz 0,0xd0(9); cmpw 0,11; beq 5f; stw 11,0xd0(9); li 3,1; b 6f; 5:; li 3,0; 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s80336990_0();
extern "C" void _s80336990_1();
extern "C" void _s80336990_2();
extern "C" void _s80336990_3();
extern "C" void _s80336990_4();
extern "C" void f_80336990() {}
