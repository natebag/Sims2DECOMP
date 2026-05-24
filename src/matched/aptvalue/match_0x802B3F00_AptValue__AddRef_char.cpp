// 0x802B3F00 AptValue::AddRef(char (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 31,3; lwz 9,-27008(13); lwz 0,0x0(31); rlwinm 0,0,0,25,31; cmpw 0,9; beq 0f; lwz 0,-27004(13); cmpw 31,0; bne 1f; 0:; lis 11,-32700; addi 4,1,8; lhz 9,-6476(11); addi 0,11,-6476; stw 0,0x8(1); mr 3,31; addi 9,9,1; sth 9,-6476(11); bl _s802B3F00_0; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 1f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802B3F00_1; 1:; lwz 0,0x0(31); rlwinm 9,0,18,20,31; addi 9,9,1; cmplwi 9,4095; ble 2f; ori 0,0,128; li 9,4095; stw 0,0x0(31); 2:; lwz 0,0x0(31); rlwimi 0,9,14,6,17; stw 0,0x0(31); lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"

extern "C" void _s802B3F00_0();
extern "C" void _s802B3F00_1();

struct AptValue {
    void AddRef();
};

void AptValue::AddRef() {
}
