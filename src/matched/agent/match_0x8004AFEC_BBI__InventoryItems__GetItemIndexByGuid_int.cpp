// 0x8004AFEC BBI::InventoryItems::GetItemIndexByGuid(int, (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 29,3; mr 26,4; mr 27,5; bl _s8004AFEC_0; li 30,0; mr 28,3; cmpw 30,28; bge 2f; li 31,0; 0:; lwzx 3,31,29; cmpwi 3,0; beq 1f; bl _s8004AFEC_1; cmpw 3,26; bne 1f; lwzx 3,31,29; bl _s8004AFEC_2; cmpw 3,27; bne 1f; mr 3,30; b 3f; 1:; addi 30,30,1; addi 31,31,4; cmpw 30,28; blt 0b; 2:; li 3,-1; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s8004AFEC_0();
extern "C" void _s8004AFEC_1();
extern "C" void _s8004AFEC_2();
extern "C" void f_8004AFEC() {}
