// 0x80369DE0 ERSoundEvent::Refresh (40b)

extern void ERSoundEvent_RefreshImpl(void*, void*);

void ERSoundEvent_Refresh(void* self, void* file) {
    if (file) {
        ERSoundEvent_RefreshImpl(self, file);
    }
}
