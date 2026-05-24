// 0x8012606C cXPersonImpl::CancelLastAction(void) (296 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; li 4,0; lwz 3,0x4(30); li 28,-1; lwz 9,0x4(3); lha 0,0xd8(9); lwz 9,0xdc(9); add 3,3,0; mtspr 8,9; blrl; mr. 31,3; ble 2f; lwz 3,0x4(30); addi 4,31,-1; li 5,0; lwz 9,0x4(3); lha 0,0xe0(9); lwz 9,0xe4(9); add 3,3,0; mtspr 8,9; blrl; lwz 29,0x38(3); cmpwi 31,1; ble 0f; lwz 3,0x4(30); addi 4,31,-2; li 5,0; lwz 9,0x4(3); lha 0,0xe0(9); lwz 9,0xe4(9); add 3,3,0; mtspr 8,9; blrl; b 1f; 0:; lwz 3,0x4(30); lwz 9,0x4(3); lha 0,0xe8(9); lwz 9,0xec(9); add 3,3,0; mtspr 8,9; blrl; 1:; lwz 0,0x3c(3); andi. 9,0,32768; beq 3f; lwz 28,0x38(3); b 3f; 2:; lwz 3,0x4(30); lwz 9,0x4(3); lha 0,0xe8(9); lwz 9,0xec(9); add 3,3,0; mtspr 8,9; blrl; lwz 29,0x38(3); 3:; cmpwi 28,-1; li 3,0; bne 4f; lwz 3,0x4(30); mr 4,29; lwz 9,0x4(3); lha 0,0xb8(9); lwz 9,0xbc(9); add 3,3,0; mtspr 8,9; blrl; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

struct cXPersonImpl {
    void CancelLastAction();
};

void cXPersonImpl::CancelLastAction() {
}
