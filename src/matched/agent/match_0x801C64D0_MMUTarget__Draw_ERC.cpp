// 0x801C64D0 MMUTarget::Draw(ERC (372 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-296(1); mfspr 0,8; stmw 30,0x120(1); stw 0,0x12c(1); lis 9,-32697; mr 31,3; lwz 0,0x61d0(9); mr 30,4; cmpwi 0,0; beq 4f; lwz 0,0x8c(31); cmpwi 0,0; bne 2f; lis 11,-32697; lis 9,-32705; addi 6,11,23428; lwz 8,0x2c44(9); lwz 0,0xf0(6); addi 9,9,11332; lbz 7,0x10(9); addi 3,1,24; cmpwi 0,0; lwz 10,0x4(9); lwz 11,0x8(9); lwz 0,0xc(9); stw 8,0x18(1); stw 10,0x4(3); stw 11,0x8(3); stw 0,0xc(3); stb 7,0x10(3); bne 0f; lis 4,-32705; addi 4,4,11352; bl _s801C64D0_0; b 3f; 0:; lwz 0,0xe8(6); cmpwi 0,0; bne 1f; lis 4,-32705; addi 4,4,11372; bl _s801C64D0_1; b 3f; 1:; lis 4,-32705; addi 4,4,11392; bl _s801C64D0_2; b 3f; 2:; li 0,0; stb 0,0x18(1); 3:; lwz 3,0x18c(31); mr 4,30; bl _s801C64D0_3; lis 9,-32697; lwz 8,0x18c(31); lfs f0,0x62a0(9); lis 10,-32705; addi 9,9,25248; addi 11,8,88; stfs f0,0x58(8); lis 7,-32705; lfs f1,0x2ca0(10); li 4,1; lfs f13,0x4(9); lfs f2,0x2ca4(7); stfs f13,0x4(11); lfs f0,0x8(9); stfs f0,0x8(11); lfs f13,0xc(9); stfs f13,0xc(11); lwz 3,0x18c(31); bl _s801C64D0_4; lis 9,-32705; lwz 3,0x18c(31); lfs f0,0x2ca8(9); addi 6,1,280; li 9,1; li 0,0; stfs f0,0x118(1); mr 4,30; stfs f0,0x4(6); addi 5,1,24; stw 9,0x10(1); li 7,0; stw 0,0xc(1); li 8,0; stw 0,0x8(1); li 9,0; li 10,0; bl _s801C64D0_5; 4:; lwz 0,0x12c(1); mtspr 8,0; lmw 30,0x120(1); addi 1,1,296"
extern "C" void _s801C64D0_0();
extern "C" void _s801C64D0_1();
extern "C" void _s801C64D0_2();
extern "C" void _s801C64D0_3();
extern "C" void _s801C64D0_4();
extern "C" void _s801C64D0_5();
extern "C" void f_801C64D0() {}
