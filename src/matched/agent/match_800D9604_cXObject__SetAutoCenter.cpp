/* cXObject::SetAutoCenter(bool) - 8 bytes */

static int s_autoCenter;

struct cXObject {
    static void SetAutoCenter(int val);
};

void cXObject::SetAutoCenter(int val) {
    s_autoCenter = val;
}
