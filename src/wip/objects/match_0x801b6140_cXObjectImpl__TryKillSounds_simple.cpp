// 0x801b6140 (68 bytes)
// cXObjectImpl::TryKillSounds

extern void QuietBySourceID(int);

void __cXObjectImpl_TryKillSounds(void* this_ptr, void* elem, void* param) {
    short* param_ptr = (short*)param;
    short* this_sound_ptr = (short*)((char*)this_ptr + 100);

    int source_id;
    if (param_ptr[0] == 0) {
        source_id = this_sound_ptr[0];
    } else {
        source_id = param_ptr[2];
    }

    QuietBySourceID(source_id);
}
