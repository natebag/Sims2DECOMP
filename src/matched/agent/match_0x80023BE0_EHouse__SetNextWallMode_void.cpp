// 0x80023BE0 EHouse::SetNextWallMode(void) (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x24(31); cmpwi 0,1; beq 2f; bgt 0f; cmpwi 0,0; beq 1f; b 3f; 0:; cmpwi 0,2; b 3f; 1:; li 0,1; b 4f; 2:; li 0,2; b 4f; 3:; li 0,0; 4:; stw 0,0x24(31); lwz 3,0x8(31); cmpwi 3,0; beq 5f; lwz 4,0x24(31); bl _s80023BE0_0; lwz 9,0x1c(31); lwz 0,0x24(31); addis 9,9,3; stw 0,-7468(9); 5:; lwz 3,-26392(13); lwz 9,0x0(3); lha 0,0x40(9); lwz 9,0x44(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80023BE0_0();
extern "C" void f_80023BE0() {}
