/* cXObjectImpl::GetFreeWill(void) - 8 bytes */

static int s_freeWill;

class cXObjectImpl {
public:
    static int GetFreeWill(void);
};

int cXObjectImpl::GetFreeWill(void) {
    return s_freeWill;
}
