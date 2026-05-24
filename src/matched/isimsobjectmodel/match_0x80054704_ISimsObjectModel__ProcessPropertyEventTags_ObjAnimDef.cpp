// 0x80054704 ISimsObjectModel::ProcessPropertyEventTags(ObjAnimDef (476 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; mfcr 12; stfd f31,0x20(1); stmw 29,0x14(1); stw 0,0x2c(1); stw 12,0x10(1); lwz 4,0x8(4); mr 31,3; fmr f31,f1; li 29,0; cmpwi 4,0; beq 0f; lis 3,-32693; addi 3,3,11064; bl _s80054704_0; mr 29,3; 0:; cmpwi 4,29,0; beq cr4,11f; lis 9,-32707; lfs f13,-26800(13); lfs f0,0x330c(9); lfs f11,0x48c(31); mr 11,10; fmuls f13,f13,f0; lis 8,17200; fmadds f13,f13,f31,f11; lis 9,-32707; fmr f0,f13; lfd f11,0x3310(9); fctiwz f12,f0; stfd f12,0x8(1); lwz 30,0xc(1); xoris 0,30,32768; cmpwi 30,0; stw 0,0xc(1); stw 8,0x8(1); lfd f0,0x8(1); fsub f0,f0,f11; frsp f0,f0; fsubs f13,f13,f0; stfs f13,0x48c(31); beq 11f; lwz 5,0x490(31); mr 3,31; mr 4,29; mr 6,30; li 7,0; bl _s80054704_1; addi 9,31,1188; lwz 11,0x4a4(31); lwz 0,0x4(9); mr 8,9; subf 0,11,0; rlwinm. 9,0,30,2,31; beq 1f; addi 0,3,1; b 2f; 1:; lwz 0,0x490(31); add 0,0,30; 2:; stw 0,0x490(31); li 10,0; beq cr4,3f; lwz 10,0x14(29); 3:; lwz 0,0x498(31); cmpwi 0,0; beq 11f; lwz 0,0x490(31); cmpw 0,10; ble 11f; addi 9,31,820; mr 11,9; lwz 9,0x8(9); cmpwi 9,0; blt 4f; mulli 9,9,176; lwz 0,0x44(11); add 0,0,9; b 5f; 4:; li 0,0; 5:; cmpwi 0,0; beq 11f; lwz 0,0x4a4(31); stw 0,0x4(8); lwz 9,0x8(11); cmpwi 9,0; blt 6f; mulli 9,9,176; lwz 0,0x44(11); add 9,0,9; b 7f; 6:; li 9,0; 7:; lbz 0,0xd(9); cmpwi 0,1; beq 8f; cmpwi 0,2; beq 9f; b 10f; 8:; stw 10,0x490(31); 9:; li 0,1; stw 0,0x49c(31); b 11f; 10:; lwz 0,0x490(31); mr 3,31; mr 4,29; li 5,0; subf 0,10,0; li 7,0; mr 6,0; stw 0,0x490(31); bl _s80054704_2; 11:; lwz 0,0x2c(1); lwz 12,0x10(1); mtspr 8,0; lmw 29,0x14(1); lfd f31,0x20(1); mtcrf 8,12; addi 1,1,40"

extern "C" void _s80054704_0();
extern "C" void _s80054704_1();
extern "C" void _s80054704_2();

struct ISimsObjectModel {
    void ProcessPropertyEventTags_ObjAnimDef();
};

void ISimsObjectModel::ProcessPropertyEventTags_ObjAnimDef() {
}
