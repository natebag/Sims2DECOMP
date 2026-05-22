// 0x80179A54 UIDB::UIDBShutdown(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32696; li 30,0; addi 31,9,31252; addi 29,31,900; 0:; lwz 0,0x4(31); cmpwi 0,115; bne 2f; lwz 0,0x8(31); cmpwi 0,0; beq 1f; bl _s80179A54_0; lwz 4,0x8(31); bl _s80179A54_1; stw 30,0x8(31); 1:; stw 30,0x4(31); 2:; addi 31,31,12; cmpw 31,29; ble 0b; li 0,0; stw 0,-31520(13); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80179A54_0();
extern "C" void _s80179A54_1();
extern "C" void f_80179A54() {}
