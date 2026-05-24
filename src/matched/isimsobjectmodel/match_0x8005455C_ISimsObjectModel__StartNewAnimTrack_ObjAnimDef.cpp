// 0x8005455C ISimsObjectModel::StartNewAnimTrack(ObjAnimDef (424 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; mfcr 12; stmw 28,0x10(1); stw 0,0x24(1); stw 12,0xc(1); mr 31,3; lwz 30,0x8(4); lwz 0,0x428(31); mr 28,5; cmpw 0,30; bne 0f; cmpwi 28,0; beq 7f; 0:; lwz 0,0x378(31); cmpwi 0,0; beq 7f; lis 9,-32707; lwz 10,0x4a4(31); lfs f0,0x3308(9); li 11,0; li 0,1; stw 11,0x49c(31); stfs f0,0x48c(31); cmpwi 4,30,0; stw 0,0x498(31); stw 10,0x4a8(31); stw 11,0x490(31); beq cr4,1f; lwz 11,0x328(31); cmpwi 11,0; beq 1f; lwz 9,0x4(11); lha 3,0xd0(9); lwz 0,0xd4(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 1f; lwz 3,0x328(31); lwz 9,0x4(3); lha 0,0xc8(9); lwz 9,0xcc(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 1f; lwz 3,0x328(31); lwz 9,0x4(3); lha 0,0x4e0(9); lwz 9,0x4e4(9); add 3,3,0; mtspr 8,9; blrl; b 7f; 1:; addi 3,31,820; li 4,1; addi 5,31,192; bl _s8005455C_0; lwz 0,0x3cc(31); lis 9,-32707; lfs f0,0x3308(9); addi 11,31,1056; rlwinm 0,0,0,1,31; mr 29,11; stw 0,0x3cc(31); li 9,0; stfs f0,0x3ec(31); lwz 0,0x8(11); cmpwi 0,0; beq 2f; beq cr4,2f; li 9,1; 2:; cmpwi 9,1; bne 3f; cmpwi 28,0; bne 3f; mr 3,31; mr 4,30; bl _s8005455C_1; b 6f; 3:; li 0,1; bne cr4,4f; li 0,0; 4:; cmpwi 0,1; bne 5f; mr 3,31; mr 4,30; bl _s8005455C_2; b 6f; 5:; mfcr 0; rlwinm 0,0,19,31,31; cmpwi 0,1; bne 6f; mr 3,31; bl _s8005455C_3; 6:; stw 30,0x8(29); 7:; lwz 0,0x24(1); lwz 12,0xc(1); mtspr 8,0; lmw 28,0x10(1); mtcrf 8,12; addi 1,1,32"

extern "C" void _s8005455C_0();
extern "C" void _s8005455C_1();
extern "C" void _s8005455C_2();
extern "C" void _s8005455C_3();

struct ISimsObjectModel {
    void StartNewAnimTrack_ObjAnimDef();
};

void ISimsObjectModel::StartNewAnimTrack_ObjAnimDef() {
}
