// 0x8022FA6C ELightGrid::ELightGrid(void) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); li 0,512; mr 31,3; mtspr 9,0; 0:; bdnz 0b; li 11,40; mtspr 9,11; 1:; bdnz 1b; li 0,4; mtspr 9,0; 2:; bdnz 2b; li 11,4; mtspr 9,11; 3:; bdnz 3b; li 11,4; li 0,-1; mtspr 9,11; addi 9,13,-23766; 4:; sth 0,0x0(9); addi 9,9,-2; bdnz 4b; li 0,0; mr 3,31; stw 0,0x8(31); bl _s8022FA6C_0; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8022FA6C_0();
extern "C" void f_8022FA6C() {}
