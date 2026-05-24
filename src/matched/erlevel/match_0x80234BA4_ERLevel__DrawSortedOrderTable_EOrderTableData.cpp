// 0x80234BA4 ERLevel::DrawSortedOrderTable(EOrderTableData (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 28,3; mr 31,4; li 30,0; cmpwi 4,0; beq 1f; 0:; lwz 4,0x28(4); addi 30,30,1; cmpwi 4,0; bne 0b; 1:; cmpwi 30,0; beq 6f; addis 9,28,3; addi 26,30,-1; lwz 27,-24008(9); bl _s80234BA4_0; mulli 4,30,12; li 5,0; bl _s80234BA4_1; mr 29,3; mr. 4,31; mr 31,29; beq 3f; 2:; stw 4,0x0(31); lfs f0,0x2c(4); stfs f0,0x4(31); lfs f13,0x30(4); stfs f13,0x8(31); addi 31,31,12; lwz 4,0x28(4); cmpwi 4,0; bne 2b; 3:; lis 6,-32733; mr 4,30; addi 6,6,17584; mr 3,29; li 5,12; mr 30,26; bl _s80234BA4_2; mr 31,29; cmpwi 30,-1; beq 5f; 4:; lwz 4,0x0(31); mr 3,28; mr 5,27; addi 31,31,12; bl _s80234BA4_3; cmpwi 30,0; addi 30,30,-1; bne 4b; 5:; bl _s80234BA4_4; mr 4,29; bl _s80234BA4_5; 6:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"

extern "C" void _s80234BA4_0();
extern "C" void _s80234BA4_1();
extern "C" void _s80234BA4_2();
extern "C" void _s80234BA4_3();
extern "C" void _s80234BA4_4();
extern "C" void _s80234BA4_5();

struct ERLevel {
    void DrawSortedOrderTable_EOrderTableData();
};

void ERLevel::DrawSortedOrderTable_EOrderTableData() {
}
