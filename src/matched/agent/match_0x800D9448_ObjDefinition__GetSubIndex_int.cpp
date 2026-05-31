// FLAGS: -fno-schedule-insns
// 0x800D9448 ObjDefinition::GetSubIndex(int, int) (20B)
// slwi r3,r3,8; clrlwi r4,r4,24; or r3,r3,r4; extsh r3,r3; blr
// (high << 8) | (low & 0xFF), truncated to short
struct ObjDefinition {
    static short GetSubIndex(int high, int low);
};

short ObjDefinition::GetSubIndex(int high, int low) {
    return (short)((high << 8) | (low & 0xFF));
}
