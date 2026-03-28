/* global constructors keyed to _localizationShaders at 0x80320A30 (44 bytes) */

void InitLocalizationShaders(int flag, unsigned int mask);

void global_ctor_locShaders(void)
{
    InitLocalizationShaders(1, 0xFFFF);
}
