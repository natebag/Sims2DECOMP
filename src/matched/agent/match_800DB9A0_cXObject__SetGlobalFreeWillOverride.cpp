/* cXObject::SetGlobalFreeWillOverride(bool) - 8 bytes */

static int s_globalFreeWillOverride;

struct cXObject {
    static void SetGlobalFreeWillOverride(int val);
};

void cXObject::SetGlobalFreeWillOverride(int val) {
    s_globalFreeWillOverride = val;
}
