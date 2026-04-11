/* __tcf_0 (object.obj) - 40 bytes */

struct BString2 {
    int m_data[2];
    ~BString2(void);
};

static BString2 s_objectString;

void __tcf_0(void) {
    s_objectString.~BString2();
}
