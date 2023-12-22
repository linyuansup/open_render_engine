#ifndef OPEN_RENDER_ENGINE_API_H
#define OPEN_RENDER_ENGINE_API_H

#ifdef EXPORTED_FUNCTION_VISIBILITY
#ifdef _WIN32
#define EXAPI extern "C" __declspec(dllexport)
#else
#define EXAPI extern "C" __attribute__((visibility("default")))
#endif
#else
#define EXAPI
#endif

#endif