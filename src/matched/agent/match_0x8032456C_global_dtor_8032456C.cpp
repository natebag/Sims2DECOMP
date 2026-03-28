/* global dtor at 0x8032456C (44 bytes) */

void Init_dtor_8032456C(int flag, unsigned int mask);

void global_dtor_8032456C(void)
{
    Init_dtor_8032456C(0, 0xFFFF);
}
