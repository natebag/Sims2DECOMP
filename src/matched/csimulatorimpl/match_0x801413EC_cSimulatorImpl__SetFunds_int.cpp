// 0x801413EC cSimulatorImpl::SetFunds(int, (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); lwz 10,0x74(3); lwz 9,0x78(3); add 0,10,9; cmpw 4,0; beq 1f; subf 0,10,4; lis 11,15; subf 8,9,0; ori 11,11,16959; add 9,10,0; stw 0,0x78(3); cmpw 9,11; ble 0f; subf 0,10,11; stw 0,0x78(3); add 4,10,0; 0:; lis 0,26843; srawi 11,4,31; ori 0,0,35757; cmpwi 8,0; mulhw 0,4,0; srawi 0,0,12; subf 0,11,0; mulli 9,0,10000; sth 0,0x30(3); subf 9,9,4; sth 9,0x2e(3); ble 1f; lis 30,20971; li 0,0; ori 30,30,34079; sth 0,0x8(1); mulhw 30,4,30; lhz 9,-21224(13); addi 29,1,8; lhz 0,-21208(13); sth 9,0x4(29); mr 4,29; sth 9,0x2(29); li 5,0; srawi 30,30,5; sth 0,0x8(1); subf 30,11,30; lwz 11,-21476(13); sth 30,0xc(1); lwz 9,0x0(11); lwz 0,0x1ac(9); lha 3,0x1a8(9); mtspr 8,0; add 3,11,3; blrl; lhz 0,-21206(13); mr 4,29; sth 30,0xc(1); li 5,0; sth 0,0x8(1); lwz 11,-21476(13); lwz 9,0x0(11); lha 3,0x1a8(9); lwz 0,0x1ac(9); add 3,11,3; mtspr 8,0; blrl; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"

struct cSimulatorImpl {
    void SetFunds();
};

void cSimulatorImpl::SetFunds() {
}
