// 0x80056DB4 CLoadingScreen::Update(float) (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 0,0x38c(31); cmpwi 0,0; bne 3f; lwz 0,0x358(31); li 30,1; cmpwi 0,0; bne 0f; lis 3,-32692; lis 4,32602; addi 3,3,-17444; ori 4,4,48173; bl _s80056DB4_0; cmpwi 3,0; stw 3,0x358(31); bne 0f; li 30,0; 0:; lwz 0,0x35c(31); cmpwi 0,0; bne 1f; lis 3,-32692; lis 4,27935; addi 3,3,-27556; ori 4,4,2390; bl _s80056DB4_1; cmpwi 3,0; stw 3,0x35c(31); bne 1f; li 30,0; 1:; lwz 0,0x360(31); cmpwi 0,0; bne 2f; lis 3,-32692; lis 4,28588; addi 3,3,-27556; ori 4,4,34431; bl _s80056DB4_2; cmpwi 3,0; stw 3,0x360(31); bne 2f; li 30,0; 2:; cmpwi 30,0; beq 3f; mr 3,31; bl _s80056DB4_3; li 0,3; stw 0,0x38c(31); 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80056DB4_0();
extern "C" void _s80056DB4_1();
extern "C" void _s80056DB4_2();
extern "C" void _s80056DB4_3();
extern "C" void f_80056DB4() {}
