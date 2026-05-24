// 0x80016B54 ESimsCam::SetState(Panelstateman::Panelstate) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; cmpwi 4,4; bgt 0f; cmpwi 4,3; bge 1f; cmpwi 4,0; beq 1f; b 4f; 0:; cmpwi 4,8; beq 3f; b 4f; 1:; lwz 3,0x4(31); bl _s80016B54_0; cmpwi 3,0; li 4,0; beq 2f; li 4,1; 2:; mr 3,31; bl _s80016B54_1; b 4f; 3:; mr 3,31; li 4,0; bl _s80016B54_2; 4:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s80016B54_0();
extern "C" void _s80016B54_1();
extern "C" void _s80016B54_2();

struct ESimsCam {
    void SetState_Panelstateman__Panelstate();
};

void ESimsCam::SetState_Panelstateman__Panelstate() {
}
