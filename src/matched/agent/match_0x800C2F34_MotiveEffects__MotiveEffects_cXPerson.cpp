// 0x800C2F34 MotiveEffects::MotiveEffects(cXPerson (292 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 25,0x1c(1); stw 0,0x3c(1); mr 30,3; li 0,9; addi 9,30,8; stw 0,0x4(30); stw 9,0x0(30); mr 28,4; mr 31,9; li 29,8; addi 25,1,8; addi 26,1,16; li 27,-1; 0:; mr 3,31; bl _s800C2F34_0; stw 27,0x10(31); cmpwi 29,0; addi 31,31,20; addi 29,29,-1; bne 0b; stw 28,0xbc(30); li 27,0; lwz 9,0x4(28); lwz 0,0x254(9); lha 3,0x250(9); mtspr 8,0; add 3,28,3; blrl; lis 9,-32706; lis 11,-32706; lfs f0,-23592(9); lfs f13,-23588(11); stfs f0,0x8(1); stfs f0,0x4(25); lwz 0,0x4(30); stfs f13,0x10(1); stw 3,0xc0(30); cmpw 27,0; stfs f13,0x4(26); bge 2f; lis 9,-32702; li 31,0; addi 29,9,16588; 1:; lwz 9,0x0(30); li 4,4; lwz 0,0x0(29); addi 27,27,1; add 9,9,31; addi 29,29,4; stw 0,0x10(9); lwz 3,0x0(30); add 3,3,31; bl _s800C2F34_1; lwz 3,0x0(30); mr 4,25; add 3,3,31; bl _s800C2F34_2; lwz 3,0x0(30); mr 4,26; add 3,3,31; bl _s800C2F34_3; addi 31,31,20; lwz 0,0x4(30); cmpw 27,0; blt 1b; 2:; mr 3,30; lwz 0,0x3c(1); mtspr 8,0; lmw 25,0x1c(1); addi 1,1,56"
extern "C" void _s800C2F34_0();
extern "C" void _s800C2F34_1();
extern "C" void _s800C2F34_2();
extern "C" void _s800C2F34_3();
extern "C" void f_800C2F34() {}
