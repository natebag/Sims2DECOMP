// FLAGS: -fno-elide-constructors
// 0x801190C4 cSampleChannel::~cSampleChannel (76b)
void ch_delete(void*);

void cSampleChannel_dtor(void* self, int mode) {
    ch_stop(self);
    *(int*)self = 0;
    *(int*)((char*)self + 4) = 0;
    if (mode & 1) {
        ch_delete(self);
    }
}
