// 0x80089214 CreateASimBaseState::GetDatasetName(char *) (44B)
// FLAGS: -fno-schedule-insns

struct DatasetStr11 { int w0; int w4; unsigned short h8; unsigned char b10; };
extern DatasetStr11 s_dataset_createasim;

struct CreateASimBaseState {
    void GetDatasetName(char* dst);
};

void CreateASimBaseState::GetDatasetName(char* dst) {
    int w0 = s_dataset_createasim.w0;
    unsigned char b = s_dataset_createasim.b10;
    int w4 = s_dataset_createasim.w4;
    unsigned short h = s_dataset_createasim.h8;
    *(unsigned char*)&dst[10] = b;
    *(int*)(dst+0) = w0;
    *(int*)(dst+4) = w4;
    *(unsigned short*)(dst+8) = h;
}
