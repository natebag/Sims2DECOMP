// FLAGS: -msdata=eabi -G 8
// 0x800BAEC4 cGZMusic::SetVolume (52b)
extern void cGZMusic_setVolume(void*, int);

struct cGZMusic {
    char pad[20];
    int currentVol;
    char pad2[8];
    int dirty;
};

void cGZMusic_SetVolume(cGZMusic* self, int vol) {
    if (vol != self->currentVol) {
        self->dirty = 1;
    }
    cGZMusic_setVolume(self, vol);
}
