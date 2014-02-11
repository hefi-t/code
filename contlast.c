#include "stdafx.h"
#define N 5 //諧調数に使用

int _tmain(int argc, _TCHAR* argv[])
{
	int a[5][5]={{3,3,2,3,3},
				 {3,2,1,2,3},
				 {3,1,0,1,3},
				 {3,2,1,2,3},
				 {3,3,2,3,3}};
	int i,j,k;

	int temp;
	double c;//コントラスト
	double pmax;//画像の最大画素
	double pmin;//画像の最小画素

	double pave;//画素値の平均
	double dg;
	double psum;//画素合計
	double dgmax;
	double Cdg;

	int count[N];//諧調数

	for(k=0;k<=N-1;k++)
		count[k]=0;

	printf("\t0\t1\t2\t3\t4\n");

	//各画素の諧調を求める
	for(i=0;i<=4;i++)
	{
		printf("%d\t",i);
		for(j=0;j<=4;j++)
		{
			printf("%d\t",a[i][j]);
			count[a[i][j]]++;
		}
		printf("\n");
	}

	printf("\n");

	
	for(k=0;k<N;k++)
	{
		printf("諧調数\t%d\t%d個\n",k,count[k]);
	}

	//コントラストの計算
	//pminを求める
	for(k=0;k<N;k++)
	{
		if(count[k]!=0)
		{
			pmin=(double)k;
			break;
		}
	}
	//pmaxを求める
	for(k=N-1;k>=0;k--)
	{
		if(count[k]!=0)
		{
			pmax=(double)k;
			break;
		}
	}

	printf("pmax=%lf,pmin=%lf\n",pmax,pmin);

	c=(pmax-pmin)/(pmax+pmin);//コントラストの計算
	
	printf("コントラスト\tC=%lf\n",c);

	printf("\n諧調修正後\n\n"); 
//画素平均と差
	psum=0;
	pave=0;
	for(i=0;i<=4;i++)
	{
		for(j=0;j<=4;j++)
		{
			psum+=(double)a[i][j];
		}
	}
	pave=psum/(double)(N*N);

	dgmax=pmax-pave;
	Cdg=0.5;//補正係数(0.1~0.5)
	dg=Cdg*dgmax;//補正量

	printf("平均(pave)%lf\n",pave);
	printf("修正(dg)%lf\n",dg);

	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(a[i][j]>pave)
			{
				a[i][j]=a[i][j]+dg*(pmax-a[i][j])/(pmax-pave);
				if(a[i][j]>pmax)
				{
					a[i][j]=pmax;
				}
			}
			if(a[i][j]<pave)
			{
				a[i][j]=a[i][j]-dg*(pmax-a[i][j])/(pave-pmin);
				if(a[i][j]<0)
				{
					a[i][j]=0;
				}
			}
			
		}
		
	}
	

	//表示のプログラム
	for(k=0;k<=4;k++)
		count[k]=0;

	printf("\t0\t1\t2\t3\t4\n");

	for(i=0;i<=4;i++)
	{
		printf("%d\t",i);
		for(j=0;j<=4;j++)
		{
			printf("%d\t",a[i][j]);
			count[a[i][j]]++;
		}
		printf("\n");
	}

	printf("\n");

	for(k=0;k<N;k++)
	{
		printf("諧調数\t%d\t%d\n",k,count[k]);
	}
		//コントラストの計算
	//pminを求める
	for(k=0;k<N;k++)
	{
		if(count[k]!=0)
		{
			pmin=(double)k;
			break;
		}
	}
	//pmaxを求める
	for(k=N-1;k>=0;k--)
	{
		if(count[k]!=0)
		{
			pmax=(double)k;
			break;
		}
	}

	printf("pmax=%lf,pmin=%lf\n",pmax,pmin);

	c=(pmax-pmin)/(pmax+pmin);//コントラストの計算
	
	printf("コントラスト\tC=%lf\n",c);
	return 0;
}

