// 0x802B7920 AptScriptFunctionBase::InitializeStaticData(AptInitParmsT (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x30(3); rlwinm 3,0,2,0,29; stw 0,-26964(13); bl _s802B7920_0; lwz 9,-26964(13); stw 3,-26976(13); stw 3,-26972(13); cmpwi 9,0; ble 1f; mtspr 9,9; lwz 0,-22936(13); 0:; stw 0,0x0(3); addi 3,3,4; bdnz 0b; 1:; li 0,0; stw 0,-26968(13); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s802B7920_0();

struct AptScriptFunctionBase {
    void InitializeStaticData_AptInitParmsT();
};

void AptScriptFunctionBase::InitializeStaticData_AptInitParmsT() {
}
