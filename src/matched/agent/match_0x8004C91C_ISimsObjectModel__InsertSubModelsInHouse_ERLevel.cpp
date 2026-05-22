// 0x8004C91C ISimsObjectModel::InsertSubModelsInHouse(ERLevel (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 31,0x450(3); mr 30,4; cmpwi 31,0; beq 1f; 0:; lwz 4,0x0(31); mr 3,30; li 5,0; bl _s8004C91C_0; lwz 31,0x8(31); cmpwi 31,0; bne 0b; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8004C91C_0();
extern "C" void f_8004C91C() {}
