/* cXObjectImpl::SetAutoReset(bool) - 8 bytes */

static int s_autoReset;

class cXObjectImpl {
public:
    static void SetAutoReset(int val);
};

void cXObjectImpl::SetAutoReset(int val) {
    s_autoReset = val;
}
