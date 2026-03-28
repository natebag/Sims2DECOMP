/* cXObject::GetFreeWill(void) - 8 bytes */

static int s_freeWill;

struct cXObject {
    static int GetFreeWill(void);
};

int cXObject::GetFreeWill(void) {
    return s_freeWill;
}
