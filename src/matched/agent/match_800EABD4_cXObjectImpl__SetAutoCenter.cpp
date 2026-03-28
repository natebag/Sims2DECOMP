/* cXObjectImpl::SetAutoCenter(bool) - 8 bytes */

static int s_autoCenter;

class cXObjectImpl {
public:
    static void SetAutoCenter(int val);
};

void cXObjectImpl::SetAutoCenter(int val) {
    s_autoCenter = val;
}
