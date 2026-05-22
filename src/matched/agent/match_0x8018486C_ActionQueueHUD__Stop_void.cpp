// 0x8018486C ActionQueueHUD::Stop(void) (388 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; li 0,0; stw 0,0x98(31); li 11,0; stw 0,0x4(31); addi 9,31,8; li 0,9; mtspr 9,0; 0:; stw 11,0x0(9); addi 9,9,4; bdnz 0b; li 8,9; addi 11,31,80; mtspr 9,8; addi 10,31,116; li 0,0; addi 9,31,44; 1:; stw 0,0x0(9); addi 9,9,4; bdnz 1b; mr 9,11; li 0,0; li 11,9; mtspr 9,11; 2:; stw 0,0x0(9); addi 9,9,4; bdnz 2b; li 8,9; mr 9,10; mtspr 9,8; li 0,0; 3:; stw 0,0x0(9); addi 9,9,4; bdnz 3b; lwz 0,0x314(31); cmpwi 0,255; beq 7f; li 28,0; lis 27,-32701; li 29,0; 4:; lwz 0,-31544(13); cmpwi 0,0; bne 5f; li 3,16; bl _s8018486C_0; bl _s8018486C_1; stw 3,-31544(13); 5:; lwz 0,0x314(31); addi 30,27,27552; lwz 3,-31544(13); mulli 0,0,36; add 0,29,0; lwzx 4,30,0; bl _s8018486C_2; cmpwi 3,0; beq 6f; lwz 9,0x314(31); lwz 3,0x0(31); mulli 9,9,36; lwz 0,0x0(3); cmpwi 0,0; add 9,29,9; lwzx 4,30,9; beq 6f; lwz 3,0x1c(3); cmpwi 3,0; beq 6f; bl _s8018486C_3; 6:; addi 28,28,1; addi 29,29,4; cmplwi 28,8; ble 4b; 7:; lwz 0,0x310(31); li 30,0; stw 30,0x154(31); cmpwi 0,0; stw 30,0x150(31); stb 30,0x308(31); stb 30,0x30a(31); stw 30,0x0(31); stb 30,0x318(31); beq 8f; lwz 4,0x314(31); lwz 3,-26524(13); bl _s8018486C_4; lwz 4,0x310(31); bl _s8018486C_5; stw 30,0x310(31); 8:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8018486C_0();
extern "C" void _s8018486C_1();
extern "C" void _s8018486C_2();
extern "C" void _s8018486C_3();
extern "C" void _s8018486C_4();
extern "C" void _s8018486C_5();
extern "C" void f_8018486C() {}
