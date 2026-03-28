/* ObjDefinition::GetSubIndex(int, int) - 20 bytes */

struct ObjDefinition {
    static short GetSubIndex(int a, int b);
};

short ObjDefinition::GetSubIndex(int a, int b) {
    return (short)((a << 8) | (b & 0xFF));
}
