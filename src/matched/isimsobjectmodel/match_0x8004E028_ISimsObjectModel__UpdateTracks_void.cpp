// 0x8004E028 ISimsObjectModel::UpdateTracks(void) (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 0,0x3e8(31); cmpwi 0,1; bne 4f; addi 30,31,820; lis 4,1; mr 3,30; bl _s8004E028_0; lis 9,-32707; lfs f0,0x3ec(31); lfs f13,0x31e8(9); fcmpu 0,f0,f13; blt 0f; cmpwi 3,0; beq 1f; lbz 0,0xe(3); cmpwi 0,0; bne 1f; 0:; mr 3,30; li 4,1; addi 5,31,192; bl _s8004E028_1; lwz 0,0x3cc(31); rlwinm 0,0,0,1,31; b 2f; 1:; lwz 0,0x3cc(31); oris 0,0,32768; 2:; stw 0,0x3cc(31); mr 3,31; bl _s8004E028_2; lwz 0,0x3cc(31); rlwinm 0,0,0,1,31; stw 0,0x3cc(31); b 9f; 3:; li 0,1; b 8f; 4:; cmpwi 0,2; bne 9f; mr 3,31; bl _s8004E028_3; addi 11,31,820; li 10,0; lwz 9,0x38(11); addi 0,9,-1; cmpw 10,0; bgt 7f; lis 9,-32707; lwz 11,0x44(11); lfs f13,0x31ec(9); mr 9,0; 5:; lwz 0,0xa8(11); cmpwi 0,1; bne 6f; lwz 0,0x30(11); andis. 8,0,4; beq 6f; lfs f0,0x50(11); fcmpu 0,f0,f13; bgt 3b; 6:; addi 10,10,1; addi 11,11,176; cmpw 10,9; ble 5b; 7:; li 0,0; 8:; cmpwi 0,0; bne 9f; li 0,1; stw 0,0x3e8(31); 9:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s8004E028_0();
extern "C" void _s8004E028_1();
extern "C" void _s8004E028_2();
extern "C" void _s8004E028_3();

struct ISimsObjectModel {
    void UpdateTracks();
};

void ISimsObjectModel::UpdateTracks() {
}
