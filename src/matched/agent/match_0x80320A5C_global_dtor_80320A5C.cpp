/* global dtor at 0x80320A5C (44 bytes) */

void Init_dtor_80320A5C(int flag, unsigned int mask);

void global_dtor_80320A5C(void)
{
    Init_dtor_80320A5C(0, 0xFFFF);
}
