#include<iostream>
using namespace std;

int main()
{
	int latas,base=0;
	bool band=false;
	cout<<"Digite el numero de latas: ";cin>>latas;
	if(latas>2)
	{
		for(int i=2;i<=latas&&band==false;i++)
		{
			if(2*latas==i*(i+1))
			{
				cout<<"Las latas SI se pueden apilar de forma triangular.";
				base=i;
				band=true;
			}
		}
		if(band==false)
		{
			cout<<"Las latas NO se pueden apilar de forma triangular";
		}
	}
	else
	{
		cout<<"Las latas NO se pueden apilar de forma triangular";
	}
	//DIBUJANDO EL DIAGRAMA
	if(band==true)
	{
		cout<<"\n\n";
		int contador=0;
		while(base>0)
		{
			for(int i=0;i<base;i++)
			{
				cout<<" ";
			}
			cout<<"*";
			for(int i=0;i<contador;i++)
			{
				cout<<" *";
			}
			cout<<endl;
			contador++;
			base--;
		}
	}
	
	return 0;
}
