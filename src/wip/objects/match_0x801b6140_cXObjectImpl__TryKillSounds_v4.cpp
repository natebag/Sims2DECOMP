// 0x801b6140 (68 bytes)
// cXObjectImpl::TryKillSounds(StackElem *, KillSoundsParam *)

// External function from cSoundPlayer
extern "C" void cSoundPlayer_QuietBySourceID(int id);

// Simulate the stack element and param structures
struct StackElem {};
struct KillSoundsParam {
    short check_flag;
    short pad;
    short source_id;
};

// Forward declare cXObjectImpl
struct cXObjectImpl {
    char pad[100];
    short sound_id;

    void TryKillSounds(StackElem *elem, KillSoundsParam *param);
};

// Implementation
void cXObjectImpl::TryKillSounds(StackElem *elem, KillSoundsParam *param) {
    int sound_id;
    if (param->check_flag == 0) {
        sound_id = this->sound_id;
    } else {
        sound_id = param->source_id;
    }
    cSoundPlayer_QuietBySourceID(sound_id);
}
