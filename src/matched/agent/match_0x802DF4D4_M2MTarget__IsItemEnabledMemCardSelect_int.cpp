// 0x802DF4D4 M2MTarget::IsItemEnabledMemCardSelect(int) (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 31,0; beq 0f; cmpwi 0,0; li 5,1; beq 2f; b 1f; 0:; cmpwi 0,0; li 5,1; bne 2f; 1:; li 5,0; 2:; mr 3,30; mr 4,29; bl _s802DF4D4_0; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 4,0x4(3); lwz 3,0x0(3); bl _s802DF4D4_1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; mr 30,3; li 0,0; addi 9,9,-23560; stw 9,0x10(30); stw 0,0x4(30); li 4,4096; stw 0,0x0(30); stw 0,0x8(30); bl _s802DF4D4_2; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802DF4D4_0();
extern "C" void _s802DF4D4_1();
extern "C" void _s802DF4D4_2();
extern "C" void f_802DF4D4() {}
