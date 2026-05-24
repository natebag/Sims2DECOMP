// 0x800F1F6C ObjectFolderImpl::FindUniqueResourceName(unsigned (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 11,3; mr 31,5; mr 30,6; cmpwi 4,-1; beq 0f; lwz 9,0x0(11); lha 3,0x38(9); lwz 0,0x3c(9); add 3,11,3; mtspr 8,0; blrl; mr. 11,3; beq 0f; lwz 9,0xc(11); mr 4,31; mr 5,30; lha 3,0xc8(9); lwz 0,0xcc(9); add 3,11,3; mtspr 8,0; blrl; li 3,1; b 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

struct ObjectFolderImpl {
    void FindUniqueResourceName();
};

void ObjectFolderImpl::FindUniqueResourceName() {
}
