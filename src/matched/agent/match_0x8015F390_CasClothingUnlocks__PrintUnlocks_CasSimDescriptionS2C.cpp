// 0x8015F390 CasClothingUnlocks::PrintUnlocks(CasSimDescriptionS2C (404 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 24,0x28(1); stw 0,0x4c(1); mr 28,3; mr 25,4; addi 3,1,8; li 31,0; bl _s8015F390_0; 0:; li 27,1; cmpwi 31,0; bne 1f; li 27,0; 1:; addi 3,1,8; mr 4,27; bl _s8015F390_1; addi 24,31,1; li 30,0; addi 29,1,24; lis 26,-32692; 2:; li 31,0; 3:; mr 3,28; mr 4,27; mr 5,30; mr 6,31; bl _s8015F390_2; cmpwi 3,0; bne 5f; mr 3,29; mr 4,25; mr 5,30; bl _s8015F390_3; addi 3,1,8; mr 4,30; mr 5,31; mr 6,29; bl _s8015F390_4; mr. 3,3; li 0,0; beq 4f; mr 4,3; li 5,0; addi 3,26,-27556; li 6,0; bl _s8015F390_5; mr 0,3; 4:; cmpwi 0,0; beq 5f; mr 3,0; bl _s8015F390_6; 5:; addi 31,31,1; cmpwi 31,39; ble 3b; addi 30,30,1; cmpwi 30,25; ble 2b; li 30,0; lis 26,-32692; 6:; li 31,0; addi 29,30,1; 7:; mr 3,28; mr 4,27; mr 5,30; mr 6,31; bl _s8015F390_7; cmpwi 3,0; bne 9f; addi 3,1,8; mr 4,30; mr 5,31; bl _s8015F390_8; mr. 3,3; li 0,0; beq 8f; mr 4,3; li 5,0; addi 3,26,-7364; li 6,0; bl _s8015F390_9; mr 0,3; 8:; cmpwi 0,0; beq 9f; mr 3,0; bl _s8015F390_10; 9:; addi 31,31,1; cmpwi 31,29; ble 7b; mr 30,29; cmpwi 30,2; ble 6b; mr 31,24; cmpwi 31,1; ble 0b; addi 3,1,8; li 4,2; bl _s8015F390_11; lwz 0,0x4c(1); mtspr 8,0; lmw 24,0x28(1); addi 1,1,72"
extern "C" void _s8015F390_0();
extern "C" void _s8015F390_1();
extern "C" void _s8015F390_2();
extern "C" void _s8015F390_3();
extern "C" void _s8015F390_4();
extern "C" void _s8015F390_5();
extern "C" void _s8015F390_6();
extern "C" void _s8015F390_7();
extern "C" void _s8015F390_8();
extern "C" void _s8015F390_9();
extern "C" void _s8015F390_10();
extern "C" void _s8015F390_11();
extern "C" void f_8015F390() {}
