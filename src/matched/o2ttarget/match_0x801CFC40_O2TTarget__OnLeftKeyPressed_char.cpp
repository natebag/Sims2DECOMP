// 0x801CFC40 O2TTarget::OnLeftKeyPressed(char (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x88(3); cmpwi 0,0; beq 2f; cmpwi 0,2; bne 1f; lwz 0,0xa0(3); cmpwi 0,3; bne 0f; lbz 9,-29739(13); extsb 0,9; cmpwi 0,0; ble 1f; addi 0,9,-1; stb 0,-29739(13); b 1f; 0:; cmpwi 0,4; bne 1f; lbz 9,-29740(13); extsb 0,9; cmpwi 0,0; ble 1f; addi 0,9,-1; stb 0,-29740(13); 1:; bl _s801CFC40_0; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s801CFC40_0();

struct O2TTarget {
    void OnLeftKeyPressed();
};

void O2TTarget::OnLeftKeyPressed() {
}
