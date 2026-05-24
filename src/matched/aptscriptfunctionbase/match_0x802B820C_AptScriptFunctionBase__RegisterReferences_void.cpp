// 0x802B820C AptScriptFunctionBase::RegisterReferences(void) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s802B820C_0; lwz 4,0x2c(31); cmpwi 4,0; beq 0f; lwz 9,-27024(13); lis 5,-32703; addi 5,5,26164; mr 3,31; mtspr 8,9; blrl; 0:; lwz 4,0x24(31); cmpwi 4,0; beq 1f; lwz 9,-27024(13); lis 5,-32703; addi 5,5,27064; mr 3,31; mtspr 8,9; blrl; 1:; lwz 4,0x28(31); cmpwi 4,0; beq 2f; lwz 9,-27024(13); lis 5,-32703; mr 3,31; addi 5,5,27068; mtspr 8,9; blrl; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s802B820C_0();

struct AptScriptFunctionBase {
    void RegisterReferences();
};

void AptScriptFunctionBase::RegisterReferences() {
}
