// 0x800B4D58 CTilePt__SetY_float (32b)
struct CTilePt {
    signed char x;
    signed char y;
};

signed char CTilePt_SetY(CTilePt* self, float val) {
    return self->y = (int)val;
}
