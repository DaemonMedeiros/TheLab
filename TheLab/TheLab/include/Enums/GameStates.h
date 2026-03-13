#ifndef GAMESTATES_H
#define GAMESTATES_H

typedef enum GameState {
	GS_LOADING_TEXTURES,
	GS_INIT_OBJECTS,
	GS_START,
	GS_PLAY,
	GS_PAUSE,
	GS_END
} GameState;

#endif
