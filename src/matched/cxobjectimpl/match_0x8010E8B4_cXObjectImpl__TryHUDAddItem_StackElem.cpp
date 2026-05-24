// 0x8010E8B4 cXObjectImpl::TryHUDAddItem(StackElem (892 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); lis 9,-32697; mr 31,3; lwz 0,0x5bc8(9); mr 28,4; mr 29,5; cmpwi 0,0; beq 12f; lbz 4,0x2(29); mr 3,31; lha 5,0x0(29); li 6,0; li 7,0; addi 8,1,8; bl _s8010E8B4_0; cmpwi 3,-1; bne 0f; cmpwi 4,-1; beq 12f; 0:; addi 6,1,12; addi 30,1,10; li 0,0; lbz 4,0x6(29); lha 5,0x4(29); mr 27,6; mr 3,31; sth 0,0xa(1); li 7,0; mr 8,30; bl _s8010E8B4_1; mr 6,30; cmpwi 3,-1; bne 1f; cmpwi 4,-1; beq 12f; 1:; lbz 0,0x7(29); cmpwi 0,3; beq 8f; bgt 2f; cmpwi 0,1; beq 5f; bgt 6f; cmpwi 0,0; beq 3f; b 18f; 2:; cmpwi 0,5; beq 14f; blt 13f; cmpwi 0,6; beq 15f; cmpwi 0,7; beq 16f; b 18f; 3:; lwz 0,0xc(1); cmpwi 0,0; bne 4f; lwz 11,0x0(31); li 0,1; stw 0,-24512(13); li 9,19; sth 9,0x34(11); li 4,19; b 19f; 4:; lis 9,-32697; lbz 4,0x3(29); lwz 3,0x5bc8(9); lha 5,0x8(1); bl _s8010E8B4_2; cmpwi 3,0; beq 12f; lwz 0,0xc(1); cmpwi 0,0; beq 20f; lha 5,0x4(29); mr 3,31; lbz 4,0x6(29); mr 6,27; lha 7,0xa(1); bl _s8010E8B4_3; b 20f; 5:; lis 9,-32697; lha 4,0x8(1); lwz 3,0x5bc8(9); lha 5,0xa(1); bl _s8010E8B4_4; b 11f; 6:; lhz 0,0xa(1); cmplwi 0,5; ble 7f; lwz 11,0x0(31); li 0,1; stw 0,-24512(13); li 9,75; sth 9,0x34(11); li 4,75; b 19f; 7:; lwz 11,0x4(31); li 4,0; lwz 9,0x4(11); lwz 0,0x274(9); lha 3,0x270(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x4(31); mr 30,3; li 4,1; lwz 9,0x4(11); lwz 0,0x274(9); lha 3,0x270(9); mtspr 8,0; add 3,11,3; blrl; mr 6,3; lis 9,-32697; lwz 3,0x5bc8(9); mr 5,30; lha 4,0xa(1); bl _s8010E8B4_5; b 11f; 8:; lha 0,0xa(1); cmpwi 0,5; beq 9f; lwz 11,0x0(31); li 0,1; stw 0,-24512(13); li 9,75; sth 9,0x34(11); li 4,75; b 19f; 9:; lwz 3,0x4(31); lha 4,0x4(28); lwz 9,0x4(3); lha 0,0x488(9); lwz 9,0x48c(9); add 3,3,0; mtspr 8,9; blrl; mr. 11,3; bne 10f; lwz 11,0x0(31); li 0,1; stw 0,-24512(13); li 9,21; sth 9,0x34(11); li 4,21; b 19f; 10:; lwz 9,0x4(11); lwz 0,0x37c(9); lha 3,0x378(9); mtspr 8,0; add 3,11,3; blrl; bl _s8010E8B4_6; lwz 11,0x4(31); mr 30,3; li 4,0; lwz 9,0x4(11); lwz 0,0x274(9); lha 3,0x270(9); mtspr 8,0; add 3,11,3; blrl; mr 5,3; lis 9,-32697; lwz 3,0x5bc8(9); mr 4,30; bl _s8010E8B4_7; 11:; cmpwi 3,0; bne 20f; 12:; li 3,0; li 4,0; b 21f; 13:; lbz 11,0x3(29); lis 9,-32697; lwz 3,0x5bc8(9); li 5,1; b 17f; 14:; lbz 11,0x3(29); lis 9,-32697; lwz 3,0x5bc8(9); li 5,2; b 17f; 15:; lbz 11,0x3(29); lis 9,-32697; lwz 3,0x5bc8(9); li 5,3; b 17f; 16:; lbz 11,0x3(29); lis 9,-32697; lwz 3,0x5bc8(9); li 5,4; 17:; addi 11,11,1; mr 4,11; sth 11,0xa(1); bl _s8010E8B4_8; b 20f; 18:; lwz 11,0x0(31); li 0,1; stw 0,-24512(13); li 9,20; sth 9,0x34(11); li 4,20; 19:; lwz 11,0x4(31); lwz 9,0x4(11); lha 3,0x110(9); lwz 0,0x114(9); add 3,11,3; mtspr 8,0; blrl; li 3,-1; li 4,-1; b 21f; 20:; li 3,0; li 4,1; 21:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"

extern "C" void _s8010E8B4_0();
extern "C" void _s8010E8B4_1();
extern "C" void _s8010E8B4_2();
extern "C" void _s8010E8B4_3();
extern "C" void _s8010E8B4_4();
extern "C" void _s8010E8B4_5();
extern "C" void _s8010E8B4_6();
extern "C" void _s8010E8B4_7();
extern "C" void _s8010E8B4_8();

struct cXObjectImpl {
    void TryHUDAddItem_StackElem();
};

void cXObjectImpl::TryHUDAddItem_StackElem() {
}
