// 0x8017A64C UIDrawTable::UIDrawTable(void) (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); lis 9,-32698; mr 31,3; li 0,0; addi 9,9,26208; lis 11,-32698; stw 9,0xc(31); stw 0,0x8(31); addi 26,11,26232; stw 0,0x0(31); li 28,0; stw 0,0x4(31); li 30,0; li 27,75; li 29,64; 0:; li 3,24; bl _s8017A64C_0; lwz 0,0x8(31); stw 26,0x14(3); cmpwi 0,0; stw 30,0x0(3); stw 30,0x4(3); stw 27,0x8(3); stw 30,0xc(3); stw 30,0x10(3); bne 1f; stw 3,0x8(31); b 2f; 1:; stw 3,0x4(28); stw 28,0x0(3); 2:; mr 28,3; addic. 29,29,-1; bne 0b; mr 3,31; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s8017A64C_0();
extern "C" void f_8017A64C() {}
