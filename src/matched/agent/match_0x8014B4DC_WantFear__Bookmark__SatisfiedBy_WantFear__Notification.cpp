// 0x8014B4DC WantFear::Bookmark::SatisfiedBy(WantFear::Notification (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 31,4; lwz 11,0x4(30); li 3,0; lhz 9,0x0(31); lhz 0,0x2(11); cmpw 0,9; bne 9f; mr 3,30; bl _s8014B4DC_0; cmpwi 3,0; beq 0f; mr 3,30; bl _s8014B4DC_1; lha 0,0x2(31); cmpw 3,0; li 3,0; bne 9f; 0:; lwz 3,0x4(30); lha 4,0x8(3); cmpwi 4,0; beq 8f; lbz 0,0x1c(3); extsb 0,0; cmpwi 0,2; beq 3f; bgt 1f; cmpwi 0,0; beq 8f; cmpwi 0,1; beq 2f; b 7f; 1:; cmpwi 0,4; beq 5f; blt 4f; cmpwi 0,5; beq 6f; b 7f; 2:; lha 0,0x4(31); cmpw 0,4; bge 7f; b 8f; 3:; lha 0,0x4(31); cmpw 0,4; bgt 7f; b 8f; 4:; lha 0,0x4(31); cmpw 0,4; bne 7f; b 8f; 5:; lha 0,0x4(31); cmpw 0,4; blt 7f; b 8f; 6:; lha 0,0x4(31); li 3,1; cmpw 0,4; bgt 9f; 7:; li 3,0; b 9f; 8:; li 3,1; 9:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8014B4DC_0();
extern "C" void _s8014B4DC_1();
extern "C" void f_8014B4DC() {}
