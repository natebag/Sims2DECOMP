// 0x8004A800 BBI::InventoryItems::CountItemsByGuid(int) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; mr 27,4; li 28,0; bl _s8004A800_0; cmpw 28,3; bge 2f; mr 30,3; li 31,0; 0:; lwzx 3,31,29; cmpwi 3,0; beq 1f; bl _s8004A800_1; cmpw 3,27; bne 1f; lwzx 3,31,29; bl _s8004A800_2; add 28,28,3; 1:; addi 31,31,4; addic. 30,30,-1; bne 0b; 2:; mr 3,28; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8004A800_0();
extern "C" void _s8004A800_1();
extern "C" void _s8004A800_2();
extern "C" void f_8004A800() {}
