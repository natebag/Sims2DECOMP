// 0x8007E620 DlgWrapper::DialogDeclined (24b)
int DlgW_DialogDeclined(char* self) {
    return *(int*)(*(char**)(self + 172) + 52) == 2;
}
