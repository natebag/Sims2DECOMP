// 0x802B45FC AptValue::AptValue(AptVirtualFunctionTable_Indices) (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32703; mr 31,3; addi 9,9,9120; mr 30,4; stw 9,0x8(31); bl _s802B45FC_0; mr 3,31; li 4,0; bl _s802B45FC_1; mr 3,31; li 4,1; bl _s802B45FC_2; mr 3,31; li 4,0; bl _s802B45FC_3; mr 3,31; li 4,0; bl _s802B45FC_4; lwz 0,0x0(31); addi 11,13,-27020; cmpwi 30,28; oris 0,0,1024; stw 0,0x0(31); lwz 9,0x0(11); stw 9,0x4(31); addi 9,9,1; stw 9,0x0(11); beq 0f; cmpwi 30,43; beq 0f; cmpwi 30,44; bne 1f; 0:; mr 3,31; bl _s802B45FC_5; b 2f; 1:; mr 3,31; bl _s802B45FC_6; lwz 3,-27600(13); mr 4,31; bl _s802B45FC_7; 2:; mr 3,31; li 4,0; bl _s802B45FC_8; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s802B45FC_0();
extern "C" void _s802B45FC_1();
extern "C" void _s802B45FC_2();
extern "C" void _s802B45FC_3();
extern "C" void _s802B45FC_4();
extern "C" void _s802B45FC_5();
extern "C" void _s802B45FC_6();
extern "C" void _s802B45FC_7();
extern "C" void _s802B45FC_8();

struct AptValue {
    void AptValue_AptVirtualFunctionTable_Indices();
};

void AptValue::AptValue_AptVirtualFunctionTable_Indices() {
}
