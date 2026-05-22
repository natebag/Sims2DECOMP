// 0x80392FC8 THPVideoDecode (580 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-56(1); stmw 27,0x24(1); mr. 27,3; addi 28,4,0; addi 29,5,0; addi 30,6,0; addi 31,7,0; beq 12f; cmplwi 28,0; beq 13f; cmplwi 29,0; beq 13f; cmplwi 30,0; beq 13f; cmplwi 31,0; beq 14f; bl _s80392FC8_0; rlwinm. 0,3,0,3,3; beq 18f; lwz 0,-21548(13); cmpwi 0,0; beq 19f; stw 31,-21556(13); li 4,1724; lwz 3,-21556(13); addi 0,3,31; rlwinm 3,0,0,0,26; stw 3,-21552(13); addi 0,3,1724; stw 0,-21556(13); lwz 3,-21552(13); bl _s80392FC8_1; lwz 3,-21552(13); li 4,33; li 0,0; stw 4,0x6a4(3); li 31,0; lwz 3,-21552(13); sth 0,0x698(3); lwz 3,-21552(13); stw 27,0x69c(3); 0:; lwz 4,-21552(13); lwz 3,0x69c(4); addi 0,3,1; stw 0,0x69c(4); lbz 0,0x0(3); cmplwi 0,255; bne 16f; b 2f; 1:; lwz 3,0x0(4); addi 0,3,1; stw 0,0x0(4); 2:; lwz 3,-21552(13); addi 4,3,1692; lwz 3,0x69c(3); lbz 0,0x0(3); cmplwi 0,255; beq 1b; addi 0,3,1; stw 0,0x0(4); lbz 0,0x0(3); cmplwi 0,215; bgt 4f; cmplwi 0,196; bne 3f; bl _s80392FC8_2; rlwinm. 0,3,0,24,31; bne 17f; b 11f; 3:; cmplwi 0,192; bne 15f; bl _s80392FC8_3; rlwinm. 0,3,0,24,31; bne 17f; b 11f; 4:; cmplwi 0,216; blt 8f; cmplwi 0,223; bgt 8f; cmplwi 0,221; bne 5f; bl _s80392FC8_4; b 11f; 5:; cmplwi 0,219; bne 6f; bl _s80392FC8_5; rlwinm. 0,3,0,24,31; bne 17f; b 11f; 6:; cmplwi 0,218; bne 7f; bl _s80392FC8_6; rlwinm. 0,3,0,24,31; bne 17f; li 31,1; b 11f; 7:; cmplwi 0,216; beq 11f; b 15f; 8:; cmplwi 0,224; blt 11f; blt 9f; cmplwi 0,239; ble 10f; 9:; cmplwi 0,254; bne 15f; 10:; lwz 3,-21552(13); lwz 4,0x69c(3); addi 5,3,1692; lbz 3,0x0(4); lbz 0,0x1(4); rlwimi 0,3,8,16,23; add 0,4,0; stw 0,0x0(5); 11:; rlwinm. 0,31,0,24,31; beq 0b; bl _s80392FC8_7; addi 3,28,0; addi 4,29,0; addi 5,30,0; bl _s80392FC8_8; li 3,0; b 20f; 12:; li 3,25; b 20f; 13:; li 3,27; b 20f; 14:; li 3,26; b 20f; 15:; li 3,11; b 20f; 16:; li 3,3; b 20f; 17:; rlwinm 3,3,0,24,31; b 20f; 18:; li 3,28; b 20f; 19:; li 3,29; 20:; lmw 27,0x24(1); lwz 0,0x3c(1); addi 1,1,56; mtspr 8,0"
extern "C" void _s80392FC8_0();
extern "C" void _s80392FC8_1();
extern "C" void _s80392FC8_2();
extern "C" void _s80392FC8_3();
extern "C" void _s80392FC8_4();
extern "C" void _s80392FC8_5();
extern "C" void _s80392FC8_6();
extern "C" void _s80392FC8_7();
extern "C" void _s80392FC8_8();
extern "C" void f_80392FC8() {}
