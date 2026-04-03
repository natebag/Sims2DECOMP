// 0x80109BEC (68 bytes) - DVD build
// cXObjectImpl::TryKillSounds(StackElem *, KillSoundsParam *)

extern void QuietBySourceID(int soundID);

// Use explicit register declarations to match register allocation
void cXObjectImpl_TryKillSounds(
    void* this_ptr,        // r3
    void* stack_elem,      // r4
    void* param) {         // r5

    register short check_flag asm("r0");
    register short* param_ptr asm("r5") = (short*)param;
    register short* this_sound_ptr asm("r3") = (short*)((char*)this_ptr + 0x64);

    check_flag = param_ptr[0];

    int sound_id;
    if (check_flag == 0) {
        sound_id = this_sound_ptr[0];
    } else {
        sound_id = param_ptr[2];
    }

    QuietBySourceID(sound_id);
}
