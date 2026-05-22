// 0x80377960 ARQPostRequest (348 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; cmplwi 10,0; stw 0,0x4(1); li 0,0; stwu 1,-56(1); stw 31,0x34(1); stw 30,0x30(1); addi 30,6,0; stw 29,0x2c(1); addi 29,3,0; stw 0,0x0(3); stw 4,0x4(3); stw 5,0x8(3); stw 7,0x10(3); stw 8,0x14(3); stw 9,0x18(3); beq 0f; stw 10,0x1c(29); b 1f; 0:; lis 3,-32713; addi 0,3,30684; stw 0,0x1c(29); 1:; bl _s80377960_0; cmpwi 30,1; addi 31,3,0; beq 5f; bge 8f; cmpwi 30,0; bge 2f; b 8f; 2:; lwz 0,-22328(13); cmplwi 0,0; beq 3f; lwz 3,-22324(13); stw 29,0x0(3); b 4f; 3:; stw 29,-22328(13); 4:; stw 29,-22324(13); b 8f; 5:; lwz 0,-22336(13); cmplwi 0,0; beq 6f; lwz 3,-22332(13); stw 29,0x0(3); b 7f; 6:; stw 29,-22336(13); 7:; stw 29,-22332(13); 8:; lwz 0,-22312(13); cmplwi 0,0; bne 12f; lwz 0,-22308(13); cmplwi 0,0; bne 12f; lwz 6,-22336(13); cmplwi 6,0; beq 11f; lwz 3,0x8(6); cmplwi 3,0; bne 9f; lwz 4,0x10(6); lwz 5,0x14(6); lwz 6,0x18(6); bl _s80377960_1; b 10f; 9:; lwz 4,0x14(6); lwz 5,0x10(6); lwz 6,0x18(6); bl _s80377960_2; 10:; lwz 3,-22336(13); lwz 0,0x1c(3); stw 0,-22304(13); stw 3,-22312(13); lwz 0,0x0(3); stw 0,-22336(13); 11:; lwz 0,-22312(13); cmplwi 0,0; bne 12f; bl _s80377960_3; 12:; mr 3,31; bl _s80377960_4; lwz 0,0x3c(1); lwz 31,0x34(1); lwz 30,0x30(1); lwz 29,0x2c(1); addi 1,1,56; mtspr 8,0"
extern "C" void _s80377960_0();
extern "C" void _s80377960_1();
extern "C" void _s80377960_2();
extern "C" void _s80377960_3();
extern "C" void _s80377960_4();
extern "C" void f_80377960() {}
