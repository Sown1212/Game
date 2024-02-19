#pragma once

#ifndef DATA_BASE_HPP_
#define DATA_BASE_HPP_

#include<iostream>
#include<string>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include"BaseObject.hpp"

static const unsigned int g_Window_Width = 800;
static const unsigned int g_Window_Height = 500;
static const unsigned int g_Window_PositionX = 550;
static const unsigned int g_Window_PositionY = 100;
static const unsigned int g_Player_Width = 60;
static const unsigned int g_Player_Height = 80;
static unsigned int g_Player_PositionX = 45;
static unsigned int g_Player_PositionY = 378;


static SDL_Window *g_pwindow = nullptr;
static SDL_Renderer *g_prenderer = nullptr;

static int g_ColorKeyR = 222;
static int g_ColorKeyG = 222;
static int g_ColorKeyB = 222;

static Uint32 firt_time;
static Uint32 last_time;
static const unsigned int FPS = 60;

static SDL_Event event;
static bool run = true;

Base_Object backgroud;
Base_Object player;

#endif // DATA_BASE_HPP_