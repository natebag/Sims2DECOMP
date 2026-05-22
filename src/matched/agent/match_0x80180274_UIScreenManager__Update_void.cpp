// 0x80180274 UIScreenManager::Update(void) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; li 28,0; addi 31,30,516; lwzx 0,31,28; cmpwi 0,0; beq 3f; li 29,0; 0:; lwzx 4,31,29; mr 3,30; bl _s80180274_0; cmpwi 3,0; bne 1f; lwzx 4,31,29; mr 3,30; li 5,0; bl _s80180274_1; mr 3,30; mr 4,28; bl _s80180274_2; b 2f; 1:; addi 29,29,4; addi 28,28,1; 2:; addi 31,30,516; lwzx 0,31,29; cmpwi 0,0; beq 3f; cmpwi 28,7; ble 0b; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80180274_0();
extern "C" void _s80180274_1();
extern "C" void _s80180274_2();
extern "C" void f_80180274() {}
