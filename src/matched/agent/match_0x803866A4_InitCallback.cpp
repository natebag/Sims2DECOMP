// 0x803866A4 InitCallback (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 4,-32688; stw 0,0x4(1); addi 4,4,-24000; addi 0,4,48; stwu 1,-24(1); cmplw 0,3; stw 31,0x14(1); beq 0f; addi 0,4,320; cmplw 0,3; addi 4,4,272; 0:; lwz 31,0x80(4); lis 3,-256; bl _s803866A4_0; 1:; bl _s803866A4_1; cmplwi 3,0; bne 1b; mr 3,31; bl _s803866A4_2; 2:; bl _s803866A4_3; cmplwi 3,0; bne 2b; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s803866A4_0();
extern "C" void _s803866A4_1();
extern "C" void _s803866A4_2();
extern "C" void _s803866A4_3();
extern "C" void f_803866A4() {}
