// 0x80070580 SimModel::SimModel(void) (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); li 11,26; mr 30,3; mtspr 9,11; li 0,0; mr 9,30; 0:; stw 0,0x0(9); addi 9,9,4; bdnz 0b; li 9,0; li 0,1; stw 0,0x150(30); addi 31,30,344; stw 9,0x154(30); li 29,3; stw 9,0x138(30); addi 28,30,104; stw 9,0x13c(30); addi 27,30,208; addi 26,30,320; 1:; mr 3,31; bl _s80070580_0; addi 31,31,4; cmpwi 29,0; addi 29,29,-1; bne 1b; li 4,0; li 5,104; mr 3,28; bl _s80070580_1; mr 3,27; li 4,0; li 5,104; bl _s80070580_2; li 10,0; li 11,0; 2:; rlwinm 9,11,2,0,29; addi 0,11,1; rlwinm 11,0,0,24,31; stwx 10,9,30; cmplwi 11,25; ble 2b; mr 10,26; li 11,0; li 8,0; 3:; rlwinm 9,11,2,0,29; addi 0,11,1; rlwinm 11,0,0,24,31; stwx 8,10,9; cmplwi 11,3; ble 3b; lis 9,-32697; lwz 0,0x6210(9); cmpwi 0,0; li 0,2; beq 4f; li 0,1; 4:; sth 0,-32204(13); mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s80070580_0();
extern "C" void _s80070580_1();
extern "C" void _s80070580_2();
extern "C" void f_80070580() {}
