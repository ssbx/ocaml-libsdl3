#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>

#include <SDL3/SDL_platform.h>

CAMLprim value
caml_SDL_GetPlatform(value unit)
{
    CAMLparam0();
    const char *platform_name = SDL_GetPlatform();
    CAMLreturn(caml_copy_string(platform_name));
}
