// 0x800F1EE8 ObjectFolderImpl::GetNamespaceName(unsigned (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-296(1); mfspr 0,8; stmw 29,0x11c(1); stw 0,0x12c(1); lwz 9,0x0(3); mr 29,5; lha 0,0x38(9); lwz 9,0x3c(9); add 3,3,0; mtspr 8,9; blrl; mr. 31,3; beq 0f; addi 30,1,8; li 5,260; addi 4,30,8; mr 3,30; bl _s800F1EE8_0; lwz 9,0xc(31); mr 4,30; lha 3,0x58(9); lwz 0,0x5c(9); add 3,31,3; mtspr 8,0; blrl; mr 3,30; mr 4,29; bl _s800F1EE8_1; 0:; lwz 0,0x12c(1); mtspr 8,0; lmw 29,0x11c(1); addi 1,1,296"

extern "C" void _s800F1EE8_0();
extern "C" void _s800F1EE8_1();

struct ObjectFolderImpl {
    void GetNamespaceName();
};

void ObjectFolderImpl::GetNamespaceName() {
}
