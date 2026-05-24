// 0x800B6650 FamilyImpl::LoadByResID(iResFile (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 28,0x28(1); stw 0,0x3c(1); mr 31,3; mr 30,4; mr 29,5; mr 28,6; addi 6,1,8; li 0,0; addi 8,6,8; stw 0,0x8(1); addi 7,31,44; stw 0,0x4(6); stw 0,0x4(8); lwz 0,0x28(31); lwz 9,0x24(31); lwz 11,0x8(1); lwz 10,0xc(1); stw 9,0x8(1); stw 0,0xc(1); stw 11,0x24(31); lwz 0,0x4(8); stw 10,0x28(31); stw 0,0x24(1); lwz 9,0x2c(31); lwz 0,0x4(7); stw 9,0x8(6); stw 0,0x4(8); lwz 9,0x20(1); lwz 0,0x24(1); stw 9,0x2c(31); stw 0,0x4(7); lwz 0,0x4(6); lwz 9,0x8(1); cmpw 9,0; beq 1f; 0:; addi 9,9,4; cmpw 9,0; bne 0b; 1:; lwz 3,0x0(6); cmpwi 3,0; beq 3f; lwz 0,0xc(6); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 2f; bl _s800B6650_0; b 3f; 2:; bl _s800B6650_1; 3:; lis 5,17985; mr 3,31; mr 4,30; mr 6,29; mr 7,28; ori 5,5,19785; bl _s800B6650_2; subfic 0,3,0; adde 3,0,3; lwz 0,0x3c(1); mtspr 8,0; lmw 28,0x28(1); addi 1,1,56"

extern "C" void _s800B6650_0();
extern "C" void _s800B6650_1();
extern "C" void _s800B6650_2();

struct FamilyImpl {
    void LoadByResID_iResFile();
};

void FamilyImpl::LoadByResID_iResFile() {
}
