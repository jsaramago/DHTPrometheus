#ifndef DEBUG_H
#define DEBUG_H

#ifdef DEBUG_MODE
    #include <RemoteDebug.h>
    char message_buffer [255];
    extern RemoteDebug Debug;
    #define DEBUG_WARNING(message, ...) debugW(message, ##__VA_ARGS__);
    #define DEBUG_DEBUG(message, ...) debugD(message, ##__VA_ARGS__);
#else
    #define DEBUG_WARNING(message, ...)
    #define DEBUG_DEBUG(message, ...)
#endif


#endif /* DEBUG_H */