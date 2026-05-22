// 0x802F1BB8 EGraphics::LoadSystemFont(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; lwz 0,0x90(30); cmpwi 0,0; bne 0f; lis 9,-32702; lis 29,-32692; addi 31,9,-4016; mr 3,31; bl _s802F1BB8_0; mr 4,3; addi 3,29,-30916; bl _s802F1BB8_1; cmpwi 3,0; beq 0f; mr 3,31; bl _s802F1BB8_2; mr 4,3; li 5,0; addi 3,29,-30916; li 6,0; bl _s802F1BB8_3; stw 3,0x90(30); 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802F1BB8_0();
extern "C" void _s802F1BB8_1();
extern "C" void _s802F1BB8_2();
extern "C" void _s802F1BB8_3();
extern "C" void f_802F1BB8() {}
