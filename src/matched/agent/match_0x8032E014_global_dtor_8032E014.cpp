/* global dtor at 0x8032E014 (44 bytes) */

void Init_dtor_8032E014(int flag, unsigned int mask);

void global_dtor_8032E014(void)
{
    Init_dtor_8032E014(0, 0xFFFF);
}
