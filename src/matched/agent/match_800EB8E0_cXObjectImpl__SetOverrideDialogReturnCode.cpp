/* cXObjectImpl::SetOverrideDialogReturnCode(TreeReturnCode) - 8 bytes */

typedef short TreeReturnCode;

static TreeReturnCode s_overrideDialogReturnCode;

class cXObjectImpl {
public:
    void SetOverrideDialogReturnCode(TreeReturnCode code);
};

void cXObjectImpl::SetOverrideDialogReturnCode(TreeReturnCode code) {
    s_overrideDialogReturnCode = code;
}
