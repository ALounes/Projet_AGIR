
void init_bp(void)
{
	if (FIO2PIN == 1)
		FIO2CLR |= 1;
	else
		FIO2SET |= 1;
}