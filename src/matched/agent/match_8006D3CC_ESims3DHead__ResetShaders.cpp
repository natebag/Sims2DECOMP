extern void* gShader1;
extern void* gShader2;

void SomeRelease(void*);

void ESims3DHead_ResetShaders() {
    if (gShader1 != 0) {
        SomeRelease(gShader1);
        gShader1 = 0;
    }
    if (gShader2 != 0) {
        SomeRelease(gShader2);
        gShader2 = 0;
    }
}
