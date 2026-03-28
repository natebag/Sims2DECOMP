/* cXObject::SetAutoReset(bool) - 8 bytes */

static int s_autoReset;

struct cXObject {
    static void SetAutoReset(int val);
};

void cXObject::SetAutoReset(int val) {
    s_autoReset = val;
}
