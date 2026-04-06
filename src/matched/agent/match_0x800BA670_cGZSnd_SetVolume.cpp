// FLAGS: -msdata=eabi -G 8
// 0x800BA670 cGZSnd::SetVolume (64b)
extern void cGZSnd_setVolume(void*, int);

struct cGZSnd {
    char pad[28];
    int field_28;
    int currentVol;
    char pad2[16];
    int dirty;
};

void cGZSnd_SetVolume(cGZSnd* self, int vol) {
    if (vol != self->currentVol) {
        if (self->field_28 != 0) {
            self->dirty = 1;
        }
    }
    cGZSnd_setVolume(self, vol);
}
