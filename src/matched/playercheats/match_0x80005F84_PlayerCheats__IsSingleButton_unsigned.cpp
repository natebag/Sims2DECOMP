// 0x80005F84 PlayerCheats::IsSingleButton(unsigned (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 3,0; li 9,0; andi. 0,4,1; beq 0f; cmpwi 3,0; li 3,1; beq 0f; li 3,0; blr; 0:; addi 9,9,1; cmpwi 9,15; bgtlr; sraw 0,4,9; andi. 11,0,1; beq 0b; cmpwi 3,0; li 3,1; beq 0b; li 3,0"

struct PlayerCheats {
    void IsSingleButton();
};

void PlayerCheats::IsSingleButton() {
}
