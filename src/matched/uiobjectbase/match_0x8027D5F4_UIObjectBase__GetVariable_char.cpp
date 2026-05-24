// 0x8027D5F4 UIObjectBase::GetVariable(char (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8027D67C" lines="rlwinm 3,3,1,31,31"

struct UIObjectBase {
    void GetVariable();
};

void UIObjectBase::GetVariable() {
}
