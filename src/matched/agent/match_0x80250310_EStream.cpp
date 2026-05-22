// 0x80250310 EStream (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32768; lwz 3,0x30d0(3); cmplwi 3,0; beq 0f; lwz 0,0x14(31); add 0,0,3; stw 0,0x14(31); 0:; li 3,0; addi 4,31,0; bl _s80250310_0; lis 3,-32768; lwz 28,0x30c8(3); b 3f; 1:; addi 3,31,0; addi 4,28,0; bl _s80250310_1; cmplw 28,31; beq 2f; addi 3,28,0; addi 4,31,0; bl _s80250310_2; 2:; lwz 28,0x4(28); 3:; cmplwi 28,0; bne 1b; cmpwi 30,0; beq 7f; lwz 4,0x28(31); lwz 0,0x2c(31); addi 5,4,0; add 3,4,0; addi 0,3,7; subf 0,5,0; rlwinm 0,0,29,3,31; cmplw 5,3; mtspr 9,0; bge 7f; 4:; lwz 3,0x0(5); cmplwi 3,0; beq 5f; lwz 0,0x0(31); cmplw 3,0; bne 6f; 5:; subf 0,4,5; stw 0,0x2c(31); b 7f; 6:; addi 5,5,8; bdnz 4b; 7:; lwz 5,0x20(31); addi 3,29,0; li 4,0; bl _s80250310_3; mr 3,31; bl _s80250310_4; li 3,1; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); lwz 28,0x18(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s80250310_0();
extern "C" void _s80250310_1();
extern "C" void _s80250310_2();
extern "C" void _s80250310_3();
extern "C" void _s80250310_4();
extern "C" void f_80250310() {}
