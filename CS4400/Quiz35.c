typedef	struct	{
int	x[5][9];					/*	Unknown	constants	A	and	B	*/
long	y;
}	str1;
typedef	struct	{
char	array[9];
int	t;
short	s[5];
long	u;
}	str2;
void	setVal(str1	*p,	str2	*q)	{
long	v1	=	q->t;
long	v2	=	q->u;
p->y	=	v1+v2;
}