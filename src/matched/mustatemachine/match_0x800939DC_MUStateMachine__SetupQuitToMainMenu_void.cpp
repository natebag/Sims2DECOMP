// 0x800939DC MUStateMachine::SetupQuitToMainMenu(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32696; lis 11,-32697; addi 10,11,23428; addi 8,9,22744; lwz 11,0x30(8); li 7,1; lwz 9,0x4(8); li 0,0; stw 0,0xa4(10); cmpwi 11,2; stw 9,0xa0(10); stw 7,0x9c(10); bne 0f; stw 7,0xa4(10); 0:; lwz 0,0x34(8); cmpwi 0,2; bnelr; lwz 0,0xa4(10); ori 0,0,2; stw 0,0xa4(10)"

struct MUStateMachine {
    void SetupQuitToMainMenu();
};

void MUStateMachine::SetupQuitToMainMenu() {
}
