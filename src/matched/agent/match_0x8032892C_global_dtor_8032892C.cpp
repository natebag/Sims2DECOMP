/* global dtor at 0x8032892C (44 bytes) */

void Init_dtor_8032892C(int flag, unsigned int mask);

void global_dtor_8032892C(void)
{
    Init_dtor_8032892C(0, 0xFFFF);
}
