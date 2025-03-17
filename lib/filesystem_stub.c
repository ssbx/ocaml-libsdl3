/* ocaml-libsdl3 - An OCaml interface to the SDL3 library
 Copyright (C) 2035 Sébastien Serre

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

#include <SDL3/SDL_filesystem.h>

CAMLprim value
caml_SDL_GetBasePath(value unit)
{
    CAMLparam0();
    CAMLlocal1(ret);
    const char *base_path = SDL_GetBasePath();
    if (base_path == NULL)
        caml_failwith("Sdlfilesystem.get_base_path");
    ret = caml_copy_string(base_path);
    CAMLreturn(ret);
}

CAMLprim value
caml_SDL_GetPrefPath(value org, value app)
{
    CAMLparam0();
    CAMLlocal1(ret);
    char *pref_path = SDL_GetPrefPath(String_val(org), String_val(app));
    if (pref_path == NULL)
        caml_failwith("Sdlfilesystem.get_pref_path");
    ret = caml_copy_string(pref_path);
    SDL_free(pref_path);
    CAMLreturn(ret);
}

/* vim: set ts=4 sw=4 et: */
