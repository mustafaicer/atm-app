#include<stdio.h>
#include<stdlib.h>
#include<windows.h> // for sleep(); functions
#include<conio.h> // for getch(); functions

float depositMoney, withdrawMoney, balance, takeCredit, interest, dabt, payedDabt; // Money variables
int chooseCase, chooseYorN, chooseLang, payDabtCase, chooseDabt; // Chooseing variables

// English functions
void depositMoneyFunc();
void withdrawMoneyFunc();
void takeCreditFunc();
void showBalance();
void dabtFunc();

// Turkish functions
void paraYatir();
void paraCek();
void krediCek();
void bakiyeGoster();
void borcFonk();

// Menu functions
int menuEnglish();
int menuTurkish();

// Main function
int main()
{
	printf("\n\n\t\tChoose langue\n\n\t\t1. English\n\n\t\t2. Turkce\n\n\t\tYour options : ");
	scanf("%d",&chooseLang);
	if(chooseLang == 1)
	{
		printf("\n\t\tWelcome to MustafaBank!");
		getch();
		if(menuEnglish() == 1)
			{
				printf("\n\t\tGOODBYE :) ");
				getch();
				return 0;
			}
		do{
			menuEnglish();
			if(menuEnglish() == 1)
			{
				printf("\n\t\tGOODBYE :) ");
				getch();
				return 0;
			}	
		}while(menuEnglish() != 1);
	}
	else if(chooseLang == 2)
	{
		printf("\n\t\tMustafaBank'a Hosgeldiniz!");
		getch();
		do{
			menuTurkish();
			if(menuTurkish() == 1)
			{
				printf("\n\t\tHOSCAKALIN :) ");
				getch();
				return 0;
			}
		}while(menuTurkish() != 1);
	}
	else{
		printf("\n\t\tPlease don't do this!");
		getch();
		main();
	}
	getch();
	return 0;
}

// ----- MENU ENGLİSH FUNCTİONS ----- //

void depositMoneyFunc()
{
	printf("\n\t\tHow much money do you want to deposit? : ");
	scanf("%f",&depositMoney);
	printf("\n\t\tWait a second");
	balance += depositMoney;
	for(int i = 0; i <4; i++)
	{
		Sleep(500);
		if(i!=3) printf(".");
	}
	printf("\n\n\t\tYour balance is now %.2f $",balance);
	getch();
}

void withdrawMoneyFunc()
{
	printf("\n\t\tHow much money do you want to withdraw? : ");
	scanf("%f",&withdrawMoney);
	if(balance <= 0)
	{
		printf("\n\n\t\tYou haven't money");
		getch();
	}
	else if(withdrawMoney > balance)
	{
		printf("\n\n\t\tYou don't have enough money");
		getch();
	}
	else
	{
		balance -= withdrawMoney;
		printf("\n\t\tWait a second");
		for(int i = 0; i <4; i++)
		{
			Sleep(500);
			if(i!=3) printf(".");
		}
		printf("\n\n\t\tYour balance is now %.2f $",balance);
		getch();
	}
}

void takeCreditFunc()
{
	printf("\n\t\tHow much money do you want to take credit? : ");
	scanf("%f",&takeCredit);
	if(takeCredit < 100){
		printf("\n\t\tYou can't take credit less than 100$");
		getch();
	}
	else if(takeCredit >= 100 && takeCredit <= 1000){
		balance += takeCredit;
		interest = takeCredit * 10.20 / 100; 
		dabt = interest + takeCredit;
		printf("\n\t\tWait a second");
		for(int i = 0; i <4; i++)
		{
			Sleep(500);
			if(i!=3) printf(".");
		}
		printf("\n\n\t\t10.20 percent interest was applied");
		getch();
	}
	else if(takeCredit > 1000 && takeCredit <= 100000){
		balance += takeCredit;
		interest = takeCredit * 20.50 / 100; 
		dabt = interest + takeCredit;
		printf("\n\n\t\t20.50 percent interest was applied");
		getch();
	}
	else if(takeCredit > 100000){
		printf("\n\t\tYou can't take credit more than 100.000$");
		getch();
	}
	printf("\n\n\t\tYour balance is now %.2f $",balance);
	getch();
	printf("\n\n\t\tYour dabt is %.2f $",dabt);
	getch();
}

void showBalance()
{
	printf("\n\t\tWait a second");
	for(int i = 0; i <4; i++)
	{
		Sleep(500);
		if(i!=3) printf(".");
	}
	printf("\n\n\t\tYour balance is now %.2f $",balance);
	getch();
}

void dabtFunc()
{
	printf("\n\t\tWait a second");
	for(int i = 0; i <4; i++)
	{
		Sleep(500);
		if(i!=3) printf(".");
	}
	printf("\n\n\t\tYour dabt is %.2f$",dabt);
	getch();
	if(dabt != 0 && balance > dabt)
	{
		printf("\n\n\t\tDo you want to pay your dabt? ('1 (Yes) ' or '0 (No)') : ");
		scanf("%d",&payDabtCase);
		switch(payDabtCase)
		{
			case 1:
				printf("\n\n\t\tHow many dolar you will pay?\n\n\t\t1. All\n\n\t\t2. Some part\n\n\t\tYour choose : ");
				scanf("%d",&chooseDabt);
				switch (chooseDabt)
				{
					case 1:
						if(dabt > balance)
						{
							printf("\n\n\t\tYou cant this");
							break;
						}
						else
						{
							balance -= dabt;
							dabt -= dabt;
							printf("\n\t\tWait a second");
							for(int i = 0; i <4; i++)
							{
								Sleep(500);
								if(i!=3) printf(".");
							}
							printf("\n\n\t\tYour dabt is now %.2f$",dabt);
							getch();
							printf("\n\n\t\tYour balance now : %.2f",balance);
							getch();
						}
						break;
					case 2:
						printf("\n\n\t\tHow much of your debt do you want to pay off? : ");
						scanf("%f",&payedDabt);
						dabt -= payedDabt;
						balance -= payedDabt;
						printf("\n\t\tWait a second");
						for(int i = 0; i <4; i++)
						{
							Sleep(500);
							if(i!=3) printf(".");
						}
						printf("\n\n\t\tYour dabt is now %.2f$",dabt);
						getch();
						printf("\n\n\t\tYour balance is now %.2f$",balance);
						getch();
						break;
					default:
						printf("\n\n\t\tPlease don't do this");
						getch();
						break;
				}
			case 0:
				break;
		}
	}
}

// ----- MENU TURKİSH FUNCTİONS ----- //

void paraYatir()
{
		printf("\n\t\tNe kadar para yatirmak istiyorsunuz? : ");
		scanf("%f",&depositMoney);
		balance += depositMoney;
		printf("\n\t\tBir saniye");
		for(int i = 0; i <4; i++)
		{
			Sleep(500);
			if(i!=3) printf(".");
		}
		printf("\n\n\t\tSu anki bakiyeniz : %.2f $",balance);
		getch();
}
void paraCek()
{
	printf("\n\t\tNe kadar para cekmek istiyorsunuz? : ");
	scanf("%f",&withdrawMoney);
	if(balance <= 0)
	{
		printf("\n\n\t\tParaniz yok");
		getch();
	}
	else if(withdrawMoney > balance)
	{
		printf("\n\n\t\tParan yeterli degil");
		getch();
	}
	else
	{
		balance -= withdrawMoney;
		printf("\n\t\tBir saniye");
		for(int i = 0; i <4; i++)
		{
			Sleep(500);
			if(i!=3) printf(".");
		}
		printf("\n\n\t\tSu anki bakiyeniz %.2f $",balance);
		getch();
	}
}
void krediCek()
{
	printf("\n\t\tNe kadar kredi cekmek istiyorsunuz? : ");
	scanf("%f",&takeCredit);
	if(takeCredit < 100){
		printf("\n\n\t\t100$'dan az kredi cekemezsiniz");
		getch();
	}
	else if(takeCredit >= 100 && takeCredit <= 1000){
		balance += takeCredit;
		interest = takeCredit * 10.20 / 100; 
		dabt = interest + takeCredit;
		printf("\n\t\tBir saniye");
		for(int i = 0; i <4; i++)
		{
			Sleep(500);
			if(i!=3) printf(".");
		}
		printf("\n\t\tYuzde 10.20 faiz uygulandi");
		getch();
	}
	else if(takeCredit > 1000 && takeCredit <= 100000){
		balance += takeCredit;
		interest = takeCredit * 20.50 / 100; 
		dabt = interest + takeCredit;
		printf("\n\t\tBir saniye");
		for(int i = 0; i <4; i++)
		{
			Sleep(500);
			if(i!=3) printf(".");
		}
		printf("\n\n\t\tYuzde 20.50 faiz uygulandi");
		getch();
	}
	else if(takeCredit > 100000){
		printf("\n\n\t\t100.000$'dan fazla kredi cekemezsiniz");
		getch();
	}
	printf("\n\n\t\tSu anki bakiyeniz %.2f $",balance);
	getch();
	printf("\n\n\t\tBorcunuz %.2f $",dabt);
	getch();
}
void bakiyeGoster()
{
	printf("\n\t\tSu anki bakiyeniz %.2f $",balance);
	getch();
}
void borcFonk()
{
	printf("\n\n\t\tBorcunuz %.2f$",dabt);
	getch();
	if(dabt != 0 && balance > dabt)
	{
		printf("\n\n\t\tBorcunuzu odemek ister misiniz? ('1 (Evet)' ya da '0 (Hayir)') : ");
		scanf("%d",&payDabtCase);
		switch(payDabtCase)
		{
			case 1:
				printf("\n\n\t\tBorcunuzun ne kadarini odeyeceksiniz?\n\n\t\t1. Hepsini\n\n\t\t2. Bi kismini\n\n\t\tSeciminiz : ");
				scanf("%d",&chooseDabt);
				switch (chooseDabt)
				{
					case 1:
						if(dabt > balance)
						{
							printf("\n\n\t\tBunu yapamazsın");
							getch();
						}
						else
						{
							balance -= dabt;
							dabt -= dabt;
							printf("\n\t\tBir saniye");
							for(int i = 0; i <4; i++)
							{
								Sleep(500);
								if(i!=3) printf(".");
							}
							printf("\n\n\t\tSu anki borcun %.2f$",dabt);
							getch();
							printf("\n\n\t\tSu anki bakiyen : %.2f",balance);
							getch();
						}
						break;
					case 2:
						printf("\n\n\t\tKac dolar odeyeceksiniz? : ");
						scanf("%f",&payedDabt);
						dabt -= payedDabt;
						balance -= payedDabt;
						printf("\n\t\tBir saniye");
						for(int i = 0; i <4; i++)
						{
							Sleep(500);
							if(i!=3) printf(".");
						}
						printf("\n\n\t\tSu anki borcun %.2f$",dabt);
						getch();
						printf("\n\n\t\tSu anki bakiyen : %.2f",balance);
						getch();
						break;
					default:
						printf("\n\n\t\tLutfen bunu yapma!");
						getch();
						break;
				}
			case 0:
				break;
		}
	}
}

// Menu functions

int menuEnglish()
{
	printf("\n\n\t\t------Menu------\n\n\t\t0. Exit\n\n\t\t1. Deposit Money\n\n\t\t2. Withdraw Money\n\n\t\t3. Take Credit\n\n\t\t4. Show Balance\n\n\t\t5. Show Dabt");
	printf("\n\n\t\tChoose your options : ");
	scanf("%d",&chooseCase);
	switch (chooseCase)
	{
		case 0:
			return 1;
			break;
		case 1:
			depositMoneyFunc();
			break;
		case 2:
			withdrawMoneyFunc();
			break;
		case 3:
			takeCreditFunc();
			break;
		case 4:
			showBalance();
			break;
		case 5:
			dabtFunc();
			break;
	}
	return 0;
}

int menuTurkish()
{
	printf("\n\n\t\t------Menu------\n\n\t\t0. Cikis\n\n\t\t1. Para Yatir\n\n\t\t2. Para Cek\n\n\t\t3. Kredi Cek\n\n\t\t4. Bakiye Goster\n\n\t\t5. Borclari Goster");
	printf("\n\n\t\tSeceneginizi secin : ");
	scanf("%d",&chooseCase);
	switch (chooseCase)
	{
		case 0:
			return 1;
			break;
		case 1:
			paraYatir();
			break;
		case 2:
			paraCek();
			break;
		case 3:
			krediCek();
			break;
		case 4:
			bakiyeGoster();
			break;
		case 5:
			borcFonk();
			break;
	}
	return 0;
}