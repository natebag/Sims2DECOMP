// 0x800B6F74 FloatConstantsQuickData::Load(iResFile (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; mr. 4,4; beq 1f; lwz 3,0x8(4); cmpwi 3,0; beq 1f; lwz 3,0x30(3); li 4,0; cmpwi 3,0; beq 0f; lwz 4,-4(3); 0:; rlwinm 4,4,3,0,28; add 4,3,4; bl _s800B6F74_0; stw 3,0xc(31); li 3,0; b 2f; 1:; li 3,-98; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800B6F74_0();
extern "C" void f_800B6F74() {}
