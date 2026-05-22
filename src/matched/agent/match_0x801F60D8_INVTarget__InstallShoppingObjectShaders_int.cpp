// 0x801F60D8 INVTarget::InstallShoppingObjectShaders(int) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0x178(3); rlwinm 4,4,3,0,28; lwzx 11,9,4; add 9,9,4; lwz 0,0x4(9); cmpwi 11,9; mulli 5,0,12; beq 0f; blt 3f; cmpwi 11,10; beq 1f; cmpwi 11,11; beq 2f; b 3f; 0:; lwz 4,0x164(3); bl _s801F60D8_0; b 4f; 1:; lwz 4,0x168(3); bl _s801F60D8_1; b 4f; 2:; lwz 4,0x16c(3); bl _s801F60D8_2; b 4f; 3:; cmplwi 11,14; bgt 4f; rlwinm 0,11,2,0,29; addi 9,3,320; lwzx 4,9,0; bl _s801F60D8_3; 4:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801F60D8_0();
extern "C" void _s801F60D8_1();
extern "C" void _s801F60D8_2();
extern "C" void _s801F60D8_3();
extern "C" void f_801F60D8() {}
