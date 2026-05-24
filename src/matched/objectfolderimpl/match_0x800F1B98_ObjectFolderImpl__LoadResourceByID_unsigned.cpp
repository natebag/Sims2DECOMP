// 0x800F1B98 ObjectFolderImpl::LoadResourceByID(unsigned (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); cmpwi 4,-1; bne 0f; li 3,0; b 2f; 0:; cmpwi 7,0; bne 1f; lwz 9,0x0(6); lha 3,0x30(9); lwz 0,0x34(9); add 3,6,3; mtspr 8,0; blrl; b 2f; 1:; lwz 9,0x0(6); lha 3,0x38(9); lwz 0,0x3c(9); add 3,6,3; mtspr 8,0; blrl; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

struct ObjectFolderImpl {
    void LoadResourceByID();
};

void ObjectFolderImpl::LoadResourceByID() {
}
