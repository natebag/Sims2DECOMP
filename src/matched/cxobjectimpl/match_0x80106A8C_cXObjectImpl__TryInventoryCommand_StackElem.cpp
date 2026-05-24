// 0x80106A8C cXObjectImpl::TryInventoryCommand(StackElem (752 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; mr 28,5; cmpwi 4,0; beq 14f; cmpwi 28,0; beq 14f; lwz 9,0x4(29); lwz 10,0x0(9); lwz 11,0x18(10); lwz 0,0x1c(11); lha 3,0x18(11); mtspr 8,0; add 3,10,3; blrl; mr. 3,3; li 0,0; beq 0f; lwz 0,0x4(3); 0:; cmpwi 0,0; bne 1f; lwz 11,0x0(29); li 0,1; stw 0,-24512(13); li 9,77; sth 9,0x34(11); li 4,77; b 10f; 1:; lwz 10,-21476(13); lis 9,-32697; lwz 4,0x5c5c(9); lwz 11,0x0(10); lwz 0,0x124(11); lha 3,0x120(11); mtspr 8,0; add 3,10,3; blrl; lwz 9,0x0(3); lha 0,0x140(9); lwz 9,0x144(9); add 3,3,0; mtspr 8,9; blrl; mr. 27,3; beq 14f; lbz 0,0x4(28); rlwinm 31,0,0,26,31; cmpwi 31,2; beq 14f; bgt 2f; cmpwi 31,0; beq 3f; cmpwi 31,1; beq 5f; b 14f; 2:; cmpwi 31,4; beq 8f; blt 7f; cmpwi 31,5; beq 12f; b 14f; 3:; mr 4,28; mr 3,29; bl _s80106A8C_0; mr. 30,3; bne 4f; lwz 11,0x0(29); li 0,1; stw 0,-24512(13); li 9,79; sth 9,0x34(11); li 4,79; b 10f; 4:; lis 9,-32697; lwz 0,0x61bc(9); cmpwi 0,0; bne 13f; mr 4,30; mr 3,27; bl _s80106A8C_1; cmpwi 3,0; li 3,0; li 4,1; bne 15f; b 14f; 5:; mr 4,28; mr 3,29; bl _s80106A8C_2; mr. 30,3; bne 6f; lwz 9,0x0(29); li 0,79; stw 31,-24512(13); li 4,79; sth 0,0x34(9); b 10f; 6:; mr 4,30; mr 3,27; bl _s80106A8C_3; lwz 9,0x4(29); extsh 5,3; li 4,0; lwz 11,0x4(9); lha 3,0x1f0(11); lwz 0,0x1f4(11); add 3,9,3; mtspr 8,0; blrl; b 13f; 7:; mr 4,28; mr 3,29; bl _s80106A8C_4; mr 30,3; mr 4,28; mr 3,29; bl _s80106A8C_5; extsh 5,3; cmpwi 5,0; ble 9f; mr 4,30; li 6,0; mr 3,27; bl _s80106A8C_6; lwz 9,0x4(29); extsh 5,3; li 4,0; lwz 11,0x4(9); lha 3,0x1f0(11); lwz 0,0x1f4(11); add 3,9,3; mtspr 8,0; blrl; b 13f; 8:; mr 4,28; mr 3,29; bl _s80106A8C_7; mr 30,3; mr 4,28; mr 3,29; bl _s80106A8C_8; extsh 5,3; cmpwi 5,0; bgt 11f; 9:; lwz 11,0x0(29); li 0,1; stw 0,-24512(13); li 9,78; sth 9,0x34(11); li 4,78; 10:; lwz 11,0x4(29); lwz 9,0x4(11); lha 3,0x110(9); lwz 0,0x114(9); add 3,11,3; mtspr 8,0; blrl; li 3,-1; li 4,-1; b 15f; 11:; mr 4,30; li 6,0; mr 3,27; bl _s80106A8C_9; lwz 9,0x4(29); extsh 5,3; li 4,0; lwz 11,0x4(9); lha 3,0x1f0(11); lwz 0,0x1f4(11); add 3,9,3; mtspr 8,0; blrl; b 13f; 12:; mr 3,27; bl _s80106A8C_10; 13:; li 3,0; li 4,1; b 15f; 14:; li 3,0; li 4,0; 15:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s80106A8C_0();
extern "C" void _s80106A8C_1();
extern "C" void _s80106A8C_2();
extern "C" void _s80106A8C_3();
extern "C" void _s80106A8C_4();
extern "C" void _s80106A8C_5();
extern "C" void _s80106A8C_6();
extern "C" void _s80106A8C_7();
extern "C" void _s80106A8C_8();
extern "C" void _s80106A8C_9();
extern "C" void _s80106A8C_10();

struct cXObjectImpl {
    void TryInventoryCommand_StackElem();
};

void cXObjectImpl::TryInventoryCommand_StackElem() {
}
