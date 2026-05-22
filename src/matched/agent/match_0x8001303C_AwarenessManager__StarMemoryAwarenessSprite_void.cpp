// 0x8001303C AwarenessManager::StarMemoryAwarenessSprite(void) (392 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; lwz 9,0x34(29); cmpwi 9,0; beq 0f; lwz 9,0x0(9); li 4,10; lwz 3,0x0(9); bl _s8001303C_0; b 1f; 0:; li 3,0; 1:; cmpwi 3,0; beq 13f; lwz 31,0xb0(3); li 9,1; lwz 0,0x10(31); cmpwi 0,0; bne 2f; li 9,0; 2:; cmpwi 9,0; bne 13f; lwz 0,0x14(29); li 30,0; cmpwi 0,3; beq 7f; bgt 3f; cmpwi 0,0; beq 4f; ble 12f; cmpwi 0,1; beq 5f; cmpwi 0,2; beq 6f; b 12f; 3:; cmpwi 0,5; beq 9f; blt 8f; cmpwi 0,6; beq 10f; cmpwi 0,7; beq 11f; b 12f; 4:; li 30,903; b 12f; 5:; li 30,904; b 12f; 6:; li 30,905; b 12f; 7:; li 30,906; b 12f; 8:; li 30,907; b 12f; 9:; li 30,908; b 12f; 10:; li 30,909; b 12f; 11:; li 30,910; 12:; cmpwi 30,0; beq 13f; li 0,2; mr 3,31; stw 0,0x44(31); bl _s8001303C_1; lis 9,-32707; li 0,4; lfs f0,-8988(9); mr 5,30; li 6,1; li 7,0; stw 0,0x48(31); li 4,1; stfs f0,0x5c(31); mr 3,31; bl _s8001303C_2; li 3,0; bl _s8001303C_3; li 0,0; stw 3,0x3c(31); mr 3,31; stw 0,0x40(31); li 4,-1; bl _s8001303C_4; lwz 9,0x34(29); lwz 10,0x0(9); lwz 11,0x4(10); lha 3,0x250(11); lwz 0,0x254(11); add 3,10,3; mtspr 8,0; blrl; 13:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8001303C_0();
extern "C" void _s8001303C_1();
extern "C" void _s8001303C_2();
extern "C" void _s8001303C_3();
extern "C" void _s8001303C_4();
extern "C" void f_8001303C() {}
