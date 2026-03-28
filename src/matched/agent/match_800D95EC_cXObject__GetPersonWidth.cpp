/* cXObject::GetPersonWidth(void) - 8 bytes */

static int s_personWidth;

struct cXObject {
    static int GetPersonWidth(void);
};

int cXObject::GetPersonWidth(void) {
    return s_personWidth;
}
