// 0x8025B0D0 isSame (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); addi 30,4,0; stw 29,0x14(1); addi 29,3,0; b 1f; 0:; lbz 0,0x0(30); addi 30,30,1; extsb 3,0; bl _s8025B0D0_0; lbz 0,0x0(29); addi 31,3,0; addi 29,29,1; extsb 3,0; bl _s8025B0D0_1; cmpw 3,31; beq 1f; li 3,0; b 4f; 1:; lbz 0,0x0(30); extsb. 0,0; bne 0b; lbz 3,0x0(29); cmpwi 3,47; beq 2f; extsb. 0,3; bne 3f; 2:; li 3,1; b 4f; 3:; li 3,0; 4:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8025B0D0_0();
extern "C" void _s8025B0D0_1();
extern "C" void f_8025B0D0() {}
