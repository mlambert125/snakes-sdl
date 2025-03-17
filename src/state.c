#include "../includes/state.h"

GameState getInitialGameState() {
    return (GameState) {
        .score = 0,
        .level = 1,
        .lives = 3,
        .snakeBodySegmentLocations = {
            {(MAX_X + 1) / 2, (MAX_Y + 1) / 2},
            [1 ... MAX_SNAKE_LENGTH - 1] = {INVALID_COORDINATE, INVALID_COORDINATE}
        },
        .appleLocation = {5, 5},
        .snakeLength = 1,
        .gameOverFramesDisplayed = 0,
    };
}
