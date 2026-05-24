// 0x802E94D8 EAnimController::GetAnimTrans(eTrackFlags, (464 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); lis 0,1; mr 31,3; ori 0,0,255; mr 30,6; and. 9,5,0; beq 2f; lwz 0,0x8(4); mr 11,0; cmpwi 0,-1; beq 0f; mulli 9,11,176; lwz 0,0x44(4); add 9,9,0; lwz 0,0x30(9); b 1f; 0:; li 0,0; 1:; and. 9,0,5; beq 17f; mulli 9,11,176; b 16f; 2:; cmpwi 5,2048; beq 9f; bgt 4f; cmpwi 5,512; beq 7f; bgt 3f; cmpwi 5,256; beq 6f; b 14f; 3:; cmpwi 5,1024; beq 8f; b 14f; 4:; cmpwi 5,8192; beq 11f; bgt 5f; cmpwi 5,4096; beq 10f; b 14f; 5:; cmpwi 5,16384; beq 12f; li 0,0; ori 0,0,32768; cmpw 5,0; beq 13f; b 14f; 6:; lwz 9,0x38(4); b 15f; 7:; lwz 9,0x38(4); addi 9,9,1; b 15f; 8:; lwz 9,0x38(4); addi 9,9,2; b 15f; 9:; lwz 9,0x38(4); addi 9,9,3; b 15f; 10:; lwz 9,0x38(4); addi 9,9,4; b 15f; 11:; lwz 9,0x38(4); addi 9,9,5; b 15f; 12:; lwz 9,0x38(4); addi 9,9,6; b 15f; 13:; lwz 9,0x38(4); addi 9,9,7; b 15f; 14:; li 9,-1; 15:; cmpwi 9,-1; beq 17f; mulli 9,9,176; 16:; lwz 0,0x44(4); add 5,0,9; b 18f; 17:; li 5,0; 18:; cmpwi 5,0; beq 19f; lwz 0,0xa8(5); cmpwi 0,0; bne 20f; 19:; lis 9,-32702; lfs f0,-4628(9); stfs f0,0x0(31); stfs f0,0x8(31); stfs f0,0x4(31); b 21f; 20:; addi 3,1,8; bl _s802E94D8_0; lfs f13,0x4(30); addi 9,1,8; lfs f0,0xc(1); lfs f10,0x8(30); fmuls f0,f0,f13; lfs f11,0x0(30); stfs f0,0xc(1); lfs f13,0x8(1); lfs f0,0x8(9); lfs f12,0x4(9); fmuls f13,f13,f11; fmuls f0,f0,f10; stfs f13,0x0(31); stfs f12,0x4(31); stfs f0,0x8(31); stfs f13,0x8(1); stfs f0,0x8(9); 21:; mr 3,31; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"

extern "C" void _s802E94D8_0();

struct EAnimController {
    void GetAnimTrans();
};

void EAnimController::GetAnimTrans() {
}
