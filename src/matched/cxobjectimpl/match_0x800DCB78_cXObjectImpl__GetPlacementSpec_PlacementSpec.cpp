// 0x800DCB78 cXObjectImpl::GetPlacementSpec(PlacementSpec (468 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lwz 9,-21488(13); mr 29,3; mr 31,4; lwz 11,0x0(9); addi 4,29,104; lha 3,0x68(11); lwz 0,0x6c(11); add 3,9,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; li 9,-16; li 0,0; stw 0,0x0(31); stw 9,0x4(31); stw 9,0x8(31); b 1f; 0:; li 0,1; stw 0,0x0(31); lwz 9,0x68(29); lwz 10,0x6c(29); stw 9,0x4(31); stw 10,0x8(31); 1:; lwz 0,0x80(29); mr 30,29; stw 0,0x14(31); b 4f; 2:; lwz 3,0x4(30); lwz 9,0x4(3); lha 0,0x300(9); lwz 9,0x304(9); add 3,3,0; mtspr 8,9; blrl; mr. 11,3; beq 3f; lwz 9,0x4(11); lha 3,0x520(9); lwz 0,0x524(9); add 3,11,3; mtspr 8,0; blrl; mr 30,3; b 4f; 3:; li 30,0; 4:; lwz 3,0x4(30); lwz 9,0x4(3); lha 0,0x300(9); lwz 9,0x304(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 2b; lwz 29,0x4(29); addi 3,30,40; li 4,26; mr 28,3; lwz 30,0x4(29); lha 0,0x488(30); addi 30,30,1160; add 29,29,0; bl _s800DCB78_0; lwz 0,0x4(30); lha 4,0x0(3); mr 3,29; mtspr 8,0; blrl; mr. 11,3; beq 5f; lwz 9,0x4(11); lha 3,0x520(9); lwz 0,0x524(9); add 3,11,3; mtspr 8,0; blrl; b 6f; 5:; li 3,0; 6:; stw 3,0xc(31); li 4,14; mr 3,28; bl _s800DCB78_1; lha 9,0x0(3); stw 9,0x10(31); cmpwi 9,-1; beq 8f; addi 0,9,-1; stw 0,0x10(31); cmpwi 0,-1; bne 7f; mr 3,28; li 4,14; li 5,-1; bl _s800DCB78_2; b 8f; 7:; lwz 4,0xc(31); cmpwi 4,0; beq 8f; cmpwi 0,0; blt 8f; lwz 3,0x4(4); lwz 9,0x4(3); lha 0,0x2b0(9); lwz 9,0x2b4(9); add 3,3,0; mtspr 8,9; blrl; 8:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s800DCB78_0();
extern "C" void _s800DCB78_1();
extern "C" void _s800DCB78_2();

struct cXObjectImpl {
    void GetPlacementSpec_PlacementSpec();
};

void cXObjectImpl::GetPlacementSpec_PlacementSpec() {
}
