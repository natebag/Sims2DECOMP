// 0x80109BEC (68 bytes) - DVD build
// cXObjectImpl::TryKillSounds(StackElem *, KillSoundsParam *)

extern void QuietBySourceID(int soundID);

void cXObjectImpl_TryKillSounds(void* this_ptr, void* stack_elem, void* param) {
    // param is KillSoundsParam*
    short* param_ptr = (short*)param;
    short check_flag = param_ptr[0];

    // this_ptr offset 0x64 = 100 decimal
    short* this_sound_ptr = (short*)((char*)this_ptr + 0x64);

    int sound_id;
    if (check_flag == 0) {
        // Load from this[0x64]
        sound_id = this_sound_ptr[0];
    } else {
        // Load from param[2] = param offset 4
        sound_id = param_ptr[2];
    }

    QuietBySourceID(sound_id);
}
