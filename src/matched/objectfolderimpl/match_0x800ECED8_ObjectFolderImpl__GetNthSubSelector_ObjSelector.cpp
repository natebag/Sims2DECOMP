// 0x800ECED8 ObjectFolderImpl::GetNthSubSelector(ObjSelector (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 27,4; mr 29,3; lwz 9,0x38(27); mr 30,5; li 31,0; lha 28,0x14(9); cmpwi 28,0; bne 3f; b 4f; 0:; mr 3,31; b 5f; 1:; mr 3,31; mr 4,27; bl _s800ECED8_0; cmpwi 3,0; beq 3f; lwz 9,0x38(31); lha 0,0x14(9); cmpw 0,28; bne 3f; cmpwi 0,0; li 0,0; beq 2f; lha 0,0x16(9); subfic 0,0,-1; subfic 9,0,0; adde 0,9,0; 2:; cmpwi 0,0; bne 3f; cmpwi 30,0; beq 0b; addi 30,30,-1; 3:; lwz 9,0x0(29); mr 4,31; lha 3,0x70(9); lwz 0,0x74(9); add 3,29,3; mtspr 8,0; blrl; mr. 31,3; bne 1b; 4:; li 3,0; 5:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s800ECED8_0();

struct ObjectFolderImpl {
    void GetNthSubSelector_ObjSelector();
};

void ObjectFolderImpl::GetNthSubSelector_ObjSelector() {
}
