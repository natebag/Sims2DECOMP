// 0x80109BEC (68 bytes) - DVD build
// cXObjectImpl::TryKillSounds(StackElem *, KillSoundsParam *)

extern void QuietBySourceID(int soundID);

void cXObjectImpl_TryKillSounds(void* this_ptr, void* stack_elem, void* param) {
    short* param_ptr = (short*)param;
    short check_flag = param_ptr[0];

    short* this_sound_ptr = (short*)((char*)this_ptr + 0x64);
    short* param_sound_ptr = (short*)((char*)param + 4);

    int sound_id;
    if (check_flag != 0) {
        sound_id = param_sound_ptr[0];
    } else {
        sound_id = this_sound_ptr[0];
    }

    QuietBySourceID(sound_id);
}
