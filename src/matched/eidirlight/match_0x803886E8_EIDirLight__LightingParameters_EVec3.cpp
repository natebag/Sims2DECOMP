// 0x803886E8 EIDirLight::LightingParameters(EVec3 (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 5,0x8(3); rlwinm 5,5,31,1,26; stw 0,0x1c(30); bl _s803886E8_0; addi 3,30,0; addi 4,31,0; addi 5,31,0; bl _s803886E8_1; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); addi 1,1,32; mtspr 8,0; blr; mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); addi 31,5,0; stw 30,0x20(1); addi 30,4,0; stw 29,0x1c(1); addi 29,3,0; bl _s803886E8_2; stw 30,0x14(29); subf 0,30,31; stw 31,0x18(29); stw 0,0x1c(29); lwz 4,0x1c(29); cmpwi 4,0; bge 0f; lwz 0,0x8(29); add 0,4,0; stw 0,0x1c(29); 0:; bl _s803886E8_3; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); addi 1,1,40; mtspr 8,0"

extern "C" void _s803886E8_0();
extern "C" void _s803886E8_1();
extern "C" void _s803886E8_2();
extern "C" void _s803886E8_3();

struct EIDirLight {
    void LightingParameters_EVec3();
};

void EIDirLight::LightingParameters_EVec3() {
}
