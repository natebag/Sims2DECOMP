// 0x801D1D0C sort_wallpaper_by_name(void (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); cmpw 3,4; bne 0f; li 3,0; b 3f; 0:; lwz 9,0x14(3); li 11,0; lwz 4,0x14(4); lwz 3,0x4(9); cmpwi 3,0; beq 1f; lwz 11,0x0(3); 1:; lwz 4,0x4(4); li 0,0; cmpwi 4,0; beq 2f; lwz 0,0x0(4); 2:; mr 3,11; mr 4,0; bl _s801D1D0C_0; 3:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801D1D0C_0();
extern "C" void f_801D1D0C() {}
