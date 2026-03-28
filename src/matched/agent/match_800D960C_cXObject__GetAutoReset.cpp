/* cXObject::GetAutoReset(void) - 8 bytes */

static int s_autoReset;

struct cXObject {
    static int GetAutoReset(void);
};

int cXObject::GetAutoReset(void) {
    return s_autoReset;
}
