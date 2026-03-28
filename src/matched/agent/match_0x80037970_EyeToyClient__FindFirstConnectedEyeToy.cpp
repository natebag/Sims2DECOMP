/* EyeToyClient::FindFirstConnectedEyeToy(void) at 0x80037970 (96B) */

int EyeToyManager_GetPhysicalConnectionCount(void);
int EyeToyManager_IsPhysicallyConnected(int index);

int EyeToyClient_FindFirstConnectedEyeToy(void) {
    int count = EyeToyManager_GetPhysicalConnectionCount();
    int i = 0;
    while (i < count) {
        if (EyeToyManager_IsPhysicallyConnected(i) != 0) {
            return i;
        }
        i++;
    }
    return -1;
}
