// 0x8004ED3C ISimsObjectModel::TryAnimateObject(short, (540 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; mr 27,4; lwz 0,0x4b4(31); mr 28,5; cmpwi 0,0; beq 2f; lwz 3,0x328(31); li 4,0; lwz 9,0x4(3); lha 0,0x260(9); lwz 9,0x264(9); add 3,3,0; mtspr 8,9; blrl; cmpw 3,27; beq 0f; lis 3,-32693; lwz 4,0x4b4(31); addi 3,3,11064; bl _s8004ED3C_0; li 0,0; stw 0,0x494(31); b 1f; 0:; lis 30,-32693; lwz 4,0x4b4(31); addi 3,30,11064; bl _s8004ED3C_1; cmpwi 3,0; beq 10f; lwz 4,0x4b4(31); addi 3,30,11064; li 5,1; bl _s8004ED3C_2; li 0,0; 1:; stw 0,0x4b4(31); 2:; lwz 30,0x494(31); li 0,0; stw 0,0x49c(31); stw 0,0x498(31); cmpwi 30,0; bne 3f; lwz 11,0x328(31); li 4,0; mr 5,27; lwz 9,0x4(11); lwz 0,0x1ec(9); lha 3,0x1e8(9); mtspr 8,0; add 3,11,3; blrl; li 0,1; stw 30,0x490(31); stw 0,0x494(31); 3:; cmpwi 28,0; beq 6f; addi 29,31,1188; lwz 9,0x4a4(31); lwz 0,0x4(29); subf 0,9,0; rlwinm. 11,0,30,2,31; beq 5f; lhz 0,0x2(9); sth 0,0x0(28); lwz 3,0x4a4(31); lwz 30,0x4(29); addi 4,3,4; cmpw 30,4; beq 4f; subf 30,4,30; mr 5,30; bl _s8004ED3C_3; add 3,3,30; 4:; stw 3,0x4(29); li 0,1; li 3,0; stw 0,0x4a0(31); li 4,0; b 12f; 5:; li 0,-1; sth 0,0x0(28); b 8f; 6:; addi 29,31,1188; lwz 3,0x4a4(31); lwz 30,0x4(29); subf 0,3,30; rlwinm. 9,0,30,2,31; beq 8f; addi 4,3,4; cmpw 30,4; beq 7f; subf 30,4,30; mr 5,30; bl _s8004ED3C_4; add 3,3,30; 7:; stw 3,0x4(29); 8:; li 0,0; lwz 5,-32420(13); stw 0,0x4a0(31); mr 4,27; mr 3,31; bl _s8004ED3C_5; lwz 30,0x8(3); cmpwi 30,0; beq 11f; lis 29,-32693; mr 4,30; addi 3,29,11064; bl _s8004ED3C_6; mr. 3,3; beq 9f; lwz 9,0x14(3); lwz 0,0x490(31); cmpw 0,9; bge 11f; b 10f; 9:; stw 30,0x4b4(31); mr 4,30; addi 3,29,11064; bl _s8004ED3C_7; 10:; li 3,0; li 4,2; b 12f; 11:; li 0,0; li 3,0; stw 0,0x494(31); li 4,1; 12:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s8004ED3C_0();
extern "C" void _s8004ED3C_1();
extern "C" void _s8004ED3C_2();
extern "C" void _s8004ED3C_3();
extern "C" void _s8004ED3C_4();
extern "C" void _s8004ED3C_5();
extern "C" void _s8004ED3C_6();
extern "C" void _s8004ED3C_7();

struct ISimsObjectModel {
    void TryAnimateObject_short();
};

void ISimsObjectModel::TryAnimateObject_short() {
}
