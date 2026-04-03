// 0x801b6140 (68 bytes)
// cXObjectImpl::TryKillSounds(StackElem *, KillSoundsParam *)

extern void QuietBySourceID(int id);

void cXObjectImpl_TryKillSounds(void* this_ptr, void* elem, void* param) {
    short* param_ptr = (short*)param;
    short check_value = param_ptr[0];

    int sound_id;
    if (check_value == 0) {
        // Load from this[100]
        short* this_short_ptr = (short*)((char*)this_ptr + 100);
        sound_id = this_short_ptr[0];
    } else {
        // Load from param[4]
        sound_id = param_ptr[2];  // offset 4 bytes = index 2 in short array
    }

    // Call QuietBySourceID
    QuietBySourceID(sound_id);
}
