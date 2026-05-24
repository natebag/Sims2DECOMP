// 0x800ECD38 ObjectFolderImpl::GetSubTileSelector(ObjSelector (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 29,3; mr 28,4; mr 4,6; mr 26,7; li 31,0; mr. 3,5; blt 3f; cmpwi 4,0; blt 3f; bl _s800ECD38_0; lwz 9,0x38(28); mr 27,3; lha 30,0x14(9); cmpwi 30,0; bne 2f; b 3f; 0:; mr 3,31; b 4f; 1:; mr 3,31; mr 4,28; bl _s800ECD38_1; cmpwi 3,0; beq 2f; lwz 9,0x38(31); lha 0,0x14(9); cmpw 0,30; bne 2f; lha 0,0x16(9); cmpw 0,27; bne 2f; lha 0,0x70(9); cmpw 0,26; beq 0b; 2:; lwz 9,0x0(29); mr 4,31; lha 3,0x70(9); lwz 0,0x74(9); add 3,29,3; mtspr 8,0; blrl; mr. 31,3; bne 1b; 3:; li 3,0; 4:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"

extern "C" void _s800ECD38_0();
extern "C" void _s800ECD38_1();

struct ObjectFolderImpl {
    void GetSubTileSelector_ObjSelector();
};

void ObjectFolderImpl::GetSubTileSelector_ObjSelector() {
}
