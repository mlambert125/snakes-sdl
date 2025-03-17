#ifndef STATE_H
#define STATE_H

#define MAX_SNAKE_LENGTH 64
#define INVALID_COORDINATE -1
#define MAX_X 30
#define MAX_Y 30

/**
 * Represents a location on the game board.
 */
typedef struct {
    int x;
    int y;
} Location;

/**
 * Represents the direction of the snake.
 */
typedef enum { UP, DOWN, LEFT, RIGHT } Direction;

/**
 * Represents the state of the game.
 */
typedef struct {
    /**
     * The current score of the game.
     */
    int score;

    /**
     * The current level of the game.
     */
    int level;

    /**
     * The number of lives the player has left.
     */
    int lives;

    /**
     * The number of frames the game over screen has been displayed.
     */
    int gameOverFramesDisplayed;

    /**
     * The direction the snake is currently moving.
     */
    Direction snakeDirection;

    /**
     * The current length of the snake.
     */
    int snakeLength;

    /**
     * The locations of the snake's body segments.
     */
    Location snakeBodySegmentLocations[MAX_SNAKE_LENGTH];

    /**
     * The location of the apple.
     */
    Location appleLocation;
} GameState;

/**
 * Returns an initial game state.
 */
GameState getInitialGameState();
#endif
