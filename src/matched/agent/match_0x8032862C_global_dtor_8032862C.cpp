/* global dtor at 0x8032862C (44 bytes) */

void Init_dtor_8032862C(int flag, unsigned int mask);

void global_dtor_8032862C(void)
{
    Init_dtor_8032862C(0, 0xFFFF);
}
