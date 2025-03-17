
type uint8 = int
type uint16 = int
type uint32 = int32
type uint64 = int64

module Subsystem = struct
  type t =
    [ `TIMER
    | `AUDIO
    | `VIDEO
    | `JOYSTICK
    | `HAPTIC
    | `GAMECONTROLLER
    | `EVENTS
    | `EVERYTHING
    | `NOPARACHUTE
    ]
end

external init : Subsystem.t list -> unit = "caml_SDL_Init"
(*[< subsystem | `EVERYTHING | `NOPARACHUTE ] list -> unit*)

external init_subsystem : Subsystem.t list -> unit = "caml_SDL_InitSubSystem"
external quit : unit -> unit = "caml_SDL_Quit"
external quit_requested : unit -> bool = "caml_SDL_QuitRequested"

module AudioBuffer = struct
  type t
end

module AudioDeviceID = struct
  type t
end

module AudioSpec = struct
  type t
end

module AudioStream = struct
  type t
end

module AudioFormat = struct
  type t =
    | AUDIO_U8
    | AUDIO_S8
    | AUDIO_U16LSB
    | AUDIO_S16LSB
    | AUDIO_U16MSB
    | AUDIO_S16MSB
    | AUDIO_U16
    | AUDIO_S16
    | AUDIO_S32LSB
    | AUDIO_S32MSB
    | AUDIO_S32
    | AUDIO_F32LSB
    | AUDIO_F32MSB
    | AUDIO_F32
    | AUDIO_U16SYS
    | AUDIO_S16SYS
    | AUDIO_S32SYS
    | AUDIO_F32SYS
end

module AudioStatus = struct
  type t =
    | Stopped
    | Playing
    | Paused

  let to_string = function
    | Stopped -> "Stopped"
    | Playing -> "Playing"
    | Paused -> "Paused"
  ;;

  let of_string = function
    | "Stopped" -> Stopped
    | "Playing" -> Playing
    | "Paused" -> Paused
    | str -> invalid_arg str
  ;;
end

(** internals *)
external new_audio_spec : unit -> AudioSpec.t = "caml_SDL_alloc_audio_spec"

(** internals *)
external free_audio_spec : AudioSpec.t -> unit = "caml_SDL_free_audio_spec"

external get_audio_drivers : unit -> string array = "caml_SDL_GetAudioDrivers"
external audio_init : driver_name:string -> unit = "caml_SDL_AudioInit"
external audio_quit : unit -> unit = "caml_SDL_AudioQuit"
external get_current_audio_driver : unit -> string = "caml_SDL_GetCurrentAudioDriver"
external get_audio_status : unit -> AudioStatus.t = "caml_SDL_GetAudioStatus"
external pause_audio : pause_on:bool -> unit = "caml_SDL_PauseAudio"
external lock_audio : unit -> unit = "caml_SDL_LockAudio"
external unlock_audio : unit -> unit = "caml_SDL_UnlockAudio"
external close_audio : unit -> unit = "caml_SDL_CloseAudio"

external load_wav
  :  filename:string
  -> spec:AudioSpec.t
  -> AudioBuffer.t * int32
  = "caml_SDL_LoadWAV"

external free_wav : AudioBuffer.t -> unit = "caml_SDL_FreeWAV"

external open_audio_device_simple
  :  AudioSpec.t
  -> AudioDeviceID.t
  = "caml_SDL_OpenAudioDevice_simple"

external queue_audio
  :  AudioDeviceID.t
  -> AudioBuffer.t
  -> int32
  -> unit
  = "caml_SDL_QueueAudio"

external unpause_audio_device : AudioDeviceID.t -> unit = "caml_SDL_UnpauseAudioDevice"
external pause_audio_device : AudioDeviceID.t -> unit = "caml_SDL_PauseAudioDevice"
external close_audio_device : AudioDeviceID.t -> unit = "caml_SDL_CloseAudioDevice"

module Rect = struct
  type t =
    { x : int
    ; y : int
    ; w : int
    ; h : int
    }

  let make ~x ~y ~w ~h = { x; y; w; h }
end

module Point = struct
  type t =
    { x : int
    ; y : int
    }
end

external has_intersection : a:Rect.t -> b:Rect.t -> bool = "caml_SDL_HasIntersection"

external intersect_rect_and_line
  :  rect:Rect.t
  -> x1:int
  -> y1:int
  -> x2:int
  -> y2:int
  -> (int * int * int * int) option
  = "caml_SDL_IntersectRectAndLine"

external point_in_rect : p:Point.t -> r:Rect.t -> bool = "caml_SDL_PointInRect"

module Color = struct
  type t =
    { r : uint8
    ; g : uint8
    ; b : uint8
    ; a : uint8
    }
  let make ~r ~g ~b ~a = {r; g; b; a}
end
module PixelFormat = struct
  type t =
    | Unknown
    | Index1LSB
    | Index1MSB
    | Index4LSB
    | Index4MSB
    | Index8
    | RGB332
    | RGB444
    | RGB555
    | BGR555
    | ARGB4444
    | RGBA4444
    | ABGR4444
    | BGRA4444
    | ARGB1555
    | RGBA5551
    | ABGR1555
    | BGRA5551
    | RGB565
    | BGR565
    | RGB24
    | BGR24
    | RGB888
    | RGBX8888
    | BGR888
    | BGRX8888
    | ARGB8888
    | RGBA8888
    | ABGR8888
    | BGRA8888
    | ARGB2101010
    | YV12
    | IYUV
    | YUY2
    | UYVY
    | YVYU

  let to_string = function
    | Unknown -> "SDL_PIXELFORMAT_UNKNOWN"
    | Index1LSB -> "SDL_PIXELFORMAT_INDEX1LSB"
    | Index1MSB -> "SDL_PIXELFORMAT_INDEX1MSB"
    | Index4LSB -> "SDL_PIXELFORMAT_INDEX4LSB"
    | Index4MSB -> "SDL_PIXELFORMAT_INDEX4MSB"
    | Index8 -> "SDL_PIXELFORMAT_INDEX8"
    | RGB332 -> "SDL_PIXELFORMAT_RGB332"
    | RGB444 -> "SDL_PIXELFORMAT_RGB444"
    | RGB555 -> "SDL_PIXELFORMAT_RGB555"
    | BGR555 -> "SDL_PIXELFORMAT_BGR555"
    | ARGB4444 -> "SDL_PIXELFORMAT_ARGB4444"
    | RGBA4444 -> "SDL_PIXELFORMAT_RGBA4444"
    | ABGR4444 -> "SDL_PIXELFORMAT_ABGR4444"
    | BGRA4444 -> "SDL_PIXELFORMAT_BGRA4444"
    | ARGB1555 -> "SDL_PIXELFORMAT_ARGB1555"
    | RGBA5551 -> "SDL_PIXELFORMAT_RGBA5551"
    | ABGR1555 -> "SDL_PIXELFORMAT_ABGR1555"
    | BGRA5551 -> "SDL_PIXELFORMAT_BGRA5551"
    | RGB565 -> "SDL_PIXELFORMAT_RGB565"
    | BGR565 -> "SDL_PIXELFORMAT_BGR565"
    | RGB24 -> "SDL_PIXELFORMAT_RGB24"
    | BGR24 -> "SDL_PIXELFORMAT_BGR24"
    | RGB888 -> "SDL_PIXELFORMAT_RGB888"
    | RGBX8888 -> "SDL_PIXELFORMAT_RGBX8888"
    | BGR888 -> "SDL_PIXELFORMAT_BGR888"
    | BGRX8888 -> "SDL_PIXELFORMAT_BGRX8888"
    | ARGB8888 -> "SDL_PIXELFORMAT_ARGB8888"
    | RGBA8888 -> "SDL_PIXELFORMAT_RGBA8888"
    | ABGR8888 -> "SDL_PIXELFORMAT_ABGR8888"
    | BGRA8888 -> "SDL_PIXELFORMAT_BGRA8888"
    | ARGB2101010 -> "SDL_PIXELFORMAT_ARGB2101010"
    | YV12 -> "SDL_PIXELFORMAT_YV12"
    | IYUV -> "SDL_PIXELFORMAT_IYUV"
    | YUY2 -> "SDL_PIXELFORMAT_YUY2"
    | UYVY -> "SDL_PIXELFORMAT_UYVY"
    | YVYU -> "SDL_PIXELFORMAT_YVYU"
  ;;

  let of_string s =
    match String.uppercase_ascii s with
    | "SDL_PIXELFORMAT_UNKNOWN" -> Unknown
    | "SDL_PIXELFORMAT_INDEX1LSB" -> Index1LSB
    | "SDL_PIXELFORMAT_INDEX1MSB" -> Index1MSB
    | "SDL_PIXELFORMAT_INDEX4LSB" -> Index4LSB
    | "SDL_PIXELFORMAT_INDEX4MSB" -> Index4MSB
    | "SDL_PIXELFORMAT_INDEX8" -> Index8
    | "SDL_PIXELFORMAT_RGB332" -> RGB332
    | "SDL_PIXELFORMAT_RGB444" -> RGB444
    | "SDL_PIXELFORMAT_RGB555" -> RGB555
    | "SDL_PIXELFORMAT_BGR555" -> BGR555
    | "SDL_PIXELFORMAT_ARGB4444" -> ARGB4444
    | "SDL_PIXELFORMAT_RGBA4444" -> RGBA4444
    | "SDL_PIXELFORMAT_ABGR4444" -> ABGR4444
    | "SDL_PIXELFORMAT_BGRA4444" -> BGRA4444
    | "SDL_PIXELFORMAT_ARGB1555" -> ARGB1555
    | "SDL_PIXELFORMAT_RGBA5551" -> RGBA5551
    | "SDL_PIXELFORMAT_ABGR1555" -> ABGR1555
    | "SDL_PIXELFORMAT_BGRA5551" -> BGRA5551
    | "SDL_PIXELFORMAT_RGB565" -> RGB565
    | "SDL_PIXELFORMAT_BGR565" -> BGR565
    | "SDL_PIXELFORMAT_RGB24" -> RGB24
    | "SDL_PIXELFORMAT_BGR24" -> BGR24
    | "SDL_PIXELFORMAT_RGB888" -> RGB888
    | "SDL_PIXELFORMAT_RGBX8888" -> RGBX8888
    | "SDL_PIXELFORMAT_BGR888" -> BGR888
    | "SDL_PIXELFORMAT_BGRX8888" -> BGRX8888
    | "SDL_PIXELFORMAT_ARGB8888" -> ARGB8888
    | "SDL_PIXELFORMAT_RGBA8888" -> RGBA8888
    | "SDL_PIXELFORMAT_ABGR8888" -> ABGR8888
    | "SDL_PIXELFORMAT_BGRA8888" -> BGRA8888
    | "SDL_PIXELFORMAT_ARGB2101010" -> ARGB2101010
    | "SDL_PIXELFORMAT_YV12" -> YV12
    | "SDL_PIXELFORMAT_IYUV" -> IYUV
    | "SDL_PIXELFORMAT_YUY2" -> YUY2
    | "SDL_PIXELFORMAT_UYVY" -> UYVY
    | "SDL_PIXELFORMAT_YVYU" -> YVYU
    | "PIXELFORMAT_UNKNOWN" -> Unknown
    | "PIXELFORMAT_INDEX1LSB" -> Index1LSB
    | "PIXELFORMAT_INDEX1MSB" -> Index1MSB
    | "PIXELFORMAT_INDEX4LSB" -> Index4LSB
    | "PIXELFORMAT_INDEX4MSB" -> Index4MSB
    | "PIXELFORMAT_INDEX8" -> Index8
    | "PIXELFORMAT_RGB332" -> RGB332
    | "PIXELFORMAT_RGB444" -> RGB444
    | "PIXELFORMAT_RGB555" -> RGB555
    | "PIXELFORMAT_BGR555" -> BGR555
    | "PIXELFORMAT_ARGB4444" -> ARGB4444
    | "PIXELFORMAT_RGBA4444" -> RGBA4444
    | "PIXELFORMAT_ABGR4444" -> ABGR4444
    | "PIXELFORMAT_BGRA4444" -> BGRA4444
    | "PIXELFORMAT_ARGB1555" -> ARGB1555
    | "PIXELFORMAT_RGBA5551" -> RGBA5551
    | "PIXELFORMAT_ABGR1555" -> ABGR1555
    | "PIXELFORMAT_BGRA5551" -> BGRA5551
    | "PIXELFORMAT_RGB565" -> RGB565
    | "PIXELFORMAT_BGR565" -> BGR565
    | "PIXELFORMAT_RGB24" -> RGB24
    | "PIXELFORMAT_BGR24" -> BGR24
    | "PIXELFORMAT_RGB888" -> RGB888
    | "PIXELFORMAT_RGBX8888" -> RGBX8888
    | "PIXELFORMAT_BGR888" -> BGR888
    | "PIXELFORMAT_BGRX8888" -> BGRX8888
    | "PIXELFORMAT_ARGB8888" -> ARGB8888
    | "PIXELFORMAT_RGBA8888" -> RGBA8888
    | "PIXELFORMAT_ABGR8888" -> ABGR8888
    | "PIXELFORMAT_BGRA8888" -> BGRA8888
    | "PIXELFORMAT_ARGB2101010" -> ARGB2101010
    | "PIXELFORMAT_YV12" -> YV12
    | "PIXELFORMAT_IYUV" -> IYUV
    | "PIXELFORMAT_YUY2" -> YUY2
    | "PIXELFORMAT_UYVY" -> UYVY
    | "PIXELFORMAT_YVYU" -> YVYU
    | "UNKNOWN" -> Unknown
    | "INDEX1LSB" -> Index1LSB
    | "INDEX1MSB" -> Index1MSB
    | "INDEX4LSB" -> Index4LSB
    | "INDEX4MSB" -> Index4MSB
    | "INDEX8" -> Index8
    | "RGB332" -> RGB332
    | "RGB444" -> RGB444
    | "RGB555" -> RGB555
    | "BGR555" -> BGR555
    | "ARGB4444" -> ARGB4444
    | "RGBA4444" -> RGBA4444
    | "ABGR4444" -> ABGR4444
    | "BGRA4444" -> BGRA4444
    | "ARGB1555" -> ARGB1555
    | "RGBA5551" -> RGBA5551
    | "ABGR1555" -> ABGR1555
    | "BGRA5551" -> BGRA5551
    | "RGB565" -> RGB565
    | "BGR565" -> BGR565
    | "RGB24" -> RGB24
    | "BGR24" -> BGR24
    | "RGB888" -> RGB888
    | "RGBX8888" -> RGBX8888
    | "BGR888" -> BGR888
    | "BGRX8888" -> BGRX8888
    | "ARGB8888" -> ARGB8888
    | "RGBA8888" -> RGBA8888
    | "ABGR8888" -> ABGR8888
    | "BGRA8888" -> BGRA8888
    | "ARGB2101010" -> ARGB2101010
    | "YV12" -> YV12
    | "IYUV" -> IYUV
    | "YUY2" -> YUY2
    | "UYVY" -> UYVY
    | "YVYU" -> YVYU
    | _ -> invalid_arg "SdlpixelFormat.of_string"
  ;;

  type allocated
end

external get_pixel_format_name : PixelFormat.t -> string = "caml_SDL_GetPixelFormatName"
external alloc_format : PixelFormat.t -> PixelFormat.allocated = "caml_SDL_AllocFormat"
external free_format : PixelFormat.allocated -> unit = "caml_SDL_FreeFormat"

type rgb = uint8 * uint8 * uint8
type rgba = uint8 * uint8 * uint8 * uint8

external map_RGB : PixelFormat.allocated -> rgb:rgb -> int32 = "caml_SDL_MapRGB"
external map_RGBA : PixelFormat.allocated -> rgba:rgba -> int32 = "caml_SDL_MapRGBA"
external get_RGB : pixel:int32 -> fmt:PixelFormat.allocated -> rgb = "caml_SDL_GetRGB"
external get_RGBA : pixel:int32 -> fmt:PixelFormat.allocated -> rgba = "caml_SDL_GetRGBA"

module BlendMode = struct
  type t =
    | NONE
    | BLEND
    | ADD
    | MOD
    | MUL

  let to_string = function
    | NONE -> "SDL_BLENDMODE_NONE"
    | BLEND -> "SDL_BLENDMODE_BLEND"
    | ADD -> "SDL_BLENDMODE_ADD"
    | MOD -> "SDL_BLENDMODE_MOD"
    | MUL -> "SDL_BLENDMODE_MUL"
  ;;

  let of_string = function
    | "SDL_BLENDMODE_NONE" -> NONE
    | "SDL_BLENDMODE_BLEND" -> BLEND
    | "SDL_BLENDMODE_ADD" -> ADD
    | "SDL_BLENDMODE_MOD" -> MOD
    | "SDL_BLENDMODE_MUL" -> MUL
    | invalid -> invalid_arg (Printf.sprintf "BlendMode.t %s" invalid)
  ;;
end

external set_clipboard_text : text:string -> int = "caml_SDL_SetClipboardText"
external get_clipboard_text : unit -> string = "caml_SDL_GetClipboardText"
external has_clipboard_text : unit -> bool = "caml_SDL_HasClipboardText"
external get_CPU_count : unit -> int = "caml_SDL_GetCPUCount"
external get_error : unit -> string = "caml_SDL_GetError"
external set_error : string -> unit = "caml_SDL_SetError"
external clear_error : unit -> unit = "caml_SDL_ClearError"
external get_base_path : unit -> string = "caml_SDL_GetBasePath"
external get_pref_path : org:string -> app:string -> string = "caml_SDL_GetPrefPath"

module HintPriority = struct
  type t =
    | Default
    | Normal
    | Override

  let to_string = function
    | Default -> "SDL_HINT_DEFAULT"
    | Normal -> "SDL_HINT_NORMAL"
    | Override -> "SDL_HINT_OVERRIDE"
  ;;

  let of_string s =
    match String.uppercase_ascii s with
    | "SDL_HINT_DEFAULT" -> Default
    | "SDL_HINT_NORMAL" -> Normal
    | "SDL_HINT_OVERRIDE" -> Override
    | _ -> invalid_arg "Sdlhintpriority.of_string"
  ;;
end

external get_hint : string -> string option = "caml_SDL_GetHint"
external set_hint : string -> string -> unit = "caml_SDL_SetHint"

external set_hint_with_priority
  :  string
  -> string
  -> HintPriority.t
  -> unit
  = "caml_SDL_SetHintWithPriority"

module HapticPosition = struct
  type t =
    { left : bool
    ; right : bool
    ; up : bool
    ; down : bool
    }

  let string_of_pos p =
    let lst = [] in
    let lst = if p.down then "Down" :: lst else lst in
    let lst = if p.up then "Up" :: lst else lst in
    let lst = if p.right then "Right" :: lst else lst in
    let lst = if p.left then "Left" :: lst else lst in
    String.concat " " lst
  ;;
end

module HapticDirection = struct
  type t =
    | Centered
    | Up
    | Right
    | Down
    | Left
    | Right_Up
    | Right_Down
    | Left_Up
    | Left_Down

  let string_of_dir = function
    | Centered -> "Centered"
    | Up -> "Up"
    | Right -> "Right"
    | Down -> "Down"
    | Left -> "Left"
    | Right_Up -> "Right_Up"
    | Right_Down -> "Right_Down"
    | Left_Up -> "Left_Up"
    | Left_Down -> "Left_Down"
  ;;

  let dir_of_string s =
    match String.lowercase_ascii s with
    | "centered" -> Centered
    | "up" -> Up
    | "right" -> Right
    | "down" -> Down
    | "left" -> Left
    | "right_up" -> Right_Up
    | "right_down" -> Right_Down
    | "left_up" -> Left_Up
    | "left_down" -> Left_Down
    | _ -> invalid_arg "of_string"
  ;;
end

module Joystick = struct
  type t
end

external num_joysticks : unit -> int = "caml_SDL_NumJoysticks"

external joystick_name_for_index
  :  device_index:int
  -> string
  = "caml_SDL_JoystickNameForIndex"

external joystick_open : device_index:int -> Joystick.t = "caml_SDL_JoystickOpen"
external joystick_close : Joystick.t -> unit = "caml_SDL_JoystickClose"
external joystick_num_axes : Joystick.t -> int = "caml_SDL_JoystickNumAxes"
external joystick_num_hats : Joystick.t -> int = "caml_SDL_JoystickNumHats"
external joystick_get_axis : Joystick.t -> axis:int -> int = "caml_SDL_JoystickGetAxis"

external joystick_get_button
  :  Joystick.t
  -> button:int
  -> int
  = "caml_SDL_JoystickGetButton"

external start_text_input : unit -> unit = "caml_SDL_StartTextInput"
external stop_text_input : unit -> unit = "caml_SDL_StopTextInput"
external is_text_input_active : unit -> bool = "caml_SDL_IsTextInputActive"
external set_text_input_rect : Rect.t -> unit = "caml_SDL_SetTextInputRect"
external has_screen_keyboard_support : unit -> bool = "caml_SDL_HasScreenKeyboardSupport"

module Keycode = struct
  type t =
    | Unknown
    | Return
    | Escape
    | Backspace
    | Tab
    | Space
    | Exclaim
    | QuoteDBL
    | Hash
    | Percent
    | Dollar
    | Ampersand
    | Quote
    | LeftParen
    | RightParen
    | Asterisk
    | Plus
    | Comma
    | Minus
    | Period
    | Slash
    | Num0
    | Num1
    | Num2
    | Num3
    | Num4
    | Num5
    | Num6
    | Num7
    | Num8
    | Num9
    | Colon
    | SemiColon
    | Less
    | Equals
    | Greater
    | Question
    | At
    | LeftBracket
    | BackSlash
    | RightBracket
    | Caret
    | Underscore
    | BackQuote
    | A
    | B
    | C
    | D
    | E
    | F
    | G
    | H
    | I
    | J
    | K
    | L
    | M
    | N
    | O
    | P
    | Q
    | R
    | S
    | T
    | U
    | V
    | W
    | X
    | Y
    | Z
    | CapsLock
    | F1
    | F2
    | F3
    | F4
    | F5
    | F6
    | F7
    | F8
    | F9
    | F10
    | F11
    | F12
    | PrintScreen
    | ScrollLock
    | Pause
    | Insert
    | Home
    | PageUp
    | Delete
    | End
    | PageDown
    | Right
    | Left
    | Down
    | Up
    | NumLockClear
    | KP_Divide
    | KP_Multiply
    | KP_Minus
    | KP_Plus
    | KP_Enter
    | KP_1
    | KP_2
    | KP_3
    | KP_4
    | KP_5
    | KP_6
    | KP_7
    | KP_8
    | KP_9
    | KP_0
    | KP_Period
    | Application
    | Power
    | KP_Equals
    | F13
    | F14
    | F15
    | F16
    | F17
    | F18
    | F19
    | F20
    | F21
    | F22
    | F23
    | F24
    | Execute
    | Help
    | Menu
    | Select
    | Stop
    | Again
    | Undo
    | Cut
    | Copy
    | Paste
    | Find
    | Mute
    | VolumeUp
    | VolumeDown
    | KP_Comma
    | KP_EqualsAs400
    | ALTERASE
    | SYSREQ
    | CANCEL
    | CLEAR
    | PRIOR
    | RETURN2
    | SEPARATOR
    | OUT
    | OPER
    | CLEARAGAIN
    | CRSEL
    | EXSEL
    | KP_00
    | KP_000
    | ThousandsSeparator
    | DecimalSeparator
    | CurrencyUnit
    | CurrencySubunit
    | KP_LeftParen
    | KP_RightParen
    | KP_LeftBrace
    | KP_RightBrace
    | KP_Tab
    | KP_Backspace
    | KP_A
    | KP_B
    | KP_C
    | KP_D
    | KP_E
    | KP_F
    | KP_Xor
    | KP_Power
    | KP_Percent
    | KP_Less
    | KP_Greater
    | KP_Ampersand
    | KP_DBLAmpersand
    | KP_VerticalBar
    | KP_DBLVerticalBar
    | KP_Colon
    | KP_Hash
    | KP_Space
    | KP_At
    | KP_Exclam
    | KP_MemStore
    | KP_MemRecall
    | KP_MemClear
    | KP_MemAdd
    | KP_MemSubtract
    | KP_MemMultiply
    | KP_MemDivide
    | KP_PlusMinus
    | KP_Clear
    | KP_Clearentry
    | KP_Binary
    | KP_Octal
    | KP_Decimal
    | KP_Hexadecimal
    | LCtrl
    | LShift
    | LAlt
    | LGui
    | RCtrl
    | RShift
    | RAlt
    | RGUI
    | MODE
    | AudioNext
    | AudioPrev
    | AudioStop
    | AudioPlay
    | AudioMute
    | MediaSelect
    | WWW
    | Mail
    | Calculator
    | Computer
    | AC_Search
    | AC_Home
    | AC_Back
    | AC_Forward
    | AC_Stop
    | AC_Refresh
    | AC_Bookmarks
    | BrightnessDown
    | BrightnessUp
    | DisplaySwitch
    | KBDIllumToggle
    | KBDIllumDown
    | KBDIllumUp
    | Eject
    | Sleep

  let to_string = function
    | Unknown -> "Unknown"
    | Return -> "Return"
    | Escape -> "Escape"
    | Backspace -> "Backspace"
    | Tab -> "Tab"
    | Space -> "Space"
    | Exclaim -> "Exclaim"
    | QuoteDBL -> "QuoteDBL"
    | Hash -> "Hash"
    | Percent -> "Percent"
    | Dollar -> "Dollar"
    | Ampersand -> "Ampersand"
    | Quote -> "Quote"
    | LeftParen -> "LeftParen"
    | RightParen -> "RightParen"
    | Asterisk -> "Asterisk"
    | Plus -> "Plus"
    | Comma -> "Comma"
    | Minus -> "Minus"
    | Period -> "Period"
    | Slash -> "Slash"
    | Num0 -> "Num0"
    | Num1 -> "Num1"
    | Num2 -> "Num2"
    | Num3 -> "Num3"
    | Num4 -> "Num4"
    | Num5 -> "Num5"
    | Num6 -> "Num6"
    | Num7 -> "Num7"
    | Num8 -> "Num8"
    | Num9 -> "Num9"
    | Colon -> "Colon"
    | SemiColon -> "SemiColon"
    | Less -> "Less"
    | Equals -> "Equals"
    | Greater -> "Greater"
    | Question -> "Question"
    | At -> "At"
    | LeftBracket -> "LeftBracket"
    | BackSlash -> "BackSlash"
    | RightBracket -> "RightBracket"
    | Caret -> "Caret"
    | Underscore -> "Underscore"
    | BackQuote -> "BackQuote"
    | A -> "A"
    | B -> "B"
    | C -> "C"
    | D -> "D"
    | E -> "E"
    | F -> "F"
    | G -> "G"
    | H -> "H"
    | I -> "I"
    | J -> "J"
    | K -> "K"
    | L -> "L"
    | M -> "M"
    | N -> "N"
    | O -> "O"
    | P -> "P"
    | Q -> "Q"
    | R -> "R"
    | S -> "S"
    | T -> "T"
    | U -> "U"
    | V -> "V"
    | W -> "W"
    | X -> "X"
    | Y -> "Y"
    | Z -> "Z"
    | CapsLock -> "CapsLock"
    | F1 -> "F1"
    | F2 -> "F2"
    | F3 -> "F3"
    | F4 -> "F4"
    | F5 -> "F5"
    | F6 -> "F6"
    | F7 -> "F7"
    | F8 -> "F8"
    | F9 -> "F9"
    | F10 -> "F10"
    | F11 -> "F11"
    | F12 -> "F12"
    | PrintScreen -> "PrintScreen"
    | ScrollLock -> "ScrollLock"
    | Pause -> "Pause"
    | Insert -> "Insert"
    | Home -> "Home"
    | PageUp -> "PageUp"
    | Delete -> "Delete"
    | End -> "End"
    | PageDown -> "PageDown"
    | Right -> "Right"
    | Left -> "Left"
    | Down -> "Down"
    | Up -> "Up"
    | NumLockClear -> "NumLockClear"
    | KP_Divide -> "KP_Divide"
    | KP_Multiply -> "KP_Multiply"
    | KP_Minus -> "KP_Minus"
    | KP_Plus -> "KP_Plus"
    | KP_Enter -> "KP_Enter"
    | KP_1 -> "KP_1"
    | KP_2 -> "KP_2"
    | KP_3 -> "KP_3"
    | KP_4 -> "KP_4"
    | KP_5 -> "KP_5"
    | KP_6 -> "KP_6"
    | KP_7 -> "KP_7"
    | KP_8 -> "KP_8"
    | KP_9 -> "KP_9"
    | KP_0 -> "KP_0"
    | KP_Period -> "KP_Period"
    | Application -> "Application"
    | Power -> "Power"
    | KP_Equals -> "KP_Equals"
    | F13 -> "F13"
    | F14 -> "F14"
    | F15 -> "F15"
    | F16 -> "F16"
    | F17 -> "F17"
    | F18 -> "F18"
    | F19 -> "F19"
    | F20 -> "F20"
    | F21 -> "F21"
    | F22 -> "F22"
    | F23 -> "F23"
    | F24 -> "F24"
    | Execute -> "Execute"
    | Help -> "Help"
    | Menu -> "Menu"
    | Select -> "Select"
    | Stop -> "Stop"
    | Again -> "Again"
    | Undo -> "Undo"
    | Cut -> "Cut"
    | Copy -> "Copy"
    | Paste -> "Paste"
    | Find -> "Find"
    | Mute -> "Mute"
    | VolumeUp -> "VolumeUp"
    | VolumeDown -> "VolumeDown"
    | KP_Comma -> "KP_Comma"
    | KP_EqualsAs400 -> "KP_EqualsAs400"
    | ALTERASE -> "ALTERASE"
    | SYSREQ -> "SYSREQ"
    | CANCEL -> "CANCEL"
    | CLEAR -> "CLEAR"
    | PRIOR -> "PRIOR"
    | RETURN2 -> "RETURN2"
    | SEPARATOR -> "SEPARATOR"
    | OUT -> "OUT"
    | OPER -> "OPER"
    | CLEARAGAIN -> "CLEARAGAIN"
    | CRSEL -> "CRSEL"
    | EXSEL -> "EXSEL"
    | KP_00 -> "KP_00"
    | KP_000 -> "KP_000"
    | ThousandsSeparator -> "ThousandsSeparator"
    | DecimalSeparator -> "DecimalSeparator"
    | CurrencyUnit -> "CurrencyUnit"
    | CurrencySubunit -> "CurrencySubunit"
    | KP_LeftParen -> "KP_LeftParen"
    | KP_RightParen -> "KP_RightParen"
    | KP_LeftBrace -> "KP_LeftBrace"
    | KP_RightBrace -> "KP_RightBrace"
    | KP_Tab -> "KP_Tab"
    | KP_Backspace -> "KP_Backspace"
    | KP_A -> "KP_A"
    | KP_B -> "KP_B"
    | KP_C -> "KP_C"
    | KP_D -> "KP_D"
    | KP_E -> "KP_E"
    | KP_F -> "KP_F"
    | KP_Xor -> "KP_Xor"
    | KP_Power -> "KP_Power"
    | KP_Percent -> "KP_Percent"
    | KP_Less -> "KP_Less"
    | KP_Greater -> "KP_Greater"
    | KP_Ampersand -> "KP_Ampersand"
    | KP_DBLAmpersand -> "KP_DBLAmpersand"
    | KP_VerticalBar -> "KP_VerticalBar"
    | KP_DBLVerticalBar -> "KP_DBLVerticalBar"
    | KP_Colon -> "KP_Colon"
    | KP_Hash -> "KP_Hash"
    | KP_Space -> "KP_Space"
    | KP_At -> "KP_At"
    | KP_Exclam -> "KP_Exclam"
    | KP_MemStore -> "KP_MemStore"
    | KP_MemRecall -> "KP_MemRecall"
    | KP_MemClear -> "KP_MemClear"
    | KP_MemAdd -> "KP_MemAdd"
    | KP_MemSubtract -> "KP_MemSubtract"
    | KP_MemMultiply -> "KP_MemMultiply"
    | KP_MemDivide -> "KP_MemDivide"
    | KP_PlusMinus -> "KP_PlusMinus"
    | KP_Clear -> "KP_Clear"
    | KP_Clearentry -> "KP_Clearentry"
    | KP_Binary -> "KP_Binary"
    | KP_Octal -> "KP_Octal"
    | KP_Decimal -> "KP_Decimal"
    | KP_Hexadecimal -> "KP_Hexadecimal"
    | LCtrl -> "LCtrl"
    | LShift -> "LShift"
    | LAlt -> "LAlt"
    | LGui -> "LGui"
    | RCtrl -> "RCtrl"
    | RShift -> "RShift"
    | RAlt -> "RAlt"
    | RGUI -> "RGUI"
    | MODE -> "MODE"
    | AudioNext -> "AudioNext"
    | AudioPrev -> "AudioPrev"
    | AudioStop -> "AudioStop"
    | AudioPlay -> "AudioPlay"
    | AudioMute -> "AudioMute"
    | MediaSelect -> "MediaSelect"
    | WWW -> "WWW"
    | Mail -> "Mail"
    | Calculator -> "Calculator"
    | Computer -> "Computer"
    | AC_Search -> "AC_Search"
    | AC_Home -> "AC_Home"
    | AC_Back -> "AC_Back"
    | AC_Forward -> "AC_Forward"
    | AC_Stop -> "AC_Stop"
    | AC_Refresh -> "AC_Refresh"
    | AC_Bookmarks -> "AC_Bookmarks"
    | BrightnessDown -> "BrightnessDown"
    | BrightnessUp -> "BrightnessUp"
    | DisplaySwitch -> "DisplaySwitch"
    | KBDIllumToggle -> "KBDIllumToggle"
    | KBDIllumDown -> "KBDIllumDown"
    | KBDIllumUp -> "KBDIllumUp"
    | Eject -> "Eject"
    | Sleep -> "Sleep"
  ;;

  let of_string s =
    match String.lowercase_ascii s with
    | "unknown" -> Unknown
    | "return" -> Return
    | "escape" -> Escape
    | "backspace" -> Backspace
    | "tab" -> Tab
    | "space" -> Space
    | "exclaim" -> Exclaim
    | "quotedbl" -> QuoteDBL
    | "hash" -> Hash
    | "percent" -> Percent
    | "dollar" -> Dollar
    | "ampersand" -> Ampersand
    | "quote" -> Quote
    | "leftparen" -> LeftParen
    | "rightparen" -> RightParen
    | "asterisk" -> Asterisk
    | "plus" -> Plus
    | "comma" -> Comma
    | "minus" -> Minus
    | "period" -> Period
    | "slash" -> Slash
    | "num0" -> Num0
    | "num1" -> Num1
    | "num2" -> Num2
    | "num3" -> Num3
    | "num4" -> Num4
    | "num5" -> Num5
    | "num6" -> Num6
    | "num7" -> Num7
    | "num8" -> Num8
    | "num9" -> Num9
    | "colon" -> Colon
    | "semicolon" -> SemiColon
    | "less" -> Less
    | "equals" -> Equals
    | "greater" -> Greater
    | "question" -> Question
    | "at" -> At
    | "leftbracket" -> LeftBracket
    | "backslash" -> BackSlash
    | "rightbracket" -> RightBracket
    | "caret" -> Caret
    | "underscore" -> Underscore
    | "backquote" -> BackQuote
    | "a" -> A
    | "b" -> B
    | "c" -> C
    | "d" -> D
    | "e" -> E
    | "f" -> F
    | "g" -> G
    | "h" -> H
    | "i" -> I
    | "j" -> J
    | "k" -> K
    | "l" -> L
    | "m" -> M
    | "n" -> N
    | "o" -> O
    | "p" -> P
    | "q" -> Q
    | "r" -> R
    | "s" -> S
    | "t" -> T
    | "u" -> U
    | "v" -> V
    | "w" -> W
    | "x" -> X
    | "y" -> Y
    | "z" -> Z
    | "capslock" -> CapsLock
    | "f1" -> F1
    | "f2" -> F2
    | "f3" -> F3
    | "f4" -> F4
    | "f5" -> F5
    | "f6" -> F6
    | "f7" -> F7
    | "f8" -> F8
    | "f9" -> F9
    | "f10" -> F10
    | "f11" -> F11
    | "f12" -> F12
    | "printscreen" -> PrintScreen
    | "scrolllock" -> ScrollLock
    | "pause" -> Pause
    | "insert" -> Insert
    | "home" -> Home
    | "pageup" -> PageUp
    | "delete" -> Delete
    | "end" -> End
    | "pagedown" -> PageDown
    | "right" -> Right
    | "left" -> Left
    | "down" -> Down
    | "up" -> Up
    | "numlockclear" -> NumLockClear
    | "kp_divide" -> KP_Divide
    | "kp_multiply" -> KP_Multiply
    | "kp_minus" -> KP_Minus
    | "kp_plus" -> KP_Plus
    | "kp_enter" -> KP_Enter
    | "kp_1" -> KP_1
    | "kp_2" -> KP_2
    | "kp_3" -> KP_3
    | "kp_4" -> KP_4
    | "kp_5" -> KP_5
    | "kp_6" -> KP_6
    | "kp_7" -> KP_7
    | "kp_8" -> KP_8
    | "kp_9" -> KP_9
    | "kp_0" -> KP_0
    | "kp_period" -> KP_Period
    | "application" -> Application
    | "power" -> Power
    | "kp_equals" -> KP_Equals
    | "f13" -> F13
    | "f14" -> F14
    | "f15" -> F15
    | "f16" -> F16
    | "f17" -> F17
    | "f18" -> F18
    | "f19" -> F19
    | "f20" -> F20
    | "f21" -> F21
    | "f22" -> F22
    | "f23" -> F23
    | "f24" -> F24
    | "execute" -> Execute
    | "help" -> Help
    | "menu" -> Menu
    | "select" -> Select
    | "stop" -> Stop
    | "again" -> Again
    | "undo" -> Undo
    | "cut" -> Cut
    | "copy" -> Copy
    | "paste" -> Paste
    | "find" -> Find
    | "mute" -> Mute
    | "volumeup" -> VolumeUp
    | "volumedown" -> VolumeDown
    | "kp_comma" -> KP_Comma
    | "kp_equalsas400" -> KP_EqualsAs400
    | "alterase" -> ALTERASE
    | "sysreq" -> SYSREQ
    | "cancel" -> CANCEL
    | "clear" -> CLEAR
    | "prior" -> PRIOR
    | "return2" -> RETURN2
    | "separator" -> SEPARATOR
    | "out" -> OUT
    | "oper" -> OPER
    | "clearagain" -> CLEARAGAIN
    | "crsel" -> CRSEL
    | "exsel" -> EXSEL
    | "kp_00" -> KP_00
    | "kp_000" -> KP_000
    | "thousandsseparator" -> ThousandsSeparator
    | "decimalseparator" -> DecimalSeparator
    | "currencyunit" -> CurrencyUnit
    | "currencysubunit" -> CurrencySubunit
    | "kp_leftparen" -> KP_LeftParen
    | "kp_rightparen" -> KP_RightParen
    | "kp_leftbrace" -> KP_LeftBrace
    | "kp_rightbrace" -> KP_RightBrace
    | "kp_tab" -> KP_Tab
    | "kp_backspace" -> KP_Backspace
    | "kp_a" -> KP_A
    | "kp_b" -> KP_B
    | "kp_c" -> KP_C
    | "kp_d" -> KP_D
    | "kp_e" -> KP_E
    | "kp_f" -> KP_F
    | "kp_xor" -> KP_Xor
    | "kp_power" -> KP_Power
    | "kp_percent" -> KP_Percent
    | "kp_less" -> KP_Less
    | "kp_greater" -> KP_Greater
    | "kp_ampersand" -> KP_Ampersand
    | "kp_dblampersand" -> KP_DBLAmpersand
    | "kp_verticalbar" -> KP_VerticalBar
    | "kp_dblverticalbar" -> KP_DBLVerticalBar
    | "kp_colon" -> KP_Colon
    | "kp_hash" -> KP_Hash
    | "kp_space" -> KP_Space
    | "kp_at" -> KP_At
    | "kp_exclam" -> KP_Exclam
    | "kp_memstore" -> KP_MemStore
    | "kp_memrecall" -> KP_MemRecall
    | "kp_memclear" -> KP_MemClear
    | "kp_memadd" -> KP_MemAdd
    | "kp_memsubtract" -> KP_MemSubtract
    | "kp_memmultiply" -> KP_MemMultiply
    | "kp_memdivide" -> KP_MemDivide
    | "kp_plusminus" -> KP_PlusMinus
    | "kp_clear" -> KP_Clear
    | "kp_clearentry" -> KP_Clearentry
    | "kp_binary" -> KP_Binary
    | "kp_octal" -> KP_Octal
    | "kp_decimal" -> KP_Decimal
    | "kp_hexadecimal" -> KP_Hexadecimal
    | "lctrl" -> LCtrl
    | "lshift" -> LShift
    | "lalt" -> LAlt
    | "lgui" -> LGui
    | "rctrl" -> RCtrl
    | "rshift" -> RShift
    | "ralt" -> RAlt
    | "rgui" -> RGUI
    | "mode" -> MODE
    | "audionext" -> AudioNext
    | "audioprev" -> AudioPrev
    | "audiostop" -> AudioStop
    | "audioplay" -> AudioPlay
    | "audiomute" -> AudioMute
    | "mediaselect" -> MediaSelect
    | "www" -> WWW
    | "mail" -> Mail
    | "calculator" -> Calculator
    | "computer" -> Computer
    | "ac_search" -> AC_Search
    | "ac_home" -> AC_Home
    | "ac_back" -> AC_Back
    | "ac_forward" -> AC_Forward
    | "ac_stop" -> AC_Stop
    | "ac_refresh" -> AC_Refresh
    | "ac_bookmarks" -> AC_Bookmarks
    | "brightnessdown" -> BrightnessDown
    | "brightnessup" -> BrightnessUp
    | "displayswitch" -> DisplaySwitch
    | "kbdillumtoggle" -> KBDIllumToggle
    | "kbdillumdown" -> KBDIllumDown
    | "kbdillumup" -> KBDIllumUp
    | "eject" -> Eject
    | "sleep" -> Sleep
    | _ -> invalid_arg "Sdlkeycode.of_string"
  ;;
end

module Keymod = struct
  type t =
    | LShift
    | RShift
    | LCtrl
    | RCtrl
    | LAlt
    | RAlt
    | LGUI
    | RGUI
    | NUM
    | CAPS
    | MODE

  let to_string = function
    | LShift -> "LShift"
    | RShift -> "RShift"
    | LCtrl -> "LCtrl"
    | RCtrl -> "RCtrl"
    | LAlt -> "LAlt"
    | RAlt -> "RAlt"
    | LGUI -> "LGUI"
    | RGUI -> "RGUI"
    | NUM -> "NUM"
    | CAPS -> "CAPS"
    | MODE -> "MODE"
  ;;

  let of_string s =
    match String.lowercase_ascii s with
    | "lshift" -> LShift
    | "rshift" -> RShift
    | "lctrl" -> LCtrl
    | "rctrl" -> RCtrl
    | "lalt" -> LAlt
    | "ralt" -> RAlt
    | "lgui" -> LGUI
    | "rgui" -> RGUI
    | "num" -> NUM
    | "caps" -> CAPS
    | "mode" -> MODE
    | _ -> invalid_arg "Sdlkeymod.of_string"
  ;;
end

module Scancode = struct
  type t =
    | UNKNOWN
    | A
    | B
    | C
    | D
    | E
    | F
    | G
    | H
    | I
    | J
    | K
    | L
    | M
    | N
    | O
    | P
    | Q
    | R
    | S
    | T
    | U
    | V
    | W
    | X
    | Y
    | Z
    | Num1
    | Num2
    | Num3
    | Num4
    | Num5
    | Num6
    | Num7
    | Num8
    | Num9
    | Num0
    | RETURN
    | ESCAPE
    | BACKSPACE
    | TAB
    | SPACE
    | MINUS
    | EQUALS
    | LEFTBRACKET
    | RIGHTBRACKET
    | BACKSLASH
    | NONUSHASH
    | SEMICOLON
    | APOSTROPHE
    | GRAVE
    | COMMA
    | PERIOD
    | SLASH
    | CAPSLOCK
    | F1
    | F2
    | F3
    | F4
    | F5
    | F6
    | F7
    | F8
    | F9
    | F10
    | F11
    | F12
    | PRINTSCREEN
    | SCROLLLOCK
    | PAUSE
    | INSERT
    | HOME
    | PAGEUP
    | DELETE
    | END
    | PAGEDOWN
    | RIGHT
    | LEFT
    | DOWN
    | UP
    | NUMLOCKCLEAR
    | KP_DIVIDE
    | KP_MULTIPLY
    | KP_MINUS
    | KP_PLUS
    | KP_ENTER
    | KP_1
    | KP_2
    | KP_3
    | KP_4
    | KP_5
    | KP_6
    | KP_7
    | KP_8
    | KP_9
    | KP_0
    | KP_PERIOD
    | NONUSBACKSLASH
    | APPLICATION
    | POWER
    | KP_EQUALS
    | F13
    | F14
    | F15
    | F16
    | F17
    | F18
    | F19
    | F20
    | F21
    | F22
    | F23
    | F24
    | EXECUTE
    | HELP
    | MENU
    | SELECT
    | STOP
    | AGAIN
    | UNDO
    | CUT
    | COPY
    | PASTE
    | FIND
    | MUTE
    | VOLUMEUP
    | VOLUMEDOWN
    | KP_COMMA
    | KP_EQUALSAS400
    | INTERNATIONAL1
    | INTERNATIONAL2
    | INTERNATIONAL3
    | INTERNATIONAL4
    | INTERNATIONAL5
    | INTERNATIONAL6
    | INTERNATIONAL7
    | INTERNATIONAL8
    | INTERNATIONAL9
    | LANG1
    | LANG2
    | LANG3
    | LANG4
    | LANG5
    | LANG6
    | LANG7
    | LANG8
    | LANG9
    | ALTERASE
    | SYSREQ
    | CANCEL
    | CLEAR
    | PRIOR
    | RETURN2
    | SEPARATOR
    | OUT
    | OPER
    | CLEARAGAIN
    | CRSEL
    | EXSEL
    | KP_00
    | KP_000
    | THOUSANDSSEPARATOR
    | DECIMALSEPARATOR
    | CURRENCYUNIT
    | CURRENCYSUBUNIT
    | KP_LEFTPAREN
    | KP_RIGHTPAREN
    | KP_LEFTBRACE
    | KP_RIGHTBRACE
    | KP_TAB
    | KP_BACKSPACE
    | KP_A
    | KP_B
    | KP_C
    | KP_D
    | KP_E
    | KP_F
    | KP_XOR
    | KP_POWER
    | KP_PERCENT
    | KP_LESS
    | KP_GREATER
    | KP_AMPERSAND
    | KP_DBLAMPERSAND
    | KP_VERTICALBAR
    | KP_DBLVERTICALBAR
    | KP_COLON
    | KP_HASH
    | KP_SPACE
    | KP_AT
    | KP_EXCLAM
    | KP_MEMSTORE
    | KP_MEMRECALL
    | KP_MEMCLEAR
    | KP_MEMADD
    | KP_MEMSUBTRACT
    | KP_MEMMULTIPLY
    | KP_MEMDIVIDE
    | KP_PLUSMINUS
    | KP_CLEAR
    | KP_CLEARENTRY
    | KP_BINARY
    | KP_OCTAL
    | KP_DECIMAL
    | KP_HEXADECIMAL
    | LCTRL
    | LSHIFT
    | LALT
    | LGUI
    | RCTRL
    | RSHIFT
    | RALT
    | RGUI
    | MODE
    | AUDIONEXT
    | AUDIOPREV
    | AUDIOSTOP
    | AUDIOPLAY
    | AUDIOMUTE
    | MEDIASELECT
    | WWW
    | MAIL
    | CALCULATOR
    | COMPUTER
    | AC_SEARCH
    | AC_HOME
    | AC_BACK
    | AC_FORWARD
    | AC_STOP
    | AC_REFRESH
    | AC_BOOKMARKS
    | BRIGHTNESSDOWN
    | BRIGHTNESSUP
    | DISPLAYSWITCH
    | KBDILLUMTOGGLE
    | KBDILLUMDOWN
    | KBDILLUMUP
    | EJECT
    | SLEEP

  let to_string = function
    | UNKNOWN -> "UNKNOWN"
    | A -> "A"
    | B -> "B"
    | C -> "C"
    | D -> "D"
    | E -> "E"
    | F -> "F"
    | G -> "G"
    | H -> "H"
    | I -> "I"
    | J -> "J"
    | K -> "K"
    | L -> "L"
    | M -> "M"
    | N -> "N"
    | O -> "O"
    | P -> "P"
    | Q -> "Q"
    | R -> "R"
    | S -> "S"
    | T -> "T"
    | U -> "U"
    | V -> "V"
    | W -> "W"
    | X -> "X"
    | Y -> "Y"
    | Z -> "Z"
    | Num1 -> "Num1"
    | Num2 -> "Num2"
    | Num3 -> "Num3"
    | Num4 -> "Num4"
    | Num5 -> "Num5"
    | Num6 -> "Num6"
    | Num7 -> "Num7"
    | Num8 -> "Num8"
    | Num9 -> "Num9"
    | Num0 -> "Num0"
    | RETURN -> "RETURN"
    | ESCAPE -> "ESCAPE"
    | BACKSPACE -> "BACKSPACE"
    | TAB -> "TAB"
    | SPACE -> "SPACE"
    | MINUS -> "MINUS"
    | EQUALS -> "EQUALS"
    | LEFTBRACKET -> "LEFTBRACKET"
    | RIGHTBRACKET -> "RIGHTBRACKET"
    | BACKSLASH -> "BACKSLASH"
    | NONUSHASH -> "NONUSHASH"
    | SEMICOLON -> "SEMICOLON"
    | APOSTROPHE -> "APOSTROPHE"
    | GRAVE -> "GRAVE"
    | COMMA -> "COMMA"
    | PERIOD -> "PERIOD"
    | SLASH -> "SLASH"
    | CAPSLOCK -> "CAPSLOCK"
    | F1 -> "F1"
    | F2 -> "F2"
    | F3 -> "F3"
    | F4 -> "F4"
    | F5 -> "F5"
    | F6 -> "F6"
    | F7 -> "F7"
    | F8 -> "F8"
    | F9 -> "F9"
    | F10 -> "F10"
    | F11 -> "F11"
    | F12 -> "F12"
    | PRINTSCREEN -> "PRINTSCREEN"
    | SCROLLLOCK -> "SCROLLLOCK"
    | PAUSE -> "PAUSE"
    | INSERT -> "INSERT"
    | HOME -> "HOME"
    | PAGEUP -> "PAGEUP"
    | DELETE -> "DELETE"
    | END -> "END"
    | PAGEDOWN -> "PAGEDOWN"
    | RIGHT -> "RIGHT"
    | LEFT -> "LEFT"
    | DOWN -> "DOWN"
    | UP -> "UP"
    | NUMLOCKCLEAR -> "NUMLOCKCLEAR"
    | KP_DIVIDE -> "KP_DIVIDE"
    | KP_MULTIPLY -> "KP_MULTIPLY"
    | KP_MINUS -> "KP_MINUS"
    | KP_PLUS -> "KP_PLUS"
    | KP_ENTER -> "KP_ENTER"
    | KP_1 -> "KP_1"
    | KP_2 -> "KP_2"
    | KP_3 -> "KP_3"
    | KP_4 -> "KP_4"
    | KP_5 -> "KP_5"
    | KP_6 -> "KP_6"
    | KP_7 -> "KP_7"
    | KP_8 -> "KP_8"
    | KP_9 -> "KP_9"
    | KP_0 -> "KP_0"
    | KP_PERIOD -> "KP_PERIOD"
    | NONUSBACKSLASH -> "NONUSBACKSLASH"
    | APPLICATION -> "APPLICATION"
    | POWER -> "POWER"
    | KP_EQUALS -> "KP_EQUALS"
    | F13 -> "F13"
    | F14 -> "F14"
    | F15 -> "F15"
    | F16 -> "F16"
    | F17 -> "F17"
    | F18 -> "F18"
    | F19 -> "F19"
    | F20 -> "F20"
    | F21 -> "F21"
    | F22 -> "F22"
    | F23 -> "F23"
    | F24 -> "F24"
    | EXECUTE -> "EXECUTE"
    | HELP -> "HELP"
    | MENU -> "MENU"
    | SELECT -> "SELECT"
    | STOP -> "STOP"
    | AGAIN -> "AGAIN"
    | UNDO -> "UNDO"
    | CUT -> "CUT"
    | COPY -> "COPY"
    | PASTE -> "PASTE"
    | FIND -> "FIND"
    | MUTE -> "MUTE"
    | VOLUMEUP -> "VOLUMEUP"
    | VOLUMEDOWN -> "VOLUMEDOWN"
    | KP_COMMA -> "KP_COMMA"
    | KP_EQUALSAS400 -> "KP_EQUALSAS400"
    | INTERNATIONAL1 -> "INTERNATIONAL1"
    | INTERNATIONAL2 -> "INTERNATIONAL2"
    | INTERNATIONAL3 -> "INTERNATIONAL3"
    | INTERNATIONAL4 -> "INTERNATIONAL4"
    | INTERNATIONAL5 -> "INTERNATIONAL5"
    | INTERNATIONAL6 -> "INTERNATIONAL6"
    | INTERNATIONAL7 -> "INTERNATIONAL7"
    | INTERNATIONAL8 -> "INTERNATIONAL8"
    | INTERNATIONAL9 -> "INTERNATIONAL9"
    | LANG1 -> "LANG1"
    | LANG2 -> "LANG2"
    | LANG3 -> "LANG3"
    | LANG4 -> "LANG4"
    | LANG5 -> "LANG5"
    | LANG6 -> "LANG6"
    | LANG7 -> "LANG7"
    | LANG8 -> "LANG8"
    | LANG9 -> "LANG9"
    | ALTERASE -> "ALTERASE"
    | SYSREQ -> "SYSREQ"
    | CANCEL -> "CANCEL"
    | CLEAR -> "CLEAR"
    | PRIOR -> "PRIOR"
    | RETURN2 -> "RETURN2"
    | SEPARATOR -> "SEPARATOR"
    | OUT -> "OUT"
    | OPER -> "OPER"
    | CLEARAGAIN -> "CLEARAGAIN"
    | CRSEL -> "CRSEL"
    | EXSEL -> "EXSEL"
    | KP_00 -> "KP_00"
    | KP_000 -> "KP_000"
    | THOUSANDSSEPARATOR -> "THOUSANDSSEPARATOR"
    | DECIMALSEPARATOR -> "DECIMALSEPARATOR"
    | CURRENCYUNIT -> "CURRENCYUNIT"
    | CURRENCYSUBUNIT -> "CURRENCYSUBUNIT"
    | KP_LEFTPAREN -> "KP_LEFTPAREN"
    | KP_RIGHTPAREN -> "KP_RIGHTPAREN"
    | KP_LEFTBRACE -> "KP_LEFTBRACE"
    | KP_RIGHTBRACE -> "KP_RIGHTBRACE"
    | KP_TAB -> "KP_TAB"
    | KP_BACKSPACE -> "KP_BACKSPACE"
    | KP_A -> "KP_A"
    | KP_B -> "KP_B"
    | KP_C -> "KP_C"
    | KP_D -> "KP_D"
    | KP_E -> "KP_E"
    | KP_F -> "KP_F"
    | KP_XOR -> "KP_XOR"
    | KP_POWER -> "KP_POWER"
    | KP_PERCENT -> "KP_PERCENT"
    | KP_LESS -> "KP_LESS"
    | KP_GREATER -> "KP_GREATER"
    | KP_AMPERSAND -> "KP_AMPERSAND"
    | KP_DBLAMPERSAND -> "KP_DBLAMPERSAND"
    | KP_VERTICALBAR -> "KP_VERTICALBAR"
    | KP_DBLVERTICALBAR -> "KP_DBLVERTICALBAR"
    | KP_COLON -> "KP_COLON"
    | KP_HASH -> "KP_HASH"
    | KP_SPACE -> "KP_SPACE"
    | KP_AT -> "KP_AT"
    | KP_EXCLAM -> "KP_EXCLAM"
    | KP_MEMSTORE -> "KP_MEMSTORE"
    | KP_MEMRECALL -> "KP_MEMRECALL"
    | KP_MEMCLEAR -> "KP_MEMCLEAR"
    | KP_MEMADD -> "KP_MEMADD"
    | KP_MEMSUBTRACT -> "KP_MEMSUBTRACT"
    | KP_MEMMULTIPLY -> "KP_MEMMULTIPLY"
    | KP_MEMDIVIDE -> "KP_MEMDIVIDE"
    | KP_PLUSMINUS -> "KP_PLUSMINUS"
    | KP_CLEAR -> "KP_CLEAR"
    | KP_CLEARENTRY -> "KP_CLEARENTRY"
    | KP_BINARY -> "KP_BINARY"
    | KP_OCTAL -> "KP_OCTAL"
    | KP_DECIMAL -> "KP_DECIMAL"
    | KP_HEXADECIMAL -> "KP_HEXADECIMAL"
    | LCTRL -> "LCTRL"
    | LSHIFT -> "LSHIFT"
    | LALT -> "LALT"
    | LGUI -> "LGUI"
    | RCTRL -> "RCTRL"
    | RSHIFT -> "RSHIFT"
    | RALT -> "RALT"
    | RGUI -> "RGUI"
    | MODE -> "MODE"
    | AUDIONEXT -> "AUDIONEXT"
    | AUDIOPREV -> "AUDIOPREV"
    | AUDIOSTOP -> "AUDIOSTOP"
    | AUDIOPLAY -> "AUDIOPLAY"
    | AUDIOMUTE -> "AUDIOMUTE"
    | MEDIASELECT -> "MEDIASELECT"
    | WWW -> "WWW"
    | MAIL -> "MAIL"
    | CALCULATOR -> "CALCULATOR"
    | COMPUTER -> "COMPUTER"
    | AC_SEARCH -> "AC_SEARCH"
    | AC_HOME -> "AC_HOME"
    | AC_BACK -> "AC_BACK"
    | AC_FORWARD -> "AC_FORWARD"
    | AC_STOP -> "AC_STOP"
    | AC_REFRESH -> "AC_REFRESH"
    | AC_BOOKMARKS -> "AC_BOOKMARKS"
    | BRIGHTNESSDOWN -> "BRIGHTNESSDOWN"
    | BRIGHTNESSUP -> "BRIGHTNESSUP"
    | DISPLAYSWITCH -> "DISPLAYSWITCH"
    | KBDILLUMTOGGLE -> "KBDILLUMTOGGLE"
    | KBDILLUMDOWN -> "KBDILLUMDOWN"
    | KBDILLUMUP -> "KBDILLUMUP"
    | EJECT -> "EJECT"
    | SLEEP -> "SLEEP"
  ;;

  let of_string s =
    match String.uppercase_ascii s with
    | "UNKNOWN" -> UNKNOWN
    | "A" -> A
    | "B" -> B
    | "C" -> C
    | "D" -> D
    | "E" -> E
    | "F" -> F
    | "G" -> G
    | "H" -> H
    | "I" -> I
    | "J" -> J
    | "K" -> K
    | "L" -> L
    | "M" -> M
    | "N" -> N
    | "O" -> O
    | "P" -> P
    | "Q" -> Q
    | "R" -> R
    | "S" -> S
    | "T" -> T
    | "U" -> U
    | "V" -> V
    | "W" -> W
    | "X" -> X
    | "Y" -> Y
    | "Z" -> Z
    | "NUM1" -> Num1
    | "NUM2" -> Num2
    | "NUM3" -> Num3
    | "NUM4" -> Num4
    | "NUM5" -> Num5
    | "NUM6" -> Num6
    | "NUM7" -> Num7
    | "NUM8" -> Num8
    | "NUM9" -> Num9
    | "NUM0" -> Num0
    | "RETURN" -> RETURN
    | "ESCAPE" -> ESCAPE
    | "BACKSPACE" -> BACKSPACE
    | "TAB" -> TAB
    | "SPACE" -> SPACE
    | "MINUS" -> MINUS
    | "EQUALS" -> EQUALS
    | "LEFTBRACKET" -> LEFTBRACKET
    | "RIGHTBRACKET" -> RIGHTBRACKET
    | "BACKSLASH" -> BACKSLASH
    | "NONUSHASH" -> NONUSHASH
    | "SEMICOLON" -> SEMICOLON
    | "APOSTROPHE" -> APOSTROPHE
    | "GRAVE" -> GRAVE
    | "COMMA" -> COMMA
    | "PERIOD" -> PERIOD
    | "SLASH" -> SLASH
    | "CAPSLOCK" -> CAPSLOCK
    | "F1" -> F1
    | "F2" -> F2
    | "F3" -> F3
    | "F4" -> F4
    | "F5" -> F5
    | "F6" -> F6
    | "F7" -> F7
    | "F8" -> F8
    | "F9" -> F9
    | "F10" -> F10
    | "F11" -> F11
    | "F12" -> F12
    | "PRINTSCREEN" -> PRINTSCREEN
    | "SCROLLLOCK" -> SCROLLLOCK
    | "PAUSE" -> PAUSE
    | "INSERT" -> INSERT
    | "HOME" -> HOME
    | "PAGEUP" -> PAGEUP
    | "DELETE" -> DELETE
    | "END" -> END
    | "PAGEDOWN" -> PAGEDOWN
    | "RIGHT" -> RIGHT
    | "LEFT" -> LEFT
    | "DOWN" -> DOWN
    | "UP" -> UP
    | "NUMLOCKCLEAR" -> NUMLOCKCLEAR
    | "KP_DIVIDE" -> KP_DIVIDE
    | "KP_MULTIPLY" -> KP_MULTIPLY
    | "KP_MINUS" -> KP_MINUS
    | "KP_PLUS" -> KP_PLUS
    | "KP_ENTER" -> KP_ENTER
    | "KP_1" -> KP_1
    | "KP_2" -> KP_2
    | "KP_3" -> KP_3
    | "KP_4" -> KP_4
    | "KP_5" -> KP_5
    | "KP_6" -> KP_6
    | "KP_7" -> KP_7
    | "KP_8" -> KP_8
    | "KP_9" -> KP_9
    | "KP_0" -> KP_0
    | "KP_PERIOD" -> KP_PERIOD
    | "NONUSBACKSLASH" -> NONUSBACKSLASH
    | "APPLICATION" -> APPLICATION
    | "POWER" -> POWER
    | "KP_EQUALS" -> KP_EQUALS
    | "F13" -> F13
    | "F14" -> F14
    | "F15" -> F15
    | "F16" -> F16
    | "F17" -> F17
    | "F18" -> F18
    | "F19" -> F19
    | "F20" -> F20
    | "F21" -> F21
    | "F22" -> F22
    | "F23" -> F23
    | "F24" -> F24
    | "EXECUTE" -> EXECUTE
    | "HELP" -> HELP
    | "MENU" -> MENU
    | "SELECT" -> SELECT
    | "STOP" -> STOP
    | "AGAIN" -> AGAIN
    | "UNDO" -> UNDO
    | "CUT" -> CUT
    | "COPY" -> COPY
    | "PASTE" -> PASTE
    | "FIND" -> FIND
    | "MUTE" -> MUTE
    | "VOLUMEUP" -> VOLUMEUP
    | "VOLUMEDOWN" -> VOLUMEDOWN
    | "KP_COMMA" -> KP_COMMA
    | "KP_EQUALSAS400" -> KP_EQUALSAS400
    | "INTERNATIONAL1" -> INTERNATIONAL1
    | "INTERNATIONAL2" -> INTERNATIONAL2
    | "INTERNATIONAL3" -> INTERNATIONAL3
    | "INTERNATIONAL4" -> INTERNATIONAL4
    | "INTERNATIONAL5" -> INTERNATIONAL5
    | "INTERNATIONAL6" -> INTERNATIONAL6
    | "INTERNATIONAL7" -> INTERNATIONAL7
    | "INTERNATIONAL8" -> INTERNATIONAL8
    | "INTERNATIONAL9" -> INTERNATIONAL9
    | "LANG1" -> LANG1
    | "LANG2" -> LANG2
    | "LANG3" -> LANG3
    | "LANG4" -> LANG4
    | "LANG5" -> LANG5
    | "LANG6" -> LANG6
    | "LANG7" -> LANG7
    | "LANG8" -> LANG8
    | "LANG9" -> LANG9
    | "ALTERASE" -> ALTERASE
    | "SYSREQ" -> SYSREQ
    | "CANCEL" -> CANCEL
    | "CLEAR" -> CLEAR
    | "PRIOR" -> PRIOR
    | "RETURN2" -> RETURN2
    | "SEPARATOR" -> SEPARATOR
    | "OUT" -> OUT
    | "OPER" -> OPER
    | "CLEARAGAIN" -> CLEARAGAIN
    | "CRSEL" -> CRSEL
    | "EXSEL" -> EXSEL
    | "KP_00" -> KP_00
    | "KP_000" -> KP_000
    | "THOUSANDSSEPARATO  ->RTHOUSANDSSEPARATOR" | "DECIMALSEPARATOR" -> DECIMALSEPARATOR
    | "CURRENCYUNIT" -> CURRENCYUNIT
    | "CURRENCYSUBUNIT" -> CURRENCYSUBUNIT
    | "KP_LEFTPAREN" -> KP_LEFTPAREN
    | "KP_RIGHTPAREN" -> KP_RIGHTPAREN
    | "KP_LEFTBRACE" -> KP_LEFTBRACE
    | "KP_RIGHTBRACE" -> KP_RIGHTBRACE
    | "KP_TAB" -> KP_TAB
    | "KP_BACKSPACE" -> KP_BACKSPACE
    | "KP_A" -> KP_A
    | "KP_B" -> KP_B
    | "KP_C" -> KP_C
    | "KP_D" -> KP_D
    | "KP_E" -> KP_E
    | "KP_F" -> KP_F
    | "KP_XOR" -> KP_XOR
    | "KP_POWER" -> KP_POWER
    | "KP_PERCENT" -> KP_PERCENT
    | "KP_LESS" -> KP_LESS
    | "KP_GREATER" -> KP_GREATER
    | "KP_AMPERSAND" -> KP_AMPERSAND
    | "KP_DBLAMPERSAND" -> KP_DBLAMPERSAND
    | "KP_VERTICALBAR" -> KP_VERTICALBAR
    | "KP_DBLVERTICALBAR" -> KP_DBLVERTICALBAR
    | "KP_COLON" -> KP_COLON
    | "KP_HASH" -> KP_HASH
    | "KP_SPACE" -> KP_SPACE
    | "KP_AT" -> KP_AT
    | "KP_EXCLAM" -> KP_EXCLAM
    | "KP_MEMSTORE" -> KP_MEMSTORE
    | "KP_MEMRECALL" -> KP_MEMRECALL
    | "KP_MEMCLEAR" -> KP_MEMCLEAR
    | "KP_MEMADD" -> KP_MEMADD
    | "KP_MEMSUBTRACT" -> KP_MEMSUBTRACT
    | "KP_MEMMULTIPLY" -> KP_MEMMULTIPLY
    | "KP_MEMDIVIDE" -> KP_MEMDIVIDE
    | "KP_PLUSMINUS" -> KP_PLUSMINUS
    | "KP_CLEAR" -> KP_CLEAR
    | "KP_CLEARENTRY" -> KP_CLEARENTRY
    | "KP_BINARY" -> KP_BINARY
    | "KP_OCTAL" -> KP_OCTAL
    | "KP_DECIMAL" -> KP_DECIMAL
    | "KP_HEXADECIMAL" -> KP_HEXADECIMAL
    | "LCTRL" -> LCTRL
    | "LSHIFT" -> LSHIFT
    | "LALT" -> LALT
    | "LGUI" -> LGUI
    | "RCTRL" -> RCTRL
    | "RSHIFT" -> RSHIFT
    | "RALT" -> RALT
    | "RGUI" -> RGUI
    | "MODE" -> MODE
    | "AUDIONEXT" -> AUDIONEXT
    | "AUDIOPREV" -> AUDIOPREV
    | "AUDIOSTOP" -> AUDIOSTOP
    | "AUDIOPLAY" -> AUDIOPLAY
    | "AUDIOMUTE" -> AUDIOMUTE
    | "MEDIASELECT" -> MEDIASELECT
    | "WWW" -> WWW
    | "MAIL" -> MAIL
    | "CALCULATOR" -> CALCULATOR
    | "COMPUTER" -> COMPUTER
    | "AC_SEARCH" -> AC_SEARCH
    | "AC_HOME" -> AC_HOME
    | "AC_BACK" -> AC_BACK
    | "AC_FORWARD" -> AC_FORWARD
    | "AC_STOP" -> AC_STOP
    | "AC_REFRESH" -> AC_REFRESH
    | "AC_BOOKMARKS" -> AC_BOOKMARKS
    | "BRIGHTNESSDOWN" -> BRIGHTNESSDOWN
    | "BRIGHTNESSUP" -> BRIGHTNESSUP
    | "DISPLAYSWITCH" -> DISPLAYSWITCH
    | "KBDILLUMTOGGLE" -> KBDILLUMTOGGLE
    | "KBDILLUMDOWN" -> KBDILLUMDOWN
    | "KBDILLUMUP" -> KBDILLUMUP
    | "EJECT" -> EJECT
    | "SLEEP" -> SLEEP
    | _ -> invalid_arg "Sdlscancode.of_string"
  ;;
end

external get_platform : unit -> string = "caml_SDL_GetPlatform"

module PowerState = struct
  type t =
    [ `Unknown (** cannot determine power status *)
    | `On_Battery (** Not plugged in, running on the battery *)
    | `No_Battery (** Plugged in, no battery available *)
    | `Charging (** Plugged in, charging battery *)
    | `Charged (** Plugged in, battery charged *)
    ]
end

external get_power_info : unit -> PowerState.t * int * int = "caml_SDL_GetPowerInfo"

module Version = struct
  type t =
    { major : int
    ; minor : int
    ; patch : int
    }
end

external get_runtime_version : unit -> Version.t = "caml_SDL_GetRunTimeVersion"
external get_compiled_version : unit -> Version.t = "caml_SDL_GetCompiledVersion"
external get_revision_string : unit -> string = "caml_SDL_GetRevisionString"
external get_revision_number : unit -> int = "caml_SDL_GetRevisionNumber"
external get_ticks : unit -> int = "caml_SDL_GetTicks" [@@noalloc]
external delay : ms:int -> unit = "caml_SDL_Delay"

module RWops = struct
  type t

  type input =
    [ `Filename of string (* provide the input by its filename *)
    | `Buffer of bytes (* provide the input data as a bytes buffer *)
    | `String of string (* provide the input data as a string buffer *)
    ]

  type seek =
    | SEEK_SET
    | SEEK_CUR
    | SEEK_END
end

external rw_from_mem : bytes -> RWops.t = "caml_SDL_RWFromMem"
external rw_from_const_mem : string -> RWops.t = "caml_SDL_RWFromConstMem"
external rw_from_file : filename:string -> mode:string -> RWops.t = "caml_SDL_RWFromFile"
external alloc_rw : unit -> RWops.t = "caml_SDL_AllocRW"
external free_rw : RWops.t -> unit = "caml_SDL_FreeRW"
external close_rw : RWops.t -> unit = "caml_SDL_CloseRW"
external rw_size : RWops.t -> int64 = "caml_SDL_RWsize"
external rw_seek : RWops.t -> offset:int64 -> RWops.seek -> int64 = "caml_SDL_RWseek"
external rw_tell : RWops.t -> int64 = "caml_SDL_RWtell"
external read_U8 : RWops.t -> uint8 = "caml_SDL_ReadU8"
external write_U8 : RWops.t -> uint8 -> unit = "caml_SDL_WriteU8"
external read_be16 : RWops.t -> uint16 = "caml_SDL_ReadBE16"
external read_be32 : RWops.t -> uint32 = "caml_SDL_ReadBE32"
external read_be64 : RWops.t -> uint64 = "caml_SDL_ReadBE64"
external write_be16 : RWops.t -> uint16 -> unit = "caml_SDL_WriteBE16"
external write_be32 : RWops.t -> uint32 -> unit = "caml_SDL_WriteBE32"
external write_be64 : RWops.t -> uint64 -> unit = "caml_SDL_WriteBE64"
external read_le16 : RWops.t -> uint16 = "caml_SDL_ReadLE16"
external read_le32 : RWops.t -> uint32 = "caml_SDL_ReadLE32"
external read_le64 : RWops.t -> uint64 = "caml_SDL_ReadLE64"
external write_le16 : RWops.t -> uint16 -> unit = "caml_SDL_WriteLE16"
external write_le32 : RWops.t -> uint32 -> unit = "caml_SDL_WriteLE32"
external write_le64 : RWops.t -> uint64 -> unit = "caml_SDL_WriteLE64"

let from_input = function
  | `Filename filename -> rw_from_file ~filename ~mode:"r"
  | `Buffer mem -> rw_from_mem mem
  | `String mem -> rw_from_const_mem mem
;;

let from_input_opt = function
  | `Filename filename -> Some (rw_from_file ~filename ~mode:"r")
  | `Buffer mem -> Some (rw_from_mem mem)
  | `String mem -> Some (rw_from_const_mem mem)
  | _ -> None
;;

module Surface = struct
  type t
end

module SurfaceBigarray = struct
  type t = Surface.t
end

external create_rgb_surface
  :  width:int
  -> height:int
  -> depth:int
  -> Surface.t
  = "caml_SDL_CreateRGBSurface"

external free_surface : Surface.t -> unit = "caml_SDL_FreeSurface"
external load_bmp : filename:string -> Surface.t = "caml_SDL_LoadBMP"
external save_bmp : Surface.t -> filename:string -> unit = "caml_SDL_SaveBMP"

external fill_rect
  :  dst:Surface.t
  -> rect:Rect.t
  -> color:int32
  -> unit
  = "caml_SDL_FillRect"

external blit_surface
  :  src:Surface.t
  -> src_rect:Rect.t
  -> dst:Surface.t
  -> dst_rect:Rect.t
  -> Rect.t
  = "caml_SDL_BlitSurface"

external blit_surf
  :  src:Surface.t
  -> dst:Surface.t
  -> dst_rect:Rect.t
  -> Rect.t
  = "caml_SDL_BlitSurf"

external blit_surfs
  :  src:Surface.t
  -> dst:Surface.t
  -> dst_rect:Rect.t
  -> unit
  = "caml_SDL_BlitSurfs"

external surface_blit_pixels_unsafe
  :  Surface.t
  -> string
  -> unit
  = "caml_SDL_Surface_Blit_Pixels"

external set_color_key
  :  Surface.t
  -> enable:bool
  -> key:int32
  -> unit
  = "caml_SDL_SetColorKey"

external set_color_key_map_rgb
  :  Surface.t
  -> enable:bool
  -> rgb:int * int * int
  -> unit
  = "caml_SDL_SetColorKey_MapRGB"

external get_surface_width : Surface.t -> int = "caml_SDL_SurfaceGetWidth"
external get_surface_height : Surface.t -> int = "caml_SDL_SurfaceGetHeight"
external get_surface_dims : Surface.t -> int * int = "caml_SDL_SurfaceGetDims"
external get_surface_pitch : Surface.t -> int = "caml_SDL_SurfaceGetPitch"

external get_surface_pixel32_unsafe
  :  Surface.t
  -> x:int
  -> y:int
  -> int32
  = "caml_SDL_SurfaceGetPixel32"

external get_surface_pixel16_unsafe
  :  Surface.t
  -> x:int
  -> y:int
  -> int32
  = "caml_SDL_SurfaceGetPixel16"

external get_surface_pixel8_unsafe
  :  Surface.t
  -> x:int
  -> y:int
  -> int32
  = "caml_SDL_SurfaceGetPixel8"

external get_surface_bits_per_pixel : Surface.t -> int = "caml_SDL_SurfaceGetBitsPerPixel"
external surface_has_palette : Surface.t -> bool = "caml_SDL_SurfaceHasPalette"
external surface_palette_colors : Surface.t -> int = "caml_SDL_SurfacePaletteColors"

external set_surface_blend_mode
  :  Surface.t
  -> BlendMode.t
  -> unit
  = "caml_SDL_SetSurfaceBlendMode"

external surface_get_pixelformat_t
  :  Surface.t
  -> PixelFormat.t
  = "caml_SDL_Surface_get_pixelformat_t"

external surface_get_pixels : Surface.t -> string = "caml_SDL_Surface_get_pixels"

external surface_ba_get_pixels
  :  SurfaceBigarray.t
  -> (int, Bigarray.int8_unsigned_elt, Bigarray.c_layout) Bigarray.Array1.t
  = "caml_SDL_Surface_ba_get_pixels"

external create_rgb_surface_from
  :  pixels:(int, Bigarray.int8_unsigned_elt, Bigarray.c_layout) Bigarray.Array1.t
  -> width:int
  -> height:int
  -> depth:int
  -> pitch:int
  -> r_mask:int32
  -> g_mask:int32
  -> b_mask:int32
  -> a_mask:int32
  -> SurfaceBigarray.t
  = "caml_SDL_CreateRGBSurfaceFrom_bytecode" "caml_SDL_CreateRGBSurfaceFrom"

module WindowEventID = struct
  type t =
    | NONE
    | SHOWN
    | HIDDEN
    | EXPOSED
    | MOVED of Point.t
    | RESIZED of Point.t
    | SIZE_CHANGED of Point.t
    | MINIMIZED
    | MAXIMIZED
    | RESTORED
    | ENTER
    | LEAVE
    | FOCUS_GAINED
    | FOCUS_LOST
    | CLOSE
    | TAKE_FOCUS
    | HIT_TEST

  let string_of_id = function
    | NONE -> "SDL_WINDOWEVENT_NONE"
    | SHOWN -> "SDL_WINDOWEVENT_SHOWN"
    | HIDDEN -> "SDL_WINDOWEVENT_HIDDEN"
    | EXPOSED -> "SDL_WINDOWEVENT_EXPOSED"
    | MINIMIZED -> "SDL_WINDOWEVENT_MINIMIZED"
    | MAXIMIZED -> "SDL_WINDOWEVENT_MAXIMIZED"
    | RESTORED -> "SDL_WINDOWEVENT_RESTORED"
    | ENTER -> "SDL_WINDOWEVENT_ENTER"
    | LEAVE -> "SDL_WINDOWEVENT_LEAVE"
    | FOCUS_GAINED -> "SDL_WINDOWEVENT_FOCUS_GAINED"
    | FOCUS_LOST -> "SDL_WINDOWEVENT_FOCUS_LOST"
    | CLOSE -> "SDL_WINDOWEVENT_CLOSE"
    | TAKE_FOCUS -> "SDL_WINDOWEVENT_TAKE_FOCUS"
    | HIT_TEST -> "SDL_WINDOWEVENT_HIT_TEST"
    | MOVED p -> Printf.sprintf "SDL_WINDOWEVENT_MOVED(%d, %d)" p.x p.y
    | RESIZED p ->
      Printf.sprintf "SDL_WINDOWEVENT_RESIZED(%d, %d)" p.x p.y
    | SIZE_CHANGED p ->
      Printf.sprintf "SDL_WINDOWEVENT_SIZE_CHANGED(%d, %d)" p.x p.y
  ;;
end

module GLattr = struct
  type t =
    | SDL_GL_RED_SIZE
    | SDL_GL_GREEN_SIZE
    | SDL_GL_BLUE_SIZE
    | SDL_GL_ALPHA_SIZE
    | SDL_GL_BUFFER_SIZE
    | SDL_GL_DOUBLEBUFFER
    | SDL_GL_DEPTH_SIZE
    | SDL_GL_STENCIL_SIZE
    | SDL_GL_ACCUM_RED_SIZE
    | SDL_GL_ACCUM_GREEN_SIZE
    | SDL_GL_ACCUM_BLUE_SIZE
    | SDL_GL_ACCUM_ALPHA_SIZE
    | SDL_GL_STEREO
    | SDL_GL_MULTISAMPLEBUFFERS
    | SDL_GL_MULTISAMPLESAMPLES
    | SDL_GL_ACCELERATED_VISUAL
    | SDL_GL_RETAINED_BACKING
    | SDL_GL_CONTEXT_MAJOR_VERSION
    | SDL_GL_CONTEXT_MINOR_VERSION
    | SDL_GL_CONTEXT_EGL
    | SDL_GL_CONTEXT_FLAGS
    | SDL_GL_CONTEXT_PROFILE_MASK
    | SDL_GL_SHARE_WITH_CURRENT_CONTEXT
end

module GLcontext = struct
  type t
end

module Window = struct
  type t
end

module WindowFlags = struct
  type t =
    | FullScreen
    | OpenGL
    | Shown
    | Hidden
    | Borderless
    | Resizable
    | Minimized
    | Maximized
    | Input_Grabbed
    | Input_Focus
    | Mouse_Focus
    | FullScreen_Desktop
    | Foreign
    | Allow_HighDPI
end

module WindowPos = struct
  type t =
    [ `centered
    | `undefined
    | `pos of int
    ]
end

external gl_create_context : win:Window.t -> GLcontext.t = "caml_SDL_GL_CreateContext"

external gl_make_current
  :  win:Window.t
  -> ctx:GLcontext.t
  -> int
  = "caml_SDL_GL_MakeCurrent"

external gl_unload_library : unit -> unit = "caml_SDL_GL_UnloadLibrary"

external gl_extension_supported
  :  extension:string
  -> bool
  = "caml_SDL_GL_ExtensionSupported"

external gl_set_swap_interval : interval:int -> unit = "caml_SDL_GL_SetSwapInterval"
external gl_get_swap_interval : unit -> int = "caml_SDL_GL_GetSwapInterval"
external gl_swap_window : Window.t -> unit = "caml_SDL_GL_SwapWindow"
external gl_delete_context : GLcontext.t -> unit = "caml_SDL_GL_DeleteContext"
external set_attribute : GLattr.t -> int -> unit = "caml_SDL_GL_SetAttribute"
external get_attribute : GLattr.t -> int = "caml_SDL_GL_GetAttribute"

external create_window
  :  title:string
  -> x:WindowPos.t
  -> y:WindowPos.t
  -> width:int
  -> height:int
  -> flags:WindowFlags.t list
  -> Window.t
  = "caml_SDL_CreateWindow_bc" "caml_SDL_CreateWindow"

external set_window_title
  :  window:Window.t
  -> title:string
  -> unit
  = "caml_SDL_SetWindowTitle"

external show_window : Window.t -> unit = "caml_SDL_ShowWindow"
external hide_window : Window.t -> unit = "caml_SDL_HideWindow"
external raise_window : Window.t -> unit = "caml_SDL_RaiseWindow"
external maximize_window : Window.t -> unit = "caml_SDL_MaximizeWindow"
external minimize_window : Window.t -> unit = "caml_SDL_MinimizeWindow"
external restore_window : Window.t -> unit = "caml_SDL_RestoreWindow"
external get_window_surface : Window.t -> Surface.t = "caml_SDL_GetWindowSurface"
external update_window_surface : Window.t -> unit = "caml_SDL_UpdateWindowSurface"

external set_window_brightness
  :  Window.t
  -> brightness:float
  -> unit
  = "caml_SDL_SetWindowBrightness"

external get_window_brightness : Window.t -> float = "caml_SDL_GetWindowBrightness"
external destroy_window : Window.t -> unit = "caml_SDL_DestroyWindow"
external get_window_size : Window.t -> int * int = "caml_SDL_GetWindowSize"

module Renderer = struct
  type t
end

module RendererInfo = struct
  type t =
    { name : string
    ; max_texture_width : int
    ; max_texture_height : int
    }
end

module RendererFlags = struct
  type t =
    | Software
    | Accelerated
    | PresentVSync
    | TargetTexture

  let to_string = function
    | Software -> "Software"
    | Accelerated -> "Accelerated"
    | PresentVSync -> "PresentVSync"
    | TargetTexture -> "TargetTexture"
  ;;

  let of_string s =
    match String.lowercase_ascii s with
    | "software" -> Software
    | "accelerated" -> Accelerated
    | "presentvsync" -> PresentVSync
    | "targettexture" -> TargetTexture
    | _ -> invalid_arg "Sdl.RendererFlags.of_string"
  ;;
end

module RendererFlip = struct
  type t =
    | Flip_None
    | Flip_Horizontal
    | Flip_Vertical
end

module TextureAccess = struct
  type t =
    | Static
    | Streaming
    | Target

  let to_string = function
    | Static -> "SDL_TEXTUREACCESS_STATIC"
    | Streaming -> "SDL_TEXTUREACCESS_STREAMING"
    | Target -> "SDL_TEXTUREACCESS_TARGET"
  ;;

  let of_string s =
    match String.uppercase_ascii s with
    | "SDL_TEXTUREACCESS_STATIC" -> Static
    | "SDL_TEXTUREACCESS_STREAMING" -> Streaming
    | "SDL_TEXTUREACCESS_TARGET" -> Target
    | _ -> invalid_arg "SdltextureAccess.of_string"
  ;;
end

module Texture = struct
  type t
end

external create_window_and_renderer
  :  width:int
  -> height:int
  -> flags:WindowFlags.t list
  -> Window.t * Renderer.t
  = "caml_SDL_CreateWindowAndRenderer"

external create_renderer
  :  win:Window.t
  -> index:int
  -> flags:RendererFlags.t list
  -> Renderer.t
  = "caml_SDL_CreateRenderer"

external destroy_renderer : Renderer.t -> unit = "caml_SDL_DestroyRenderer"

external render_set_logical_size
  :  Renderer.t
  -> width:int
  -> height:int
  -> unit
  = "caml_SDL_RenderSetLogicalSize"

external render_set_viewport : Renderer.t -> Rect.t -> unit = "caml_SDL_RenderSetViewport"

external render_set_clip_rect
  :  Renderer.t
  -> Rect.t
  -> unit
  = "caml_SDL_RenderSetClipRect"

external set_render_draw_color
  :  Renderer.t
  -> r:int
  -> g:int
  -> b:int
  -> a:int
  -> unit
  = "caml_SDL_SetRenderDrawColor"

external set_render_draw_blend_mode
  :  Renderer.t
  -> BlendMode.t
  -> unit
  = "caml_SDL_SetRenderDrawBlendMode"

external render_draw_point : Renderer.t -> int * int -> unit = "caml_SDL_RenderDrawPoint"

external render_draw_point2
  :  Renderer.t
  -> x:int
  -> y:int
  -> unit
  = "caml_SDL_RenderDrawPoint2"

external render_draw_points
  :  Renderer.t
  -> points:(int * int) array
  -> unit
  = "caml_SDL_RenderDrawPoints"

external render_draw_line
  :  Renderer.t
  -> (int * int) * (int * int)
  -> unit
  = "caml_SDL_RenderDrawLine"

external render_draw_line2
  :  Renderer.t
  -> p1:int * int
  -> p2:int * int
  -> unit
  = "caml_SDL_RenderDrawLine2"

external render_draw_lines
  :  Renderer.t
  -> (int * int) array
  -> unit
  = "caml_SDL_RenderDrawLines"

external render_draw_rect : Renderer.t -> Rect.t -> unit = "caml_SDL_RenderDrawRect"

external render_draw_rects
  :  Renderer.t
  -> Rect.t array
  -> unit
  = "caml_SDL_RenderDrawRects"

external render_fill_rect : Renderer.t -> Rect.t -> unit = "caml_SDL_RenderFillRect"

external render_fill_rects
  :  Renderer.t
  -> Rect.t array
  -> unit
  = "caml_SDL_RenderFillRects"

external render_copy
  :  Renderer.t
  -> texture:Texture.t
  -> srcrect:Rect.t option
  -> dstrect:Rect.t option
  -> unit
  = "caml_SDL_RenderCopy"

external render_copyEx
  :  Renderer.t
  -> texture:Texture.t
  -> srcrect:Rect.t option
  -> dstrect:Rect.t option
  -> angle:float
  -> center:Point.t option
  -> flip:RendererFlip.t
  -> unit
  = "caml_SDL_RenderCopyEx_bc" "caml_SDL_RenderCopyEx"

external render_set_scale
  :  Renderer.t
  -> scaleX:float
  -> scaleY:float
  -> unit
  = "caml_SDL_RenderSetScale"

external render_present : Renderer.t -> unit = "caml_SDL_RenderPresent"
external render_clear : Renderer.t -> unit = "caml_SDL_RenderClear"
external get_num_render_drivers : unit -> int = "caml_SDL_GetNumRenderDrivers"
external get_render_driver_info : int -> RendererInfo.t = "caml_SDL_GetRenderDriverInfo"

external render_read_pixels
  :  Renderer.t
  -> ?rect:Rect.t
  -> Surface.t
  -> unit
  = "caml_SDL_RenderReadPixels"

external create_texture
  :  Renderer.t
  -> fmt:PixelFormat.t
  -> access:TextureAccess.t
  -> width:int
  -> height:int
  -> Texture.t
  = "caml_SDL_CreateTexture"

external destroy_texture : Texture.t -> unit = "caml_SDL_DestroyTexture"
external query_texture
  :  Texture.t
  -> (PixelFormat.t * TextureAccess.t * int * int) = "caml_SDL_QueryTexture"

external set_render_target
  :  Renderer.t
  -> Texture.t option
  -> unit
  = "caml_SDL_SetRenderTarget"

external get_renderer_output_size
  :  Renderer.t
  -> int * int
  = "caml_SDL_GetRendererOutputSize"

external create_texture_from_surface
  :  Renderer.t
  -> Surface.t
  -> Texture.t
  = "caml_SDL_CreateTextureFromSurface"

external set_texture_blend_mode
  :  Texture.t
  -> BlendMode.t
  -> unit
  = "caml_SDL_SetTextureBlendMode"
[@@noalloc]

external get_texture_blend_mode
  :  Texture.t
  -> BlendMode.t
  = "caml_SDL_GetTextureBlendMode"

external set_texture_alpha_mod
  :  Texture.t
  -> alpha:int
  -> unit
  = "caml_SDL_SetTextureAlphaMod"

external get_texture_alpha_mod : Texture.t -> int = "caml_SDL_GetTextureAlphaMod"

external set_texture_color_mod
  :  Texture.t
  -> int * int * int
  -> unit
  = "caml_SDL_SetTextureColorMod"

external set_texture_color_mod3
  :  Texture.t
  -> r:int
  -> g:int
  -> b:int
  -> unit
  = "caml_SDL_SetTextureColorMod3"

external get_texture_color_mod
  :  Texture.t
  -> int * int * int
  = "caml_SDL_GetTextureColorMod"

module KeyState = struct
  type t =
    | SDL_RELEASED
    | SDL_PRESSED

  let to_string = function
    | SDL_RELEASED -> "SDL_RELEASED"
    | SDL_PRESSED -> "SDL_PRESSED"
  ;;
end

module KeyboardEvent = struct
  type t =
    { ke_timestamp : int32
    ; ke_window_id : int32
    ; ke_state : KeyState.t
    ; ke_repeat : int
    ; scancode : Scancode.t
    ; keycode : Keycode.t
    ; keymod : Keymod.t list
    }
end

module MouseMotionEvent = struct
  type t =
    { mm_timestamp : int32
    ; mm_window_id : int32
    ; mm_buttons : int list
    ; mm_x : int
    ; mm_y : int
    ; mm_xrel : int
    ; mm_yrel : int
    }
end

module MouseButtonEvent = struct
  type t =
    { mb_timestamp : int32
    ; mb_window_id : int32
    ; mb_button : int
    ; mb_state : KeyState.t
    ; mb_x : int
    ; mb_y : int
    }
end

module MouseWheelEvent = struct
  type t =
    { mw_timestamp : int32
    ; mw_window_id : int32
    ; mw_x : int
    ; mw_y : int
    }
end

module JoyAxisEvent = struct
  type t =
    { ja_timestamp : int32
    ; ja_which : int
    ; ja_axis : int
    ; ja_value : int
    }
end

module JoyButtonEvent = struct
  type t =
    { jb_timestamp : int32
    ; jb_which : int
    ; jb_button : int
    ; jb_state : KeyState.t
    }
end

module JoyHatEvent = struct
  type t =
    { jh_timestamp : int32
    ; jh_which : int
    ; jh_hat : int
    ; jh_dir : HapticDirection.t
    ; jh_pos : HapticPosition.t
    }
end

module JoyDeviceEvent = struct
  type event_type =
    | SDL_JOYDEVICEADDED
    | SDL_JOYDEVICEREMOVED

  let to_string = function
    | SDL_JOYDEVICEADDED -> "SDL_JOYDEVICEADDED"
    | SDL_JOYDEVICEREMOVED -> "SDL_JOYDEVICEREMOVED"
  ;;

  type t =
    { jd_timestamp : int32
    ; jd_which : int
    ; jd_change : event_type
    }
end

module WindowEvent = struct
  type t =
    { we_timestamp : int32
    ; window_ID : int32
    ; kind : WindowEventID.t
    }
end

module QuitEvent = struct
  type t = { quit_timestamp : int32 }
end

module TextEditingEvent = struct
  type t =
    { te_timestamp : int32
    ; te_window_ID : int32
    ; te_text : string
    ; te_begin : int
    ; te_length : int
    }
end

module TextInputEvent = struct
  type t =
    { ti_timestamp : int32
    ; ti_window_ID : int32
    ; ti_text : string
    }
end

module Event = struct
  type t =
    | SDL_QUIT of QuitEvent.t
    | SDL_MOUSEMOTION of MouseMotionEvent.t
    | SDL_MOUSEBUTTONDOWN of MouseButtonEvent.t
    | SDL_MOUSEBUTTONUP of MouseButtonEvent.t
    | SDL_MOUSEWHEEL of MouseWheelEvent.t
    | SDL_KEYDOWN of KeyboardEvent.t
    | SDL_KEYUP of KeyboardEvent.t
    | SDL_TEXTEDITING of TextEditingEvent.t
    | SDL_TEXTINPUT of TextInputEvent.t
    | SDL_JOYAXISMOTION of JoyAxisEvent.t
    | SDL_JOYBALLMOTION
    | SDL_JOYHATMOTION of JoyHatEvent.t
    | SDL_JOYBUTTONDOWN of JoyButtonEvent.t
    | SDL_JOYBUTTONUP of JoyButtonEvent.t
    | SDL_JOYDEVICEADDED of JoyDeviceEvent.t
    | SDL_JOYDEVICEREMOVED of JoyDeviceEvent.t
    | SDL_CONTROLLERAXISMOTION
    | SDL_CONTROLLERBUTTONDOWN
    | SDL_CONTROLLERBUTTONUP
    | SDL_CONTROLLERDEVICEADDED
    | SDL_CONTROLLERDEVICEREMOVED
    | SDL_CONTROLLERDEVICEREMAPPED
    | SDL_FINGERDOWN
    | SDL_FINGERUP
    | SDL_FINGERMOTION
    | SDL_DOLLARGESTURE
    | SDL_DOLLARRECORD
    | SDL_MULTIGESTURE
    | SDL_CLIPBOARDUPDATE
    | SDL_DROPFILE
    | SDL_USEREVENT
    | SDL_WINDOWEVENT of WindowEvent.t
    | SDL_SYSWMEVENT
    | SDL_APP_TERMINATING
    | SDL_APP_LOWMEMORY
    | SDL_APP_WILLENTERBACKGROUND
    | SDL_APP_DIDENTERBACKGROUND
    | SDL_APP_WILLENTERFOREGROUND
    | SDL_APP_DIDENTERFOREGROUND
    | SDL_DISPLAYEVENT
    | SDL_KEYMAPCHANGED
    | SDL_DROPTEXT
    | SDL_DROPBEGIN
    | SDL_DROPCOMPLETE
    | SDL_AUDIODEVICEADDED
    | SDL_AUDIODEVICEREMOVED
    | SDL_SENSORUPDATE
    | SDL_RENDER_TARGETS_RESET
    | SDL_RENDER_DEVICE_RESET

  let to_string = function
    | SDL_QUIT _ -> "SDL_QUIT"
    | SDL_MOUSEMOTION _ -> "SDL_MOUSEMOTION"
    | SDL_MOUSEBUTTONDOWN _ -> "SDL_MOUSEBUTTONDOWN"
    | SDL_MOUSEBUTTONUP _ -> "SDL_MOUSEBUTTONUP"
    | SDL_MOUSEWHEEL _ -> "SDL_MOUSEWHEEL"
    | SDL_KEYDOWN _ -> "SDL_KEYDOWN"
    | SDL_KEYUP _ -> "SDL_KEYUP"
    | SDL_TEXTEDITING _ -> "SDL_TEXTEDITING"
    | SDL_TEXTINPUT _ -> "SDL_TEXTINPUT"
    | SDL_JOYAXISMOTION _ -> "SDL_JOYAXISMOTION"
    | SDL_JOYBALLMOTION -> "SDL_JOYBALLMOTION"
    | SDL_JOYHATMOTION _ -> "SDL_JOYHATMOTION"
    | SDL_JOYBUTTONDOWN _ -> "SDL_JOYBUTTONDOWN"
    | SDL_JOYBUTTONUP _ -> "SDL_JOYBUTTONUP"
    | SDL_JOYDEVICEADDED _ -> "SDL_JOYDEVICEADDED"
    | SDL_JOYDEVICEREMOVED _ -> "SDL_JOYDEVICEREMOVED"
    | SDL_CONTROLLERAXISMOTION -> "SDL_CONTROLLERAXISMOTION"
    | SDL_CONTROLLERBUTTONDOWN -> "SDL_CONTROLLERBUTTONDOWN"
    | SDL_CONTROLLERBUTTONUP -> "SDL_CONTROLLERBUTTONUP"
    | SDL_CONTROLLERDEVICEADDED -> "SDL_CONTROLLERDEVICEADDED"
    | SDL_CONTROLLERDEVICEREMOVED -> "SDL_CONTROLLERDEVICEREMOVED"
    | SDL_CONTROLLERDEVICEREMAPPED -> "SDL_CONTROLLERDEVICEREMAPPED"
    | SDL_FINGERDOWN -> "SDL_FINGERDOWN"
    | SDL_FINGERUP -> "SDL_FINGERUP"
    | SDL_FINGERMOTION -> "SDL_FINGERMOTION"
    | SDL_DOLLARGESTURE -> "SDL_DOLLARGESTURE"
    | SDL_DOLLARRECORD -> "SDL_DOLLARRECORD"
    | SDL_MULTIGESTURE -> "SDL_MULTIGESTURE"
    | SDL_CLIPBOARDUPDATE -> "SDL_CLIPBOARDUPDATE"
    | SDL_DROPFILE -> "SDL_DROPFILE"
    | SDL_USEREVENT -> "SDL_USEREVENT"
    | SDL_WINDOWEVENT _ -> "SDL_WINDOWEVENT"
    | SDL_SYSWMEVENT -> "SDL_SYSWMEVENT"
    | SDL_APP_TERMINATING -> "SDL_APP_TERMINATING"
    | SDL_APP_LOWMEMORY -> "SDL_APP_LOWMEMORY"
    | SDL_APP_WILLENTERBACKGROUND -> "SDL_APP_WILLENTERBACKGROUND"
    | SDL_APP_DIDENTERBACKGROUND -> "SDL_APP_DIDENTERBACKGROUND"
    | SDL_APP_WILLENTERFOREGROUND -> "SDL_APP_WILLENTERFOREGROUND"
    | SDL_APP_DIDENTERFOREGROUND -> "SDL_APP_DIDENTERFOREGROUND"
    | SDL_DISPLAYEVENT -> "SDL_DISPLAYEVENT"
    | SDL_KEYMAPCHANGED -> "SDL_KEYMAPCHANGED"
    | SDL_DROPTEXT -> "SDL_DROPTEXT"
    | SDL_DROPBEGIN -> "SDL_DROPBEGIN"
    | SDL_DROPCOMPLETE -> "SDL_DROPCOMPLETE"
    | SDL_AUDIODEVICEADDED -> "SDL_AUDIODEVICEADDED"
    | SDL_AUDIODEVICEREMOVED -> "SDL_AUDIODEVICEREMOVED"
    | SDL_SENSORUPDATE -> "SDL_SENSORUPDATE"
    | SDL_RENDER_TARGETS_RESET -> "SDL_RENDER_TARGETS_RESET"
    | SDL_RENDER_DEVICE_RESET -> "SDL_RENDER_DEVICE_RESET"
  ;;
end

external poll_event : unit -> Event.t option = "caml_SDL_PollEvent"

module MouseButton = struct
  type t =
    | Left
    | Middle
    | Right
    | X1
    | X2
    | X3
    | X4
    | X5

  let to_string = function
    | Left -> "Button_Left"
    | Middle -> "Button_Middle"
    | Right -> "Button_Right"
    | X1 -> "Button_X1"
    | X2 -> "Button_X2"
    | X3 -> "Button_X3"
    | X4 -> "Button_X4"
    | X5 -> "Button_X5"
  ;;

  let of_string s =
    match String.lowercase_ascii s with
    | "Button_Left" -> Left
    | "Button_Middle" -> Middle
    | "Button_Right" -> Right
    | "Button_X1" -> X1
    | "Button_X2" -> X2
    | "Button_X3" -> X3
    | "Button_X4" -> X4
    | "Button_X5" -> X5
    | _ -> invalid_arg "Sdlmouse.of_string"
  ;;
end

module MousePosition = struct
  type t = int * int
end

external get_mouse_state
  :  unit
  -> MousePosition.t * MouseButton.t list
  = "caml_SDL_GetMouseState"

external get_mouse_buttons : unit -> MouseButton.t list = "caml_SDL_GetMouseButtons"
external get_mouse_pos : unit -> MousePosition.t = "caml_SDL_GetMousePos"

external warp_mouse_in_window
  :  Window.t
  -> x:int
  -> y:int
  -> unit
  = "caml_SDL_WarpMouseInWindow"

external set_relative_mouse_mode : enabled:bool -> unit = "caml_SDL_SetRelativeMouseMode"
external show_cursor : toggle:bool -> unit = "caml_SDL_ShowCursor"
external show_cursor_query : unit -> bool = "caml_SDL_ShowCursor_Query"
