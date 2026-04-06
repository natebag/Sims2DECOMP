// 0x80119470 cSoundCache::cSoundCache (64b)
void memset_impl(void*, int, int);

void* cSoundCache_ctor(void* self) {
    memset_impl(self, 0, 256);
    *(int*)((char*)self + 256) = 0;
    return self;
}
