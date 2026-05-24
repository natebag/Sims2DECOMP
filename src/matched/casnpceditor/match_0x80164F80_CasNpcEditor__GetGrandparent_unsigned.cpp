// 0x80164F80 CasNpcEditor::GetGrandparent(unsigned (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); cmplwi 4,51; bgt 1f; mr 5,4; li 4,1; cmplwi 5,25; ble 0f; addi 5,5,-26; li 4,0; 0:; lwz 3,0x58(3); bl _s80164F80_0; mr. 3,3; beq 1f; lwz 3,0x0(3); cmpwi 3,0; bne 2f; 1:; li 3,0; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s80164F80_0();

struct CasNpcEditor {
    void GetGrandparent();
};

void CasNpcEditor::GetGrandparent() {
}
