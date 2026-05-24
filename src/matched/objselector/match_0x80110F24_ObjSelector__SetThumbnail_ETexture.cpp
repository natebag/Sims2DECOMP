// 0x80110F24 ObjSelector::SetThumbnail(ETexture (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 9,0x94(31); cmpwi 9,0; beq 3f; lwz 0,0x14(9); cmpwi 0,0; bne 0f; lwz 9,0x18(9); li 0,0; cmpwi 9,0; beq 0f; lwz 0,0x14(9); 0:; cmpwi 0,0; beq 2f; lwz 9,0x94(31); lwz 3,0x14(9); cmpwi 3,0; bne 1f; lwz 9,0x18(9); li 3,0; cmpwi 9,0; beq 1f; lwz 3,0x14(9); 1:; li 4,0; bl _s80110F24_0; cmpw 3,30; beq 5f; 2:; lwz 0,0x94(31); cmpwi 0,0; bne 4f; 3:; lis 3,-32692; li 4,108; li 5,8; addi 3,3,-17444; bl _s80110F24_1; bl _s80110F24_2; stw 3,0x94(31); addi 11,13,-31800; lwz 9,0x0(11); mr 0,9; addi 9,9,1; stw 9,0x0(11); stw 0,0x8(3); 4:; lwz 3,0x94(31); mr 4,30; bl _s80110F24_3; 5:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s80110F24_0();
extern "C" void _s80110F24_1();
extern "C" void _s80110F24_2();
extern "C" void _s80110F24_3();

struct ObjSelector {
    void SetThumbnail_ETexture();
};

void ObjSelector::SetThumbnail_ETexture() {
}
