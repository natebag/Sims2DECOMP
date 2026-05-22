// 0x80035588 ESpriteRender::DeleteShaders(void) (320 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,0x10(31); cmpwi 3,0; beq 0f; bl _s80035588_0; b 1f; 0:; lwz 4,0xc(31); cmpwi 4,0; beq 1f; lis 3,-32692; addi 3,3,-17444; bl _s80035588_1; 1:; lwz 3,0x18(31); li 0,0; stw 0,0x10(31); stw 0,0xc(31); cmpwi 3,0; beq 2f; bl _s80035588_2; b 3f; 2:; lwz 4,0x14(31); cmpwi 4,0; beq 3f; lis 3,-32692; addi 3,3,-17444; bl _s80035588_3; 3:; lwz 3,0x20(31); li 0,0; stw 0,0x18(31); stw 0,0x14(31); cmpwi 3,0; beq 4f; bl _s80035588_4; b 5f; 4:; lwz 4,0x1c(31); cmpwi 4,0; beq 5f; lis 3,-32692; addi 3,3,-17444; bl _s80035588_5; 5:; lwz 3,0x24(31); li 0,0; stw 0,0x20(31); stw 0,0x1c(31); cmpwi 3,0; beq 6f; bl _s80035588_6; b 7f; 6:; lwz 4,0x28(31); cmpwi 4,0; beq 7f; lis 3,-32692; addi 3,3,-17444; bl _s80035588_7; 7:; lwz 3,0x2c(31); li 0,0; stw 0,0x28(31); stw 0,0x24(31); cmpwi 3,0; beq 8f; bl _s80035588_8; b 9f; 8:; lwz 4,0x30(31); cmpwi 4,0; beq 9f; lis 3,-32692; addi 3,3,-17444; bl _s80035588_9; 9:; li 0,0; stw 0,0x30(31); stw 0,0x2c(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80035588_0();
extern "C" void _s80035588_1();
extern "C" void _s80035588_2();
extern "C" void _s80035588_3();
extern "C" void _s80035588_4();
extern "C" void _s80035588_5();
extern "C" void _s80035588_6();
extern "C" void _s80035588_7();
extern "C" void _s80035588_8();
extern "C" void _s80035588_9();
extern "C" void f_80035588() {}
