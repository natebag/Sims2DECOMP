struct EVec3 { float x, y, z; };

struct SAnimator2 {
    char _pad[0x134];
    EVec3 bone0;
    EVec3 bone1;
    EVec3 bone2;
};

EVec3* SAnimator2_GetBonePos(SAnimator2* self, int idx, EVec3* out) {
    EVec3* src = 0;
    switch (idx) {
        case 0: src = &self->bone0; break;
        case 1: src = &self->bone1; break;
        case 2: src = &self->bone2; break;
    }
    if (src) {
        out->x = src->x;
        out->y = src->y;
        out->z = src->z;
    }
    return out;
}
