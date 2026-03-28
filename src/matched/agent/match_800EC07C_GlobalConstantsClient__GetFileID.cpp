/* GlobalConstantsClient::GetFileID(void) - 8 bytes */

static int s_fileID;

class GlobalConstantsClient {
public:
    int GetFileID(void);
};

int GlobalConstantsClient::GetFileID(void) {
    return s_fileID;
}
