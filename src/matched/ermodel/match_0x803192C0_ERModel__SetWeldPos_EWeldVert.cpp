// 0x803192C0 ERModel::SetWeldPos(EWeldVert (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lwz 0,0x18(3); cmpwi 0,0; beq 3f; li 0,3; lis 9,-32702; lis 11,-32702; lis 10,-32702; mtspr 9,0; lfs f10,0x8b8(9); lfs f11,0x8bc(11); lfs f12,0x8c0(10); lwz 4,0x0(4); 0:; lfs f0,0x0(5); addi 5,5,4; fcmpu 0,f0,f10; bge 1f; fadds f0,f0,f11; b 2f; 1:; fadds f0,f0,f12; 2:; fctiwz f13,f0; stfd f13,0x8(1); lwz 9,0xc(1); sth 9,0x0(4); addi 4,4,2; bdnz 0b; b 4f; 3:; lwz 9,0x0(4); lwz 0,0x8(5); lwz 11,0x0(5); lwz 10,0x4(5); stw 0,0x8(9); stw 11,0x0(9); stw 10,0x4(9); 4:; addi 1,1,16"

struct ERModel {
    void SetWeldPos_EWeldVert();
};

void ERModel::SetWeldPos_EWeldVert() {
}
