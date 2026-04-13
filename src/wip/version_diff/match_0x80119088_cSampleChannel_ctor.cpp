// FLAGS: -fno-elide-constructors
// 0x80119088 cSampleChannel::cSampleChannel (60b)
void* cSampleChannel_ctor(void* self, void* patch) {
    *(int*)((char*)self + 0) = 0;
    *(int*)((char*)self + 4) = 0;
    ch_init(self);
    return self;
}
