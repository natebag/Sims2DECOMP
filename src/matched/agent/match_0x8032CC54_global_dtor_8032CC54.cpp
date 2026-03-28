/* global dtor at 0x8032CC54 (44 bytes) */

void Init_dtor_8032CC54(int flag, unsigned int mask);

void global_dtor_8032CC54(void)
{
    Init_dtor_8032CC54(0, 0xFFFF);
}
