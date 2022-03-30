# so_long

# Install minilibx

```
cd ~/
git clone https://github.com/42Paris/minilibx-linux.git minilibx && cd minilibx
./configure
mkdir -p ./include
cp mlx.h ./include/.
```

```
alias -g gmlx="~/minilibx/libmlx_Linux.a -lXext -lX11 -I ~/minilibx/include/"
gcc test.c gmlx
```

# Pseudo-code

```
main(argc, argv):
	if argc != 2:
		return (ft_putendl_fd("Incorrect number of arguments"),1)
	if 
```
