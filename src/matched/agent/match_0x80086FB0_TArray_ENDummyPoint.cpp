// 0x80086FB0 TArray<ENDummyPoint, (488 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="crxor 6,6,6; bl _s80086FB0_0; lis 11,-32697; addi 9,11,25392; lfs f11,0x6330(11); lfs f0,0xc(9); lfs f13,0x4(9); lfs f12,0x8(9); stfs f0,0xc(30); stfs f11,0x0(30); stfs f13,0x4(30); stfs f12,0x8(30); lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40; blr; stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32698; mr 30,3; li 0,1; addi 9,9,-10872; li 29,0; stw 4,0x0(30); stw 9,0x1c(30); lis 10,-32707; stw 0,0x4(30); lis 9,-32698; stw 29,0x8(30); addi 9,9,-11112; addi 11,30,32; lfs f0,0x7308(10); mr 3,11; stw 9,0x1c(30); stfs f0,0x18(30); stfs f0,0xc(30); stfs f0,0x10(30); stfs f0,0x14(30); stw 29,0x24(11); bl _s80086FB0_1; stw 29,0x6c(30); mr 3,30; bl _s80086FB0_2; mr 3,30; bl _s80086FB0_3; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24; blr; stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lis 9,-32698; lwz 30,0x44(31); addi 9,9,-11112; mr 29,4; stw 9,0x1c(31); cmpwi 30,0; beq 0f; bl _s80086FB0_4; mr 4,30; bl _s80086FB0_5; 0:; lis 9,-32698; mr 3,31; addi 9,9,-10872; stw 9,0x1c(31); bl _s80086FB0_6; mr 3,31; bl _s80086FB0_7; andi. 0,29,1; beq 1f; mr 3,31; bl _s80086FB0_8; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24; blr; li 0,1; stw 0,0x4(3); blr; stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lwz 9,0x1c(31); addi 3,31,32; lwz 11,0x38(3); lha 0,0x68(9); addi 29,9,104; andis. 9,11,4096; add 30,31,0; beq 2f; bl _s80086FB0_9; 2:; lwz 0,0x4(29); mr 3,30; addi 4,31,60; mtspr 8,0; blrl; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24; blr; lfs f0,0x0(4); lwz 9,0x44(3); stfs f0,0x0(9); lfs f13,0x4(4); stfs f13,0x4(9); lfs f0,0x8(4); stfs f0,0x8(9); lfs f13,0xc(4); stfs f13,0xc(9)"
extern "C" void _s80086FB0_0();
extern "C" void _s80086FB0_1();
extern "C" void _s80086FB0_2();
extern "C" void _s80086FB0_3();
extern "C" void _s80086FB0_4();
extern "C" void _s80086FB0_5();
extern "C" void _s80086FB0_6();
extern "C" void _s80086FB0_7();
extern "C" void _s80086FB0_8();
extern "C" void _s80086FB0_9();
extern "C" void f_80086FB0() {}
