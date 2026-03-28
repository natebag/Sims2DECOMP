/* cXObject::GetAutoCenter(void) - 8 bytes */

static int s_autoCenter;

struct cXObject {
    static int GetAutoCenter(void);
};

int cXObject::GetAutoCenter(void) {
    return s_autoCenter;
}
