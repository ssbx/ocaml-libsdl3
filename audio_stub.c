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

#include <SDL3/SDL_audio.h>
#include "OcamlSDL3/audio_stub.h"

const SDL_AudioFormat ocaml_SDL_AudioFormat_table[] = {
    SDL_AUDIO_U8,
    SDL_AUDIO_S8,
    AUDIO_U16LSB,
    SDL_AUDIO_S16LE,
    AUDIO_U16MSB,
    SDL_AUDIO_S16BE,
    AUDIO_U16,
    SDL_AUDIO_S16LE,
    SDL_AUDIO_S32LE,
    SDL_AUDIO_S32BE,
    SDL_AUDIO_S32LE,
    SDL_AUDIO_F32LE,
    SDL_AUDIO_F32BE,
    SDL_AUDIO_F32LE,
    AUDIO_U16SYS,
    SDL_AUDIO_S16,
    SDL_AUDIO_S32,
    SDL_AUDIO_F32
};

value
Val_SDL_AudioFormat(SDL_AudioFormat format)
{
    // commented-out cases are synonyms
    switch (format) {
    case SDL_AUDIO_U8: return Val_int(0);
    case SDL_AUDIO_S8: return Val_int(1);
    case AUDIO_U16LSB: return Val_int(2);
    case SDL_AUDIO_S16LE: return Val_int(3);
    case AUDIO_U16MSB: return Val_int(4);
    case SDL_AUDIO_S16BE: return Val_int(5);
        // case AUDIO_U16: return Val_int(6);
        // case SDL_AUDIO_S16LE: return Val_int(7);
    case SDL_AUDIO_S32LE: return Val_int(8);
    case SDL_AUDIO_S32BE: return Val_int(9);
        // case SDL_AUDIO_S32LE: return Val_int(10);
    case SDL_AUDIO_F32LE: return Val_int(11);
    case SDL_AUDIO_F32BE: return Val_int(12);
        // case SDL_AUDIO_F32LE: return Val_int(13);
        // case AUDIO_U16SYS: return Val_int(14);
        // case SDL_AUDIO_S16: return Val_int(15);
        // case SDL_AUDIO_S32: return Val_int(16);
        // case SDL_AUDIO_F32: return Val_int(17);
    }
    caml_failwith("SdlAudiFormat.t");
}

CAMLprim value
caml_SDL_GetAudioDrivers(value unit)
{
    CAMLparam1(unit);
    CAMLlocal1(ret);
    int i, num;
    num = SDL_GetNumAudioDrivers();
    ret = caml_alloc(num, 0);
    for (i = 0; i < num; i++) {
        const char *driver = SDL_GetAudioDriver(i);
        Store_field(ret, i, caml_copy_string(driver));
    }
    CAMLreturn(ret);
}

CAMLprim value
caml_SDL_AudioInit(value driver_name)
{
    CAMLparam1(driver_name);
    int r = SDL_AudioInit(String_val(driver_name));
    if (r) caml_failwith("Sdlaudio.init");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_AudioQuit(value unit)
{
    CAMLparam1(unit);
    SDL_AudioQuit();
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_GetCurrentAudioDriver(value unit)
{
    CAMLparam1(unit);
    CAMLlocal1(ret);
    const char * dr = SDL_GetCurrentAudioDriver();
    ret = caml_copy_string(dr);
    CAMLreturn(ret);
}

static inline SDL_AudioStatus
SDL_AudioStatus_val(value v)
{
    CAMLparam1(v);
    switch (Int_val(v))
    {
        case 0: CAMLreturn(SDL_AUDIO_STOPPED);
        case 1: CAMLreturn(SDL_AUDIO_PLAYING);
        case 2: CAMLreturn(SDL_AUDIO_PAUSED);
        default: caml_failwith("Sdlaudio.status");
    }
    caml_failwith("Sdlaudio.status");
}

static inline value
Val_SDL_AudioStatus(SDL_AudioStatus st)
{
    switch (st)
    {
        case SDL_AUDIO_STOPPED: return Val_int(0);
        case SDL_AUDIO_PLAYING: return Val_int(1);
        case SDL_AUDIO_PAUSED:  return Val_int(2);
        default: caml_failwith("Sdlaudio.status");
    }
    caml_failwith("Sdlaudio.status");
}

CAMLprim value
caml_SDL_GetAudioStatus(value unit)
{
    CAMLparam1(unit);
    SDL_AudioStatus st = SDL_GetAudioStatus();
    CAMLreturn(Val_SDL_AudioStatus(st));
}

CAMLprim value
caml_SDL_PauseAudio(value pause_on)
{
    CAMLparam1(pause_on);
    SDL_PauseAudio(Bool_val(pause_on));
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_LockAudio(value unit)
{
    CAMLparam1(unit);
    SDL_LockAudio();
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_UnlockAudio(value unit)
{
    CAMLparam1(unit);
    SDL_UnlockAudio();
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_CloseAudio(value unit)
{
    CAMLparam1(unit);
    SDL_CloseAudio();
    CAMLreturn(Val_unit);
}

static value Val_SDL_AudioSpec(SDL_AudioSpec * p)
{
    return caml_copy_nativeint((intnat) p);
}

static SDL_AudioSpec * SDL_AudioSpec_val(value v)
{
    return (SDL_AudioSpec *) Nativeint_val(v);
}

CAMLprim value
caml_SDL_alloc_audio_spec(value unit)
{
    CAMLparam1(unit);
    SDL_AudioSpec *audio_spec;
    audio_spec = malloc(sizeof(SDL_AudioSpec));
    CAMLreturn(Val_SDL_AudioSpec(audio_spec));
}

CAMLprim value
caml_SDL_free_audio_spec(value audio_spec)
{
    CAMLparam1(audio_spec);
    free(SDL_AudioSpec_val(audio_spec));
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_LoadWAV(
        value filename,
        value audio_spec)
{
    CAMLparam2(filename, audio_spec);
    CAMLlocal1(ret);
    Uint8 *audio_buf;
    Uint32 audio_len;
    if (SDL_LoadWAV(String_val(filename),
            SDL_AudioSpec_val(audio_spec),
            &audio_buf,
            &audio_len) == NULL) {
        caml_failwith("Sdlaudio.load_wav");
    }
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, ((value)audio_buf));
    Store_field(ret, 1, caml_copy_int32(audio_len));
    CAMLreturn(ret);
}

CAMLprim value
caml_SDL_FreeWAV(value audio_buf)
{
    CAMLparam1(audio_buf);
    SDL_free((Uint8 *) audio_buf);
    CAMLreturn(Val_unit);
}

#define Val_SDL_AudioDeviceID caml_copy_int32
#define SDL_AudioDeviceID_val Int32_val

CAMLprim value
caml_SDL_OpenAudioDevice_simple(value spec)
{
    CAMLparam1(spec);
    SDL_AudioDeviceID deviceId =
        SDL_OpenAudioDevice(
                NULL, 0, SDL_AudioSpec_val(spec), NULL, 0);
    if (deviceId == 0)
        caml_failwith("Sdlaudio.open_audio_device_simple");
    CAMLreturn(Val_SDL_AudioDeviceID(deviceId));
}

CAMLprim value
caml_SDL_QueueAudio(value dev, value data, value len)
{
    CAMLparam3(dev, data, len);
    int success =
        SDL_QueueAudio(
                SDL_AudioDeviceID_val(dev),
                (void *)data,
                (Uint32)Int32_val(len));
    if (success != 0)
        caml_failwith("Sdlaudio.queue_audio");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_UnpauseAudioDevice(value dev)
{
    CAMLparam1(dev);
    int pause_on = 0;
    SDL_PauseAudioDevice(
            SDL_AudioDeviceID_val(dev),
            pause_on);
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_PauseAudioDevice(value dev)
{
    CAMLparam1(dev);
    int pause_on = 1;
    SDL_PauseAudioDevice(
            SDL_AudioDeviceID_val(dev),
            pause_on);
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_CloseAudioDevice(value dev)
{
    CAMLparam1(dev);
    SDL_CloseAudioDevice(SDL_AudioDeviceID_val(dev));
    CAMLreturn(Val_unit);
}

#if 0
int
SDL_OpenAudio(
            SDL_AudioSpec * desired,
            SDL_AudioSpec * obtained);

int SDL_GetNumAudioDevices(int iscapture);
const char *
SDL_GetAudioDeviceName(
            int index,
            int iscapture);

SDL_AudioDeviceID
SDL_OpenAudioDevice(
            const char *device,
            int iscapture,
            const SDL_AudioSpec * desired,
            SDL_AudioSpec * obtained,
            int allowed_changes);

SDL_AudioStatus
SDL_GetAudioDeviceStatus(SDL_AudioDeviceID dev);
SDL_AudioSpec *
SDL_LoadWAV_IO(
            SDL_IOStream * src,
            int freesrc,
            SDL_AudioSpec * spec,
            Uint8 ** audio_buf,
            Uint32 * audio_len);

#define SDL_LoadWAV(file, spec, audio_buf, audio_len) \
	SDL_LoadWAV_IO(SDL_IOFromFile(file, "rb"),1, spec,audio_buf,audio_len)


int
SDL_BuildAudioCVT(
            SDL_AudioCVT * cvt,
            SDL_AudioFormat src_format,
            Uint8 src_channels,
            int src_rate,
            SDL_AudioFormat dst_format,
            Uint8 dst_channels,
            int dst_rate);

int SDL_ConvertAudio(SDL_AudioCVT * cvt);

#define SDL_MIX_MAXVOLUME 128
void
SDL_MixAudio(
            Uint8 * dst, const Uint8 * src,
            Uint32 len, int volume);

void
SDL_MixAudio(
            Uint8 * dst,
            const Uint8 * src,
            SDL_AudioFormat format,
            Uint32 len, int volume);

void SDL_LockAudioDevice(SDL_AudioDeviceID dev);
void SDL_UnlockAudioDevice(SDL_AudioDeviceID dev);
int SDL_AudioDeviceConnected(SDL_AudioDeviceID dev);

#endif

/* vim: set ts=4 sw=4 et: */

