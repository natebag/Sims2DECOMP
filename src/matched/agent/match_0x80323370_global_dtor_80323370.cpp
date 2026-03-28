/* global dtor at 0x80323370 (44 bytes) */

void Init_dtor_80323370(int flag, unsigned int mask);

void global_dtor_80323370(void)
{
    Init_dtor_80323370(0, 0xFFFF);
}
