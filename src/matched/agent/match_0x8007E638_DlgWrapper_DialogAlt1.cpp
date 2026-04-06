// 0x8007E638 DlgWrapper::DialogAlt1 (24b)
int DlgW_DialogAlt1(char* self) {
    return *(int*)(*(char**)(self + 172) + 52) == 3;
}
