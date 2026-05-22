// 0x802EA128 EAnimController::AllocMatrices(void) (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 11,-26812(13); lwz 0,0x2c(31); cmpw 0,11; beq 3f; lwz 0,-26816(13); addi 9,31,28; stw 11,0x2c(31); rlwinm 0,0,2,0,29; lwzx 0,9,0; cmpwi 0,0; bne 2f; lwz 0,0x24(31); mr 4,0; cmpwi 0,0; li 0,0; beq 0f; lwz 0,0x18(4); 0:; cmpwi 0,0; beq 2f; cmpwi 4,0; li 0,0; beq 1f; lwz 0,0x18(4); 1:; lis 9,-32693; rlwinm 4,0,6,0,25; addi 9,9,3420; li 5,16; lwz 3,0x34(9); mulli 3,3,24; addi 3,3,4; add 3,3,9; bl _s802EA128_0; stw 3,0x10(31); b 3f; 2:; stw 0,0x10(31); 3:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802EA128_0();
extern "C" void f_802EA128() {}
