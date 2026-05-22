// 0x801F0050 INVTarget::OnSetCurrentTab(int) (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x90(31); cmpwi 0,0; bne 0f; li 3,0; b 3f; 0:; cmpwi 4,0; bge 1f; lwz 9,0xbc(31); addi 4,9,-1; b 2f; 1:; lwz 0,0xbc(31); cmpw 4,0; blt 2f; li 4,0; 2:; lwz 9,0x84(31); addi 8,13,-28708; addi 10,13,-28700; li 11,0; rlwinm 9,9,2,0,29; stwx 4,9,8; lwz 0,0x84(31); rlwinm 0,0,2,0,29; stwx 11,10,0; lwz 9,0x84(31); rlwinm 9,9,2,0,29; lwzx 3,9,8; bl _s801F0050_0; mr 4,3; mr 3,31; bl _s801F0050_1; li 3,1; 3:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801F0050_0();
extern "C" void _s801F0050_1();
extern "C" void f_801F0050() {}
