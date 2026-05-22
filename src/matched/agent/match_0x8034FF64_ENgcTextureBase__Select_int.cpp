// 0x8034FF64 ENgcTextureBase::Select(int, (424 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); mr 31,3; mr 29,5; lwz 0,0x80(31); cmpwi 0,0; bne 5f; lwz 9,0x90(31); li 0,1; stw 0,0x80(31); cmpwi 9,0; beq 0f; bl _s8034FF64_0; stw 3,0x94(31); li 5,2; lwz 4,0x90(31); addi 3,31,132; lhz 6,0x14(31); bl _s8034FF64_1; lwz 0,0x94(31); addi 3,31,72; lwz 4,0x74(31); li 10,0; lhz 5,0x10(31); lhz 6,0x12(31); lwz 7,0x70(31); lwz 8,0x68(31); lwz 9,0x6c(31); stw 0,0x8(1); bl _s8034FF64_2; b 1f; 0:; lbz 10,0xb(31); addi 3,31,72; lwz 4,0x74(31); lhz 5,0x10(31); rlwinm 10,10,0,26,26; lhz 6,0x12(31); lwz 7,0x70(31); lwz 8,0x68(31); lwz 9,0x6c(31); bl _s8034FF64_3; 1:; lwz 0,0x8(31); andi. 9,0,32; beq 4f; lwz 0,0x90(31); li 4,5; cmpwi 0,0; beq 2f; li 4,3; 2:; lhz 0,0x16(31); addi 3,31,72; addic. 0,0,-1; bge 3f; li 0,0; 3:; xoris 0,0,32768; stw 0,0x1c(1); lis 11,17200; lis 10,-32702; lis 8,-32702; stw 11,0x18(1); li 5,1; lfd f0,0x23b8(10); li 6,0; lfd f2,0x18(1); li 7,1; lfs f1,0x23c0(8); fsub f2,f2,f0; lfs f3,-25892(13); frsp f2,f2; li 8,2; bl _s8034FF64_4; b 5f; 4:; lis 9,-32702; addi 3,31,72; lfs f1,0x23c0(9); li 4,1; li 5,1; li 6,0; fmr f2,f1; li 7,0; fmr f3,f2; li 8,0; bl _s8034FF64_5; 5:; lwz 0,0x90(31); addi 30,31,72; cmpwi 0,0; beq 6f; bl _s8034FF64_6; mr 0,3; mr 4,0; mr 3,30; stw 0,0x94(31); bl _s8034FF64_7; lwz 4,0x94(31); addi 3,31,132; bl _s8034FF64_8; 6:; mr 3,30; mr 4,29; bl _s8034FF64_9; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s8034FF64_0();
extern "C" void _s8034FF64_1();
extern "C" void _s8034FF64_2();
extern "C" void _s8034FF64_3();
extern "C" void _s8034FF64_4();
extern "C" void _s8034FF64_5();
extern "C" void _s8034FF64_6();
extern "C" void _s8034FF64_7();
extern "C" void _s8034FF64_8();
extern "C" void _s8034FF64_9();
extern "C" void f_8034FF64() {}
