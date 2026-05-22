// 0x801BB918 INGTarget::update_current_items(unsigned (320 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; mfcr 12; stmw 23,0xc(1); stw 0,0x34(1); stw 12,0x8(1); mr 31,4; mr 27,3; addi 3,27,432; li 4,0; li 5,48; bl _s801BB918_0; cmplwi 31,9; bgt 0f; mulli 0,31,12; addi 9,27,312; lwzx 4,9,0; mr 10,0; cmpwi 4,0; bne 1f; 0:; li 3,0; b 9f; 1:; add 9,27,10; lha 0,0x13c(9); cmpwi 0,0; beq 2f; mr 23,0; b 3f; 2:; lha 23,0x0(4); 3:; addi 9,27,516; li 25,0; lwzx 0,9,25; mr 31,9; addi 11,27,320; li 24,0; lwzx 9,11,10; cmpwi 0,0; beq 8f; cmpwi 4,9,0; mr 26,31; mr 28,31; li 30,0; addi 29,27,432; 4:; mr 3,27; mr 4,28; bl _s801BB918_1; cmpw 3,23; bne 7f; beq cr4,5f; lwzx 9,30,31; lha 0,0x2(9); cmpwi 0,0; bne 7f; b 6f; 5:; lwzx 9,30,31; lha 0,0x2(9); cmpwi 0,0; beq 7f; 6:; stw 26,0x0(29); addi 24,24,1; addi 29,29,4; cmplwi 24,11; bgt 8f; 7:; addi 25,25,1; addi 26,26,8; addi 28,28,8; addi 30,30,8; cmplwi 25,71; bgt 8f; lwzx 0,30,31; cmpwi 0,0; bne 4b; 8:; li 3,1; 9:; lwz 0,0x34(1); lwz 12,0x8(1); mtspr 8,0; lmw 23,0xc(1); mtcrf 8,12; addi 1,1,48"
extern "C" void _s801BB918_0();
extern "C" void _s801BB918_1();
extern "C" void f_801BB918() {}
