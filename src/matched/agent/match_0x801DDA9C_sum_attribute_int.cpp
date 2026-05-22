// 0x801DDA9C sum_attribute(int, (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; mfcr 12; stmw 25,0xc(1); stw 0,0x2c(1); stw 12,0x8(1); mr 30,3; mr. 25,4; beq 0f; bl _s801DDA9C_0; mr. 26,3; bne 1f; 0:; li 3,0; b 16f; 1:; cmpwi 30,0; li 31,0; cmpwi 7,30,2; li 29,0; mfcr 27; mfcr 28; rlwinm 28,28,28,0,3; cmpwi 2,30,3; cmpwi 3,30,10; cmpwi 4,30,12; 2:; lbzx 4,25,29; cmpwi 4,0; beq 15f; mr 3,26; bl _s801DDA9C_1; cmpwi 30,7; beq 9f; bgt 4f; cmpwi 30,1; beq 6f; bgt 3f; mtcrf 128,27; beq 5f; b 15f; 3:; mtcrf 128,28; beq 7f; beq cr2,8f; b 15f; 4:; cmpwi 30,9; beq 11f; blt 10f; beq cr3,12f; beq cr4,13f; b 15f; 5:; lwz 0,0x18(3); b 14f; 6:; lwz 0,0x1c(3); b 14f; 7:; lwz 0,0x20(3); b 14f; 8:; lwz 0,0x24(3); b 14f; 9:; lwz 0,0x38(3); b 14f; 10:; lwz 0,0x3c(3); b 14f; 11:; lwz 0,0x2c(3); b 14f; 12:; lwz 0,0x34(3); b 14f; 13:; lwz 0,0x30(3); 14:; add 31,31,0; 15:; addi 29,29,1; cmplwi 29,3; ble 2b; mr 3,31; 16:; lwz 0,0x2c(1); lwz 12,0x8(1); mtspr 8,0; lmw 25,0xc(1); mtcrf 56,12; addi 1,1,40"
extern "C" void _s801DDA9C_0();
extern "C" void _s801DDA9C_1();
extern "C" void f_801DDA9C() {}
