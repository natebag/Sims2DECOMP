// 0x800390FC EyeToyClient::GetFunFrameUnLockedBits(int) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s800390FC_0; li 11,0; li 9,0; andi. 0,3,1; beq 1f; li 11,1; 0:; addi 9,9,1; cmpwi 9,4; bgt 1f; sraw 0,3,9; andi. 10,0,1; beq 1f; addi 11,11,1; b 0b; 1:; li 3,0; cmpw 3,11; bge 3f; mtspr 9,11; lis 9,-32707; addi 9,9,5820; 2:; lwz 0,0x0(9); addi 9,9,4; or 3,3,0; bdnz 2b; 3:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s800390FC_0();

struct EyeToyClient {
    void GetFunFrameUnLockedBits();
};

void EyeToyClient::GetFunFrameUnLockedBits() {
}
