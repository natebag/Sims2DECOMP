/* cXObjectImpl::GetAutoCenter(void) - 8 bytes */

static int s_autoCenter;

class cXObjectImpl {
public:
    static int GetAutoCenter(void);
};

int cXObjectImpl::GetAutoCenter(void) {
    return s_autoCenter;
}
