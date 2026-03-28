/* ERCharacter::ERCharacter at 0x803686E8 (64 bytes) */

extern int ERCharacter_vtable[];

void EResourceInit(void*);
void SubObjectInit(void*);

struct ERCharacter {
    int* _vtable;
    char _pad_04[0x10];
    int m_subObject;

    ERCharacter();
};

ERCharacter::ERCharacter()
{
    EResourceInit(this);
    _vtable = ERCharacter_vtable;
    SubObjectInit(&m_subObject);
}
