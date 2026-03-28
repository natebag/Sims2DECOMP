struct StringBuffer;

int ResFileFunc(StringBuffer *, int);

struct NghResFileWrapper {
    char pad_00[0x0C];
    int m_field0C;

    int WrapFunc(StringBuffer *sb);
};

int NghResFileWrapper::WrapFunc(StringBuffer *sb) {
    int val = m_field0C;
    return ResFileFunc(sb, val ^ 1);
}
