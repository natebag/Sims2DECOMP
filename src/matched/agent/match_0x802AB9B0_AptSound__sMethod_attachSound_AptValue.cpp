// 0x802AB9B0 AptSound::sMethod_attachSound(AptValue (316 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 28,3; li 11,0; lwz 9,0x0(28); rlwinm 0,9,0,25,31; cmpwi 0,21; bne 0f; rlwinm 11,9,5,31,31; 0:; cmpwi 11,0; beq 4f; lis 9,-32694; lis 10,-32700; lwz 11,-16032(9); addi 8,10,-6476; addi 9,9,-16032; addi 4,1,8; lwz 0,0x8(9); rlwinm 11,11,2,0,29; lhz 9,-6476(10); li 29,0; add 11,11,0; lwz 3,-4(11); addi 9,9,1; sth 9,-6476(10); stw 8,0x8(1); lwz 9,0x24(28); addi 31,9,8; bl _s802AB9B0_0; lwz 0,0x28(31); cmpw 29,0; bge 3f; li 30,0; 1:; lwz 9,0x2c(31); lwz 3,0x8(1); lwzx 4,30,9; addi 3,3,8; bl _s802AB9B0_1; cmpwi 3,0; bne 2f; lwz 11,0x2c(31); lwz 10,0x10(31); add 11,30,11; lwz 9,0x4(11); rlwinm 9,9,2,0,29; lwzx 9,9,10; lwz 0,0x0(9); cmpwi 0,6; bne 3f; lwz 0,0x8(9); stw 0,0x28(28); lwz 9,0x2c(31); lwzx 0,30,9; stw 0,0x2c(28); b 3f; 2:; lwz 0,0x28(31); addi 29,29,1; addi 30,30,8; cmpw 29,0; blt 1b; 3:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 4f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802AB9B0_2; 4:; lwz 3,-22936(13); lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s802AB9B0_0();
extern "C" void _s802AB9B0_1();
extern "C" void _s802AB9B0_2();
extern "C" void f_802AB9B0() {}
