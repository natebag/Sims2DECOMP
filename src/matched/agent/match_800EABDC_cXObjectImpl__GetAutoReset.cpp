/* cXObjectImpl::GetAutoReset(void) - 8 bytes */

static int s_autoReset;

class cXObjectImpl {
public:
    static int GetAutoReset(void);
};

int cXObjectImpl::GetAutoReset(void) {
    return s_autoReset;
}
