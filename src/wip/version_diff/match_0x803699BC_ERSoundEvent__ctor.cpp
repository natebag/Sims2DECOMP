/* ERSoundEvent::ERSoundEvent at 0x803699BC (64 bytes) */

extern int ERSoundEvent_vtable[];

void EResourceInit(void*);
void SubObjectInit2(void*);

struct ERSoundEvent {
    int* _vtable;
    char _pad_04[0x20];
    int m_subObject;

    ERSoundEvent();
};

ERSoundEvent::ERSoundEvent()
{
    EResourceInit(this);
    _vtable = ERSoundEvent_vtable;
    SubObjectInit2(&m_subObject);
}
