# AGENT.md

## Project Snapshot
- Repository: `El-cmd/Cub3D`
- Default branch: `main`
- Detected stack: C, shell scripts
- Notable root entries: `includes/`, `libft/`, `maps/`, `minilibx-linux/`, `src/`, `srcs/`, `texture/`, `textures/`, `Makefile`, `readme.md`
- Source mix: .c:117, .cub:33, .xpm:18, .3:5, .1:5, .h:4

## Working Guidelines
- Keep changes scoped to the requested behavior and follow the style already present in the touched files.
- Check `README.md`, `Makefile`, package scripts, and Docker files before introducing new commands or tooling.
- Preserve the existing C/C++ layout and Makefile conventions; avoid committing binaries, object files, or local test outputs.
- Do not commit local secrets, `.env` files, generated dependency folders, build artifacts, or editor metadata.

## Setup
- `No explicit dependency install command is defined in the repository.`

## Run
- `No canonical run command is defined; inspect README/Makefile/package scripts first.`

## Validate
- `make`
- `make re`
- `make clean`
- `make fclean`

## Makefile Targets Detected
- `all`, `clean`, `fclean`, `re`
