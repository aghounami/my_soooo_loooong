all :
	@cd manda_so_long && make

bonus :
	@cd bonus_so_long && make

clean :
	@cd manda_so_long && make clean
	@cd bonus_so_long && make clean

fclean :
	@cd manda_so_long && make fclean
	@cd bonus_so_long && make fclean

re :
	@cd manda_so_long && make re

re_bonus :
	@cd bonus_so_long && make re
