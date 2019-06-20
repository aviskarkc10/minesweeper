#ifndef __MINESWEEPER_H__
#define __MINESWEEPER_H__

#include <stdbool.h>

#define INDEX_FOR_CELL(rows, cols, x, y) (cols * y + x)
#define POSITION_X_FOR_INDEX(cols, index) (index % cols)
#define POSITION_Y_FOR_INDEX(cols, index) (index / cols)

typedef struct {
  int x;
  int y;
  int index;
  int bombs_count;
  bool is_bomb;
  bool is_revealed;
  bool is_flagged;
} MinesweeperCell;

typedef struct {
  int rows;
  int cols;
  int bomb_count;
  bool is_bombs_initialized;
  MinesweeperCell ***cells;
} MinesweeperCtx;

MinesweeperCtx* msw_init(int rows, int cols);
int msw_init_bomb_positions(MinesweeperCtx *game, int first_cell_index);

/**
 * CELL FUNCTIONS
 */
int cell_reveal(MinesweeperCtx *game, MinesweeperCell *cell);
int cell_flag(MinesweeperCtx *game, MinesweeperCell *cell);
/**
 * CELL FUNCTIONS END
 */

int msw_quit();

#endif
