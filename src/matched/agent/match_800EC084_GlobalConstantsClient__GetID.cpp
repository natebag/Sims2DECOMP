/* GlobalConstantsClient::GetID(void) - 8 bytes */

class GlobalConstantsClient {
public:
    char pad[0x04];
    short m_id;

    short GetID(void);
};

short GlobalConstantsClient::GetID(void) {
    return m_id;
}
