/* global dtor at 0x80325240 (44 bytes) */

void Init_dtor_80325240(int flag, unsigned int mask);

void global_dtor_80325240(void)
{
    Init_dtor_80325240(0, 0xFFFF);
}
