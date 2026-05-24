// 0x80040550 EGlobal::ConvertUnicodeToShiftJIS(unsigned (372 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,4; lwz 3,0xe4(3); lis 4,-32707; mr 28,6; mr 29,5; addi 4,4,10412; bl _s80040550_0; lwz 30,0xc(3); li 4,0; lwz 3,0x4(3); mr 8,28; cmplwi 28,3; sth 4,0x0(29); ble 8f; lhz 0,0x0(31); li 12,0; cmpwi 0,0; beq 8f; 0:; lhzx 9,12,31; li 10,0; ori 10,10,38529; addi 0,9,-65; cmplwi 0,25; ble 2f; addi 0,9,-97; cmplwi 0,25; bgt 1f; addi 0,9,32; b 3f; 1:; addi 0,9,-48; cmplwi 0,9; bgt 4f; 2:; addi 0,9,31; 3:; addi 5,8,-2; rlwinm 10,0,8,16,23; addi 6,4,1; ori 10,10,130; b 7f; 4:; rlwinm 9,9,0,16,31; cmpwi 9,10; bne 5f; addi 5,8,-2; li 10,10; addi 6,4,1; b 7f; 5:; li 7,0; addi 5,8,-2; cmpw 7,30; addi 6,4,1; bge 7f; lhz 0,0x0(3); cmpw 0,9; bne 6f; lhz 10,0x2(3); b 7f; 6:; addi 7,7,1; cmpw 7,30; bge 7f; rlwinm 0,7,2,0,29; lhzx 11,12,31; lhzx 9,3,0; add 8,0,3; cmpw 9,11; bne 6b; lhz 10,0x2(8); 7:; rlwinm 0,10,8,0,23; rlwinm 9,10,24,8,31; add 11,4,4; or 9,9,0; mr 8,5; sthx 9,11,29; mr 4,6; cmplwi 8,3; ble 8f; add 0,4,4; lhzx 9,31,0; mr 12,0; cmpwi 9,0; bne 0b; 8:; add 3,4,4; cmplw 3,28; bge 9f; li 0,0; sthx 0,3,29; 9:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s80040550_0();

struct EGlobal {
    void ConvertUnicodeToShiftJIS();
};

void EGlobal::ConvertUnicodeToShiftJIS() {
}
