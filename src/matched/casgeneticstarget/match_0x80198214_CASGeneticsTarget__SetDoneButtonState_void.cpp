// 0x80198214 CASGeneticsTarget::SetDoneButtonState(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); lis 9,-32697; lwz 9,0x5bc0(9); lwz 11,0x134c(9); mr 0,11; cmpwi 11,0; bge 0f; addi 0,11,3; 0:; lwz 9,0x1348(9); rlwinm 0,0,0,0,29; subf 0,0,11; srw 9,9,0; andi. 0,9,1; beq 1f; lis 9,-32705; lis 3,-32705; addi 9,9,-15588; addi 3,3,-14892; stw 9,0x8(1); li 4,0; li 5,0; li 6,1; addi 7,1,8; bl _s80198214_0; 1:; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"

extern "C" void _s80198214_0();

struct CASGeneticsTarget {
    void SetDoneButtonState();
};

void CASGeneticsTarget::SetDoneButtonState() {
}
