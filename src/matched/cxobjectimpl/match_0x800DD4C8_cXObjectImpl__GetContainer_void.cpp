// 0x800DD4C8 cXObjectImpl::GetContainer(void) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; lwz 31,0x4(30); b 1f; 0:; lwz 9,0x4(31); lha 3,0x300(9); lwz 0,0x304(9); add 3,31,3; mtspr 8,0; blrl; mr 31,3; 1:; lwz 9,0x4(31); lha 3,0x300(9); lwz 0,0x304(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0b; lwz 9,0x4(31); li 4,26; lwz 29,0x4(30); lha 3,0x260(9); lwz 9,0x264(9); lwz 30,0x4(29); add 3,31,3; mtspr 8,9; lha 0,0x488(30); addi 30,30,1160; add 29,29,0; blrl; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

struct cXObjectImpl {
    void GetContainer();
};

void cXObjectImpl::GetContainer() {
}
