// 0x801CFB58 O2TTarget::OnDownKeyPressed(char (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x88(3); cmpwi 0,0; bne 0f; lwz 9,0x9c(3); addi 9,9,1; cmpwi 9,1; stw 9,0x9c(3); ble 1f; stw 0,0x9c(3); b 1f; 0:; cmpwi 0,2; bne 1f; lwz 9,0xa0(3); addi 9,9,1; cmpwi 9,6; stw 9,0xa0(3); ble 1f; li 0,0; stw 0,0xa0(3); 1:; bl _s801CFB58_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s801CFB58_0();

struct O2TTarget {
    void OnDownKeyPressed();
};

void O2TTarget::OnDownKeyPressed() {
}
