// 0x800B4D38 CTilePt__SetX_float (32b)
struct CTilePt {
    signed char x;
    signed char y;
};

signed char CTilePt_SetX(CTilePt* self, float val) {
    return self->x = (int)val;
}
