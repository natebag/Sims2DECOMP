// 0x800356C8 ESpriteRender::Update(void) (456 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x0(31); cmpwi 0,0; bne 7f; lwz 4,0xc(31); cmpwi 4,0; beq 0f; lwz 0,0x10(31); cmpwi 0,0; bne 0f; lis 3,-32692; addi 3,3,-17444; bl _s800356C8_0; stw 3,0x10(31); 0:; lwz 4,0x14(31); cmpwi 4,0; beq 1f; lwz 0,0x18(31); cmpwi 0,0; bne 1f; lis 3,-32692; addi 3,3,-17444; bl _s800356C8_1; stw 3,0x18(31); 1:; lwz 4,0x1c(31); cmpwi 4,0; beq 2f; lwz 0,0x20(31); cmpwi 0,0; bne 2f; lis 3,-32692; addi 3,3,-17444; bl _s800356C8_2; stw 3,0x20(31); 2:; lwz 4,0x28(31); cmpwi 4,0; beq 3f; lwz 0,0x24(31); cmpwi 0,0; bne 3f; lis 3,-32692; addi 3,3,-17444; bl _s800356C8_3; stw 3,0x24(31); 3:; lwz 4,0x30(31); cmpwi 4,0; beq 4f; lwz 0,0x2c(31); cmpwi 0,0; bne 4f; lis 3,-32692; addi 3,3,-17444; bl _s800356C8_4; stw 3,0x2c(31); 4:; lwz 11,0x8(31); lwz 9,0x4(11); lwz 0,0x5c(9); lha 3,0x58(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x10(3); li 9,1; cmpwi 0,0; bne 5f; li 9,0; 5:; cmpwi 9,0; bne 6f; lwz 3,0x8(31); lwz 9,0x4(3); lha 0,0x368(9); lwz 9,0x36c(9); add 3,3,0; mtspr 8,9; blrl; bl _s800356C8_5; cmpwi 3,0; beq 7f; lwz 11,0x8(31); li 4,0; lwz 9,0x0(11); lwz 3,0x14(9); bl _s800356C8_6; b 7f; 6:; lwz 3,0x8(31); lwz 9,0x4(3); lha 0,0x368(9); lwz 9,0x36c(9); add 3,3,0; mtspr 8,9; blrl; bl _s800356C8_7; cmpwi 3,0; beq 7f; lwz 0,0xc(31); cmpwi 0,0; beq 7f; lwz 9,0x8(31); lwz 11,0x0(9); lwz 3,0x14(11); lwz 0,0x3ec(3); cmpwi 0,0; bne 7f; li 4,10; bl _s800356C8_8; 7:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800356C8_0();
extern "C" void _s800356C8_1();
extern "C" void _s800356C8_2();
extern "C" void _s800356C8_3();
extern "C" void _s800356C8_4();
extern "C" void _s800356C8_5();
extern "C" void _s800356C8_6();
extern "C" void _s800356C8_7();
extern "C" void _s800356C8_8();
extern "C" void f_800356C8() {}
