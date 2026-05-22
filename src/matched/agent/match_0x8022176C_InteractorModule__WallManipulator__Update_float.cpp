// 0x8022176C InteractorModule::WallManipulator::Update(float) (584 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; bl _s8022176C_0; mr 3,31; bl _s8022176C_1; mr 3,31; bl _s8022176C_2; lwz 11,0x78(31); addi 10,31,120; lwz 0,0x4(10); mr 9,11; cmpw 11,0; beq 1f; 0:; addi 9,9,8; cmpw 9,0; bne 0b; 1:; stw 11,0x4(10); lwz 29,0x4(31); cmpwi 29,0; beq 8f; lwz 0,0xc4(31); andi. 9,0,2; beq 4f; addi 30,31,32; addi 0,31,8; mr 3,0; mr 29,0; mr 4,30; li 5,2; bl _s8022176C_3; lwz 10,0x20(31); addi 11,31,96; lwz 0,0x8(30); lis 9,-32704; lwz 8,0x4(30); addi 7,31,108; stw 10,0x60(31); stw 0,0x8(11); stw 8,0x4(11); lfs f13,-7840(9); lwz 0,0x20(31); lwz 9,0x8(30); lwz 11,0x4(30); stw 0,0x6c(31); stw 9,0x8(7); stw 11,0x4(7); lfs f0,0x34(31); fcmpu 0,f0,f13; bne 2f; lfs f0,0x38(31); fcmpu 0,f0,f13; bne 2f; stfs f13,0x8(1); lis 9,-32704; lfs f0,-7836(9); addi 11,1,8; lwz 5,0x4(31); mr 4,11; stfs f0,0x4(11); mr 3,29; li 6,2; bl _s8022176C_4; b 3f; 2:; lwz 5,0x4(31); mr 3,29; addi 4,31,52; li 6,2; bl _s8022176C_5; 3:; lwz 0,0xc4(31); rlwinm 0,0,0,31,29; stw 0,0xc4(31); b 6f; 4:; andi. 9,0,2048; beq 5f; addi 0,31,8; mr 5,29; mr 3,0; addi 4,31,52; li 6,2; mr 29,0; bl _s8022176C_6; b 6f; 5:; mr 3,29; addi 30,31,8; bl _s8022176C_7; mr 5,29; addi 4,31,52; mr 3,30; mr 29,30; bl _s8022176C_8; 6:; mr 3,29; bl _s8022176C_9; lwz 0,0xc4(31); andi. 0,0,17; bne 7f; addi 30,31,32; stw 0,0xd0(31); mr 3,29; mr 4,30; li 5,2; bl _s8022176C_10; lwz 11,0x20(31); addi 9,31,96; lwz 0,0x8(30); addi 8,31,108; lwz 10,0x4(30); stw 11,0x60(31); stw 0,0x8(9); stw 10,0x4(9); lwz 0,0x20(31); lwz 9,0x8(30); lwz 11,0x4(30); stw 0,0x6c(31); stw 9,0x8(8); stw 11,0x4(8); b 8f; 7:; mr 3,31; bl _s8022176C_11; mr 3,31; bl _s8022176C_12; 8:; lwz 0,0xc4(31); andi. 9,0,32; beq 9f; mr 3,31; bl _s8022176C_13; 9:; lwz 0,0xc4(31); andi. 9,0,4096; beq 10f; mr 3,31; bl _s8022176C_14; 10:; lwz 4,0xd0(31); mr 3,31; bl _s8022176C_15; lwz 0,0xc4(31); andi. 9,0,64; beq 11f; mr 3,31; bl _s8022176C_16; 11:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s8022176C_0();
extern "C" void _s8022176C_1();
extern "C" void _s8022176C_2();
extern "C" void _s8022176C_3();
extern "C" void _s8022176C_4();
extern "C" void _s8022176C_5();
extern "C" void _s8022176C_6();
extern "C" void _s8022176C_7();
extern "C" void _s8022176C_8();
extern "C" void _s8022176C_9();
extern "C" void _s8022176C_10();
extern "C" void _s8022176C_11();
extern "C" void _s8022176C_12();
extern "C" void _s8022176C_13();
extern "C" void _s8022176C_14();
extern "C" void _s8022176C_15();
extern "C" void _s8022176C_16();
extern "C" void f_8022176C() {}
