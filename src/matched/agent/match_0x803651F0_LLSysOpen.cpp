// 0x803651F0 LLSysOpen (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,4; mr 5,3; lis 4,-32702; addi 3,13,-25848; addi 4,4,12668; li 6,152; bl _s803651F0_0; lwz 0,-25848(13); li 3,-1; cmpwi 0,0; beq 1f; lis 4,-32702; mr 5,31; addi 4,4,12672; addi 3,13,-25844; li 6,16; bl _s803651F0_1; lwz 0,-25844(13); cmpwi 0,0; beq 0f; li 0,0; li 3,0; stw 0,-25840(13); b 1f; 0:; li 3,-1; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s803651F0_0();
extern "C" void _s803651F0_1();
extern "C" void f_803651F0() {}
