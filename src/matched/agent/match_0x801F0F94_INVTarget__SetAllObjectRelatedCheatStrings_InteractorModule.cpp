// 0x801F0F94 INVTarget::SetAllObjectRelatedCheatStrings(InteractorModule::WallData (256 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,4; mr 31,3; lwz 0,0x4(30); cmpwi 0,-1; bne 1f; lis 4,-32697; lis 5,-32704; addi 4,4,24012; addi 5,5,-26072; addi 3,1,8; crxor 6,6,6; bl _s801F0F94_0; lwz 9,0x8(1); addi 4,31,4491; li 6,0; cmpwi 9,0; beq 0f; lwz 6,0x0(9); 0:; mr 3,31; li 5,2048; bl _s801F0F94_1; lis 6,-32704; mr 3,31; addi 6,6,-28448; addi 4,31,6539; li 5,2048; bl _s801F0F94_2; mr 3,31; li 5,2048; addi 4,3,8587; li 6,20; bl _s801F0F94_3; b 3f; 1:; lwz 9,0x0(30); addi 4,31,4491; li 6,0; lwz 9,0x8(9); cmpwi 9,0; beq 2f; lwz 6,0x0(9); 2:; mr 3,31; li 5,2048; bl _s801F0F94_4; lis 6,-32704; mr 3,31; addi 6,6,-28448; addi 4,31,6539; li 5,2048; bl _s801F0F94_5; lwz 9,0x0(30); mr 3,31; addi 4,3,8587; li 5,2048; lhz 6,0x6(9); bl _s801F0F94_6; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s801F0F94_0();
extern "C" void _s801F0F94_1();
extern "C" void _s801F0F94_2();
extern "C" void _s801F0F94_3();
extern "C" void _s801F0F94_4();
extern "C" void _s801F0F94_5();
extern "C" void _s801F0F94_6();
extern "C" void f_801F0F94() {}
