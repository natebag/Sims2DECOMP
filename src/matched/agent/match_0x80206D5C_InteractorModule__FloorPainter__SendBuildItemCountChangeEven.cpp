// 0x80206D5C InteractorModule::FloorPainter::SendBuildItemCountChangeEvent(int) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 27,0x24(1); stw 0,0x3c(1); lis 9,-32697; addi 29,1,8; mr 30,3; addi 9,9,-32192; lis 28,-32697; mr 27,4; addi 28,28,-32168; stw 9,0x8(29); bl _s80206D5C_0; lwz 0,0xa0(30); li 9,5; stw 3,0x14(1); addi 30,30,128; stw 27,0x18(1); mr 3,29; stw 0,0x1c(1); stw 9,0x8(1); lwz 0,0x8(30); stw 0,0x4(29); lwz 0,0xc(30); mtspr 8,0; blrl; stw 28,0x8(29); lwz 0,0x3c(1); mtspr 8,0; lmw 27,0x24(1); addi 1,1,56"
extern "C" void _s80206D5C_0();
extern "C" void f_80206D5C() {}
