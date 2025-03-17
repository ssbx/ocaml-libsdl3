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

#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keyboard.h>
#include <SDL3/SDL_keycode.h>
#include <SDL3/SDL_scancode.h>
#include "OcamlSDL3/keycode_stub.h"


#if 0
    SDL_WindowEvent window;           /* Window */
    SDL_KeyboardEvent key;            /* Keyboard */
    SDL_TextEditingEvent edit;        /* Text editing */
    SDL_TextInputEvent text;          /* Text input */
    SDL_MouseMotionEvent motion;      /* Mouse motion */
    SDL_MouseButtonEvent button;      /* Mouse button */
    SDL_MouseWheelEvent wheel;        /* Mouse wheel */
    SDL_JoyAxisEvent jaxis;           /* Joystick axis */
    SDL_JoyBallEvent jball;           /* Joystick ball */
    SDL_JoyHatEvent jhat;             /* Joystick hat */
    SDL_JoyButtonEvent jbutton;       /* Joystick button */
    SDL_JoyDeviceEvent jdevice;       /* Joystick device change */
    SDL_GamepadAxisEvent caxis;      /* Game Controller button */
    SDL_GamepadButtonEvent cbutton;  /* Game Controller button */
    SDL_GamepadDeviceEvent cdevice;  /* Game Controller device */
    SDL_QuitEvent quit;
    SDL_UserEvent user;               /* Custom */
    SDL_SysWMEvent syswm;             /* System dependent window */
    SDL_TouchFingerEvent tfinger;     /* Touch finger */
    SDL_TouchButtonEvent tbutton;     /* Touch button */
    SDL_MultiGestureEvent mgesture;   /* Multi Finger Gesture data */
    SDL_DollarGestureEvent dgesture;  /* Multi Finger Gesture data */
    SDL_DropEvent drop;               /* Drag and drop */
#endif

#define Val_Joy_Ball_Motion             Val_int(0)
#define Val_Controller_Axis_Motion      Val_int(1)
#define Val_Controller_Button_Down      Val_int(2)
#define Val_Controller_Button_Up        Val_int(3)
#define Val_Controller_Device_Added     Val_int(4)
#define Val_Controller_Device_Removed   Val_int(5)
#define Val_Controller_Device_Remapped  Val_int(6)
#define Val_Finger_Down                 Val_int(7)
#define Val_Finger_Up                   Val_int(8)
#define Val_Finger_Motion               Val_int(9)
#define Val_Dollar_Gesture              Val_int(10)
#define Val_Dollar_Record               Val_int(11)
#define Val_Multi_Gesture               Val_int(12)
#define Val_Clipboard_Update            Val_int(13)
#define Val_Drop_File                   Val_int(14)
#define Val_User_Event                  Val_int(15)
#define Val_SYSWM_Event                 Val_int(16)
#define Val_SDL_APP_TERMINATING         Val_int(17)
#define Val_SDL_APP_LOWMEMORY           Val_int(18)
#define Val_SDL_APP_WILLENTERBACKGROUND Val_int(19)
#define Val_SDL_APP_DIDENTERBACKGROUND  Val_int(20)
#define Val_SDL_APP_WILLENTERFOREGROUND Val_int(21)
#define Val_SDL_APP_DIDENTERFOREGROUND  Val_int(22)
#define Val_SDL_DISPLAYEVENT            Val_int(23)
#define Val_SDL_KEYMAPCHANGED           Val_int(24)
#define Val_SDL_DROPTEXT                Val_int(25)
#define Val_SDL_DROPBEGIN               Val_int(26)
#define Val_SDL_DROPCOMPLETE            Val_int(27)
#define Val_SDL_AUDIODEVICEADDED        Val_int(28)
#define Val_SDL_AUDIODEVICEREMOVED      Val_int(29)
#define Val_SDL_SENSORUPDATE            Val_int(30)
#define Val_SDL_RENDER_TARGETS_RESET    Val_int(31)
#define Val_SDL_RENDER_DEVICE_RESET     Val_int(32)



#define Tag_Quit                        (0)
#define Tag_Mouse_Motion                (1)
#define Tag_Mouse_Button_Down           (2)
#define Tag_Mouse_Button_Up             (3)
#define Tag_Mouse_Wheel                 (4)
#define Tag_KeyDown                     (5)
#define Tag_KeyUp                       (6)
#define Tag_Text_Editing                (7)
#define Tag_Text_Input                  (8)
#define Tag_Joy_Axis_Motion             (9)
#define Tag_Joy_Hat_Motion              (10)
#define Tag_Joy_Button_Down             (11)
#define Tag_Joy_Button_Up               (12)
#define Tag_Joy_Device_Added            (13)
#define Tag_Joy_Device_Removed          (14)
#define Tag_Window_Event                (15)


static value Val_SDL_QuitEvent(SDL_QuitEvent * e) {
    CAMLparam0();
    CAMLlocal2(ret, rec);
    ret = caml_alloc(1, Tag_Quit);
    rec = caml_alloc(1, 0);
    Store_field(rec, 0, caml_copy_int32(e->timestamp));
    Store_field(ret, 0, rec);
    CAMLreturn(ret);
}


static inline value Val_state(Uint8 state)
{
    switch (state) {
    case SDL_RELEASED:  return Val_int(0);
    case SDL_PRESSED:   return Val_int(1);
    }
    caml_failwith("Keysym state");
}

static inline value Val_SDL_Keycode(SDL_Keycode kcode)
{
    switch (kcode) {
    case SDLK_UNKNOWN:                    return Val_int(0);
    case SDLK_RETURN:                     return Val_int(1);
    case SDLK_ESCAPE:                     return Val_int(2);
    case SDLK_BACKSPACE:                  return Val_int(3);
    case SDLK_TAB:                        return Val_int(4);
    case SDLK_SPACE:                      return Val_int(5);
    case SDLK_EXCLAIM:                    return Val_int(6);
    case SDLK_DBLAPOSTROPHE:                   return Val_int(7);
    case SDLK_HASH:                       return Val_int(8);
    case SDLK_PERCENT:                    return Val_int(9);
    case SDLK_DOLLAR:                     return Val_int(10);
    case SDLK_AMPERSAND:                  return Val_int(11);
    case SDLK_APOSTROPHE:                      return Val_int(12);
    case SDLK_LEFTPAREN:                  return Val_int(13);
    case SDLK_RIGHTPAREN:                 return Val_int(14);
    case SDLK_ASTERISK:                   return Val_int(15);
    case SDLK_PLUS:                       return Val_int(16);
    case SDLK_COMMA:                      return Val_int(17);
    case SDLK_MINUS:                      return Val_int(18);
    case SDLK_PERIOD:                     return Val_int(19);
    case SDLK_SLASH:                      return Val_int(20);
    case SDLK_0:                          return Val_int(21);
    case SDLK_1:                          return Val_int(22);
    case SDLK_2:                          return Val_int(23);
    case SDLK_3:                          return Val_int(24);
    case SDLK_4:                          return Val_int(25);
    case SDLK_5:                          return Val_int(26);
    case SDLK_6:                          return Val_int(27);
    case SDLK_7:                          return Val_int(28);
    case SDLK_8:                          return Val_int(29);
    case SDLK_9:                          return Val_int(30);
    case SDLK_COLON:                      return Val_int(31);
    case SDLK_SEMICOLON:                  return Val_int(32);
    case SDLK_LESS:                       return Val_int(33);
    case SDLK_EQUALS:                     return Val_int(34);
    case SDLK_GREATER:                    return Val_int(35);
    case SDLK_QUESTION:                   return Val_int(36);
    case SDLK_AT:                         return Val_int(37);
    case SDLK_LEFTBRACKET:                return Val_int(38);
    case SDLK_BACKSLASH:                  return Val_int(39);
    case SDLK_RIGHTBRACKET:               return Val_int(40);
    case SDLK_CARET:                      return Val_int(41);
    case SDLK_UNDERSCORE:                 return Val_int(42);
    case SDLK_GRAVE:                  return Val_int(43);
    case SDLK_A:                          return Val_int(44);
    case SDLK_B:                          return Val_int(45);
    case SDLK_C:                          return Val_int(46);
    case SDLK_D:                          return Val_int(47);
    case SDLK_E:                          return Val_int(48);
    case SDLK_F:                          return Val_int(49);
    case SDLK_G:                          return Val_int(50);
    case SDLK_H:                          return Val_int(51);
    case SDLK_I:                          return Val_int(52);
    case SDLK_J:                          return Val_int(53);
    case SDLK_K:                          return Val_int(54);
    case SDLK_L:                          return Val_int(55);
    case SDLK_M:                          return Val_int(56);
    case SDLK_N:                          return Val_int(57);
    case SDLK_O:                          return Val_int(58);
    case SDLK_P:                          return Val_int(59);
    case SDLK_Q:                          return Val_int(60);
    case SDLK_R:                          return Val_int(61);
    case SDLK_S:                          return Val_int(62);
    case SDLK_T:                          return Val_int(63);
    case SDLK_U:                          return Val_int(64);
    case SDLK_V:                          return Val_int(65);
    case SDLK_W:                          return Val_int(66);
    case SDLK_X:                          return Val_int(67);
    case SDLK_Y:                          return Val_int(68);
    case SDLK_Z:                          return Val_int(69);
    case SDLK_CAPSLOCK:                   return Val_int(70);
    case SDLK_F1:                         return Val_int(71);
    case SDLK_F2:                         return Val_int(72);
    case SDLK_F3:                         return Val_int(73);
    case SDLK_F4:                         return Val_int(74);
    case SDLK_F5:                         return Val_int(75);
    case SDLK_F6:                         return Val_int(76);
    case SDLK_F7:                         return Val_int(77);
    case SDLK_F8:                         return Val_int(78);
    case SDLK_F9:                         return Val_int(79);
    case SDLK_F10:                        return Val_int(80);
    case SDLK_F11:                        return Val_int(81);
    case SDLK_F12:                        return Val_int(82);
    case SDLK_PRINTSCREEN:                return Val_int(83);
    case SDLK_SCROLLLOCK:                 return Val_int(84);
    case SDLK_PAUSE:                      return Val_int(85);
    case SDLK_INSERT:                     return Val_int(86);
    case SDLK_HOME:                       return Val_int(87);
    case SDLK_PAGEUP:                     return Val_int(88);
    case SDLK_DELETE:                     return Val_int(89);
    case SDLK_END:                        return Val_int(90);
    case SDLK_PAGEDOWN:                   return Val_int(91);
    case SDLK_RIGHT:                      return Val_int(92);
    case SDLK_LEFT:                       return Val_int(93);
    case SDLK_DOWN:                       return Val_int(94);
    case SDLK_UP:                         return Val_int(95);
    case SDLK_NUMLOCKCLEAR:               return Val_int(96);
    case SDLK_KP_DIVIDE:                  return Val_int(97);
    case SDLK_KP_MULTIPLY:                return Val_int(98);
    case SDLK_KP_MINUS:                   return Val_int(99);
    case SDLK_KP_PLUS:                    return Val_int(100);
    case SDLK_KP_ENTER:                   return Val_int(101);
    case SDLK_KP_1:                       return Val_int(102);
    case SDLK_KP_2:                       return Val_int(103);
    case SDLK_KP_3:                       return Val_int(104);
    case SDLK_KP_4:                       return Val_int(105);
    case SDLK_KP_5:                       return Val_int(106);
    case SDLK_KP_6:                       return Val_int(107);
    case SDLK_KP_7:                       return Val_int(108);
    case SDLK_KP_8:                       return Val_int(109);
    case SDLK_KP_9:                       return Val_int(110);
    case SDLK_KP_0:                       return Val_int(111);
    case SDLK_KP_PERIOD:                  return Val_int(112);
    case SDLK_APPLICATION:                return Val_int(113);
    case SDLK_POWER:                      return Val_int(114);
    case SDLK_KP_EQUALS:                  return Val_int(115);
    case SDLK_F13:                        return Val_int(116);
    case SDLK_F14:                        return Val_int(117);
    case SDLK_F15:                        return Val_int(118);
    case SDLK_F16:                        return Val_int(119);
    case SDLK_F17:                        return Val_int(120);
    case SDLK_F18:                        return Val_int(121);
    case SDLK_F19:                        return Val_int(122);
    case SDLK_F20:                        return Val_int(123);
    case SDLK_F21:                        return Val_int(124);
    case SDLK_F22:                        return Val_int(125);
    case SDLK_F23:                        return Val_int(126);
    case SDLK_F24:                        return Val_int(127);
    case SDLK_EXECUTE:                    return Val_int(128);
    case SDLK_HELP:                       return Val_int(129);
    case SDLK_MENU:                       return Val_int(130);
    case SDLK_SELECT:                     return Val_int(131);
    case SDLK_STOP:                       return Val_int(132);
    case SDLK_AGAIN:                      return Val_int(133);
    case SDLK_UNDO:                       return Val_int(134);
    case SDLK_CUT:                        return Val_int(135);
    case SDLK_COPY:                       return Val_int(136);
    case SDLK_PASTE:                      return Val_int(137);
    case SDLK_FIND:                       return Val_int(138);
    case SDLK_MUTE:                       return Val_int(139);
    case SDLK_VOLUMEUP:                   return Val_int(140);
    case SDLK_VOLUMEDOWN:                 return Val_int(141);
    case SDLK_KP_COMMA:                   return Val_int(142);
    case SDLK_KP_EQUALSAS400:             return Val_int(143);
    case SDLK_ALTERASE:                   return Val_int(144);
    case SDLK_SYSREQ:                     return Val_int(145);
    case SDLK_CANCEL:                     return Val_int(146);
    case SDLK_CLEAR:                      return Val_int(147);
    case SDLK_PRIOR:                      return Val_int(148);
    case SDLK_RETURN2:                    return Val_int(149);
    case SDLK_SEPARATOR:                  return Val_int(150);
    case SDLK_OUT:                        return Val_int(151);
    case SDLK_OPER:                       return Val_int(152);
    case SDLK_CLEARAGAIN:                 return Val_int(153);
    case SDLK_CRSEL:                      return Val_int(154);
    case SDLK_EXSEL:                      return Val_int(155);
    case SDLK_KP_00:                      return Val_int(156);
    case SDLK_KP_000:                     return Val_int(157);
    case SDLK_THOUSANDSSEPARATOR:         return Val_int(158);
    case SDLK_DECIMALSEPARATOR:           return Val_int(159);
    case SDLK_CURRENCYUNIT:               return Val_int(160);
    case SDLK_CURRENCYSUBUNIT:            return Val_int(161);
    case SDLK_KP_LEFTPAREN:               return Val_int(162);
    case SDLK_KP_RIGHTPAREN:              return Val_int(163);
    case SDLK_KP_LEFTBRACE:               return Val_int(164);
    case SDLK_KP_RIGHTBRACE:              return Val_int(165);
    case SDLK_KP_TAB:                     return Val_int(166);
    case SDLK_KP_BACKSPACE:               return Val_int(167);
    case SDLK_KP_A:                       return Val_int(168);
    case SDLK_KP_B:                       return Val_int(169);
    case SDLK_KP_C:                       return Val_int(170);
    case SDLK_KP_D:                       return Val_int(171);
    case SDLK_KP_E:                       return Val_int(172);
    case SDLK_KP_F:                       return Val_int(173);
    case SDLK_KP_XOR:                     return Val_int(174);
    case SDLK_KP_POWER:                   return Val_int(175);
    case SDLK_KP_PERCENT:                 return Val_int(176);
    case SDLK_KP_LESS:                    return Val_int(177);
    case SDLK_KP_GREATER:                 return Val_int(178);
    case SDLK_KP_AMPERSAND:               return Val_int(179);
    case SDLK_KP_DBLAMPERSAND:            return Val_int(180);
    case SDLK_KP_VERTICALBAR:             return Val_int(181);
    case SDLK_KP_DBLVERTICALBAR:          return Val_int(182);
    case SDLK_KP_COLON:                   return Val_int(183);
    case SDLK_KP_HASH:                    return Val_int(184);
    case SDLK_KP_SPACE:                   return Val_int(185);
    case SDLK_KP_AT:                      return Val_int(186);
    case SDLK_KP_EXCLAM:                  return Val_int(187);
    case SDLK_KP_MEMSTORE:                return Val_int(188);
    case SDLK_KP_MEMRECALL:               return Val_int(189);
    case SDLK_KP_MEMCLEAR:                return Val_int(190);
    case SDLK_KP_MEMADD:                  return Val_int(191);
    case SDLK_KP_MEMSUBTRACT:             return Val_int(192);
    case SDLK_KP_MEMMULTIPLY:             return Val_int(193);
    case SDLK_KP_MEMDIVIDE:               return Val_int(194);
    case SDLK_KP_PLUSMINUS:               return Val_int(195);
    case SDLK_KP_CLEAR:                   return Val_int(196);
    case SDLK_KP_CLEARENTRY:              return Val_int(197);
    case SDLK_KP_BINARY:                  return Val_int(198);
    case SDLK_KP_OCTAL:                   return Val_int(199);
    case SDLK_KP_DECIMAL:                 return Val_int(200);
    case SDLK_KP_HEXADECIMAL:             return Val_int(201);
    case SDLK_LCTRL:                      return Val_int(202);
    case SDLK_LSHIFT:                     return Val_int(203);
    case SDLK_LALT:                       return Val_int(204);
    case SDLK_LGUI:                       return Val_int(205);
    case SDLK_RCTRL:                      return Val_int(206);
    case SDLK_RSHIFT:                     return Val_int(207);
    case SDLK_RALT:                       return Val_int(208);
    case SDLK_RGUI:                       return Val_int(209);
    case SDLK_MODE:                       return Val_int(210);
    case SDLK_MEDIA_NEXT_TRACK:                  return Val_int(211);
    case SDLK_MEDIA_PREVIOUS_TRACK:                  return Val_int(212);
    case SDLK_MEDIA_STOP:                  return Val_int(213);
    case SDLK_MEDIA_PLAY:                  return Val_int(214);
    case SDLK_MUTE:                  return Val_int(215);
    case SDLK_MEDIA_SELECT:                return Val_int(216);
    case SDLK_WWW:                        return Val_int(217);
    case SDLK_MAIL:                       return Val_int(218);
    case SDLK_CALCULATOR:                 return Val_int(219);
    case SDLK_COMPUTER:                   return Val_int(220);
    case SDLK_AC_SEARCH:                  return Val_int(221);
    case SDLK_AC_HOME:                    return Val_int(222);
    case SDLK_AC_BACK:                    return Val_int(223);
    case SDLK_AC_FORWARD:                 return Val_int(224);
    case SDLK_AC_STOP:                    return Val_int(225);
    case SDLK_AC_REFRESH:                 return Val_int(226);
    case SDLK_AC_BOOKMARKS:               return Val_int(227);
    case SDLK_BRIGHTNESSDOWN:             return Val_int(228);
    case SDLK_BRIGHTNESSUP:               return Val_int(229);
    case SDLK_DISPLAYSWITCH:              return Val_int(230);
    case SDLK_KBDILLUMTOGGLE:             return Val_int(231);
    case SDLK_KBDILLUMDOWN:               return Val_int(232);
    case SDLK_KBDILLUMUP:                 return Val_int(233);
    case SDLK_MEDIA_EJECT:                      return Val_int(234);
    case SDLK_SLEEP:                      return Val_int(235);
    }
    return Val_int(0);
}

static inline value Val_SDL_Scancode(SDL_Scancode scancode)
{
    switch (scancode) {
    case SDL_SCANCODE_UNKNOWN:            return Val_int(0);
    case SDL_SCANCODE_A:                  return Val_int(1);
    case SDL_SCANCODE_B:                  return Val_int(2);
    case SDL_SCANCODE_C:                  return Val_int(3);
    case SDL_SCANCODE_D:                  return Val_int(4);
    case SDL_SCANCODE_E:                  return Val_int(5);
    case SDL_SCANCODE_F:                  return Val_int(6);
    case SDL_SCANCODE_G:                  return Val_int(7);
    case SDL_SCANCODE_H:                  return Val_int(8);
    case SDL_SCANCODE_I:                  return Val_int(9);
    case SDL_SCANCODE_J:                  return Val_int(10);
    case SDL_SCANCODE_K:                  return Val_int(11);
    case SDL_SCANCODE_L:                  return Val_int(12);
    case SDL_SCANCODE_M:                  return Val_int(13);
    case SDL_SCANCODE_N:                  return Val_int(14);
    case SDL_SCANCODE_O:                  return Val_int(15);
    case SDL_SCANCODE_P:                  return Val_int(16);
    case SDL_SCANCODE_Q:                  return Val_int(17);
    case SDL_SCANCODE_R:                  return Val_int(18);
    case SDL_SCANCODE_S:                  return Val_int(19);
    case SDL_SCANCODE_T:                  return Val_int(20);
    case SDL_SCANCODE_U:                  return Val_int(21);
    case SDL_SCANCODE_V:                  return Val_int(22);
    case SDL_SCANCODE_W:                  return Val_int(23);
    case SDL_SCANCODE_X:                  return Val_int(24);
    case SDL_SCANCODE_Y:                  return Val_int(25);
    case SDL_SCANCODE_Z:                  return Val_int(26);
    case SDL_SCANCODE_1:                  return Val_int(27);
    case SDL_SCANCODE_2:                  return Val_int(28);
    case SDL_SCANCODE_3:                  return Val_int(29);
    case SDL_SCANCODE_4:                  return Val_int(30);
    case SDL_SCANCODE_5:                  return Val_int(31);
    case SDL_SCANCODE_6:                  return Val_int(32);
    case SDL_SCANCODE_7:                  return Val_int(33);
    case SDL_SCANCODE_8:                  return Val_int(34);
    case SDL_SCANCODE_9:                  return Val_int(35);
    case SDL_SCANCODE_0:                  return Val_int(36);
    case SDL_SCANCODE_RETURN:             return Val_int(37);
    case SDL_SCANCODE_ESCAPE:             return Val_int(38);
    case SDL_SCANCODE_BACKSPACE:          return Val_int(39);
    case SDL_SCANCODE_TAB:                return Val_int(40);
    case SDL_SCANCODE_SPACE:              return Val_int(41);
    case SDL_SCANCODE_MINUS:              return Val_int(42);
    case SDL_SCANCODE_EQUALS:             return Val_int(43);
    case SDL_SCANCODE_LEFTBRACKET:        return Val_int(44);
    case SDL_SCANCODE_RIGHTBRACKET:       return Val_int(45);
    case SDL_SCANCODE_BACKSLASH:          return Val_int(46);
    case SDL_SCANCODE_NONUSHASH:          return Val_int(47);
    case SDL_SCANCODE_SEMICOLON:          return Val_int(48);
    case SDL_SCANCODE_APOSTROPHE:         return Val_int(49);
    case SDL_SCANCODE_GRAVE:              return Val_int(50);
    case SDL_SCANCODE_COMMA:              return Val_int(51);
    case SDL_SCANCODE_PERIOD:             return Val_int(52);
    case SDL_SCANCODE_SLASH:              return Val_int(53);
    case SDL_SCANCODE_CAPSLOCK:           return Val_int(54);
    case SDL_SCANCODE_F1:                 return Val_int(55);
    case SDL_SCANCODE_F2:                 return Val_int(56);
    case SDL_SCANCODE_F3:                 return Val_int(57);
    case SDL_SCANCODE_F4:                 return Val_int(58);
    case SDL_SCANCODE_F5:                 return Val_int(59);
    case SDL_SCANCODE_F6:                 return Val_int(60);
    case SDL_SCANCODE_F7:                 return Val_int(61);
    case SDL_SCANCODE_F8:                 return Val_int(62);
    case SDL_SCANCODE_F9:                 return Val_int(63);
    case SDL_SCANCODE_F10:                return Val_int(64);
    case SDL_SCANCODE_F11:                return Val_int(65);
    case SDL_SCANCODE_F12:                return Val_int(66);
    case SDL_SCANCODE_PRINTSCREEN:        return Val_int(67);
    case SDL_SCANCODE_SCROLLLOCK:         return Val_int(68);
    case SDL_SCANCODE_PAUSE:              return Val_int(69);
    case SDL_SCANCODE_INSERT:             return Val_int(70);
    case SDL_SCANCODE_HOME:               return Val_int(71);
    case SDL_SCANCODE_PAGEUP:             return Val_int(72);
    case SDL_SCANCODE_DELETE:             return Val_int(73);
    case SDL_SCANCODE_END:                return Val_int(74);
    case SDL_SCANCODE_PAGEDOWN:           return Val_int(75);
    case SDL_SCANCODE_RIGHT:              return Val_int(76);
    case SDL_SCANCODE_LEFT:               return Val_int(77);
    case SDL_SCANCODE_DOWN:               return Val_int(78);
    case SDL_SCANCODE_UP:                 return Val_int(79);
    case SDL_SCANCODE_NUMLOCKCLEAR:       return Val_int(80);
    case SDL_SCANCODE_KP_DIVIDE:          return Val_int(81);
    case SDL_SCANCODE_KP_MULTIPLY:        return Val_int(82);
    case SDL_SCANCODE_KP_MINUS:           return Val_int(83);
    case SDL_SCANCODE_KP_PLUS:            return Val_int(84);
    case SDL_SCANCODE_KP_ENTER:           return Val_int(85);
    case SDL_SCANCODE_KP_1:               return Val_int(86);
    case SDL_SCANCODE_KP_2:               return Val_int(87);
    case SDL_SCANCODE_KP_3:               return Val_int(88);
    case SDL_SCANCODE_KP_4:               return Val_int(89);
    case SDL_SCANCODE_KP_5:               return Val_int(90);
    case SDL_SCANCODE_KP_6:               return Val_int(91);
    case SDL_SCANCODE_KP_7:               return Val_int(92);
    case SDL_SCANCODE_KP_8:               return Val_int(93);
    case SDL_SCANCODE_KP_9:               return Val_int(94);
    case SDL_SCANCODE_KP_0:               return Val_int(95);
    case SDL_SCANCODE_KP_PERIOD:          return Val_int(96);
    case SDL_SCANCODE_NONUSBACKSLASH:     return Val_int(97);
    case SDL_SCANCODE_APPLICATION:        return Val_int(98);
    case SDL_SCANCODE_POWER:              return Val_int(99);
    case SDL_SCANCODE_KP_EQUALS:          return Val_int(100);
    case SDL_SCANCODE_F13:                return Val_int(101);
    case SDL_SCANCODE_F14:                return Val_int(102);
    case SDL_SCANCODE_F15:                return Val_int(103);
    case SDL_SCANCODE_F16:                return Val_int(104);
    case SDL_SCANCODE_F17:                return Val_int(105);
    case SDL_SCANCODE_F18:                return Val_int(106);
    case SDL_SCANCODE_F19:                return Val_int(107);
    case SDL_SCANCODE_F20:                return Val_int(108);
    case SDL_SCANCODE_F21:                return Val_int(109);
    case SDL_SCANCODE_F22:                return Val_int(110);
    case SDL_SCANCODE_F23:                return Val_int(111);
    case SDL_SCANCODE_F24:                return Val_int(112);
    case SDL_SCANCODE_EXECUTE:            return Val_int(113);
    case SDL_SCANCODE_HELP:               return Val_int(114);
    case SDL_SCANCODE_MENU:               return Val_int(115);
    case SDL_SCANCODE_SELECT:             return Val_int(116);
    case SDL_SCANCODE_STOP:               return Val_int(117);
    case SDL_SCANCODE_AGAIN:              return Val_int(118);
    case SDL_SCANCODE_UNDO:               return Val_int(119);
    case SDL_SCANCODE_CUT:                return Val_int(120);
    case SDL_SCANCODE_COPY:               return Val_int(121);
    case SDL_SCANCODE_PASTE:              return Val_int(122);
    case SDL_SCANCODE_FIND:               return Val_int(123);
    case SDL_SCANCODE_MUTE:               return Val_int(124);
    case SDL_SCANCODE_VOLUMEUP:           return Val_int(125);
    case SDL_SCANCODE_VOLUMEDOWN:         return Val_int(126);
    case SDL_SCANCODE_KP_COMMA:           return Val_int(127);
    case SDL_SCANCODE_KP_EQUALSAS400:     return Val_int(128);
    case SDL_SCANCODE_INTERNATIONAL1:     return Val_int(129);
    case SDL_SCANCODE_INTERNATIONAL2:     return Val_int(130);
    case SDL_SCANCODE_INTERNATIONAL3:     return Val_int(131);
    case SDL_SCANCODE_INTERNATIONAL4:     return Val_int(132);
    case SDL_SCANCODE_INTERNATIONAL5:     return Val_int(133);
    case SDL_SCANCODE_INTERNATIONAL6:     return Val_int(134);
    case SDL_SCANCODE_INTERNATIONAL7:     return Val_int(135);
    case SDL_SCANCODE_INTERNATIONAL8:     return Val_int(136);
    case SDL_SCANCODE_INTERNATIONAL9:     return Val_int(137);
    case SDL_SCANCODE_LANG1:              return Val_int(138);
    case SDL_SCANCODE_LANG2:              return Val_int(139);
    case SDL_SCANCODE_LANG3:              return Val_int(140);
    case SDL_SCANCODE_LANG4:              return Val_int(141);
    case SDL_SCANCODE_LANG5:              return Val_int(142);
    case SDL_SCANCODE_LANG6:              return Val_int(143);
    case SDL_SCANCODE_LANG7:              return Val_int(144);
    case SDL_SCANCODE_LANG8:              return Val_int(145);
    case SDL_SCANCODE_LANG9:              return Val_int(146);
    case SDL_SCANCODE_ALTERASE:           return Val_int(147);
    case SDL_SCANCODE_SYSREQ:             return Val_int(148);
    case SDL_SCANCODE_CANCEL:             return Val_int(149);
    case SDL_SCANCODE_CLEAR:              return Val_int(150);
    case SDL_SCANCODE_PRIOR:              return Val_int(151);
    case SDL_SCANCODE_RETURN2:            return Val_int(152);
    case SDL_SCANCODE_SEPARATOR:          return Val_int(153);
    case SDL_SCANCODE_OUT:                return Val_int(154);
    case SDL_SCANCODE_OPER:               return Val_int(155);
    case SDL_SCANCODE_CLEARAGAIN:         return Val_int(156);
    case SDL_SCANCODE_CRSEL:              return Val_int(157);
    case SDL_SCANCODE_EXSEL:              return Val_int(158);
    case SDL_SCANCODE_KP_00:              return Val_int(159);
    case SDL_SCANCODE_KP_000:             return Val_int(160);
    case SDL_SCANCODE_THOUSANDSSEPARATOR: return Val_int(161);
    case SDL_SCANCODE_DECIMALSEPARATOR:   return Val_int(162);
    case SDL_SCANCODE_CURRENCYUNIT:       return Val_int(163);
    case SDL_SCANCODE_CURRENCYSUBUNIT:    return Val_int(164);
    case SDL_SCANCODE_KP_LEFTPAREN:       return Val_int(165);
    case SDL_SCANCODE_KP_RIGHTPAREN:      return Val_int(166);
    case SDL_SCANCODE_KP_LEFTBRACE:       return Val_int(167);
    case SDL_SCANCODE_KP_RIGHTBRACE:      return Val_int(168);
    case SDL_SCANCODE_KP_TAB:             return Val_int(169);
    case SDL_SCANCODE_KP_BACKSPACE:       return Val_int(170);
    case SDL_SCANCODE_KP_A:               return Val_int(171);
    case SDL_SCANCODE_KP_B:               return Val_int(172);
    case SDL_SCANCODE_KP_C:               return Val_int(173);
    case SDL_SCANCODE_KP_D:               return Val_int(174);
    case SDL_SCANCODE_KP_E:               return Val_int(175);
    case SDL_SCANCODE_KP_F:               return Val_int(176);
    case SDL_SCANCODE_KP_XOR:             return Val_int(177);
    case SDL_SCANCODE_KP_POWER:           return Val_int(178);
    case SDL_SCANCODE_KP_PERCENT:         return Val_int(179);
    case SDL_SCANCODE_KP_LESS:            return Val_int(180);
    case SDL_SCANCODE_KP_GREATER:         return Val_int(181);
    case SDL_SCANCODE_KP_AMPERSAND:       return Val_int(182);
    case SDL_SCANCODE_KP_DBLAMPERSAND:    return Val_int(183);
    case SDL_SCANCODE_KP_VERTICALBAR:     return Val_int(184);
    case SDL_SCANCODE_KP_DBLVERTICALBAR:  return Val_int(185);
    case SDL_SCANCODE_KP_COLON:           return Val_int(186);
    case SDL_SCANCODE_KP_HASH:            return Val_int(187);
    case SDL_SCANCODE_KP_SPACE:           return Val_int(188);
    case SDL_SCANCODE_KP_AT:              return Val_int(189);
    case SDL_SCANCODE_KP_EXCLAM:          return Val_int(190);
    case SDL_SCANCODE_KP_MEMSTORE:        return Val_int(191);
    case SDL_SCANCODE_KP_MEMRECALL:       return Val_int(192);
    case SDL_SCANCODE_KP_MEMCLEAR:        return Val_int(193);
    case SDL_SCANCODE_KP_MEMADD:          return Val_int(194);
    case SDL_SCANCODE_KP_MEMSUBTRACT:     return Val_int(195);
    case SDL_SCANCODE_KP_MEMMULTIPLY:     return Val_int(196);
    case SDL_SCANCODE_KP_MEMDIVIDE:       return Val_int(197);
    case SDL_SCANCODE_KP_PLUSMINUS:       return Val_int(198);
    case SDL_SCANCODE_KP_CLEAR:           return Val_int(199);
    case SDL_SCANCODE_KP_CLEARENTRY:      return Val_int(200);
    case SDL_SCANCODE_KP_BINARY:          return Val_int(201);
    case SDL_SCANCODE_KP_OCTAL:           return Val_int(202);
    case SDL_SCANCODE_KP_DECIMAL:         return Val_int(203);
    case SDL_SCANCODE_KP_HEXADECIMAL:     return Val_int(204);
    case SDL_SCANCODE_LCTRL:              return Val_int(205);
    case SDL_SCANCODE_LSHIFT:             return Val_int(206);
    case SDL_SCANCODE_LALT:               return Val_int(207);
    case SDL_SCANCODE_LGUI:               return Val_int(208);
    case SDL_SCANCODE_RCTRL:              return Val_int(209);
    case SDL_SCANCODE_RSHIFT:             return Val_int(210);
    case SDL_SCANCODE_RALT:               return Val_int(211);
    case SDL_SCANCODE_RGUI:               return Val_int(212);
    case SDL_SCANCODE_MODE:               return Val_int(213);
    case SDL_SCANCODE_MEDIA_NEXT_TRACK:          return Val_int(214);
    case SDL_SCANCODE_MEDIA_PREVIOUS_TRACK:          return Val_int(215);
    case SDL_SCANCODE_MEDIA_STOP:          return Val_int(216);
    case SDL_SCANCODE_MEDIA_PLAY:          return Val_int(217);
    case SDL_SCANCODE_MUTE:          return Val_int(218);
    case SDL_SCANCODE_MEDIA_SELECT:        return Val_int(219);
    case SDL_SCANCODE_WWW:                return Val_int(220);
    case SDL_SCANCODE_MAIL:               return Val_int(221);
    case SDL_SCANCODE_CALCULATOR:         return Val_int(222);
    case SDL_SCANCODE_COMPUTER:           return Val_int(223);
    case SDL_SCANCODE_AC_SEARCH:          return Val_int(224);
    case SDL_SCANCODE_AC_HOME:            return Val_int(225);
    case SDL_SCANCODE_AC_BACK:            return Val_int(226);
    case SDL_SCANCODE_AC_FORWARD:         return Val_int(227);
    case SDL_SCANCODE_AC_STOP:            return Val_int(228);
    case SDL_SCANCODE_AC_REFRESH:         return Val_int(229);
    case SDL_SCANCODE_AC_BOOKMARKS:       return Val_int(230);
    case SDL_SCANCODE_BRIGHTNESSDOWN:     return Val_int(231);
    case SDL_SCANCODE_BRIGHTNESSUP:       return Val_int(232);
    case SDL_SCANCODE_DISPLAYSWITCH:      return Val_int(233);
    case SDL_SCANCODE_KBDILLUMTOGGLE:     return Val_int(234);
    case SDL_SCANCODE_KBDILLUMDOWN:       return Val_int(235);
    case SDL_SCANCODE_KBDILLUMUP:         return Val_int(236);
    case SDL_SCANCODE_MEDIA_EJECT:              return Val_int(237);
    case SDL_SCANCODE_SLEEP:              return Val_int(238);
    case SDL_SCANCODE_COUNT:               return Val_int(239);
    case SDL_SCANCODE_APP1:               return Val_int(240);
    case SDL_SCANCODE_APP2:               return Val_int(241);
    }
    return Val_int(0);
}

static inline value
Val_SDL_KeyboardEvent(SDL_KeyboardEvent * e, int tag)
{
    CAMLparam0();
    CAMLlocal2(ret, rec);
    SDL_Keysym *keysym = &(e->keysym);
    ret = caml_alloc(1, tag);
    rec = caml_alloc(7, 0);
    Store_field(rec, 0, caml_copy_int32(e->timestamp));
    Store_field(rec, 1, caml_copy_int32(e->windowID));
    Store_field(rec, 2, Val_state(e->state));
    Store_field(rec, 3, Val_int(e->repeat));
    Store_field(rec, 4, Val_SDL_Scancode(keysym->scancode));
    Store_field(rec, 5, Val_SDL_Keycode(keysym->sym));
    Store_field(rec, 6, Val_SDL_Keymod(keysym->mod));
    Store_field(ret, 0, rec);
    CAMLreturn(ret);
}

#define Val_SDL_KeyDown(ev)  Val_SDL_KeyboardEvent(ev, Tag_KeyDown)
#define Val_SDL_KeyUp(ev)    Val_SDL_KeyboardEvent(ev, Tag_KeyUp  )


static value
Val_MouseMotionState(Uint8 buttons_mask)
{
    CAMLparam0();
    CAMLlocal2(li, cons);
    li = Val_emptylist;
    int i;
    for (i = 7; i >= 0; --i) {
        if ((buttons_mask >> i) & 1) {
            cons = caml_alloc_small(2, 0);
            Store_field(cons, 0, Val_int(i+1));
            Store_field(cons, 1, li);
            li = cons;
        }
    }
    CAMLreturn(li);
}

static inline value
Val_SDL_MouseMotionEvent(SDL_MouseMotionEvent * e)
{
    CAMLparam0();
    CAMLlocal2(ret, rec);
    ret = caml_alloc(1, Tag_Mouse_Motion);
    rec = caml_alloc(7, 0);
    Store_field(rec, 0, caml_copy_int32(e->timestamp));
    Store_field(rec, 1, caml_copy_int32(e->windowID));
    Store_field(rec, 2, Val_MouseMotionState(e->state));
    Store_field(rec, 3, Val_int(e->x));
    Store_field(rec, 4, Val_int(e->y));
    Store_field(rec, 5, Val_int(e->xrel));
    Store_field(rec, 6, Val_int(e->yrel));
    Store_field(ret, 0, rec);
    CAMLreturn(ret);
}

static inline value
Val_SDL_MouseButtonEvent(SDL_MouseButtonEvent * e, int tag)
{
    CAMLparam0();
    CAMLlocal2(ret, rec);
    ret = caml_alloc(1, tag);
    rec = caml_alloc(6, 0);
    Store_field(rec, 0, caml_copy_int32(e->timestamp));
    Store_field(rec, 1, caml_copy_int32(e->windowID));
    Store_field(rec, 2, Val_int(e->button));
    Store_field(rec, 3, Val_state(e->state));
    Store_field(rec, 4, Val_int(e->x));
    Store_field(rec, 5, Val_int(e->y));
    Store_field(ret, 0, rec);
    CAMLreturn(ret);
}

#define Val_SDL_MouseButtonDown(ev) Val_SDL_MouseButtonEvent(ev, Tag_Mouse_Button_Down)
#define Val_SDL_MouseButtonUp(ev)   Val_SDL_MouseButtonEvent(ev, Tag_Mouse_Button_Up)


static inline value
Val_SDL_MouseWheelEvent(SDL_MouseWheelEvent * e)
{
    CAMLparam0();
    CAMLlocal2(ret, rec);
    ret = caml_alloc(1, Tag_Mouse_Wheel);
    rec = caml_alloc(4, 0);
    Store_field(rec, 0, caml_copy_int32(e->timestamp));
    Store_field(rec, 1, caml_copy_int32(e->windowID));
    Store_field(rec, 2, Val_int(e->x));
    Store_field(rec, 3, Val_int(e->y));
    Store_field(ret, 0, rec);
    CAMLreturn(ret);
}

static inline value
Val_SDL_JoyAxisEvent(SDL_JoyAxisEvent * e)
{
    CAMLparam0();
    CAMLlocal2(ret, rec);
    ret = caml_alloc(1, Tag_Joy_Axis_Motion);
    rec = caml_alloc(4, 0);
    Store_field(rec, 0, caml_copy_int32(e->timestamp));
    Store_field(rec, 1, Val_int(e->which));
    Store_field(rec, 2, Val_int(e->axis));
    Store_field(rec, 3, Val_int(e->value));
    Store_field(ret, 0, rec);
    CAMLreturn(ret);
}

static inline value
Val_SDL_JoyButtonEvent(SDL_JoyButtonEvent * e, int tag)
{
    CAMLparam0();
    CAMLlocal2(ret, rec);
    ret = caml_alloc(1, tag);
    rec = caml_alloc(4, 0);
    Store_field(rec, 0, caml_copy_int32(e->timestamp));
    Store_field(rec, 1, Val_int(e->which));
    Store_field(rec, 2, Val_int(e->button));
    Store_field(rec, 3, Val_state(e->state));
    Store_field(ret, 0, rec);
    CAMLreturn(ret);
}

#define Val_SDL_JoyButtonDown(ev) Val_SDL_JoyButtonEvent(ev, Tag_Joy_Button_Down)
#define Val_SDL_JoyButtonUp(ev)   Val_SDL_JoyButtonEvent(ev, Tag_Joy_Button_Up)


#define Val_SDL_HAT_CENTERED        Val_int(0)
#define Val_SDL_HAT_UP              Val_int(1)
#define Val_SDL_HAT_RIGHT           Val_int(2)
#define Val_SDL_HAT_DOWN            Val_int(3)
#define Val_SDL_HAT_LEFT            Val_int(4)
#define Val_SDL_HAT_RIGHTUP         Val_int(5)
#define Val_SDL_HAT_RIGHTDOWN       Val_int(6)
#define Val_SDL_HAT_LEFTUP          Val_int(7)
#define Val_SDL_HAT_LEFTDOWN        Val_int(8)

#define Val_hat_position(b, ret) \
  do{ \
    ret = caml_alloc(4, 0); \
    Store_field(ret, 0, Val_bool(0 != ((b) & SDL_HAT_LEFT))); \
    Store_field(ret, 1, Val_bool(0 != ((b) & SDL_HAT_RIGHT))); \
    Store_field(ret, 2, Val_bool(0 != ((b) & SDL_HAT_UP))); \
    Store_field(ret, 3, Val_bool(0 != ((b) & SDL_HAT_DOWN))); \
  }while(0)

static value
Val_direction(Uint8 b)
{
    switch (b)
    {
    case SDL_HAT_CENTERED:  return Val_SDL_HAT_CENTERED;
    case SDL_HAT_UP:        return Val_SDL_HAT_UP;
    case SDL_HAT_RIGHT:     return Val_SDL_HAT_RIGHT;
    case SDL_HAT_DOWN:      return Val_SDL_HAT_DOWN;
    case SDL_HAT_LEFT:      return Val_SDL_HAT_LEFT;
    case SDL_HAT_RIGHTUP:   return Val_SDL_HAT_RIGHTUP;
    case SDL_HAT_RIGHTDOWN: return Val_SDL_HAT_RIGHTDOWN;
    case SDL_HAT_LEFTUP:    return Val_SDL_HAT_LEFTUP;
    case SDL_HAT_LEFTDOWN:  return Val_SDL_HAT_LEFTDOWN;
    }
    caml_failwith("JoyHat direction");
    return 0;
}

static inline value
Val_SDL_JoyHatEvent(SDL_JoyHatEvent * e)
{
    CAMLparam0();
    CAMLlocal3(ret, rec, hat_pos);
    Val_hat_position(e->value, hat_pos);
    ret = caml_alloc(1, Tag_Joy_Hat_Motion);
    rec = caml_alloc(5, 0);
    Store_field(rec, 0, caml_copy_int32(e->timestamp));
    Store_field(rec, 1, Val_int(e->which));
    Store_field(rec, 2, Val_int(e->hat));
    Store_field(rec, 3, Val_direction(e->value));
    Store_field(rec, 4, hat_pos);
    Store_field(ret, 0, rec);
    CAMLreturn(ret);
}

static inline value Val_SDL_JoyDevice(Uint32 type)
{
    switch (type) {
    case SDL_EVENT_JOYSTICK_ADDED:    return Val_int(0);
    case SDL_EVENT_JOYSTICK_REMOVED:  return Val_int(1);
    }
    caml_failwith("joy_device_change");
}

static inline value
Val_SDL_JoyDeviceEvent(SDL_JoyDeviceEvent * e, int tag)
{
    CAMLparam0();
    CAMLlocal2(ret, rec);
    ret = caml_alloc(1, tag);
    rec = caml_alloc(3, 0);
    Store_field(rec, 0, caml_copy_int32(e->timestamp));
    Store_field(rec, 1, Val_int(e->which));
    Store_field(rec, 2, Val_SDL_JoyDevice(e->type));
    Store_field(ret, 0, rec);
    CAMLreturn(ret);
}

#define Val_SDL_JoyDeviceAdded(ev)    Val_SDL_JoyDeviceEvent(ev, Tag_Joy_Device_Added)
#define Val_SDL_JoyDeviceRemoved(ev)  Val_SDL_JoyDeviceEvent(ev, Tag_Joy_Device_Removed)


#define Val_WindowEvent_None            Val_int(0)
#define Val_WindowEvent_Shown           Val_int(1)
#define Val_WindowEvent_Hidden          Val_int(2)
#define Val_WindowEvent_Exposed         Val_int(3)
#define Val_WindowEvent_Minimized       Val_int(4)
#define Val_WindowEvent_Maximized       Val_int(5)
#define Val_WindowEvent_Restored        Val_int(6)
#define Val_WindowEvent_Enter           Val_int(7)
#define Val_WindowEvent_Leave           Val_int(8)
#define Val_WindowEvent_Focus_Gained    Val_int(9)
#define Val_WindowEvent_Focus_Lost      Val_int(10)
#define Val_WindowEvent_Close           Val_int(11)
#define Val_WindowEvent_Take_Focus      Val_int(12)
#define Val_WindowEvent_Hit_Test        Val_int(13)

#define Tag_WindowEvent_Moved           (0)
#define Tag_WindowEvent_Resized         (1)
#define Tag_WindowEvent_Size_Changed    (2)

static inline value
Val_WindowEvent_XY(SDL_WindowEvent * e, int tag)
{
    CAMLparam0();
    CAMLlocal2(ret, rec);
    ret = caml_alloc(1, tag);
    rec = caml_alloc(2, 0);
    Store_field(rec, 0, Val_int(e->data1));
    Store_field(rec, 1, Val_int(e->data2));
    Store_field(ret, 0, rec);
    CAMLreturn(ret);
}

#define Val_WindowEvent_Moved(e)   Val_WindowEvent_XY(e,Tag_WindowEvent_Moved)
#define Val_WindowEvent_Resized(e) Val_WindowEvent_XY(e,Tag_WindowEvent_Resized)
#define Val_WindowEvent_Resized(e) Val_WindowEvent_XY(e,Tag_WindowEvent_Resized)

static inline value
Val_WindowEvent_Kind(SDL_WindowEvent * e)
{
    switch (e->event) {
    case SDL_WINDOWEVENT_NONE:          return Val_WindowEvent_None;
    case SDL_EVENT_WINDOW_SHOWN:         return Val_WindowEvent_Shown;
    case SDL_EVENT_WINDOW_HIDDEN:        return Val_WindowEvent_Hidden;
    case SDL_EVENT_WINDOW_EXPOSED:       return Val_WindowEvent_Exposed;
    case SDL_EVENT_WINDOW_MOVED:         return Val_WindowEvent_Moved(e);
    case SDL_EVENT_WINDOW_RESIZED:       return Val_WindowEvent_Resized(e);
    case SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED:  return Val_WindowEvent_Resized(e);
    case SDL_EVENT_WINDOW_MINIMIZED:     return Val_WindowEvent_Minimized;
    case SDL_EVENT_WINDOW_MAXIMIZED:     return Val_WindowEvent_Maximized;
    case SDL_EVENT_WINDOW_RESTORED:      return Val_WindowEvent_Restored;
    case SDL_EVENT_WINDOW_MOUSE_ENTER:         return Val_WindowEvent_Enter;
    case SDL_EVENT_WINDOW_MOUSE_LEAVE:         return Val_WindowEvent_Leave;
    case SDL_EVENT_WINDOW_FOCUS_GAINED:  return Val_WindowEvent_Focus_Gained;
    case SDL_EVENT_WINDOW_FOCUS_LOST:    return Val_WindowEvent_Focus_Lost;
    case SDL_EVENT_WINDOW_CLOSE_REQUESTED:         return Val_WindowEvent_Close;
    case SDL_WINDOWEVENT_TAKE_FOCUS:    return Val_WindowEvent_Take_Focus;
    case SDL_EVENT_WINDOW_HIT_TEST:      return Val_WindowEvent_Hit_Test;

    default:
        caml_failwith("window_event_kind");
    }
}

static inline value
Val_SDL_WindowEvent(SDL_WindowEvent * e)
{
    CAMLparam0();
    CAMLlocal2(ret, rec);
    ret = caml_alloc(1, Tag_Window_Event);
    rec = caml_alloc(3, 0);
    Store_field(rec, 0, caml_copy_int32(e->timestamp));
    Store_field(rec, 1, caml_copy_int32(e->windowID));
    Store_field(rec, 2, Val_WindowEvent_Kind(e));
    Store_field(ret, 0, rec);
    CAMLreturn(ret);
}

static inline value
Val_SDL_TextEditingEvent(SDL_TextEditingEvent * e)
{
    CAMLparam0();
    CAMLlocal2(ret, rec);
    ret = caml_alloc(1, Tag_Text_Editing);
    rec = caml_alloc(5, 0);
    Store_field(rec, 0, caml_copy_int32(e->timestamp));
    Store_field(rec, 1, caml_copy_int32(e->windowID));
    Store_field(rec, 2, caml_copy_string(e->text));
    Store_field(rec, 3, Val_int(e->start));
    Store_field(rec, 4, Val_int(e->length));
    Store_field(ret, 0, rec);
    CAMLreturn(ret);
}

static inline value
Val_SDL_TextInputEvent(SDL_TextInputEvent * e)
{
    CAMLparam0();
    CAMLlocal2(ret, rec);
    ret = caml_alloc(1, Tag_Text_Input);
    rec = caml_alloc(3, 0);
    Store_field(rec, 0, caml_copy_int32(e->timestamp));
    Store_field(rec, 1, caml_copy_int32(e->windowID));
    Store_field(rec, 2, caml_copy_string(e->text));
    Store_field(ret, 0, rec);
    CAMLreturn(ret);
}

static inline value
Val_SDL_Event(SDL_Event * event)
{
    switch (event->type)
    {
    case SDL_EVENT_MOUSE_MOTION:       return Val_SDL_MouseMotionEvent(&(event->motion));
    case SDL_EVENT_MOUSE_BUTTON_DOWN:   return Val_SDL_MouseButtonDown(&(event->button));
    case SDL_EVENT_MOUSE_BUTTON_UP:     return Val_SDL_MouseButtonUp(&(event->button));
    case SDL_EVENT_MOUSE_WHEEL:        return Val_SDL_MouseWheelEvent(&(event->wheel));
    case SDL_EVENT_KEY_DOWN:           return Val_SDL_KeyDown(&(event->key));
    case SDL_EVENT_KEY_UP:             return Val_SDL_KeyUp(&(event->key));
    case SDL_EVENT_TEXT_EDITING:       return Val_SDL_TextEditingEvent(&(event->edit));
    case SDL_EVENT_TEXT_INPUT:         return Val_SDL_TextInputEvent(&(event->text));
    case SDL_EVENT_JOYSTICK_AXIS_MOTION:     return Val_SDL_JoyAxisEvent(&(event->jaxis));
    case SDL_EVENT_JOYSTICK_BALL_MOTION:     return Val_Joy_Ball_Motion;
    case SDL_EVENT_JOYSTICK_HAT_MOTION:      return Val_SDL_JoyHatEvent(&(event->jhat));
    case SDL_EVENT_JOYSTICK_BUTTON_DOWN:     return Val_SDL_JoyButtonDown(&(event->jbutton));
    case SDL_EVENT_JOYSTICK_BUTTON_UP:       return Val_SDL_JoyButtonUp(&(event->jbutton));
    case SDL_EVENT_JOYSTICK_ADDED:    return Val_SDL_JoyDeviceAdded(&(event->jdevice));
    case SDL_EVENT_JOYSTICK_REMOVED:  return Val_SDL_JoyDeviceRemoved(&(event->jdevice));
    case SDL_EVENT_GAMEPAD_AXIS_MOTION:      return Val_Controller_Axis_Motion;
    case SDL_EVENT_GAMEPAD_BUTTON_DOWN:      return Val_Controller_Button_Down;
    case SDL_EVENT_GAMEPAD_BUTTON_UP:        return Val_Controller_Button_Up;
    case SDL_EVENT_GAMEPAD_ADDED:     return Val_Controller_Device_Added;
    case SDL_EVENT_GAMEPAD_REMOVED:   return Val_Controller_Device_Removed;
    case SDL_EVENT_GAMEPAD_REMAPPED:  return Val_Controller_Device_Remapped;
    case SDL_EVENT_FINGER_DOWN:        return Val_Finger_Down;
    case SDL_EVENT_FINGER_UP:          return Val_Finger_Up;
    case SDL_EVENT_FINGER_MOTION:      return Val_Finger_Motion;
    case SDL_DOLLARGESTURE:     return Val_Dollar_Gesture;
    case SDL_DOLLARRECORD:      return Val_Dollar_Record;
    case SDL_MULTIGESTURE:      return Val_Multi_Gesture;
    case SDL_EVENT_CLIPBOARD_UPDATE:   return Val_Clipboard_Update;
    case SDL_EVENT_DROP_FILE:          return Val_Drop_File;
    case SDL_EVENT_USER:         return Val_User_Event;
    case SDL_WINDOWEVENT:       return Val_SDL_WindowEvent(&(event->window));
    case SDL_SYSWMEVENT:        return Val_SYSWM_Event;
    case SDL_EVENT_QUIT:              return Val_SDL_QuitEvent(&(event->quit));
    case SDL_EVENT_TERMINATING:            return Val_SDL_APP_TERMINATING;
    case SDL_EVENT_LOW_MEMORY:              return Val_SDL_APP_LOWMEMORY;
    case SDL_EVENT_WILL_ENTER_BACKGROUND:    return Val_SDL_APP_WILLENTERBACKGROUND;
    case SDL_EVENT_DID_ENTER_BACKGROUND:     return Val_SDL_APP_DIDENTERBACKGROUND;
    case SDL_EVENT_WILL_ENTER_FOREGROUND:    return Val_SDL_APP_WILLENTERFOREGROUND;
    case SDL_EVENT_DID_ENTER_FOREGROUND:     return Val_SDL_APP_DIDENTERFOREGROUND;
    case SDL_DISPLAYEVENT:               return Val_SDL_DISPLAYEVENT;
    case SDL_EVENT_KEYMAP_CHANGED:              return Val_SDL_KEYMAPCHANGED;
    case SDL_EVENT_DROP_TEXT:                   return Val_SDL_DROPTEXT;
    case SDL_EVENT_DROP_BEGIN:                  return Val_SDL_DROPBEGIN;
    case SDL_EVENT_DROP_COMPLETE:               return Val_SDL_DROPCOMPLETE;
    case SDL_EVENT_AUDIO_DEVICE_ADDED:           return Val_SDL_AUDIODEVICEADDED;
    case SDL_EVENT_AUDIO_DEVICE_REMOVED:         return Val_SDL_AUDIODEVICEREMOVED;
    case SDL_EVENT_SENSOR_UPDATE:               return Val_SDL_SENSORUPDATE;
    case SDL_EVENT_RENDER_TARGETS_RESET:       return Val_SDL_RENDER_TARGETS_RESET;
    case SDL_EVENT_RENDER_DEVICE_RESET:        return Val_SDL_RENDER_DEVICE_RESET;

    default: caml_failwith("SDL Event");
    }
    caml_failwith("SDL Event");
}

CAMLprim value
caml_SDL_PollEvent(value unit)
{
    CAMLparam1(unit);
    CAMLlocal1(ret);

    SDL_Event event;
    int r = SDL_PollEvent(&event);
    if (!r) {
        ret = Val_none;
    } else {
        ret = caml_alloc_some(Val_SDL_Event(&event));
    }
    CAMLreturn(ret);
}
