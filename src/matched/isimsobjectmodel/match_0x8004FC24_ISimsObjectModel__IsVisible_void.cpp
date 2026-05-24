// 0x8004FC24 ISimsObjectModel::IsVisible(void) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x120(3); cmpwi 0,0; bne 0f; li 3,0; b 2f; 0:; lwz 11,0x328(3); cmpwi 11,0; beq 1f; lwz 9,0x4(11); li 4,34; lha 3,0x260(9); lwz 0,0x264(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; li 3,0; bne 2f; 1:; li 3,1; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

struct ISimsObjectModel {
    void IsVisible();
};

void ISimsObjectModel::IsVisible() {
}
