


void gpio_all_out_off(void)
{
	// Contacteur OFF 
	relais_all_off();

	// Led Turned on a RED value
	led_all_off();
}

void relais_all_on(void)
{
	set_relais_margeur(RELAIS_00, RELAIS_ON);
	set_relais_margeur(RELAIS_01, RELAIS_ON);
	set_relais_margeur(RELAIS_02, RELAIS_ON);
	set_relais_margeur(RELAIS_03, RELAIS_ON);
}

void relais_all_off(void)
{
	set_relais_margeur(RELAIS_00, RELAIS_OFF);
	set_relais_margeur(RELAIS_01, RELAIS_OFF);
	set_relais_margeur(RELAIS_02, RELAIS_OFF);
	set_relais_margeur(RELAIS_03, RELAIS_OFF);	
}




void gpio_affichage(unsigned int numero_port, unsigned int numero_pin) 
{
	static char str_01[TAILLE_ECRAN];
	static char str_02[TAILLE_ECRAN];
	char pin_value;

	// Recuperation de la veleur du pin
	pin_value = gpio_get_value(numero_port, numero_pin);
	

	// 1ere ligne de l'afficheur 

	set_cursor (1, 0);

	sprintf(str_02,"GPIO : P%d.%d",numero_port,numero_pin);

	lcd_print (str);


	// 2 eme ligne de l'afficheur 
	set_cursor (0, 1);

	if (pin_value == -1)
	{
		sprintf(str_02,"Erreur Lecture");
	}
	else
	{
		if (pin_value == LEVEL_LOW)
			sprintf(str_02,"Value : Low");
		else
			sprintf(str_02,"Value : Hight");
	}		

	lcd_print (str);}
}



