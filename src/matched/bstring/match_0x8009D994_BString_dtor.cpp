/* BString::~BString(void) - 0x8009D994 (64 bytes) */

struct BString {
    void delete_ref();
    ~BString();
};

BString::~BString()
{
    delete_ref();
}
