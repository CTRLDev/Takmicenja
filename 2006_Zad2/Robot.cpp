//Robot, okruzno takmicenje 2006 godine, prvi zadatak
#include <fstream>
#include <iostream> //Zbog provere

using namespace std;

//deklaracija variabli
int Rot = 0; // Rotacija robota (90=1, 180=2, 270 = 3)
int Posx, Posy; //Pozicija robota
int CommandNum; // broj komandi

int i; // za For loop

ifstream dati ("Robot.dat"); //input datoteka
ofstream dato ("Robot.txt"); //resenje

//deklaracija funkcija
int Forward();
int TurnL();
int TurnR();




int main()
{
	//ucitavanje sa fajla
	dati >> CommandNum;
	dati >> Posx;
	dati >> Posy;
	cout << CommandNum << Posx << Posy;
	char Commands[CommandNum];
	for (i = 0; i < CommandNum; i++) //Za svaku komandu, pogledati koju funkciju izvrsiti
	{
		dati >> Commands[i];
		switch (Commands[i]) //Switch statement radi izbegavanja suvisnih if statmenta
		{
			case 'D' :
				TurnR();
				break;
			case 'L' :
				TurnL();
				break;
			case 'N' :
				Forward();
				break;
			default :
				return 0;
		}
		
	}
	dato << "Pozicija x: " << Posx << " Pozicija y: " << Posy;
	return 0;
}




int Forward() //Za kretanje unapred
{
	switch(Rot) // Zavisno od rotacije
	{
		case 0 :
			Posx += 1;
			break;
		case 1 :
			Posy -= 1;
			break;
		case 2 :
			Posx -= 1;
			break;
		case 3 :
			Posy += 1;
		default :
			return 0;
	}
	
}


int TurnL() // Skretanje levo
{
	if (Rot == 0) //Da bi se izbegli slucajevi od 360 i vise stepeni, nema potrebe, isto vazi i za TurnR()
	{
		Rot = 3;
	}
	else
	{
		Rot = Rot - 1;	
	}
	return 0;
}

int TurnR() // Skretanje desno
{
	if (Rot == 3)
	{
		Rot = 0;
	}
	else
	{
		Rot = Rot + 1;	
	}
	return 0;
}
