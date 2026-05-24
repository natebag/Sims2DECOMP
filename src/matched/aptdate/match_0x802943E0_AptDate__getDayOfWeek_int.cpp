// 0x802943E0 AptDate::getDayOfWeek(int, (680 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 27,0x2c(1); stw 0,0x44(1); lis 0,20971; mr 31,4; ori 0,0,34079; lis 9,-32704; mulhw 0,31,0; lwz 10,0x6880(9); addi 9,9,26752; lwz 4,0xc(9); srawi 11,31,31; lwz 7,0x4(9); mr 30,6; lwz 8,0x8(9); srawi 0,0,5; addi 9,1,8; stw 10,0x8(1); subf 29,11,0; stw 7,0x4(9); mr 11,9; addi 28,5,1; stw 8,0x8(9); cmpwi 29,18; stw 4,0xc(9); bgt 1f; addi 0,29,-19; srawi 10,0,31; xor 9,10,0; subf 9,10,9; mr 0,9; cmpwi 9,0; bge 0f; addi 0,9,3; 0:; rlwinm 0,0,0,0,29; subf 0,0,9; subfic 0,0,4; b 3f; 1:; addi 0,29,-19; srawi 10,0,31; xor 9,10,0; subf 9,10,9; mr 0,9; cmpwi 9,0; bge 2f; addi 0,9,3; 2:; rlwinm 0,0,0,0,29; subf 0,0,9; 3:; rlwinm 29,0,2,0,29; lis 0,20971; srawi 9,31,31; ori 0,0,34079; lwzx 27,11,29; mulhw 0,31,0; cmpwi 5,1; srawi 0,0,5; subf 0,9,0; mulli 29,0,100; bne 4f; mr 4,31; bl _s802943E0_0; cmpwi 3,0; li 28,28; beq 10f; li 28,29; b 10f; 4:; andi. 0,5,1; bne 10f; cmpwi 5,8; bne 5f; li 28,5; b 10f; 5:; cmpwi 5,4; bne 6f; li 28,9; b 10f; 6:; cmpwi 5,6; bne 7f; li 28,11; b 10f; 7:; cmpwi 5,10; beq 8f; cmpwi 5,2; bne 9f; 8:; li 28,7; b 10f; 9:; cmpwi 5,0; bne 10f; mr 4,31; bl _s802943E0_1; cmpwi 3,0; li 28,31; beq 10f; li 28,32; 10:; cmpwi 27,0; blt 11f; cmpwi 28,0; bge 12f; 11:; li 3,-1; b 15f; 12:; cmpw 28,30; ble 13f; lis 9,-28087; subf 11,30,28; ori 9,9,9363; srawi 10,11,31; mulhw 9,11,9; addi 8,28,7; add 9,9,11; srawi 9,9,2; subf 9,10,9; rlwinm 0,9,3,0,28; subf 0,9,0; subf 11,0,11; subf 6,11,8; b 14f; 13:; mr 6,30; 14:; lis 30,-28087; subf 28,28,6; ori 30,30,9363; subf 29,29,31; mulhw 9,28,30; xoris 0,29,32768; stw 0,0x24(1); lis 10,17200; lis 8,-32704; srawi 0,28,31; stw 10,0x20(1); add 9,9,28; lfd f0,0x6890(8); srawi 9,9,2; lfd f1,0x20(1); subf 9,0,9; lis 11,-32704; rlwinm 0,9,3,0,28; fsub f1,f1,f0; lfs f13,0x6898(11); subf 0,9,0; frsp f1,f1; subf 28,0,28; fmuls f1,f1,f13; bl _s802943E0_2; fctiwz f0,f1; add 29,27,29; stfd f0,0x20(1); lwz 9,0x24(1); add 29,29,9; mulhw 0,29,30; srawi 11,29,31; add 0,0,29; srawi 0,0,2; subf 0,11,0; rlwinm 9,0,3,0,28; subf 9,0,9; subf 29,9,29; add 28,28,29; mulhw 30,28,30; srawi 0,28,31; add 30,30,28; srawi 30,30,2; subf 30,0,30; rlwinm 3,30,3,0,28; subf 3,30,3; subf 3,3,28; 15:; lwz 0,0x44(1); mtspr 8,0; lmw 27,0x2c(1); addi 1,1,64"

extern "C" void _s802943E0_0();
extern "C" void _s802943E0_1();
extern "C" void _s802943E0_2();

struct AptDate {
    void getDayOfWeek();
};

void AptDate::getDayOfWeek() {
}
