// 0x802D1540 EStorable::DynamicCast(ETypeInfo (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr. 31,3; beq 0f; mr 3,31; bl _s802D1540_0; cmpwi 3,0; li 3,0; beq 1f; mr 3,31; b 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s802D1540_0();

struct EStorable {
    void DynamicCast_ETypeInfo();
};

void EStorable::DynamicCast_ETypeInfo() {
}
