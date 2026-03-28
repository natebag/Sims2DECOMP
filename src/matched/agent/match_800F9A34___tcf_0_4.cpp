/* __tcf_0_4 - 40 bytes */

struct ObjectModuleStatic {
    char data[1];
};

static ObjectModuleStatic s_staticObj;

void destroy_static(ObjectModuleStatic* obj, int mode);

void __tcf_0_4(void) {
    destroy_static(&s_staticObj, 2);
}
