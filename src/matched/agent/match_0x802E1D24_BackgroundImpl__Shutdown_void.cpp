// 0x802E1D24 BackgroundImpl::Shutdown(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 9,0x0(30); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x0(30); lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,30,3; blrl; addi 3,30,8; bl _s802E1D24_0; addi 3,30,872; bl _s802E1D24_1; li 0,0; stw 0,0x348(30); stw 0,-22756(13); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802E1D24_0();
extern "C" void _s802E1D24_1();
extern "C" void f_802E1D24() {}
