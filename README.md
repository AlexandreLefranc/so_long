# so_long

# Install minilibx

```
cd ~/
git clone https://github.com/42Paris/minilibx-linux.git minilibx && cd minilibx
./configure
mkdir -p ./include
cp mlx.h ./include/.
```

Add to .zshrc:

```
alias -g gmlx="~/minilibx/libmlx_Linux.a -lXext -lX11 -I ~/minilibx/include/"
```

Compile as follow:

```
clang main.c gmlx
```

# Ressources

- https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx#
- https://gontjarow.github.io/MiniLibX/
- https://harm-smits.github.io/42docs/libs/minilibx.html


# Pseudo-code

```
main(argc, argv):
	if argc != 2:
		return (ft_putendl_fd("Incorrect number of arguments"),1)
	if is_file_valid(argv[1]) == 0:
		return file is not .ber

	mlx = mlx_init
	mlx_win = mlx_new_window()
	mlx_loop
```
