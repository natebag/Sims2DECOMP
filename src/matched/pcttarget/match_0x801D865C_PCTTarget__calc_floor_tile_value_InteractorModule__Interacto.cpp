// 0x801D865C PCTTarget::calc_floor_tile_value(InteractorModule::Interactor::CallbackData (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mr. 4,4; bne 0f; li 3,0; b 5f; 0:; lwz 0,0xc(4); cmpwi 0,0; beq 4f; lwz 0,0x14(4); mr 9,0; cmpwi 0,0; beq 4f; lwz 11,0x4(9); lwz 0,0x0(9); cmpw 0,11; beq 4f; lis 9,-32697; li 7,0; lwz 8,0x5ea0(9); li 5,0; lwz 9,0x0(8); cmpwi 9,0; beq 1f; lwz 5,-4(9); 1:; mr 10,0; mr 6,11; 2:; lwz 9,0x0(10); cmpw 9,5; bge 3f; lwz 11,0x0(8); rlwinm 9,9,2,0,29; lwzx 9,11,9; cmpwi 9,0; beq 3f; lwz 0,0x0(9); lwz 9,0x4(10); mullw 0,0,9; add 7,7,0; 3:; addi 10,10,8; cmpw 10,6; bne 2b; xoris 0,7,32768; stw 0,0xc(1); lis 11,17200; lis 10,-32705; mr 3,9; stw 11,0x8(1); lfd f13,0x48f0(10); lfd f0,0x8(1); fsub f0,f0,f13; frsp f0,f0; fmr f13,f0; fctiwz f12,f13; stfd f12,0x8(1); lwz 3,0xc(1); b 5f; 4:; lwz 0,0x10(4); lwz 3,0x210(3); mullw 3,0,3; 5:; addi 1,1,16"

struct PCTTarget {
    void calc_floor_tile_value_InteractorModule__Interacto();
};

void PCTTarget::calc_floor_tile_value_InteractorModule__Interacto() {
}
