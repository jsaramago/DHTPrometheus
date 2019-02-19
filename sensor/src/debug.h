#ifndef DEBUG_H
#define DEBUG_H

#ifdef DEBUG_MODE
    #include <RemoteDebug.h>
    extern RemoteDebug Debug;
    #define DEBUG_WARNING(message) debugW(message);
#else
    #define DEBUG_WARNING(message)
#endif


#endif /* DEBUG_H */