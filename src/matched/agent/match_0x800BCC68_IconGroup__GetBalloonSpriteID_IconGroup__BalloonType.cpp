// 0x800BCC68 IconGroup::GetBalloonSpriteID(IconGroup::BalloonType) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); mr 31,3; li 30,0; addi 3,1,8; bl _s800BCC68_0; addi 3,1,8; li 4,1; bl _s800BCC68_1; cmpwi 31,1; beq 3f; bgt 0f; cmpwi 31,0; beq 1f; b 5f; 0:; cmpwi 31,2; beq 2f; b 5f; 1:; addi 3,1,8; li 4,0; b 4f; 2:; addi 3,1,8; li 4,2; b 4f; 3:; addi 3,1,8; li 4,1; 4:; bl _s800BCC68_2; mr 30,3; 5:; addi 3,1,8; li 4,2; bl _s800BCC68_3; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s800BCC68_0();
extern "C" void _s800BCC68_1();
extern "C" void _s800BCC68_2();
extern "C" void _s800BCC68_3();
extern "C" void f_800BCC68() {}
