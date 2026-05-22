// 0x80208DA0 InteractorModule::FloorPainter::CancelSession(void) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); mr 11,3; lis 9,-32697; lwz 0,0xa4(11); addi 29,1,8; lwz 10,0xa0(11); addi 9,9,-32192; stw 9,0x8(29); addi 11,11,128; subfic 9,0,0; adde 0,9,0; stw 10,0x1c(1); li 9,3; stw 0,0x14(1); stw 9,0x8(1); mr 3,29; lis 30,-32697; lwz 0,0x8(11); addi 30,30,-32168; stw 0,0x4(29); lwz 0,0xc(11); mtspr 8,0; blrl; stw 30,0x8(29); lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void f_80208DA0() {}
