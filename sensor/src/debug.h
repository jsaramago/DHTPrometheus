#ifndef DEBUG_H
#define DEBUG_H

#ifdef DEBUG_MODE
    #include <RemoteDebug.h>
    extern RemoteDebug Debug;
    #define DEBUG_WARNING(message) debugW(message);
    #define DEBUG_DEBUG(message) debugD(message);
#else
    #define DEBUG_WARNING(message)
    #define DEBUG_DEBUG(message)
#endif


#endif /* DEBUG_H */