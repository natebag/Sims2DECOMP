/* global dtor at 0x80323078 (44 bytes) */

void Init_dtor_80323078(int flag, unsigned int mask);

void global_dtor_80323078(void)
{
    Init_dtor_80323078(0, 0xFFFF);
}
