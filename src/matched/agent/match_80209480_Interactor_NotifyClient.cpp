// 0x80209480 (56 bytes) - InteractorModule::Interactor::NotifyClient(...)
// Stores this at data[0], copies params[8] to data[4], calls params[12] with data

typedef void (*ClientCallback)(void*);

struct CallbackData_NC {
    void* m_interactor;
    int m_state;
};

struct InteractorParams_NC {
    char pad[8];
    int m_data;
    ClientCallback m_callback;
};

struct Interactor_NC {
    void NotifyClient(CallbackData_NC& data, InteractorParams_NC& params);
};

void Interactor_NC::NotifyClient(CallbackData_NC& data, InteractorParams_NC& params) {
    data.m_interactor = this;
    data.m_state = params.m_data;
    params.m_callback(&data);
}
