// 0x80095E34 StateMachine::GetReturnStateId(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); addi 9,3,100; lwz 11,0x64(3); lwz 10,0x4(9); addi 7,1,8; lwz 8,0xc(9); lwz 0,0x8(9); cmpw 11,10; stw 11,0x8(1); stw 0,0x10(1); stw 10,0xc(1); stw 8,0x14(1); bne 0f; addi 0,8,-4; stw 0,0x14(1); lwz 9,-4(8); addi 11,9,128; stw 9,0xc(1); stw 11,0x10(1); lwz 0,0x8(7); stw 0,0x8(1); 0:; lwz 10,0x8(1); addi 0,10,-4; stw 0,0x8(1); lwz 9,-4(10); lwz 11,0x0(9); lwz 3,0x0(11); addi 1,1,24"

struct StateMachine {
    void GetReturnStateId();
};

void StateMachine::GetReturnStateId() {
}
