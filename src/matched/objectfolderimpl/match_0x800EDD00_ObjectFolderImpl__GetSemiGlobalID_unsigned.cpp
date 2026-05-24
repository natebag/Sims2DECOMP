// 0x800EDD00 ObjectFolderImpl::GetSemiGlobalID(unsigned (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 31,3; lwz 9,0x0(31); lha 3,0x38(9); lwz 0,0x3c(9); add 3,31,3; mtspr 8,0; blrl; mr. 3,3; beq 0f; lwz 0,0x8(3); mr 4,0; cmpwi 0,0; beq 0f; lwz 4,0x34(4); cmpwi 4,0; bne 1f; 0:; li 3,-1; b 3f; 1:; lwz 3,0x690(31); addi 5,1,8; bl _s800EDD00_0; cmpwi 3,0; li 0,-1; beq 2f; lwz 0,0x8(1); 2:; mr. 3,0; bne 3f; li 3,-1; 3:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"

extern "C" void _s800EDD00_0();

struct ObjectFolderImpl {
    void GetSemiGlobalID();
};

void ObjectFolderImpl::GetSemiGlobalID() {
}
