// 0x80296888 AptDate::sMethod_UTC(AptValue*, int) (8B) — clean
//
// Native-method handler stub: AptDate.UTC is unimplemented and simply returns
// a cached global AptValue* held in small-data. Compiles to a single
// `lwz r3,g@sda21(r13); blr`.

struct AptValue;

struct AptDate {
    static AptValue* sMethod_UTC(AptValue* args, int argc);
};

extern AptValue* g_aptDateUTCResult;   // SDA: -0x5998(r13)

AptValue* AptDate::sMethod_UTC(AptValue* args, int argc) {
    return g_aptDateUTCResult;
}
