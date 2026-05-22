// 0x801F1094 INVTarget::SetAllObjectRelatedCheatStrings(InteractorModule::WallPaperData (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; mr 31,3; lwz 9,0x0(30); addi 4,31,4491; li 6,0; lwz 9,0x4(9); cmpwi 9,0; beq 0f; lwz 6,0x0(9); 0:; mr 3,31; li 5,2048; bl _s801F1094_0; lis 6,-32704; mr 3,31; addi 6,6,-28448; addi 4,31,6539; li 5,2048; bl _s801F1094_1; lwz 9,0x0(30); mr 3,31; addi 4,3,8587; li 5,2048; lhz 6,0x2(9); bl _s801F1094_2; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801F1094_0();
extern "C" void _s801F1094_1();
extern "C" void _s801F1094_2();
extern "C" void f_801F1094() {}
