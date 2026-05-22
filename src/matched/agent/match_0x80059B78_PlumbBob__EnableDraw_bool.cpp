// 0x80059B78 PlumbBob::EnableDraw(bool) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr. 4,4; beq 0f; lwz 0,0x154(3); ori 0,0,1; b 1f; 0:; lwz 0,0x154(3); rlwinm 0,0,0,0,30; 1:; stw 0,0x154(3); cmpwi 4,0; bne 4f; lwz 0,0x154(3); andi. 9,0,4; beq 2f; ori 0,0,8; b 3f; 2:; rlwinm 0,0,0,29,27; 3:; stw 0,0x154(3); bl _s80059B78_0; b 5f; 4:; lwz 4,0x154(3); rlwinm 4,4,29,31,31; bl _s80059B78_1; 5:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80059B78_0();
extern "C" void _s80059B78_1();
extern "C" void f_80059B78() {}
