/* cXObjectImpl::GetErrorString(StringBuffer &) - 36 bytes */

struct StringBuffer;

void GetErrorStringGlobal(StringBuffer* buf);

class cXObjectImpl {
public:
    void GetErrorString(StringBuffer& buf);
};

void cXObjectImpl::GetErrorString(StringBuffer& buf) {
    GetErrorStringGlobal(&buf);
}
