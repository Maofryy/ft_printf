#include "ft_libft.h"

static void	pad_fieldprecision(t_token *fl, t_intstuff *vars)
{
	if (fl->fl_pr > 0 && fl->buf.size < fl->fl_pr)
	{
		buf_pad(&(fl->buf), '0', fl->fl_pr, 0);
		if (!(fl->buf.str))
			exit(1);
	}
	vars->can_expand = fl->fl_pr < 0
		&& fl->fl_zero && !(fl->fl_minus);
	if (fl->fl_fw > 0 && vars->can_expand)
	{
		vars->offset = 0;
		if ((fl->fl_cs == 4)
			&& (vars->neg || fl->fl_plus || fl->fl_space))
			vars->offset += 1;
		else if (fl->fl_sharp && fl->fl_cv = 5
			&& (!(vars->is_zero) || fl->fl_pr == 0))
			vars->offset += 1;
		else if (fl->fl_sharp && (fl->fl_cv == 7 || fl->fl_cv == 8)
			&& !(vars->is_zero))
			vars->offset += 2;
		buf_pad(&(fl->buf), '0', fl->fl_fw - vars->offset, 0);
		if (!(fl->buf.str))
			exit(1);
	}
}
//TO CHANGE
static void	prepend_stuff(t_token *tok, t_intstuff *vars)
{
	pad_fieldprecision(tok, vars);
	if ((tok->type == 'd' || tok->type == 'i'))
	{
		if (vars->neg)
			buf_prepend("-", &(tok->buf));
		else if (tok->flags & PLUS_FLAG)
			buf_prepend("+", &(tok->buf));
		else if (tok->flags & SPACE_FLAG)
			buf_prepend(" ", &(tok->buf));
		if (!(tok->buf.str))
			exit(1);
	}
	if (tok->flags & HASH_FLAG)
	{
		if (tok->type == 'o'
			&& ((tok->buf.str)[0] != '0' || tok->precision == 0))
			buf_prepend("0", &(tok->buf));
		else if ((tok->type == 'x' || tok->type == 'X') && !(vars->is_zero))
			buf_prepend("0X", &(tok->buf));
		if (!(tok->buf.str))
			exit(1);
	}
}

void		convert_int(t_token *tok, va_list ap)
{
	t_intstuff	vars;

	vars.neg = intval_to_buf(tok, ap);
	if (!(tok->buf.str))
		exit(1);
	tok->buf.size = ft_strlen(tok->buf.str);
	vars.is_zero = tok->buf.size == 0
		|| (tok->buf.size == 1 && (tok->buf.str)[0] == '0');
	prepend_stuff(tok, &vars);
	if (tok->type == 'x')
		tok->buf.str = ft_strtolower(tok->buf.str);
	if (tok->width_field > 0
		&& tok->buf.size < tok->width_field && !(vars.can_expand))
		buf_pad(&(tok->buf), ' ', tok->width_field, tok->flags & MINUS_FLAG);
}
