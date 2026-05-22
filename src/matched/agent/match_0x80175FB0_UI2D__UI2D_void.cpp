// 0x80175FB0 UI2D::UI2D(void) (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lis 9,-32698; mr 30,3; li 0,0; addi 9,9,25856; lis 11,-32698; stw 9,0xc(30); stw 0,0x8(30); addi 27,11,25880; stw 0,0x0(30); li 28,0; stw 0,0x4(30); li 31,0; li 29,400; 0:; li 3,48; bl _s80175FB0_0; lwz 0,0x8(30); stw 27,0x2c(3); cmpwi 0,0; stw 31,0x0(3); stw 31,0x4(3); stw 31,0x8(3); stw 31,0xc(3); stw 31,0x10(3); stw 31,0x14(3); stw 31,0x18(3); stw 31,0x1c(3); stw 31,0x20(3); stw 31,0x24(3); stw 31,0x28(3); bne 1f; stw 3,0x8(30); b 2f; 1:; stw 3,0x4(28); stw 28,0x0(3); 2:; mr 28,3; addic. 29,29,-1; bne 0b; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80175FB0_0();
extern "C" void f_80175FB0() {}
