// 0x8003D344 GameData::CopyrightDraw(ERC (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); mr 29,3; lis 9,-32707; lfs f13,0x1e68(9); mr 30,4; lfs f0,0x118(29); fcmpu 0,f0,f13; ble 1f; lis 9,-32697; addi 28,9,24012; lwz 31,0x104(28); cmpwi 31,0; beq 1f; lis 9,-32697; addi 11,31,88; lfs f0,0x6280(9); lis 10,-32707; addi 9,9,25216; lis 27,-32707; stfs f0,0x58(31); mr 3,31; lfs f1,0x1e6c(10); li 4,1; lfs f13,0x4(9); lfs f2,0x1e70(27); stfs f13,0x4(11); lfs f0,0x8(9); stfs f0,0x8(11); lfs f13,0xc(9); stfs f13,0xc(11); bl _s8003D344_0; mr 3,31; mr 4,30; bl _s8003D344_1; lis 5,-32707; mr 4,28; addi 5,5,7764; addi 3,1,16; crxor 6,6,6; bl _s8003D344_2; lwz 9,0x10(1); li 5,0; cmpwi 9,0; beq 0f; lwz 5,0x0(9); 0:; lis 9,-32707; lis 11,-32707; lfs f0,0x1e74(9); addi 10,1,8; lfs f13,0x1e78(11); mr 6,10; stfs f0,0x8(1); mr 3,31; lfs f1,0x1e70(27); mr 4,30; lfs f2,0x118(29); li 7,2; stfs f13,0x4(10); li 8,0; li 9,0; li 10,1; bl _s8003D344_3; 1:; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"
extern "C" void _s8003D344_0();
extern "C" void _s8003D344_1();
extern "C" void _s8003D344_2();
extern "C" void _s8003D344_3();
extern "C" void f_8003D344() {}
