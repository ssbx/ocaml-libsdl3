/* ocaml-libsdl3 - An OCaml interface to the SDL3 library
 Copyright (C) 2025 Sébastien Serre

 This software is provided "AS-IS", without any express or implied warranty.
 In no event will the authors be held liable for any damages arising from
 the use of this software.

 Permission is granted to anyone to use this software for any purpose,
 including commercial applications, and to alter it and redistribute it freely.
*/
#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/fail.h>

#include <SDL3/SDL_video.h>
#include "OcamlSDL3/video_stub.h"
#include "OcamlSDL3/surface_stub.h"
#include "OcamlSDL3/rect_stub.h"

static const Uint32 caml_sdl_windowflags_table[] = {
    SDL_WINDOW_FULLSCREEN,
    SDL_WINDOW_OPENGL,
    SDL_WINDOW_SHOWN,
    SDL_WINDOW_HIDDEN,
    SDL_WINDOW_BORDERLESS,
    SDL_WINDOW_RESIZABLE,
    SDL_WINDOW_MINIMIZED,
    SDL_WINDOW_MAXIMIZED,
    SDL_WINDOW_MOUSE_GRABBED,
    SDL_WINDOW_INPUT_FOCUS,
    SDL_WINDOW_MOUSE_FOCUS,
    SDL_WINDOW_FULLSCREEN_DESKTOP,
    SDL_WINDOW_FOREIGN,
    SDL_WINDOW_HIGH_PIXEL_DENSITY
};

static const SDL_GLAttr ocaml_sdl_glattr_table[] = {
    SDL_GL_RED_SIZE,
    SDL_GL_GREEN_SIZE,
    SDL_GL_BLUE_SIZE,
    SDL_GL_ALPHA_SIZE,
    SDL_GL_BUFFER_SIZE,
    SDL_GL_DOUBLEBUFFER,
    SDL_GL_DEPTH_SIZE,
    SDL_GL_STENCIL_SIZE,
    SDL_GL_ACCUM_RED_SIZE,
    SDL_GL_ACCUM_GREEN_SIZE,
    SDL_GL_ACCUM_BLUE_SIZE,
    SDL_GL_ACCUM_ALPHA_SIZE,
    SDL_GL_STEREO,
    SDL_GL_MULTISAMPLEBUFFERS,
    SDL_GL_MULTISAMPLESAMPLES,
    SDL_GL_ACCELERATED_VISUAL,
    SDL_GL_RETAINED_BACKING,
    SDL_GL_CONTEXT_MAJOR_VERSION,
    SDL_GL_CONTEXT_MINOR_VERSION,
    SDL_GL_CONTEXT_EGL,
    SDL_GL_CONTEXT_FLAGS,
    SDL_GL_CONTEXT_PROFILE_MASK,
    SDL_GL_SHARE_WITH_CURRENT_CONTEXT
};
#define SDL_GLattr_val(v) \
    ocaml_sdl_glattr_table[Long_val(v)]

Uint32
Val_SDL_WindowFlags(value mask_list)
{
    Uint32 c_mask = 0x00000000;
    while (mask_list != Val_emptylist)
    {
        value head = Field(mask_list, 0);
        c_mask |= caml_sdl_windowflags_table[Long_val(head)];
        mask_list = Field(mask_list, 1);
    }
    return c_mask;
}

static inline int
caml_SDL_WindowPos(value pos)
{
    if (Is_long(pos))
    {
        if (pos == caml_hash_variant("centered"))
        {
            return SDL_WINDOWPOS_CENTERED;
        } else
        if (pos == caml_hash_variant("undefined"))
        {
            return SDL_WINDOWPOS_UNDEFINED;
        } else
            caml_failwith("Sdlwindow.window_pos");
    }
    else if (Is_block(pos))
    {
        if (Field(pos,0) == caml_hash_variant("pos"))
        {
            return Int_val(Field(pos,1));
        } else
            caml_failwith("Sdlwindow.window_pos");
    } else {
        caml_failwith("Sdlwindow.window_pos");
    }
}
CAMLprim value
caml_SDL_CreateWindow(
        value title,
        value x, value y,
        value w, value h,
        value flags)
{
    CAMLparam5(title,x,y,w,h);
    CAMLxparam1(flags);

    int _x = caml_SDL_WindowPos(x);
    int _y = caml_SDL_WindowPos(y);

    SDL_Window *win =
        SDL_CreateWindow(
                String_val(title),
                _x, _y,
                Int_val(w), Int_val(h),
                Val_SDL_WindowFlags(flags));

    if (win == NULL)
        caml_failwith("Sdlwindow.create");

    CAMLreturn(Val_SDL_Window(win));
}

CAMLprim value
caml_SDL_CreateWindow_bc(value * argv, int argn)
{
    return caml_SDL_CreateWindow(
                argv[0], argv[1], argv[2],
                argv[3], argv[4], argv[5]);
}

CAMLprim value
caml_SDL_SetWindowTitle(value window, value title)
{
    CAMLparam2(window, title);
    SDL_SetWindowTitle(
            SDL_Window_val(window),
            String_val(title));
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_GetWindowSize(value window)
{
    CAMLparam1(window);
    CAMLlocal1(ret);

    int w, h;
    SDL_GetWindowSize(SDL_Window_val(window), &w, &h);

    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(w));
    Store_field(ret, 1, Val_int(h));
    CAMLreturn(ret);
}

CAMLprim value
caml_SDL_ShowWindow(value window)
{
    CAMLparam1(window);
    SDL_ShowWindow(SDL_Window_val(window));
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_HideWindow(value window)
{
    CAMLparam1(window);
    SDL_HideWindow(SDL_Window_val(window));
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_RaiseWindow(value window)
{
    CAMLparam1(window);
    SDL_RaiseWindow(SDL_Window_val(window));
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_MaximizeWindow(value window)
{
    CAMLparam1(window);
    SDL_MaximizeWindow(SDL_Window_val(window));
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_MinimizeWindow(value window)
{
    CAMLparam1(window);
    SDL_MinimizeWindow(SDL_Window_val(window));
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_RestoreWindow(value window)
{
    CAMLparam1(window);
    SDL_RestoreWindow(SDL_Window_val(window));
    CAMLreturn(Val_unit);
}

/* TODO:
int SDL_SetWindowFullscreen(SDL_Window * window, Uint32 flags);
*/

CAMLprim value
caml_SDL_GetWindowSurface(value window)
{
    CAMLparam1(window);
    SDL_Surface *surf = SDL_GetWindowSurface(SDL_Window_val(window));
    CAMLreturn(Val_SDL_Surface(surf));
}

CAMLprim value
caml_SDL_UpdateWindowSurface(value window)
{
    CAMLparam1(window);
    int r = SDL_UpdateWindowSurface(SDL_Window_val(window));
    if (r)
        caml_failwith("Sdlwindow.update_surface");
    CAMLreturn(Val_unit);
}

/* TODO
int SDL_UpdateWindowSurfaceRects(
      SDL_Window * window, SDL_Rect * rects, int numrects);

void SDL_SetWindowGrab(SDL_Window * window, bool grabbed);

bool SDL_GetWindowGrab(SDL_Window * window);
*/

CAMLprim value
caml_SDL_SetWindowBrightness(value window, value brightness)
{
    CAMLparam2(window, brightness);
    int r = SDL_SetWindowBrightness(SDL_Window_val(window), Double_val(brightness));
    if (r)
        caml_failwith("Sdlwindow.set_brightness");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_GetWindowBrightness(value window)
{
    CAMLparam1(window);
    float brightness = SDL_GetWindowBrightness(SDL_Window_val(window));
    CAMLreturn(caml_copy_double(brightness));
}

/* TODO
int SDL_SetWindowGammaRamp(
      SDL_Window * window,
      const Uint16 * red,
      const Uint16 * green,
      const Uint16 * blue);

int SDL_GetWindowGammaRamp(
      SDL_Window * window,
      Uint16 * red,
      Uint16 * green,
      Uint16 * blue);
*/

CAMLprim value
caml_SDL_DestroyWindow(value window)
{
    CAMLparam1(window);
    SDL_DestroyWindow(SDL_Window_val(window));
    CAMLreturn(Val_unit);
}

/*
bool SDL_ScreenSaverEnabled(void);

void SDL_EnableScreenSaver(void);

void SDL_DisableScreenSaver(void);
*/

/* TODO
int SDL_GL_LoadLibrary(const char *path);
void * SDL_GL_GetProcAddress(const char *proc);
*/

CAMLprim value
caml_SDL_GL_UnloadLibrary(value unit)
{
    CAMLparam1(unit);
    SDL_GL_UnloadLibrary();
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_GL_ExtensionSupported(value extension)
{
    CAMLparam1(extension);
    bool b = SDL_GL_ExtensionSupported(String_val(extension));
    CAMLreturn(Val_bool(b));
}

CAMLprim value
caml_SDL_GL_SetAttribute(value attr, value val)
{
    CAMLparam2(attr, val);
    int r = SDL_GL_SetAttribute(
                SDL_GLattr_val(attr),
                Int_val(val));
    if (r)
        caml_failwith("Sdlgl.set_attribute");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_GL_GetAttribute(value attr)
{
    CAMLparam1(attr);
    int val;
    int r = SDL_GL_GetAttribute(
                SDL_GLattr_val(attr),
                &val);
    if (r)
        caml_failwith("Sdlgl.get_attribute");
    CAMLreturn(Val_int(val));
}

CAMLprim value
caml_SDL_GL_CreateContext(value window)
{
    CAMLparam1(window);
    SDL_GLContext ctx = SDL_GL_CreateContext(SDL_Window_val(window));
    CAMLreturn(Val_SDL_GLContext(ctx));
}

CAMLprim value
caml_SDL_GL_MakeCurrent(value window, value context)
{
    CAMLparam2(window, context);
    int r = SDL_GL_MakeCurrent(
                SDL_Window_val(window),
                SDL_GLContext_val(context));
    CAMLreturn(Val_int(r));
}

CAMLprim value
caml_SDL_GL_SetSwapInterval(value interval)
{
    CAMLparam1(interval);
    int r = SDL_GL_SetSwapInterval(Int_val(interval));
    if (r) caml_failwith("Sdlgl.set_swap_interval");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_GL_GetSwapInterval(value unit)
{
    CAMLparam1(unit);
    int r = SDL_GL_GetSwapInterval();
    CAMLreturn(Val_int(r));
}

CAMLprim value
caml_SDL_GL_SwapWindow(value window)
{
    CAMLparam1(window);
    SDL_GL_SwapWindow(SDL_Window_val(window));
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_GL_DeleteContext(value context)
{
    CAMLparam1(context);
    SDL_GL_DestroyContext(SDL_GLContext_val(context));
    CAMLreturn(Val_unit);
}
/* vim: set ts=4 sw=4 et: */
