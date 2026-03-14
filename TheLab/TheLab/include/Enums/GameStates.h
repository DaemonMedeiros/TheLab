#ifndef GAMESTATES_H
#define GAMESTATES_H

typedef enum GameState {
	GS_LOADING_TEXTURES,
	GS_START_MENU,
	GS_INIT_OBJECTS,
	GS_PLAY,
	GS_PAUSE,
	GS_END
} GameState;

#endif
