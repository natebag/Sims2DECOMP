// 0x800F1C44 ObjectFolderImpl::GetResourceCount(unsigned (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,4; mr 11,3; mr 4,5; cmpwi 6,1; beq 0f; li 3,0; b 1f; 0:; lwz 9,0x0(11); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0xc(3); mr 4,31; lha 0,0x78(9); lwz 9,0x7c(9); add 3,3,0; mtspr 8,9; blrl; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

struct ObjectFolderImpl {
    void GetResourceCount();
};

void ObjectFolderImpl::GetResourceCount() {
}
