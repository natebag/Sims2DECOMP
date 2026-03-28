
void* CBMemberTranslator1wRet_ThunkInternal(void *, void *);

void* CBMemberTranslator1wRet_Thunk(void* base, void* arg) {
    return CBMemberTranslator1wRet_ThunkInternal(base, arg);
}
