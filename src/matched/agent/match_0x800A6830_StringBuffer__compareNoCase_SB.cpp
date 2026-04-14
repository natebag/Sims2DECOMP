// 0x800A6830 StringBuffer::compareNoCase(StringBuffer&) const (80B)
struct StringBuffer;

extern char* StringBuffer__c_str(StringBuffer* self);
extern int StringBuffer__length(StringBuffer* self);
extern int StringBuffer__compareNoCase_cstr(StringBuffer* self, char* s, int n);

int StringBuffer__compareNoCase_SB(StringBuffer* self, StringBuffer& other) {
    char* str = StringBuffer__c_str(&other);
    int len = StringBuffer__length(&other);
    return StringBuffer__compareNoCase_cstr(self, str, len);
}
