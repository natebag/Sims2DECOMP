/* ObjectFolderImpl::DoCommand(short, int) - 8 bytes */

class ObjectFolderImpl {
public:
    int DoCommand(short cmd, int param);
};

int ObjectFolderImpl::DoCommand(short cmd, int param) {
    return 1;
}
