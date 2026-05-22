// 0x80337314 Reader(void (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); lis 9,-32691; li 28,0; addi 9,9,14656; lis 26,-32691; lwz 29,0xb8(9); mr 25,9; lwz 30,0xbc(9); lis 27,-32691; 0:; bl _s80337314_0; mr 31,3; mr 5,30; lwz 4,0x0(31); addi 3,26,14656; mr 6,29; li 7,2; bl _s80337314_1; cmpw 3,30; beq 3f; cmpwi 3,-1; bne 1f; stw 3,0xa8(25); 1:; cmpwi 28,0; bne 2f; li 3,0; bl _s80337314_2; 2:; addi 3,27,15336; bl _s80337314_3; 3:; stw 28,0x4(31); mr 3,31; add 29,29,30; bl _s80337314_4; addi 8,26,14656; lwz 10,0x0(31); lwz 9,0xc0(8); lwz 11,0x50(8); add 9,28,9; lwz 30,0x0(10); divwu 0,9,11; addi 10,11,-1; mullw 0,0,11; subf 9,0,9; cmpw 9,10; bne 5f; lbz 0,0xa6(8); andi. 9,0,1; beq 4f; lwz 29,0x64(8); b 5f; 4:; addi 3,27,15336; bl _s80337314_5; 5:; addi 28,28,1; b 0b"
extern "C" void _s80337314_0();
extern "C" void _s80337314_1();
extern "C" void _s80337314_2();
extern "C" void _s80337314_3();
extern "C" void _s80337314_4();
extern "C" void _s80337314_5();
extern "C" void f_80337314() {}
