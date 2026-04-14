// 0x800EB8E0 cXObjectImpl::SetOverrideDialogReturnCode (8B)

extern short s_overrideDialogReturnCode;

struct cXObj_SODRC {
    void SetOverrideDialogReturnCode(short v);
};

void cXObj_SODRC::SetOverrideDialogReturnCode(short v) {
    s_overrideDialogReturnCode = v;
}
