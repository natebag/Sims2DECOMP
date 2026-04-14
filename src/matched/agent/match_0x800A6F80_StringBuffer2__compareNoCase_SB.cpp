// 0x800A6F80 StringBuffer2::compareNoCase(StringBuffer2&) const (80B)
struct StringBuffer2;

extern unsigned short* StringBuffer2__c_str(StringBuffer2* self);
extern int StringBuffer2__length(StringBuffer2* self);
extern int StringBuffer2__compareNoCase_wstr(StringBuffer2* self, unsigned short* s, int n);

int StringBuffer2__compareNoCase_SB(StringBuffer2* self, StringBuffer2& other) {
    unsigned short* str = StringBuffer2__c_str(&other);
    int len = StringBuffer2__length(&other);
    return StringBuffer2__compareNoCase_wstr(self, str, len);
}
