// 0x80224A3C InteractorModule::WallPainter::HandleExitRequest(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 9,0x88(31); andi. 0,9,1; beq 0f; li 0,-66; lis 3,-32704; and 0,9,0; addi 3,3,-7340; stw 0,0x88(31); crxor 6,6,6; bl _s80224A3C_0; b 1f; 0:; lis 3,-32704; stw 0,0x88(31); addi 3,3,-7304; crxor 6,6,6; bl _s80224A3C_1; mr 3,31; bl _s80224A3C_2; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80224A3C_0();
extern "C" void _s80224A3C_1();
extern "C" void _s80224A3C_2();
extern "C" void f_80224A3C() {}
