// 0x80182904 WidgetScreenFormat::IsValidTag(char (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); lis 9,-32706; mr 27,4; addi 30,9,16216; li 29,0; li 28,0; lis 26,-32705; 0:; lwz 31,0x0(30); addi 4,26,-23988; addi 30,30,8; mr 3,31; bl _s80182904_0; cmpwi 3,0; bne 1f; li 28,1; b 2f; 1:; mr 3,31; mr 4,27; bl _s80182904_1; cmpwi 3,0; bne 2f; li 29,1; 2:; cmpwi 29,0; bne 3f; cmpwi 28,0; beq 0b; 3:; mr 3,29; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s80182904_0();
extern "C" void _s80182904_1();
extern "C" void f_80182904() {}
