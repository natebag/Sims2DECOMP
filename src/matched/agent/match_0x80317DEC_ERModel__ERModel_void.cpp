// 0x80317DEC ERModel::ERModel(void) (552 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 30,0x48(1); stw 0,0x54(1); mr 31,3; li 30,0; bl _s80317DEC_0; lis 9,-32697; addi 3,31,20; addi 9,9,-19256; stw 9,0x0(31); bl _s80317DEC_1; addi 3,31,60; bl _s80317DEC_2; lis 9,-32702; addi 10,31,72; lfs f0,0x890(9); addi 8,31,100; addi 7,31,88; addi 6,31,124; stfs f0,0x8(1); addi 5,31,112; stfs f0,0x10(1); lis 4,-32702; stfs f0,0xc(1); addi 3,31,144; lwz 0,0x8(1); lwz 9,0xc(1); lwz 11,0x10(1); stw 0,0x48(31); stfs f0,0xc(10); stw 9,0x4(10); stw 11,0x8(10); stfs f0,0x18(1); stfs f0,0x20(1); stfs f0,0x1c(1); lwz 0,0x18(1); lwz 11,0x1c(1); lwz 9,0x20(1); stw 0,0x64(31); stw 9,0x8(8); stw 11,0x4(8); lwz 0,0x64(31); stw 0,0x58(31); stw 9,0x8(7); stw 11,0x4(7); stfs f0,0x28(1); stfs f0,0x30(1); stfs f0,0x2c(1); lwz 0,0x28(1); lwz 11,0x2c(1); lwz 9,0x30(1); stw 0,0x7c(31); stw 9,0x8(6); stw 11,0x4(6); lwz 0,0x7c(31); stw 0,0x70(31); stw 9,0x8(5); stw 11,0x4(5); lfs f0,0x894(4); stw 30,0x8c(31); stfs f0,0x88(31); bl _s80317DEC_3; li 0,1; stw 30,0x100(31); stw 0,0xfc(31); addi 3,31,260; bl _s80317DEC_4; addi 3,31,272; bl _s80317DEC_5; addi 3,31,284; bl _s80317DEC_6; addi 3,31,296; bl _s80317DEC_7; li 0,-1; stw 30,0x140(31); stb 0,0x135(31); addi 12,1,56; li 0,4; stb 30,0x134(31); mtspr 9,0; stw 30,0x138(31); stw 30,0x13c(31); 0:; bdnz 0b; lis 9,-32702; li 11,0; lfs f0,0x890(9); addi 8,31,100; stw 11,0x17c(31); addi 7,31,88; stfs f0,0x8(12); addi 6,31,124; stfs f0,0x4(12); addi 30,31,112; stfs f0,0x38(1); li 4,0; lwz 9,0x40(1); li 5,48; lwz 0,0x38(1); addi 3,31,156; lwz 10,0x3c(1); stw 0,0x64(31); stw 11,0x174(31); stb 11,0x178(31); stw 9,0x8(8); stw 10,0x4(8); lwz 0,0x64(31); stw 0,0x58(31); stw 9,0x8(7); stw 10,0x4(7); stfs f0,0x4(12); stfs f0,0x8(12); stfs f0,0x38(1); lwz 11,0x3c(1); lwz 0,0x38(1); lwz 9,0x40(1); stw 0,0x7c(31); stw 9,0x8(6); stw 11,0x4(6); lwz 0,0x7c(31); stw 0,0x70(31); stw 9,0x8(30); stw 11,0x4(30); bl _s80317DEC_8; li 4,0; li 5,48; addi 3,31,204; bl _s80317DEC_9; addi 3,31,324; li 4,0; li 5,48; bl _s80317DEC_10; mr 3,31; lwz 0,0x54(1); mtspr 8,0; lmw 30,0x48(1); addi 1,1,80"
extern "C" void _s80317DEC_0();
extern "C" void _s80317DEC_1();
extern "C" void _s80317DEC_2();
extern "C" void _s80317DEC_3();
extern "C" void _s80317DEC_4();
extern "C" void _s80317DEC_5();
extern "C" void _s80317DEC_6();
extern "C" void _s80317DEC_7();
extern "C" void _s80317DEC_8();
extern "C" void _s80317DEC_9();
extern "C" void _s80317DEC_10();
extern "C" void f_80317DEC() {}
