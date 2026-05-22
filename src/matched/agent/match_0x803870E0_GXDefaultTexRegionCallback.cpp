// 0x803870E0 __GXDefaultTexRegionCallback (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); mr 29,3; mr 30,4; mr 3,29; bl _s803870E0_0; mr 31,3; mr 3,29; bl _s803870E0_1; srawi 4,30,3; addze 4,4; rlwinm 4,4,3,0,28; cmpwi 31,7; subfc 4,4,30; beq 4f; bge 0f; cmpwi 31,6; bge 1f; b 4f; 0:; cmpwi 31,11; bge 4f; b 3f; 1:; rlwinm 0,3,0,24,31; cmplwi 0,0; beq 2f; rlwinm 3,4,4,0,27; lwz 0,-17720(13); addi 3,3,776; add 3,0,3; b 6f; 2:; rlwinm 3,4,4,0,27; lwz 0,-17720(13); addi 3,3,648; add 3,0,3; b 6f; 3:; rlwinm 3,4,4,0,27; lwz 0,-17720(13); addi 3,3,520; add 3,0,3; b 6f; 4:; rlwinm 0,3,0,24,31; cmplwi 0,0; beq 5f; rlwinm 3,4,4,0,27; lwz 0,-17720(13); addi 3,3,648; add 3,0,3; b 6f; 5:; rlwinm 3,4,4,0,27; lwz 0,-17720(13); addi 3,3,520; add 3,0,3; 6:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s803870E0_0();
extern "C" void _s803870E0_1();
extern "C" void f_803870E0() {}
