// 0x80029D2C EIWallPart::GetShadowModel(void) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; li 30,0; lwz 0,0x1c(31); addi 5,1,8; addi 6,1,10; cmpwi 0,0; beq 0f; lwz 3,0x28(31); li 4,0; mtspr 8,0; blrl; b 1f; 0:; sth 30,0xa(1); sth 30,0x8(1); 1:; lha 0,0x8(1); cmpwi 0,0; bne 4f; lwz 0,0x358(31); cmpwi 0,0; bne 2f; lwz 30,0x110(31); b 4f; 2:; lha 0,0x358(31); cmpwi 0,0; beq 3f; lha 0,0x35a(31); cmpwi 0,0; bne 4f; 3:; lwz 3,0x110(31); bl _s80029D2C_0; mr 30,3; 4:; cmpwi 30,0; beq 5f; lis 3,-32692; mr 4,30; addi 3,3,-27556; li 5,0; li 6,0; bl _s80029D2C_1; stw 3,0x3ac(31); 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s80029D2C_0();
extern "C" void _s80029D2C_1();
extern "C" void f_80029D2C() {}
