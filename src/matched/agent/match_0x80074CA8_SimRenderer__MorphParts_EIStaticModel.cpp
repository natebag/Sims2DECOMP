// 0x80074CA8 SimRenderer::MorphParts(EIStaticModel (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; mfcr 12; stmw 29,0xc(1); stw 0,0x1c(1); stw 12,0x8(1); mr 31,3; cmpwi 4,4,0; li 29,0; li 30,0; 0:; lwzx 3,30,31; cmpwi 3,0; beq 2f; lwz 3,0x120(3); cmpwi 7,29,1; cmpwi 3,0; beq 2f; bne cr7,1f; beq cr4,2f; 1:; bl _s80074CA8_0; lwzx 9,30,31; lwz 3,0x120(9); bl _s80074CA8_1; lwzx 9,30,31; lwz 3,0x120(9); bl _s80074CA8_2; lwzx 9,30,31; lwz 3,0x120(9); bl _s80074CA8_3; 2:; addi 29,29,1; addi 30,30,4; cmpwi 29,25; ble 0b; lwz 0,0x1c(1); lwz 12,0x8(1); mtspr 8,0; lmw 29,0xc(1); mtcrf 8,12; addi 1,1,24"
extern "C" void _s80074CA8_0();
extern "C" void _s80074CA8_1();
extern "C" void _s80074CA8_2();
extern "C" void _s80074CA8_3();
extern "C" void f_80074CA8() {}
