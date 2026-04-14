// 0x8007E608 DlgWrapper::DialogAccepted (24b)
int DlgW_DialogAccepted(char* self) {
    return *(int*)(*(char**)(self + 172) + 52) == 1;
}
